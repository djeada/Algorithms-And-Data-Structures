## Solving Programming Brain Teasers

Programming puzzles serve as an entertaining and challenging way to test and sharpen your coding abilities and problem-solving skills. These types of problems are frequently utilized in technical interviews to gauge a candidate's logical thinking and ability to devise efficient solutions. To maximize your chances of success in these scenarios, it's crucial to master strategies for approaching and solving these problems.

## General Strategies

When addressing programming puzzles, consider the following strategies:

- Starting with a straightforward solution can be beneficial if a problem seems daunting. This approach helps to understand the problem's intricacies and establishes a base for developing more advanced and efficient solutions.
- Implementing unit tests is essential to confirm the correctness of your solution. These tests help in detecting bugs or issues that might be otherwise overlooked and allow for systematic testing of different code aspects.
- Considering time complexity is crucial, especially in competitive programming or interview scenarios. Strive for solutions with a time complexity of $O(n)$ or better, where n represents the input size, to ensure efficiency.
- Utilizing hash tables, also known as dictionaries or maps, can significantly accelerate data lookup. They provide constant time complexity $O(1)$ for search, insertion, and deletion operations, making them highly effective for specific problems.
- Employing memoization or tabulation can optimize your solution by storing information for later use. Memoization is used in recursive algorithms, while tabulation applies to iterative ones, allowing you to store and re-use computed results, thus trading space for time.
- Using appropriate data structures is essential for improving the speed of your solution. Consider what information can be stored and utilized later, potentially employing different types of data structures to enhance performance.

## Data structures

### Working with Arrays

Arrays are fundamental data structures that store elements in a contiguous block of memory, allowing for efficient access and modification. Here are some useful tips when working with arrays:

- Sorting the array first can simplify many problems because a sorted array provides a clear order and structure that can be exploited. Common sorting algorithms like merge sort or quick sort generally have a time complexity of $O(n \log n)$.
- Using binary search is effective for problems involving searching in sorted arrays. This algorithm halves the search space at each step, thus operating in $O(\log n)$ time, which significantly improves efficiency for large inputs.
- The two-pointer technique is useful in problems where you need to find pairs of elements that satisfy certain conditions, especially in sorted arrays. By using two pointers, one at the start and the other at the end of the array, and moving them towards each other, you can reduce the time complexity to $O(n)$.
- Being mindful of space complexity is important since large arrays can consume significant memory. Ensure that your algorithm is both time and space efficient.
- Leveraging pointers can lead to faster and more memory-efficient operations compared to conventional looping constructs. This approach is particularly useful for tasks like removing duplicates from an array or finding elements that meet a certain condition.
- Linked lists are preferable for use cases involving frequent insertions or deletions, as arrays may not be optimal due to the cost of shifting elements. In such scenarios, consider using a linked list instead.
- Careful operation ordering can minimize unnecessary shifting of array elements, especially when performing multiple insertions or deletions. Thoughtful planning of the sequence of operations is crucial.
- Using divide-and-conquer techniques can find the maximum or minimum element in an array in $O(n)$ time. This approach involves dividing the problem into smaller subproblems and combining the results to solve the original problem.
- Hashing can facilitate quick lookups if you frequently need to check for the presence of an element. A hash set allows for $O(1)$ lookups, though it will increase space complexity.
- Prefix sums are beneficial for problems involving multiple range sum queries. Calculating prefix sums for the array allows you to answer any range sum query in $O(1)$ time after an initial $O(n)$ preprocessing step.

### Working with Strings

Strings, being sequences of characters, have a unique set of operations and considerations. Here are some tips and techniques for working with strings:
- Using Tries for efficient string operations is advantageous, particularly for applications like Auto-Complete where prefix matching is needed. Tries, also known as prefix trees, allow for efficient retrieval of strings with a common prefix.
- The immutability of strings in Python means that once a string is created, it cannot be changed. Any operation that seems to modify a string will create a new one instead, leading to increased memory usage if new strings are frequently created.
- Building strings dynamically using the `str.format()` method is beneficial for constructing strings with dynamic content. This method provides a way to substitute placeholders with values, allowing for the creation of complex formatted strings easily.
- Efficient string concatenation can be achieved using the `str.join()` method in Python. This approach is faster and uses less memory compared to the repeated use of the `+` operator.
- Splitting strings using the `str.split()` method allows breaking a string into substrings based on a delimiter. This technique is particularly useful for parsing input or handling structured text data.
- Using regular expressions through the `re` module in Python provides powerful capabilities for pattern matching and string manipulation. Regular expressions enable sophisticated matching and extraction of information from strings.
- Handling Unicode characters is supported by Python, allowing for the internationalization and localization of applications. Unicode characters can be used directly in strings or inserted using escape sequences.
- Manipulating Unicode data is facilitated by the `unicodedata` module in Python. This module offers functions to inspect the properties of Unicode characters and manipulate strings containing Unicode data.
- Conversion between strings and bytes is possible with the `str.encode()` method to convert a string into bytes and the `bytes.decode()` method to convert bytes back into a string. This conversion is particularly useful for I/O operations, network communication, or scenarios involving raw binary data.
- Reversing strings and performing palindrome checks can be done using slicing in Python (`str[::-1]`). This technique is helpful when checking if a string is a palindrome, meaning it reads the same forward and backward.
- Case insensitive comparisons are achieved by using the `str.lower()` or `str.upper()` methods to ensure all characters are in the same case before comparison.

