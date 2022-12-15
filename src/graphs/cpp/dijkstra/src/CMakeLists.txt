add_library(dijkstra "")

target_sources(
  dijkstra
  PRIVATE dijkstra.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/dijkstra.h)

target_include_directories(dijkstra PUBLIC ${CMAKE_CURRENT_LIST_DIR})
