add_library(generating_words "")

target_sources(
  generating_words
  PRIVATE generating_words.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/generating_words.h)

target_include_directories(generating_words PUBLIC ${CMAKE_CURRENT_LIST_DIR})
