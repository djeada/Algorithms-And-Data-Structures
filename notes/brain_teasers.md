## Solving Programming Brain Teasers

Programming puzzles and brain teasers are excellent tools for testing and enhancing your coding abilities and problem-solving skills. They are frequently used in technical interviews to evaluate a candidate's logical thinking, analytical prowess, and ability to devise efficient algorithms. To excel in these scenarios, it is recommended to master effective strategies for approaching and solving these problems.

### General Strategies

When tackling programming puzzles, consider the following strategies:

- Starting with a **simple solution** can help you understand the problem better and identify key challenges. This initial approach often highlights areas where optimization is needed later.
- Writing **unit tests** ensures your solution works for a variety of input scenarios. These tests are invaluable for catching logical errors and handling edge cases, and they allow for safe updates through regression testing.
- Analyzing the **time and space complexity** of your algorithm helps you measure its efficiency. Aim for the best possible complexity, such as $O(n)$, while avoiding unnecessary memory usage.
- Choosing the **appropriate data structure** is important for achieving better performance. Knowing when to use structures like arrays, linked lists, stacks, or trees can greatly enhance your solution.
- **Hash tables** are ideal for problems that require fast lookups, such as counting elements, detecting duplicates, or associating keys with values, as they offer average-case $O(1)$ complexity.
- Implementing **memoization or dynamic programming** can optimize problems with overlapping subproblems by storing and reusing previously computed results to save time.
- Breaking a problem into **smaller subproblems** often simplifies the process. Solving these subproblems individually makes it easier to manage and integrate the solutions.
- Considering both **recursive and iterative approaches** allows flexibility. Recursion can simplify the logic for certain problems, while iteration may be more efficient and avoid stack overflow risks.
- Paying attention to **edge cases and constraints** helps ensure robustness. Examples include handling empty inputs, very large or very small values, and duplicate data correctly.
- While optimizing too early can complicate development, **targeted optimization** at the right time focuses on the most resource-intensive parts of the code, improving performance without reducing clarity or maintainability.

### Data Structures

Understanding and effectively using data structures is fundamental in programming. Below are detailed strategies and tips for working with various data structures.

#### Working with Arrays

Arrays are fundamental data structures that store elements in contiguous memory locations, allowing efficient random access. Here are strategies for working with arrays:

- **Sorting** an array can simplify many problems. Algorithms like Quick Sort and Merge Sort are efficient with $O(n \log n)$ time complexity. For nearly sorted or small arrays, **Insertion Sort** may be a better option due to its simplicity and efficiency in those cases.
- In **sorted arrays**, binary search provides a fast way to find elements or their positions, working in $O(\log n)$. Be cautious with **mid-point calculations** in languages prone to integer overflow due to fixed-size integer types.
- The **two-pointer technique** uses two indices, often starting from opposite ends of the array, to solve problems involving pairs or triplets, like finding two numbers that add up to a target sum. It helps optimize time and space.
- The **sliding window technique** is effective for subarray or substring problems, such as finding the longest substring without repeating characters. It keeps a dynamic subset of the array while iterating, improving efficiency.
- **Prefix sums** enable quick range sum queries after preprocessing the array in $O(n)$. Similarly, **difference arrays** allow efficient range updates without modifying individual elements one by one.
- **In-place operations** modify the array directly without using extra memory. This approach saves space but requires careful handling to avoid unintended side effects on other parts of the program.
- When dealing with **duplicates**, it’s important to adjust the algorithm to handle them correctly. For example, in the two-pointer technique, duplicates may need to be skipped to prevent redundant results or errors.
- **Memory usage** is a important consideration with large arrays, as they can consume significant space. Be mindful of space complexity in constrained environments to prevent excessive memory usage.

#### Working with Strings

Strings, as sequences of characters, often require special handling due to their immutable nature in some languages and the variety of operations performed on them.

- In languages with **immutable strings**, repeatedly concatenating strings using the `+` operator inside a loop can result in inefficient $O(n^2)$ time complexity. To optimize to $O(n)$, use a `StringBuilder` in Java or `''.join(list_of_strings)` in Python.
- Efficient **string search algorithms** like Knuth-Morris-Pratt (KMP), Rabin-Karp, or Boyer-Moore can significantly outperform the naive $O(nm)$ approach, where $n$ is the text length and $m$ is the pattern length.
- **Tries (prefix trees)** are specialized data structures for storing and retrieving strings with shared prefixes efficiently. They are widely used in applications like autocomplete, spell checking, and IP routing.
- **Regular expressions** are powerful for pattern matching and text processing but require careful design to avoid inefficiencies. Poorly written patterns can lead to exponential time complexity, which impacts performance.
- Being aware of **Unicode and character encoding** (e.g., ASCII, UTF-8) is important when working with strings, especially for internationalization or data from external sources, to ensure proper handling and compatibility.
- For tasks like **anagram detection**, using character count arrays or hash maps is an efficient way to compare character frequencies between two strings. Similarly, for **palindrome checks**, the two-pointer technique or a simple comparison with the string’s reverse can provide quick solutions.

