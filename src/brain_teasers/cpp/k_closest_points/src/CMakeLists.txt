add_library(k_closest_points "")

target_sources(
  k_closest_points
  PRIVATE k_closest_points.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/k_closest_points.h)

target_include_directories(k_closest_points PUBLIC ${CMAKE_CURRENT_LIST_DIR})
