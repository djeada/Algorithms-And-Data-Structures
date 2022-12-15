add_library(longestCommonSubsequence "")

target_sources(
  longestCommonSubsequence
  PRIVATE longest_common_subsequence.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/longest_common_subsequence.h)

target_include_directories(longestCommonSubsequence
                           PUBLIC ${CMAKE_CURRENT_LIST_DIR})
