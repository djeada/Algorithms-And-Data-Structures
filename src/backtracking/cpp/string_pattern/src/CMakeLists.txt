add_library(string_pattern "")

target_sources(
  string_pattern
  PRIVATE string_pattern.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/string_pattern.h)

target_include_directories(string_pattern PUBLIC ${CMAKE_CURRENT_LIST_DIR})
