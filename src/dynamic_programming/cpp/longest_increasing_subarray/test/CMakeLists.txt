add_executable(unit_tests test_longest_increasing_subarray.cpp)

target_link_libraries(unit_tests gtest_main longestIncreasingSubarray)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
