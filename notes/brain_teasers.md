# Solving Programming Brain Teasers

Programming puzzles and brain teasers are excellent tools for testing and enhancing your coding abilities and problem-solving skills. They are frequently used in technical interviews to evaluate a candidate's logical thinking, analytical prowess, and ability to devise efficient algorithms. To excel in these scenarios, it is crucial to master effective strategies for approaching and solving these problems.

## General Strategies

When tackling programming puzzles, consider the following comprehensive strategies:

- When tackling a problem, it is often beneficial to begin by **implementing a straightforward solution** to gain a basic understanding of its intricacies. This approach provides insight into potential bottlenecks and serves as a foundation for further optimization.
- Writing **unit tests is essential** to validate the correctness of your solution by ensuring it works for various input scenarios. They play a crucial role in identifying logical errors and edge cases early on, while also enabling regression testing after making changes to the code.
- It is important to **evaluate the time and space complexity** of your algorithm, particularly in competitive programming or interviews. Striving for optimal time complexity, such as \( O(n) \), is crucial while also keeping an eye on space complexity to avoid unnecessary memory usage.
- **Selecting the right data structure** can significantly impact your solution's performance. Understanding the strengths and weaknesses of different data structures allows you to make the most efficient choice for a given problem.
- **Using hash tables** is often a good strategy when fast lookup operations are required. With an average-case complexity of \( O(1) \), hash tables are useful for counting frequencies, checking duplicates, or mapping keys to values.
- **Memoization and dynamic programming** can be employed for problems with overlapping subproblems, helping to avoid redundant computations and significantly improve efficiency by caching results.
- For complex problems, it can be helpful to **break the problem down into smaller subproblems**. Solving these subproblems individually can make the overall problem easier to manage and understand.
- In some situations, you may need to **consider both recursive and iterative approaches** to solving the problem. While recursion may feel more natural for certain problems, an iterative solution could offer better efficiency or avoid stack overflow issues.
- Always be mindful of **edge cases and constraints** presented in the problem, such as empty inputs, extreme values, or duplicates. Ensuring your solution addresses these cases can prevent unexpected failures.
- Though premature optimization can lead to complications, it is important to **optimize at the right time**, focusing on the most critical sections of your code. Doing so can enhance performance without sacrificing the clarity or maintainability of your solution.

## Data Structures

Understanding and effectively using data structures is fundamental in programming. Below are detailed strategies and tips for working with various data structures.

### Working with Arrays

Arrays are fundamental data structures that store elements in contiguous memory locations, allowing efficient random access. Here are strategies for working with arrays:

- **Sorting arrays** can greatly simplify many types of problems by bringing order to the data. Algorithms like Quick Sort and Merge Sort are efficient choices, with average and worst-case time complexities of \( O(n \log n) \). However, for nearly sorted arrays or smaller datasets, **Insertion Sort** might be a more efficient option.
- In **sorted arrays**, binary search is an efficient method for locating elements or determining insertion points. This technique operates with a time complexity of \( O(\log n) \), but care must be taken in handling mid-point calculations, particularly in languages prone to **integer overflow** due to fixed-size integer types.
- The **two-pointer technique** is an approach that uses two indices to traverse the array, often from opposite ends. This technique is particularly useful for problems involving pairs or triplets, such as finding pairs that sum to a target value, and can optimize space and time.
- The **sliding window technique** is highly effective for problems that involve subarrays or substrings, such as finding the longest substring without repeating characters. This method efficiently maintains a dynamic subset of the array while iterating through it.
- **Prefix sums** allow for efficient range sum queries by preprocessing the array in \( O(n) \) time. Similarly, **difference arrays** can be used to handle range update queries efficiently, reducing the need to update individual elements one by one.
- In scenarios where space is limited, **in-place operations** are preferred because they modify the array without using additional memory. It’s important to be cautious with side effects to ensure that in-place modifications do not inadvertently affect other parts of the program.
- When **handling duplicates**, it’s crucial to account for their impact on your algorithm. For example, when using the two-pointer technique, duplicates may need to be skipped to prevent redundant calculations or incorrect results.
- **Memory considerations** are important when working with large arrays, as they can consume substantial amounts of memory. It's vital to be mindful of the space complexity, especially in constrained environments, to prevent excessive memory usage.

### Working with Strings

Strings, as sequences of characters, often require special handling due to their immutable nature in some languages and the variety of operations performed on them.

