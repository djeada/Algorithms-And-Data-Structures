add_library(kruskal "")

target_sources(
  kruskal
  PRIVATE kruskal.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/kruskal.h)

target_include_directories(kruskal PUBLIC ${CMAKE_CURRENT_LIST_DIR})
