add_library(knight_tour "")

target_sources(
  knight_tour
  PRIVATE knight_tour.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/knight_tour.h)

target_include_directories(knight_tour PUBLIC ${CMAKE_CURRENT_LIST_DIR})
