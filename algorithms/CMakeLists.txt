cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(algorithms src/BinaryTree.hpp src/RedBlackTree.cpp src/RedBlackTree.hpp tests/test.hpp main.cpp tests/rb_tree_test.cpp)
target_link_libraries(algorithms gtest gtest_main)