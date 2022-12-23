## Minimum Insertions for Palindrome

Given a string s, the task is to find the minimum number of insertions needed to make the string a palindrome.

## Examples

```
Input: s = "aa"
Output: 0
Explanation: The string is already a palindrome.
```

```
Input: s = "abcd"
Output: 3
Explanation: The string can be converted to "**dcb**abcd" by inserting 3 characters.
```

## Approach

Three different approaches have been implemented to solve this problem:

* `minimum_insertions_for_palindrome_basic()`: This is a recursive function that uses a helper function to find the minimum number of insertions needed. It starts at the beginning and end of the string, and compares the characters at these positions. If they are the same, it moves on to the next pair of characters. If they are different, it inserts a character and continues the comparison.

* `minimum_insertions_for_palindrome_memo()`: This is similar to the first approach, but it uses memoization to avoid recalculating the same subproblems.

* `minimum_insertions_for_palindrome_tab()`: This is a dynamic programming approach that uses a table to store the results of subproblems. It starts by filling the table with the minimum number of insertions needed for substrings of length 1 and 2, and then uses these values to calculate the minimum number of insertions needed for longer substrings.

## Complexity

* The time complexity of the first two approaches is $O(n^2)$, since they both consider every possible substring of the input string. The space complexity is also $O(n^2)$, since the helper function in the first approach and the memoization table in the second approach both use an array of size $n^2$ to store the results of subproblems.
* The time complexity of the third approach is $O(n^2)$, since it considers every possible substring of the input string. The space complexity is $O(n^2)$, since the table used to store the results of subproblems has a size of $n^2$.
