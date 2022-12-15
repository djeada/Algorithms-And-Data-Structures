add_library(longestIncreasingSubarray "")

target_sources(
  longestIncreasingSubarray
  PRIVATE longest_increasing_subarray.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/longest_increasing_subarray.h)

target_include_directories(longestIncreasingSubarray
                           PUBLIC ${CMAKE_CURRENT_LIST_DIR})