- In languages with **immutable strings**, concatenating strings using the `+` operator inside a loop can lead to inefficient \( O(n^2) \) time complexity. To achieve \( O(n) \) time for concatenation, use a `StringBuilder` in Java or the `''.join(list_of_strings)` method in Python.
- **String search algorithms** like Knuth-Morris-Pratt (KMP), Rabin-Karp, or Boyer-Moore provide efficient ways to find patterns within strings, significantly improving on the naive \( O(nm) \) method, where \( n \) is the length of the text and \( m \) is the length of the pattern.
- **Tries (prefix trees)** are useful for storing dynamic sets of strings and allow efficient retrieval of strings sharing a common prefix. They are commonly applied in tasks such as autocomplete systems, spell checking, and IP routing.
- **Regular expressions** offer powerful tools for complex pattern matching and text manipulation, but care must be taken to construct efficient patterns. Poorly designed regular expressions can lead to exponential time complexity, affecting performance.
- When handling strings, it is important to be mindful of **Unicode and character encoding** (e.g., ASCII, UTF-8), particularly when dealing with internationalization or data from external sources to ensure correct string processing.
- For problems like **anagram detection**, character count arrays or hash maps are effective ways to compare character frequencies between two strings. Similarly, for **palindrome checks**, you can use the two-pointer technique or simply compare the string to its reverse for an efficient solution.

### Working with Linked Lists

Linked lists are dynamic data structures consisting of nodes that contain data and references to the next (and possibly previous) nodes.

- **Choosing the appropriate list type** depends on the problem's needs. Singly linked lists are ideal for scenarios where traversal is only in one direction, minimizing memory usage. On the other hand, doubly linked lists are better suited for cases where traversal in both directions is required or where efficient insertions and deletions from both ends are needed.
- **Insertions and deletions in linked lists** are highly efficient at known positions, particularly at the head or tail, with operations typically taking \( O(1) \) time. When deleting nodes, it is crucial to maintain a reference to the previous node to update pointers properly and avoid breaking the list.
- **Reversing a singly linked list** can be achieved by iterating through the list and adjusting the `next` pointers of each node to point to the previous one. This process can be completed in \( O(n) \) time with only \( O(1) \) additional space, making it highly efficient.
- **Detecting cycles in a linked list** can be done using Floyd’s Tortoise and Hare algorithm, where a slow pointer and a fast pointer traverse the list at different speeds. If there is a cycle, the fast pointer will eventually meet the slow pointer.
- It's important to handle **edge cases** in linked lists, such as dealing with empty lists, single-node lists, or lists with cycles. Always check for null pointers to prevent runtime exceptions or crashes, especially in languages that don't automatically handle such errors.
- In environments where **memory management** is manual, it's essential to explicitly deallocate memory for nodes once they are no longer in use. This prevents memory leaks and ensures that your program runs efficiently without unnecessary memory consumption.

### Working with Trees and Binary Trees

Trees are hierarchical data structures with a root node and child nodes. Binary trees are a specific type where each node has at most two children.

- **Tree traversals** are fundamental for working with binary trees, including in-order, pre-order, and post-order traversals. These can be implemented both recursively and iteratively, with stacks being used for the iterative versions to simulate the recursive call stack.
- **Binary Search Trees (BSTs)** are structured so that the left subtree contains nodes with keys smaller than the parent node, while the right subtree contains nodes with larger keys. This property allows efficient search, insertion, and deletion operations, typically in \( O(\log n) \) time for balanced trees.
- **Balancing trees** like AVL trees and Red-Black trees ensure that tree height remains logarithmic, allowing operations such as search, insert, and delete to remain efficient at \( O(\log n) \) time. These trees achieve balance through rotations after insertions or deletions.
- **Heaps** are specialized tree structures where, in a max-heap, every parent node is greater than or equal to its children. Heaps are most commonly used to implement priority queues, as they allow efficient access to the highest or lowest priority element.
- **Binary heaps**, typically implemented using arrays, are an efficient way to represent heaps in memory. They support operations such as insertions, deletions, and heapify in \( O(\log n) \) time, while **Heap Sort**, which uses binary heaps, is an in-place sorting algorithm with a time complexity of \( O(n \log n) \).
- When solving **common tree problems**, be comfortable with tasks such as finding the lowest common ancestor of two nodes, calculating the depth or height of a tree, and performing level-order traversals using breadth-first search (BFS) methods.

