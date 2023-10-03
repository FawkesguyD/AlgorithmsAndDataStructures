cmake_minimum_required(VERSION 3.23)
project(AlgorithmsAndDataStructures)

set(CMAKE_CXX_STANDARD 23)

add_executable(AlgorithmsAndDataStructures pr_1/pr_1.cpp pr_1/ex1.h pr_1/ex2.h pr_1/ex3.h
        pr_2/InterpolationSearch.cpp
        pr_2/InterpolationSearch.h
        pr_2/test.cpp
)
