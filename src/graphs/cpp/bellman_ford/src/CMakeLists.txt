add_library(bellman_ford "")

target_sources(
  bellman_ford
  PRIVATE bellman_ford.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/bellman_ford.h)

target_include_directories(bellman_ford PUBLIC ${CMAKE_CURRENT_LIST_DIR})
