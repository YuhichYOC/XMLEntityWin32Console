#pragma once

#include "stdafx.h"

class AttributeEntity
{
private:

    unique_ptr<string> attrName;

    unique_ptr<string> attrValue;

    bool disposed;

public:

    void SetAttrName(string * arg);

    string * GetAttrName();

    string * CloneAttrName();

    void SetAttrValue(string * arg);

    string * GetAttrValue();

    string * CloneAttrValue();

    bool NameEquals(string * arg);

    bool ValueEquals(string * arg);

    AttributeEntity * Clone();

    AttributeEntity();

    void Dispose();

    ~AttributeEntity();
};