### Working with Graphs

Graphs consist of vertices (nodes) and edges connecting them, used to represent complex relationships.

I. **Graph Representations**:

- An **adjacency list** is a structure where each element corresponds to a node and contains a list of adjacent nodes. It is particularly efficient for representing sparse graphs, where not all nodes are connected to many others.
- An **adjacency matrix** is a 2D array in which the entry \( (i, j) \) indicates whether there is an edge (and possibly the weight of that edge) between nodes \( i \) and \( j \). This method is more suitable for dense graphs where many nodes are interconnected.

II. **Graph Traversal Algorithms**:

- **Depth-First Search (DFS)** explores a graph by going as deep as possible along each branch before backtracking. It can be implemented using recursion, which implicitly uses a stack, or by explicitly maintaining a stack.
- **Breadth-First Search (BFS)** explores all neighbors of a node at the current depth level before moving on to the next level of nodes. This algorithm uses a queue to keep track of nodes that need to be visited.

III. **Cycle Detection**:

- In **directed graphs**, cycle detection can be done using DFS while tracking the recursion stack to identify back edges, which indicate the presence of a cycle.
- For **undirected graphs**, cycle detection can be performed using either DFS or BFS. A cycle is detected if a visited node is encountered again, excluding its immediate parent.

IV. **Shortest Path Algorithms**:

- **Dijkstra's Algorithm** finds the shortest path from a source node to all other nodes in a graph with non-negative edge weights. It uses a priority queue (min-heap) to efficiently select the node with the smallest tentative distance.
- **Bellman-Ford Algorithm** can handle graphs with negative edge weights and detects negative weight cycles. It works by repeatedly relaxing all edges in the graph.
- **Floyd-Warshall Algorithm** computes shortest paths between all pairs of nodes. It is suitable for dense graphs but has a higher time complexity of \( O(n^3) \), making it less efficient for sparse graphs.

V. **Minimum Spanning Trees (MST)**:

- **Prim's Algorithm** builds a minimum spanning tree by starting with an arbitrary node and adding the smallest edge that connects the current tree to a node outside of it. A priority queue is used to efficiently manage edge selection.
- **Kruskal's Algorithm** constructs the minimum spanning tree by sorting all edges and adding them in order of increasing weight, while using a Union-Find data structure to avoid forming cycles.

VI. **Network Flow Algorithms**:

- The **Ford-Fulkerson Method** calculates the maximum flow in a flow network by finding augmenting paths. It is useful for networks with capacities and adjusts flows iteratively.
- The **Edmonds-Karp Algorithm** is a specific implementation of the Ford-Fulkerson method that uses BFS to find the shortest augmenting paths, improving its efficiency for certain types of networks.

VII. **Other Important Concepts**:

- **Topological sorting** is applied to directed acyclic graphs (DAGs) and produces a linear ordering of vertices such that for every directed edge \( uv \), vertex \( u \) appears before \( v \) in the ordering.
- **Strongly Connected Components (SCCs)** can be identified in directed graphs using algorithms such as Kosaraju's or Tarjan's, which efficiently decompose the graph into its SCCs.
- **Graph coloring and bipartite graphs** involve assigning colors to nodes such that no two adjacent nodes share the same color. BFS or DFS can be used to check if a graph is bipartite (i.e., 2-colorable), while backtracking or greedy methods may be used for more general graph coloring problems.

### Working with Hash Tables

Hash tables store key-value pairs for efficient lookup, insertion, and deletion.

- **Choosing a Good Hash Function**: The hash function should distribute keys uniformly to minimize collisions. For custom objects, override hash functions carefully to maintain consistency.

- **Handling Collisions**:

  - **Chaining**: Store colliding elements in a linked list at each index.
  
  - **Open Addressing**: Find another slot using probing methods (linear, quadratic, or double hashing).

- **Load Factor and Resizing**: Monitor the load factor (number of elements divided by the number of buckets). Resize and rehash when the load factor exceeds a threshold to maintain performance.

- **Immutable Keys**: Use immutable objects as keys to prevent issues with key mutation after insertion.

- **Applications**: Use hash tables for frequency counts, caching, indexing, and implementing associative arrays.

- **Time Complexity**: While hash tables have \( O(1) \) average-case time complexity, be aware that the worst-case can degrade to \( O(n) \) if many collisions occur.

