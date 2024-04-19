cmake_minimum_required(VERSION 3.10)
project(NHF CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(NHF NHF_main.cpp)

add_executable(NHF_test NHF_test.cpp)

add_library(graph STATIC graph/graph.cpp graph/graph.h)
add_library(node STATIC node/node.cpp node/node.h)
add_library(edge STATIC edge/edge.cpp edge/edge.h)
add_library(vector STATIC helper/vector.cpp helper/vector.h)
add_library(algorithm STATIC algorithm/algorithm.cpp algorithm/algorithm.h)
add_library(memtrace STATIC helper/memtrace.cpp helper/memtrace.h)
add_library(gtest_lite STATIC helper/gtest_lite.h)

add_dependencies(NHF_test memtrace gtest_lite vector node edge graph algorithm)

add_dependencies(NHF memtrace vector node edge graph algorithm)

add_definitions(-Wdeprecated -pedantic -DMEMTRACE)

add_test(Full NHF_test)