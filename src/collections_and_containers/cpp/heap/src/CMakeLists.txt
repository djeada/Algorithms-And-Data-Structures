add_library(heap "")

target_sources(
  heap
  PRIVATE heap.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/heap.h)

target_include_directories(heap PUBLIC ${CMAKE_CURRENT_LIST_DIR})
