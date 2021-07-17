<h1>Dynamic Programming</h1>

A lot of problems dealing with optimizing some quantity can be solved using three different approaches: 

1.  A brute force top-down recursive approach.
    - Visualize the problem as a tree of subproblems
    - Implement the tree using recursion
    - Add a base case that will end the recursion
 
2.  A dynamic top-down recursive approach using memoization.   
    - Visualize the problem as a tree of subproblems
    - Implement the tree using recursion
    - Use a hash-map to store already computed subproblem
    - Add a base case that will end the recursion       

3.  A dynamic bottom-up iterative approach using tabulation.
    - Visualize the problem as a table
    - Initialize table with default values
    - The table size is based on inputs
    - Put trivial answer as a first element in the table
    - Set further elements based on the already set elements

Recursive brute force solutions usually look elegant and concise. However they are doing the same calculation repeatedly. As a result, not seldom the time grows exponentially with the size of the problem.

<h1>List of problems</h1>

<h2>Fibonacci</h2>
Given a number n, find n-th element of the Fibonacci Sequence.

<h2>Grid Traveller</h2>
Grid traveller can only move right and down. Give a matrix of size MxN, in how many ways he can reach point (M, N) starting from (1, 1).

<h2>Number of ways to reach at the top of stairs</h2>
Given a n-step stair case, count the number of ways of reaching the stop of stairs. You can make: 1, 2, or 3 steps.

<h2>Sum Problems</h2>
Can Sum: Can we sum numbers from the list to get a given target. We can choose one number multiple times.
How Sum: If we can sum numbers from the list to get a given target, then which numbers would that be.
Best Sum: If we can sum numbers from the list to get a given target, then which set of numbers would be the smallest.

<h2>Construct Problems</h2>
Can Construct: Can we construct a word by concatenating string from a given list. One string can be chosen multiple times.
Count Construct: If we can construct a word by concatenating string from a given list, then which strings would that be.
All Constructs: If we can construct a word by concatenating string from a given list, then which set of strings would be the smallest.

<h2>Coins</h2>
Given a set of denominations and an amount, find the minimum number of coins from the set that will sum up to the given amount.
