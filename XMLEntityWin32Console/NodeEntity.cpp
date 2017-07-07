/*
*
* NodeEntity.cpp
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

#include "stdafx.h"

#include "NodeEntity.h"

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName)
{
    if ((node->GetNodeName().compare(tagName)) == 0) {
        return node;
    }
    size_t loop = node->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(node->GetChildren().at(i), tagName);
        if (ret != nullptr) {
            return ret;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindTail(NodeEntity * node, int depth)
{
    if (depth == 1) {
        return node;
    }
    else {
        depth--;
        size_t count = node->GetChildren().size();
        return FindTail(node->GetChildren().at(count - 1), depth);
    }
}

void NodeEntity::SetNodeName(string arg)
{
    nodeName.assign(arg);
}

string NodeEntity::GetNodeName()
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

void NodeEntity::SetNodeValue(string arg)
{
    nodeValue.assign(arg);
}

string NodeEntity::GetNodeValue()
{
    return nodeValue;
}

void NodeEntity::AddAttribute(AttributeEntity * arg)
{
    attrList.push_back(arg);
}

vector<AttributeEntity *> NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::AddChild(NodeEntity * arg)
{
    children.push_back(arg);
}

vector<NodeEntity *> NodeEntity::GetChildren()
{
    return children;
}

bool NodeEntity::AttrExists(string name)
{
    bool ret = false;
    size_t loop = attrList.size();
    for (size_t i = 0; i < loop; i++) {
        if (attrList.at(i)->NameEquals(name)) {
            ret = true;
        }
    }
    return ret;
}

string NodeEntity::AttrByName(string name)
{
    string ret;
    size_t loop = attrList.size();
    for (size_t i = 0; i < loop; i++) {
        if (attrList.at(i)->NameEquals(name)) {
            ret = attrList.at(i)->GetAttrValue();
        }
    }
    return ret;
}

NodeEntity * NodeEntity::Find(string tagName)
{
    if ((this->GetNodeName().compare(tagName) == 0)) {
        return this;
    }
    size_t loop = this->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(this->GetChildren().at(i), tagName);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindTail(int depth)
{
    if (depth == 1) { return this; }
    depth--;
    size_t count = this->GetChildren().size();
    return FindTail(this->GetChildren().at(count - 1), depth);
}

NodeEntity::NodeEntity()
{
    disposed = false;
}

void NodeEntity::Dispose()
{
    size_t iloop = attrList.size();
    for (size_t i = 0; i < iloop; i++) {
        delete attrList.at(i);
    }
    size_t jloop = children.size();
    for (size_t j = 0; j < jloop; j++) {
        delete children.at(j);
    }
    disposed = true;
}

NodeEntity::~NodeEntity()
{
    if (!disposed) {
        Dispose();
    }
}