#pragma once

#include <codecvt>                 // wstring_convert を利用するために必要

#include <Shlwapi.h>               // SHCreateStreamOnFile を利用するために必要

#include <atlbase.h>

#include "NodeEntity.h"

class SettingReader
{
private:

    unique_ptr<string> directory;

    unique_ptr<string> fileName;

    NodeEntity * myNode;

    int nodeId;

    IStream * stream;

    IXmlReader * reader;

    bool prepared;

    bool parseSucceeded;

    unique_ptr<string> errorMessage;

    wchar_t * WChar_tFromStr(string * arg);

    void ParseElement(IXmlReader * reader, vector<string *> * tree);

    void ParseText(IXmlReader * reader, vector<string *> * tree);

    void ParseCDATA(IXmlReader * reader, vector<string *> * tree);

    void ParseEndElement(IXmlReader * reader, vector<string *> * tree);

    void ParseAttributes(IXmlReader * reader, vector<string *> * tree, string * name);

    string * StrFromWChar_t(wchar_t * arg);

    string * StrFromCWChar_t(const wchar_t * arg);

    bool disposed;

public:

    void SetDirectory(string * arg);

    string * GetDirectory();

    void SetFileName(string * arg);

    string * GetFileName();

    NodeEntity * GetNode();

    void Prepare();

    bool IsPrepared();

    void Parse();

    bool IsParseSucceeded();

    string * GetErrorMessage();

    SettingReader();

    void Dispose();

    ~SettingReader();
};
