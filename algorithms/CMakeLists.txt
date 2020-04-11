cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms src/BinaryTree.hpp src/RedBlackTree.hpp src/SplayTree.hpp src/BPlusTree.hpp src/BPlusTree.tpp
                tests/catch.cpp tests/bplus_tree_test.cpp)
target_link_libraries(algorithms)