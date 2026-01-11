add_library(lca "")

target_sources(
  lca
  PRIVATE lca.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lca.h)

target_include_directories(lca PUBLIC ${CMAKE_CURRENT_LIST_DIR})
