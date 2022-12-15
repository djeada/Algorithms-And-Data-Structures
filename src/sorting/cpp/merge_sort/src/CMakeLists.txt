add_library(merge_sort "")

target_sources(
  merge_sort
  PRIVATE merge_sort.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/merge_sort.h)

target_include_directories(merge_sort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
