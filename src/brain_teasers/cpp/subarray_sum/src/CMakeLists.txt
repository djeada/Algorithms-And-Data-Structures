add_library(subarray_sum "")

target_sources(
  subarray_sum
  PRIVATE subarray_sum.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/subarray_sum.h)

target_include_directories(subarray_sum PUBLIC ${CMAKE_CURRENT_LIST_DIR})
