add_library(heap_sort "")

target_sources(
  heap_sort
  PRIVATE heap_sort.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/heap_sort.h)

target_include_directories(heap_sort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
