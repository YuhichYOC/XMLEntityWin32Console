#include "stdafx.h"

#include "SettingReaderTest.h"

bool SettingReaderTest::GetTestSuccess()
{
    return testSuccess;
}

void SettingReaderTest::SettingReaderTest01()
{
    std::string * fileName = new std::string("E:\\Users\\b50061tem.NES00\\Desktop\\Desktop\\作成物\\Proj.1609\\XMLEntityWin32Console\\Setting.config");
    SettingReader * sr = new SettingReader();
    sr->SetFileName(fileName);
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
    std::string * fileName = new std::string("E:\\Users\\b50061tem.NES00\\Desktop\\Desktop\\作成物\\Proj.1609\\XMLEntityWin32Console\\Setting.config");
    SettingReader * sr = new SettingReader();
    sr->SetFileName(fileName);
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

    std::string value;
    std::cin >> value;
}

SettingReaderTest::SettingReaderTest()
{
}

SettingReaderTest::~SettingReaderTest()
{
}