## Solving Programming Brain Teasers

Programming brain teasers can be an enjoyable and fulfilling way to challenge your coding expertise and problem-solving skills. These problems are frequently used in technical interviews to assess a candidate's critical thinking and ability to develop efficient solutions. To enhance your chances of success in these situations, it's essential to grasp how to tackle and solve these problems.

These notes provide general guidance and techniques for tackling programming brain teasers, as well as targeted suggestions for handling a range of data structures, including arrays, strings, graphs, and trees.

## General Tips

Keep these general principles in mind when solving programming brain teasers:

* If you don't know how to solve a problem, start with a simple solution even if it's not the most efficient. This will help you understand the problem and think about better solutions later.
* Write unit tests. They can be invaluable in confirming that your solution is accurate and in detecting any bugs or issues.
* Be mindful of your solution's time complexity. In competitive programming, time is often crucial, so strive for solutions with a time complexity of O(n) or better.
* Always think about using hash tables (also called dictionaries) to quickly find data. These are data structures that let you find things very fast, which is really good for some types of problems.
* To make your solution faster, think about what information you can save to use later. You can use another type of data structure to make it faster.

## Data structures

### Working with Arrays

Arrays store elements in a continuous block of memory. Tips for working with arrays:

1. Consider sorting first, using O(n log n) algorithms like merge or quick sort.
2. For sorted arrays, use binary search with O(log n) complexity.
3. Employ the two-pointer technique to find pairs meeting specific criteria.
4. Be aware of space complexity, especially with large arrays.
5. Use pointers instead of traditional loops for faster, memory-efficient operations.
6. If frequent insertions/deletions are needed, consider using a linked list.
7. Pay attention to the order of operations to minimize element shifting.
8. Use divide-and-conquer to find maximum or minimum elements in O(n) time.

### Working with Strings

Strings store sequences of characters. Here are some tips:

1. For many strings, use a prefix tree (trie) for efficient storage and searching.
2. In Python, strings are immutable, so create new strings for modifications.
3. Use str.format() to build strings with dynamic content.
4. Concatenate strings efficiently with str.join().
5. Divide strings into substrings with str.split().
6. Use the re module for regular expressions in Python.
7. Python supports Unicode characters with escape sequences.
8. Use the unicodedata module for Unicode data manipulation.
9. Convert between strings and bytes with str.encode() and bytes.decode().

### Working with Linked Lists

Linked lists store elements in nodes with references to the next (and sometimes previous) nodes. Keep these points in mind:

1. Linked lists can be singly-linked or doubly-linked.
2. They're dynamic and suitable for situations with unknown data sizes.
3. Constant-time insertions/deletions, but linear-time search/access.
4. Track head, tail, and size of the list.
5. Common operations: insert, delete, search, and traverse.
6. Consider edge cases like inserting/deleting first or last elements or handling empty lists.
7. Use a dummy head for front insertions to simplify code.
8. Use slow and fast pointers to find the middle node or detect cycles.
9. Reverse a linked list by iteratively updating next pointers.
10. Use a stack to simulate recursive calls if recursion exceeds maximum call stack depth.
11. Track the previous node in addition to the current one using a "dummy" node.

### Working with Binary Trees

Binary trees are data structures where each node has up to two children. Tips for working with them:

1. Perform operations like search, insert, and finding predecessors.
2. Traverse in three orders: in-order (left, root, right), pre-order (root, left, right), and post-order (left, right, root).
3. To create a complete tree from an array, use a recursive function with indices `i * 2 + 1` (left) and `i * 2 + 2` (right).
4. For efficiency, use binary search trees (BST) or self-balancing BSTs like AVL trees, which have O(logn) time complexity.

### Working with n-ary Trees

n-ary trees are trees where nodes have up to n children. Some common types and tips:

1. Trie trees: store words with fast lookup (O(n)) but high memory usage due to 26 possible child nodes (one per alphabet letter).
2. AVL trees: self-balancing BSTs with O(logn) complexity. Rebalance if the balance factor is greater than 1 during insertion or deletion.
3. Red-black trees: self-balancing trees, faster than AVL trees with many insertions/deletions due to fewer rotations.
4. For storing ordered items, use balanced BSTs. For unordered items, use hash maps, which have constant lookup time.

