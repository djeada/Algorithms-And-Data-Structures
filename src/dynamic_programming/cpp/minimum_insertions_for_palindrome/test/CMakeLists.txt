add_executable(unit_tests test_minimum_insertions_for_palindrome.cpp)

target_link_libraries(unit_tests gtest_main minimum_insertions_for_palindrome)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
