file(GLOB_RECURSE data_src CONFIGURE_DEPENDS *.h *.cpp)

add_library(data ${data_src})
target_include_directories(data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})