cmake_minimum_required(VERSION 3.29)
project(Alien_Hunt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Alien_Hunt
        Alien.cpp
        Driver.cpp
        Entity.cpp
        GameController.cpp
        Hazard.cpp
        Person.cpp
        Room.cpp
        Survivor.cpp
        Treasure.cpp
        Weapon.cpp
)
