## Dynamic Programming

A lot of problems dealing with optimizing some quantity can be solved using three different approaches: 

1.  A brute force top-down recursive approach (recursion).
    - Visualize the problem as a tree of subproblems;
    - Implement the tree using recursion;
    - Add a base case that will end the recursion;
 
2.  A dynamic top-down recursive approach using memoization (recursion + memoization).   
    - Visualize the problem as a tree of subproblems;
    - Implement the tree using recursion;
    - Use a hash-map to store already computed subproblem;
    - Add a base case that will end the recursion;

3.  A dynamic bottom-up iterative approach using tabulation.
    - Visualize the problem as a table;
    - Initialize table with default values;
    - The table size is based on inputs;
    - Put trivial answer as a first element in the table;
    - Set further elements based on the already set elements;
    - It tracks the mapping between the term number and the answer for that term;

Recursive brute force solutions usually look elegant and concise. However they are doing the same calculation repeatedly. As a result, not seldom the time grows exponentially with the size of the problem.

## Why are recursive solutions needed when iterative techniques with tabulation are so fast?

Overall, it is faster, but we must manually choose the order in which the subproblems must be calculated. That is frequently troublesome in and of itself. This is straightforward for fibonacci, but it quickly becomes challenging for more complicated dynamic programming problems. As a result, when it is not the bottleneck of our program or we do not expect large inputs, we are typically satisfied with recursive solutions. 

## Common terms explained

### Recursion

### Subset

### Subarray

### Substring

### Subsequence

## List of problems

### Fibonacci
Given a number n, find n-th element of the Fibonacci Sequence.

TODO: nlogn fast solution

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/fibonacci/src/fibonacci.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/fibonacci/src/fib.py">Python</a>

### Grid traveller
Grid traveller can only move right and down. Give a matrix of size MxN, in how many ways he can reach point (M, N) starting from (1, 1).

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/grid_traveler/src/grid_travelers.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/grid_traveler/src/grid_traveler.py">Python</a>

### Climbing stairs
Given a n-step stair case, count the number of ways of reaching the stop of stairs. You can make: 1, 2, or 3 steps.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/climb_stairs/src/climb.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/climbing_stairs/src/climb.py">Python</a>


### Can Sum: 
Can we sum numbers from the list to get a given target. We can choose one number multiple times.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_sum/src/can_sum.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_sum/src/can_sum.py">Python</a>

### How Sum: 
If we can sum numbers from the list to get a given target, then which numbers would that be.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/how_sum/src/how_sum.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/how_sum/src/how_sum.py">Python</a>

### Best Sum: 
If we can sum numbers from the list to get a given target, then which set of numbers would be the smallest.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/best_sum/src/best_sum.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/best_sum/src/best_sum.py">Python</a>

### Can Construct: 
Can we construct a word by concatenating string from a given list. One string can be chosen multiple times.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_construct/src/can_construct.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_construct/src/can_construct.py">Python</a>

### Count Construct: 
If we can construct a word by concatenating string from a given list, then which strings would that be.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/count_construct/src/count_construct.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/count_construct/src/count_construct.py">Python</a>

### All Constructs: 
If we can construct a word by concatenating string from a given list, then which set of strings would be the smallest.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/all_construct/src/all_construct.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/all_construct/src/all_construct.py">Python</a>

### Coins
Given a set of denominations and an amount, find the minimum number of coins from the set that will sum up to the given amount.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/coin_change/src/coin_change.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/coins/src/coins.py">Python</a>

### Longest common subsequence
Find the longest common subsequence in a given array.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_common_subsequence/src/longest_common_subsequence.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_common_subsequence/src/lcs.py">Python</a>

### Longest increasing subarray
Find the longest increasing subarray in a given array.

#### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_increasing_subarray/src/longest_increasing_subarray.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_increasing_subarray/src/lis.py">Python</a>

