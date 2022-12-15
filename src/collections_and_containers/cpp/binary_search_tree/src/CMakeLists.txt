add_library(binary_search_tree "")

target_sources(
  binary_search_tree
  PRIVATE binary_search_tree.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/binary_search_tree.h)

target_include_directories(binary_search_tree PUBLIC ${CMAKE_CURRENT_LIST_DIR})
