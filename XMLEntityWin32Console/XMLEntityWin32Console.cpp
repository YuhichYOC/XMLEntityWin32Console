// XMLEntityWin32Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "NodeEntityTest.h"
#include "SettingReaderTest.h"

void SmartPointerTest01()
{
    NodeEntityTest * nSmartPointerTest = new NodeEntityTest();
    nSmartPointerTest->SmartPointerTest01();
    if (nSmartPointerTest->GetTestSuccess()) {
        std::cout << "nSmartPointerTest 01 success." << "\n";
    }
    else {
        std::cout << "nSmartPointerTest 01 failed." << "\n";
    }
    delete nSmartPointerTest;
}

void NoSmartPointerTest01()
{
    NodeEntityTest * nNoSmartPointerTest = new NodeEntityTest();
    nNoSmartPointerTest->NoSmartPointerTest01();
    if (nNoSmartPointerTest->GetTestSuccess()) {
        std::cout << "nNoSmartPointerTest 01 success." << "\n";
    }
    else {
        std::cout << "nNoSmartPointerTest 01 failed." << "\n";
    }
    delete nNoSmartPointerTest;
}

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

int main()
{
    /*
    SmartPointerTest01();
    NoSmartPointerTest01();
    NodeEntityTest01();
    NodeEntityTest02();
    NodeEntityTest04();
    SettingReaderTest01();
    */
    NodeEntityTest03();

    std::string value;
    std::cin >> value;
    return 0;
}