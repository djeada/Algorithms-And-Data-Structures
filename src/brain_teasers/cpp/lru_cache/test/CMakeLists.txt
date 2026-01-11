add_executable(unit_tests test_lru_cache.cpp)

target_link_libraries(unit_tests gtest_main lru_cache)

add_test(NAME unit
         COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
