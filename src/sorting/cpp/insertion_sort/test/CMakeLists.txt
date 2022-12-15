add_executable(unit_tests test_insertion_sort.cpp)

target_link_libraries(unit_tests gtest_main insertion_sort)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
