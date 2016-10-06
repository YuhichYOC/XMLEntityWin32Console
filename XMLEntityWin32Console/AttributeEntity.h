#pragma once

#include "stdafx.h"

class AttributeEntity
{
private:

    std::string * attrName;

    std::string * attrValue;

public:

    void SetAttrName(std::string * arg);

    std::string * GetAttrName();

    void SetAttrValue(std::string * arg);

    std::string * GetAttrValue();

    bool NameEquals(std::string * arg);

    bool ValueEquals(std::string * arg);

    AttributeEntity();

    ~AttributeEntity();
};
