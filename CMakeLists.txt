cmake_minimum_required(VERSION 3.10)
project(cs225_final_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

add_executable(main src/main.cpp)

add_subdirectory(lib/algorithm)
add_subdirectory(lib/data)
add_subdirectory(lib/graph)

target_link_libraries(main PUBLIC algorithm graph data)

find_package(Catch2 3 REQUIRED)
add_executable(test tests/test-bfs.cpp)
target_link_libraries(test PUBLIC algorithm graph data)
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
