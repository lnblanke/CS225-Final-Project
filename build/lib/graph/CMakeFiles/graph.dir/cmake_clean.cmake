file(REMOVE_RECURSE
  "libgraph.a"
  "libgraph.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/graph.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
