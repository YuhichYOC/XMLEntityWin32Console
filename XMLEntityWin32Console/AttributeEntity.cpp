#include "stdafx.h"

#include "AttributeEntity.h"

void AttributeEntity::SetAttrName(string * arg)
{
    attrName.reset(arg);
}

string * AttributeEntity::GetAttrName()
{
    return attrName.get();
}

string * AttributeEntity::CloneAttrName()
{
    string * cloneName = new string(*attrName);
    return cloneName;
}

void AttributeEntity::SetAttrValue(string * arg)
{
    attrValue.reset(arg);
}

string * AttributeEntity::GetAttrValue()
{
    return attrValue.get();
}

string * AttributeEntity::CloneAttrValue()
{
    string * cloneValue = new string(*attrValue);
    return cloneValue;
}

bool AttributeEntity::NameEquals(string * arg)
{
    if ((attrName->compare(*arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool AttributeEntity::ValueEquals(string * arg)
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