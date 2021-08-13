cmake_minimum_required(VERSION 3.19)
project(AdvancedProgramming)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvancedProgrammingTask1
        main.cpp
        Game.cpp
        Game.h
        GameComponent.cpp
        GameComponent.h
        DrawableGameComponent.cpp
        DrawableGameComponent.h
        )