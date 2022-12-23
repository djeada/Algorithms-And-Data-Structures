## Minimum Insertions for Palindrome

Given the dimensions of a grid, represented by the number of rows num_rows and the number of columns num_columns, the task is to find the total number of unique paths that a traveller can take to go from the top left corner of the grid to the bottom right corner. The traveller can only move down or right at each step.

## Examples

```
Input: num_rows=2, num_columns=2
Output: 2
Explanation: There are two paths the traveller can take: down-right and right-down.

+---+---+
| S |   |
+---+---+
|   | E |
+---+---+
```


```
Input: num_rows=3, num_columns=4
Output: 10
Explanation: There are 10 paths the traveller can take, for example down-down-right-right or down-right-down-right.

+---+---+---+---+
| S |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   | E |
+---+---+---+---+
```


## Approach

Three different approaches have been implemented to solve this problem:

* `grid_traveller_basic()`: This is a recursive function that finds the number of paths by considering the number of paths to the top left corner of the grid and the number of paths to the left of the current position.

* `grid_traveller_memo()`: This is similar to the first approach, but it uses memoization to avoid recalculating the same subproblems.

* `grid_traveller_table()`: This is a dynamic programming approach that uses a table to store the results of subproblems. It starts by filling the table with the number of paths to the top left corner of the grid, and then uses these values to calculate the number of paths to the other positions in the grid.

## Complexity

* The time complexity of the first two approaches (`grid_traveller_basic()` and `grid_traveller_memo()`) is $O(2^n)$, where $n$ is the number of rows or columns in the grid. The space complexity is $O(n)$, since the helper function in the first approach and the memoization table in the second approach both use an array of size $n$ to store the results of subproblems.

* The time complexity of the third approach (`grid_traveller_table()`) is $O(n^2)$, since it uses a table of size $n x m$ to store the results of subproblems. The space complexity is also $O(n^2)$.
