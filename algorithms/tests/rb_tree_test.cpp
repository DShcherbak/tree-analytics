//
// Created by Ivan Ramyk on 3/21/20.
//

#include <gtest/gtest.h>
#include "../src/RedBlackTree.hpp"
#include <iostream>
#include <cmath>

TEST(RBTree, CreationSearcing){
    //RedBlackTreeNode<int> * node;
    RedBlackTree<int> tree;
    tree.insert(3);
    EXPECT_TRUE(tree.search(3) != nullptr);
    EXPECT_EQ(tree.search(3)->value(), 3);
    tree.insert(5);
    tree.insert(2);
    tree.insert(17);
    EXPECT_TRUE(tree.search(11) == nullptr);
    EXPECT_EQ(tree.search(2)->value(), 2);
    EXPECT_EQ(tree.search(17)->value(), 17);
}

TEST(RBTree, Height){
    RedBlackTree<int> tree;
    for (int i = 0 ; i < 100000; ++i) {
        tree.insert(i);
        EXPECT_TRUE(tree.height() <int(2 * (std::log2(i + 1) + 1)));
    }
}

TEST(RBTree, Remove){
    RedBlackTree<int> tree;
    for (int i = 0 ; i < 20; ++i) {
        tree.insert(i);
    }
    tree.remove(tree.search(5));
    tree.remove(tree.search(6));
    tree.remove(tree.search(7));
    tree.remove(tree.search(8));
    tree.remove(tree.search(9));
    for (int i = 0; i < 5; ++i){
        EXPECT_TRUE(tree.search(i) != nullptr);
    }
    for (int i = 5; i < 10; ++i)
        EXPECT_EQ(tree.search(5), nullptr);
    for (int i = 10; i < 20; ++i){
        EXPECT_TRUE(tree.search(i) != nullptr);
    }
}
