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
        std::cout << "nTest 01 success." << "\n";
    }
    else {
        std::cout << "nTest 01 failed." << "\n";
    }
    delete nTest;
}

void NodeEntityTest02()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest02();
    if (nTest->GetTestSuccess()) {
        std::cout << "nTest 02 success." << "\n";
    }
    else {
        std::cout << "nTest 02 failed." << "\n";
    }
    delete nTest;
}

void NodeEntityTest03()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest03();
    if (nTest->GetTestSuccess()) {
        std::cout << "nTest 03 success." << "\n";
    }
    else {
        std::cout << "nTest 03 failed." << "\n";
    }
    delete nTest;
}

void NodeEntityTest04()
{
    NodeEntityTest * nTest = new NodeEntityTest();
    nTest->NodeEntityTest04();
    if (nTest->GetTestSuccess()) {
        std::cout << "nTest 04 success." << "\n";
    }
    else {
        std::cout << "nTest 04 failed." << "\n";
    }
    delete nTest;
}

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

void SmartPointerTest01()
{
    SmartPointerTest * sTest = new SmartPointerTest();
    sTest->SmartPointerTest01();
    if (sTest->GetTestSuccess()) {
        std::cout << "sTest 01 success." << "\n";
    }
    else {
        std::cout << "sTest 01 failed." << "\n";
    }
    delete sTest;
}

void SmartPointerTest02()
{
    SmartPointerTest * sTest = new SmartPointerTest();
    sTest->SmartPointerTest02();
    if (sTest->GetTestSuccess()) {
        std::cout << "sTest 02 success." << "\n";
    }
    else {
        std::cout << "sTest 02 failed." << "\n";
    }
    delete sTest;
}

int main()
{
    /*
    NodeEntityTest01();
    NodeEntityTest02();
    NodeEntityTest04();
    SettingReaderTest01();
    SmartPointerTest01();
    */
    NodeEntityTest03();

    std::string value;
    std::cin >> value;
    return 0;
}