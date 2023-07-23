# Algorithms-And-Data-Structures

<a href="https://github.com/djeada/Data-Structures/stargazers"><img alt="GitHub stars" src="https://img.shields.io/github/stars/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/network"><img alt="GitHub forks" src="https://img.shields.io/github/forks/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/blob/master/LICENSE"><img alt="GitHub license" src="https://img.shields.io/github/license/djeada/Data-Structures"></a>
<a href=""><img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"></a>
</div>

This repository contains a collection of projects in C++ and Python that implement various data structures and algorithms. The projects are organized by language and topic, and include detailed explanations and examples to help you understand how they work.

![algorithms](https://user-images.githubusercontent.com/37275728/213442579-155a1549-89ee-43d1-878b-9d1673524a5a.png)

## About

Ever since I first tackled Algorithms and Data Structures at university in 2015, I've found it super useful to regularly go back to the basics. This becomes even more important when you're trying to learn a new programming language - a strong foundation is key. To help others, I've decided to share my code and notes on the subject with everyone.

My code is written in two programming languages I really enjoy, C++ and Python. I've done my best to stick to the latest best practices. Alongside the code, you'll find the notes I made while learning. These notes give more context and could be really handy for anyone new to Algorithms and Data Structures.

## Requirements

The following requirements are necessary to build and run the code in this repository:

* For C++ projects:
  - A C++ compiler supporting C++14
  - CMake 3.15 or later
* For Python projects:
  - Python 3.10 or later

No additional libraries or modules are required.

## Running the Examples

This repository is organized into distinct algorithm implementations, each contained in its own subdirectory. These subdirectories provide the source code, unit tests, and build configuration files necessary for each algorithm. Because each algorithm forms a separate project, you should handle the build and test processes individually.

### Building and Testing C++ Projects

Building and testing C++ projects involve a sequence of steps. Here's a detailed walkthrough:

1. **Navigate to the project directory:** Start by moving into the directory containing the specific project you want to build and test.

2. **Create and navigate into the build directory:**

```
mkdir -p build && cd build
```

This command creates a new directory named `build` (if it doesn't already exist) and then navigates into it. The `build` directory is where the output files of the build process will be stored.

3. **Generate the build files with CMake:**

```
cmake ..
```

This command runs CMake to generate the build files. `..` tells CMake to look for the `CMakeLists.txt` file in the directory above `build`.

4. **Build the project:**

```
make
```

This command compiles the source code using the instructions specified in the `CMakeLists.txt` file.

5. **Run the unit tests:**

```
ctest --verbose
```

The `ctest --verbose` command executes the unit tests and uses the verbose flag to provide a detailed output.

### Testing Python Projects

To test a Python project, execute the following command in the project directory:

```
python -m unittest discover -v
```

This command uses Python's built-in `unittest` module to discover and run the tests. The `-v` (verbose) flag is used to get more detailed output from the tests.

### Using the Utility Script

For convenience, this repository includes a utility script named `run_tests.sh`. This script runs the unit tests for all subprojects. To use the script, execute the following command from the repository's root directory:

```
./run_tests.sh
```

## Code Formatting Conventions

Consistent code formatting is essential for maintaining readability and understanding of the codebase. Therefore, we have adopted specific formatting guidelines for each programming language used in this repository.

### C++ Formatting

We adhere to the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). To automatically format the code, we use `clang-format`. Use the following command to format your code:

```
find . -regex '.*\\.(cpp|hpp|cu|c|h)' -exec clang-format -style=file -i {} \\;
```

This command recursively finds all files with `.cpp`, `.hpp`, `.cu`, `.c`, or `.h` extensions and formats them using `clang-format`.

### CMake Formatting

CMake files should have a consistent style as well. For this, we use `cmake-format`. To format a `CMakeLists.txt` file, execute the following command:

```
cmake-format CMakeLists.txt -i
```

This command applies the `cmake-format` to the `CMakeLists.txt` file.

### Python Formatting

We follow the [PEP 8 - Style Guide for Python Code](https://peps.python.org/pep-0008/) for Python projects and use `black` to automatically format the code. Use the following command to format your Python code:

```
black .
```

This command formats all Python files in the current directory and its subdirectories using `black`.

## Notes

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/basic_concepts.md">Basic concepts.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/data_structures.md">Data structures.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/graphs.md">Graph algorithms.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/backtracking.md">Backtracking.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/dynamic_programming.md">Dynamic programming.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/sorting.md">Sorting.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/brain_teasers.md">Brain teasers.</a>

## List of projects

### Data structures
<table>
    <thead>
        <tr>
            <th>#</th>
            <th>Structure</th>
            <th colspan="2">Implementation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Linked List</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/linked_list">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/linked_list">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Vector</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/vector">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/vector">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Stack</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/stack">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/stack">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Queue</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/simple_queue">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/queue">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Heap</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/heap">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/heap">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Binary Search Tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/binary_search_tree">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/binary_search_tree">Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Avl Tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/avl_tree">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/avl_tree">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Red Black Tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/red_black_tree">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/red_black_tree">Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>Hash Table</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/hash_table">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/hash_table">Cpp</a></td>
        </tr>
    </tbody>
</table>


### Graphs
<table>
    <thead>
        <tr>
            <th>#</th>
            <th>Algorithm</th>
            <th colspan="2">Implementation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>General graph</td>
            <td><a href="https://github.com/djeada/Data-Structures/blob/master/src/graphs/python/graph">Python</a></td>
            <td><a href="https://github.com/djeada/Data-Structures/tree/master/src/graphs/cpp/graph">Cpp</a></td>
        </tr>
        <tr>
            <td>1</td>
            <td>Is Bipartite?</td>
            <td><a href="https://github.com/djeada/Data-Structures/blob/master/src/graphs/python/bipartite_graph">Python</a></td>
            <td><a href="https://github.com/djeada/Data-Structures/tree/master/src/graphs/cpp/bipartite_graph">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>BFS</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs">Python</a></td>
            <td><a href="https://github.com/djeada/Data-Structures/tree/master/src/graphs/cpp/bfs">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>DFS</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dfs">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dfs">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Dijkstra</td>
            <td><a href="https://github.com/djeada/Data-Structures/blob/master/src/graphs/python/dijkstra">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>A*</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/a_star">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/a_star">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Bellman-Ford</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford">Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Kruskal</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/kruskal">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/kruskal">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Prim</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim">Cpp</a></td>
        </tr>
    </tbody>
</table>

### Backtracking
<table>
    <thead>
        <tr>
            <th>#</th>
            <th>Problem</th>
            <th colspan="2">Solution</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Permutations</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_permutations">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_permutations">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Combinations</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_combinations">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_permutations">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>String Pattern</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/string_pattern">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/string_pattern">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Generating words</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/generating_words">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/generating_words">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>K-colorable configurations</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/k_colorable_configurations">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/k_colorable_configurations">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Hamiltonian paths</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/hamiltonian_paths">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/hamiltonian_paths">Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Knigt tour</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/knight_tour">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/knight_tour">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Topological orderings</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/topological_sort">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/topological_sort">Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>Tic-tac-toe (minimax)</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/minimax">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/minimax">Cpp</a></td>
        </tr>
    </tbody>
</table>

### Dynamic Programming
<table>
    <thead>
        <tr>
            <th>#</th>
            <th>Problem</th>
            <th colspan="2">Solution</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Fibonacci</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/fibonacci">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/fibonacci">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Grid travelers</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/grid_traveler">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/grid_travelers">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Stairs</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/climbing_stairs">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/climb_stairs">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Can sum</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/can_sum">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/can_sum">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>How sum</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/how_sum">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/how_sum">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Best sum</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/best_sum">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/best_sum">Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Can construct</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/can_construct">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/can_construct">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Count construct</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/count_construct">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/count_construct">Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>All construct</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/all_construct">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/all_construct">Cpp</a></td>
        </tr>
        <tr>
            <td>10</td>
            <td>Coins</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/coins">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/coin_change">Cpp</a></td>
        </tr>
        <tr>
            <td>11</td>
            <td>Longest increasing subsequence</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/longest_increasing_subarray">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/longest_increasing_subarray">Cpp</a></td>
        </tr>
        <tr>
            <td>12</td>
            <td>Longest common subsequence</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/longest_common_subsequence">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/longest_common_subsequence">Cpp</a></td>
        </tr>
        <tr>
            <td>13</td>
            <td>Knuth-Morris-Pratt</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/kmp">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/kmp">Cpp</a></td>
        </tr>
         <tr>
            <td>14</td>
            <td>Minimum insertions to form a palindrome</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/minimum_insertions_for_palindrome">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/minimum_insertions_for_palindrome">Cpp</a></td>
        </tr>
    </tbody>
</table>

### Sorting
<table>
    <thead>
        <tr>
            <th>#</th>
            <th>Algorithm</th>
            <th colspan="2">Implementation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Insertion sort</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/python/insertion_sort">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/insertion_sort">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Selection sort</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/python/selection_sort">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/selection_sort">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Heap sort</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/python/heap_sort">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/heap_sort">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Merge sort</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/python/merge_sort">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/merge_sort">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Quick sort</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/python/quick_sort">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/quick_sort">Cpp</a></td>
        </tr>
    </tbody>
</table>

### Brain Teasers
<table>
    <thead>
        <tr>
            <th>#</th>
            <th>Problem</th>
            <th colspan="2">Solution</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Minimum deletions to make valid parentheses</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/deletions_to_make_valid_parentheses">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/deletions_to_make_valid_parentheses">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Is palindrome after at most one char deletion?</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/is_palindrome_after_char_deletion">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/is_palindrome_after_char_deletion">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td><i>K</i> closest points to origin</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/k_closest_points">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/k_closest_points">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Subarray sum equals <i>K</i></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/subarray_sum">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/subarray_sum">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Add numbers given as strings</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/add_string_numbers">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/add_string_numbers">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Dot product of two sparse vectors</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/sparse_vectors_product">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/sparse_vectors_product">Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Range sum of BST </td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/range_sum_of_bst">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/range_sum_of_bst">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Product of array except self</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/array_product">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/array_product">Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>Convert BST to sorted doubly linked list</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/bst_to_list">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/bst_to_list">Cpp</a></td>
        </tr>
        <tr>
            <td>10</td>
            <td>Lowest common ancestor of a binary tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lowest_common_ancestor">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lowest_common_ancestor">Cpp</a></td>
        </tr>
        <tr>
            <td>11</td>
            <td>LRU Cache</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lru_cache">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lru_cache">Cpp</a></td>
        </tr>
        <tr>
            <td>12</td>
            <td>Randomize An Array</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/randomize_array">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/randomize_array">Cpp</a></td>
        </tr>
        <tr>
            <td>13</td>
            <td>Binary Tree Right Side View</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/binary_tree_right_side_view">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/binary_tree_right_side_view">Cpp</a></td>
        </tr>
        <tr>
            <td>14</td>
            <td>Design Browser History</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/design_browser_history">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/design_browser_history">Cpp</a></td>
        </tr>
        <tr>
            <td>15</td>
            <td>Score After Flipping Matrix</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/score_after_flipping_matrix">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/score_after_flipping_matrix">Cpp</a></td>
        </tr>
    </tbody>
</table>


## References

* L. V. Narashima Prasad, E. Kishna Rao Patro "<i>Lecture Notes on Data Structures using C</i>" 
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. "<i>Introduction to Algorithms, 3rd Edition (The MIT Press)</i>"
* Steven Halim "<i>Competitive Programming 3</i>" 
* Narasimha Karumanchi "<i>Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles</i>" 
* Brian Kernighan, Dennis Ritchie "<i>The C Programming Language</i>" 
* Steven Skiena, Miguel Revilla "<i>Programming Challenges: The Programming Contest Training Manual</i>" 
* Antti Laaksonen "<i>  Guide to Competitive Programming: Learning and Improving Algorithms Through Contests (Undergraduate Topics in Computer Science) </i>" 
* Nite Nimajneb "<i>The Hitchhiker’s Guide to the Programming Contests</i>" 
* http://cslibrary.stanford.edu/
* https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-851-advanced-data-structures-spring-2012/
* https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-0002-introduction-to-computational-thinking-and-data-science-fall-2016/lecture-slides-and-files/index.htm
* https://www.cs.bham.ac.uk/~jxb/DSA/
* https://www.ics.uci.edu/~eppstein/161/syl.html
* http://www.columbia.edu/~cs2035/oldcourses.html
* https://www.cs.auckland.ac.nz/courses/compsci220s1t/lectures/lecturenotes/GG-lectures/
* https://sp19.datastructur.es/
* https://www.csc.kth.se/~viggo/problemlist
* https://cp-algorithms.com/
* https://www.personal.kent.edu/~rmuhamma/Compgeometry/compgeom.html
* https://codeahoy.com/learn/cprogramming/toc/

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
