add_library(binary_search "")

target_sources(
  binary_search
  PRIVATE binary_search.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/binary_search.h)

target_include_directories(binary_search PUBLIC ${CMAKE_CURRENT_LIST_DIR})
