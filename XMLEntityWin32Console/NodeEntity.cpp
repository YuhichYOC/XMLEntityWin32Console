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
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName().compare(tagName)) == 0) {
        return node;
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName, string attrName, string attrValue)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName().compare(tagName)) == 0) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName).compare(attrValue) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName, attrName, attrValue);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName().compare(tagName)) == 0) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name).compare(attr1Value) == 0) && (node->AttrByName(attr2Name).compare(attr2Value) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindFromTail(NodeEntity * node, vector<string> tree)
{
    if (node == nullptr) {
        node = this;
    }
    if (tree.size() == 0) {
        return node;
    }
    int pos = FindChildIndexByName(node, tree.at(0));
    tree.erase(tree.begin());
    if (pos >= 0) {
        return FindFromTail(node->GetChildList()->at(pos), tree);
    }
    else {
        return nullptr;
    }
}

NodeEntity * NodeEntity::FindFromTail(NodeEntity * node, vector<string> tree, string leafName)
{
    if (node == nullptr) {
        node = this;
    }
    if (tree.size() == 0) {
        int retPos = FindChildIndexByName(node, leafName);
        if (retPos >= 0) {
            return node->GetChildList()->at(retPos);
        }
        else {
            return nullptr;
        }
    }
    int pos = FindChildIndexByName(node, tree.at(0));
    tree.erase(tree.begin());
    if (pos >= 0) {
        return FindFromTail(node->GetChildList()->at(pos), tree, leafName);
    }
    else {
        return nullptr;
    }
}

int NodeEntity::FindChildIndexByName(NodeEntity * node, string name)
{
    int pos = -1;
    int iLoopCount = (int)node->GetChildList()->size();
    for (int i = 0; i < iLoopCount; i++) {
        if ((node->GetChildList()->at(i)->GetNodeName().compare(name)) == 0) {
            pos = i;
        }
    }
    return pos;
}

void NodeEntity::DisposeAttrList()
{
    int iLoopCount = attrList->size();
    for (int i = 0; i < iLoopCount; i++) {
        attrList->at(i)->Dispose();
        delete attrList->at(i);
    }
    delete attrList;
}

void NodeEntity::DisposeChildList()
{
    int iLoopCount = childList->size();
    for (int i = 0; i < iLoopCount; i++) {
        childList->at(i)->Dispose();
        delete childList->at(i);
    }
    delete childList;
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

void NodeEntity::SetAttrList(vector<AttributeEntity *> * arg)
{
    attrList = arg;
}

vector<AttributeEntity *> * NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::AddAttribute(AttributeEntity * arg)
{
    attrList->push_back(arg);
}

void NodeEntity::SetChildList(vector<NodeEntity *> * arg)
{
    childList = arg;
}

vector<NodeEntity *> * NodeEntity::GetChildList()
{
    return childList;
}

void NodeEntity::AddChild(NodeEntity * arg)
{
    childList->push_back(arg);
}

bool NodeEntity::AttrExists(string name)
{
    bool ret = false;
    for (size_t i = 0; i < attrList->size(); i++) {
        if (attrList->at(i)->NameEquals(name)) {
            ret = true;
        }
    }
    return ret;
}

string NodeEntity::AttrByName(string name)
{
    string ret;
    for (size_t i = 0; i < attrList->size(); i++) {
        if (attrList->at(i)->NameEquals(name)) {
            ret = attrList->at(i)->GetAttrValue();
        }
    }
    return ret;
}

NodeEntity * NodeEntity::Find(string tagName)
{
    NodeEntity * node = this;
    if ((node->GetNodeName().compare(tagName) == 0)) {
        return node;
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * ret = Find(node->GetChildList()->at(i), tagName);
        if (ret != nullptr) {
            return ret;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(string tagName, string attrName, string attrValue)
{
    NodeEntity * node = this;
    if ((node->GetNodeName().compare(tagName) == 0)) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName).compare(attrValue) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * ret = Find(node->GetChildList()->at(i), tagName, attrName, attrValue);
        if (ret != nullptr) {
            return ret;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    NodeEntity * node = this;
    if ((node->GetNodeName().compare(tagName) == 0)) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name).compare(attr1Value) == 0) && (node->AttrByName(attr2Name).compare(attr2Value) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindFromTail(vector<string> * tree)
{
    NodeEntity * node = this;
    if (tree->size() <= 1) {
        return node;
    }
    else {
        vector<string> subtree = *tree;
        subtree.erase(subtree.begin());
        return FindFromTail(node, subtree);
    }
}

NodeEntity * NodeEntity::FindFromTail(vector<string> * tree, string leafName)
{
    NodeEntity * node = this;
    if (tree->size() <= 0) {
        return node;
    }
    else {
        if (leafName.length() == 0) {
            return FindFromTail(tree);
        }
        /*
        else if (tree->at(tree->size() - 1)->compare(*leafName) == 0) {
        return FindFromTail(tree);
        }
        */
        else {
            vector<string> subtree = *tree;
            subtree.erase(subtree.begin());
            return FindFromTail(node, subtree, leafName);
        }
    }
}

NodeEntity * NodeEntity::Dir(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Dir = "Dir";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Dir, arg4Name, name);
}

NodeEntity * NodeEntity::File(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3File = "File";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3File, arg4Name, name);
}

NodeEntity * NodeEntity::Tag(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Tag = "Tag";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Tag, arg4Name, name);
}

NodeEntity * NodeEntity::Attr(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Attr = "Attr";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Attr, arg4Name, name);
}

NodeEntity * NodeEntity::Table(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Table = "Table";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Table, arg4Name, name);
}

NodeEntity * NodeEntity::SubCategory(string name)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    return Find(arg1Category, arg2Name, name);
}

NodeEntity * NodeEntity::SubCategory(string childName, string grandChildName)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    string arg3Category = "Category";
    string arg4Name = "name";
    return Find(arg1Category, arg2Name, childName)->Find(arg3Category, arg4Name, grandChildName);
}

NodeEntity * NodeEntity::SubCategory(string childName, string grandChildName, string greatGrandChildName)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    string arg3Category = "Category";
    string arg4Name = "name";
    string arg5Category = "Category";
    string arg6Name = "name";
    return Find(arg1Category, arg2Name, childName)->Find(arg3Category, arg4Name, grandChildName)->Find(arg5Category, arg6Name, greatGrandChildName);
}

NodeEntity * NodeEntity::Clone()
{
    NodeEntity * clone = new NodeEntity();

    for (size_t i = 0; i < attrList->size(); i++) {
        AttributeEntity * cloneAttr = attrList->at(i)->Clone();
        clone->AddAttribute(cloneAttr);
    }

    for (size_t j = 0; j < childList->size(); j++) {
        clone->AddChild(childList->at(j)->Clone());
    }

    clone->SetNodeName(this->GetNodeName());
    clone->SetNodeID(this->GetNodeID());
    clone->SetNodeValue(this->GetNodeValue());

    return clone;
}

NodeEntity::NodeEntity()
{
    attrList = new vector<AttributeEntity *>();
    childList = new vector<NodeEntity *>();
    disposed = false;
}

void NodeEntity::Dispose()
{
    DisposeAttrList();
    DisposeChildList();
    disposed = true;
}

NodeEntity::~NodeEntity()
{
    if (!disposed) {
        Dispose();
    }
}