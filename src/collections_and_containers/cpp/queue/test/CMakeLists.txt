add_executable(unit_tests_queue test_queue.cpp)

target_link_libraries(unit_tests_queue gtest_main_queue queue)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests_queue)
