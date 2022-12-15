add_library(quick_sort "")

target_sources(
  quick_sort
  PRIVATE quick_sort.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/quick_sort.h)

target_include_directories(quick_sort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
