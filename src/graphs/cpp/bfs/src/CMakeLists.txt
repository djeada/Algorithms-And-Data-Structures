add_library(bfs "")

target_sources(
  bfs
  PRIVATE bfs.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/bfs.h)

target_include_directories(bfs PUBLIC ${CMAKE_CURRENT_LIST_DIR})
