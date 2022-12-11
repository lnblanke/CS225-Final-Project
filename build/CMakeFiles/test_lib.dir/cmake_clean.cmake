file(REMOVE_RECURSE
  "libtest_lib.a"
  "libtest_lib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/test_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
