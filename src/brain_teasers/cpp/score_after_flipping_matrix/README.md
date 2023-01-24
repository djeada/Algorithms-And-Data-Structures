## Score After Flipping Matrix

We are given a matrix that contains only 0s and 1s. Each row represents a binary number. We can flip any number of rows and columns. We want to maximize the sum of the numbers in the matrix after flipping.

## Examples

```
Input Matrix:

1 1 1
1 0 1
0 0 0

Output: 19

Explanation:

0b111 -> 7
0b101 -> 5
0b111 -> 7
```

## Approach

The function loops through all the rows and columns of the matrix and toggles each row and column. It then calculates the score of the matrix after each toggle and updates the maximum score if the new score is greater than the current maximum score.

## Complexity

The time complexity of the function is $O(n^2)$, where $n$ is the number of rows and columns in the matrix. The function loops through all the rows and columns of the matrix and performs a constant number of operations on each iteration. The space complexity is $O(1)$, as the function does not create any new data structures.