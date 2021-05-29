cmake_minimum_required(VERSION 3.19)
project(algos_graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(algos_graph main.cpp MatrixGraph/MatrixGraph.cpp MatrixGraph/MatrixGraph.h SetGraph/SetGraph.cpp SetGraph/SetGraph.h)

add_library(ListGraph ./ListGraph/ListGraph.cpp IGraph/IGraph_funcs.cpp)

target_link_libraries(algos_graph ListGraph)