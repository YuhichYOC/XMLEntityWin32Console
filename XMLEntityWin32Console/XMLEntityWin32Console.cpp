/*
*
* XMLEntityWin32Console.cpp
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