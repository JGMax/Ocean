cmake_minimum_required(VERSION 3.17)
project(Ocean)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ocean main.cpp Common.h Cell.cpp Cell.h Stone.cpp Stone.h Prey.cpp Prey.h Predator.cpp Predator.h Ocean.cpp Ocean.h Object.h Object.cpp)