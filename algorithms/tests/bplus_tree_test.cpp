//
// Created by darik on 4/10/2020.
//

#include "catch.hpp"
#include "../src/BPlusTree.hpp"

TEST_CASE("Searching in B+-tree", "[B+-tree]") {
    std::shared_ptr<BPlusTree<int>> tree = std::make_shared<BPlusTree<int>>(5);
}

TEST_CASE("Insertion in B+-tree", "[B+-tree]") {
    std::shared_ptr<BPlusTree<int>> tree = std::make_shared<BPlusTree<int> >(4);
    tree->insert(0, std::make_shared<int>(0));
    for (int i = 0; i < 100; ++i) {
        tree->insert(i, std::make_shared<int>(i));
    }
    for (int i = 0; i < 5; ++i) {
        CHECK(tree->search(rand() % 100) != nullptr);
    }
}

TEST_CASE("Removing from B+-tree", "[B+-tree]") {
    std::shared_ptr<BPlusTree<int>> tree = std::make_shared<BPlusTree<int> >(5);

}