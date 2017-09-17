cmake_minimum_required(VERSION 3.7)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest-master)

include_directories(googletest-master/googletest/include)

include_directories(googletest-master/googlemock/include)


set(SOURCE_FILES main.cpp)
add_executable (${PROJECT_NAME} src/main.cpp src/Calculator.cpp src/EquationParser.cpp src/EquationVerifier.cpp src/ut/TestCalculator.cpp src/ut/TestEquationVerifier.cpp src/ut/TestEquationParser.cpp)


target_link_libraries(${PROJECT_NAME} gtest gtest_main)
