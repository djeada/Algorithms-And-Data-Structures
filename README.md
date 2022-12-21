# Algorithms-And-Data-Structures

<a href="https://github.com/djeada/Data-Structures/stargazers"><img alt="GitHub stars" src="https://img.shields.io/github/stars/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/network"><img alt="GitHub forks" src="https://img.shields.io/github/forks/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/blob/master/LICENSE"><img alt="GitHub license" src="https://img.shields.io/github/license/djeada/Data-Structures"></a>
<a href=""><img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"></a>
</div>

This repository contains a collection of projects in C++ and Python that implement various data structures and algorithms. The projects are organized by language and topic, and include detailed explanations and examples to help you understand how they work.

## About

As someone who has been captivated by Algorithms and Data Structures since my first encounter with the subject at university in 2015, I have come to value the importance of regularly revisiting the fundamentals. This is especially true when learning a new programming language, as it helps to build a strong foundation of understanding. With this in mind, I have decided to share my code and notes on Algorithms and Data Structures with the wider community.

My code is written in two of my favorite programming languages, C++ and Python, and I have made a conscious effort to adhere to modern best practices. Along with the code, I have also included comprehensive notes that I took while learning the topic. These notes are intended to provide additional context and understanding, and may be particularly helpful for those who are new to the subject.

## Requirements

The following requirements are necessary to build and run the code in this repository:

* For C++ projects:
  - A C++ compiler supporting C++14
  - CMake 3.15 or later
* For Python projects:
  - Python 3.10 or later

No additional libraries or modules are required.

## Running the examples
Each algorithm implementation has its own subdirectory, including the source code, unit tests, and build configuration files. Each subdirectory is a separate project that should be built and tested individually.

### C++

To build and test a C++ project, follow these steps:

1. Navigate to the project directory.
1. Create a build directory and enter it: `mkdir -p build && cd build`
1. Generate the build files with CMake: `cmake ..`
1. Build the project: `make`
1. Run the unit tests: `ctest --verbose`

### Python

To test a Python project, use the following command from the project directory:

```bash
python -m unittest discover -v
```

### Using the utility script

You can also use the `run_tests.sh` utility script to run the unit tests for all subprojects. To do so, execute the following command from the root directory of the repository:

```bash
./run_tests.sh
```

## Formatting conventions

### C++

We follow the <a href="https://google.github.io/styleguide/cppguide.html">Google C++ Style Guide</a> and use clang-format to automatically format the code.

```bash
find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
```

### CMake
For CMake files, we use <a href="https://github.com/cheshirekow/cmake_format">cmake-format</a> to ensure a consistent style. To format a CMakeLists.txt file, use the following command:

```bash
cmake-format CMakeLists.txt -i
```

### Python

We follow the <a href="https://peps.python.org/pep-0008/">PEP 8 - Style Guide for Python Code</a> and use black to automatically format the code.

```bash
black .
```

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
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/queue">Python</a></td>
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
            <td>String Pattern</td>
            <td><a href="">Python</a></td>
            <td><a href="">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Permutations</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Generating words</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>K-colorable configurations</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Hamiltonian paths</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>K-partition</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Topological orderings</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Tic Tac Toe</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
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
            <td>14</td>
            <td>Minimum insertions to form a palindrome</td>
            <td><a href="">Python</a></td>
            <td><a href="">Cpp</a></td>
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
            <td>Minimum remove to make valid parentheses</td>
            <td><a href="">Python</a></td>
            <td><a href="">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Is palindrome after at most one char delete?</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td><i>K</i> closest points to origin</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Subarray sum equals <i>K</i></td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Add numbers given as strings</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Dot product of two sparse vectors</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Range sum of BST </td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Product of array except self</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>Convert BST to sorted doubly linked list</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>10</td>
            <td>Lowest common ancestor of a binary tree</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>11</td>
            <td>LRU Cache</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>12</td>
            <td>Randomize An Array</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
    </tbody>
</table>


## Refrences

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