#### Working with Linked Lists

Linked lists are dynamic data structures consisting of nodes that contain data and references to the next (and possibly previous) nodes.

- Choosing the **appropriate list type** depends on the problem's requirements. Singly linked lists work well for one-way traversal and minimize memory usage, while doubly linked lists are better for two-way traversal or when efficient insertions and deletions from both ends are needed.
- **Insertions and deletions in linked lists** are efficient at known positions, especially at the head or tail, with an average time complexity of $O(1)$. When deleting nodes, ensure the previous node's pointer is updated correctly to avoid breaking the list structure.
- **Reversing a singly linked list** involves iterating through the nodes and redirecting their `next` pointers to point to the previous node. This can be done in $O(n)$ time with $O(1)$ extra space, making it an efficient operation.
- **Detecting cycles in a linked list** is possible using Floyd’s Tortoise and Hare algorithm. A slow pointer and a fast pointer move at different speeds; if they meet, the list contains a cycle.
- Handling **edge cases** in linked lists, such as empty lists, single-node lists, or lists with cycles, is essential. Always check for null pointers to prevent runtime errors, particularly in languages that don’t handle such exceptions automatically.
- In environments with **manual memory management**, it’s important to explicitly free memory for nodes that are no longer needed. This prevents memory leaks and ensures efficient resource usage.

#### Working with Trees and Binary Trees

Trees are hierarchical data structures with a root node and child nodes. Binary trees are a specific type where each node has at most two children.

- **Tree traversals** are key techniques for exploring binary trees, including in-order, pre-order, and post-order methods. These can be done recursively or iteratively, with stacks often used to simulate the recursive behavior in iterative solutions.
- A **Binary Search Tree (BST)** organizes nodes so that the left subtree contains keys smaller than the root, and the right subtree contains keys larger. This structure supports efficient operations like search, insertion, and deletion, usually taking $O(\log n)$ time in balanced trees.
- **Balancing trees**, such as AVL trees and Red-Black trees, maintain a logarithmic height to ensure efficient $O(\log n)$ operations. They use rotations to rebalance the tree after insertions or deletions.
- **Heaps** are tree structures where each parent node satisfies a heap property. In a max-heap, the parent is greater than or equal to its children. Heaps are ideal for priority queues, where quick access to the maximum or minimum element is needed.
- **Binary heaps** are commonly implemented using arrays for efficient memory usage. They allow $O(\log n)$ operations like insertion, deletion, and heapify. **Heap Sort**, based on binary heaps, is an in-place sorting algorithm with a time complexity of $O(n \log n)$.
- Solving **common tree problems** often involves tasks like finding the lowest common ancestor of two nodes, determining the depth or height of the tree, and performing level-order traversals using breadth-first search (BFS). These are foundational skills for tree-based problem-solving.

#### Working with Graphs

Graphs consist of vertices (nodes) and edges connecting them, used to represent complex relationships.

I. **Graph Representations**:

- An **adjacency list** is a structure where each element corresponds to a node and contains a list of adjacent nodes. It is particularly efficient for representing sparse graphs, where not all nodes are connected to many others.
- An **adjacency matrix** is a 2D array in which the entry $(i, j)$ indicates whether there is an edge (and possibly the weight of that edge) between nodes $i$ and $j$. This method is more suitable for dense graphs where many nodes are interconnected.

II. **Graph Traversal Algorithms**:

- **Depth-First Search (DFS)** explores a graph by going as deep as possible along each branch before backtracking. It can be implemented using recursion, which implicitly uses a stack, or by explicitly maintaining a stack.
- **Breadth-First Search (BFS)** explores all neighbors of a node at the current depth level before moving on to the next level of nodes. This algorithm uses a queue to keep track of nodes that need to be visited.

III. **Cycle Detection**:

- In **directed graphs**, cycle detection can be done using DFS while tracking the recursion stack to identify back edges, which indicate the presence of a cycle.
- For **undirected graphs**, cycle detection can be performed using either DFS or BFS. A cycle is detected if a visited node is encountered again, excluding its immediate parent.

IV. **Shortest Path Algorithms**:

- **Dijkstra's Algorithm** finds the shortest path from a source node to all other nodes in a graph with non-negative edge weights. It uses a priority queue (min-heap) to efficiently select the node with the smallest tentative distance.
- **Bellman-Ford Algorithm** can handle graphs with negative edge weights and detects negative weight cycles. It works by repeatedly relaxing all edges in the graph.
- **Floyd-Warshall Algorithm** computes shortest paths between all pairs of nodes. It is suitable for dense graphs but has a higher time complexity of $O(n^3)$, making it less efficient for sparse graphs.

V. **Minimum Spanning Trees (MST)**:

- **Prim's Algorithm** builds a minimum spanning tree by starting with an arbitrary node and adding the smallest edge that connects the current tree to a node outside of it. A priority queue is used to efficiently manage edge selection.
- **Kruskal's Algorithm** constructs the minimum spanning tree by sorting all edges and adding them in order of increasing weight, while using a Union-Find data structure to avoid forming cycles.

VI. **Network Flow Algorithms**:

