/*
*
* NodeEntity.h
*
* Copyright 2016 Yuichi Yoshii
*     ‹gˆä—Yˆê @ ‹gˆäŽY‹Æ  you.65535.kir@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "stdafx.h"

#include "AttributeEntity.h"

class NodeEntity
{
private:

    string nodeName;

    int nodeId;

    string nodeValue;

    vector<AttributeEntity *> * attrList;

    vector<NodeEntity *> * childList;

    NodeEntity * Find(NodeEntity * node, string tagName);

    NodeEntity * Find(NodeEntity * node, string tagName, string attrName, string attrValue);

    NodeEntity * Find(NodeEntity * node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    NodeEntity * FindFromTail(NodeEntity * node, vector<string> tree);

    NodeEntity * FindFromTail(NodeEntity * node, vector<string> tree, string leafName);

    int FindChildIndexByName(NodeEntity * node, string name);

    bool disposed;

    void DisposeAttrList();

    void DisposeChildList();

public:

    void SetNodeName(string arg);

    string GetNodeName();

    void SetNodeID(int arg);

    int GetNodeID();

    void SetNodeValue(string arg);

    string GetNodeValue();

    void SetAttrList(vector<AttributeEntity *> * arg);

    vector<AttributeEntity *> * GetAttrList();

    void AddAttribute(AttributeEntity * arg);

    void SetChildList(vector<NodeEntity *> * arg);

    vector<NodeEntity *> * GetChildList();

    void AddChild(NodeEntity * arg);

    bool AttrExists(string name);

    string AttrByName(string name);

    NodeEntity * Find(string tagName);

    NodeEntity * Find(string tagName, string attrName, string attrValue);

    NodeEntity * Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    NodeEntity * FindFromTail(vector<string> * tree);

    NodeEntity * FindFromTail(vector<string> * tree, string leafName);

    NodeEntity * Dir(string name);

    NodeEntity * File(string name);

    NodeEntity * Tag(string name);

    NodeEntity * Attr(string name);

    NodeEntity * Table(string name);

    NodeEntity * SubCategory(string name);

    NodeEntity * SubCategory(string childName, string grandChildName);

    NodeEntity * SubCategory(string childName, string grandChildName, string greatGrandChildName);

    NodeEntity * Clone();

    NodeEntity();

    void Dispose();

    ~NodeEntity();
};
