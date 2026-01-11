add_library(right_side_view "")

target_sources(
  right_side_view
  PRIVATE right_side_view.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/right_side_view.h)

target_include_directories(right_side_view PUBLIC ${CMAKE_CURRENT_LIST_DIR})