- The **Ford-Fulkerson Method** calculates the maximum flow in a flow network by finding augmenting paths. It is useful for networks with capacities and adjusts flows iteratively.
- The **Edmonds-Karp Algorithm** is a specific implementation of the Ford-Fulkerson method that uses BFS to find the shortest augmenting paths, improving its efficiency for certain types of networks.

VII. **Other Important Concepts**:

- **Topological sorting** is applied to directed acyclic graphs (DAGs) and produces a linear ordering of vertices such that for every directed edge $uv$, vertex $u$ appears before $v$ in the ordering.
- **Strongly Connected Components (SCCs)** can be identified in directed graphs using algorithms such as Kosaraju's or Tarjan's, which efficiently decompose the graph into its SCCs.
- **Graph coloring and bipartite graphs** involve assigning colors to nodes such that no two adjacent nodes share the same color. BFS or DFS can be used to check if a graph is bipartite (i.e., 2-colorable), while backtracking or greedy methods may be used for more general graph coloring problems.

#### Working with Hash Tables

Hash tables store key-value pairs for efficient lookup, insertion, and deletion.

- When **choosing a good hash function**, ensure it distributes keys uniformly across the table to reduce the likelihood of collisions. For custom objects, it's important to override hash functions carefully, ensuring they are consistent and align with the object’s equality logic.
- To deal with **collisions**, two main methods are commonly used: **Chaining**, where multiple elements that hash to the same index are stored in a linked list or another structure at that index. **Open addressing**, which resolves collisions by finding another empty slot through probing methods, such as linear probing, quadratic probing, or double hashing.
- The **load factor and resizing** are important aspects of hash table management. The load factor, which is the ratio of the number of elements to the number of buckets, should be monitored. When the load factor exceeds a certain threshold (often around 0.7), it's time to resize and rehash the table to maintain performance.
- Always use **immutable keys** in a hash table to avoid complications from key mutation. If a key changes after insertion, it can corrupt the structure of the hash table and lead to retrieval failures.
- Hash tables have numerous **applications**, including frequency counting, caching, indexing, and implementing associative arrays like dictionaries or maps in various programming languages.
- While hash tables offer **$O(1)$ average-case time complexity**, it’s important to understand that the worst-case time complexity can degrade to $O(n)$ if the hash function leads to many collisions, particularly when the load factor is too high.

### Algorithms

Mastering algorithms is helpful for solving programming problems more efficiently by understanding patterns and techniques that reduce time and space usage.

#### Two-Pointer Technique

I. The **two-pointer technique** is ideal when working with sorted arrays or when the task involves finding pairs or triplets that meet a certain condition, such as summing to a target value.

II. **Implementation tips** for the two-pointer technique include:

- **Initialization**, where two pointers are placed at specific positions, typically at the start and end of the array.
- The **movement logic** dictates how the pointers move based on the comparison of the sum or product of the elements they point to with the target value.
- **Avoiding duplicates** is helpful, especially when finding multiple solutions, so you should skip over repeated elements to prevent redundant results.

III. An example of this technique is finding all pairs in a sorted array that sum to a given value.

```
Step 1: Start with two pointers, `left` at the beginning and `right` at the end of the array.

  Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]
          ↑                       ↑
        left                   right
  Check: arr[left] + arr[right] = 1 + 9 = 10 (Target Found!)

Step 2: If `arr[left] + arr[right]` equals the target, you’re done!
If the sum is less than the target, move `left` right.
If the sum is greater than the target, move `right` left.

Example when the sum is too small:
  Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]
             ↑                  ↑
           left              right
  Check: arr[left] + arr[right] = 2 + 9 = 11 (Too Large, move `right` left)

Example when the sum is too large:
  Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]
          ↑                    ↑
        left                 right
  Check: arr[left] + arr[right] = 1 + 8 = 9 (Too Small, move `left` right)
```

#### Recursion

I. **Recursion** works by breaking a problem into smaller instances of itself, with each call reducing the size of the problem.

II. Key **principles** of recursion include:

- Defining a clear **base case** to ensure that recursion terminates when the simplest version of the problem is solved.
- Ensuring that the **recursive case** moves toward the base case by reducing the problem’s size or complexity with each call.
- Verifying the **correctness** of your recursion logic to ensure it mirrors the structure of the problem.

III. Consider **stack overflow** when recursion depth is too great. You can either switch to an iterative approach or use tail recursion optimization (if supported by the language). **Memoization** is another technique to improve efficiency by caching results of recursive calls to avoid redundant computations.

```
factorial(4)
|
|---> 4 * factorial(3)
           |
           |---> 3 * factorial(2)
                      |
                      |---> 2 * factorial(1)
                                 |
                                 |---> 1 * factorial(0)
                                            |
                                            |---> Base case: 1
```

#### Backtracking

I. **Backtracking** is well-suited for problems that require exploring all potential configurations, such as puzzles like Sudoku, the N-Queens problem, or combinatorial tasks.

II. **Implementation tips** for backtracking include:

