cmake_minimum_required(VERSION 3.26)
project(task_1)

add_subdirectory(google_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(task_1
        BitArray.cpp
        BitArray.h
        BitArrayException.cpp)
