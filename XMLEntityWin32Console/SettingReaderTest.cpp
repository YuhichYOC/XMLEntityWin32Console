/*
*
* SettingReaderTest.cpp
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

#include "SettingReaderTest.h"

bool SettingReaderTest::GetTestSuccess()
{
    return testSuccess;
}

void SettingReaderTest::SettingReaderTest01()
{
    string * fileName = new string("E:\\Users\\b50061tem.NES00\\Desktop\\Desktop\\作成物\\Proj.1609\\XMLEntityWin32Console\\Setting.config");
    SettingReader * sr = new SettingReader();
    sr->SetFileName(*fileName);
    sr->Prepare();
    if (!sr->IsPrepared()) {
        delete sr;
        return;
    }
    sr->Parse();
    if (!sr->IsParseSucceeded()) {
        delete sr;
        return;
    }
    // 実際の値について検証
}

void SettingReaderTest::SettingReaderTest02()
{
    string * fileName = new string("E:\\Users\\b50061tem.NES00\\Desktop\\Desktop\\作成物\\Proj.1609\\XMLEntityWin32Console\\Setting.config");
    SettingReader * sr = new SettingReader();
    sr->SetFileName(*fileName);
    sr->Prepare();
    if (!sr->IsPrepared()) {
        delete sr;
        return;
    }
    sr->Parse();
    if (!sr->IsParseSucceeded()) {
        delete sr;
        return;
    }
    // 実際の値について検証
    sr->GetNode()->Dispose();

    string value;
    cin >> value;
}

SettingReaderTest::SettingReaderTest()
{
}

SettingReaderTest::~SettingReaderTest()
{
}