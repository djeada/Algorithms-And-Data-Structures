add_library(exponential_search "")

target_sources(
  exponential_search
  PRIVATE exponential_search.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/exponential_search.h)

target_include_directories(exponential_search PUBLIC ${CMAKE_CURRENT_LIST_DIR})
