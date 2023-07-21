# Dynamic Programming

Dynamic Programming (DP) is a method used in computer science for solving complex problems by breaking them down into simpler, more manageable sub-problems. By solving these sub-problems once, storing their solutions, and reusing these solutions, dynamic programming ensures efficient problem-solving. It transforms potentially exponential-time problems into more manageable polynomial-time problems.

## Key Properties for Dynamic Programming

Two fundamental properties make a problem suitable for a dynamic programming solution: **optimal substructure** and **overlapping sub-problems**. 

1. **Optimal Substructure**: A problem has an optimal substructure if an optimal solution can be constructed efficiently from the optimal solutions of its subproblems. For example, the shortest path between two cities, say City A and City C, going through City B, can be found by combining the shortest path from City A to City B and the shortest path from City B to City C.

2. **Overlapping Sub-problems**: A problem has overlapping sub-problems if the problem can be broken down into subproblems which are reused several times. For instance, in the calculation of the Fibonacci sequence, to compute the 5th Fibonacci number, one must calculate the 3rd and 4th Fibonacci numbers, which in turn require calculating the 2nd, 1st, and 0th numbers, showing a repetition of subproblems.

## Implementation Techniques

Dynamic programming can be implemented via three main strategies: **Brute Force Recursion**, **Memoized Recursion**, and **Tabulation**.

### Brute Force Recursion

In this approach, problems are divided into smaller sub-problems using recursion, and these are solved independently. However, because the same sub-problems might be solved multiple times, this can lead to inefficiency. Imagine trying to find a path in a maze; one might end up visiting the same points multiple times, leading to wasted effort.

```
      Fib(5)
       |
--------------------------------------------------
|                                                |
Fib(4)                                         Fib(3)
|                                                |
-------------------------------                  -------------
|                             |                  |           |
Fib(3)                      Fib(2)             Fib(2)     Fib(1)
|                             |                  |
--------------              ------             ------
|            |             |      |           |      |  
Fib(2)      Fib(1)       Fib(1) Fib(0)       Fib(1) Fib(0)
|             
---------     
|       | 
Fib(1) Fib(0)
```

### Memoized Recursion (Top-Down Dynamic Programming)

To improve upon brute force recursion, memoized recursion stores the results of already solved sub-problems to avoid redundancy. It's like taking notes while solving a complex problem - if you encounter the same subproblem again, you simply look up your notes instead of solving it again. For instance, while climbing a stair-case, if you calculate and store the number of ways to reach each step, you can use these results to easily calculate the number of ways to reach the top.

Here, we only fill in entries as we encounter them during the recursive calls. We don't need to calculate Fib(n) for all n, only for the ones that are actually used.

```
 Memoization Table for Fibonacci Sequence:
 --------------------------------------
 | n  | Fib(n)                         |
 --------------------------------------
 | 5  | 5  (from Fib(4) + Fib(3))      |
 | 4  | 3  (from Fib(3) + Fib(2))      |
 | 3  | 2  (from Fib(2) + Fib(1))      |
 | 2  | 1                              |
 | 1  | 1                              |
 --------------------------------------
```

### Tabulation (Bottom-Up Dynamic Programming)

Tabulation takes a more proactive approach, solving all related sub-problems right from the start, storing their results in a table, and building up the final solution from these results. It's like filling out a complex form, where you fill out all the individual sections (sub-problems) first, and finally use them to complete the entire form (main problem). If you were building a pyramid of blocks, a tabulation approach would have you systematically build up from the base.

In the tabulation approach, we systematically fill in the table from the smallest subproblems up to the problem of interest.

```
 Tabulation Table for Fibonacci Sequence:
 --------------------------------------
 | n  | Fib(n)                         |
 --------------------------------------
 | 1  | 1                              |
 | 2  | 1                              |
 | 3  | 2  (from Fib(2) + Fib(1))      |
 | 4  | 3  (from Fib(3) + Fib(2))      |
 | 5  | 5  (from Fib(4) + Fib(3))      |
 | 6  | 8  (from Fib(5) + Fib(4))      |
 | 7  | 13 (from Fib(6) + Fib(5))      |
 --------------------------------------
```

### Choosing Between Recursion and Tabulation

The choice between recursion and tabulation is often a matter of trade-offs. Recursion is usually simpler and more intuitive, but it can be slower for large inputs due to repeated calculations and function call overhead. Tabulation, on the other hand, can be faster and more efficient because it eliminates the need for recursion, but it can be less intuitive and requires understanding the problem thoroughly to figure out the correct sequence of solving sub-problems.

