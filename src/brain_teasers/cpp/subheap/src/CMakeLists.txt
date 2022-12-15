add_library(subheap "")

target_sources(
  subheap
  PRIVATE subheap.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/subheap.h)

target_include_directories(subheap PUBLIC ${CMAKE_CURRENT_LIST_DIR})
