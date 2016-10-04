#include "stdafx.h"

#include "SettingReader.h"

void SettingReader::SetDirectory(std::string * arg)
{
    directory = arg;
}

std::string * SettingReader::GetDirectory()
{
    return directory;
}

void SettingReader::SetFileName(std::string * arg)
{
    fileName = arg;
}

std::string * SettingReader::GetFileName()
{
    return fileName;
}

NodeEntity * SettingReader::GetNode()
{
    return myNode;
}

void SettingReader::Prepare()
{
    if (fileName->length() == 0) {
        errorMessage->assign("SettingReader::Prepare -- File name is not set. Method : Parse");
        prepared = false;
        return;
    }
    if (FAILED(SHCreateStreamOnFile(ConvertStrToWChar_t(fileName), STGM_READ, &stream))) {
        errorMessage->assign("SettingReader::Prepare -- File reader can't be create. Method : SHCreateStreamOnFile");
        prepared = false;
        return;
    }
    if (FAILED(CreateXmlReader(__uuidof(IXmlReader), (void**)&reader, NULL))) {
        errorMessage->assign("SettingReader::Prepare -- Xml reader can't be create. Method : CreateXmlReader");
        prepared = false;
        return;
    }
    if (FAILED(reader->SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit))) {
        errorMessage->assign("SettingReader::Prepare -- Reader property can't set. Method : SetProperty");
        prepared = false;
        return;
    }
    if (FAILED(reader->SetInput(stream))) {
        errorMessage->assign("SettingReader::Prepare -- Reader stream can't set. Method : SetInput");
        parseSucceeded = false;
        return;
    }

    prepared = true;
}

wchar_t * SettingReader::ConvertStrToWChar_t(std::string * arg)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
    std::wstring wstr = conv.from_bytes(*arg);
    wchar_t retVal;
    retVal = *wstr.c_str();
    return &retVal;
}

bool SettingReader::IsPrepared()
{
    return prepared;
}

void SettingReader::Parse()
{
    nodeId = 0;

    std::vector<std::string> * tree = new std::vector<std::string>();

    XmlNodeType nodeType;
    while (reader->Read(&nodeType) == S_OK) {
        switch (nodeType)
        {
        case XmlNodeType_None:
            break;
        case XmlNodeType_Element:
            ParseElement(reader, tree);
            break;
        case XmlNodeType_Attribute:
            break;
        case XmlNodeType_Text:
            break;
        case XmlNodeType_CDATA:
            ParseCDATA(reader, tree);
            break;
        case XmlNodeType_ProcessingInstruction:
            break;
        case XmlNodeType_Comment:
            break;
        case XmlNodeType_DocumentType:
            break;
        case XmlNodeType_Whitespace:
            break;
        case XmlNodeType_EndElement:
            ParseEndElement(reader, tree);
            break;
        case XmlNodeType_XmlDeclaration:
            break;
        default:
            break;
        }
    }

    parseSucceeded = true;
}

void SettingReader::ParseElement(IXmlReader * reader, std::vector<std::string> * tree)
{
    wchar_t * prefix;
    wchar_t * localName;
    uint32_t prefixLength;
    if (FAILED(reader->GetPrefix(&prefix, &prefixLength))) {
        return;
    }
    if (FAILED(reader->GetLocalName(&localName, NULL))) {
        return;
    }

    nodeId++;

    NodeEntity * newNode = new NodeEntity();
    newNode->SetNodeName(ConvertWChar_tToStr(localName));
    newNode->SetNodeID(nodeId);

    ParseAttributes(reader, tree);
    if (nodeId == 1) {
        tree->push_back(*newNode->GetNodeName());
        myNode == newNode;
    }
    else {
        myNode->FindFromTail(tree)->AddChild(newNode);
        if (!reader->IsEmptyElement()) {
            tree->push_back(*newNode->GetNodeName());
        }
    }
}

void SettingReader::ParseCDATA(IXmlReader * reader, std::vector<std::string> * tree)
{
    wchar_t * value;
    if (FAILED(reader->GetValue(&value, NULL))) {
        return;
    }
    myNode->FindFromTail(tree)->SetNodeValue(ConvertWChar_tToStr(value));
}

void SettingReader::ParseEndElement(IXmlReader * reader, std::vector<std::string> * tree)
{
    tree->pop_back();
}

void SettingReader::ParseAttributes(IXmlReader * reader, std::vector<std::string> * tree)
{
    wchar_t * prefix;
    wchar_t * localName;
    wchar_t * value;
    uint32_t prefixLength;
    
    if (FAILED(reader->MoveToFirstAttribute())) {
        return;
    }
    while (true) {
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
        newAttr->SetAttrName(ConvertWChar_tToStr(localName));
        newAttr->SetAttrValue(ConvertWChar_tToStr(value));
        myNode->FindFromTail(tree)->AddAttribute(newAttr);

        if (reader->MoveToNextAttribute() != S_OK) {
            break;
        }
    }
}

std::string * SettingReader::ConvertWChar_tToStr(wchar_t * arg)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
    std::string str = conv.to_bytes(*arg);
    return &str;
}

bool SettingReader::IsParseSucceeded()
{
    return parseSucceeded;
}

std::string * SettingReader::GetErrorMessage()
{
    return errorMessage;
}

SettingReader::SettingReader()
{
    directory = new std::string();
    fileName = new std::string();
    myNode = new NodeEntity();
    stream = nullptr;
    reader = nullptr;
    errorMessage = new std::string();
}

SettingReader::~SettingReader()
{
    delete directory;
    delete fileName;
    delete myNode;
    if (stream != nullptr) {
        delete stream;
    }
    if (reader != nullptr) {
        delete reader;
    }
    delete errorMessage;
}
