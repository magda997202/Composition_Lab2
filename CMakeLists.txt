cmake_minimum_required(VERSION 3.20)
project(MultiFileIDE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MultiFile_Refactoring_IDE
        main.cpp
        Page.cpp
        Book.cpp
)