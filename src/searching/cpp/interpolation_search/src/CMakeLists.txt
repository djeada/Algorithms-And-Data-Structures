add_library(interpolation_search "")

target_sources(
  interpolation_search
  PRIVATE interpolation_search.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/interpolation_search.h)

target_include_directories(interpolation_search PUBLIC ${CMAKE_CURRENT_LIST_DIR})
