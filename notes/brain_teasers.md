## Solving Programming Brain Teasers

Programming puzzles serve as an entertaining and challenging way to test and sharpen your coding abilities and problem-solving skills. These types of problems are frequently utilized in technical interviews to gauge a candidate's logical thinking and ability to devise efficient solutions. To maximize your chances of success in these scenarios, it's crucial to master strategies for approaching and solving these problems.

## General Strategies

When addressing programming puzzles, consider the following strategies:

* **Start with a Simple Solution**: If a problem appears overwhelming, initiate with a simple, potentially less efficient solution. This initial step helps in comprehending the problem's intricacies and lays a foundation for more sophisticated, efficient solutions.

* **Implement Unit Tests**: Unit tests are crucial to verifying the correctness of your solution. They can aid in identifying bugs or issues that might otherwise go unnoticed, and they allow you to systematically test the different aspects of your code.

* **Consider Time Complexity**: The efficiency of your solution often plays a pivotal role in competitive programming or during interviews. Aim for solutions with a time complexity of O(n) or better, where n is the size of the input.

* **Leverage Hash Tables**: Hash tables, also known as dictionaries or maps, can speed up data lookup significantly. They offer constant time complexity O(1) for search, insertion, and deletion operations, making them highly effective for certain types of problems.

* **Employ Memoization or Tabulation**: To optimize your solution, contemplate what information can be stored for later use. This technique, known as memoization in the context of recursive algorithms or tabulation for iterative ones, allows you to store and re-use computed results, effectively trading space for time.

* **Use Appropriate Data Structures**: To make your solution faster, think about what information you can save to use later. You can use another type of data structure to make it faster.

## Data structures

### Working with Arrays

Arrays are fundamental data structures that store elements in a contiguous block of memory, allowing for efficient access and modification. Here are some useful tips when working with arrays:

1. **Sorting the Array**: Sorting the array first can simplify many problems, as a sorted array provides a clear order and structure that can be exploited. Common sorting algorithms like merge sort or quick sort generally have a time complexity of O(n log n).

2. **Using Binary Search**: For problems involving searching in sorted arrays, consider using binary search. This algorithm effectively halves the search space at each step, thus operating in O(log n) time, considerably improving efficiency for large inputs.

3. **Two-Pointer Technique**: This technique is useful in problems where you need to find pairs of elements that satisfy certain conditions, particularly in sorted arrays. By using two pointers, one at the start and the other at the end of the array, and moving them towards each other, you can reduce the time complexity to O(n).

4. **Being Mindful of Space Complexity**: While arrays provide efficient access to their elements, large arrays can consume significant memory. Ensure that your algorithm is both time and space efficient.

5. **Leveraging Pointers**: Use pointers instead of conventional looping constructs for faster and more memory-efficient operations. This approach is particularly useful for removing duplicates from an array or finding elements that satisfy a certain condition.

6. **Linked Lists for Frequent Insertions/Deletions**: If your use case involves frequent insertions or deletions, an array may not be the best data structure due to the cost of shifting elements. In such scenarios, consider using a linked list instead.

7. **Careful Operation Ordering**: Be cautious about the sequence of your operations. Thoughtful planning can minimize unnecessary shifting of array elements, especially when performing multiple insertions or deletions.

8. **Divide-and-Conquer for Maximum/Minimum Elements**: Use divide-and-conquer techniques to find the maximum or minimum element in an array in O(n) time. This approach involves dividing the problem into smaller subproblems and combining the results from these subproblems to solve the original one.

9. **Hashing for Quick Lookups**: If you need to frequently check for the presence of an element, consider using a hash set for O(1) lookups. This will however increase your space complexity.

10. **Prefix Sums for Multiple Range Queries**: If the problem involves multiple range sum queries, consider calculating prefix sums for the array. This approach allows you to answer any range sum query in O(1) time after an initial O(n) preprocessing step.

### Working with Strings

Strings, being sequences of characters, have a unique set of operations and considerations. Here are some tips and techniques for working with strings:

1. **Using Tries for Efficient String Operations**: A Trie, also known as a prefix tree, is a tree-like data structure that proves effective for storing and searching strings, particularly in applications like Auto-Complete where prefix matching is needed. Tries allow for efficient retrieval of strings with a common prefix.

