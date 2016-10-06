#include "stdafx.h"

#include "SmartPointerTest.h"

bool SmartPointerTest::GetTestSuccess()
{
    return testSuccess;
}

void SmartPointerTest::SmartPointerTest01()
{
    unique_ptr<NodeEntity> node(new NodeEntity());
    node->SetNodeName(new string("test"));

    AttributeEntity * attr = new AttributeEntity();
    attr->SetAttrName(new string("test"));

    node->AddAttribute(attr);

    testSuccess = true;
}

void SmartPointerTest::SmartPointerTest02()
{
    NodeEntity * node = new NodeEntity();
    node->SetNodeName(new string("test"));

    testSuccess = true;
}

SmartPointerTest::SmartPointerTest()
{
}

SmartPointerTest::~SmartPointerTest()
{
}