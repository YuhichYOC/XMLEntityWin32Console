/*
*
* NodeEntityTest.cpp
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

#include "NodeEntityTest.h"

bool NodeEntityTest::GetTestSuccess()
{
    return testSuccess;
}

void NodeEntityTest::NodeEntityTest01()
{
    NodeEntity * node = new NodeEntity();
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

    NodeEntity * addNodeAAA = new NodeEntity();
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    node->AddChild(addNodeAAA);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    node->FindTail(2)->AddChild(addNodeBBB);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    node->FindTail(3)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    node->FindTail(3)->AddChild(addNodeDDD);

    delete node;
    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest02()
{
    NodeEntity * node = new NodeEntity();
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

    NodeEntity * addNodeAAA = new NodeEntity();
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = "type";
    addAttrAAAtype->SetAttrName(name);
    name = "typeAAA";
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = "name";
    addAttrBBBname->SetAttrName(name);
    name = "nameBBB";
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = "type";
    addAttrBBBtype->SetAttrName(name);
    name = "typeBBB";
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindTail(2)->AddChild(addNodeBBB);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = "type";
    addAttrCCCtype->SetAttrName(name);
    name = "typeCCC";
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindTail(3)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = "name";
    addAttrDDDname->SetAttrName(name);
    name = "nameDDD";
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindTail(3)->AddChild(addNodeDDD);

    delete node;
    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest03()
{
    NodeEntity * node = new NodeEntity();
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

    NodeEntity * addNodeAAA = new NodeEntity();
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = "type";
    addAttrAAAtype->SetAttrName(name);
    name = "typeAAA";
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = "name";
    addAttrBBBname->SetAttrName(name);
    name = "nameBBB";
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = "type";
    addAttrBBBtype->SetAttrName(name);
    name = "typeBBB";
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindTail(2)->AddChild(addNodeBBB);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = "type";
    addAttrCCCtype->SetAttrName(name);
    name = "typeCCC";
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindTail(3)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = "name";
    addAttrDDDname->SetAttrName(name);
    name = "nameDDD";
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindTail(3)->AddChild(addNodeDDD);

    //unique_ptr<NodeEntity> testNode = node->FindTail(3)->Clone();

    delete node;
    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest04()
{
    NodeEntity * node = new NodeEntity();
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

    NodeEntity * addNodeAAA = new NodeEntity();
    name = "AAA";
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = "type";
    addAttrAAAtype->SetAttrName(name);
    name = "typeAAA";
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = "BBB";
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = "name";
    addAttrBBBname->SetAttrName(name);
    name = "nameBBB";
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = "type";
    addAttrBBBtype->SetAttrName(name);
    name = "typeBBB";
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindTail(2)->AddChild(addNodeBBB);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = "CCC";
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = "type";
    addAttrCCCtype->SetAttrName(name);
    name = "typeCCC";
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindTail(3)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = "DDD";
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = "name";
    addAttrDDDname->SetAttrName(name);
    name = "nameDDD";
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindTail(3)->AddChild(addNodeDDD);

    //unique_ptr<NodeEntity> testNode = node->FindTail(3)->Clone();

    delete node;
    testSuccess = true;
}

NodeEntityTest::NodeEntityTest()
{
}

NodeEntityTest::~NodeEntityTest()
{
}