add_library(aStar "")

target_sources(
  aStar
  PRIVATE a_star.cpp graph.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/a_star.h)

target_include_directories(aStar PUBLIC ${CMAKE_CURRENT_LIST_DIR})