- Clearly defining how to represent the **current state** of the problem.
- Using **constraints checking** before progressing to ensure that the current path meets the problem's criteria, which helps prune invalid paths early.
- Recursively **exploring** valid options by modifying the state and recursively diving deeper into the solution space.
- After exploring each path, **backtracking** involves undoing the last change and trying the next alternative, ensuring all possible solutions are considered.
- Consider **optimizations** such as using heuristics to explore more promising paths first.

III. A classic example is solving the **N-Queens problem**, where queens are placed row by row, and conflicts are resolved by backtracking when necessary.

**Step 1: Start with an empty board.**

- Place a queen in Row 1, Column 1.
- Try placing queens row by row.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

**Step 2: Move to Row 2.**

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Conflict! (Diagonal from Queen in Row 1).
- Try Column 3 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   | Q |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

**Step 3: Move to Row 3.**

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   | Q |   |
+---+---+---+---+
|   | Q |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

**Step 4: Move to Row 4.**

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Conflict! (Same column as Queen in Row 3).
- Try Column 3 → Conflict! (Diagonal from Queen in Row 2).
- Try Column 4 → Conflict! (Diagonal from Queen in Row 1).
- No valid positions! (All columns conflict).
- Backtrack: Remove the queen from Row 3, Column 2.

**Step 5: Try other possibilities in Row 3.**

- Try Column 3 → Conflict! (Diagonal from Queen in Row 1).
- Try Column 4 → Conflict! (Diagonal from Queen in Row 2).
- No valid positions in Row 3.
- Backtrack: Remove the queen from Row 2, Column 3.

**Step 6: Try other possibilities in Row 2.**

- Try Column 4 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   |   | Q |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

**Step 7: Move to Row 3.**

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   |   | Q |
+---+---+---+---+
|   | Q |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

Continue exploring alternatives and backtracking as necessary until all solutions are found.

#### Dynamic Programming

I. **Dynamic programming** is used to solve optimization problems by breaking them down into overlapping subproblems with an optimal substructure, meaning solutions to smaller subproblems can be reused to solve larger problems.
  
II. There are two primary **approaches** to dynamic programming:

- The **top-down approach (memoization)** involves using recursion while caching the results of subproblems to avoid redundant computations.
- The **bottom-up approach (tabulation)** builds a solution iteratively by solving the smallest subproblems first and using their solutions to solve larger subproblems.
  
III. The **key steps** in dynamic programming include:

- **Defining the subproblems** to break the main problem into manageable parts.
- **Identifying the state variables** that uniquely define each subproblem.
- Establishing a **recurrence relation** to compute the solution of each subproblem based on smaller subproblems.
- Proper **initialization** of base cases in a table or memoization cache.
- Determining the correct **iteration order** to fill the DP table for bottom-up approaches.

IV. **Space optimization** is often possible by realizing that only a few recent states are needed, reducing space complexity.
  
V. Classic examples include problems like the Fibonacci sequence, the Knapsack problem, or calculating the minimum edit distance between two strings.

```
DP Table (Rows = Items, Columns = Knapsack Capacities):

  Capacity ->  0   1   2   3   4   5   6   7
  Item 0     [ 0   0   0   0   0   0   0   0 ]  (Base case: No items)
  Item 1     [ 0   1   1   1   1   1   1   1 ]  (Include Item 1)
  Item 2     [ 0   1   1   4   5   5   5   5 ]  (Include Item 2)
  Item 3     [ 0   1   1   4   5   6   6   9 ]  (Include Item 3)
  Item 4     [ 0   1   1   4   5   7   8  11 ]  (Include Item 4)
```

**How the Table Is Filled**

For each cell $DP[i][w]$ if the weight of the item $i$ is less than or equal to the current capacity $w$, choose the maximum of:

- Value without including the item ($DP[i-1][w]$).
- Value including the item ($DP[i-1][w-\text{weight}[i]] + \text{value}[i]$).

**Visualization of Choices**

I. For **Item 1** (Weight = 1, Value = 1):

```
Capacity = 0 → Can't include Item 1 → DP[1][0] = 0
Capacity = 1 → Include Item 1 → DP[1][1] = 1
Capacity = 2 → Include Item 1 → DP[1][2] = 1
...
Capacity = 7 → Include Item 1 → DP[1][7] = 1
```

II. For **Item 2** (Weight = 3, Value = 4):

```
Capacity = 0 → Can't include Item 2 → DP[2][0] = 0
Capacity = 3 → Include Item 2 → DP[2][3] = 4
Capacity = 4 → Include Item 2 → DP[2][4] = 5
...
Capacity = 7 → Include Item 2 → DP[2][7] = 5
```

III. Continue for all items, progressively updating the table.

**Extract the Solution**

To find the maximum value look at the last cell: $DP[4][7] = 11$.

To find the items included trace back from $DP[4][7]$, checking where values changed:

- $DP[4][7] → Include Item 4$
- $DP[3][3] → Include Item 3$

**Final Knapsack Contents:**

- Item 3 (Weight 4, Value 5)
- Item 4 (Weight 3, Value 7)
- Total Weight = 7, Total Value = 11

### Greedy Algorithms

