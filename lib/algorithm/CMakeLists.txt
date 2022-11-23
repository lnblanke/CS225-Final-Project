file(GLOB_RECURSE algorithm_cpp CONFIGURE_DEPENDS *.h *.cpp)

add_library(algorithm ${algorithm_cpp})
target_include_directories(algorithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})