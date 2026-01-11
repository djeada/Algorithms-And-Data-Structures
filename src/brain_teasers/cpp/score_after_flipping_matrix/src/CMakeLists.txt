add_library(matrix_score "")

target_sources(
  matrix_score
  PRIVATE matrix_score.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/matrix_score.h)

target_include_directories(matrix_score PUBLIC ${CMAKE_CURRENT_LIST_DIR})
