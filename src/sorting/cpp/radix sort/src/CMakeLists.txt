
add_library (radix_sort "")

target_sources(
    radix_sort
    PRIVATE
        radix_sort.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/radix_sort.h
    )

target_include_directories(
    radix_sort
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
