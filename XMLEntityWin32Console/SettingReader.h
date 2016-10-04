#pragma once

#include <codecvt>                 // wstring_convert �𗘗p���邽�߂ɕK�v

#include <Shlwapi.h>               // SHCreateStreamOnFile �𗘗p���邽�߂ɕK�v

#include <atlbase.h>               // �X�}�[�g�|�C���^�𗘗p���邽�߂ɕK�v

#include "NodeEntity.h"

class SettingReader
{
private:

    std::string * directory;

    std::string * fileName;

    NodeEntity * myNode;

    int nodeId;

    IStream * stream;

    IXmlReader * reader;

    bool prepared;

    bool parseSucceeded;

    std::string * errorMessage;

    wchar_t * ConvertStrToWChar_t(std::string * arg);

    void ParseElement(IXmlReader * reader, std::vector<std::string> * tree);

    void ParseCDATA(IXmlReader * reader, std::vector<std::string> * tree);

    void ParseEndElement(IXmlReader * reader, std::vector<std::string> * tree);

    void ParseAttributes(IXmlReader * reader, std::vector<std::string> * tree);

    std::string * ConvertWChar_tToStr(wchar_t * arg);

public:

    void SetDirectory(std::string * arg);

    std::string * GetDirectory();

    void SetFileName(std::string * arg);

    std::string * GetFileName();

    NodeEntity * GetNode();

    void Prepare();

    bool IsPrepared();

    void Parse();

    bool IsParseSucceeded();

    std::string * GetErrorMessage();

    SettingReader();

    ~SettingReader();
};

