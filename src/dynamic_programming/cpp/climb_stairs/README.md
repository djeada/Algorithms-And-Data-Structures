## Climbing Stairs

You are given a staircase with n steps, and you can climb 1, 2, or 3 steps at a time. Write a function to count the number of ways you can climb the staircase.

## Examples
```
Input:

num_steps = 3

Output:

4

Explanation: There are four ways to climb the staircase:

    1 step + 1 step + 1 step
    1 step + 2 steps
    2 steps + 1 step
    3 steps
```

```
Input:

num_steps = 4

Output:

7

Explanation: There are seven ways to climb the staircase:

    1 step + 1 step + 1 step + 1 step
    1 step + 1 step + 2 steps
    1 step + 2 steps + 1 step
    2 steps + 1 step + 1 step
    2 steps + 2 steps
    1 step + 3 steps
    3 steps + 1 step
```

## Approach 

There are three ways to climb the staircase: by taking 1 step, 2 steps, or 3 steps. For each step, we can choose one of these options. We can recursively count the number of ways to climb the rest of the steps, depending on which option we choose.

* The `count_ways_to_climb_basic` function uses a recursive approach to solve the problem. It recursively calls itself with a modified input (num_steps reduced by either 1, 2, or 3) until the base case (num_steps is 0) is reached, at which point it returns 1. The recursive calls are then combined and returned as the final result.
* The `count_ways_to_climb_memo` function also uses a recursive approach, but includes an additional parameter called `ways_to_climb` which serves as a memoization cache. This cache stores the number of ways to climb the staircase for a given number of steps. If the number of steps has already been calculated and stored in the cache, the function returns the value from the cache instead of making a recursive call. This helps to avoid repeating calculations and improve the performance of the function.
* The `count_ways_to_climb_table function` uses a bottom-up dynamic programming approach to solve the problem. It starts by initializing a table with the base case ($table[0] = 1$) and then iteratively fills in the rest of the table using a loop. The value at each index i in the table is calculated by adding together the values at the previous indices ($i - 1$, $i - 2$, and $i - 3$). This approach avoids the need for recursive calls and instead builds up the solution in a tabular format.

## Complexity  

* The `count_ways_to_climb_basic` function has a time complexity of O(3^n), since at each step we make 3 recursive calls. The space complexity is O(n), since the maximum depth of the recursion tree is n.
* The `count_ways_to_climb_memo` function has a time complexity of O(n), since we only need to compute each subproblem once, and the space complexity is also O(n), since we need to store the results of each subproblem in a dictionary.
* The `count_ways_to_climb_table` function has a time complexity of O(n) and a space complexity of O(n), since we store the results of each subproblem in an array.