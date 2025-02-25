cmake_minimum_required(VERSION 3.30)
project(Proxy)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proxy main.cpp
        main.cpp
        BankAccount.hpp
        Property.hpp
        Image.hpp
        PingPong.hpp)
