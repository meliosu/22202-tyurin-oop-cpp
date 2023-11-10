cmake_minimum_required(VERSION 3.26)
project(task_2)

set(CMAKE_CXX_STANDARD 11)

# add_compile_options(-O3 -march-native)

add_executable(task_2 main.cpp
        Game.cpp
        Game.h
        Rule.cpp
        Rule.h
        Renderer.cpp
        Renderer.h
        State.cpp
        State.h)
