file(GLOB_RECURSE algorithm_src CONFIGURE_DEPENDS *.h *.cpp)

add_library(algorithm ${algorithm_src})
target_include_directories(algorithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})