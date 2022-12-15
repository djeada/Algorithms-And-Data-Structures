add_executable(unit_tests test_quick_sort.cpp)

target_link_libraries(unit_tests gtest_main quick_sort)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
