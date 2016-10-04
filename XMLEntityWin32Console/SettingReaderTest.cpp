#include "stdafx.h"

#include "SettingReaderTest.h"

bool SettingReaderTest::GetTestSuccess()
{
    return testSuccess;
}

void SettingReaderTest::SettingReaderTest01()
{
    std::string * fileName = new std::string("E:\\Users\\b50061tem.NES00\\Desktop\\Desktop\\�쐬��\\Proj.1609\\XMLEntityWin32Console\\Setting.config");
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
    // ���ۂ̒l�ɂ��Č���
}

SettingReaderTest::SettingReaderTest()
{
}

SettingReaderTest::~SettingReaderTest()
{
}