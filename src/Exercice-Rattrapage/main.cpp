//
// Created by Flo on 23/04/2022.
//

#include <iostream>
#include "includes/Tree.hpp"

using namespace ExplorableTree;

/*namespace ExplorableTree
{*/

int main()
{
    // Tree Declaration

    auto rootNode = TreeNode::createTree("tree");

    auto n1 = rootNode->addChild("n1");
    auto n2 = rootNode->addChild("n2");

    auto n11 = n1->addChild("n11");
    auto n12 = n1->addChild("n12");

    auto n13 = n2->addChild("n13");
    auto n14 = n2->addChild("n14");

    auto n21 = n12->addChild("n21");
    auto n31 = n14->addChild("n31");

    auto n41 = n31->addChild("n41");


    std::cout << "---------- Going up in arborescence" << std::endl;

    // Going up in arborescence

    for(TreeNode* itr = n41; itr != nullptr; itr = itr->prev())
    {
        std::cout << itr->getName() << std::endl;
    }

    // Exploring arborescence

    std::cout << "---------- Exploring arborescence" << std::endl;

    rootNode->explore([](TreeNode* element) -> void
    {
        std::cout << element->getName() << std::endl;
    });

    return 0;
}

//}