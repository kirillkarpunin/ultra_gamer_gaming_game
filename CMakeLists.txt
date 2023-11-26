cmake_minimum_required(VERSION 3.26)
project(oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop src/Main.cpp
        src/entities/player/Player.cpp
        src/entities/player/Player.h
        src/entities/player/PlayerManager.cpp
        src/entities/player/PlayerManager.h
        src/world/map/Cell.cpp
        src/world/map/Cell.h
        src/world/map/Playground.cpp
        src/world/map/Playground.h
        src/world/map/MapGenerator.cpp
        src/world/map/MapGenerator.h
        src/input_output/Renderer.cpp
        src/input_output/Renderer.h
        src/world/events/IEvent.h
        src/world/events/Trap.cpp
        src/world/events/Trap.h
        src/world/events/Chest.cpp
        src/world/events/Chest.h
        src/world/events/ExplodeWall.cpp
        src/world/events/ExplodeWall.h
        src/world/events/Teleport.cpp
        src/world/events/Teleport.h
        src/sup/circular_linked_list/CircularLinkedList.cpp
        src/sup/circular_linked_list/CircularLinkedList.h
        src/sup/circular_linked_list/Node.cpp
        src/sup/circular_linked_list/Node.h
        src/game/Game.cpp
        src/game/Game.h
        src/game/structure/Menu.cpp
        src/game/structure/Menu.h
        src/input_output/Config.cpp
        src/input_output/Config.h
        src/input_output/Printer.cpp
        src/input_output/Printer.h
        src/game/structure/Level.cpp
        src/game/structure/Level.h
        src/input_output/input_interface/IInput.h
        src/input_output/input_interface/FileInput.cpp
        src/input_output/input_interface/FileInput.h
        src/input_output/input_interface/ConsoleInput.cpp
        src/input_output/input_interface/ConsoleInput.h
        src/game/updater/Updater.cpp
        src/game/updater/Updater.h
)
