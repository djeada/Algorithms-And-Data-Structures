add_library(add_string_numbers "")

target_sources(
  add_string_numbers
  PRIVATE add_string_numbers.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/add_string_numbers.h)

target_include_directories(add_string_numbers PUBLIC ${CMAKE_CURRENT_LIST_DIR})
