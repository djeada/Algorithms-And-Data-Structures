add_library(avl_tree "")

target_sources(
  avl_tree
  PRIVATE avl_tree.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/avl_tree.h)

target_include_directories(avl_tree PUBLIC ${CMAKE_CURRENT_LIST_DIR})
