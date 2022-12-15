add_library(insertion_sort "")

target_sources(
  insertion_sort
  PRIVATE insertion_sort.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/insertion_sort.h)

target_include_directories(insertion_sort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
