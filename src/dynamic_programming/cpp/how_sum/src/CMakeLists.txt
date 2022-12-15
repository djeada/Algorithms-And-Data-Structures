add_library(how_sum "")

target_sources(
  how_sum
  PRIVATE how_sum.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/how_sum.h)

target_include_directories(how_sum PUBLIC ${CMAKE_CURRENT_LIST_DIR})
