cmake_minimum_required(VERSION 3.24)
project (pwr_projekt_ak2)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -S")

enable_testing()

set(SOURCE_FILES
        source/TwosComplement_Num.cpp
        source/TwosComplement_Num.h
        source/TwosComplement_Exception.cpp
        source/TwosComplement_Exception.h)

add_executable(calc ${SOURCE_FILES})
add_subdirectory(source)
add_subdirectory(tests)
