/*
*
* SettingReader.cpp
*
* Copyright 2016 Yuichi Yoshii
*     ‹gˆä—Yˆê @ ‹gˆäŽY‹Æ  you.65535.kir@gmail.com
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

unique_ptr<NodeEntity> SettingReader::GetNode()
{
    return move(myNode);
}

void SettingReader::Prepare()
{
    setlocale(LC_ALL, "japanese");

    if (fileName.length() == 0) {
        errorMessage.assign("SettingReader::Prepare -- File name is not set. Method : Parse");
        prepared = false;
        return;
    }
    WCharString wc = wc.Value(fileName);
    if (FAILED(SHCreateStreamOnFile((LPCWSTR)(wc.ToWChar().get()), STGM_READ, &stream))) {
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

    unique_ptr<NodeEntity> newNode;
    WCharString wc;
    newNode->SetNodeName(wc.Value(localName).ToString());
    newNode->SetNodeID(nodeId);
    newNode = move(ParseAttributes(reader, move(newNode)));

    if (nodeId == 1) {
        myNode = move(newNode);
    }
    else {
        myNode->FindTail(depth)->AddChild(move(newNode));
    }
    if (!reader->IsEmptyElement()) {
        depth++;
    }
}

unique_ptr<NodeEntity> SettingReader::ParseAttributes(IXmlReader * reader, unique_ptr<NodeEntity> node)
{
    const wchar_t * prefix;
    const wchar_t * localName;
    const wchar_t * value;
    uint32_t prefixLength;

    if (FAILED(reader->MoveToFirstAttribute())) {
        return move(node);
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
            unique_ptr<AttributeEntity> newAttr;
            WCharString wc;
            newAttr->SetAttrName(wc.Value(localName).ToString());
            newAttr->SetAttrValue(wc.Value(value).ToString());
            node->AddAttribute(move(newAttr));
        }
        if (S_OK != reader->MoveToNextAttribute()) {
            break;
        }
    }
    return move(node);
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
    stream = nullptr;
    reader = nullptr;
    disposed = false;
}

void SettingReader::Dispose()
{
    if (stream != nullptr) {
        delete stream;
    }
    if (reader != nullptr) {
        delete reader;
    }
    disposed = true;
}

SettingReader::~SettingReader()
{
    if (!disposed) {
        Dispose();
    }
}