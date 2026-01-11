add_library(range_sum_bst "")

target_sources(
  range_sum_bst
  PRIVATE range_sum_bst.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/range_sum_bst.h)

target_include_directories(range_sum_bst PUBLIC ${CMAKE_CURRENT_LIST_DIR})
