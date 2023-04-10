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

Arrays are frequently used in programming brain teasers. Here are some tips for working with arrays:

* Consider sorting the array first. This can make it easier to identify patterns and solve the problem. Use sorting algorithms with a time complexity of O(n log n), such as merge sort or quick sort.
* If the array is already sorted, use a binary search algorithm with a time complexity of O(log n). This can efficiently find specific elements in the array.
* Employ the two-pointer technique, which involves using two pointers to iterate through the array. This can help find pairs of elements that meet certain criteria, like having a specific sum.
* Be aware of your solution's space complexity. If the array is very large, create a solution that doesn't require additional space or uses minimal extra space.
* Use pointers to iterate through the array instead of a traditional for loop for faster and more memory-efficient operations.
* If frequent insertions or deletions in the middle of an array are needed, consider using a linked list instead of an array.
* Pay attention to the order of operations when working with arrays. Perform multiple operations in a way that minimizes element shifting within the array.
* To find the maximum or minimum element in an array, use a divide-and-conquer approach, which often finds the maximum or minimum in O(n) time.

### Working with Strings

Strings are another frequent data structure in programming brain teasers. Here are some tips for working with strings:

* For a large number of strings, consider using a prefix tree (also known as a trie) for efficient storage and searching.
* In Python, strings are immutable, meaning you can't change them in place. To modify a string, create a new string with the desired changes.
* Use the str.format() method to build strings with dynamic content, allowing you to insert placeholders and fill them with variable values or expressions.
* To concatenate a list of strings into a single string with a specified separator, use the str.join() method, which is often more efficient than manually concatenating strings in a loop.
* Use the str.split() method to divide a string into a list of substrings based on a specified delimiter.
* The re module in Python offers functions for working with regular expressions to match patterns, extract, or modify substrings in strings.
* Python natively supports Unicode, a standardized character encoding representing most written languages. Include Unicode characters in string literals using special escape sequences (like \uxxxx).
* The unicodedata module provides functions for working with Unicode data, such as determining a character's category or decomposing a character into its components.
* Python's bytes type represents byte sequences used to store binary data or encode strings in specific character encodings. Convert between strings and bytes using the str.encode() and bytes.decode() methods.

### Linked lists
Keep these points in mind when working with linked lists:

* Linked lists are linear data structures comprising a chain of nodes, each containing a value and a reference to the next node. The last node has a reference to None.
* They can be singly-linked (each node refers to the next) or doubly-linked (each node refers to both the next and previous nodes).
* Linked lists are dynamic data structures, which means they can grow and shrink in size as needed, making them suitable for situations with unknown data sizes.
* They offer constant-time insertions and deletions but have linear-time search and access.
* It's essential to track the head, tail, and size of the list, which can be stored as separate variables or list class properties.
* Common operations include inserting, deleting, searching for elements, and traversing the list.
* When implementing a linked list, consider edge cases like inserting or deleting the first or last element, or handling empty lists.
* For problems requiring inserting nodes at the front of the list, use a dummy head to simplify the code and avoid edge cases where the list head needs updating.
* To find the middle node or detect a cycle in a linked list, use a slow and fast pointer technique involving two pointers moving at different paces. If the fast pointer reaches the end before the slow one, the list isn't cyclic; if it catches up, there's a cycle.
* Reverse a linked list to solve problems requiring reverse traversal by iteratively updating the next pointers of each node to point to the previous node.
* Use a stack to simulate recursive calls for a linked list problem if a recursive solution exceeds the maximum call stack depth.
* Often, it's necessary to track the previous node in addition to the current one. This can be achieved by using a "dummy" node pointing to the list head and updating the next pointer as the list is traversed.

### Working with Binary Trees

Binary trees are a common data structure used in programming brain teasers. Here are some tips for working with binary trees:

