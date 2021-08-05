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
* Python 3.6+

<h1>How to run examples?</h1>
Each algorithm implementation has its own subdirectory with source code, unit tests and build files. They are all independent of each other and should be built independently.

Go to the project directory and run the following commands to create a C++ project and run unit tests:

```bash
mkdir build
cd build
cmake ..
make
ctest --verbose
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
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/cpp/vector">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Stack</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/python/stack">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/cpp/stack">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Queue</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/python/queue">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/cpp/queue">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Heap</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/python/heap">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/cpp/heap">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Binary Tree</td>
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
            <td>Hash Map</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections/python/hashtable">Python</a></td>
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
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/a%20star">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/a%20star">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Bellman-Ford</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman%20ford">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman%20ford">Cpp</a></td>
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
            <td>Genereting words</td>
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
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/fibonacci">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Grid travelers</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/grid%20traveler">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Stairs</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/climbing%20stairs">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Can sum</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/can%20sum">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/cpp/can%20sum">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>How sum</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/how%20sum">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/cpp/how%20sum">Cpp</a></td>
        </tr>
        <tr>
            <td>6</td>
            <td>Best sum</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/best%20sum">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>7</td>
            <td>Can construct</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/can%20construct">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/cpp/can%20construct">Cpp</a></td>
        </tr>
        <tr>
            <td>8</td>
            <td>Count construct</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/count%20construct">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/cpp/count%20construct">Cpp</a></td>
        </tr>
        <tr>
            <td>9</td>
            <td>All construct</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/all%20construct">Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/cpp/all%20construct">Cpp</a></td>
        </tr>
        <tr>
            <td>10</td>
            <td>Coins</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/coins">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>11</td>
            <td>Longest increasing subarray</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/longest%20increasing%20subarray">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>12</td>
            <td>Longest common subsequence</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/longest%20common%20subsequence">Python</a></td>
            <td><a>Cpp</a></td>
        </tr>
        <tr>
            <td>13</td>
            <td>Knuth-Morris-Pratt</td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic%20programming/python/kmp">Python</a></td>
            <td><a>Cpp</a></td>
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
            <td>Heap sort</td>
            <td><a>Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/heap%20sort">Cpp</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Insertion sort</td>
            <td><a>Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/insertion%20sort">Cpp</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>Merge sort</td>
            <td><a>Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/merge%20sort">Cpp</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td>Quick sort</td>
            <td><a>Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/quick%20sort">Cpp</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td>Selection sort</td>
            <td><a>Python</a></td>
            <td><a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/selection%20sort">Cpp</a></td>
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
    <li>http://cslibrary.stanford.edu/105/</li>
    <li>https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-851-advanced-data-structures-spring-2012/</li>
    <li>https://www.cs.bham.ac.uk/~jxb/DSA/</li>
    <li>https://www.ics.uci.edu/~eppstein/161/syl.html</li>
</ol>
