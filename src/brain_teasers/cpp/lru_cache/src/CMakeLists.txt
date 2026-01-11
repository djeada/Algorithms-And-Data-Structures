add_library(lru_cache "")

target_sources(
  lru_cache
  PRIVATE lru_cache.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lru_cache.h)

target_include_directories(lru_cache PUBLIC ${CMAKE_CURRENT_LIST_DIR})