* When working with binary trees, you may need to perform operations such as search, insert, and predecessor.
* There are three main traversal orders for binary trees: in-order, pre-order, and post-order. In-order traversal is done by visiting the left node, the root, and then the right node. Pre-order traversal is done by visiting the root, the left node, and then the right node. Post-order traversal is done by visiting the left node, the right node, and then the root.
* You can construct a complete tree with an array by using a recursive function to create a TreeNode with the value at each index, and setting its left and right properties to the result of calling the function on the indices i * 2 + 1 and i * 2 + 2. The base case is when i becomes larger than the length of the array.
* When working with binary trees, you'll typically want to use a binary search tree (BST) or a self-balancing BST such as an AVL tree. These types of trees are more efficient for inserting, searching, and deleting elements, and have a time complexity of O(logn).

### Working with n-ary Trees

n-ary trees are trees that have no more than n children. Some common types of n-ary trees include trie trees and AVL trees. Here are some tips for working with these types of trees:

* Trie trees, also known as retrieval trees, are commonly used to store words or strings. They allow for fast lookup of specific words, but can use a lot of memory due to the fact that each node can point to up to 26 other nodes (one for each letter in the alphabet). The time complexity for both retrieval and insertion in a trie tree is O(n), where n is the length of the key being searched for or inserted.
* AVL trees are self-balancing binary search trees that maintain a balance factor of no more than 1 (the difference in height between the left and right subtrees). This ensures that the tree has O(logn) time complexity for operations such as insertion, retrieval, and deletion. However, if the balance factor becomes greater than 1 during an insertion or deletion, a rebalance operation is needed, which has a time complexity of O(logn).
* Red-black trees are another type of self-balancing tree that may be more efficient for scenarios with a large number of insertions and deletions. They have a slightly lower level of balance than AVL trees, but are generally faster due to the fact that they require fewer rotations.
* When deciding between using a balanced BST or a hash map, consider whether you need to store ordered or unordered items. Hash maps are efficient for storing unordered items and have constant time lookup, while balanced BSTs are efficient for storing ordered items and allow for operations such as finding the value nearest to a certain value. The time complexity for lookup in a balanced BST is O(logn).
    
### Working with Graphs

Graphs are a common data structure used in programming brain teasers. Here are some tips for working with graphs:

* When storing a graph, there are a few different options to consider. These include an edge list (a list of edges between numbered nodes, with a weight if needed), an adjacency matrix (a V * V array with 0s and 1s indicating the presence of an edge), and an adjacency list (an array or hash table with a list of edges at each element, where the key is the node and the edges are the values).
* Consider treating the problem as a graph problem and using breadth-first or depth-first traversal to solve it.
* Use a stack if the problem involves parsing or traversals.
* Consider using heaps whenever you need to take the minimum or maximum of a dynamic collection.
* For directed graphs, it can be useful to store the graph using nodes as objects and edges as pointers (OOP). This can work well because you don't have to maintain the storage of an edge at each vertex and don't have to worry about becoming unsynchronized.
* When working with directed graphs, you'll need to keep track of visited nodes to avoid getting stuck in infinite loops. One option is to use a set to keep track of visited nodes, as this allows for constant lookup time and easy initialization. Alternatively, you can use a visited array in your recursive stack to keep track of the current path and detect cycles.
* When working with undirected graphs, you'll need to be careful to skip the parent node when calling the DFS on each neighbor to avoid detecting non-existent cycles.
* To determine whether a graph is a tree, consider the following two conditions: (1) the graph is fully connected (i.e., for every pair of nodes in the graph, there is a path between them) and (2) the graph contains no cycles (i.e., there is exactly one path between each pair of nodes in the graph).

### Hash tables

Here are some points to keep in mind while working with hash tables:

* A hash table is a data structure that maps keys to values using a hash function. It allows for constant-time insertions, deletions, and searches, making it an efficient data structure for storing and retrieving data.
* Hash tables use an array to store the data, and the hash function maps the keys to indices in the array. A collision occurs when two keys map to the same index, and must be resolved by storing the data in a different way at that index.
* There are various techniques for resolving collisions, including chaining (using a linked list at each index to store the data), open addressing (probing through the array to find an empty slot), and linear probing (finding the next available slot in the array).
* The choice of hash function is important for the efficiency of the hash table. A good hash function should distribute the keys evenly across the indices of the array and minimize the number of collisions.
*  The load factor, or the ratio of the number of elements to the size of the array, can affect the performance of the hash table. A high load factor can increase the number of collisions and decrease the performance of the hash table.
* Hash tables have constant-time insertions, deletions, and searches on average, but the worst-case time complexity for these operations can be linear.
* In Python, the built-in dict data type is implemented using a hash table. The hash() function can be used to compute the hash value of an object, and the set() data type is implemented using a hash table.

## Algorithms

Algorithms are a set of steps or procedures used to solve a problem. There are various types of algorithms that can be used to solve different types of problems, and choosing the right algorithm is crucial for finding an efficient solution. Some common types of algorithms include:

## Two pointers

The two pointer technique is a method used to traverse through a list or array with two pointers pointing to different elements. One pointer is usually at the start of the list and the other at the end. The pointers then move towards each other, depending on a certain condition. This technique is often used to solve problems involving subarrays or finding the maximum or minimum of a subarray.

* Begin by identifying the problem constraints and deciding which of the two pointer approaches (i.e. starting from the beginning, ending, or middle of the list) is most appropriate
* Carefully consider the conditions under which you will increment or decrement the pointers, and ensure that these are consistent with the problem constraints
* Pay attention to the bounds of your pointers to avoid going out of range of the list

### Recursion

Recursion is a method of solving problems where the solution is based on solving smaller instances of the same problem. In other words, the solution to a problem is expressed in terms of itself. Recursion is a powerful technique that can be used to solve problems that are difficult to solve using other methods.

To use recursion, you need to identify the base case, which is the smallest instance of the problem that can be solved directly. The base case is used to stop the recursion and provide a solution for the problem. The solution for the base case is then used to solve larger instances of the problem, by calling the function recursively.

## Backtracking

Backtracking is a general algorithm for finding all (or some) solutions to some computational problems, that incrementally builds candidates to the solutions, and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

* Start by identifying the base case(s) of your problem, as these will be the stopping point for your recursive calls
* Carefully consider the recursive case, and identify what steps need to be taken in order to break the problem down into smaller subproblems
* Use a suitable data structure, such as a stack or queue, to store your potential solutions as you explore the different possibilities
* Consider using pruning techniques to avoid exploring unnecessary paths and improve the efficiency of your solution

## Dynamic Programming and Memoization

Dynamic programming is a method of solving problems by breaking them down into smaller subproblems and storing the solutions to these subproblems in order to avoid redundant calculations. There are two approaches to dynamic programming: top-down and bottom-up.

In the top-down approach, you start with the problem itself and break it down into smaller pieces in order to solve it. This approach is also known as memoization, as you use a cache to store already computed results in order to prevent redundant calculations. The top-down approach is often easier to code and more intuitive, but it may not be as efficient as the bottom-up approach in some cases.

In the bottom-up approach, you start with the smallest subproblems and build up to the final solution. This approach is often used when each subproblem must be solved at least once, as it ensures that all subproblems are solved in the correct order. The bottom-up approach may also be more efficient than the top-down approach in terms of memory usage because it avoids the need for recursive function calls, which can take up space on the call stack. In the bottom-up approach, the subproblems are solved and stored in a table or array, so there is no need to keep track of the intermediate state of the function during the recursive calls. This can be especially important in cases where the subproblems are large or there are many of them, as the call stack can quickly become overloaded. Additionally, the bottom-up approach allows for better control over the order in which the subproblems are solved, as it is possible to solve the subproblems in a specific order that ensures that the required information is available when it is needed. This can be particularly useful in cases where the subproblems have dependencies on one another.

### Greedy algorithms

A greedy algorithm is an algorithmic paradigm that follows the problem-solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum. In other words, a greedy algorithm makes the most optimal choice at each step, without considering the consequences of those choices on future steps.

