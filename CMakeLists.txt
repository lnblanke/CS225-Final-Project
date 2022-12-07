cmake_minimum_required(VERSION 3.10)
project(cs225_final_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gdwarf-4 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

add_subdirectory(lib/algorithm)
add_subdirectory(lib/data)
add_subdirectory(lib/graph)

add_library(test_lib tests/test.h tests/test.cpp)
target_include_directories(test_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)
add_library(exec ${sources})

add_executable(main src/main.cpp)

target_link_libraries(main PUBLIC algorithm graph data exec test_lib)

find_package(Catch2 3 REQUIRED)
file(GLOB_RECURSE test_src CONFIGURE_DEPENDS tests/test-*.cpp)
add_executable(test ${test_src})
target_link_libraries(test PUBLIC Catch2::Catch2WithMain algorithm graph data test_lib)