I. **Greedy algorithms** are used when making a locally optimal choice at each step leads to a globally optimal solution.
  
II. The two key **characteristics** of greedy algorithms are:

- **Optimal substructure**, meaning the overall solution incorporates optimal solutions to subproblems.
- The **greedy choice property**, where making the best local decision at each step results in the globally best solution.

III. Common **implementation tips** for greedy algorithms include:

- **Sorting** the input data according to a specific criterion before applying the greedy strategy.
- Always ensure the greedy choice leads to an optimal solution by providing a **proof of correctness** or counterexamples.

IV. Examples of greedy algorithms include the activity selection problem, Huffman coding, and algorithms for finding minimum spanning trees (Prim's and Kruskal's).

**Example Huffman coding Input**:

Characters: $[A, B, C, D, E, F]$  

Frequencies: $[5, 9, 12, 13, 16, 45]$

**Build a Min-Heap**

Create a priority queue (min-heap) with the characters and their frequencies.

```
Initial Min-Heap:
    5(A)  9(B)  12(C)  13(D)  16(E)  45(F)
```

**Build the Huffman Tree**

Combine the two smallest frequency nodes into a new node. Repeat until there is one tree.

I. Combine 5(A) and 9(B):

```
 (14)
 /  \
5(A) 9(B)
```

Updated Heap: $[12(C), 13(D), 14(AB), 16(E), 45(F)]$

II. Combine 12(C) and 13(D):

```
 (25)
 /  \
12(C) 13(D)
```

Updated Heap: $[14(AB), 16(E), 25(CD), 45(F)]$

III. Combine 14(AB) and 16(E):

```
 (30)
 /  \
14(AB) 16(E)
```

Updated Heap: $[25(CD), 30(ABE), 45(F)]$

IV. Combine 25(CD) and 30(ABE):

```
 (55)
 /  \
25(CD) 30(ABE)
```

Updated Heap: $[45(F), 55(CDABE)]$

V. Combine 45(F) and 55(CDABE):

```
Tree:
         (100)
         /    \
      45(F)  55(CDABE)
       /      \
    25(CD)   30(ABE)
    /   \     /    \
 12(C) 13(D) 14(AB) 16(E)
                  /   \
               5(A)   9(B)
```

**Assign Binary Codes**

Traverse the tree to assign codes:

- Left edge = `0`
- Right edge = `1`

```
Codes:
A = 000
B = 001
C = 100
D = 101
E = 01
F = 11
```

**Final Huffman Tree Diagram:**

```
Tree:
                        (100)
                       /     \
                    (45)     (55)
                   /         /    \
                (F)      (25)    (30)
                        /   \     /   \
                     (C)   (D) (14)  (E)
                                 /  \
                              (A)  (B)
```

#### Divide and Conquer

I. The **divide and conquer** strategy solves problems by dividing them into smaller subproblems, solving those independently, and then combining their solutions.
  
II. **Implementation tips** for divide and conquer:

- Use **recursion** to divide the problem, with each recursive call handling a subproblem.
- Pay attention to the **combine step**, as the efficiency of combining subproblem solutions can affect the overall performance.
- Define **base cases** for small subproblems that can be solved directly without further division.

III. Examples of divide and conquer algorithms include Merge Sort, Quick Sort, and Binary Search.

#### Graph Algorithms

Below is a detailed comparison of commonly used graph algorithms:

| **Algorithm/Technique**        | **Uses**                                                   | **Implementation**                                                                               |
|---------------------------------|-------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **Breadth-First Search (BFS)**  | Finding the shortest path in unweighted graphs, level-order traversal. | Use a queue to process nodes in a First In, First Out (FIFO) manner.                              |
| **Depth-First Search (DFS)**    | Topological sorting, cycle detection, pathfinding.          | Use recursion or a stack to explore as deep as possible before backtracking.                      |
| **Dijkstra's Algorithm**        | Shortest path in weighted graphs with non-negative weights. | Use a min-heap (priority queue) to select the next node with the smallest tentative distance.      |
| **Bellman-Ford Algorithm**      | Shortest path in graphs with negative weights, detecting negative cycles. | Relax all edges V-1 times, where V is the number of vertices.                                     |
| **Floyd-Warshall Algorithm**    | All pairs shortest paths.                                   | Use a 2D matrix to store distances, updating distances by considering each vertex as an intermediate point. |
| **Union-Find Data Structure**   | Keeping track of disjoint sets, cycle detection in Kruskal's algorithm. | Optimize with path compression and union by rank for efficient merging of sets and lookups.        |

### Sorting Algorithms

Sorting algorithms are fundamental to computer science and programming. They are used to rearrange elements in a list or array so that they follow a specific order (ascending or descending). Efficient sorting is a first step for optimizing other algorithms (like search and merge algorithms) that require input data to be in sorted lists. Understanding the different sorting algorithms, their time and space complexities, stability, and suitable use cases is essential for problem-solving and technical interviews.

#### Overview of Common Sorting Algorithms

Below is a detailed comparison of commonly used sorting algorithms:

