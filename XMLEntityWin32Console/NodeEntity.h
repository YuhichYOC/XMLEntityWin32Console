#pragma once

#include "stdafx.h"

#include "AttributeEntity.h"

class NodeEntity
{
private:

    std::string * nodeName;

    int nodeId;

    std::string * nodeValue;

    std::vector<AttributeEntity> * attrList;
    
    std::vector<NodeEntity> * childList;

    NodeEntity * Find(NodeEntity * node, std::string * tagName);

    NodeEntity * Find(NodeEntity * node, std::string * tagName, std::string * attrName, std::string * attrValue);

    NodeEntity * Find(NodeEntity * node, std::string * tagName, std::string * attr1Name, std::string * attr1Value, std::string * attr2Name, std::string * attr2Value);

public:

    void SetNodeName(std::string * arg);

    std::string * GetNodeName();

    void SetNodeID(int arg);

    int GetNodeID();

    void SetNodeValue(std::string * arg);

    std::string * GetNodeValue();

    void SetAttrList(std::vector<AttributeEntity> * arg);

    std::vector<AttributeEntity> * GetAttrList();

    void SetChildList(std::vector<NodeEntity> * arg);

    std::vector<NodeEntity> * GetChildList();

    bool AttrExists(std::string * name);

    std::string * AttrByName(std::string * name);

    NodeEntity * Find(std::string * tagName);

    NodeEntity * Find(std::string * tagName, std::string * attrName, std::string * attrValue);

    NodeEntity * Find(std::string * tagName, std::string * attr1Name, std::string * attr1Value, std::string * attr2Name, std::string * attr2Value);

    NodeEntity * Dir(std::string * name);

    NodeEntity * File(std::string * name);

    NodeEntity * Tag(std::string * name);

    NodeEntity * Attr(std::string * name);

    NodeEntity * Table(std::string * name);

    NodeEntity * SubCategory(std::string * name);

    NodeEntity * SubCategory(std::string * childName, std::string * grandChildName);

    NodeEntity * SubCategory(std::string * childName, std::string * grandChildName, std::string * greatGrandChildName);

    NodeEntity();

    ~NodeEntity();
};

