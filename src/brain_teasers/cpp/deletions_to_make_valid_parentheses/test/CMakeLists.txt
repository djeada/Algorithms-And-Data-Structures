add_executable(unit_tests test_valid_parentheses.cpp)

target_link_libraries(unit_tests gtest_main valid_parentheses)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