### Working with Linked Lists

Linked lists, unlike arrays, store elements in individual nodes, each containing a reference to the next node (and often to the previous one as well). Here are some important concepts and strategies for working with linked lists:

- Types of linked lists include singly-linked (each node references the next node) and doubly-linked (each node references both the next and previous nodes). Choose the appropriate type based on the problem requirements.
- The dynamic nature of linked lists means they can grow and shrink during program execution. This makes them suitable for situations where the size of the data is unknown or may change.
- The time complexity of operations in linked lists includes constant-time insertions and deletions, as only a few pointers need updating. However, searching for a specific element or accessing an element at a specific position requires traversing the list, which takes linear time, or $O(n)$.
- Tracking important nodes and the size of the list, such as the head (first node), tail (last node), and the list's size, helps in many operations like append, prepend, or determining if the list is empty.
- Common operations on linked lists include insertion (at the beginning, end, or a specific position), deletion (first, last, or a specific node), searching for an element, and traversal (iterating through all the nodes).
- Handling edge cases, such as inserting or deleting nodes, requires considering scenarios like inserting at the beginning or end of the list, deleting the last remaining node, or performing operations on an empty list.
- Using a dummy head node can simplify code for insertions at the beginning of the list and other operations. The dummy head node is a sentinel node that doesn't hold any data and serves only as a reference point.
- Slow and fast pointers are a common technique used to find the middle node of a linked list or to detect cycles. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
- Reversing a linked list can be done by iteratively updating the next pointers of the nodes. Maintain a reference to the previous node and during traversal, change the next pointer of the current node to point to the previous node.
- Using a stack for recursion is useful when the depth of recursive calls might exceed the maximum call stack depth. A stack can simulate the recursive calls and is also useful when visiting nodes in a non-linear order (e.g., post-order traversal).
- Tracking the previous node in addition to the current one can simplify handling edge cases. A dummy node can be used to facilitate this and can significantly ease the implementation of certain operations.

### Working with Binary Trees

Binary trees are hierarchical data structures in which each node has up to two children: the left child and the right child. Here are some key considerations when working with binary trees:

- Common operations performed on binary trees include searching for a particular value, inserting a new value, and finding predecessors or successors of a certain node. Understanding the properties of the tree, such as whether it's a binary search tree, can greatly affect the implementation of these operations.
- Tree traversals can be performed in three ways: in-order traversal (left child, root, right child), pre-order traversal (root, left child, right child), and post-order traversal (left child, right child, root). The traversal order depends on the problem requirements and the properties of the tree.
- Constructing a complete binary tree from an array can be done using a recursive function. In this construction, the left child and right child of a node at index `i` are located at indices `i * 2 + 1` and `i * 2 + 2`, respectively.
- Efficient binary trees, such as binary search trees (BSTs) or self-balancing BSTs like AVL trees, provide improved efficiency. These trees maintain their balance while performing insertions and deletions, ensuring that operations like search, insert, and delete have a time complexity of $O(\log n)$.

### Working with n-ary Trees

n-ary trees, or trees where nodes can have up to n children, come in many forms. Here are some common types and tips for working with them:

- Trie trees, or tries, store words or other sequences to facilitate fast lookup with $O(n)$ complexity, where $n$ is the length of the sequence. Tries are extremely memory-intensive because each node can have up to 26 possible child nodes, one for each letter of the alphabet.
- AVL trees are a type of self-balancing binary search tree, named after their inventors, Adelson-Velsky and Landis. AVL trees ensure that the balance factor (the difference between the heights of the left and right subtrees) never exceeds 1, maintaining $O(\log n)$ time complexity for operations. The tree rebalances itself after insertions or deletions that violate this property.
- Red-black trees are another type of self-balancing binary search tree. They balance themselves by assigning each node a color (red or black) according to specific properties. Red-black trees tend to be faster than AVL trees when dealing with many insertions and deletions, as they require fewer rotations to maintain balance.
- The choice between n-ary trees, hash maps, or other data structures depends on the problem requirements. For storing ordered items, balanced binary search trees like AVL trees (like AVL or red-black trees) are often suitable. For unordered items, hash maps offer constant-time lookup, making them a great choice.

