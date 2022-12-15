add_library(selection_sort "")

target_sources(
  selection_sort
  PRIVATE selection_sort.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/selection_sort.h)

target_include_directories(selection_sort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
