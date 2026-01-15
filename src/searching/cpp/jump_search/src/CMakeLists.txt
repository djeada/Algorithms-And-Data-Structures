add_library(jump_search "")

target_sources(
  jump_search
  PRIVATE jump_search.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/jump_search.h)

target_include_directories(jump_search PUBLIC ${CMAKE_CURRENT_LIST_DIR})
