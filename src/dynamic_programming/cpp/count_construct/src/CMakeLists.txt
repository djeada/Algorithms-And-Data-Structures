add_library(count_construct "")

target_sources(
  count_construct
  PRIVATE count_construct.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/count_construct.h)

target_include_directories(count_construct PUBLIC ${CMAKE_CURRENT_LIST_DIR})
