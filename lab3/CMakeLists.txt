cmake_minimum_required(VERSION 3.17)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_exercise_03 main.cpp Figure.cpp Figure.h Point.cpp Point.h
        Rhombus.cpp Rhombus.h Pentagon.cpp Pentagon.h Hexagon.cpp Hexagon.h)