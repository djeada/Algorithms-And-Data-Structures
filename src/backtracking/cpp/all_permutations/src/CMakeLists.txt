add_library(all_permutations "")

target_sources(
  all_permutations
  PRIVATE all_permutations.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/all_permutations.h)

target_include_directories(all_permutations PUBLIC ${CMAKE_CURRENT_LIST_DIR})
