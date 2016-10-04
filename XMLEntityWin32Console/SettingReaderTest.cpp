#include "stdafx.h"

#include "SettingReaderTest.h"

bool SettingReaderTest::GetTestSuccess()
{
    return testSuccess;
}

void SettingReaderTest::SettingReaderTest01()
{
    std::string * fileName = new std::string("E:\\Users\\b50061tem.NES00\\Desktop\\Desktop\\ì¬•¨\\Proj.1609\\XMLEntityWin32Console\\Setting.config");
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
    // ÀÛ‚Ì’l‚É‚Â‚¢‚ÄŒŸØ
}

SettingReaderTest::SettingReaderTest()
{
}

SettingReaderTest::~SettingReaderTest()
{
}