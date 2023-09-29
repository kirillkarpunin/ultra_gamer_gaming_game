cmake_minimum_required(VERSION 3.26)
project(oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop Main.cpp
        Player.cpp
        Player.h
        Player-Manager.cpp
        Player-Manager.h
        Cell.cpp
        Cell.h
        Playground.cpp
        Playground.h)
