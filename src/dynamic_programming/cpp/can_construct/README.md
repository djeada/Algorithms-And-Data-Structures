## Can Construct
Given a target string target and a list of strings word_bank, the goal is to determine if it is possible to concatenate elements from word_bank to form the target string.

## Examples

```
Input: target="thehat", word_bank=["the", "hat"]
Output: True

Explanation: The target string can be constructed by concatenating the strings "the" and "hat" from the word bank.
```

```
Input: target="robotoflove", word_bank=["robot", "of", "lore"]
Output: False

Explanation: The target string cannot be constructed by concatenating elements from the word bank.
```

## Approach 

Three different functions have been implemented to solve this problem:

* `can_construct_basic`: This function uses a recursive approach to check if it is possible to concatenate elements from word_bank to form the target string. It starts by checking if the target is an empty string (in which case it returns True). If it is not empty, it checks if any of the recursive calls to itself using the target with the first word removed returns True.
* `can_construct_memo`: This function is similar to can_construct_basic, but it includes a memoization step to store the results of recursive calls and avoid calculating them multiple times. This improves the performance of the function by reducing the number of recursive calls.
* `can_construct_table`: This function uses a dynamic programming approach to solve the problem. It creates a table of Booleans with length $len(target) + 1$, initialized to False, and sets the first element to True. Then, it iterates over the table and, for each True element, sets the value of the element at index $i + len(word)$ (where i is the current index and word is an element in word_bank) to True if `target[i : i + len(word)]` is equal to word. Finally, it returns the value of the last element in the table, which will be True if it is possible to concatenate elements from word_bank to form the target string and False otherwise.

## Complexity

The complexity of the different solutions is as follows:

* `can_construct_basic`: This function has a time complexity of $O(2^n)$, where $n$ is the length of word_bank, because it makes two recursive calls for each element in word_bank. It has a space complexity of $O(n)$, because the call stack grows by $n$ at each recursive call.
* `can_construct_memo`: This function has a time complexity of $O(n * len(target))$, where $n$ is the length of word_bank, because it iterates over word_bank once for each character of the target. It has a space complexity of $O(n * len(target))$, because it stores the results of the recursive calls in a dictionary with $n * len(target)$ elements.
* `can_construct_table`: This function has a time complexity of $O(n * len(target))$, where $n$ is the length of word_bank, because it iterates over the elements in word_bank once for each character of the target. It has a space complexity of $O(len(target))$, because it creates a table with len(target) elements.