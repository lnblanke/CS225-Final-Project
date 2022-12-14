# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# algorithm_src at lib/algorithm/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/lib/algorithm/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/bfs.cpp"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/dfs.cpp"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/dijkstra.cpp"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/tarjan.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# algorithm_src at lib/algorithm/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/lib/algorithm/*.h")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/bfs.h"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/dfs.h"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/dijkstra.h"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/dinic.h"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/kd-tree.h"
  "/workspaces/cs225/CS225-Final-Project/lib/algorithm/tarjan.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# data_src at lib/data/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/lib/data/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/lib/data/file.cpp"
  "/workspaces/cs225/CS225-Final-Project/lib/data/table.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# data_src at lib/data/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/lib/data/*.h")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/lib/data/file.h"
  "/workspaces/cs225/CS225-Final-Project/lib/data/table.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# graph_src at lib/graph/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/lib/graph/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/lib/graph/graph.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# graph_src at lib/graph/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/lib/graph/*.h")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/lib/graph/city.h"
  "/workspaces/cs225/CS225-Final-Project/lib/graph/edge.h"
  "/workspaces/cs225/CS225-Final-Project/lib/graph/graph.h"
  "/workspaces/cs225/CS225-Final-Project/lib/graph/vertex.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# sources at CMakeLists.txt:15 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/src/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()

# test_src at CMakeLists.txt:23 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225-Final-Project/tests/test-*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225-Final-Project/tests/test-bfs.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-dfs.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-dijkstra.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-dinic.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-file.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-graph.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-kdtree.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-loadfile.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-real.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-spread.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-table.cpp"
  "/workspaces/cs225/CS225-Final-Project/tests/test-tarjan.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225-Final-Project/build/CMakeFiles/cmake.verify_globs")
endif()
