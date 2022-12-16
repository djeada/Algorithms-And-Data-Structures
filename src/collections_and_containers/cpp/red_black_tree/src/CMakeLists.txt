add_library(red_black_tree "")

target_sources(
  red_black_tree
  PRIVATE red_black_tree.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/red_black_tree.h)

target_include_directories(red_black_tree PUBLIC ${CMAKE_CURRENT_LIST_DIR})
