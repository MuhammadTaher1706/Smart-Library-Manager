cmake_minimum_required(VERSION 3.20)
project(SmartLibraryManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(SmartLibraryManager
        Book.h
        Book.cpp
        User.h
        User.cpp
        Library.h
        Library.cpp)
