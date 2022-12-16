# Algorithms-And-Data-Structures

<a href="https://github.com/djeada/Data-Structures/stargazers"><img alt="GitHub stars" src="https://img.shields.io/github/stars/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/network"><img alt="GitHub forks" src="https://img.shields.io/github/forks/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/blob/master/LICENSE"><img alt="GitHub license" src="https://img.shields.io/github/license/djeada/Data-Structures"></a>
<a href=""><img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"></a>
</div>

Implementations of various algorithms.

## About

Since I initially attended the course at my university in 2015, Algorithms and Data Structures have attracted my attention. I find it really beneficial to return to the fundamentals on a regular basis, especially while learning a new language. Since this is my n'th iteration of the process, I wanted to share my code with the world so everyone may benefit from it.

The code is written in two of my favorite programming languages: C++ and Python. To the best of my ability, I adhered to modern practices.

Aside from the code, you'll come across various comprehensive notes that I wrote down while learning the subject.

## Requirements

For C++ projects you will need:
* C++ compiler supporting C++14
* Cmake 3.15+

For Python projects you will need:
* Python 3.10+

No additional libraries or modules are needed.

## How to run the examples?
Each algorithm implementation has its own subdirectory including the source code, unit tests, and build configuration files.
Each subdirectory is a separate project that should be built separately.

### C++

To build a C++ project and run unit tests, go to the project directory and execute the following commands:

```bash
mkdir -p build && cd build
cmake ..
make
ctest --verbose
```

### Python

Use the following commands to run Python unit tests from the project directory:

```bash
python -m unittest discover -v
```

### Using BASH script

You can also check the unit tests in all subprojects using the utility script *run_tests.sh*, which is located in the project directory: 

```bash
./run_tests.sh
```

## Formatting conventions

For CMake files we use <a href="https://github.com/cheshirekow/cmake_format">cmake-format</a>. For example you can format the *CMakeLists.txt* in the following way:

```bash
cmake-format CMakeLists.txt -i
```

## Notes

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/basic_concepts.md">Basic concepts.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/collections_and_containers.md">Collections and containers.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/graphs.md">Graph algorithms.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/backtracking.md">Backtracking.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/dynamic_programming.md">Dynamic programming.</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/sorting.md">Sorting.</a>

## List of projects

### Collections
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
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/linked_list/src/linked_list.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/linked_list/src/linked_list.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Vector</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/vector/src/vector.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/vector/src/vector.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Stack</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/stack/src/stack.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/stack/src/stack.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Queue</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/queue/src/queue.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/queue/src/queue.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Heap</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/heap/src/heap.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/heap/src/heap.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Binary Search Tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/binary_search_tree/src/binary_search_tree.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/binary_search_tree/src/binary_search_tree.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Avl Tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/avl_tree/src/avl_tree.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/avl_tree/src/avl_tree.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Red Black Tree</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/python/red_black_tree/src/red_black_tree.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/red_black_tree/src/red_black_tree.cpp">Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>Hash Table</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/hash_table/src/hash_table.py">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/collections_and_containers/cpp/hash_table/src/hash_table.cpp">Cpp</a></td>
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
            <td><a href="https://github.com/djeada/Data-Structures/blob/master/src/graphs/python/graph">Python</a></td>
            <td><a href="https://github.com/djeada/Data-Structures/tree/master/src/graphs/cpp/graph">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>BFS</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs">Python</a></td>
            <td><a href="https://github.com/djeada/Data-Structures/tree/master/src/graphs/cpp/bfs/src">Cpp</a></td>
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
* https://www.csc.kth.se/~viggo/problemlist/M
* https://cp-algorithms.com/
* https://www.personal.kent.edu/~rmuhamma/Compgeometry/compgeom.html
* https://codeahoy.com/learn/cprogramming/toc/

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
