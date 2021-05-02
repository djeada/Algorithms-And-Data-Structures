add_executable(
	unit_tests
	test_radix_sort.cpp
)

target_link_libraries(
	unit_tests
	gtest_main
	radix_sort
)

add_test(
	NAME
		unit
	COMMAND
		${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
