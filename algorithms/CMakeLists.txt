cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms src/BinaryTree.hpp src/RedBlackTree.hpp src/SplayTree.hpp src/BPlusTree.hpp src/BPlusTree.tpp
                tests/catch.cpp tests/bplus_tree_test.cpp src/BinomialHeap.tpp src/BinomialHeap.hpp tests/binomial_heap_test.cpp src/AVLTree.tpp src/AVLTree.hpp tests/avltree_test.cpp)
target_link_libraries(algorithms)