add_library(vector "")

target_sources(
  vector
  PRIVATE vector.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/vector.h)

target_include_directories(vector PUBLIC ${CMAKE_CURRENT_LIST_DIR})
