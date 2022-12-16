add_library(hash_table "")

target_sources(
  hash_table
  PRIVATE hash_table.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/hash_table.h)

target_include_directories(hash_table PUBLIC ${CMAKE_CURRENT_LIST_DIR})
