//
// Created by darik on 4/10/2020.
//

#include "catch.hpp"
#include "../src/BPlusTree.hpp"
#include <memory>

using std::shared_ptr;
using std::make_shared;

TEST_CASE("Searching in B+-tree", "algorithms") {
    shared_ptr<BPlusTree<int>> tree = make_shared<BPlusTree<int>>(5);
    for (int i = 0; i < 100; ++i) {
        tree->insert(i, make_shared<int>(i));
    }

    for (int i = 0; i < 10; ++i) {
        int searched{rand() % 100};
        CHECK(*tree->search(searched) == searched);
    }

    for (int i = 0; i < 5; ++i) {
        CHECK(tree->search(rand() + 100) == nullptr);
    }
}

TEST_CASE("Insertion in B+-tree", "algorithms") {
    shared_ptr<BPlusTree<int>> tree = make_shared<BPlusTree<int> >(4);
    for (int i = 0; i < 100; ++i) {
        tree->insert(i, make_shared<int>(i));
    }
    for (int i = 0; i < 5; ++i) {
        CHECK(tree->search(rand() % 100) != nullptr);
    }
}

TEST_CASE("Removing from B+-tree", "algorithms") {
    shared_ptr<BPlusTree<int>> tree = make_shared<BPlusTree<int> >(5);
    for (int i = 0; i < 199; ++i) {
        tree->insert(i, make_shared<int>(i));
    }
    for (int i = 0; i < 10; ++i) {
        int removing = rand() % 199;
        tree->remove(removing);
        CHECK(tree->search(removing) == nullptr);
    }
}

TEST_CASE("Final test in B+-tree", "algorithms") {
    shared_ptr<BPlusTree<int>> tree = make_shared<BPlusTree<int>>(13);
    for (int i = 0; i < 1000; ++i) {
        int element = rand() % 15000;
        tree->insert(element, make_shared<int>(element));
    }
    for (int i = 0; i < 5; ++i) {
        int element = rand() % 15000;
        tree->remove(element);
        CHECK(tree->search(element) == nullptr);
        tree->insert(element, make_shared<int>(element));
        CHECK(tree->search(element) != nullptr);
    }
}

TEST_CASE("Iterators in B+-tree", "algorithms") {
    BPlusTree<int> tree(13);
    for (auto i = 0; i < 100; ++i) {
        tree.insert(i, make_shared<int>(i));
    }
    int counter{0};
    auto it = tree.begin();
    for(; it != tree.end(); ++it){
        CHECK(*it == counter);
        ++counter;
    }
    CHECK(counter == 100);
}