### Working with Graphs

Graphs are versatile data structures with nodes and edges. Key considerations for working with them include:

- Graph representation can be done using edge lists (a list of edges), adjacency matrices (a $V \times V$ array where $V$ is the number of vertices), or adjacency lists (an array or hash table of edges).
- Graph traversal can be approached using depth-first search (DFS) and breadth-first search (BFS) traversals. DFS is often used to explore as far as possible along each branch before backtracking, while BFS is used to visit all vertices at the current depth before proceeding to vertices at the next depth level.
- Graph cycle detection can be performed using variations of DFS and BFS. In directed graphs, cycles can be detected by keeping track of "gray" nodes (visited and still in the recursion stack) and "black" nodes (visited and popped out of the recursion stack) to detect back edges.
- Topological sorting is used in directed acyclic graphs (DAGs) to find a linear ordering of vertices that adheres to the directed edges, which is often applied in scheduling problems.
- Shortest path algorithms include Dijkstra's algorithm for finding the shortest path in a weighted graph with no negative weights, and Bellman-Ford or Floyd-Warshall algorithms for handling graphs with negative weights.
- Minimum spanning tree (MST) can be found using Prim's and Kruskal's algorithms, which are popular for finding the MST in a weighted, connected, and undirected graph.
- Connectivity considerations include whether the graph is connected or disconnected, strongly connected or weakly connected, which can significantly influence the strategy used.
- Edge weights in graphs can impact the choice of algorithm depending on whether the weights are positive, negative, or zero.
- Bipartite graphs can be determined using DFS or BFS to check if the graph can be colored with two colors without adjacent vertices sharing the same color.
- Network flow problems, such as maximum bipartite matching or the max-flow min-cut theorem, can be addressed using the Ford-Fulkerson algorithm or its optimization, the Edmonds-Karp algorithm.

### Working with Hash Tables

Hash tables are powerful data structures that use a hash function to map keys to their associated values. This allows for rapid data retrieval and modification. When working with hash tables, keep the following pointers in mind:

- One of the main strengths of hash tables is their ability to perform insertions, deletions, and lookups in constant time on average, providing a significant performance boost for these operations.
- The underlying structure of a hash table is an array. The hash function transforms keys into array indices, effectively mapping each key-value pair to a specific location in the array.
- Collisions occur when different keys hash to the same index. Various methods for handling these include chaining and open addressing.
- Chaining places colliding elements into a linked list at the colliding index. This method is simple but can lead to slower access times if the list at a single index becomes too long.
- Open addressing, an alternative to chaining, finds another open slot in the array for a colliding element. This includes linear probing, which sequentially checks the array for an open slot, and quadratic probing or double hashing, which use more complex methods to find open slots.
- The quality of a hash function significantly affects the performance of a hash table. An ideal hash function uniformly distributes keys across the array indices to minimize collisions and balance the data load.
- The load factor is the ratio of stored entries to total available slots in the hash table. As it approaches 1, or sometimes a set threshold less than 1, it's common to resize the hash table to maintain performance.
- Although hash tables have average-case constant time complexity for basic operations, they can degrade to linear time complexity in the worst-case scenario, usually when there are too many collisions.
- Python's built-in `dict` and `set` types use hash tables. The `hash()` function is used to compute the hash value of objects, and you can define the `__hash__` method for custom objects.
- Mutable objects can be problematic as keys because if a key object changes after insertion, its hash value will also change, causing difficulties in retrieving the associated value.
- Implementing dynamic resizing of the hash table ensures that the load factor stays within an optimal range, balancing memory usage with performance.
- Open addressing is typically more cache-friendly than chaining because it exhibits better locality of reference, making efficient use of the CPU cache.
- Hash tables have wide-ranging applications, from compiler design (implementing symbol tables) to web application development (storing user sessions). They are also a crucial component of caching systems, where their fast access times facilitate quick data retrieval.

## Algorithms

Algorithms, which are structured sets of instructions to solve problems, are at the heart of computer science and programming. The choice of an algorithm can greatly influence the efficiency and performance of your code. Here are some commonly used strategies and tips to help you use them effectively.

### Two Pointers

