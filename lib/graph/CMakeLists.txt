file(GLOB_RECURSE graph_src CONFIGURE_DEPENDS *.h *.cpp)

add_library(graph ${graph_src})
target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(graph PROPERTIES LINKER_LANGUAGE CXX)