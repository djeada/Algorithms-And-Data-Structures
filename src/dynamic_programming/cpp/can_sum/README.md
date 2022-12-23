## Can Sum

Given a target number target and a list of positive integers numbers, the goal is to determine if it is possible to sum the elements in numbers to reach the target.

## Examples

```
Input: target=7, numbers=[2, 3]
Output: True

Explanation: 2 + 2 + 3 = 7
```

```
Input: target=9, numbers=[2, 4, 8]
Output: False

Explanation: There is no combination of numbers that add up to 9
```

## Approach

Three different functions have been implemented to solve this problem:

* `can_sum_basic`: This function uses a recursive approach to check if it is possible to sum the elements in numbers to reach the target. It starts by checking if the target is 0 (in which case it returns True) or if the target is negative (in which case it returns False). If neither of those conditions is met, it checks if any of the recursive calls to itself using the target minus one of the elements in numbers returns True.
* `can_sum_memo`: This function is similar to can_sum_basic, but it includes a memoization step to store the results of recursive calls and avoid calculating them multiple times. This improves the performance of the function by reducing the number of recursive calls.
* `can_sum_table`: This function uses a dynamic programming approach to solve the problem. It creates a table of Booleans with length target + 1, initialized to False, and sets the first element to True. Then, it iterates over the table and, for each True element, sets the value of the element at index i + number (where i is the current index and number is an element in numbers) to True if i + number is less than or equal to the target. Finally, it returns the value of the last element in the table, which will be True if it is possible to sum the elements in numbers to reach the target and False otherwise.

## Complexity

The complexity of the different solutions is as follows:

* `can_sum_basic`: This function has a time complexity of $O(2^n)$, where n is the length of numbers, because it makes two recursive calls for each element in numbers. It has a space complexity of $O(n)$, because the call stack grows by n at each recursive call.
* `can_sum_memo`: This function has a time complexity of $O(n * target)$, where n is the length of numbers, because it iterates over numbers once for each element of the target. It has a space complexity of $O(n * target)$, because it stores the results of the recursive calls in a dictionary with $n * target elements$.
* `can_sum_table`: This function has a time complexity of $O(n * target)$, where n is the length of numbers, because it iterates over the elements in numbers once for each element of the target. It has a space complexity of $O(target)$, because it creates a table with target elements.. The space complexity is $O(n^2)$, since the table used to store the results of subproblems has a size of $n^2$.
