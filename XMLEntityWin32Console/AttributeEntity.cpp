#include "stdafx.h"

#include "AttributeEntity.h"

void AttributeEntity::SetAttrName(string arg)
{
    attrName.assign(arg);
}

string AttributeEntity::GetAttrName()
{
    return attrName;
}

string * AttributeEntity::CloneAttrName()
{
    string * cloneName = new string();
    cloneName->assign(attrName);
    return cloneName;
}

void AttributeEntity::SetAttrValue(string arg)
{
    attrValue.assign(arg);
}

string AttributeEntity::GetAttrValue()
{
    return attrValue;
}

string * AttributeEntity::CloneAttrValue()
{
    string * cloneValue = new string();
    cloneValue->assign(attrValue);
    return cloneValue;
}

bool AttributeEntity::NameEquals(string arg)
{
    if ((attrName.compare(arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool AttributeEntity::ValueEquals(string arg)
{
    if ((attrValue.compare(arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

AttributeEntity * AttributeEntity::Clone()
{
    AttributeEntity * clone = new AttributeEntity();
    clone->SetAttrName(*CloneAttrName());
    clone->SetAttrValue(*CloneAttrValue());
    return clone;
}

AttributeEntity::AttributeEntity()
{
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