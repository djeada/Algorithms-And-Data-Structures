add_executable(unit_tests test_all_construct.cpp)

target_link_libraries(unit_tests gtest_main all_construct)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
