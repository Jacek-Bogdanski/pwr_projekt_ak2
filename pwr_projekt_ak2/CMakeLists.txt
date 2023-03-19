cmake_minimum_required(VERSION 3.24)
project (pwr_projekt_ak2)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -S")

set(SOURCE_FILES
        main.cpp
        source/ArithmeticLibrary.cpp
        source/ArithmeticLibrary.h
        )

add_executable(aLib ${SOURCE_FILES})
