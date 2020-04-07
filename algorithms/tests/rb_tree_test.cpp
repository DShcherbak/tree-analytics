//
// Created by Ivan Ramyk on 3/21/20.
//

#include <gtest/gtest.h>
#include "../src/RedBlackTree.hpp"
#include <iostream>

TEST(RBTree, Creation){
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
    for (int i = 0 ; i < 20; ++i) {
        tree.insert(i);
    }
    /*std::vector<std::pair<int, int>> order = tree.print();
    for (auto i : order) {
        std::cout << "\t" <<i.first << " " << i.second << "\n";
    }*/
}

TEST(RBTree, Remove){
    /*RedBlackTree<int> tree;
    for (int i = 0 ; i < 20; ++i) {
        tree.insert(i);
    }
    auto * node = tree.search(7);
    std::cout << node->value();
    tree.remove(node);*/
    //EXPECT_EQ(tree.search(5), nullptr);
}
