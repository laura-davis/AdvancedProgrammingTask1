cmake_minimum_required(VERSION 3.19)
project(AdvancedProgramming)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvancedProgramming Task1/main.cpp
        Task1/Game.cpp
        Task1/Game.h
        Task1/GameComponent.cpp
        Task1/GameComponent.h
        Task1/DrawableGameComponent.cpp
        Task1/DrawableGameComponent.h
        )