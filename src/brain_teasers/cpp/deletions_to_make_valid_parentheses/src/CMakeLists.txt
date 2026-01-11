add_library(valid_parentheses "")

target_sources(
  valid_parentheses
  PRIVATE valid_parentheses.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/valid_parentheses.h)

target_include_directories(valid_parentheses PUBLIC ${CMAKE_CURRENT_LIST_DIR})
