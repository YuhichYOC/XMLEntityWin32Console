#include "stdafx.h"

#include "NodeEntityTest.h"

bool NodeEntityTest::GetTestSuccess()
{
    return testSuccess;
}

void NodeEntityTest::NodeEntityTest01()
{
    unique_ptr<NodeEntity> node(new NodeEntity());
    unique_ptr<vector<string *>> tree(new vector<string *>());
    string * name;

    /*
    *
    *  Root
    *    -> AAA
    *         -> BBB
    *              -> CCC
    *              -> DDD
    *
    */

    name = new string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new string("AAA");
    addNodeAAA->SetNodeName(name);

    node->AddChild(addNodeAAA);
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new string("BBB");
    addNodeBBB->SetNodeName(name);

    node->FindFromTail(tree.get())->AddChild(addNodeBBB);
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new string("CCC");
    addNodeCCC->SetNodeName(name);

    node->FindFromTail(tree.get())->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new string("DDD");
    addNodeDDD->SetNodeName(name);

    node->FindFromTail(tree.get())->AddChild(addNodeDDD);

    testSuccess = true;

    delete name;
}

void NodeEntityTest::NodeEntityTest02()
{
    //unique_ptr<NodeEntity> node(new NodeEntity());
    NodeEntity * node = new NodeEntity();
    vector<string *> * tree = new vector<string *>();
    string * name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = new string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new string("AAA");
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = new string("type");
    addAttrAAAtype->SetAttrName(name);
    name = new string("typeAAA");
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);
    name = new string("AAA");
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new string("BBB");
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = new string("name");
    addAttrBBBname->SetAttrName(name);
    name = new string("nameBBB");
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = new string("type");
    addAttrBBBtype->SetAttrName(name);
    name = new string("typeBBB");
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindFromTail(tree)->AddChild(addNodeBBB);
    name = new string("BBB");
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new string("CCC");
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = new string("type");
    addAttrCCCtype->SetAttrName(name);
    name = new string("typeCCC");
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindFromTail(tree)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new string("DDD");
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = new string("name");
    addAttrDDDname->SetAttrName(name);
    name = new string("nameDDD");
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindFromTail(tree)->AddChild(addNodeDDD);

    testSuccess = true;

    delete node;
}

void NodeEntityTest::NodeEntityTest03()
{
    unique_ptr<NodeEntity> node(new NodeEntity());
    //unique_ptr<vector<string *>> tree(new vector<string *>());
    vector<string *> * tree = new vector<string *>();
    string * name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = new string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new string("AAA");
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = new string("type");
    addAttrAAAtype->SetAttrName(name);
    name = new string("typeAAA");
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);
    name = new string("AAA");
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new string("BBB");
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = new string("name");
    addAttrBBBname->SetAttrName(name);
    name = new string("nameBBB");
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = new string("type");
    addAttrBBBtype->SetAttrName(name);
    name = new string("typeBBB");
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindFromTail(tree)->AddChild(addNodeBBB);
    name = new string("BBB");
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new string("CCC");
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = new string("type");
    addAttrCCCtype->SetAttrName(name);
    name = new string("typeCCC");
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindFromTail(tree)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new string("DDD");
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = new string("name");
    addAttrDDDname->SetAttrName(name);
    name = new string("nameDDD");
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindFromTail(tree)->AddChild(addNodeDDD);

    name = new string("CCC");
    NodeEntity * testNode = node.get()->FindFromTail(tree, name)->Clone();

    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest04()
{
    unique_ptr<NodeEntity> node(new NodeEntity());
    unique_ptr<vector<string *>> tree(new vector<string *>());
    string * name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = new string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new string("AAA");
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = new string("type");
    addAttrAAAtype->SetAttrName(name);
    name = new string("typeAAA");
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);
    name = new string("AAA");
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new string("BBB");
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = new string("name");
    addAttrBBBname->SetAttrName(name);
    name = new string("nameBBB");
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = new string("type");
    addAttrBBBtype->SetAttrName(name);
    name = new string("typeBBB");
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindFromTail(tree.get())->AddChild(addNodeBBB);
    name = new string("BBB");
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new string("CCC");
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = new string("type");
    addAttrCCCtype->SetAttrName(name);
    name = new string("typeCCC");
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindFromTail(tree.get())->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new string("DDD");
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = new string("name");
    addAttrDDDname->SetAttrName(name);
    name = new string("nameDDD");
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindFromTail(tree.get())->AddChild(addNodeDDD);

    name = new string("BBB");
    NodeEntity * testNode = node.get()->FindFromTail(tree.get(), name)->Clone();

    testSuccess = true;
}

NodeEntityTest::NodeEntityTest()
{
}

NodeEntityTest::~NodeEntityTest()
{
}