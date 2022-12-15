add_library(all_construct "")

target_sources(
  all_construct
  PRIVATE all_construct.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/all_construct.h)

target_include_directories(all_construct PUBLIC ${CMAKE_CURRENT_LIST_DIR})