| **Algorithm**       | **Average Time Complexity** | **Worst-Case Time Complexity** | **Space Complexity** | **Stability** | **Best Use Case**                            | **Notes**                                   |
|---------------------|-----------------------------|-------------------------------|----------------------|---------------|----------------------------------------------|---------------------------------------------|
| **Bubble Sort**     | $O(n^2)$                | $O(n^2)$                  | $O(1)$           | Stable        | Educational purposes, small datasets         | Simple but inefficient for large datasets   |
| **Insertion Sort**  | $O(n^2)$                | $O(n^2)$                  | $O(1)$           | Stable        | Nearly sorted or small datasets              | Efficient for small or nearly sorted datasets |
| **Selection Sort**  | $O(n^2)$                | $O(n^2)$                  | $O(1)$           | Unstable      | Small datasets, when memory is limited       | Inefficient for large datasets             |
| **Merge Sort**      | $O(n \log n)$           | $O(n \log n)$             | $O(n)$           | Stable        | Large datasets, linked lists                 | Requires additional memory for merging     |
| **Quick Sort**      | $O(n \log n)$           | $O(n^2)$                  | $O(\log n)$      | Unstable      | Large datasets, general-purpose sorting      | Pivot selection strategy affects performance |
| **Heap Sort**       | $O(n \log n)$           | $O(n \log n)$             | $O(1)$           | Unstable      | Large datasets, in-place sorting             | Efficient with minimal memory usage        |
| **Radix Sort**      | $O(nk)$                 | $O(nk)$                   | $O(n + k)$       | Stable        | Large datasets with integer keys             | Non-comparative sorting algorithm          |
| **Counting Sort**   | $O(n + k)$              | $O(n + k)$                | $O(k)$           | Stable        | Small range of integer keys                  | Efficient when range $k$ is small      |
| **Tim Sort**        | $O(n \log n)$           | $O(n \log n)$             | $O(n)$           | Stable        | Real-world data, hybrid sorting              | Default sorting algorithm in Python        |
| **Bucket Sort**     | $O(n + k)$              | $O(n^2)$                  | $O(n)$           | Stable        | Uniformly distributed data                   | Divides elements into buckets              |
| **Shell Sort**      | $O(n \log n)$ to $O(n^2)$ | $O(n^2)$            | $O(1)$           | Unstable      | Medium-sized datasets                        | Improves upon Insertion Sort               |

#### General Tips for Sorting Algorithms

- It’s important to **understand the data** when selecting a sorting algorithm. Factors such as the size of the dataset, its distribution, and the data type being sorted can significantly influence the choice of algorithm.
- If the **stability requirement** is important, meaning the relative order of equal elements must be preserved, you should opt for stable sorting algorithms like Merge Sort or Tim Sort.
- When memory is a concern, **in-place sorting** algorithms, such as Quick Sort or Heap Sort, are preferable because they require minimal additional memory.
- Consider the **time complexity trade-offs** when choosing a sorting algorithm. While Quick Sort is generally fast, its performance can degrade to $O(n^2)$ in the worst case if not implemented carefully.
- **Hybrid approaches** like Tim Sort, which combines Merge Sort and Insertion Sort, are designed to optimize performance by leveraging the strengths of multiple sorting techniques.

#### Practical Applications

- **Merge Sort** is particularly useful for sorting linked lists since it does not require random access to the elements.
- **Quick Sort** is often chosen for general-purpose sorting due to its efficiency in the average case and its ability to sort in-place.
- **Counting Sort** and **Radix Sort** are effective when sorting integers within a known and limited range, offering linear-time complexity under the right conditions.
- **Heap Sort** is a good option when memory usage is restricted and a guaranteed $O(n \log n)$ time complexity is necessary.
- **Insertion Sort** is ideal for very small datasets or as a subroutine in more complex algorithms due to its simplicity and efficiency on nearly sorted data.

### Bit Manipulation

Bit manipulation involves algorithms that operate directly on bits, the basic units of data in computing. By leveraging bit-level operations, you can achieve performance optimizations, reduce memory usage, and solve certain problems more elegantly. Bit manipulation is particularly useful in systems programming, cryptography, graphics, and competitive programming.

#### Fundamental Concepts

- A solid grasp of **binary representation** is essential for working with bitwise operations. In binary, each digit (or bit) represents a power of 2, starting with the least significant bit (LSB) on the right, which corresponds to $2^0$, and increasing as you move left.
- **Signed and unsigned integers** differ in how they represent numbers. **Unsigned integers** can only represent non-negative values, while **signed integers** use the most significant bit (MSB) as a sign bit, with 0 representing positive numbers and 1 representing negative numbers, typically using two's complement representation.
- **Bitwise operators** are key tools for manipulating individual bits. The **AND (`&`)** operator produces 1 only when both corresponding bits are 1, making it useful for masking bits. The **OR (`|`)** operator sets a bit to 1 if at least one of the corresponding bits is 1, often used for setting bits.
- The **XOR (`^`)** operator produces 1 when the bits are different, useful for toggling bits or swapping values. The **NOT (`~`)** operator flips all bits, performing a bitwise negation.
- The **left shift (`<<`)** operation shifts bits to the left, filling with zeros from the right, effectively multiplying the number by powers of two. Conversely, **right shift (`>>`)** operations shift bits to the right, with two variations: **logical shifts**, which fill with zeros from the left (used for unsigned integers), and **arithmetic shifts**, which preserve the sign bit, used for signed integers.

