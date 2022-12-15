add_library(queue "")

target_sources(
  queue
  PRIVATE queue.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/queue.h)

target_include_directories(queue PUBLIC ${CMAKE_CURRENT_LIST_DIR})
