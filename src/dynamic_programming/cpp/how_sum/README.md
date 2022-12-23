## How Sum

Given a target sum target and a list of positive integers numbers, the task is to find a combination of numbers from numbers that add up to target. If no such combination exists, the function should return None.

## Examples

```
Input: target=9, numbers=[2, 3, 4, 5]
Output: [2, 2, 2, 3]
Explanation: The numbers 2, 2, 2, and 3 add up to 9.
```

```
Input: target=10, numbers=[1, 2, 3, 4]
Output: [2, 2, 3, 3]
Explanation: The numbers 2, 2, 3, and 3 add up to 10.
```

## Approach

Three different approaches have been implemented to solve this problem:

* `how_sum_basic()`: This is a recursive function that tries to find a combination of numbers that adds up to the target by considering each number in numbers and subtracting it from the target. If the remainder is non-negative, it continues the search with the remainder as the new target.
* `how_sum_memo()`: This is similar to the first approach, but it uses memoization to avoid recalculating the same subproblems.
* `how_sum_table()`: This is a dynamic programming approach that uses a table to store the results of subproblems. It starts by filling the table with the combinations of numbers that add up to 0, and then uses these combinations to calculate the combinations that add up to larger numbers.

## Complexity

* The time complexity of the first two approaches is $O(2^n)$, since they both consider every possible combination of numbers. The space complexity is $O(n)$, since the helper function in the first approach and the memoization table in the second approach both use an array of size n to store the results of subproblems.

* The time complexity of the third approach is $O(tn)$, where $t$ is the target sum and $n$ is the number of elements in numbers. The space complexity is $O(t)$, since the table used to store the results of subproblems has a size of $t$.
