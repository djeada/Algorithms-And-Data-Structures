add_library(palindrome "")

target_sources(
  palindrome
  PRIVATE palindrome.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/palindrome.h)

target_include_directories(palindrome PUBLIC ${CMAKE_CURRENT_LIST_DIR})
