cmake_minimum_required(VERSION 3.17)
project(oop_lab2)

set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test1.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test2.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test3.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(oop_exercise_02 main.cpp TimePoint.cpp TimePoint.h)