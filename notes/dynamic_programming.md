## Dynamic Programming

Dynamic programming is a method for solving optimization problems by breaking them down into smaller subproblems, storing the solutions to these subproblems in a table, and using these stored solutions to solve larger problems. This approach can significantly reduce the time complexity of the algorithm, allowing it to solve problems much faster than a brute force solution.

Dynamic programming works best for problems that have an optimal substructure, meaning that the optimal solution to a problem can be found by solving its subproblems optimally. This is particularly useful for problems that involve repeating subproblems, such as in the Fibonacci sequence or the knapsack problem.

There are three main approaches to implementing dynamic programming: brute force recursion, memoized recursion, and tabulation.

### Brute Force Recursion

Brute force recursion involves visualizing the problem as a tree of subproblems and implementing the tree using recursion. While this approach may be elegant and concise, it can suffer from exponential time complexity due to the repeated calculation of the same subproblems.

### Memoized Recursion

Memoized recursion involves adding a hash map to store already computed subproblems, allowing for faster lookup and avoiding unnecessary recalculation. This can significantly improve the time complexity of the algorithm.

### Tabulation

Tabulation involves visualizing the problem as a table and setting the elements of the table based on previously calculated values. This bottom-up approach allows for faster computation but requires manual selection of the order in which subproblems are calculated.

### Why might we choose recursive solutions over iterative techniques with tabulation?

Overall, it is faster, but we must manually choose the order in which the subproblems must be calculated. That is frequently troublesome in and of itself. This is straightforward for fibonacci, but it quickly becomes challenging for more complicated dynamic programming problems. As a result, when it is not the bottleneck of our program or we do not expect large inputs, we are typically satisfied with recursive solutions. 

## Common terms explained

### Recursion
Recursion is a method of solving a problem by defining a function that calls itself with a smaller version of the same problem. This allows the function to break the problem down into smaller and smaller pieces until it reaches a base case, at which point it can begin to build a solution by combining the solutions to the smaller subproblems. Recursion is often used to solve problems that can be decomposed into smaller subproblems that are repeated, such as in the Fibonacci sequence or the Tower of Hanoi.

### Subset
A subset is a collection of elements that belongs to a larger set. Every set is considered to be a subset of itself, and the empty set is a subset of every set. Subsets are often used in combinatorial mathematics to describe the possible combinations of elements that can be chosen from a larger set.

### Subarray
A subarray is a contiguous portion of an array, or a sequence of elements within an array. A subarray is defined by its start and end indices, and can be extracted from the original array by using these indices to slice the array. Subarrays are often used in algorithms to perform operations on a portion of an array without affecting the rest of the array.

### Substring
A substring is a contiguous sequence of characters within a string. Like a subarray, a substring is defined by its start and end indices, and can be extracted from the original string by using these indices to slice the string. Substrings are often used in algorithms to search for and manipulate specific sequences of characters within a string.

### Subsequence
A subsequence is a sequence of elements within a larger sequence, such as a string or an array, that can be extracted by deleting some of the elements in the original sequence. A subsequence does not have to be contiguous, unlike a substring or a subarray, and the order of the elements in the subsequence may not be the same as the order in the original sequence. Subsequences are often used in algorithms to identify patterns or trends within a larger sequence of data.

## List of problems

### Fibonacci
Find the nth element of the Fibonacci sequence given a positive integer n.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/fibonacci/">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/fibonacci/">Python</a>

### Grid traveller
Determine the number of paths a traveler can take to reach the bottom right corner of a grid, starting from the top left corner, given the dimensions of the grid. The traveler can only move right or down at each step.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/grid_traveler/">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/grid_traveler">Python</a>

### Climbing stairs
Determine the number of ways to reach the top of a n-step staircase by taking 1, 2, or 3 steps at a time, starting from the bottom.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/climb_stairs">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/climbing_stairs">Python</a>


### Can Sum
Given a list of numbers and a target value, determine if it is possible to obtain the target value by selecting and adding one or more numbers from the list, potentially using the same number multiple times.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_sum">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_sum">Python</a>

### How Sum
If it is possible to obtain a given target value by selecting and adding one or more numbers from a list, determine which numbers should be chosen and in what combination to achieve the target value.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/how_sum">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/how_sum">Python</a>

### Best Sum
If it is possible to obtain a given target value by selecting and adding one or more numbers from a list, determine the smallest set of numbers that should be chosen to achieve the target value.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/best_sum">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/best_sum">Python</a>

### Can Construct
Given a list of strings and a target word, determine if it is possible to create the target word by concatenating one or more of the strings from the list, potentially using the same string multiple times.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_construct">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_construct">Python</a>

### Count Construct
If it is possible to create a target word by concatenating one or more strings from a given list, determine the number of possible sets of strings that can be chosen to construct the target word.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/count_construct">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/count_construct">Python</a>

### All Constructs
If it is possible to create a target word by concatenating one or more strings from a given list, determine the smallest set of strings that should be chosen to construct the target word.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/all_construct">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/all_construct">Python</a>

### Coins
Determine the minimum number of coins from a given set of denominations needed to reach a specific target amount.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/coin_change">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/coins">Python</a>

### Longest common subsequence
Given an array, find the longest sequence of elements that is present in the array as a contiguous subsequence in multiple places.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_common_subsequence">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_common_subsequence">Python</a>

### Longest increasing subarray
Given an array, find the longest contiguous subarray in which the elements are strictly increasing in value.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_increasing_subarray">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_increasing_subarray">Python</a>

### Knuth-Morris-Pratt
Given a text and a pattern, use the Knuth-Morris-Pratt (KMP) algorithm to find the occurrences of the pattern within the text and return their starting indices.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/kmp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/kmp">Python</a>

### Minimum insertions to form a palindrome
Given a string, determine the minimum number of characters that need to be inserted into the string in order to make it a palindrome.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/minimum_insertions_for_palindrome">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/minimum_insertions_for_palindrome">Python</a>
