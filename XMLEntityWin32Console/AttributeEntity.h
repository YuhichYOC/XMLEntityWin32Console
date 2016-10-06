#pragma once

#include "stdafx.h"

class AttributeEntity
{
private:

    std::string * attrName;

    std::string * attrValue;

    bool disposed;

public:

    void SetAttrName(std::string * arg);

    std::string * GetAttrName();

    std::string * CloneAttrName();

    void SetAttrValue(std::string * arg);

    std::string * GetAttrValue();

    std::string * CloneAttrValue();

    bool NameEquals(std::string * arg);

    bool ValueEquals(std::string * arg);

    AttributeEntity * Clone();

    AttributeEntity();

    void Dispose();

    ~AttributeEntity();
};