### Working with Graphs

Graphs are versatile data structures with nodes and edges. Tips for working with them:

1. Store graphs using edge lists (list of edges), adjacency matrices (V * V array), or adjacency lists (array or hash table of edges).
2. Approach problems as graph problems and apply breadth-first or depth-first traversal.
3. Use stacks for parsing or traversals, and heaps for dynamic collections with minimum/maximum retrieval.
4. For directed graphs, store nodes as objects and edges as pointers. Keep track of visited nodes using a set or visited array.
5. In undirected graphs, skip parent node when calling DFS on neighbors to avoid detecting non-existent cycles.
6. To check if a graph is a tree, ensure it's fully connected (a path between every pair of nodes) and contains no cycles (only one path between each pair).
7. Graph problems can be solved using algorithms like Dijkstra's (shortest path), Kruskal's (minimum spanning tree), and more.
8. In some graph problems, you can utilize dynamic programming or greedy algorithms for optimization.

### Hash Tables

Hash tables are efficient data structures that map keys to values using a hash function, providing constant-time operations. Here are some additional points and tricks to help you use hash tables effectively:

1. Constant-time operations: Hash tables offer constant-time insertions, deletions, and searches on average.
2. Array storage: Hash tables use an array to store data, with the hash function mapping keys to indices in the array.
3. Collisions: When two keys map to the same index, a collision occurs and needs to be resolved.
4. Chaining: One technique to resolve collisions is chaining, which uses a linked list at each index to store the data.
5. Open addressing: Another technique to resolve collisions is open addressing, where an empty slot is probed through the array.
6. Linear probing: Linear probing is a specific type of open addressing that finds the next available slot in the array.
7. Hash function choice: A good hash function should distribute keys evenly across the indices of the array, minimizing collisions.
8. Load factor: The ratio of the number of elements to the size of the array, the load factor can impact the performance of the hash table.
9. Worst-case time complexity: Although hash tables have constant-time operations on average, their worst-case time complexity can be linear.
10. Python implementations: In Python, the built-in dict and set data types are implemented using hash tables, and the hash() function computes the hash value of an object.
11. Custom hash functions: For custom objects, you can define your own hash function by implementing the `__hash__` method.
12. Handling mutable keys: Avoid using mutable objects as keys, as their hash values can change, leading to unexpected behavior.
13. Dynamic resizing: Implement dynamic resizing to maintain a reasonable load factor and optimize performance as the hash table grows or shrinks.
14. Cache-friendly: Hash tables can be cache-friendly by using open addressing, as it allows better utilization of CPU cache due to better locality of reference.
15. Applications: Hash tables are useful in various applications, such as implementing symbol tables in compilers, storing user sessions in web applications, and caching frequently accessed data.

## Algorithms

Algorithms are step-by-step procedures to solve problems. Choosing the right algorithm is crucial for efficiency.

### Two Pointers

Two pointers technique traverses a list/array with two pointers pointing to different elements:

1. Identify problem constraints and choose the appropriate two-pointer approach.
2. Consider conditions for incrementing or decrementing pointers.
3. Pay attention to pointer bounds to avoid out-of-range errors.

### Recursion

Recursion solves problems by solving smaller instances of the same problem:

1. Identify the base case(s) to stop recursion and provide a solution.
2. Call the function recursively, using the base case solution to solve larger instances.

### Backtracking

Backtracking finds solutions by incrementally building candidates and abandoning them if they can't be completed:

1. Identify the base case(s) for stopping recursive calls.
2. Break the problem down into smaller subproblems in the recursive case.
3. Use suitable data structures (e.g., stack, queue) to store potential solutions.
4. Apply pruning techniques to avoid exploring unnecessary paths and improve efficiency.

### Dynamic Programming

Dynamic programming is a problem-solving technique that breaks problems into smaller subproblems and stores solutions to avoid redundant calculations. There are two approaches: top-down (memoization) and bottom-up.

