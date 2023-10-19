cmake_minimum_required(VERSION 3.26)
project(oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop Main.cpp
        entities/player/Player.cpp
        entities/player/Player.h
        entities/player/Player-Manager.cpp
        entities/player/Player-Manager.h
        world/map/Cell.cpp
        world/map/Cell.h
        world/map/Playground.cpp
        world/map/Playground.h
        world/map/MapGenerator.cpp
        world/map/MapGenerator.h
        input_output/Renderer.cpp
        input_output/Renderer.h
        world/events/IEvent.h
        world/events/Trap.cpp
        world/events/Trap.h
        world/events/Chest.cpp
        world/events/Chest.h)