## Algorithms

Mastering algorithms is crucial for solving complex programming problems efficiently.

### Two-Pointer Technique

- **When to Use**: Use when dealing with sorted arrays or when you need to find pairs or triplets that satisfy a condition.

- **Implementation Tips**:

  - **Initialization**: Set two pointers at appropriate positions (e.g., start and end of the array).
  
  - **Movement Logic**: Move pointers based on the comparison of their sum/product with the target value.
  
  - **Avoiding Duplicates**: Skip over duplicate elements if necessary to avoid redundant results.

- **Example**: Finding all pairs in a sorted array that sum to a specific value.

### Recursion

- **Principles**:

  - **Base Case**: Define a clear base case to terminate recursion.
  
  - **Recursive Case**: Ensure each recursive call progresses toward the base case.
  
  - **Correctness**: Ensure the logic correctly represents the problem's structure.

- **Considerations**:

  - **Stack Overflow**: Be cautious of maximum recursion depth limits. For deep recursion, consider converting to an iterative solution or using tail recursion optimization if supported.
  
  - **Memoization**: Cache results of recursive calls to avoid redundant computations in problems with overlapping subproblems.

### Backtracking

- **When to Use**: Suitable for problems requiring exploration of all possible configurations (e.g., puzzles like Sudoku, N-Queens, combinatorial problems).

- **Implementation Tips**:

  - **State Representation**: Clearly define how to represent the current state.
  
  - **Constraints Checking**: Before proceeding, check if the current state satisfies the problem's constraints to prune invalid paths early.
  
  - **Recursive Exploration**: Recursively explore each valid option, modifying the state accordingly.
  
  - **Backtracking**: After exploring a path, undo the last change (backtrack) before trying the next option.
  
  - **Optimization**: Use heuristics to prioritize promising paths.

- **Example**: Solving the N-Queens problem by placing queens row by row and backtracking when a conflict is detected.

### Dynamic Programming

- **Principles**: Used for optimization problems where the problem can be broken down into overlapping subproblems with optimal substructure.

- **Approaches**:

  - **Top-Down (Memoization)**: Use recursion with caching to store results of subproblems.
  
  - **Bottom-Up (Tabulation)**: Build a table iteratively from the smallest subproblems up to the original problem.

- **Key Steps**:

  - **Define Subproblems**: Break the problem into smaller, manageable parts.
  
  - **Identify State Variables**: Determine what parameters uniquely define each subproblem.
  
  - **Recurrence Relation**: Establish how to compute the solution of a subproblem using solutions to smaller subproblems.
  
  - **Initialization**: Set up base cases for the DP table or memoization cache.
  
  - **Iteration Order**: For bottom-up approaches, determine the order to fill the DP table.

- **Space Optimization**: Reduce space complexity by noticing that only a limited portion of the DP table is needed at any time.

- **Example**: The classic Fibonacci sequence, Knapsack problem, or finding the minimum edit distance between two strings.

### Greedy Algorithms

- **When to Use**: Suitable when making the locally optimal choice at each step leads to a global optimum.

- **Characteristics**:

  - **Optimal Substructure**: The optimal solution contains optimal solutions to subproblems.
  
  - **Greedy Choice Property**: A globally optimal solution can be arrived at by making locally optimal choices.

- **Implementation Tips**:

  - **Sorting**: Often necessary to sort the data based on some criterion before applying the greedy approach.
  
  - **Proof of Correctness**: Not all problems can be solved greedily. Ensure the greedy choice leads to an optimal solution by providing a proof or counterexamples.

- **Examples**: Activity selection problem, Huffman coding, Prim's and Kruskal's algorithms for MST.

### Divide and Conquer

- **Principles**: Divide the problem into smaller subproblems, solve them independently, and combine their solutions.

- **Implementation Tips**:

  - **Recursion**: Often implemented recursively, where each recursive call handles a subproblem.
  
  - **Combine Step**: Pay special attention to how subproblem solutions are combined.
  
  - **Base Cases**: Define base cases where the problem is small enough to be solved directly.

- **Examples**: Merge Sort, Quick Sort, Binary Search.

### Graph Algorithms

Below is a detailed comparison of commonly used graph algorithms:

