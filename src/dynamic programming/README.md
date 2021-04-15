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

