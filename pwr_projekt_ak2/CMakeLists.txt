cmake_minimum_required(VERSION 3.24)
project (pwr_projekt_ak2)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -S")

enable_testing()

set(SOURCE_FILES
        main.cpp
        source/ArithmeticLibrary.cpp
        source/ArithmeticLibrary.h
        source/testy.cpp source/U2Parser.cpp)

add_executable(calc ${SOURCE_FILES})
add_subdirectory(source)
add_subdirectory(tests)
