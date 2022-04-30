//
// Created by Flo on 23/04/2022.
//

#ifndef TP_PROGGAMEPLAY_WORKSPACE_TREE_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_TREE_HPP

#include <vector>
#include <functional>

namespace ExplorableTree
{
    class TreeNode
    {
    private:
        TreeNode* parent = nullptr;
        std::vector<TreeNode*> childrens;
        std::string m_name;

        explicit TreeNode(TreeNode* parent, std::string name);

    public:
        static TreeNode* createTree(std::string name);
        ~TreeNode();

        TreeNode* addChild(std::string name);
        void removeChild(TreeNode* child);
        void removeChild(size_t childIndex);

        void explore(void (*callback)(TreeNode*));

        TreeNode* prev();
        TreeNode* operator--();
        TreeNode* operator++();

        // get-set
    public:
        std::string getName();
    };
}


#endif //TP_PROGGAMEPLAY_WORKSPACE_TREE_HPP
