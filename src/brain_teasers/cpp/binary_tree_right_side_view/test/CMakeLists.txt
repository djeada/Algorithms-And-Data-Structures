add_executable(unit_tests test_right_side_view.cpp)

target_link_libraries(unit_tests gtest_main right_side_view)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
