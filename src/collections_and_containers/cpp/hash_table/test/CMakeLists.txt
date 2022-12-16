add_executable(unit_tests test_hash_table.cpp)

target_link_libraries(unit_tests gtest_main hash_table)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