#### Top-down Approach (Memoization)

In the top-down approach, you start with the problem itself and break it down into smaller pieces to solve it. This approach is also known as memoization, as you use a cache (e.g., a dictionary or an array) to store already computed results in order to prevent redundant calculations. The top-down approach is often easier to code and more intuitive but may not be as efficient as the bottom-up approach in some cases.

Steps for the top-down approach:

1. Define a recursive function to solve the problem.
2. Identify the base case(s) that can be solved directly.
3. Use a cache to store the results of subproblems that have already been solved.
4. Check the cache before solving a subproblem; if the result is already cached, return it without recalculating.
5. Solve subproblems by making recursive calls to the function, and store the results in the cache.

#### Bottom-up Approach

In the bottom-up approach, you start with the smallest subproblems and build up to the final solution. This approach is often used when each subproblem must be solved at least once, as it ensures that all subproblems are solved in the correct order. The bottom-up approach may also be more efficient than the top-down approach in terms of memory usage because it avoids the need for recursive function calls, which can take up space on the call stack.

Steps for the bottom-up approach:

1. Identify the smallest subproblems that can be solved directly.
2. Create a table or an array to store the results of subproblems.
3. Iterate through the table/array, solving each subproblem and storing the result.
4. Build the solution for the larger problem using the results of the smaller subproblems.
5. Return the final solution from the table/array.

### Greedy Algorithms

Greedy algorithms follow a problem-solving strategy of making the locally optimal choice at each stage, hoping to find a global optimum. They make the best choice at each step without considering the consequences of those choices on future steps.

Advantages:

* Easy to understand and implement.

Disadvantages:

* May not always find the most efficient or global optimum solution.

### Sorting

Sorting algorithms are used to order a list of items. It's important to know each algorithm's strengths and weaknesses and choose the most appropriate one for your task.

#### Insertion Sort

A simple algorithm that iterates through the list, inserting each item in its correct place in the sorted portion of the list. Best for mostly sorted lists.

* Time complexity: O(n) for mostly sorted lists
* Stable

#### Merge Sort

A divide-and-conquer algorithm that recursively splits the list into halves and merges the sorted halves back together.

* Time complexity: O(n log n)
* Stable

#### Quick Sort

A divide-and-conquer algorithm that selects a pivot element and partitions the list around it.

* Time complexity: O(n log n) on average, O(n^2) worst case
* Not stable

#### Other Sorting Algorithms

Other sorting algorithms include heap sort, radix sort, and timsort (a hybrid of merge sort and insertion sort). In Python, the built-in list.sort() function uses timsort.

#### Choosing a Sorting Algorithm

Consider the time complexity, stability, and specific task constraints or requirements when choosing a sorting algorithm.

### Bit Manipulation

Bit manipulation refers to the act of modifying individual bits within a value stored in a computer's memory. It is often utilized for low-level operations or optimizing code by reducing the number of instructions needed to execute a particular operation.

1. Binary representation: Be familiar with the binary representation of integers and understand how to perform basic operations such as shifting, ORing, ANDing, and XORing.
2. Signed vs. unsigned integers: Grasp the difference between signed and unsigned integers and know how to perform arithmetic shifts for signed integers.
3. Converting between representations: Learn to convert between binary and decimal representations and carry out basic arithmetic operations in binary.
4. Operator precedence: Keep in mind that bitwise operators have lower precedence than most other operators, so you may need to use parentheses to specify the order of operations.
5. Bitwise negation: Understand how to use the bitwise negation operator (~) to flip all bits in a binary number.
6. Setting bits: Learn how to set specific bits within an integer using bitwise OR and the left shift operator.
7. Clearing bits: Know how to clear specific bits within an integer using bitwise AND and the bitwise negation operator.
8. Toggling bits: Learn to toggle specific bits within an integer using bitwise XOR.
9. Bit masking: Use bit masking to extract specific bits from an integer.
10. Bit tricks: Be aware of various bit manipulation tricks, such as using XOR to swap two variables without using a temporary variable or using bit manipulation to efficiently compute powers of two.

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
