add_library(sparse_vector "")

target_sources(
  sparse_vector
  PRIVATE sparse_vector.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/sparse_vector.h)

target_include_directories(sparse_vector PUBLIC ${CMAKE_CURRENT_LIST_DIR})
