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

std::string * AttributeEntity::CloneAttrName()
{
    std::string * cloneName = new std::string(*attrName);
    return cloneName;
}

void AttributeEntity::SetAttrValue(std::string * arg)
{
    attrValue.reset(arg);
}

std::string * AttributeEntity::GetAttrValue()
{
    return attrValue.get();
}

std::string * AttributeEntity::CloneAttrValue()
{
    std::string * cloneValue = new std::string(*attrValue);
    return cloneValue;
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

AttributeEntity * AttributeEntity::Clone()
{
    AttributeEntity * clone = new AttributeEntity();
    clone->SetAttrName(CloneAttrName());
    clone->SetAttrValue(CloneAttrValue());
    return clone;
}

AttributeEntity::AttributeEntity()
{
    attrName = unique_ptr<string>();
    attrValue = unique_ptr<string>();
    disposed = false;
}

void AttributeEntity::Dispose()
{
    disposed = true;
}

AttributeEntity::~AttributeEntity()
{
    if (!disposed) {
        Dispose();
    }
}