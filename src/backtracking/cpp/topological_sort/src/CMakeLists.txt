add_library(topological_sort "")

target_sources(
  topological_sort
  PRIVATE topological_sort.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/topological_sort.h)

target_include_directories(topological_sort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
