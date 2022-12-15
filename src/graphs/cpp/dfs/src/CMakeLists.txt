add_library(dfs "")

target_sources(
  dfs
  PRIVATE dfs.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/dfs.h)

target_include_directories(dfs PUBLIC ${CMAKE_CURRENT_LIST_DIR})
