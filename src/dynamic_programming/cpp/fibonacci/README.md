## Fibonacci Sequence

The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1. Given an integer n, the task is to find the nth number in the Fibonacci sequence.

## Examples

```
Input: n=6
Output: 8
Explanation: The Fibonacci sequence starting with 0 and 1 is [0, 1, 1, 2, 3, 5, 8]. The 6th number in the sequence is 8.
```


```
Input: n=10
Output: 55
Explanation: The Fibonacci sequence starting with 0 and 1 is [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55]. The 10th number in the sequence is 55.
```

## Approach

Three different approaches have been implemented to solve this problem:

* `fib_basic()`: This is a recursive function that finds the nth number in the Fibonacci sequence by recursively calculating the $(n - 1)th$ and $(n - 2)th$ numbers in the sequence.
* `fib_memo()`: This function uses memoization to store the results of subproblems and avoid recalculating them. It works similarly to the `fib_basic()` function, but it uses a dictionary to store the results of subproblems so that they can be reused in future recursive calls.
* `fib_tab()`: This function uses dynamic programming to store the results of subproblems in a table. It iteratively calculates the nth number in the Fibonacci sequence by using the values of the $(n - 1)th$ and $(n - 2)th $numbers in the sequence.

## Complexity

* The time complexity of the first approach (`fib_basic()`) is $O(2^n)$, since each recursive call generates two more recursive calls. The space complexity is $O(n)$, since the maximum depth of the recursion tree is $n$.
* The time complexity of the second approach (`fib_memo()`) is $O(n)$, since the function only needs to compute each number in the Fibonacci sequence once. The space complexity is also $O(n)$, since the memoization table uses an array of size $n$ to store the results of subproblems.
* The time complexity of the third approach (`fib_tab()`) is $O(n)$, since it uses a table of size $n$ to store the results of subproblems. The space complexity is also $O(n)$, since the table used to store the results of subproblems has a size of $n$.
