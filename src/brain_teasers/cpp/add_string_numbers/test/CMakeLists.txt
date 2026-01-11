add_executable(unit_tests test_add_string_numbers.cpp)

target_link_libraries(unit_tests gtest_main add_string_numbers)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
