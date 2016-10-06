#pragma once

#include "stdafx.h"

#include "AttributeEntity.h"

class NodeEntity
{
private:

    unique_ptr<string> nodeName;

    int nodeId;

    unique_ptr<string> nodeValue;

    vector<AttributeEntity *> * attrList;

    vector<NodeEntity *> * childList;

    NodeEntity * Find(NodeEntity * node, string * tagName);

    NodeEntity * Find(NodeEntity * node, string * tagName, string * attrName, string * attrValue);

    NodeEntity * Find(NodeEntity * node, string * tagName, string * attr1Name, string * attr1Value, string * attr2Name, string * attr2Value);

    NodeEntity * FindFromTail(NodeEntity * node, vector<string *> tree);

    NodeEntity * FindFromTail(NodeEntity * node, vector<string *> tree, string leafName);

    int FindChildIndexByName(NodeEntity * node, string name);

    bool disposed;

    void DisposeAttrList();

    void DisposeChildList();

public:

    void SetNodeName(string * arg);

    string * GetNodeName();

    void SetNodeID(int arg);

    int GetNodeID();

    void SetNodeValue(string * arg);

    string * GetNodeValue();

    void SetAttrList(vector<AttributeEntity *> * arg);

    vector<AttributeEntity *> * GetAttrList();

    void AddAttribute(AttributeEntity * arg);

    void SetChildList(vector<NodeEntity *> * arg);

    vector<NodeEntity *> * GetChildList();

    void AddChild(NodeEntity * arg);

    bool AttrExists(string * name);

    string * AttrByName(string * name);

    NodeEntity * Find(string * tagName);

    NodeEntity * Find(string * tagName, string * attrName, string * attrValue);

    NodeEntity * Find(string * tagName, string * attr1Name, string * attr1Value, string * attr2Name, string * attr2Value);

    NodeEntity * FindFromTail(vector<string *> * tree);

    NodeEntity * FindFromTail(vector<string *> * tree, string * leafName);

    NodeEntity * Dir(string * name);

    NodeEntity * File(string * name);

    NodeEntity * Tag(string * name);

    NodeEntity * Attr(string * name);

    NodeEntity * Table(string * name);

    NodeEntity * SubCategory(string * name);

    NodeEntity * SubCategory(string * childName, string * grandChildName);

    NodeEntity * SubCategory(string * childName, string * grandChildName, string * greatGrandChildName);

    NodeEntity * Clone();

    NodeEntity();

    void Dispose();

    ~NodeEntity();
};
