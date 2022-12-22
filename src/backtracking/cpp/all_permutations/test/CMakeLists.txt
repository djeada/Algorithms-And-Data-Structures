add_executable(unit_tests test_all_permutations.cpp)

target_link_libraries(unit_tests gtest_main all_permutations)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
