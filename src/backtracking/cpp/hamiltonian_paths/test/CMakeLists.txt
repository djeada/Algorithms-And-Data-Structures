add_executable(unit_tests test_hamiltonian_paths.cpp)

target_link_libraries(unit_tests gtest_main hamiltonian_paths)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
