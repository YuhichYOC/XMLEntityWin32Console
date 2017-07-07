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

    vector<AttributeEntity *> attrList;

    vector<NodeEntity *> children;

    NodeEntity * Find(NodeEntity * node, string tagName);

    NodeEntity * FindTail(NodeEntity * node, int depth);

    bool disposed;

public:

    void SetNodeName(string arg);

    string GetNodeName();

    void SetNodeID(int arg);

    int GetNodeID();

    void SetNodeValue(string arg);

    string GetNodeValue();

    void AddAttribute(AttributeEntity * arg);

    vector<AttributeEntity *> GetAttrList();

    void AddChild(NodeEntity * arg);

    vector<NodeEntity *> GetChildren();

    bool AttrExists(string name);

    string AttrByName(string name);

    NodeEntity * Find(string tagName);

    NodeEntity * FindTail(int depth);

    NodeEntity();

    void Dispose();

    ~NodeEntity();
};
