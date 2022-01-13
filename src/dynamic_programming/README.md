# Dynamic Programming

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

# Common terms explained

## Recursion

## Subset

## Subarray

## Substring

## Subsequence

<h1>Fibonacci</h1>
Given a number n, find n-th element of the Fibonacci Sequence.

TODO: nlogn fast solution

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Grid traveller</h1>
Grid traveller can only move right and down. Give a matrix of size MxN, in how many ways he can reach point (M, N) starting from (1, 1).

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Climbing stairs</h1>
Given a n-step stair case, count the number of ways of reaching the stop of stairs. You can make: 1, 2, or 3 steps.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Sum problems</h1>
Can Sum: Can we sum numbers from the list to get a given target. We can choose one number multiple times.
How Sum: If we can sum numbers from the list to get a given target, then which numbers would that be.
Best Sum: If we can sum numbers from the list to get a given target, then which set of numbers would be the smallest.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Construct problems</h1>
Can Construct: Can we construct a word by concatenating string from a given list. One string can be chosen multiple times.
Count Construct: If we can construct a word by concatenating string from a given list, then which strings would that be.
All Constructs: If we can construct a word by concatenating string from a given list, then which set of strings would be the smallest.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Coins</h1>
Given a set of denominations and an amount, find the minimum number of coins from the set that will sum up to the given amount.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Longest increasing subsequence</h1>
Find longest increasing subsequence in a given array.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>