| **Algorithm/Technique**        | **Uses**                                                   | **Implementation**                                                                               |
|---------------------------------|-------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **Breadth-First Search (BFS)**  | Finding the shortest path in unweighted graphs, level-order traversal. | Use a queue to process nodes in a First In, First Out (FIFO) manner.                              |
| **Depth-First Search (DFS)**    | Topological sorting, cycle detection, pathfinding.          | Use recursion or a stack to explore as deep as possible before backtracking.                      |
| **Dijkstra's Algorithm**        | Shortest path in weighted graphs with non-negative weights. | Use a min-heap (priority queue) to select the next node with the smallest tentative distance.      |
| **Bellman-Ford Algorithm**      | Shortest path in graphs with negative weights, detecting negative cycles. | Relax all edges V-1 times, where V is the number of vertices.                                     |
| **Floyd-Warshall Algorithm**    | All pairs shortest paths.                                   | Use a 2D matrix to store distances, updating distances by considering each vertex as an intermediate point. |
| **Union-Find Data Structure**   | Keeping track of disjoint sets, cycle detection in Kruskal's algorithm. | Optimize with path compression and union by rank for efficient merging of sets and lookups.        |

## Sorting Algorithms

Sorting algorithms are fundamental to computer science and programming. They are used to rearrange elements in a list or array so that they follow a specific order (ascending or descending). Efficient sorting is crucial for optimizing other algorithms (like search and merge algorithms) that require input data to be in sorted lists. Understanding the different sorting algorithms, their time and space complexities, stability, and suitable use cases is essential for problem-solving and technical interviews.

### Overview of Common Sorting Algorithms

Below is a detailed comparison of commonly used sorting algorithms:

| **Algorithm**       | **Average Time Complexity** | **Worst-Case Time Complexity** | **Space Complexity** | **Stability** | **Best Use Case**                            | **Notes**                                   |
|---------------------|-----------------------------|-------------------------------|----------------------|---------------|----------------------------------------------|---------------------------------------------|
| **Bubble Sort**     | \( O(n^2) \)                | \( O(n^2) \)                  | \( O(1) \)           | Stable        | Educational purposes, small datasets         | Simple but inefficient for large datasets   |
| **Insertion Sort**  | \( O(n^2) \)                | \( O(n^2) \)                  | \( O(1) \)           | Stable        | Nearly sorted or small datasets              | Efficient for small or nearly sorted datasets |
| **Selection Sort**  | \( O(n^2) \)                | \( O(n^2) \)                  | \( O(1) \)           | Unstable      | Small datasets, when memory is limited       | Inefficient for large datasets             |
| **Merge Sort**      | \( O(n \log n) \)           | \( O(n \log n) \)             | \( O(n) \)           | Stable        | Large datasets, linked lists                 | Requires additional memory for merging     |
| **Quick Sort**      | \( O(n \log n) \)           | \( O(n^2) \)                  | \( O(\log n) \)      | Unstable      | Large datasets, general-purpose sorting      | Pivot selection strategy affects performance |
| **Heap Sort**       | \( O(n \log n) \)           | \( O(n \log n) \)             | \( O(1) \)           | Unstable      | Large datasets, in-place sorting             | Efficient with minimal memory usage        |
| **Radix Sort**      | \( O(nk) \)                 | \( O(nk) \)                   | \( O(n + k) \)       | Stable        | Large datasets with integer keys             | Non-comparative sorting algorithm          |
| **Counting Sort**   | \( O(n + k) \)              | \( O(n + k) \)                | \( O(k) \)           | Stable        | Small range of integer keys                  | Efficient when range \( k \) is small      |
| **Tim Sort**        | \( O(n \log n) \)           | \( O(n \log n) \)             | \( O(n) \)           | Stable        | Real-world data, hybrid sorting              | Default sorting algorithm in Python        |
| **Bucket Sort**     | \( O(n + k) \)              | \( O(n^2) \)                  | \( O(n) \)           | Stable        | Uniformly distributed data                   | Divides elements into buckets              |
| **Shell Sort**      | \( O(n \log n) \) to \( O(n^2) \) | \( O(n^2) \)            | \( O(1) \)           | Unstable      | Medium-sized datasets                        | Improves upon Insertion Sort               |

### General Tips for Sorting Algorithms

