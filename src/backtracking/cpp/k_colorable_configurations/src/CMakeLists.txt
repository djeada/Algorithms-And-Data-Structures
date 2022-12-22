add_library(k_colorable_configurations "")

target_sources(
  k_colorable_configurations
  PRIVATE k_colorable_configurations.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/k_colorable_configurations.h)

target_include_directories(k_colorable_configurations PUBLIC ${CMAKE_CURRENT_LIST_DIR})
