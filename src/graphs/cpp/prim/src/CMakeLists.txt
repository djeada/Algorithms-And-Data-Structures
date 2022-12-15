add_library(prim "")

target_sources(
  prim
  PRIVATE prim.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/prim.h)

target_include_directories(prim PUBLIC ${CMAKE_CURRENT_LIST_DIR})
