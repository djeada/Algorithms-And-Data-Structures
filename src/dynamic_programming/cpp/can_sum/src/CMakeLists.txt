add_library(can_sum "")

target_sources(
  can_sum
  PRIVATE can_sum.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/can_sum.h)

target_include_directories(can_sum PUBLIC ${CMAKE_CURRENT_LIST_DIR})
