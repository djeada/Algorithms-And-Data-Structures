add_library(fibonacci "")

target_sources(
  fibonacci
  PRIVATE fibonacci.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/fibonacci.h)

target_include_directories(fibonacci PUBLIC ${CMAKE_CURRENT_LIST_DIR})
