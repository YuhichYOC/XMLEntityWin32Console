#include "stdafx.h"

#include "AttributeEntity.h"

void AttributeEntity::SetAttrName(std::string * arg)
{
    attrName.reset(arg);
}

std::string * AttributeEntity::GetAttrName()
{
    return attrName.get();
}

void AttributeEntity::SetAttrValue(std::string * arg)
{
    attrValue.reset(arg);
}

std::string * AttributeEntity::GetAttrValue()
{
    return attrValue.get();
}

bool AttributeEntity::NameEquals(std::string * arg)
{
    if ((attrName->compare(*arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool AttributeEntity::ValueEquals(std::string * arg)
{
    if ((attrValue->compare(*arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

AttributeEntity::AttributeEntity()
{
    attrName = std::unique_ptr<std::string>();
    attrValue = std::unique_ptr<std::string>();
}

AttributeEntity::~AttributeEntity()
{
}