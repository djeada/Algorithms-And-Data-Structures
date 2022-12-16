add_executable(unit_tests test_red_black_tree.cpp)

target_link_libraries(unit_tests gtest_main red_black_tree)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
