add_library(linear_search "")

target_sources(
  linear_search
  PRIVATE linear_search.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/linear_search.h)

target_include_directories(linear_search PUBLIC ${CMAKE_CURRENT_LIST_DIR})
