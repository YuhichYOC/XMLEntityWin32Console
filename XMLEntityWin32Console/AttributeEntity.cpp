#include "AttributeEntity.h"

void AttributeEntity::SetAttrName(std::string * arg)
{
    attrName = arg;
}

std::string * AttributeEntity::GetAttrName()
{
    return attrName;
}

void AttributeEntity::SetAttrValue(std::string * arg)
{
    attrValue = arg;
}

std::string * AttributeEntity::GetAttrValue()
{
    return attrValue;
}

bool AttributeEntity::NameEquals(std::string * arg)
{
    if ((attrName->compare(*arg)) != 0) {
        return true;
    }
    else {
        return false;
    }
}

bool AttributeEntity::ValueEquals(std::string * arg)
{
    if ((attrValue->compare(*arg)) != 0) {
        return true;
    }
    else {
        return false;
    }
}

AttributeEntity::AttributeEntity()
{
    attrName = new std::string();
    attrValue = new std::string();
}

AttributeEntity::~AttributeEntity()
{
    delete attrName;
    delete attrValue;
}