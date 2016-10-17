// XMLEntityWin32Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "NodeEntityTest.h"
#include "SettingReaderTest.h"
#include "SmartPointerTest.h"

void NodeEntityTest01()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest01();
    if (nTest->GetTestSuccess()) {
        cout << "nTest 01 success." << "\n";
    }
    else {
        cout << "nTest 01 failed." << "\n";
    }
    delete nTest;
}

void NodeEntityTest02()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest02();
    if (nTest->GetTestSuccess()) {
        cout << "nTest 02 success." << "\n";
    }
    else {
        cout << "nTest 02 failed." << "\n";
    }
    delete nTest;
}

void NodeEntityTest03()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest03();
    if (nTest->GetTestSuccess()) {
        cout << "nTest 03 success." << "\n";
    }
    else {
        cout << "nTest 03 failed." << "\n";
    }
    delete nTest;
}

void NodeEntityTest04()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest04();
    if (nTest->GetTestSuccess()) {
        cout << "nTest 04 success." << "\n";
    }
    else {
        cout << "nTest 04 failed." << "\n";
    }
    delete nTest;
}

void SettingReaderTest01()
{
    SettingReaderTest * sTest = new SettingReaderTest();
    sTest->SettingReaderTest01();
    if (sTest->GetTestSuccess()) {
        cout << "sTest 01 success." << "\n";
    }
    else {
        cout << "sTest 01 failed." << "\n";
    }
    delete sTest;
}

void SettingReaderTest02()
{
    SettingReaderTest * sTest = new SettingReaderTest();
    sTest->SettingReaderTest02();
    if (sTest->GetTestSuccess()) {
        cout << "sTest 02 success." << "\n";
    }
    else {
        cout << "sTest 02 failed." << "\n";
    }
    delete sTest;
}

void SmartPointerTest01()
{
    SmartPointerTest * sTest = new SmartPointerTest();
    sTest->SmartPointerTest01();
    if (sTest->GetTestSuccess()) {
        cout << "sTest 01 success." << "\n";
    }
    else {
        cout << "sTest 01 failed." << "\n";
    }
    delete sTest;
}

void SmartPointerTest02()
{
    SmartPointerTest * sTest = new SmartPointerTest();
    sTest->SmartPointerTest02();
    if (sTest->GetTestSuccess()) {
        cout << "sTest 02 success." << "\n";
    }
    else {
        cout << "sTest 02 failed." << "\n";
    }
    delete sTest;
}

int main()
{
    /*
    SmartPointerTest01();
    */
    NodeEntityTest01();
    NodeEntityTest02();
    NodeEntityTest03();
    NodeEntityTest04();
    SettingReaderTest01();
    SettingReaderTest02();

    string value;
    cin >> value;
    return 0;
}