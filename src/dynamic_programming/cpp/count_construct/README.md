## Count Construct

Given a target string and a list of words, the task is to find the number of ways the target string can be constructed by concatenating the words from the list in any order.

## Examples

```
Input: target="catsanddog", word_bank=["cat", "cats", "and", "sand", "dog"]
Output: 2
Explanation: The target string "catsanddog" can be constructed by concatenating "cats" and "and" followed by "dog", or by concatenating "cat" and "sand" followed by "dog".
```

```
Input: target="pineapple", word_bank=["apple", "pine", "robot"]
Output: 1
Explanation: The target string "pineapple" can be constructed by concatenating "pine" and "apple".
```

## Approach 

Three different approaches have been implemented to solve this problem:

* `count_construct_basic()`: This is a recursive function that finds the number of ways to construct the target string by trying each word in the word bank and recursively calling the function with the remainder of the target string.
* `count_construct_memo()`: This function uses memoization to store the results of subproblems and avoid recalculating them. It works similarly to the `count_construct_basic()` function, but it uses a dictionary to store the results of subproblems so that they can be reused in future recursive calls.
* `count_construct_table()`: This function uses dynamic programming to store the results of subproblems in a table.

## Complexity
The complexity of the three different approaches are as follows:

* `count_construct_basic()`: The time complexity of this function is $O(n^2)$ where n is the length of the target string. This is because the function makes a recursive call for each word in the word bank and the length of the target string decreases by the length of the word for each recursive call. The space complexity is $O(n)$ because of the recursive call stack.

* `count_construct_memo()`: The time complexity of this function is $O(n^2)$ where n is the length of the target string. This is because the function makes a recursive call for each word in the word bank and the length of the target string decreases by the length of the word for each recursive call. The space complexity is $O(n)$ because of the dictionary used to store the results of subproblems.

* `count_construct_table()`: The time complexity of this function is $O(n^2)$ where n is the length of the target string. This is because the function uses a nested loop to iterate over the target string and the word bank. The space complexity is $O(n)$ because of the table used to store the results of subproblems.