## Common terms made simple

### Recursion
Recursion is a way to solve problems by using a function that calls itself with a smaller problem. The function keeps breaking the problem into smaller pieces until it can solve the smallest problem. Then, it builds the answer from the smallest problems. Recursion is used for problems that have smaller, repeated problems, like the Fibonacci sequence or the Tower of Hanoi.

```
Factorial(5) = 5 * Factorial(4)
= 5 * (4 * Factorial(3))
= 5 * (4 * (3 * Factorial(2)))
= 5 * (4 * (3 * (2 * Factorial(1))))
= 5 * (4 * (3 * (2 * 1)))
= 120
```

#### Subset
A subset is a collection of elements from a larger set. Every set is considered a subset of itself, and the empty set is a subset of every set. Subsets are often used in combinatorial mathematics to describe the possible combinations of elements chosen from a larger set.

Example:

```
Set A = {1, 2, 3}

Subsets of A = { }, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}
```

#### Subarray
A subarray is a contiguous portion of an array or a sequence of elements within an array. A subarray is defined by its start and end indices and can be extracted from the original array using these indices.

Example:

```
Array A = [1, 2, 3, 4, 5]

Subarrays of A: [1], [1, 2], [1, 2, 3], [2], [2, 3], [2, 3, 4], [3], [3, 4], [3, 4, 5], [4], [4, 5], [5]
```

#### Substring
A substring is a contiguous sequence of characters within a string. A substring is defined by its start and end indices and can be extracted from the original string using these indices.

Example:

```
String S = "hello"

Substrings of S: "h", "he", "hel", "hell", "hello", "e", "el", "ell", "ello", "l", "ll", "llo", "l", "lo", "o"
```

#### Subsequence
A subsequence is a sequence of elements within a larger sequence (such as a string or an array) that can be extracted by deleting some of the elements in the original sequence. A subsequence doesn't have to be contiguous, unlike a substring or a subarray.

Example:

```
String S = "abc"

Subsequences of S: "", "a", "b", "c", "ab", "ac", "bc", "abc"
```

### Fibonacci Sequence
The Fibonacci sequence is a series of numbers where a number is the sum of the two preceding ones, starting with 0 and 1. It's a classic example of recursive algorithms and dynamic programming.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/fibonacci/)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/fibonacci/)

### Grid Traveler
Grid Traveler problem entails finding the total number of ways to traverse a grid (m x n) from the top-left to the bottom-right corner, provided you can only move right or down.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/grid_traveler)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/grid_traveler)

### Climbing stairs
The Climbing Stairs problem involves determining the number of distinct ways to reach the top of a staircase that has 'n' steps, with the condition that you can climb either 1, 2, or 3 steps at a time.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/climb_stairs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/climbing_stairs)

### Can Sum
The Can Sum problem involves determining if it's possible to achieve a target sum using any number of elements from a specific list of numbers. Each number from the list can be used multiple times.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_sum)

### How Sum
The How Sum problem extends the Can Sum problem by identifying which elements from the list can sum up to the target.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/how_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/how_sum)

### Best Sum
The Best Sum problem further extends the How Sum problem by finding the smallest combination of numbers that add up to exactly the target sum.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/best_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/best_sum)

### Can Construct
The Best Sum problem further extends the How Sum problem by finding the smallest combination of numbers that add up to exactly the target sum.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_construct)

### Count Construct
The Count Construct problem expands on the Can Construct problem by determining the number of ways a target string can be constructed using a list of substrings.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/count_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/count_construct)

### All Constructs
The All Constructs problem is a variation of the Count Construct problem, which identifies all the possible combinations of strings from a list that can be used to form the target string.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/all_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/all_construct)

### Coins
The Coins problem aims to find the minimum number of coins that make a given value, given an infinite supply of each of coin denominations.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/coin_change)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/coins)

### Longest common subsequence
The Longest Common Subsequence problem involves finding the longest subsequence that two sequences have in common.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_common_subsequence)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_common_subsequence)

### Longest increasing subarray
The Longest Increasing Subarray problem involves identifying the longest contiguous subarray in which the elements are strictly increasing.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_increasing_subarray)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_increasing_subarray)

### Knuth-Morris-Pratt
KMP is a pattern searching algorithm that searches for occurrences of a "word" within a main "text string". It uses preprocessing over the pattern to achieve linear time complexity.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/kmp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/kmp)

### Minimum insertions to form a palindrome
This problem involves finding the minimum number of insertions needed to transform a given string into a palindrome.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/minimum_insertions_for_palindrome)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/minimum_insertions_for_palindrome)
