cmake_minimum_required(VERSION 3.8)
project(adt_bts)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Red_Black_tree.cpp Red_Black_tree.h)
add_executable(adt_bts ${SOURCE_FILES})