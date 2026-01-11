add_executable(unit_tests test_randomize_array.cpp)

target_link_libraries(unit_tests gtest_main randomize_array)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
