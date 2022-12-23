add_library(stack "")

target_sources(
  stack
  PRIVATE stack.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/stack.h)

target_include_directories(stack PUBLIC ${CMAKE_CURRENT_LIST_DIR})
