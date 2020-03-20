cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_library(algorithms BinaryTree.hpp RedBlackTree.cpp RedBlackTree.hpp)