The two-pointers technique involves traversing an array or list with two pointers, typically beginning at different locations and moving towards or away from each other. This approach is particularly useful in problems involving sorted arrays or linked lists.

- Understanding the problem constraints is essential in deciding whether the two-pointer approach is suitable. Some problems might require the pointers to move in opposite directions (e.g., one pointer starting at the beginning and the other at the end), others in the same direction (e.g., both starting at the beginning and moving forward), and others yet might require more than two pointers (e.g., three-way partitioning in QuickSort).
- The conditions for advancing or retreating each pointer should be defined based on the problem requirements. Common conditions often involve comparisons between the elements at the pointer positions (e.g., finding pairs that sum up to a target value) or between the pointers themselves (e.g., checking for overlap or meeting points).
- Be cautious of pointer boundaries to prevent out-of-bounds errors. Always ensure that your pointers stay within the valid index range of the array or list, and include boundary checks in your logic to avoid accessing invalid memory locations.

### Recursion

Recursion tackles problems by breaking them down into smaller instances of the same problem. A recursive function calls itself with different inputs until it reaches a base case that can be solved directly.

- Determining the base case(s) is vital as it provides the stopping condition for the recursive calls. The base case typically handles the simplest possible instance of the problem (e.g., factorial of 0 is 1, or an empty list in a sorting algorithm).
- The recursive case should simplify the problem, calling the function itself with inputs that move progressively towards the base case. It uses the solutions of the smaller instances to solve the current instance of the problem. For example, in a recursive factorial function, `factorial(n) = n * factorial(n-1)`.
- Ensure proper handling of the recursive depth to avoid stack overflow errors. This might involve adding checks to limit the depth or using iterative solutions for problems that could lead to deep recursion.

### Backtracking

Backtracking is an algorithmic technique for solving problems recursively by building up a sequence of choices and undoing (backtracking on) certain choices when they are found to be incorrect.

- Similar to recursion, backtracking requires defining a base case, which typically corresponds to a complete and valid solution. For example, in a N-Queens problem, the base case is placing all queens on the board without any conflicts.
- In the recursive case, decompose the problem into smaller subproblems. These subproblems are usually partial solutions that need to be expanded (e.g., placing the next queen on the board in the N-Queens problem).
- Use appropriate data structures to store the partial solutions, often stacks or queues. In some languages, this could simply be the call stack provided by using recursive function calls. Maintaining a clear structure helps manage the state and backtrack correctly when needed.
- Applying pruning techniques can significantly improve the efficiency of a backtracking algorithm. Pruning involves recognizing and skipping paths that cannot lead to a valid solution, thus reducing unnecessary exploration. For example, in the N-Queens problem, pruning would involve skipping any position that would lead to an immediate conflict with already placed queens.

### Dynamic Programming

Dynamic programming is a powerful algorithmic paradigm that solves complex problems by breaking them down into simpler, overlapping subproblems, and reusing solutions to these subproblems to build up solutions to larger ones. It follows the principle of optimality, which assumes that an optimal solution to a problem can be constructed efficiently from optimal solutions to its subproblems. This approach comes in two flavors: top-down (memoization) and bottom-up (tabulation).

#### Top-down Approach (Memoization)

Memoization, also known as top-down dynamic programming, begins with the original problem and breaks it down into subproblems, caching the results of these subproblems to avoid redundant computation. It aligns more closely with the recursive problem-solving methodology, making it often more intuitive and easier to implement.

Steps for implementing memoization:

- Define a recursive function to break down the problem into simpler subproblems.
- Identify the base case(s), the simplest instances of the problem that can be solved directly.
- Set up a cache (a data structure such as an array or dictionary) to store the results of each subproblem.
- Before attempting to solve a subproblem, check if its solution is already stored in the cache. If it is, return the cached result to avoid re-computation.
- Make recursive calls for unsolved subproblems and cache their results for future reference.

#### Bottom-up Approach (Tabulation)

Tabulation, or bottom-up dynamic programming, solves the problem by starting with the smallest subproblems and gradually solving larger ones, using solutions to previous subproblems. This iterative process eliminates the need for recursion and can, in many cases, improve space efficiency.

Steps for implementing tabulation:

- Identify the smallest subproblems that can be solved directly.
- Set up a table (an array or 2D matrix, for example) to store the results of each subproblem.
- Iterate through the table, solving each subproblem in an order that guarantees each problem is solved before those that depend on it.
- Build up the solution for the original problem by referring to the solutions of its subproblems stored in the table.
- Return the solution to the original problem, which will be stored in a specific location in the table (often the last cell).

### Greedy Algorithms

