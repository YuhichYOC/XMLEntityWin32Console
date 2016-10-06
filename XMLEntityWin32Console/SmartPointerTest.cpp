#include "stdafx.h"

#include "SmartPointerTest.h"

bool SmartPointerTest::GetTestSuccess()
{
    return testSuccess;
}

void SmartPointerTest::SmartPointerTest01()
{
    std::unique_ptr<NodeEntity> node(new NodeEntity());
    node->SetNodeName(new std::string("test"));

    AttributeEntity * attr = new AttributeEntity();
    attr->SetAttrName(new std::string("test"));

    node->AddAttribute(attr);

    testSuccess = true;
}

void SmartPointerTest::SmartPointerTest02()
{
    NodeEntity * node = new NodeEntity();
    node->SetNodeName(new std::string("test"));

    testSuccess = true;
}

SmartPointerTest::SmartPointerTest()
{
}

SmartPointerTest::~SmartPointerTest()
{
}