#include "stdafx.h"

#include "NodeEntityTest.h"

bool NodeEntityTest::GetTestSuccess()
{
    return testSuccess;
}

void NodeEntityTest::NodeEntityTest01()
{
    std::unique_ptr<NodeEntity> node(new NodeEntity());
    std::unique_ptr<std::vector<std::string>> tree(new std::vector<std::string>());
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
    node.get()->SetNodeName(name);
    tree.get()->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeAAA(new NodeEntity());
    name = new std::string("AAA");
    addNodeAAA.get()->SetNodeName(name);

    node.get()->AddChild(addNodeAAA.get());
    tree->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeBBB(new NodeEntity());
    name = new std::string("BBB");
    addNodeBBB.get()->SetNodeName(name);

    node.get()->FindFromTail(tree.get())->AddChild(addNodeBBB.get());
    tree->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeCCC(new NodeEntity());
    name = new std::string("CCC");
    addNodeCCC.get()->SetNodeName(name);

    node.get()->FindFromTail(tree.get())->AddChild(addNodeCCC.get());

    std::unique_ptr<NodeEntity> addNodeDDD(new NodeEntity());
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    node.get()->FindFromTail(tree.get())->AddChild(addNodeDDD.get());

    testSuccess = true;
}

void NodeEntityTest::NodeEntityTest02()
{
    std::unique_ptr<NodeEntity> node(new NodeEntity());
    std::unique_ptr<std::vector<std::string>> tree(new std::vector<std::string>());
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
    node.get()->SetNodeName(name);
    tree.get()->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeAAA(new NodeEntity());
    name = new std::string("AAA");
    addNodeAAA.get()->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrAAAtype(new AttributeEntity());
    name = new std::string("type");
    addAttrAAAtype.get()->SetAttrName(name);
    name = new std::string("typeAAA");
    addAttrAAAtype.get()->SetAttrValue(name);
    addNodeAAA.get()->AddAttribute(addAttrAAAtype.get());

    node.get()->AddChild(addNodeAAA.get());
    name = new std::string("AAA");
    tree.get()->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeBBB(new NodeEntity());
    name = new std::string("BBB");
    addNodeBBB.get()->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrBBBname(new AttributeEntity());
    name = new std::string("name");
    addAttrBBBname.get()->SetAttrName(name);
    name = new std::string("nameBBB");
    addAttrBBBname.get()->SetAttrValue(name);
    addNodeBBB.get()->AddAttribute(addAttrBBBname.get());
    std::unique_ptr<AttributeEntity> addAttrBBBtype(new AttributeEntity());
    name = new std::string("type");
    addAttrBBBtype.get()->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype.get()->SetAttrValue(name);
    addNodeBBB.get()->AddAttribute(addAttrBBBtype.get());

    node.get()->FindFromTail(tree.get())->AddChild(addNodeBBB.get());
    name = new std::string("BBB");
    tree.get()->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeCCC(new NodeEntity());
    name = new std::string("CCC");
    addNodeCCC.get()->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrCCCtype(new AttributeEntity());
    name = new std::string("type");
    addAttrCCCtype.get()->SetAttrName(name);
    name = new std::string("typeCCC");
    addAttrCCCtype.get()->SetAttrValue(name);
    addNodeCCC.get()->AddAttribute(addAttrCCCtype.get());

    node.get()->FindFromTail(tree.get())->AddChild(addNodeCCC.get());

    std::unique_ptr<NodeEntity> addNodeDDD(new NodeEntity());
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrDDDname(new AttributeEntity());
    name = new std::string("name");
    addAttrDDDname.get()->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname.get()->SetAttrValue(name);
    addNodeDDD.get()->AddAttribute(addAttrDDDname.get());

    node.get()->FindFromTail(tree.get())->AddChild(addNodeDDD.get());

    testSuccess = true;
}

NodeEntityTest::NodeEntityTest()
{
}

NodeEntityTest::~NodeEntityTest()
{
}