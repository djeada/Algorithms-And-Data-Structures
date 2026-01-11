add_executable(unit_tests test_matrix_score.cpp)

target_link_libraries(unit_tests gtest_main matrix_score)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
