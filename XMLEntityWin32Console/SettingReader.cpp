﻿/*
*
* SettingReader.cpp
*
* Copyright 2016 Yuichi Yoshii
*     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#include "stdafx.h"

#include "SettingReader.h"

void SettingReader::SetDirectory(string arg)
{
    directory.assign(arg);
}

string SettingReader::GetDirectory()
{
    return directory;
}

void SettingReader::SetFileName(string arg)
{
    fileName.assign(arg);
}

string SettingReader::GetFileName()
{
    return fileName;
}

NodeEntity * SettingReader::GetNode()
{
    return myNode.get();
}

void SettingReader::Prepare()
{
    if (fileName.length() == 0) {
        errorMessage.assign("SettingReader::Prepare -- File name is not set. Method : Parse");
        prepared = false;
        return;
    }
    WCharString wc;
    if (FAILED(SHCreateStreamOnFile(wc.Value(fileName).ToLPWStr(), STGM_READ, &stream))) {
        errorMessage.assign("SettingReader::Prepare -- File reader can't be create. Method : SHCreateStreamOnFile");
        prepared = false;
        return;
    }
    if (FAILED(CreateXmlReader(__uuidof(IXmlReader), (void**)&reader, NULL))) {
        errorMessage.assign("SettingReader::Prepare -- Xml reader can't be create. Method : CreateXmlReader");
        prepared = false;
        return;
    }
    if (FAILED(reader->SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit))) {
        errorMessage.assign("SettingReader::Prepare -- Reader property can't set. Method : SetProperty");
        prepared = false;
        return;
    }
    if (FAILED(reader->SetInput(stream))) {
        errorMessage.assign("SettingReader::Prepare -- Reader stream can't set. Method : SetInput");
        parseSucceeded = false;
        return;
    }

    prepared = true;
}

bool SettingReader::IsPrepared()
{
    return prepared;
}

void SettingReader::Parse()
{
    XmlNodeType nodeType;
    while (reader->Read(&nodeType) == S_OK) {
        ParseElement(reader, nodeType);
        ParseText(reader, nodeType);
        ParseCDATA(reader, nodeType);
        ParseEndElement(reader, nodeType);
    }

    parseSucceeded = true;
}

void SettingReader::ParseElement(IXmlReader * reader, XmlNodeType nodeType)
{
    if (nodeType != XmlNodeType::XmlNodeType_Element) { return; }
    const wchar_t * prefix;
    const wchar_t * localName;
    uint32_t prefixLength;
    if (FAILED(reader->GetPrefix(&prefix, &prefixLength))) {
        return;
    }
    if (FAILED(reader->GetLocalName(&localName, NULL))) {
        return;
    }

    nodeId++;

    NodeEntity * newNode = new NodeEntity();
    WCharString wc;
    newNode->SetNodeName(wc.Value(localName).ToString());
    newNode->SetNodeID(nodeId);
    newNode = ParseAttributes(reader, newNode);

    if (nodeId == 1) {
        myNode.reset(newNode);
    }
    else {
        myNode->FindTail(depth)->AddChild(newNode);
    }
    if (!reader->IsEmptyElement()) {
        depth++;
    }
}

NodeEntity * SettingReader::ParseAttributes(IXmlReader * reader, NodeEntity * node)
{
    const wchar_t * prefix;
    const wchar_t * localName;
    const wchar_t * value;
    uint32_t prefixLength;

    if (FAILED(reader->MoveToFirstAttribute())) {
        return node;
    }
    while (true) {
        if (!reader->IsDefault()) {
            if (FAILED(reader->GetPrefix(&prefix, &prefixLength))) {
                continue;
            }
            if (FAILED(reader->GetLocalName(&localName, NULL))) {
                continue;
            }
            if (FAILED(reader->GetValue(&value, NULL))) {
                continue;
            }
            AttributeEntity * newAttr = new AttributeEntity();
            WCharString wc;
            newAttr->SetAttrName(wc.Value(localName).ToString());
            newAttr->SetAttrValue(wc.Value(value).ToString());
            node->AddAttribute(newAttr);
        }
        if (S_OK != reader->MoveToNextAttribute()) {
            break;
        }
    }
    return node;
}

void SettingReader::ParseText(IXmlReader * reader, XmlNodeType nodeType)
{
    if (nodeType != XmlNodeType::XmlNodeType_Text) { return; }
    const wchar_t * value;
    if (FAILED(reader->GetValue(&value, NULL))) {
        return;
    }
    WCharString wc;
    myNode->FindTail(depth)->SetNodeValue(wc.Value(value).ToString());
}

void SettingReader::ParseCDATA(IXmlReader * reader, XmlNodeType nodeType)
{
    if (nodeType != XmlNodeType::XmlNodeType_CDATA) { return; }
    const wchar_t * value;
    if (FAILED(reader->GetValue(&value, NULL))) {
        return;
    }
    WCharString wc;
    myNode->FindTail(depth)->SetNodeValue(wc.Value(value).ToString());
}

void SettingReader::ParseEndElement(IXmlReader * reader, XmlNodeType nodeType)
{
    if (nodeType != XmlNodeType::XmlNodeType_EndElement) { return; }
    depth--;
}

bool SettingReader::IsParseSucceeded()
{
    return parseSucceeded;
}

string SettingReader::GetErrorMessage()
{
    return errorMessage;
}

SettingReader::SettingReader()
{
    depth = 0;
    nodeId = 0;
    disposed = false;
}

void SettingReader::Dispose()
{
    disposed = true;
}

SettingReader::~SettingReader()
{
    if (!disposed) {
        Dispose();
    }
}