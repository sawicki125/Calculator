cmake_minimum_required(VERSION 3.7)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest-master)

include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)

set(SOURCE_FILES src/Calculator.cpp src/EquationParser.cpp
		 src/EquationVerifier.cpp)
set(TEST_FILES src/ut/main.cpp src/ut/TestCalculator.cpp
               src/ut/TestEquationVerifier.cpp src/ut/TestEquationParser.cpp)

add_executable(${PROJECT_NAME} src/main.cpp  ${SOURCE_FILES})
add_executable(tests ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(tests gtest gtest_main)

