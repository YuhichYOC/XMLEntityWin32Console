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

    void SetAttrValue(std::string * arg);

    std::string * GetAttrValue();

    bool NameEquals(std::string * arg);

    bool ValueEquals(std::string * arg);

    AttributeEntity();

    void Dispose();

    ~AttributeEntity();
};
