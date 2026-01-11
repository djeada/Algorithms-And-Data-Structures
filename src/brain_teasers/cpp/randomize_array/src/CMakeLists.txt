add_library(randomize_array "")

target_sources(
  randomize_array
  PRIVATE randomize_array.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/randomize_array.h)

target_include_directories(randomize_array PUBLIC ${CMAKE_CURRENT_LIST_DIR})
