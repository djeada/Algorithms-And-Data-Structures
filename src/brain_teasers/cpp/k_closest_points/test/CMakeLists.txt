add_executable(unit_tests test_k_closest_points.cpp)

target_link_libraries(unit_tests gtest_main k_closest_points)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
