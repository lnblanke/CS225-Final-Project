file(GLOB_RECURSE data_cpp CONFIGURE_DEPENDS *.h *.cpp)

add_library(data ${data_cpp})
target_include_directories(data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})