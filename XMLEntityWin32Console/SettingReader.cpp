#include "stdafx.h"

#include "SettingReader.h"

void SettingReader::SetDirectory(std::string * arg)
{
    directory.reset(arg);
}

std::string * SettingReader::GetDirectory()
{
    return directory.get();
}

void SettingReader::SetFileName(std::string * arg)
{
    fileName.reset(arg);
}

std::string * SettingReader::GetFileName()
{
    return fileName.get();
}

NodeEntity * SettingReader::GetNode()
{
    return myNode.get();
}

void SettingReader::Prepare()
{
    setlocale(LC_ALL, "japanese");

    if (fileName->length() == 0) {
        errorMessage->assign("SettingReader::Prepare -- File name is not set. Method : Parse");
        prepared = false;
        return;
    }
    if (FAILED(SHCreateStreamOnFile(WChar_tFromStr(fileName.get()), STGM_READ, &stream))) {
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

wchar_t * SettingReader::WChar_tFromStr(std::string * arg)
{
    size_t retSize = strlen(arg->c_str()) + 1;
    size_t convSize = 0;
    wchar_t * retVal = new wchar_t[retSize];
    mbstowcs_s(&convSize, retVal, retSize, arg->c_str(), _TRUNCATE);
    return retVal;
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

    std::unique_ptr<NodeEntity> newNode(new NodeEntity());
    newNode.get()->SetNodeName(StrFromCWChar_t(localName));
    newNode.get()->SetNodeID(nodeId);

    if (nodeId == 1) {
        myNode.reset(newNode.get());
    }
    else {
        if (reader->IsEmptyElement()) {
            tree->pop_back();
        }
        myNode.get()->FindFromTail(tree)->AddChild(std::move(newNode));
    }
    ParseAttributes(reader, tree, newNode->GetNodeName());
    tree->push_back(*newNode->GetNodeName());
}

void SettingReader::ParseCDATA(IXmlReader * reader, std::vector<std::string> * tree)
{
    const wchar_t * value;
    if (FAILED(reader->GetValue(&value, NULL))) {
        return;
    }
    myNode->FindFromTail(tree)->SetNodeValue(StrFromCWChar_t(value));
}

void SettingReader::ParseEndElement(IXmlReader * reader, std::vector<std::string> * tree)
{
    tree->pop_back();
}

void SettingReader::ParseAttributes(IXmlReader * reader, std::vector<std::string> * tree, std::string * name)
{
    const wchar_t * prefix;
    const wchar_t * localName;
    const wchar_t * value;
    uint32_t prefixLength;

    if (FAILED(reader->MoveToFirstAttribute())) {
        return;
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
            std::unique_ptr<AttributeEntity> newAttr(new AttributeEntity());
            newAttr.get()->SetAttrName(StrFromCWChar_t(localName));
            newAttr.get()->SetAttrValue(StrFromCWChar_t(value));
            myNode.get()->FindFromTail(tree, name)->AddAttribute(std::move(newAttr));
        }
        if (S_OK != reader->MoveToNextAttribute()) {
            break;
        }
    }
}

std::string * SettingReader::StrFromWChar_t(wchar_t * arg)
{
    std::wstring castedArg = arg;
    size_t retSize = castedArg.length() + 1;
    size_t convSize = 0;
    std::unique_ptr<char> arrayFromArg(new char[retSize]);
    wcstombs_s(&convSize, arrayFromArg.get(), retSize, arg, _TRUNCATE);
    std::string * retVal = new std::string(arrayFromArg.get());
    return retVal;
}

std::string * SettingReader::StrFromCWChar_t(const wchar_t * arg)
{
    // const ‹³‚Ù‚ñ‚Æ‚Ð‚Å‚½‚é‚Æ‚Ü‚Ð‚ë
    std::wstring castedArg = arg;
    size_t retSize = castedArg.length() + 1;
    size_t convSize = 0;
    std::unique_ptr<char> arrayFromArg(new char[retSize]);
    wcstombs_s(&convSize, arrayFromArg.get(), retSize, arg, _TRUNCATE);
    std::string * retVal = new std::string(arrayFromArg.get());
    return retVal;
}

bool SettingReader::IsParseSucceeded()
{
    return parseSucceeded;
}

std::string * SettingReader::GetErrorMessage()
{
    return errorMessage.get();
}

SettingReader::SettingReader()
{
    directory = std::unique_ptr<std::string>();
    fileName = std::unique_ptr<std::string>();
    myNode = std::unique_ptr<NodeEntity>();
    errorMessage = std::unique_ptr<std::string>();
    stream = nullptr;
    reader = nullptr;
}

SettingReader::~SettingReader()
{
    if (stream != nullptr) {
        delete stream;
    }
    if (reader != nullptr) {
        delete reader;
    }
}