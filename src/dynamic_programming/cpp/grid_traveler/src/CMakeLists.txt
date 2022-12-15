add_library(gridTravelers "")

target_sources(
  gridTravelers
  PRIVATE grid_travelers.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/grid_travelers.h)

target_include_directories(gridTravelers PUBLIC ${CMAKE_CURRENT_LIST_DIR})
