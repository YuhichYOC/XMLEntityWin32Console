// XMLEntityWin32Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "SettingReaderTest.h"

void SettingReaderTest01()
{
    SettingReaderTest * sTest = new SettingReaderTest();
    sTest->SettingReaderTest01();
    if (sTest->GetTestSuccess()) {
        std::cout << "sTest 01 success." << "\n";
    }
    else {
        std::cout << "sTest 01 failed." << "\n";
    }
    delete sTest;
}

int main()
{
    SettingReaderTest01();
    return 0;
}