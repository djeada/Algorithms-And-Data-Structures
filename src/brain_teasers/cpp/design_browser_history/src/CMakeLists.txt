add_library(browser_history "")

target_sources(
  browser_history
  PRIVATE browser_history.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/browser_history.h)

target_include_directories(browser_history PUBLIC ${CMAKE_CURRENT_LIST_DIR})