2. **Immutability of Strings**: In Python, strings are immutable. This means once a string is created, it cannot be changed. Any operation that appears to modify a string will instead create a new one. This should be considered during string manipulation as creating new strings frequently can lead to increased memory usage.

3. **Building Strings Dynamically**: When you need to construct a string with dynamic content, use the str.format() method. It provides a way to substitute placeholders with values, creating complex formatted strings easily.

4. **Efficient String Concatenation**: Use the str.join() method for efficient string concatenation in Python. This approach is faster and uses less memory than repeated use of the '+' operator.

5. **Splitting Strings**: The str.split() method can be used to break a string into substrings based on a delimiter. This is particularly useful when parsing input or handling structured text data.

6. **Using Regular Expressions**: The re module in Python provides powerful capabilities for pattern matching and string manipulation using regular expressions. Regular expressions allow for sophisticated matching and extraction of information from strings.

7. **Handling Unicode Characters**: Python supports Unicode characters, allowing for internationalization and localization of your applications. Unicode characters can be used directly in strings, or they can be inserted using escape sequences.

8. **Manipulating Unicode Data**: The unicodedata module in Python provides tools for manipulating Unicode data. It provides a range of functions to inspect the properties of Unicode characters and to manipulate strings containing Unicode data.

9. **Conversion Between Strings and Bytes**: The str.encode() method can be used to convert a string into bytes, and the bytes.decode() method can be used to convert bytes back into a string. This is particularly useful when dealing with I/O operations, network communication, or any scenario where raw binary data is used.

10. **Reversing Strings and Palindrome Checks**: Use slicing to reverse a string in Python (`str[::-1]`). This technique is helpful when you need to check if a string is a palindrome (a string that reads the same forward and backward).

11. **Case Insensitive Comparisons**: To compare strings in a case-insensitive manner, use the str.lower() or str.upper() methods to ensure all characters are in the same case before comparison.

### Working with Linked Lists

Linked lists, unlike arrays, store elements in individual nodes, each containing a reference to the next node (and often to the previous one as well). Here are some important concepts and strategies for working with linked lists:

1. **Types of Linked Lists**: Linked lists can be either singly-linked (each node has a reference to the next node) or doubly-linked (each node has a reference to both the next and previous nodes). Choose the appropriate type based on the problem requirements.

2. **Dynamic Nature**: Linked lists are dynamic data structures, meaning they can grow and shrink during the execution of the program. This makes them suitable for situations where the size of the data is unknown or may change.

3. **Time Complexity of Operations**: Linked lists offer constant-time insertions and deletions because you only need to update a few pointers. However, searching for a specific element or accessing an element at a specific position requires traversing the list, which takes linear time.

4. **Tracking Important Nodes and Size**: It's often beneficial to keep track of the head (first node), tail (last node), and the size of the list. These will help in many operations, such as append or prepend, or determining if the list is empty.

5. **Common Operations**: Some common operations performed on linked lists include insertion (at the beginning, end, or a specific position), deletion (first, last, or a specific node), searching for an element, and traversal (iterating through all the nodes).

6. **Handling Edge Cases**: When dealing with operations like inserting or deleting nodes, consider edge cases like inserting at the beginning or end of the list, deleting the last remaining node, or handling operations on an empty list.

7. **Dummy Head Node**: Using a dummy head node can simplify code for insertions at the beginning of the list and other operations. The dummy head node is a sentinel node that doesn't hold any data and serves only as a reference point.

8. **Slow and Fast Pointers**: This is a common technique used to find the middle node of a linked list or to detect cycles. The slow pointer moves one step at a time while the fast pointer moves two steps at a time.

9. **Reversing a Linked List**: Linked lists can be reversed by iteratively updating next pointers of the nodes. Maintain a reference to the previous node and during traversal, change the next pointer of the current node to point to the previous node.

10. **Using a Stack for Recursion**: When the depth of recursive calls is likely to exceed the maximum call stack depth, a stack can be used to simulate the recursive calls. This is also useful when you need to visit the nodes in a non-linear order (e.g., post-order traversal).

11. **Using a Dummy Node for Tracking**: In certain scenarios, it's beneficial to track the previous node in addition to the current one. A dummy node can be used to do this and can significantly simplify the handling of edge cases.

