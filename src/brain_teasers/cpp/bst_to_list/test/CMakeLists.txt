add_executable(unit_tests test_bst_to_list.cpp)

target_link_libraries(unit_tests gtest_main bst_to_list)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
