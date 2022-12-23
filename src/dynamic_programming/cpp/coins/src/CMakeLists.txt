add_library(coinChange "")

target_sources(
  coinChange
  PRIVATE coin_change.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/coin_change.h)

target_include_directories(coinChange PUBLIC ${CMAKE_CURRENT_LIST_DIR})
