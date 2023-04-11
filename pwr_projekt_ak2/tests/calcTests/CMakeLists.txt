include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(calcTests AddTests.cpp)

target_link_libraries(calcTests gtest gtest_main)
