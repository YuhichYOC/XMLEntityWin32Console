#include "stdafx.h"

#include "NodeEntity.h"

NodeEntity * NodeEntity::Find(NodeEntity * node, std::string * tagName)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName()->compare(*tagName)) == 0) {
        return node;
    }
    for (int i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(&node->GetChildList()->at(i), tagName);
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
    if ((node->GetNodeName()->compare(*tagName)) == 0) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName)->compare(*attrValue) == 0)) {
            return node;
        }
    }
    for (int i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(&node->GetChildList()->at(i), tagName, attrName, attrValue);
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
    if ((node->GetNodeName()->compare(*tagName)) == 0) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name)->compare(*attr1Value) == 0) && (node->AttrByName(attr2Name)->compare(*attr2Value) == 0)) {
            return node;
        }
    }
    for (int i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(&node->GetChildList()->at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindFromTail(NodeEntity * node, std::vector<std::string> tree)
{
    if (node == nullptr) {
        node = this;
    }
    if (tree.size() == 0) {
        return node;
    }
    std::string name = tree.at(0);
    std::vector<std::string> subtree;
    for (int i = 1; i < tree.size(); i++) {
        subtree.push_back(tree.at(i));
    }
    if ((node->GetNodeName()->compare(name)) == 0) {
        return FindFromTail(node, subtree);
    }
    int pos = 0;
    for (int j = 0; j < node->GetChildList()->size(); j++) {
        if ((node->GetChildList()->at(j).GetNodeName()->compare(name)) == 0) {
            pos = j;
        }
    }
    return FindFromTail(&node->GetChildList()->at(pos), subtree);
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

void NodeEntity::SetAttrList(std::vector<AttributeEntity> * arg)
{
    attrList = arg;
}

std::vector<AttributeEntity> * NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::AddAttribute(AttributeEntity * arg)
{
    attrList->push_back(*arg);
}

void NodeEntity::SetChildList(std::vector<NodeEntity> * arg)
{
    childList = arg;
}

std::vector<NodeEntity> * NodeEntity::GetChildList()
{
    return childList;
}

void NodeEntity::AddChild(NodeEntity * arg)
{
    childList->push_back(*arg);
}

bool NodeEntity::AttrExists(std::string * name)
{
    bool retVal = false;
    for (int i = 0; i < attrList->size(); i++) {
        if (attrList->at(i).NameEquals(name)) {
            retVal = true;
        }
    }
    return retVal;
}

std::string * NodeEntity::AttrByName(std::string * name)
{
    std::string * retVal = new std::string();
    for (int i = 0; i < attrList->size(); i++) {
        if (attrList->at(i).NameEquals(name)) {
            retVal = attrList->at(i).GetAttrValue();
        }
    }
    return retVal;
}

NodeEntity * NodeEntity::Find(std::string * tagName)
{
    NodeEntity * node = this;
    if ((node->GetNodeName()->compare(*tagName) == 0)) {
        return node;
    }
    for (int i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(&node->GetChildList()->at(i), tagName);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(std::string * tagName, std::string * attrName, std::string * attrValue)
{
    NodeEntity * node = this;
    if ((node->GetNodeName()->compare(*tagName) == 0)) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName)->compare(*attrValue) == 0)) {
            return node;
        }
    }
    for (int i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(&node->GetChildList()->at(i), tagName, attrName, attrValue);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(std::string * tagName, std::string * attr1Name, std::string * attr1Value, std::string * attr2Name, std::string * attr2Value)
{
    NodeEntity * node = this;
    if ((node->GetNodeName()->compare(*tagName) == 0)) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name)->compare(*attr1Value) == 0) && (node->AttrByName(attr2Name)->compare(*attr2Value) == 0)) {
            return node;
        }
    }
    for (int i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(&node->GetChildList()->at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindFromTail(std::vector<std::string> * tree)
{
    NodeEntity * node = this;
    return FindFromTail(node, *tree);
}

NodeEntity * NodeEntity::Dir(std::string * name)
{
    std::string arg1Item = "Item";
    std::string arg2Type = "type";
    std::string arg3Dir = "Dir";
    std::string arg4Name = "name";
    return Find(&arg1Item, &arg2Type, &arg3Dir, &arg4Name, name);
}

NodeEntity * NodeEntity::File(std::string * name)
{
    std::string arg1Item = "Item";
    std::string arg2Type = "type";
    std::string arg3File = "File";
    std::string arg4Name = "name";
    return Find(&arg1Item, &arg2Type, &arg3File, &arg4Name, name);
}

NodeEntity * NodeEntity::Tag(std::string * name)
{
    std::string arg1Item = "Item";
    std::string arg2Type = "type";
    std::string arg3Tag = "Tag";
    std::string arg4Name = "name";
    return Find(&arg1Item, &arg2Type, &arg3Tag, &arg4Name, name);
}

NodeEntity * NodeEntity::Attr(std::string * name)
{
    std::string arg1Item = "Item";
    std::string arg2Type = "type";
    std::string arg3Attr = "Attr";
    std::string arg4Name = "name";
    return Find(&arg1Item, &arg2Type, &arg3Attr, &arg4Name, name);
}

NodeEntity * NodeEntity::Table(std::string * name)
{
    std::string arg1Item = "Item";
    std::string arg2Type = "type";
    std::string arg3Table = "Table";
    std::string arg4Name = "name";
    return Find(&arg1Item, &arg2Type, &arg3Table, &arg4Name, name);
}

NodeEntity * NodeEntity::SubCategory(std::string * name)
{
    std::string arg1Category = "Category";
    std::string arg2Name = "name";
    return Find(&arg1Category, &arg2Name, name);
}

NodeEntity * NodeEntity::SubCategory(std::string * childName, std::string * grandChildName)
{
    std::string arg1Category = "Category";
    std::string arg2Name = "name";
    std::string arg3Category = "Category";
    std::string arg4Name = "name";
    return Find(&arg1Category, &arg2Name, childName)->Find(&arg3Category, &arg4Name, grandChildName);
}

NodeEntity * NodeEntity::SubCategory(std::string * childName, std::string * grandChildName, std::string * greatGrandChildName)
{
    std::string arg1Category = "Category";
    std::string arg2Name = "name";
    std::string arg3Category = "Category";
    std::string arg4Name = "name";
    std::string arg5Category = "Category";
    std::string arg6Name = "name";
    return Find(&arg1Category, &arg2Name, childName)->Find(&arg3Category, &arg4Name, grandChildName)->Find(&arg5Category, &arg6Name, greatGrandChildName);
}

NodeEntity::NodeEntity()
{
    nodeName = new std::string();
    nodeValue = new std::string();
    attrList = new std::vector<AttributeEntity>();
    childList = new std::vector<NodeEntity>();
}

NodeEntity::~NodeEntity()
{
    delete nodeName;
    delete nodeValue;
    delete attrList;
    delete childList;
}