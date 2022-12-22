add_library(hamiltonian_paths "")

target_sources(
  hamiltonian_paths
  PRIVATE hamiltonian_paths.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/hamiltonian_paths.h)

target_include_directories(hamiltonian_paths PUBLIC ${CMAKE_CURRENT_LIST_DIR})
