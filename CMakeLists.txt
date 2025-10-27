cmake_minimum_required(VERSION 3.10)
project(Battleship)

include_directories(include)

add_executable(battleship
    src/main.cpp
    src/board.cpp
    src/ship.cpp
    src/game.cpp
)
