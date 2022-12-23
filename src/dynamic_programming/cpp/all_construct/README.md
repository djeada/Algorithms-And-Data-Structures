## All Construct

Given a target string and a word bank, find all possible combinations of words from the word bank that can be concatenated to form the target string.

## Examples

```
Input: target="purple", word_bank=["purp", "p", "ur", "le", "purpl"]
Output: [["purp", "le"], ["p", "ur", "p", "le"]]
```

```
Input: target="abcdef", word_bank=["ab", "abc", "cd", "def", "abcd", "ef", "c"]
Output: [["ab", "cd", "ef"], ["ab", "c", "def"], ["abc", "def"], ["abcd", "ef"]]
```

## Approach

Three different approaches have been implemented to solve this problem:

* `all_construct_basic`: This is a recursive approach where we try all possible combinations of words from the word bank for each prefix of the target string. For each prefix, we recurse on the remaining suffix and append the current word to the list of combinations for the prefix.
* `all_construct_memo`: This is an optimized version of the basic approach where we use memoization to avoid computing the same subproblems multiple times.
* `all_construct_table`: This is an iterative approach where we use a table to store the combinations for all prefixes of the target string. We iterate through the target string and for each prefix, we try all possible combinations of words from the word bank and update the table accordingly.

## Complexity

The complexity of the different solutions is as follows:

* `all_construct_basic`: The worst case complexity of this solution is $O(2^n)$ where n is the length of the target string. This is because, in the worst case, we may have to try all possible combinations of words for every prefix of the target string.
* `all_construct_memo`: The worst case complexity of this solution is $O(n^2)$ where n is the length of the target string. This is because, in the worst case, we may have to compute the combinations for every prefix of the target string once and store it in the memoization dict.
* `all_construct_table`: The worst case complexity of this solution is $O(n^2)$ where n is the length of the target string. This is because, in the worst case, we may have to try all possible combinations of words for every prefix of the target string and update the table accordingly.
