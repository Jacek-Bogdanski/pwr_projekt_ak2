include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
        AddTests.cpp
        SubtractTests.cpp
        MultiplyTests.cpp
        DivideTests.cpp
        ../../source/TwosComplement_Num.cpp
        ../../source/TwosComplement_Num.h
        ../../source/TwosComplement_ArithmeticLibrary.cpp
        ../../source/TwosComplement_ArithmeticLibrary.h
        )

add_executable(calcTests ${SOURCE_FILES})


target_link_libraries(calcTests gtest gtest_main)
