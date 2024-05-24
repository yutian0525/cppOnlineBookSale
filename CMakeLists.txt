cmake_minimum_required(VERSION 3.28)
project(online)

set(CMAKE_CXX_STANDARD 17)

add_executable(online main.cpp
        layfolk.cpp
        buyer.cpp
        honouredGuest.cpp
        book.cpp
        member.cpp)
