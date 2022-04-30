//
// Created by Flo on 23/04/2022.
//

#include <iostream>
#include <algorithm>

#include "Tree.hpp"

namespace ExplorableTree
{
    TreeNode::TreeNode(TreeNode *parent, std::string name)
        : parent(parent)
        , m_name(std::move(name))
    {

    }

    TreeNode::~TreeNode()
    {
        for(auto children : childrens)
        {
            delete children;
        }
    }

    TreeNode *TreeNode::createTree(std::string name) {
        return new TreeNode(nullptr, std::move(name));
    }

    TreeNode *TreeNode::addChild(std::string childName)
    {
        auto newChild = new TreeNode(this, std::move(childName));
        childrens.push_back(newChild);

        return newChild;
    }

    void TreeNode::removeChild(TreeNode* child)
    {
        auto childItr = std::find(childrens.begin(), childrens.end(), child);
        removeChild(std::distance(childrens.begin(), childItr));
    }

    void TreeNode::removeChild(size_t childIndex)
    {
        delete childrens[childIndex];

        auto childItr = childrens.begin();
        std::advance(childItr, childIndex);
        childrens.erase(childItr);
    }

    void TreeNode::explore(void (*callback)(TreeNode*))
    {
        callback(this);

        for(auto& child : childrens)
        {
            child->explore(callback);
        }
    }

    TreeNode *TreeNode::prev() {
        return parent;
    }

    TreeNode *TreeNode::operator--() { return prev(); }

    TreeNode *TreeNode::operator++()
    {
        return nullptr;
    }

    std::string TreeNode::getName() { return m_name; }
}