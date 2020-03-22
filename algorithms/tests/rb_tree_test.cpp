//
// Created by Ivan Ramyk on 3/21/20.
//

#include <gtest/gtest.h>
#include "../src/RedBlackTree.hpp"

TEST(RBTree, Creation){
    RedBlackTree<int> tree;
    EXPECT_EQ(3 + 5, 8);
}