One of the main advantages of greedy algorithms is that they are easy to understand and implement. However, they are not always the most efficient solution to a problem, as they may not always find the global optimum.

### Sorting

There are many different sorting algorithms that can be used to order a list of items. It is important to know the strengths and weaknesses of each algorithm and choose the one that is most appropriate for the task at hand.

#### Insertion Sort

Insertion sort is a simple sorting algorithm that works by iterating through the list and inserting each item in its correct place in the sorted portion of the list. It is best suited for lists that are already mostly sorted, as it has a time complexity of O(n) in this case. Insertion sort is stable, meaning that it preserves the original order of items with equal keys.

#### Merge Sort

Merge sort is a divide and conquer algorithm that works by recursively splitting the list into halves and then merging the sorted halves back together. It has a time complexity of O(n log n) and is stable.

#### Quick Sort

Quick sort is another divide and conquer algorithm that works by selecting a pivot element and then partitioning the list around it. It has a time complexity of O(n log n) on average, but can be as bad as O(n^2) in the worst case. Quick sort is not stable.

#### Other Sorting Algorithms

Other commonly used sorting algorithms include heap sort, radix sort, and timsort (a hybrid of merge sort and insertion sort). In Python, the built-in list.sort() function uses timsort. There are also many other sorting algorithms that are less commonly used, such as bubble sort and selection sort.

#### Choosing a Sorting Algorithm

When choosing a sorting algorithm, it is important to consider the time complexity and stability of the algorithm, as well as any additional constraints or requirements of the task. In general, divide and conquer algorithms such as merge sort and quick sort have a good time complexity and are suitable for many tasks. However, insertion sort may be a better choice for lists that are already mostly sorted, and heap sort may be a good choice for sorting large lists that do not fit in memory.

### Bit Manipulation
Bit manipulation is the act of altering or manipulating individual bits in a value stored in a computer's memory. This is often used in computer programming to perform low-level operations or to optimize code by minimizing the number of instructions used to perform a certain operation. Some common bit manipulation techniques include bit shifting, masking, and setting or clearing individual bits.

* Be familiar with the binary representation of integers and how to perform basic operations such as shifting, ORing, ANDing, and XORing on them
* Understand the difference between signed and unsigned integers and how to perform arithmetic shifts for signed integers
* Know how to convert between binary and decimal representations, and be able to perform basic arithmetic operations in binary
* Keep in mind the bitwise operators have a lower precedence than most other operators, so you may need to use parentheses to specify the order of operations.

## List of problems

### Minimum deletions to make valid parentheses

Given a string of parentheses, determine the minimum number of parentheses that need to be removed to make the string valid. This can be solved using a stack data structure to track the open parentheses as we iterate through the string. If we encounter an open parenthesis, we add it to the stack. If we encounter a closing parenthesis, we check if there is a matching open parenthesis on the top of the stack. If there is, we pop the open parenthesis from the stack. If there is not, we add the closing parenthesis to a list of characters to remove. After we have processed the entire string, we remove the remaining open parentheses from the stack.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/deletions_to_make_valid_parentheses">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/deletions_to_make_valid_parentheses">Python</a>

### Is palindrome after at most one char delete?

Determinine whether a string can be transformed into a palindrome by deleting at most one character. This can be solved using a two pointer approach, where we start from both ends of the string and move towards the middle. If we encounter a pair of characters that are not equal, we have three options: delete the character at the left pointer, delete the character at the right pointer, or delete both characters. We check if any of these options results in a palindrome and return the result.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/is_palindrome_after_char_deletion">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/is_palindrome_after_char_deletion">Python</a>

### K closest points to origin 	

Find the K points in a list of points that are closest to the origin (0, 0). This can be solved using a min heap data structure, where we store the K closest points so far. As we iterate through the list of points, we compute the distance from each point to the origin and add it to the heap if it is among the K closest points so far.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/k_closest_points">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/k_closest_points">Python</a>

### Subarray sum equals K 	

Find a contiguous subarray of an array that has a sum of K. This can be solved using a sliding window approach, where we maintain a running sum of the elements in the window and move the window through the array until we find a subarray with the desired sum.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/subarray_sum">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/subarray_sum">Python</a>