#### Bit Manipulation Techniques

- To **set a bit** at position $n$ to 1, the operation `number |= (1 << n)` can be used. This works by left-shifting 1 by $n$ positions to create a mask with only the $n$-th bit set, and then applying bitwise OR to modify the original number.
- To **clear a bit** at position $n$, use the operation `number &= ~(1 << n)`. Here, 1 is left-shifted by $n$ and negated to form a mask where only the $n$-th bit is 0, and applying bitwise AND clears that bit.
- To **toggle a bit** at position $n$, the operation `number ^= (1 << n)` is used. By left-shifting 1 by $n$ and applying XOR, the target bit at $n$ is flipped.
- To **check if a bit** at position $n$ is set to 1, the operation `(number & (1 << n)) != 0` is employed. It works by left-shifting 1 by $n$ and applying bitwise AND; a non-zero result indicates the bit is set.
- To **clear the least significant bit (LSB)**, the operation `number &= (number - 1)` is effective. Subtracting 1 flips all bits from the LSB onward, and applying AND clears the lowest set bit.
- To **isolate the least significant bit**, the operation `isolated_bit = number & (-number)` is used. In two’s complement, `-number` is the bitwise complement plus one, so ANDing it with `number` isolates the LSB.
- To **count the set bits** (Hamming weight) in a number, Kernighan's Algorithm is applied using the following code:

```c
int count = 0;
while (number) {
    number &= (number - 1);
    count++;
}
```

This works by repeatedly clearing the LSB and incrementing the count.

- To **check if a number is a power of two**, the condition `(number != 0) && ((number & (number - 1)) == 0)` is used. This works because powers of two have only one set bit, and subtracting 1 flips all bits after that set bit, resulting in zero when ANDed.
- To **swap two variables** without using a temporary variable, the following sequence is used:

```c
a ^= b;
b ^= a;
a ^= b;
```

This sequence of XOR operations swaps the values of `a` and `b` without needing extra space.

- To **reverse the bits** in a number, bitwise operations and shifting can be used to swap bits from opposite ends, moving towards the center of the number. This is commonly achieved using a loop or bit manipulation techniques to systematically reverse bit positions.

#### Bit Masks

- A **bitmask** is a binary pattern used to select or manipulate specific bits within a byte or word, enabling efficient operations on particular bits of a number.
- **Common uses of bitmasks** include applications such as feature flags, where each bit represents a boolean option or setting, and permission sets in file systems, where bits represent different permissions like read, write, or execute.
- **State representation** is another common use, where multiple boolean states are stored in a single integer, allowing efficient space usage and manipulation of these states.
- To **create a bitmask** that selects specific bits, you can combine shifts and bitwise OR. For example, to create a mask for bits 0 and 3, the operation `mask = (1 << 0) | (1 << 3)` will set only those bits to 1.

#### Bit Shifting Tricks

- **Left shifting** (`<<`) is a useful technique for **multiplying by powers of two**. For instance, `number << 3` multiplies `number` by \(2^3 = 8\), which is a fast alternative to regular multiplication.
- Similarly, **right shifting** (`>>`) can be used for **dividing by powers of two**. For example, `number >> 2` divides `number` by \(2^2 = 4\), making it an efficient way to handle division for unsigned integers or logical shifts.
- To **extract specific bits** from a number, you can use a combination of shifting and masking. For instance, to extract bits from position $p$ to $p + n - 1$, the operation `(number >> p) & ((1 << n) - 1)` can be applied. This shifts the target bits to the right and uses a mask to isolate only those bits.

#### Cautions and Best Practices

- In programming, it is important to note that **bitwise operators** have lower precedence than arithmetic and relational operators, so parentheses should be used to ensure the correct order of operations.
- When working with shifts, be aware that **arithmetic shifts** (using `>>`) preserve the sign bit in signed integers, which is useful when working with negative numbers.
- Some languages, like Java, also support **logical shifts**, represented as `>>>`, which shift zeros into the high-order bits regardless of the sign of the number.
- **Portability** can be a concern in bit manipulation code because differences in integer sizes and endianness across various systems may affect how the code behaves.
- Be careful to avoid **overflow and underflow** when performing shifts, as shifting bits beyond the size of the data type can lead to unintended results.
- While bit manipulation can be powerful, excessive use can hurt **readability**. To make the code easier to maintain, it’s a good practice to include comments and, where appropriate, use macros or inline functions.

### List of problems

#### Minimum deletions to make valid parentheses

Given a string of parentheses, determine the minimum number of parentheses that need to be removed to make the string valid. This can be solved using a stack data structure to track the open parentheses as we iterate through the string. If we encounter an open parenthesis, we add it to the stack. If we encounter a closing parenthesis, we check if there is a matching open parenthesis on the top of the stack. If there is, we pop the open parenthesis from the stack. If there is not, we add the closing parenthesis to a list of characters to remove. After we have processed the entire string, we remove the remaining open parentheses from the stack.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/deletions_to_make_valid_parentheses)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/deletions_to_make_valid_parentheses)

