#!/bin/bash
# Runs the Python (unittest) and C++ (CMake + CTest) test suites.
#
# By default only projects touched since the base branch are tested; when
# nothing differs from the base branch (e.g. a push to master) every project
# is tested. Exits non-zero if any project fails to build or any test fails.
set -u -o pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT"

BUILD_ROOT="$(mktemp -d)"
trap 'rm -rf "$BUILD_ROOT"' EXIT

FAILED_PROJECTS=()

usage() {
    cat <<'EOF'
Usage: run_tests.sh [OPTION]
Run tests for projects modified since the base branch.

Options:
  -h, --help    Show this help message and exit
  -p, --python  Run Python tests only
  -c, --cpp     Run C++ tests only
  -a, --all     Test every project, not just modified ones
EOF
}

# Base ref to diff against: the upstream if one is set, otherwise master.
detect_base_branch() {
    git rev-parse --abbrev-ref --symbolic-full-name '@{u}' 2>/dev/null || echo "master"
}

# Files changed relative to the base branch, including uncommitted work.
get_modified_files() {
    local base
    base="$(detect_base_branch)"
    {
        git diff --name-only "$base"...HEAD 2>/dev/null
        git diff --name-only HEAD 2>/dev/null
    } | sort -u
}

# Print the subset of the given directories that contain a modified file.
filter_modified() {
    local modified="$1"
    shift
    local dir
    for dir in "$@"; do
        if grep -q "^${dir#./}/" <<<"$modified"; then
            echo "$dir"
        fi
    done
}

select_projects() {
    local all="$1" modified selected
    if [ "$RUN_ALL" = 1 ]; then
        echo "$all"
        return
    fi
    modified="$(get_modified_files)"
    if [ -z "$modified" ]; then
        echo "$all"
        return
    fi
    # shellcheck disable=SC2086
    filter_modified "$modified" $all
}

test_python_projects() {
    local all projects dir
    # Python projects keep their tests in either tests/ or test/ (C++ projects
    # also use test/, hence the /python/ filter).
    all="$(find . -type d -path '*/python/*' \( -name tests -o -name test \) \
        -not -path '*/build/*' -printf '%h\n' | sort -u)"
    projects="$(select_projects "$all")"
    if [ -z "$projects" ]; then
        echo "No Python projects to test."
        return
    fi

    echo "Running tests for Python projects:"
    for dir in $projects; do
        echo -e "\n== Python project: $dir"
        if ! (cd "$dir" && python3 -m unittest discover -v); then
            FAILED_PROJECTS+=("python:$dir")
        fi
    done
}

test_cpp_projects() {
    local all projects dir build
    # A project root is a CMakeLists.txt whose parent directory has none
    # (src/ and test/ are added via add_subdirectory).
    all="$(find . -name CMakeLists.txt -not -path '*/build/*' -printf '%h\n' | sort -u |
        while read -r d; do [ -f "$d/../CMakeLists.txt" ] || echo "$d"; done)"
    projects="$(select_projects "$all")"
    if [ -z "$projects" ]; then
        echo "No C++ projects to test."
        return
    fi

    echo "Running tests for C++ projects:"
    for dir in $projects; do
        echo -e "\n== C++ project: $dir"
        build="$BUILD_ROOT/$(echo "${dir#./}" | tr '/' '_')"
        if cmake -S "$dir" -B "$build" >"$build.log" 2>&1 &&
            cmake --build "$build" -j"$(nproc)" >>"$build.log" 2>&1; then
            (cd "$build" && ctest --output-on-failure) ||
                FAILED_PROJECTS+=("cpp:$dir")
        else
            cat "$build.log"
            echo "Build failed"
            FAILED_PROJECTS+=("cpp:$dir")
        fi
    done
}

RUN_ALL=0
RUN_PYTHON=1
RUN_CPP=1
for arg in "$@"; do
    case "$arg" in
    -h | --help) usage; exit 0 ;;
    -p | --python) RUN_CPP=0 ;;
    -c | --cpp) RUN_PYTHON=0 ;;
    -a | --all) RUN_ALL=1 ;;
    *) echo "Unknown option: $arg" >&2; usage >&2; exit 1 ;;
    esac
done

[ "$RUN_PYTHON" = 1 ] && test_python_projects
[ "$RUN_CPP" = 1 ] && test_cpp_projects

echo
if [ "${#FAILED_PROJECTS[@]}" -gt 0 ]; then
    echo "FAILED projects:"
    printf '  %s\n' "${FAILED_PROJECTS[@]}"
    exit 1
fi
echo "All tests passed."