### Add numbers given as strings 	

Add two numbers represented as strings. This can be solved by treating the strings as arrays of digits and using a carry variable to keep track of the carryover from one place value to the next.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/add_string_numbers">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/add_string_numbers">Python</a>

### Dot product of two sparse vectors 	

Compute the dot product of two sparse vectors, where a vector is represented as a list of (index, value) pairs. This can be solved by iterating through both vectors and adding up the products of the values at the same index.
 
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/sparse_vectors_product">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/sparse_vectors_product">Python</a>

### Range sum of BST 	

Compute the sum of the values of all the nodes in a binary search tree within a given range. This can be solved using a recursive in-order traversal of the tree, where we add the value of each node to the sum if it is within the range.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/range_sum_of_bst">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/range_sum_of_bst">Python</a>

### Product of array except self 	

Compute an array where each element is the product of all the other elements in the input array. This can be solved using two pass approach, where we first compute the product of all the elements before each index and then compute the product of all the elements after each index.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/array_product">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/array_product">Python</a>

### Convert BST to sorted doubly linked list 

Convert a binary search tree to a sorted doubly linked list. This can be solved using a recursive in-order traversal of the tree, where we build the linked list by adding each node to the end of the list as we visit it.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/bst_to_list">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/bst_to_list">Python</a>

### Lowest common ancestor of a binary tree

Find the lowest common ancestor (LCA) of two nodes in a binary tree. The LCA is the node in the tree that is the ancestor of both nodes and is the deepest node in the tree. To solve this problem, you can use a variety of techniques such as traversing the tree in a depth-first or breadth-first manner, or using a recursive approach to traverse the tree and find the LCA. You can also use a divide and conquer approach, where you split the tree into left and right subtrees and find the LCA in each subtree. Another approach is to use a hash table or a map to store the ancestors of each node and then use this information to find the LCA.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lowest_common_ancestor">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lowest_common_ancestor">Python</a>

### LRU Cache 	

Designing a cache data structure that stores a limited number of items and removes the least recently used items when the capacity is reached. This can be solved using a doubly linked list and a hash table. The doubly linked list is used to store the items in the cache in the order in which they were accessed, with the most recently accessed item at the front of the list and the least recently accessed item at the back. The hash table is used to store the keys and values of the items in the cache and to quickly retrieve items from the cache based on their keys.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lru_cache">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lru_cache">Python</a>

### Randomize An Array 	

Shuffle the elements of an array randomly. This can be solved using a random number generator and a Fisher-Yates shuffle algorithm. The Fisher-Yates shuffle algorithm works by starting at the end of the array and randomly swapping each element with an element preceding it. This results in a randomly shuffled array.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/randomize_array">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/randomize_array">Python</a>

### Binary Tree Right Side View

Given a binary tree, return an array containing the values of the nodes on the right side of the tree, when viewed from the right. One way to solve this problem might be to perform a breadth-first search on the tree, keeping track of the maximum depth of each node as it is visited. When visiting a node at a particular depth for the first time, add its value to the result array.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/binary_tree_right_side_view">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/binary_tree_right_side_view">Python</a>

### Design Browser History

Implement a browser history system that supports the following operations: visit a URL, go back to the previous URL, and go forward to the next URL. One potential approach to this problem could involve using a doubly-linked list to store the URLs visited, with a pointer to the current URL. Going back or forward would simply involve moving the pointer to the previous or next URL in the list.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/design_browser_history">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/design_browser_history">Python</a>

### Score After Flipping Matrix

Given a matrix of 0s and 1s, flip the rows and columns of the matrix such that the maximum possible score is achieved. The score is calculated as the number of 1s in the matrix. One way to solve this problem might be to use dynamic programming to compute the maximum score for each submatrix of the original matrix, taking into account whether the rows and columns of the submatrix should be flipped.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/score_after_flipping_matrix">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/score_after_flipping_matrix">Python</a>