#### Is palindrome after at most one char delete?

Determinine whether a string can be transformed into a palindrome by deleting at most one character. This can be solved using a two pointer approach, where we start from both ends of the string and move towards the middle. If we encounter a pair of characters that are not equal, we have three options: delete the character at the left pointer, delete the character at the right pointer, or delete both characters. We check if any of these options results in a palindrome and return the result.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/is_palindrome_after_char_deletion)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/is_palindrome_after_char_deletion)

#### K closest points to origin 	

Find the K points in a list of points that are closest to the origin (0, 0). This can be solved using a min heap data structure, where we store the K closest points so far. As we iterate through the list of points, we compute the distance from each point to the origin and add it to the heap if it is among the K closest points so far.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/k_closest_points)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/k_closest_points)

#### Subarray sum equals K 	

Find a contiguous subarray of an array that has a sum of K. This can be solved using a sliding window approach, where we maintain a running sum of the elements in the window and move the window through the array until we find a subarray with the desired sum.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/subarray_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/subarray_sum)

#### Add numbers given as strings 	

Add two numbers represented as strings. This can be solved by treating the strings as arrays of digits and using a carry variable to keep track of the carryover from one place value to the next.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/add_string_numbers)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/add_string_numbers)

#### Dot product of two sparse vectors 	

Compute the dot product of two sparse vectors, where a vector is represented as a list of (index, value) pairs. This can be solved by iterating through both vectors and adding up the products of the values at the same index.
 
 
* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/sparse_vectors_product)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/sparse_vectors_product)

#### Range sum of BST 	

Compute the sum of the values of all the nodes in a binary search tree within a given range. This can be solved using a recursive in-order traversal of the tree, where we add the value of each node to the sum if it is within the range.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/range_sum_of_bst)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/range_sum_of_bst)

#### Product of array except self 	

Compute an array where each element is the product of all the other elements in the input array. This can be solved using two pass approach, where we first compute the product of all the elements before each index and then compute the product of all the elements after each index.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/array_product)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/array_product)

#### Convert BST to sorted doubly linked list 

Convert a binary search tree to a sorted doubly linked list. This can be solved using a recursive in-order traversal of the tree, where we build the linked list by adding each node to the end of the list as we visit it.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/bst_to_list)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/bst_to_list)

#### Lowest common ancestor of a binary tree

Find the lowest common ancestor (LCA) of two nodes in a binary tree. The LCA is the node in the tree that is the ancestor of both nodes and is the deepest node in the tree. To solve this problem, you can use a variety of techniques such as traversing the tree in a depth-first or breadth-first manner, or using a recursive approach to traverse the tree and find the LCA. You can also use a divide and conquer approach, where you split the tree into left and right subtrees and find the LCA in each subtree. Another approach is to use a hash table or a map to store the ancestors of each node and then use this information to find the LCA.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lowest_common_ancestor)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lowest_common_ancestor)

#### LRU Cache 	

Designing a cache data structure that stores a limited number of items and removes the least recently used items when the capacity is reached. This can be solved using a doubly linked list and a hash table. The doubly linked list is used to store the items in the cache in the order in which they were accessed, with the most recently accessed item at the front of the list and the least recently accessed item at the back. The hash table is used to store the keys and values of the items in the cache and to quickly retrieve items from the cache based on their keys.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lru_cache)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lru_cache)

#### Randomize An Array 	

Shuffle the elements of an array randomly. This can be solved using a random number generator and a Fisher-Yates shuffle algorithm. The Fisher-Yates shuffle algorithm works by starting at the end of the array and randomly swapping each element with an element preceding it. This results in a randomly shuffled array.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/randomize_array)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/randomize_array)

#### Binary Tree Right Side View

Given a binary tree, return an array containing the values of the nodes on the right side of the tree, when viewed from the right. One way to solve this problem might be to perform a breadth-first search on the tree, keeping track of the maximum depth of each node as it is visited. When visiting a node at a particular depth for the first time, add its value to the result array.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/binary_tree_right_side_view)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/binary_tree_right_side_view)

#### Design Browser History

Implement a browser history system that supports the following operations: visit a URL, go back to the previous URL, and go forward to the next URL. One potential approach to this problem could involve using a doubly-linked list to store the URLs visited, with a pointer to the current URL. Going back or forward would simply involve moving the pointer to the previous or next URL in the list.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/design_browser_history)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/design_browser_history)

#### Score After Flipping Matrix

Given a matrix of 0s and 1s, flip the rows and columns of the matrix such that the maximum possible score is achieved. The score is calculated as the number of 1s in the matrix. One way to solve this problem might be to use dynamic programming to compute the maximum score for each submatrix of the original matrix, taking into account whether the rows and columns of the submatrix should be flipped.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/score_after_flipping_matrix)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/score_after_flipping_matrix)
