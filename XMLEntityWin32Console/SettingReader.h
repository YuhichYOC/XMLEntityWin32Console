#p/*
*
* SettingReader.h
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

#pragma once

#include <codecvt>                 // wstring_convert ‚ð—˜—p‚·‚é‚½‚ß‚É•K—v

#include <Shlwapi.h>               // SHCreateStreamOnFile ‚ð—˜—p‚·‚é‚½‚ß‚É•K—v

#include <atlbase.h>

#include "NodeEntity.h"

class SettingReader
{
private:

    string directory;

    string fileName;

    NodeEntity * myNode;

    int nodeId;

    IStream * stream;

    IXmlReader * reader;

    bool prepared;

    bool parseSucceeded;

    string errorMessage;

    wchar_t * WChar_tFromStr(string arg);

    void ParseElement(IXmlReader * reader, vector<string> * tree);

    void ParseText(IXmlReader * reader, vector<string> * tree);

    void ParseCDATA(IXmlReader * reader, vector<string> * tree);

    void ParseEndElement(IXmlReader * reader, vector<string> * tree);

    void ParseAttributes(IXmlReader * reader, vector<string> * tree, string name);

    string StrFromWChar_t(wchar_t * arg);

    string StrFromCWChar_t(const wchar_t * arg);

    bool disposed;

public:

    void SetDirectory(string arg);

    string GetDirectory();

    void SetFileName(string arg);

    string GetFileName();

    NodeEntity * GetNode();

    void Prepare();

    bool IsPrepared();

    void Parse();

    bool IsParseSucceeded();

    string GetErrorMessage();

    SettingReader();

    void Dispose();

    ~SettingReader();
};
