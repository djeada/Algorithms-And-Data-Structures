add_library(can_construct "")

target_sources(
  can_construct
  PRIVATE can_construct.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/can_construct.h)

target_include_directories(can_construct PUBLIC ${CMAKE_CURRENT_LIST_DIR})