- **Understand the Data**: Choose the sorting algorithm based on the nature of the data (size, distribution, data type).
- **Stability Requirement**: If the relative order of equal elements needs to be preserved, choose a stable sorting algorithm.
- **In-Place Requirement**: If additional memory usage is a concern, prefer in-place sorting algorithms like Quick Sort or Heap Sort.
- **Time Complexity Trade-offs**: Be aware of the worst-case scenarios; for instance, Quick Sort can degrade to \( O(n^2) \) if not implemented carefully.
- **Hybrid Approaches**: Consider hybrid algorithms like Tim Sort, which combine the strengths of multiple algorithms.

### Practical Applications

- **Merge Sort**: Preferred for sorting linked lists because it doesn't require random access to data.
- **Quick Sort**: Often the go-to for general-purpose sorting due to its average-case efficiency and in-place sorting.
- **Counting and Radix Sort**: Useful when sorting integers within a known, small range.
- **Heap Sort**: Suitable when memory space is limited and a guaranteed \( O(n \log n) \) time is required.
- **Insertion Sort**: Ideal for small datasets or as a subroutine in more complex algorithms.

## Bit Manipulation

Bit manipulation involves algorithms that operate directly on bits, the basic units of data in computing. By leveraging bit-level operations, you can achieve performance optimizations, reduce memory usage, and solve certain problems more elegantly. Bit manipulation is particularly useful in systems programming, cryptography, graphics, and competitive programming.

### Fundamental Concepts

- **Binary Representation**: Understanding how numbers are represented in binary is fundamental. Each digit (bit) represents an increasing power of 2, starting from the least significant bit (LSB) on the right.

- **Signed vs. Unsigned Integers**:
  - *Unsigned Integers*: Represent only non-negative numbers (0 and positive integers).
  - *Signed Integers*: Use the most significant bit (MSB) as the sign bit (0 for positive, 1 for negative) in systems using two's complement representation.

- **Bitwise Operators**:
  - **AND (`&`)**: Yields 1 if both bits are 1; otherwise, 0.
  - **OR (`|`)**: Yields 1 if at least one bit is 1; otherwise, 0.
  - **XOR (`^`)**: Yields 1 if bits are different; otherwise, 0.
  - **NOT (`~`)**: Flips all bits (bitwise negation).
  - **Left Shift (`<<`)**: Shifts bits to the left, filling with zeros from the right.
  - **Right Shift (`>>`)**:
    - *Logical Shift*: Shifts bits to the right, filling with zeros from the left (used with unsigned integers).
    - *Arithmetic Shift*: Preserves the sign bit when shifting (used with signed integers).

### Bit Manipulation Techniques

1. **Setting a Bit**:
   - *Objective*: Set a bit at position \( n \) to 1.
   - *Operation*: `number |= (1 << n);`
   - *Explanation*: Left-shift 1 by \( n \) positions to create a mask where only the \( n \)-th bit is 1, then use bitwise OR to set that bit in `number`.

2. **Clearing a Bit**:
   - *Objective*: Set a bit at position \( n \) to 0.
   - *Operation*: `number &= ~(1 << n);`
   - *Explanation*: Left-shift 1 by \( n \) positions and negate it to create a mask where all bits are 1 except the \( n \)-th bit, then use bitwise AND to clear that bit in `number`.

3. **Toggling a Bit**:
   - *Objective*: Flip the bit at position \( n \).
   - *Operation*: `number ^= (1 << n);`
   - *Explanation*: Left-shift 1 by \( n \) positions and use bitwise XOR to toggle the \( n \)-th bit.

4. **Checking a Bit**:
   - *Objective*: Determine if the bit at position \( n \) is 1.
   - *Operation*: `(number & (1 << n)) != 0`
   - *Explanation*: Left-shift 1 by \( n \) positions and use bitwise AND; if the result is non-zero, the bit is set.

5. **Clearing the Least Significant Bit (LSB)**:
   - *Operation*: `number &= (number - 1);`
   - *Explanation*: Subtracting 1 flips all bits from the LSB up to the first set bit; ANDing this with the original number clears the LSB.

6. **Isolating the Least Significant Bit**:
   - *Operation*: `isolated_bit = number & (-number);`
   - *Explanation*: In two's complement, `-number` is the bitwise complement plus one; ANDing it with `number` isolates the lowest set bit.

7. **Counting Set Bits (Hamming Weight)**:
   - *Method*: Use Kernighan's Algorithm.
   - *Operation*:
     ```c
     int count = 0;
     while (number) {
         number &= (number - 1);
         count++;
     }
     ```
   - *Explanation*: Repeatedly clear the LSB and increment the count until `number` becomes zero.

