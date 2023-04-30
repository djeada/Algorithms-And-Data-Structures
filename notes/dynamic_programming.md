## Dynamic Programming

Dynamic programming is a way to solve problems by breaking them into smaller parts, storing the answers to those smaller parts, and using those answers to solve bigger problems. It can make a problem faster to solve than trying every possible answer.

Dynamic programming works well for problems that can be solved by finding the best solution to smaller problems. This is especially helpful when the smaller problems are repeated, like in the Fibonacci sequence or the knapsack problem.

There are three main ways to use dynamic programming: brute force recursion, memoized recursion, and tabulation.

### Brute Force Recursion

Brute force recursion solves the problem by making a tree of smaller problems and using recursion. This can look simple, but it can be slow because the same smaller problems are solved many times.

### Memoized Recursion

Memoized recursion uses a map to store answers to smaller problems. This makes it faster because you don't have to solve the same problem again.

### Tabulation

Tabulation uses a table to solve the problem. It starts with the smallest problems and works its way up. This is faster, but you have to choose the order of solving the problems yourself.

### Why choose recursion over tabulation?

Recursion is often easier, but sometimes slower. When speed isn't important or the problem isn't too big, recursion is usually good enough.

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

#### Code examples

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/fibonacci/)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/fibonacci/)

### Grid Traveler
Find the number of ways to get to the bottom right corner of a grid, starting at the top left corner, given the size of the grid. You can only move right or down.

#### Code examples

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/grid_traveler)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/grid_traveler)

### Climbing stairs
Determine the number of ways to reach the top of a n-step staircase by taking 1, 2, or 3 steps at a time, starting from the bottom.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/climb_stairs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/climbing_stairs)

### Can Sum
Given a list of numbers and a target value, determine if it is possible to obtain the target value by selecting and adding one or more numbers from the list, potentially using the same number multiple times.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_sum)

### How Sum
If it is possible to obtain a given target value by selecting and adding one or more numbers from a list, determine which numbers should be chosen and in what combination to achieve the target value.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/how_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/how_sum)

### Best Sum
If it is possible to obtain a given target value by selecting and adding one or more numbers from a list, determine the smallest set of numbers that should be chosen to achieve the target value.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/best_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/best_sum)

### Can Construct
Given a list of strings and a target word, determine if it is possible to create the target word by concatenating one or more of the strings from the list, potentially using the same string multiple times.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_construct)

### Count Construct
If it is possible to create a target word by concatenating one or more strings from a given list, determine the number of possible sets of strings that can be chosen to construct the target word.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/count_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/count_construct)

### All Constructs
If it is possible to create a target word by concatenating one or more strings from a given list, determine the smallest set of strings that should be chosen to construct the target word.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/all_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/all_construct)

### Coins
Determine the minimum number of coins from a given set of denominations needed to reach a specific target amount.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/coin_change)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/coins)

### Longest common subsequence
Given an array, find the longest sequence of elements that is present in the array as a contiguous subsequence in multiple places.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_common_subsequence)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_common_subsequence)

### Longest increasing subarray
Given an array, find the longest contiguous subarray in which the elements are strictly increasing in value.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_increasing_subarray)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_increasing_subarray)

### Knuth-Morris-Pratt
Given a text and a pattern, use the Knuth-Morris-Pratt (KMP) algorithm to find the occurrences of the pattern within the text and return their starting indices.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/kmp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/kmp)

### Minimum insertions to form a palindrome
Given a string, determine the minimum number of characters that need to be inserted into the string in order to make it a palindrome.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/minimum_insertions_for_palindrome)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/minimum_insertions_for_palindrome)
