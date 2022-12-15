add_library(graph "")

target_sources(
  graph
  PRIVATE graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/graph.h)

target_include_directories(graph PUBLIC ${CMAKE_CURRENT_LIST_DIR})
