cmake_minimum_required(VERSION 3.26)
project(task_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(task_1 main.cpp
        BitArray.cpp
        BitArray.h
        BitArrayException.cpp)
