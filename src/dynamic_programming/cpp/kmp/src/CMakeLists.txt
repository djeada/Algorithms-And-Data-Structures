add_library(kmp "")

target_sources(
  kmp
  PRIVATE kmp.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/kmp.h)

target_include_directories(kmp PUBLIC ${CMAKE_CURRENT_LIST_DIR})
