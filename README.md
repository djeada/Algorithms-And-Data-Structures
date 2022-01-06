# Algorithms-And-Data-Structures

<a href="https://github.com/djeada/Data-Structures/stargazers"><img alt="GitHub stars" src="https://img.shields.io/github/stars/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/network"><img alt="GitHub forks" src="https://img.shields.io/github/forks/djeada/Data-Structures"></a>
<a href="https://github.com/djeada/Data-Structures/blob/master/LICENSE"><img alt="GitHub license" src="https://img.shields.io/github/license/djeada/Data-Structures"></a>
<a href=""><img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"></a>
</div>

Implementations of various algorithms.

<h1>About</h1>

Since I initially attended the course at my university in 2015, Algorithms and Data Structures have attracted my attention. I find it really beneficial to return to the fundamentals on a regular basis, especially while learning a new language. While learning, I usually find it helpful to compare my approach to that of others. Since this is my n'th iteration of the process, I wanted to share my code with others so that they, too, may benefit from it.

The code is written in two of my favorite programming languages: C++ and Python. To the best of my ability, I adhered to modern practices.

Aside from the code, you'll come across various comprehensive notes that I wrote down while learning the subject.

<h1>Requirements</h1>

For C++ projects you will need:
* C++ compiler supporting C++14
* Cmake 3.15+

For Python projects you will need:
* Python 3.10+

No additional libraries or modules are needed.

<h1>How to run examples?</h1>
Each algorithm implementation is contained in its own subdirectory, which contains the source code, unit tests, and build configuration files. Each subdirectory is a distinct project that should be built independently.

<h3>C++</h3>

To build a C++ project and run unit tests, go to the project directory and execute the following commands:

```bash
mkdir build
cd build
cmake ..
make
ctest --verbose
```

<h3>Python</h3>

Use the following commands to run Python unit tests from the project directory:

```bash
python -m unittest discover -p 'test*.py'
```

<h1>Collections</h1>
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
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Vector</td>
            <td><a>Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/vector">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Stack</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/stack">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/stack">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Queue</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/queue">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/queue">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Heap</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/heap">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/heap">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>BST</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Avl Tree</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Red Black Tree</td>
            <td><a>Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>Hash Table</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/hashtable">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
    </tbody>
</table>


<h1>Graphs</h1>
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

<h1>Backtracking</h1>
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

<h1>Dynamic Programming</h1>
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
            <td><a href="">Cpp</a></td>
        </tr>
    </tbody>
</table>

<h1>Sorting</h1>
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

<h1>Bibliography </h1>

<ol>
    <li>L. V. Narashima Prasad, E. Kishna Rao Patro "<i>Lecture Notes on Data Structures using C</i>" </li>
    <li>Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. "<i>Introduction to Algorithms, 3rd Edition (The MIT Press)</i>"</li>
    <li>Steven Halim "<i>Competitive Programming 3</i>" </li>
    <li>Narasimha Karumanchi "<i>Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles</i>" </li>
    <li>Brian Kernighan, Dennis Ritchie "<i>The C Programming Language</i>" </li>
    <li>Steven Skiena, Miguel Revilla "<i>Programming Challenges: The Programming Contest Training Manual</i>" </li>
    <li>Antti Laaksonen "<i>  Guide to Competitive Programming: Learning and Improving Algorithms Through Contests (Undergraduate Topics in Computer Science) </i>" </li>
    <li>Nite Nimajneb "<i>The Hitchhiker’s Guide to the Programming Contests</i>" </li>
    <li>http://cslibrary.stanford.edu/</li>
    <li>https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-851-advanced-data-structures-spring-2012/</li>
    <li>https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-0002-introduction-to-computational-thinking-and-data-science-fall-2016/lecture-slides-and-files/index.htm</li>
    <li>https://www.cs.bham.ac.uk/~jxb/DSA/</li>
    <li>https://www.ics.uci.edu/~eppstein/161/syl.html</li>
    <li>http://www.columbia.edu/~cs2035/oldcourses.html</li>
    <li>https://www.cs.auckland.ac.nz/courses/compsci220s1t/lectures/lecturenotes/GG-lectures/</li>
    <li>https://sp19.datastructur.es/</li>
    <li>https://www.csc.kth.se/~viggo/problemlist/M</li>
</ol>
