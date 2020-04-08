//
// Created by ivan on 08.04.20.
//

#include <gtest/gtest.h>
#include "../src/SplayTree.hpp"
#include <cmath>
#include <set>

TEST(SplayTree, CreationSearcing){
    //RedBlackTreeNode<int> * node;
    SplayTree<int> tree;
    tree.insert(3);
    EXPECT_TRUE(tree.search(3) != nullptr);
    EXPECT_EQ(tree.search(3)->value(), 3);
    tree.insert(5);
    tree.insert(2);
    tree.insert(17);
    EXPECT_TRUE(tree.search(11) == nullptr);
    return;//
    EXPECT_EQ(tree.search(2)->value(), 2);
    EXPECT_EQ(tree.search(17)->value(), 17);
}