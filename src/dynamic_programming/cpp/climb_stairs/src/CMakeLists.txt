add_library(climb "")

target_sources(
  climb
  PRIVATE climb.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/climb.h)

target_include_directories(climb PUBLIC ${CMAKE_CURRENT_LIST_DIR})
