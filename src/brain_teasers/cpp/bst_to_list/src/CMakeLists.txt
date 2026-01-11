add_library(bst_to_list "")

target_sources(
  bst_to_list
  PRIVATE bst_to_list.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/bst_to_list.h)

target_include_directories(bst_to_list PUBLIC ${CMAKE_CURRENT_LIST_DIR})
