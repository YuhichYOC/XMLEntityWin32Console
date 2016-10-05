#include "stdafx.h"

#include "NodeEntityTest.h"

bool NodeEntityTest::GetTestSuccess()
{
    return testSuccess;
}

void NodeEntityTest::SmartPointerTest01()
{
    std::unique_ptr<AttributeEntity> attr(new AttributeEntity());
    attr->SetAttrName(new std::string("test"));

    testSuccess = true;
}

void NodeEntityTest::NoSmartPointerTest01()
{
    AttributeEntity * attr = new AttributeEntity();
    attr->SetAttrName(new std::string("test"));

    testSuccess = true;
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

    node.get()->AddChild(std::move(addNodeAAA));
    tree->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeBBB(new NodeEntity());
    name = new std::string("BBB");
    addNodeBBB.get()->SetNodeName(name);

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeBBB));
    tree->push_back(*name);

    std::unique_ptr<NodeEntity> addNodeCCC(new NodeEntity());
    name = new std::string("CCC");
    addNodeCCC.get()->SetNodeName(name);

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeCCC));

    std::unique_ptr<NodeEntity> addNodeDDD(new NodeEntity());
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeDDD));

    testSuccess = true;

    delete name;
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
    addNodeAAA.get()->AddAttribute(std::move(addAttrAAAtype));

    node.get()->AddChild(std::move(addNodeAAA));
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
    addNodeBBB.get()->AddAttribute(std::move(addAttrBBBname));
    std::unique_ptr<AttributeEntity> addAttrBBBtype(new AttributeEntity());
    name = new std::string("type");
    addAttrBBBtype.get()->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype.get()->SetAttrValue(name);
    addNodeBBB.get()->AddAttribute(std::move(addAttrBBBtype));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeBBB));
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
    addNodeCCC.get()->AddAttribute(std::move(addAttrCCCtype));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeCCC));

    std::unique_ptr<NodeEntity> addNodeDDD(new NodeEntity());
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrDDDname(new AttributeEntity());
    name = new std::string("name");
    addAttrDDDname.get()->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname.get()->SetAttrValue(name);
    addNodeDDD.get()->AddAttribute(std::move(addAttrDDDname));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeDDD));

    testSuccess = true;

    delete name;
}

void NodeEntityTest::NodeEntityTest03()
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
    addNodeAAA.get()->AddAttribute(std::move(addAttrAAAtype));

    node.get()->AddChild(std::move(addNodeAAA));
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
    addNodeBBB.get()->AddAttribute(std::move(addAttrBBBname));
    std::unique_ptr<AttributeEntity> addAttrBBBtype(new AttributeEntity());
    name = new std::string("type");
    addAttrBBBtype.get()->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype.get()->SetAttrValue(name);
    addNodeBBB.get()->AddAttribute(std::move(addAttrBBBtype));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeBBB));
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
    addNodeCCC.get()->AddAttribute(std::move(addAttrCCCtype));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeCCC));

    std::unique_ptr<NodeEntity> addNodeDDD(new NodeEntity());
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrDDDname(new AttributeEntity());
    name = new std::string("name");
    addAttrDDDname.get()->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname.get()->SetAttrValue(name);
    addNodeDDD.get()->AddAttribute(std::move(addAttrDDDname));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeDDD));

    name = new std::string("CCC");
    NodeEntity * testNode = node.get()->FindFromTail(tree.get(), name);

    testSuccess = true;

    delete name;
}

void NodeEntityTest::NodeEntityTest04()
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
    addNodeAAA.get()->AddAttribute(std::move(addAttrAAAtype));

    node.get()->AddChild(std::move(addNodeAAA));
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
    addNodeBBB.get()->AddAttribute(std::move(addAttrBBBname));
    std::unique_ptr<AttributeEntity> addAttrBBBtype(new AttributeEntity());
    name = new std::string("type");
    addAttrBBBtype.get()->SetAttrName(name);
    name = new std::string("typeBBB");
    addAttrBBBtype.get()->SetAttrValue(name);
    addNodeBBB.get()->AddAttribute(std::move(addAttrBBBtype));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeBBB));
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
    addNodeCCC.get()->AddAttribute(std::move(addAttrCCCtype));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeCCC));

    std::unique_ptr<NodeEntity> addNodeDDD(new NodeEntity());
    name = new std::string("DDD");
    addNodeDDD->SetNodeName(name);

    std::unique_ptr<AttributeEntity> addAttrDDDname(new AttributeEntity());
    name = new std::string("name");
    addAttrDDDname.get()->SetAttrName(name);
    name = new std::string("nameDDD");
    addAttrDDDname.get()->SetAttrValue(name);
    addNodeDDD.get()->AddAttribute(std::move(addAttrDDDname));

    node.get()->FindFromTail(tree.get())->AddChild(std::move(addNodeDDD));

    name = new std::string("BBB");
    NodeEntity * testNode = node.get()->FindFromTail(tree.get(), name);

    testSuccess = true;

    delete name;
}

NodeEntityTest::NodeEntityTest()
{
}

NodeEntityTest::~NodeEntityTest()
{
}