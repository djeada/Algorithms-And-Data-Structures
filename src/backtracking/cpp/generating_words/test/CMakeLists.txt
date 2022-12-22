add_executable(unit_tests test_generating_words.cpp)

target_link_libraries(unit_tests gtest_main generating_words)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
