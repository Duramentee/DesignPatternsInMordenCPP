cmake_minimum_required(VERSION 3.30)
project(Builder)

set(CMAKE_CXX_STANDARD 17)

add_executable(Builder main.cpp
        html_builder.cpp
        people_builder.cpp)
