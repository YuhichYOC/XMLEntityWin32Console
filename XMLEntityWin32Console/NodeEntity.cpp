#include "NodeEntity.h"

NodeEntity::NodeEntity()
{
}

NodeEntity::~NodeEntity()
{
}

NodeEntity * NodeEntity::Find(NodeEntity * node, std::string * tagName)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName()->compare(*tagName)) != 0) {
        return node;
    }
    for each (NodeEntity var in node->GetChildList()->begin)
    {
        NodeEntity * retVal = Find(&var, tagName);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, std::string * tagName, std::string * attrName, std::string * attrValue)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName()->compare(*tagName)) != 0) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName)->compare(*attrValue) != 0)) {
            return node;
        }
    }
    for each (NodeEntity var in node->GetChildList()->begin)
    {
        NodeEntity * retVal = Find(&var, tagName, attrName, attrValue);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, std::string * tagName, std::string * attr1Name, std::string * attr1Value, std::string * attr2Name, std::string * attr2Value)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName()->compare(*tagName)) != 0) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name)->compare(*attr1Value) != 0) && (node->AttrByName(attr2Name)->compare(*attr2Value) != 0)) {
            return node;
        }
    }
    for each (NodeEntity var in node->GetChildList()->begin)
    {
        NodeEntity * retVal = Find(&var, tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

void NodeEntity::SetNodeName(std::string * arg)
{
    nodeName = arg;
}

std::string * NodeEntity::GetNodeName()
{
    return nodeName;
}

void NodeEntity::SetNodeID(int arg)
{
    nodeId = arg;
}

int NodeEntity::GetNodeID()
{
    return nodeId;
}

void NodeEntity::SetNodeValue(std::string * arg)
{
    nodeValue = arg;
}

std::string * NodeEntity::GetNodeValue()
{
    return nodeValue;
}

void NodeEntity::SetAttrList(std::vector<AttributeEntity>* arg)
{
    attrList = arg;
}

std::vector<AttributeEntity>* NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::SetChildList(std::vector<NodeEntity>* arg)
{
    childList = arg;
}

std::vector<NodeEntity>* NodeEntity::GetChildList()
{
    return childList;
}

bool NodeEntity::AttrExists(std::string * name)
{
    bool retVal = false;
    for each (AttributeEntity var in attrList->begin)
    {
        if (var.NameEquals(name)) {
            retVal = true;
        }
    }
    return retVal;
}

std::string * NodeEntity::AttrByName(std::string * name)
{
    std::string * retVal = new std::string();
    for each (AttributeEntity var in attrList->begin)
    {
        if (var.NameEquals(name)) {
            retVal = var.GetAttrValue();
        }
    }
    return retVal;
}