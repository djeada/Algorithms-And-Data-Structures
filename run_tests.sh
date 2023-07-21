#!/bin/bash

set -e

find_cmake_subdirs() {
    local start_dir="$1"
    local cmakedirs=$(find "$start_dir" -type d -exec test -e '{}/CMakeLists.txt' \; -print -prune)
    for cmakedir in $cmakedirs; do
        echo "$cmakedir"
    done
}

test_cpp_projects() {
local subdirs=$(find_cmake_subdirs .)
local current_dir=$(pwd)

local cpp_test_log="$current_dir/cpp_test.log"
: > "$cpp_test_log" # truncate the log file

local total_passed_tests=0
local total_failed_tests=0

cleanup() {
    echo "Cleaning up..."
    cd ..
    rm -rf build
}

for subdir in $subdirs; do
    : > "$cpp_test_log" # truncate the log file
    echo -e "\nRunning tests for C++ project at: $subdir"
    cd "$subdir"
    mkdir -p build && cd build
    trap cleanup EXIT

    cmake .. 1>/dev/null 2>&1 && make 1>/dev/null 2>&1
    ctest --verbose 2>&1 | tee -a "$cpp_test_log"

    trap - EXIT
    cleanup
    cd "$current_dir"

   # count the number of passed and total tests
    cpp_total_tests=$(grep -oP '\d+ tests from' "$cpp_test_log" | tail -1 | awk '{print $1}')
    cpp_passed_tests=$(grep -oP '\[\s*PASSED\s*\] \d+' "$cpp_test_log" | tail -1 | awk '{print $4}')


    echo "cpp_total_tests: $cpp_total_tests"
    echo "cpp_passed_tests: $cpp_passed_tests"

local cpp_failed_tests=$((cpp_total_tests - cpp_passed_tests))

    total_passed_tests=$((total_passed_tests + cpp_passed_tests))
    total_failed_tests=$((total_failed_tests + cpp_failed_tests))

    echo "C++ Tests summary for $subdir:"
    echo -e "Passed: \e[32m$cpp_passed_tests\e[0m, Failed: \e[31m$cpp_failed_tests\e[0m"
done

echo "Total C++ Tests summary:"
echo -e "Total Passed: \e[32m$total_passed_tests\e[0m, Total Failed: \e[31m$total_failed_tests\e[0m"

}


find_python_subdirs() {
    local start_dir="$1"
    local pydirs=$(find "$start_dir" -type d -exec test -e '{}/__init__.py' \; -print -prune)
    for pydir in $pydirs; do
        echo "$pydir"
    done
}

test_python_projects() {
    local subdirs=$(find_python_subdirs .)
    local current_dir=$(pwd)

    local python_test_log="$current_dir/python_test_log"
    : > "$python_test_log" # truncate the log file

    local total_passed_tests=0
    local total_failed_tests=0

    for subdir in $subdirs; do
        echo -e "\nRunning tests for Python project at: $subdir"
        cd "$subdir"
        : > "$python_test_log" # truncate the log file
        python3 -m unittest discover -v 2>&1 | tee -a "$python_test_log"
        cd "$current_dir"

        # count the number of passed and total tests
        local python_total_tests=$(grep -oP 'Ran \K\d+' "$python_test_log")
        local python_passed_tests=$(grep -o '.*... ok' "$python_test_log" | wc -l)
        local python_failed_tests=$((python_total_tests - python_passed_tests))

        # add the passed and failed tests to the total
        total_passed_tests=$((total_passed_tests + python_passed_tests))
        total_failed_tests=$((total_failed_tests + python_failed_tests))

        echo "Python Tests summary for $subdir:"
        echo -e "Passed: \e[32m$python_passed_tests\e[0m, Failed: \e[31m$python_failed_tests\e[0m"
    done

    echo -e "\nTotal Python Tests summary:"
    echo -e "Total Passed: \e[32m$total_passed_tests\e[0m, Total Failed: \e[31m$total_failed_tests\e[0m"

}


main() {
    if [ "$#" -eq 0 ]; then
        echo "Running tests for all projects"
        echo "Running tests for Python projects"
        test_python_projects
        echo "Running tests for C++ projects"
        test_cpp_projects
    fi

    if [ "$#" -eq 1 ]; then
        if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
            echo "Usage: run_tests.sh [OPTION]"
            echo "Run tests for all projects."
            echo ""
            echo "Options:"
            echo "  -h, --help    Show this help message and exit"
            echo "  -p, --python  Run tests for Python projects"
            echo "  -c, --cpp     Run tests for C++ projects"
            exit 0
        fi
        if [ "$1" == "-p" ] || [ "$1" == "--python" ]; then
            echo "Running tests for Python projects"
            test_python_projects
            exit 0
        fi
        if [ "$1" == "-c" ] || [ "$1" == "--cpp" ]; then
            echo "Running tests for C++ projects"
            test_cpp_projects
            exit 0
        fi
    fi

    if [ "$#" -gt 1 ]; then
        echo "Too many arguments"
        exit 1
    fi

}

main "$@"

