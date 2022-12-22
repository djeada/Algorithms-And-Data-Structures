add_executable(unit_tests test_k_colorable_configurations.cpp)

target_link_libraries(unit_tests gtest_main k_colorable_configurations)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
