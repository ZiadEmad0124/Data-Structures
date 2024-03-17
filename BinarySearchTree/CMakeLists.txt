cmake_minimum_required(VERSION 3.27)
project(BinarySearchTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(BinarySearchTree BinarySearchTree/main.cpp
        BinarySearchTree/BinarySearchTree.h
        BinarySearchTree/node.h)
