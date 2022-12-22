add_library(minimax "")

target_sources(
  minimax
  PRIVATE minimax.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/minimax.h)

target_include_directories(minimax PUBLIC ${CMAKE_CURRENT_LIST_DIR})