8. **Checking if a Number is a Power of Two**:
   - *Operation*: `(number != 0) && ((number & (number - 1)) == 0)`
   - *Explanation*: Powers of two have only one set bit; subtracting 1 flips all bits after the set bit, so ANDing with the original gives zero.

9. **Swapping Variables Without a Temporary Variable**:
   - *Operations*:
     ```c
     a ^= b;
     b ^= a;
     a ^= b;
     ```
   - *Explanation*: Uses XOR to swap values without extra space; ensure `a` and `b` are not the same memory location.

10. **Reversing Bits**:
    - *Operation*: Reverse the order of bits in a number.
    - *Method*: Use bitwise operations and shifting to swap bits from opposite ends moving towards the center.

### Bit Masks

- **Definition**: A bitmask is a binary pattern used to select or manipulate specific bits within a byte or word.

- **Common Uses**:
  - **Feature Flags**: Use bits to represent boolean options or settings.
  - **Permission Sets**: Represent permissions (read, write, execute) in file systems.
  - **State Representation**: Efficiently store multiple boolean states in a single integer.

- **Creating a Mask**:
  - *Example*: To create a mask for bits 0 and 3: `mask = (1 << 0) | (1 << 3);`

### Bit Shifting Tricks

- **Multiplication and Division by Powers of Two**:
  - *Left Shift (`<<`)*: Multiplies an integer by \( 2^n \).
    - *Example*: `number << 3` multiplies `number` by 8.
  - *Right Shift (`>>`)*: Divides an integer by \( 2^n \) (for unsigned integers or logical shift).
    - *Example*: `number >> 2` divides `number` by 4.

- **Extracting Specific Bits**:
  - *Objective*: Extract bits from position \( p \) to \( p + n - 1 \).
  - *Operation*: `(number >> p) & ((1 << n) - 1);`
  - *Explanation*: Shift the desired bits to the right and mask out the higher bits.

### Practical Applications

- **Optimization**: Bit manipulation can optimize algorithms by reducing time complexity or memory usage, especially in low-level programming or performance-critical code.

- **Cryptography**: Algorithms like AES and SHA use extensive bit manipulation.

- **Graphics Programming**: Manipulating pixels and colors often involves bitwise operations.

- **Networking**: Protocols use bit fields to pack data efficiently.

- **Competitive Programming**: Problems involving subsets, combinations, and permutations can often be solved efficiently using bits to represent sets.

### Cautions and Best Practices

- **Operator Precedence**: Bitwise operators have lower precedence than arithmetic and relational operators. Use parentheses to ensure the correct order of operations.

- **Signed vs. Unsigned Shifts**:
  - *Arithmetic Shift (`>>`)*: Preserves the sign bit in signed integers.
  - *Logical Shift (`>>>` in some languages like Java)*: Shifts zeros into the high-order bits.

- **Portability**: Bit manipulation code can be non-portable due to differences in integer sizes and endianness across systems.

- **Overflow and Underflow**: Be cautious with shifts that might cause bits to be shifted beyond the size of the data type.

- **Readability**: Excessive bit manipulation can make code hard to read and maintain. Include comments and consider using macros or inline functions.


## List of problems

### Minimum deletions to make valid parentheses

Given a string of parentheses, determine the minimum number of parentheses that need to be removed to make the string valid. This can be solved using a stack data structure to track the open parentheses as we iterate through the string. If we encounter an open parenthesis, we add it to the stack. If we encounter a closing parenthesis, we check if there is a matching open parenthesis on the top of the stack. If there is, we pop the open parenthesis from the stack. If there is not, we add the closing parenthesis to a list of characters to remove. After we have processed the entire string, we remove the remaining open parentheses from the stack.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/deletions_to_make_valid_parentheses)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/deletions_to_make_valid_parentheses)

### Is palindrome after at most one char delete?

Determinine whether a string can be transformed into a palindrome by deleting at most one character. This can be solved using a two pointer approach, where we start from both ends of the string and move towards the middle. If we encounter a pair of characters that are not equal, we have three options: delete the character at the left pointer, delete the character at the right pointer, or delete both characters. We check if any of these options results in a palindrome and return the result.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/is_palindrome_after_char_deletion)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/is_palindrome_after_char_deletion)

