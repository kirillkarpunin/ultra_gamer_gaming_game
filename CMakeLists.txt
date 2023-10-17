cmake_minimum_required(VERSION 3.26)
project(oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop Main.cpp
        entities/player/Player.cpp
        entities/player/Player.h
        entities/player/Player-Manager.cpp
        entities/player/Player-Manager.h
        world/Cell.cpp
        world/Cell.h
        world/Playground.cpp
        world/Playground.h)
