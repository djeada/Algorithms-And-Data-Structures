add_library(best_sum "")

target_sources(
  best_sum
  PRIVATE best_sum.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/best_sum.h)

target_include_directories(best_sum PUBLIC ${CMAKE_CURRENT_LIST_DIR})
