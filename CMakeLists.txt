cmake_minimum_required(VERSION 3.21)
project(AdventOfCpp)

set(CMAKE_CXX_STANDARD 20)

## Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

## Source
set(ADVENTOFCPP_SOURCES SolutionRegistry.cpp SolutionRegistry.h 2015/Solution201501.cpp 2015/Solution201502.cpp)

## Executable
add_executable(AdventOfCpp main.cpp ${ADVENTOFCPP_SOURCES})
add_custom_target(copy-input-files ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Input ${CMAKE_BINARY_DIR}/Input)
add_dependencies(AdventOfCpp copy-input-files)

## Test Executable
enable_testing()
add_executable(AdventOfCpp_Test ${ADVENTOFCPP_SOURCES} SolutionTesting.h)
target_compile_definitions(AdventOfCpp_Test PUBLIC TEST)
target_link_libraries(AdventOfCpp_Test gtest_main)
include(GoogleTest)
gtest_discover_tests(AdventOfCpp_Test)