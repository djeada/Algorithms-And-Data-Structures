#!/bin/bash

set -e

# Find all directories (under start_dir) that contain a CMakeLists.txt
find_cmake_subdirs() {
    local start_dir="$1"
    local cmakedirs
    cmakedirs=$(find "$start_dir" -type f -name 'CMakeLists.txt' -printf '%h\n' | sort -u)
    echo "$cmakedirs"
}

# Find all directories (under start_dir) that contain a __init__.py (i.e., Python packages)
find_python_subdirs() {
    local start_dir="$1"
    local pydirs
    pydirs=$(find "$start_dir" -type f -name '__init__.py' -printf '%h\n' | sort -u)
    echo "$pydirs"
}

# Get list of files changed since last commit on master
get_modified_files() {
    # Compare against master branch; adjust "master" to "origin/master" if needed
    git diff --name-only master...HEAD
}

test_cpp_projects() {
    local current_dir
    current_dir=$(pwd)

    # All C++ project directories (where CMakeLists.txt lives)
    local all_subdirs
    all_subdirs=$(find_cmake_subdirs .)

    # Files modified in this PR relative to master
    local modified_files
    modified_files=$(get_modified_files)

    # Filter to only those C++ subdirs in which at least one file was modified
    local modified_subdirs=""
    for subdir in $all_subdirs; do
        if echo "$modified_files" | grep -q "^${subdir#./}/"; then
            modified_subdirs="$modified_subdirs $subdir"
        fi
    done

    if [ -z "$modified_subdirs" ]; then
        echo "No modified C++ projects to test."
        return
    fi

    local total_passed_tests=0
    local total_failed_tests=0
    local cpp_test_log

    cleanup() {
        cd "$current_dir"
        rm -rf build
    }

    echo "Running tests for modified C++ projects:"
    for subdir in $modified_subdirs; do
        echo -e "\nRunning tests for C++ project at: $subdir"
        cd "$subdir"
        mkdir -p build && cd build

        # Ensure cleanup on exit from this block
        trap cleanup EXIT

        # Redirect cmake/make output to /dev/null
        cmake .. 1>/dev/null 2>&1 && make 1>/dev/null 2>&1

        # Run tests and capture output
        cpp_test_log="$current_dir/cpp_test_$(echo "$subdir" | tr '/' '_').log"
        : > "$cpp_test_log"
        ctest --verbose 2>&1 | tee -a "$cpp_test_log"

        trap - EXIT
        cleanup
        cd "$current_dir"

        # Count total and passed tests in this subdir
        local cpp_total_tests
        cpp_total_tests=$(grep -oP '\d+(?= tests from)' "$cpp_test_log" | tail -1 || echo 0)
        local cpp_passed_tests
        cpp_passed_tests=$(grep -oP '(?<=\[ *PASSED *\] )\d+' "$cpp_test_log" | tail -1 || echo 0)
        local cpp_failed_tests=$((cpp_total_tests - cpp_passed_tests))

        total_passed_tests=$((total_passed_tests + cpp_passed_tests))
        total_failed_tests=$((total_failed_tests + cpp_failed_tests))

        echo "C++ Tests summary for $subdir:"
        echo -e "  Passed: \e[32m$cpp_passed_tests\e[0m, Failed: \e[31m$cpp_failed_tests\e[0m"
    done

    echo -e "\nTotal C++ Tests summary for modified projects:"
    echo -e "  Total Passed: \e[32m$total_passed_tests\e[0m, Total Failed: \e[31m$total_failed_tests\e[0m"
}

test_python_projects() {
    local current_dir
    current_dir=$(pwd)

    # All Python project directories (where __init__.py lives)
    local all_subdirs
    all_subdirs=$(find_python_subdirs .)

    # Files modified in this PR relative to master
    local modified_files
    modified_files=$(get_modified_files)

    # Filter to only those Python subdirs in which at least one file was modified
    local modified_subdirs=""
    for subdir in $all_subdirs; do
        if echo "$modified_files" | grep -q "^${subdir#./}/"; then
            modified_subdirs="$modified_subdirs $subdir"
        fi
    done

    if [ -z "$modified_subdirs" ]; then
        echo "No modified Python projects to test."
        return
    fi

    local total_passed_tests=0
    local total_failed_tests=0
    local python_test_log

    echo "Running tests for modified Python projects:"
    for subdir in $modified_subdirs; do
        echo -e "\nRunning tests for Python project at: $subdir"
        cd "$subdir"

        python_test_log="$current_dir/python_test_$(echo "$subdir" | tr '/' '_').log"
        : > "$python_test_log"

        python3 -m unittest discover -v 2>&1 | tee -a "$python_test_log"
        cd "$current_dir"

        # Count total and passed tests
        local python_total_tests
        python_total_tests=$(grep -oP '(?<=Ran )\d+' "$python_test_log" | head -1 || echo 0)
        local python_passed_tests
        python_passed_tests=$(grep -c '\.\.\. ok' "$python_test_log" || echo 0)
        local python_failed_tests=$((python_total_tests - python_passed_tests))

        total_passed_tests=$((total_passed_tests + python_passed_tests))
        total_failed_tests=$((total_failed_tests + python_failed_tests))

        echo "Python Tests summary for $subdir:"
        echo -e "  Passed: \e[32m$python_passed_tests\e[0m, Failed: \e[31m$python_failed_tests\e[0m"
    done

    echo -e "\nTotal Python Tests summary for modified projects:"
    echo -e "  Total Passed: \e[32m$total_passed_tests\e[0m, Total Failed: \e[31m$total_failed_tests\e[0m"
}

main() {
    if [ "$#" -eq 0 ]; then
        echo "Running tests only for projects modified since last master commit."
        echo "---- Python Projects ----"
        test_python_projects
        echo "---- C++ Projects ----"
        test_cpp_projects
        exit 0
    fi

    if [ "$#" -eq 1 ]; then
        case "$1" in
            -h|--help)
                echo "Usage: run_tests.sh [OPTION]"
                echo "Run tests for projects modified since last master commit."
                echo ""
                echo "Options:"
                echo "  -h, --help    Show this help message and exit"
                echo "  -p, --python  Run tests for modified Python projects only"
                echo "  -c, --cpp     Run tests for modified C++ projects only"
                exit 0
                ;;
            -p|--python)
                echo "Running tests for modified Python projects:"
                test_python_projects
                exit 0
                ;;
            -c|--cpp)
                echo "Running tests for modified C++ projects:"
                test_cpp_projects
                exit 0
                ;;
            *)
                echo "Unknown option: $1"
                echo "Usage: run_tests.sh [OPTION]"
                exit 1
                ;;
        esac
    fi

    if [ "$#" -gt 1 ]; then
        echo "Too many arguments"
        echo "Usage: run_tests.sh [OPTION]"
        exit 1
    fi
}

main "$@"
