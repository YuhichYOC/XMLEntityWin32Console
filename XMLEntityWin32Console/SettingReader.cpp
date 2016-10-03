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
    return wstr.c_str;
}

bool SettingReader::IsPrepared()
{
    return prepared;
}

void SettingReader::Parse()
{
    nodeId = 0;
    XmlNodeType nodeType;
    while (reader->Read(&nodeType) == S_OK) {
        switch (nodeType)
        {
        default:
            break;
        }
    }
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
    delete stream;
    delete reader;
    delete errorMessage;
}
