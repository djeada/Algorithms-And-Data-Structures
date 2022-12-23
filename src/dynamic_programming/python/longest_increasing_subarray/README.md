## Longest Increasing Subarray
Given a list of integers a, the task is to find the length of the longest increasing subsequence (LIS) in a.

## Examples
```
Input: [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: 6
Explanation: The longest increasing subsequence is [10, 22, 33, 50, 60, 80].
```

```
Input: [3, 4, 5, 1]
Output: 3
Explanation: The longest increasing subsequence is [3, 4, 5].
```

## Approach

Three different approaches have been implemented to solve this problem:

* `lis_basic()`: This is a recursive function that finds the LIS by considering each element in the input list and deciding whether to include it in the LIS or not. It compares the current element with the previous element in the LIS, and only includes it if it is greater than the previous element.

* `lis_memo()`: This is similar to the first approach, but it uses memoization to avoid recalculating the same subproblems.

* `lis_tab()`: This is a dynamic programming approach that uses a table to store the results of subproblems. It starts by filling the table with the LIS lengths for sublists of length 1, and then uses these values to calculate the LIS lengths for longer sublists.

## Complexity

* The time complexity of the first two approaches is $O(n^2)$, since they both consider every possible subsequence of the input list. The space complexity is $O(n)$, since the helper function in the first approach and the memoization table in the second approach both use an array of size n to store the results of subproblems.

* The time complexity of the third approach is $O(n^2)$, since it considers every possible subsequence of the input list. The space complexity is $O(n)$, since the table used to store the results of subproblems has a size of $n$.