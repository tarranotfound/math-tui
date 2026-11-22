cmake_minimum_required(VERSION 3.20)
project(math_tui VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(math-tui src/main.cpp)
target_include_directories(math-tui PRIVATE include)
target_compile_options(math-tui PRIVATE -Wall -Wextra -Wpedantic)

include(CTest)
if(BUILD_TESTING)
    add_executable(math-tui-tests tests/test_calculator.cpp)
    target_include_directories(math-tui-tests PRIVATE include)
    target_compile_options(math-tui-tests PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME calculator COMMAND math-tui-tests)
endif()