Greedy algorithms follow a heuristic of making the locally optimal choice at each decision point with the hope that these local optima lead to a global optimum. These algorithms make decisions based on immediate gain and do not reconsider past choices.

Steps for implementing greedy algorithms:

- Identify the smallest unit of choice or decision that can be made at each step.
- Establish a selection criterion to choose the best possible option available at each step, ensuring that this local choice contributes to the overall optimal solution.
- Implement a loop or iterative process to make a series of decisions based on the selection criterion, moving towards the final solution.
- Keep track of the decisions made and their cumulative impact on the overall problem, ensuring that each choice remains feasible within the problem constraints.
- Return the final solution after all decisions have been made, ensuring that it represents the optimal outcome for the given problem.

### Sorting Algorithms

Sorting algorithms are used to systematically arrange data in a specific order, which is crucial for optimizing search or computational tasks. Understanding the different sorting algorithms, their complexity, and use-cases is fundamental for problem-solving.

| **Algorithm**       | **Average Time Complexity** | **Space Complexity** | **Stability** | **Best Use Case**                            | **Notes**                                 |
|---------------------|-----------------------------|----------------------|---------------|----------------------------------------------|-------------------------------------------|
| **Bubble Sort**     | $O(n^2)$                    | $O(1)$               | Stable        | Small datasets, educational purposes         | Simple but inefficient for large datasets|
| **Insertion Sort**  | $O(n^2)$                    | $O(1)$               | Stable        | Nearly sorted or small datasets              | Efficient for small or nearly sorted datasets |
| **Selection Sort**  | $O(n^2)$                    | $O(1)$               | Unstable      | Small datasets, when memory is limited       | Inefficient for large datasets           |
| **Merge Sort**      | $O(n \log n)$               | $O(n)$               | Stable        | Large datasets, linked lists                 | Uses additional memory for merge process |
| **Quick Sort**      | $O(n \log n)$               | $O(\log n)$          | Unstable      | Large datasets, in-place sorting             | Partitioning strategy crucial for performance |
| **Heap Sort**       | $O(n \log n)$               | $O(1)$               | Unstable      | Large datasets, in-place sorting             | Efficient with minimal memory usage      |
| **Radix Sort**      | $O(nk)$                     | $O(n+k)$             | Stable        | Large datasets with integer keys             | Non-comparative sorting algorithm        |
| **Counting Sort**   | $O(n+k)$                    | $O(k)$               | Stable        | Small range of integer keys                  | Efficient for small range of values      |
| **Tim Sort**        | $O(n \log n)$               | $O(n)$               | Stable        | Real-world data, hybrid sort of merge and insertion sort | Default sorting algorithm in Python      |

### Bit Manipulation

Bit manipulation is a powerful technique for examining and altering individual bits within a binary numeral, often providing low-level optimization and efficient computation. It's a critical tool in the arsenal of a competitive programmer, providing elegant solutions to seemingly complex problems. 

- Comprehending the binary representation of integers forms the foundation for bit manipulation. Be conversant with performing basic binary operations such as bit shifting (`<<`, `>>`), bitwise OR (`|`), bitwise AND (`&`), and bitwise XOR (`^`).
- Understanding the difference between signed and unsigned integers is essential. For signed integers, the leftmost bit is used to represent the sign. Hence, it's crucial to know how to perform arithmetic shifts, which preserve the sign bit.
- Be adept at converting numbers between binary and decimal representations, and performing basic arithmetic operations in both representations.
- Bitwise operators typically have lower precedence than other arithmetic and logical operators. Ensuring you're aware of this fact, you may need to use parentheses to clarify the order of operations to avoid unintended results.
- The bitwise negation operator (`~`) flips every bit in a binary number. Understanding its usage can be vital for tasks like flipping all bits or creating masks.
- Be proficient in setting specific bits within an integer. This is often achieved using the bitwise OR operator (`|`) combined with the left shift operator (`<<`).
- Learn the technique to clear (or unset) specific bits within an integer. This can be done using the bitwise AND operator (`&`) in conjunction with the bitwise negation operator (`~`).
- Gain proficiency in toggling specific bits within an integer. The bitwise XOR operator (`^`) is typically used for this operation.
- Bit masking is a technique to extract or modify subsets of bits within an integer. This can be achieved by creating a 'mask' with bits set in the positions of interest, and then using bitwise operators to perform the desired action.
- Be aware of various bit manipulation hacks and tricks, such as using XOR to swap two variables without a temporary variable, checking if a number is a power of two by checking if the binary representation has only one bit set, or using left shift (`<<`) or right shift (`>>`) to multiply or divide a number by two, respectively. These tricks can help optimize your code for time and space efficiency.

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