### Working with Binary Trees

Binary trees are hierarchical data structures in which each node has up to two children: the left child and the right child. Here are some key considerations when working with binary trees:

1. **Common Operations**: Regular operations performed on binary trees include searching for a particular value, inserting a new value, and finding predecessors or successors of a certain node. Understanding the properties of the tree (e.g., whether it's a binary search tree) can greatly affect the implementation of these operations.

2. **Tree Traversals**: You can traverse a binary tree in three ways: in-order traversal (left child, root, right child), pre-order traversal (root, left child, right child), and post-order traversal (left child, right child, root). The traversal order depends on the problem requirements and the properties of the tree.

3. **Tree Construction from an Array**: If you need to construct a complete binary tree from an array, consider using a recursive function. The left child and right child of a node at index `i` are located at indices `i * 2 + 1` and `i * 2 + 2`, respectively.

4. **Efficient Binary Trees**: For improved efficiency, use binary search trees (BSTs) or self-balancing BSTs like AVL trees. These trees maintain their balance while performing insertions and deletions, ensuring that operations like search, insert, and delete have a time complexity of O(logn).

### Working with n-ary Trees

n-ary trees, or trees where nodes can have up to n children, come in many forms. Here are some common types and tips for working with them:

1. **Trie Trees**: Trie trees (or just "tries") store words or other sequences in a way that facilitates fast lookup (with O(n) complexity, where n is the length of the sequence). Tries are extremely memory-intensive due to having up to 26 possible child nodes (one for each letter of the alphabet) at each node.

2. **AVL Trees**: AVL trees are a type of self-balancing binary search tree, named after their inventors, Adelson-Velsky and Landis. AVL trees ensure that the balance factor (the difference between the heights of the left and right subtrees) never exceeds 1, maintaining O(logn) time complexity for operations. The tree rebalances itself after insertions or deletions that violate this property.

3. **Red-Black Trees**: Red-black trees are another type of self-balancing binary search tree. They balance themselves by assigning each node a color (red or black) according to specific properties. Red-black trees tend to be faster than AVL trees when dealing with many insertions and deletions, as they require fewer rotations to maintain balance.

4. **Data Structure Choice**: The choice between n-ary trees, hash maps, or other data structures depends on the problem requirements. For storing ordered items, balanced binary search trees (like AVL or red-black trees) are often suitable. For unordered items, hash maps offer constant-time lookup, making them a great choice.

### Working with Graphs

Graphs are versatile data structures with nodes and edges. Key considerations for working with them include:

1. **Graph Representation**: Graphs can be stored using edge lists (list of edges), adjacency matrices (V x V array where V is the number of vertices), or adjacency lists (array or hash table of edges).

2. **Graph Traversal**: Learn how to approach problems using depth-first search (DFS) and breadth-first search (BFS) traversals. DFS is often used in scenarios where you need to explore as far as possible along each branch before backtracking, while BFS is used when you want to visit all the vertices at the current depth before proceeding to vertices at the next depth level.

3. **Graph Cycle Detection**: Cycles can be detected using variations of DFS and BFS. For directed graphs, keep track of "gray" (visited and still in the recursion stack) and "black" (visited and popped out of the recursion stack) nodes to detect back edges.

4. **Topological Sorting**: In directed acyclic graphs (DAGs), use topological sorting when you need to find a linear ordering of vertices that adheres to the directed edges. This is often used in scheduling problems.

5. **Shortest Path Algorithms**: Dijkstra's algorithm is effective for finding the shortest path in a weighted graph with no negative weights, while Bellman-Ford or Floyd-Warshall algorithms handle graphs with negative weights.

6. **Minimum Spanning Tree (MST)**: Prim's and Kruskal's algorithms are popular for finding the MST in a weighted, connected and undirected graph.

7. **Connectivity**: Consider if your graph is connected or disconnected, strongly connected or weakly connected. This can significantly influence your strategy.

8. **Edge Weights**: In graphs with edge weights, the nature of the weights (positive, negative, or zero) can impact the choice of algorithm.

9. **Bipartite Graphs**: Determine whether a graph is bipartite (can be colored with two colors without adjacent vertices sharing the same color) using DFS or BFS.

10. **Network Flow**: Use the Ford-Fulkerson algorithm or its optimization, the Edmonds-Karp algorithm, for problems involving network flow, such as maximum bipartite matching or the max-flow min-cut theorem.

### Working with Hash Tables

Hash tables are powerful data structures that use a hash function to map keys to their associated values. This allows for rapid data retrieval and modification. When working with hash tables, keep the following pointers in mind:

1. **Constant-Time Operations**: One of the main strengths of hash tables is their ability to perform insertions, deletions, and lookups in constant time on average, providing a significant performance boost for these operations.

2. **Underlying Array Storage**: The underlying structure of a hash table is an array. The hash function transforms keys into array indices, effectively mapping each key-value pair to a specific location in the array.

3. **Collision Resolution**: Collisions occur when different keys hash to the same index. There are various methods for handling these, including chaining and open addressing.

4. **Chaining**: This strategy places colliding elements into a linked list at the colliding index. It's a simple method but can lead to slower access times if the list at a single index becomes too long.

5. **Open Addressing**: An alternative to chaining, open addressing finds another open slot in the array for a colliding element. This includes linear probing, which sequentially checks the array for an open slot, and quadratic probing or double hashing, which use more complex methods to find open slots.

6. **Hash Function Design**: The quality of a hash function significantly affects the performance of a hash table. An ideal hash function uniformly distributes keys across the array indices to minimize collisions and balance the data load.

7. **Load Factor**: The load factor is the ratio of stored entries to total available slots in the hash table. As it approaches 1 (or sometimes a set threshold less than 1), it's common to resize the hash table to maintain performance.

8. **Worst-Case Time Complexity**: Although hash tables have average-case constant time complexity for basic operations, they can degrade to linear time complexity in the worst-case scenario, usually when there are too many collisions.

9. **Python Implementations**: Python's built-in `dict` and `set` types use hash tables. The `hash()` function is used to compute the hash value of objects, and you can define the `__hash__` method for custom objects.

10. **Mutable Keys**: Mutable objects can be problematic as keys. If a key object changes after insertion, its hash value will also change, causing difficulties in retrieving the associated value. 

11. **Dynamic Resizing**: Implementing dynamic resizing of the hash table ensures that the load factor stays within an optimal range, balancing memory usage with performance.

12. **Cache Friendliness**: Open addressing is typically more cache-friendly than chaining because it exhibits better locality of reference, making efficient use of the CPU cache.

13. **Applications**: Hash tables have wide-ranging applications, from compiler design (implementing symbol tables) to web application development (storing user sessions). They're also a crucial component of caching systems, where their fast access times facilitate quick data retrieval.

## Algorithms

Algorithms, which are structured sets of instructions to solve problems, are at the heart of computer science and programming. The choice of an algorithm can greatly influence the efficiency and performance of your code. Here are some commonly used strategies and tips to help you use them effectively.

### Two Pointers

The two-pointers technique involves traversing an array or list with two pointers, typically beginning at different locations and moving towards or away from each other. This approach is particularly useful in problems involving sorted arrays or linked lists.

1. **Problem Constraints Identification**: Understanding the problem constraints will guide you in deciding whether the two-pointer approach is suitable. Some problems might require the pointers to move in opposite directions, others in the same direction, and others yet might require more than two pointers.
   
2. **Pointer Movement Conditions**: The conditions for advancing or retreating each pointer should be defined based on the problem requirements. Common conditions often involve comparisons between the elements at the pointer positions or between the pointers themselves.
   
3. **Boundary Handling**: Be cautious of pointer boundaries to prevent out-of-bounds errors. Always ensure that your pointers stay within the valid index range of the array or list.

### Recursion

Recursion tackles problems by breaking them down into smaller instances of the same problem. A recursive function calls itself with different inputs until it reaches a base case that can be solved directly.

1. **Base Case Identification**: Determining the base case(s) is vital as it provides the stopping condition for the recursive calls. The base case typically handles the simplest possible instance of the problem.
   
2. **Recursive Case Definition**: The recursive case should simplify the problem, calling the function itself with inputs that move progressively towards the base case. It uses the solutions of the smaller instances to solve the current instance of the problem.

### Backtracking

Backtracking is an algorithmic technique for solving problems recursively by building up a sequence of choices and undoing (backtracking on) certain choices when they are found to be incorrect.

1. **Base Case(s) Identification**: Similar to recursion, backtracking requires defining a base case, which typically corresponds to a complete and valid solution.
   
2. **Subproblem Decomposition**: In the recursive case, decompose the problem into smaller subproblems. These subproblems are usually partial solutions that need to be expanded.

3. **Solution Storage**: Use appropriate data structures to store the partial solutions, often stacks or queues. In some languages, this could simply be the call stack provided by using recursive function calls.
   
4. **Pruning Strategies**: Applying pruning techniques can significantly improve the efficiency of a backtracking algorithm. Pruning involves recognizing and skipping paths that cannot lead to a valid solution, thus reducing unnecessary exploration.

### Dynamic Programming

Dynamic programming is a powerful algorithmic paradigm that solves complex problems by breaking them down into simpler, overlapping subproblems, and reusing solutions to these subproblems to build up solutions to larger ones. It follows the principle of optimality, which assumes that an optimal solution to a problem can be constructed efficiently from optimal solutions to its subproblems. This approach comes in two flavors: top-down (memoization) and bottom-up (tabulation).

#### Top-down Approach (Memoization)

Memoization, also known as top-down dynamic programming, begins with the original problem and breaks it down into subproblems, caching the results of these subproblems to avoid redundant computation. It aligns more closely with the recursive problem-solving methodology, making it often more intuitive and easier to implement.

Steps for implementing memoization:

1. **Recursive Function**: Define a recursive function to break down the problem into simpler subproblems.
2. **Base Cases**: Identify the base case(s), the simplest instances of the problem that can be solved directly.
3. **Cache Initialization**: Set up a cache (a data structure such as an array or dictionary) to store the results of each subproblem.
4. **Cache Check**: Before attempting to solve a subproblem, check if its solution is already stored in the cache. If it is, return the cached result to avoid re-computation.
5. **Subproblem Solving**: Make recursive calls for unsolved subproblems and cache their results for future reference.

#### Bottom-up Approach (Tabulation)

Tabulation, or bottom-up dynamic programming, solves the problem by starting with the smallest subproblems and gradually solving larger ones, using solutions to previous subproblems. This iterative process eliminates the need for recursion and can, in many cases, improve space efficiency.

Steps for implementing tabulation:

1. **Subproblem Identification**: Identify the smallest subproblems that can be solved directly.
2. **Table Initialization**: Set up a table (an array or 2D matrix, for example) to store the results of each subproblem.
3. **Iterative Solution Building**: Iterate through the table, solving each subproblem in an order that guarantees each problem is solved before those that depend on it.
4. **Solution Construction**: Build up the solution for the original problem by referring to the solutions of its subproblems stored in the table.
5. **Solution Retrieval**: Return the solution to the original problem, which will be stored in a specific location in the table (often the last cell).

### Greedy Algorithms

Greedy algorithms follow a heuristic of making the locally optimal choice at each decision point with the hope that these local optima lead to a global optimum. These algorithms make decisions based on immediate gain and do not reconsider past choices.

Advantages of Greedy Algorithms:

* **Simplicity**: Greedy algorithms are often simpler, easier to understand, and faster to code.
* **Efficiency**: They can provide highly efficient solutions with less computational complexity for certain problems.

Limitations of Greedy Algorithms:

* **Non-Optimal Solutions**: They may not always yield the most optimal global solution, as they do not take into account the broader problem context and do not backtrack to revise past decisions.
* **Problem-Specific**: The greedy approach may not work for all problems, and its applicability is often limited to problems where the greedy choice property and optimal substructure property hold.

### Sorting Algorithms

Sorting algorithms are used to systematically arrange data in a specific order, which is crucial for optimizing search or computational tasks. Understanding the different sorting algorithms, their complexity, and use-cases is fundamental for problem-solving.

#### Insertion Sort

Insertion sort iteratively traverses the list, positioning each element at its correct place in the sorted part of the list. It is efficient for smaller data sets and nearly sorted lists.

* **Time Complexity**: O(n²) for general case but O(n) for nearly sorted or small lists.
* **Stable**: Preserves relative order of equivalent elements.
* **In-place**: Only requires a constant amount of additional memory space.

#### Merge Sort

Merge sort is a 'divide and conquer' algorithm that recursively breaks down the list into two halves, sorts them, and then merges them back together.

* **Time Complexity**: O(n log n) for all cases (best, average, and worst).
* **Stable**: Preserves relative order of equivalent elements.
* **Not In-place**: Requires additional memory proportional to the size of the input.

#### Quick Sort

Quick sort is another 'divide and conquer' algorithm that uses a pivot element to partition the list into two parts and then sorts them independently.

* **Time Complexity**: O(n log n) on average, but O(n²) in the worst-case scenario (rare with good pivot selection).
* **Not Stable**: May not preserve relative order of equivalent elements.
* **In-place**: Typically implemented in-place, using only a small stack.

#### Other Sorting Algorithms

There are various other sorting algorithms, each with its unique properties and use-cases. 

* **Heap Sort**: An in-place sorting algorithm with O(n log n) time complexity, suitable for large data sets where memory is a concern.
* **Radix Sort**: A non-comparative integer sorting algorithm with O(nk) time complexity, suitable for sorting integers with a relatively small range.
* **TimSort**: A hybrid sorting algorithm, derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data. Python's built-in `list.sort()` and `sorted()` functions use TimSort.

#### Choosing a Sorting Algorithm

The choice of a sorting algorithm depends on multiple factors including:

* **Data Size**: Insertion sort for small data sets, quicksort for average-sized ones, and heap sort for large data sets.
* **Data State**: For partially sorted data, insertion sort or TimSort can be a good choice due to their ability to handle nearly sorted data efficiently.
* **Memory Limitations**: In-place sorting algorithms like quicksort or heapsort should be used when memory is a constraint.
* **Stability**: If stability is required, one should opt for algorithms like merge sort or TimSort.

### Bit Manipulation

Bit manipulation is a powerful technique for examining and altering individual bits within a binary numeral, often providing low-level optimization and efficient computation. It's a critical tool in the arsenal of a competitive programmer, providing elegant solutions to seemingly complex problems. 

1. **Binary Representation**: Comprehending the binary representation of integers forms the foundation for bit manipulation. Be conversant with performing basic binary operations such as bit shifting (`<<`, `>>`), bitwise OR (`|`), bitwise AND (`&`), and bitwise XOR (`^`).

2. **Signed vs. Unsigned Integers**: Understanding the difference between signed and unsigned integers is essential. For signed integers, the leftmost bit is used to represent the sign. Hence, it's crucial to know how to perform arithmetic shifts, which preserve the sign bit.

3. **Binary-Decimal Conversion**: Be adept at converting numbers between binary and decimal representations, and performing basic arithmetic operations in both representations.

4. **Operator Precedence**: Bitwise operators typically have lower precedence than other arithmetic and logical operators. Ensuring you're aware of this fact, you may need to use parentheses to clarify the order of operations to avoid unintended results.

5. **Bitwise Negation**: The bitwise negation operator (`~`) flips every bit in a binary number. Understanding its usage can be vital for tasks like flipping all bits or creating masks.

6. **Setting Bits**: Be proficient in setting specific bits within an integer. This is often achieved using the bitwise OR operator (`|`) combined with the left shift operator (`<<`).

7. **Clearing Bits**: Learn the technique to clear (or unset) specific bits within an integer. This can be done using the bitwise AND operator (`&`) in conjunction with the bitwise negation operator (`~`).

8. **Toggling Bits**: Gain proficiency in toggling specific bits within an integer. The bitwise XOR operator (`^`) is typically used for this operation.

9. **Bit Masking**: Bit masking is a technique to extract or modify subsets of bits within an integer. This can be achieved by creating a 'mask' with bits set in the positions of interest, and then using bitwise operators to perform the desired action.

10. **Bit Manipulation Tricks**: Be aware of various bit manipulation hacks and tricks, such as using XOR to swap two variables without a temporary variable, checking if a number is a power of two by checking if the binary representation has only one bit set, or using left shift (`<<`) or right shift (`>>`) to multiply or divide a number by two, respectively. These tricks can help optimize your code for time and space efficiency.

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
