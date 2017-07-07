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

unique_ptr<NodeEntity> NodeEntity::Find(unique_ptr<NodeEntity> node, string tagName)
{
    unique_ptr<NodeEntity> ret = move(node);
    if ((ret->GetNodeName().compare(tagName)) == 0) {
        return move(ret);
    }
    size_t loop = ret->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        ret = Find(move(ret->GetChildren().at(i)), tagName);
    }
    return move(ret);
}

unique_ptr<NodeEntity> NodeEntity::Find(unique_ptr<NodeEntity> node, string tagName, string attrName, string attrValue)
{
    unique_ptr<NodeEntity> ret = move(node);
    if ((ret->GetNodeName().compare(tagName)) == 0) {
        if (ret->AttrExists(attrName) && (ret->AttrByName(attrName).compare(attrValue) == 0)) {
            return move(ret);
        }
    }
    size_t loop = ret->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        ret = Find(move(ret->GetChildren().at(i)), tagName, attrName, attrValue);
    }
    return move(ret);
}

unique_ptr<NodeEntity> NodeEntity::Find(unique_ptr<NodeEntity> node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    unique_ptr<NodeEntity> ret = move(node);
    if ((ret->GetNodeName().compare(tagName)) == 0) {
        if (ret->AttrExists(attr1Name) && ret->AttrExists(attr2Name) && (ret->AttrByName(attr1Name).compare(attr1Value) == 0) && (ret->AttrByName(attr2Name).compare(attr2Value) == 0)) {
            return move(ret);
        }
    }
    size_t loop = ret->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        ret = Find(move(ret->GetChildren().at(i)), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
    }
    return move(ret);
}

unique_ptr<NodeEntity> NodeEntity::FindTail(unique_ptr<NodeEntity> node, int depth)
{
    if (depth == 1) {
        return move(node);
    }
    else {
        depth--;
        size_t count = node->GetChildren().size();
        return move(FindTail(move(node->GetChildren().at(count - 1)), depth));
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

void NodeEntity::AddAttribute(unique_ptr<AttributeEntity> arg)
{
    attrList.push_back(arg);
}

vector<unique_ptr<AttributeEntity>> NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::AddChild(unique_ptr<NodeEntity> arg)
{
    children.push_back(arg);
}

vector<unique_ptr<NodeEntity>> NodeEntity::GetChildren()
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

unique_ptr<NodeEntity> NodeEntity::Find(string tagName)
{
    unique_ptr<NodeEntity> ret(this);
    if ((ret->GetNodeName().compare(tagName) == 0)) {
        return move(ret);
    }
    size_t loop = ret->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        ret = Find(move(ret->GetChildren().at(i)), tagName);
    }
    return move(ret);
}

unique_ptr<NodeEntity> NodeEntity::Find(string tagName, string attrName, string attrValue)
{
    unique_ptr<NodeEntity> ret(this);
    if ((ret->GetNodeName().compare(tagName) == 0)) {
        if (ret->AttrExists(attrName) && (ret->AttrByName(attrName).compare(attrValue) == 0)) {
            return move(ret);
        }
    }
    size_t loop = ret->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        ret = Find(move(ret->GetChildren().at(i)), tagName, attrName, attrValue);
    }
    return move(ret);
}

unique_ptr<NodeEntity> NodeEntity::Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    unique_ptr<NodeEntity> ret(this);
    if ((ret->GetNodeName().compare(tagName) == 0)) {
        if (ret->AttrExists(attr1Name) && ret->AttrExists(attr2Name) && (ret->AttrByName(attr1Name).compare(attr1Value) == 0) && (ret->AttrByName(attr2Name).compare(attr2Value) == 0)) {
            return move(ret);
        }
    }
    size_t loop = ret->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        ret = Find(move(ret->GetChildren().at(i)), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
    }
    return move(ret);
}

unique_ptr<NodeEntity> NodeEntity::FindTail(int depth)
{
    unique_ptr<NodeEntity> ret(this);
    if (depth == 1) { return move(ret); }
    depth--;
    size_t count = ret->GetChildren().size();
    return move(FindTail(move(ret->GetChildren().at(count - 1)), depth));
}

unique_ptr<NodeEntity> NodeEntity::Dir(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Dir = "Dir";
    string arg4Name = "name";
    return move(Find(arg1Item, arg2Type, arg3Dir, arg4Name, name));
}

unique_ptr<NodeEntity> NodeEntity::File(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3File = "File";
    string arg4Name = "name";
    return move(Find(arg1Item, arg2Type, arg3File, arg4Name, name));
}

unique_ptr<NodeEntity> NodeEntity::Tag(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Tag = "Tag";
    string arg4Name = "name";
    return move(Find(arg1Item, arg2Type, arg3Tag, arg4Name, name));
}

unique_ptr<NodeEntity> NodeEntity::Attr(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Attr = "Attr";
    string arg4Name = "name";
    return move(Find(arg1Item, arg2Type, arg3Attr, arg4Name, name));
}

unique_ptr<NodeEntity> NodeEntity::Table(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Table = "Table";
    string arg4Name = "name";
    return move(Find(arg1Item, arg2Type, arg3Table, arg4Name, name));
}

unique_ptr<NodeEntity> NodeEntity::SubCategory(string name)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    return move(Find(arg1Category, arg2Name, name));
}

unique_ptr<NodeEntity> NodeEntity::SubCategory(string childName, string grandChildName)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    string arg3Category = "Category";
    string arg4Name = "name";
    return move(Find(arg1Category, arg2Name, childName)->Find(arg3Category, arg4Name, grandChildName));
}

unique_ptr<NodeEntity> NodeEntity::SubCategory(string childName, string grandChildName, string greatGrandChildName)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    string arg3Category = "Category";
    string arg4Name = "name";
    string arg5Category = "Category";
    string arg6Name = "name";
    return move(Find(arg1Category, arg2Name, childName)->Find(arg3Category, arg4Name, grandChildName)->Find(arg5Category, arg6Name, greatGrandChildName));
}

unique_ptr<NodeEntity> NodeEntity::Clone()
{
    unique_ptr<NodeEntity> clone;

    for (size_t i = 0; i < attrList.size(); i++) {
        unique_ptr<AttributeEntity> cloneAttr = move(attrList.at(i)->Clone());
        clone->AddAttribute(move(cloneAttr));
    }

    for (size_t j = 0; j < children.size(); j++) {
        unique_ptr<NodeEntity> cloneChild = move(children.at(j)->Clone());
        clone->AddChild(move(cloneChild));
    }

    clone->SetNodeName(this->GetNodeName());
    clone->SetNodeID(this->GetNodeID());
    clone->SetNodeValue(this->GetNodeValue());

    return move(clone);
}

NodeEntity::NodeEntity()
{
    disposed = false;
}

void NodeEntity::Dispose()
{
    disposed = true;
}

NodeEntity::~NodeEntity()
{
    if (!disposed) {
        Dispose();
    }
}