add_library(minimum_insertions_for_palindrome "")

target_sources(
  minimum_insertions_for_palindrome
  PRIVATE minimum_insertions_for_palindrome.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/minimum_insertions_for_palindrome.h)

target_include_directories(minimum_insertions_for_palindrome PUBLIC ${CMAKE_CURRENT_LIST_DIR})
