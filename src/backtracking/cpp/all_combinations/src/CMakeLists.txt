add_library(all_combinations "")

target_sources(
  all_combinations
  PRIVATE all_combinations.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/all_combinations.h)

target_include_directories(all_combinations PUBLIC ${CMAKE_CURRENT_LIST_DIR})
