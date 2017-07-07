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

    vector<unique_ptr<AttributeEntity>> attrList;

    vector<unique_ptr<NodeEntity>> children;

    unique_ptr<NodeEntity> Find(unique_ptr<NodeEntity> node, string tagName);

    unique_ptr<NodeEntity> Find(unique_ptr<NodeEntity> node, string tagName, string attrName, string attrValue);

    unique_ptr<NodeEntity> Find(unique_ptr<NodeEntity> node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    unique_ptr<NodeEntity> FindTail(unique_ptr<NodeEntity> node, int depth);

    bool disposed;

public:

    void SetNodeName(string arg);

    string GetNodeName();

    void SetNodeID(int arg);

    int GetNodeID();

    void SetNodeValue(string arg);

    string GetNodeValue();

    void AddAttribute(unique_ptr<AttributeEntity> arg);

    vector<unique_ptr<AttributeEntity>> GetAttrList();

    void AddChild(unique_ptr<NodeEntity> arg);

    vector<unique_ptr<NodeEntity>> GetChildren();

    bool AttrExists(string name);

    string AttrByName(string name);

    unique_ptr<NodeEntity> Find(string tagName);

    unique_ptr<NodeEntity> Find(string tagName, string attrName, string attrValue);

    unique_ptr<NodeEntity> Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    unique_ptr<NodeEntity> FindTail(int depth);

    unique_ptr<NodeEntity> Dir(string name);

    unique_ptr<NodeEntity> File(string name);

    unique_ptr<NodeEntity> Tag(string name);

    unique_ptr<NodeEntity> Attr(string name);

    unique_ptr<NodeEntity> Table(string name);

    unique_ptr<NodeEntity> SubCategory(string name);

    unique_ptr<NodeEntity> SubCategory(string childName, string grandChildName);

    unique_ptr<NodeEntity> SubCategory(string childName, string grandChildName, string greatGrandChildName);

    unique_ptr<NodeEntity> Clone();

    NodeEntity();

    void Dispose();

    ~NodeEntity();
};
