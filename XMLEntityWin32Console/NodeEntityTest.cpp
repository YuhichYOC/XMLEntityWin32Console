#include "stdafx.h"

#include "NodeEntityTest.h"

bool NodeEntityTest::GetTestSuccess()
{
    return testSuccess;
}

void NodeEntityTest::NodeEntityTest01()
{
    std::unique_ptr<NodeEntity> node(new NodeEntity());
    std::unique_ptr<std::vector<std::string *>> tree(new std::vector<std::string *>());
    std::string * name;

    /*
    *
    *  Root
    *    -> AAA
    *         -> BBB
    *              -> CCC
    *              -> DDD
    *
    */

    name = new std::string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new std::string("AAA");
    addNodeAAA->SetNodeName(name);

    node->AddChild(addNodeAAA);
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new std::string("BBB");
    addNodeBBB->SetNodeName(name);

    node->FindFromTail(tree.get())->AddChild(addNodeBBB);
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new std::string("CCC");
    addNodeCCC->SetNodeName(name);

    node->FindFromTail(tree.get())->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    node->FindFromTail(tree.get())->AddChild(addNodeDDD);

    testSuccess = true;

    delete name;
}

void NodeEntityTest::NodeEntityTest02()
{
    //std::unique_ptr<NodeEntity> node(new NodeEntity());
    NodeEntity * node = new NodeEntity();
    std::vector<std::string *> * tree = new std::vector<std::string *>();
    std::string * name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = new std::string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new std::string("AAA");
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = new std::string("type");
    addAttrAAAtype->SetAttrName(name);
    name = new std::string("typeAAA");
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);
    name = new std::string("AAA");
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new std::string("BBB");
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = new std::string("name");
    addAttrBBBname->SetAttrName(name);
    name = new std::string("nameBBB");
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = new std::string("type");
    addAttrBBBtype->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindFromTail(tree)->AddChild(addNodeBBB);
    name = new std::string("BBB");
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new std::string("CCC");
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = new std::string("type");
    addAttrCCCtype->SetAttrName(name);
    name = new std::string("typeCCC");
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindFromTail(tree)->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = new std::string("name");
    addAttrDDDname->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindFromTail(tree)->AddChild(addNodeDDD);

    testSuccess = true;

    delete node;

    int iLoopCount = tree->size();
    for (int i = 0; i < iLoopCount; i++) {
        std::string * deleteItem = tree->at(i);
        delete deleteItem;
    }
}

void NodeEntityTest::NodeEntityTest03()
{
    std::unique_ptr<NodeEntity> node(new NodeEntity());
    std::unique_ptr<std::vector<std::string *>> tree(new std::vector<std::string *>());
    std::string * name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = new std::string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new std::string("AAA");
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = new std::string("type");
    addAttrAAAtype->SetAttrName(name);
    name = new std::string("typeAAA");
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);
    name = new std::string("AAA");
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new std::string("BBB");
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = new std::string("name");
    addAttrBBBname->SetAttrName(name);
    name = new std::string("nameBBB");
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = new std::string("type");
    addAttrBBBtype->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindFromTail(tree.get())->AddChild(addNodeBBB);
    name = new std::string("BBB");
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new std::string("CCC");
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = new std::string("type");
    addAttrCCCtype->SetAttrName(name);
    name = new std::string("typeCCC");
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindFromTail(tree.get())->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = new std::string("name");
    addAttrDDDname->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindFromTail(tree.get())->AddChild(addNodeDDD);

    name = new std::string("CCC");
    NodeEntity testNode = *node.get()->FindFromTail(tree.get(), name);

    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest04()
{
    std::unique_ptr<NodeEntity> node(new NodeEntity());
    std::unique_ptr<std::vector<std::string *>> tree(new std::vector<std::string *>());
    std::string * name;

    /*
    *
    *  Root
    *    -> AAA  type = typeAAA
    *         -> BBB  name = nameBBB, type = typeBBB
    *              -> CCC  type = typeCCC
    *              -> DDD  name = nameDDD
    *
    */

    name = new std::string("Root");
    node->SetNodeName(name);
    tree->push_back(name);

    NodeEntity * addNodeAAA = new NodeEntity();
    name = new std::string("AAA");
    addNodeAAA->SetNodeName(name);

    AttributeEntity * addAttrAAAtype = new AttributeEntity();
    name = new std::string("type");
    addAttrAAAtype->SetAttrName(name);
    name = new std::string("typeAAA");
    addAttrAAAtype->SetAttrValue(name);
    addNodeAAA->AddAttribute(addAttrAAAtype);

    node->AddChild(addNodeAAA);
    name = new std::string("AAA");
    tree->push_back(name);

    NodeEntity * addNodeBBB = new NodeEntity();
    name = new std::string("BBB");
    addNodeBBB->SetNodeName(name);

    AttributeEntity * addAttrBBBname = new AttributeEntity();
    name = new std::string("name");
    addAttrBBBname->SetAttrName(name);
    name = new std::string("nameBBB");
    addAttrBBBname->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBname);
    AttributeEntity * addAttrBBBtype = new AttributeEntity();
    name = new std::string("type");
    addAttrBBBtype->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype->SetAttrValue(name);
    addNodeBBB->AddAttribute(addAttrBBBtype);

    node->FindFromTail(tree.get())->AddChild(addNodeBBB);
    name = new std::string("BBB");
    tree->push_back(name);

    NodeEntity * addNodeCCC = new NodeEntity();
    name = new std::string("CCC");
    addNodeCCC->SetNodeName(name);

    AttributeEntity * addAttrCCCtype = new AttributeEntity();
    name = new std::string("type");
    addAttrCCCtype->SetAttrName(name);
    name = new std::string("typeCCC");
    addAttrCCCtype->SetAttrValue(name);
    addNodeCCC->AddAttribute(addAttrCCCtype);

    node->FindFromTail(tree.get())->AddChild(addNodeCCC);

    NodeEntity * addNodeDDD = new NodeEntity();
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    AttributeEntity * addAttrDDDname = new AttributeEntity();
    name = new std::string("name");
    addAttrDDDname->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname->SetAttrValue(name);
    addNodeDDD->AddAttribute(addAttrDDDname);

    node->FindFromTail(tree.get())->AddChild(addNodeDDD);

    name = new std::string("BBB");
    NodeEntity testNode = *node.get()->FindFromTail(tree.get(), name);

    testSuccess = true;
}

NodeEntityTest::NodeEntityTest()
{
}

NodeEntityTest::~NodeEntityTest()
{
}