### K closest points to origin 	

Find the K points in a list of points that are closest to the origin (0, 0). This can be solved using a min heap data structure, where we store the K closest points so far. As we iterate through the list of points, we compute the distance from each point to the origin and add it to the heap if it is among the K closest points so far.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/k_closest_points)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/k_closest_points)

### Subarray sum equals K 	

Find a contiguous subarray of an array that has a sum of K. This can be solved using a sliding window approach, where we maintain a running sum of the elements in the window and move the window through the array until we find a subarray with the desired sum.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/subarray_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/subarray_sum)

### Add numbers given as strings 	

Add two numbers represented as strings. This can be solved by treating the strings as arrays of digits and using a carry variable to keep track of the carryover from one place value to the next.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/add_string_numbers)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/add_string_numbers)

### Dot product of two sparse vectors 	

Compute the dot product of two sparse vectors, where a vector is represented as a list of (index, value) pairs. This can be solved by iterating through both vectors and adding up the products of the values at the same index.
 
 
* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/sparse_vectors_product)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/sparse_vectors_product)

### Range sum of BST 	

Compute the sum of the values of all the nodes in a binary search tree within a given range. This can be solved using a recursive in-order traversal of the tree, where we add the value of each node to the sum if it is within the range.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/range_sum_of_bst)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/range_sum_of_bst)

### Product of array except self 	

Compute an array where each element is the product of all the other elements in the input array. This can be solved using two pass approach, where we first compute the product of all the elements before each index and then compute the product of all the elements after each index.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/array_product)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/array_product)

### Convert BST to sorted doubly linked list 

Convert a binary search tree to a sorted doubly linked list. This can be solved using a recursive in-order traversal of the tree, where we build the linked list by adding each node to the end of the list as we visit it.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/bst_to_list)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/bst_to_list)

### Lowest common ancestor of a binary tree

Find the lowest common ancestor (LCA) of two nodes in a binary tree. The LCA is the node in the tree that is the ancestor of both nodes and is the deepest node in the tree. To solve this problem, you can use a variety of techniques such as traversing the tree in a depth-first or breadth-first manner, or using a recursive approach to traverse the tree and find the LCA. You can also use a divide and conquer approach, where you split the tree into left and right subtrees and find the LCA in each subtree. Another approach is to use a hash table or a map to store the ancestors of each node and then use this information to find the LCA.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lowest_common_ancestor)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lowest_common_ancestor)

### LRU Cache 	

Designing a cache data structure that stores a limited number of items and removes the least recently used items when the capacity is reached. This can be solved using a doubly linked list and a hash table. The doubly linked list is used to store the items in the cache in the order in which they were accessed, with the most recently accessed item at the front of the list and the least recently accessed item at the back. The hash table is used to store the keys and values of the items in the cache and to quickly retrieve items from the cache based on their keys.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lru_cache)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lru_cache)

### Randomize An Array 	

Shuffle the elements of an array randomly. This can be solved using a random number generator and a Fisher-Yates shuffle algorithm. The Fisher-Yates shuffle algorithm works by starting at the end of the array and randomly swapping each element with an element preceding it. This results in a randomly shuffled array.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/randomize_array)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/randomize_array)

### Binary Tree Right Side View

Given a binary tree, return an array containing the values of the nodes on the right side of the tree, when viewed from the right. One way to solve this problem might be to perform a breadth-first search on the tree, keeping track of the maximum depth of each node as it is visited. When visiting a node at a particular depth for the first time, add its value to the result array.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/binary_tree_right_side_view)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/binary_tree_right_side_view)

### Design Browser History

Implement a browser history system that supports the following operations: visit a URL, go back to the previous URL, and go forward to the next URL. One potential approach to this problem could involve using a doubly-linked list to store the URLs visited, with a pointer to the current URL. Going back or forward would simply involve moving the pointer to the previous or next URL in the list.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/design_browser_history)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/design_browser_history)

### Score After Flipping Matrix

Given a matrix of 0s and 1s, flip the rows and columns of the matrix such that the maximum possible score is achieved. The score is calculated as the number of 1s in the matrix. One way to solve this problem might be to use dynamic programming to compute the maximum score for each submatrix of the original matrix, taking into account whether the rows and columns of the submatrix should be flipped.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/score_after_flipping_matrix)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/score_after_flipping_matrix)
