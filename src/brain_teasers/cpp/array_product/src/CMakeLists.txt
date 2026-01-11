add_library(array_product "")

target_sources(
  array_product
  PRIVATE array_product.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/array_product.h)

target_include_directories(array_product PUBLIC ${CMAKE_CURRENT_LIST_DIR})
