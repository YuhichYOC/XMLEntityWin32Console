/*
*
* NodeEntityTest.cpp
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

bool NodeEntityTest::GetTestSuccess()
{
    return testSuccess;
}

void NodeEntityTest::NodeEntityTest01()
{
    unique_ptr<NodeEntity> node;
    string name;

    /*
    *
    *  Root
    *    -> AAA
    *         -> BBB
    *              -> CCC
    *              -> DDD
    *
    */

    name = "Root";
    node->SetNodeName(name);

    unique_ptr<NodeEntity> addNodeAAA;
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    node->AddChild(move(addNodeAAA));

    unique_ptr<NodeEntity> addNodeBBB;
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    node->FindTail(2)->AddChild(move(addNodeBBB));

    unique_ptr<NodeEntity> addNodeCCC;
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    node->FindTail(3)->AddChild(move(addNodeCCC));

    unique_ptr<NodeEntity> addNodeDDD;
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    node->FindTail(4)->AddChild(move(addNodeDDD));

    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest02()
{
    unique_ptr<NodeEntity> node;
    string name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = "Root";
    node->SetNodeName(name);

    unique_ptr<NodeEntity> addNodeAAA;
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrAAAtype;
    name = "type";
    addAttrAAAtype->SetAttrName(name);
    name = "typeAAA";
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(move(addAttrAAAtype));

    node->AddChild(move(addNodeAAA));
    name = "AAA";

    unique_ptr<NodeEntity> addNodeBBB;
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrBBBname;
    name = "name";
    addAttrBBBname->SetAttrName(name);
    name = "nameBBB";
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(move(addAttrBBBname));
    unique_ptr<AttributeEntity> addAttrBBBtype;
    name = "type";
    addAttrBBBtype->SetAttrName(name);
    name = "typeBBB";
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(move(addAttrBBBtype));

    node->FindTail(2)->AddChild(move(addNodeBBB));
    name = "BBB";

    unique_ptr<NodeEntity> addNodeCCC;
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrCCCtype;
    name = "type";
    addAttrCCCtype->SetAttrName(name);
    name = "typeCCC";
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(move(addAttrCCCtype));

    node->FindTail(3)->AddChild(move(addNodeCCC));

    unique_ptr<NodeEntity> addNodeDDD;
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrDDDname;
    name = "name";
    addAttrDDDname->SetAttrName(name);
    name = "nameDDD";
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(move(addAttrDDDname));

    node->FindTail(3)->AddChild(move(addNodeDDD));

    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest03()
{
    unique_ptr<NodeEntity> node;
    string name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = "Root";
    node->SetNodeName(name);

    unique_ptr<NodeEntity> addNodeAAA;
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrAAAtype;
    name = "type";
    addAttrAAAtype->SetAttrName(name);
    name = "typeAAA";
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(move(addAttrAAAtype));

    node->AddChild(move(addNodeAAA));
    name = "AAA";

    unique_ptr<NodeEntity> addNodeBBB;
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrBBBname;
    name = "name";
    addAttrBBBname->SetAttrName(name);
    name = "nameBBB";
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(move(addAttrBBBname));
    unique_ptr<AttributeEntity> addAttrBBBtype;
    name = "type";
    addAttrBBBtype->SetAttrName(name);
    name = "typeBBB";
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(move(addAttrBBBtype));

    node->FindTail(2)->AddChild(move(addNodeBBB));
    name = "BBB";

    unique_ptr<NodeEntity> addNodeCCC;
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrCCCtype;
    name = "type";
    addAttrCCCtype->SetAttrName(name);
    name = "typeCCC";
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(move(addAttrCCCtype));

    node->FindTail(3)->AddChild(move(addNodeCCC));

    unique_ptr<NodeEntity> addNodeDDD;
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrDDDname;
    name = "name";
    addAttrDDDname->SetAttrName(name);
    name = "nameDDD";
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(move(addAttrDDDname));

    node->FindTail(3)->AddChild(move(addNodeDDD));

    unique_ptr<NodeEntity> testNode = node->FindTail(3)->Clone();

    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest04()
{
    unique_ptr<NodeEntity> node;
    string name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = "Root";
    node->SetNodeName(name);

    unique_ptr<NodeEntity> addNodeAAA;
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrAAAtype;
    name = "type";
    addAttrAAAtype->SetAttrName(name);
    name = "typeAAA";
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(move(addAttrAAAtype));

    node->AddChild(move(addNodeAAA));
    name = "AAA";

    unique_ptr<NodeEntity> addNodeBBB;
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrBBBname;
    name = "name";
    addAttrBBBname->SetAttrName(name);
    name = "nameBBB";
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(move(addAttrBBBname));
    unique_ptr<AttributeEntity> addAttrBBBtype;
    name = "type";
    addAttrBBBtype->SetAttrName(name);
    name = "typeBBB";
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(move(addAttrBBBtype));

    node->FindTail(2)->AddChild(move(addNodeBBB));
    name = "BBB";

    unique_ptr<NodeEntity> addNodeCCC;
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrCCCtype;
    name = "type";
    addAttrCCCtype->SetAttrName(name);
    name = "typeCCC";
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(move(addAttrCCCtype));

    node->FindTail(3)->AddChild(move(addNodeCCC));

    unique_ptr<NodeEntity> addNodeDDD;
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    unique_ptr<AttributeEntity> addAttrDDDname;
    name = "name";
    addAttrDDDname->SetAttrName(name);
    name = "nameDDD";
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(move(addAttrDDDname));

    node->FindTail(3)->AddChild(move(addNodeDDD));

    unique_ptr<NodeEntity> testNode = node->FindTail(3)->Clone();

    testSuccess = true;
}

NodeEntityTest::NodeEntityTest()
{
}

NodeEntityTest::~NodeEntityTest()
{
}