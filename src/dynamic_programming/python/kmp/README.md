## Knuth-Morris-Pratt Algorithm

Given a string text and a pattern pattern, the task is to find all the occurrences of pattern in text.

## Examples

```
Input: text="abcdefghijklmnopqrstuvwxyz", pattern="bc"
Output: [1]
Explanation: The pattern "bc" occurs once in text, at index 1.
```

```
Input: text="abcabcabcabc", pattern="abc"
Output: [0, 3, 6, 9]
Explanation: The pattern "abc" occurs four times in text, at indices 0, 3, 6, and 9.
```

## Approach

The implemented solution uses the Knuth-Morris-Pratt (KMP) algorithm to find the occurrences of pattern in text. The algorithm first preprocesses the pattern by calculating the longest prefix and suffix that are also a prefix of the pattern. It then uses this information to skip comparisons when searching for the pattern in the text, reducing the time complexity.

## Complexity

The time complexity of the implemented solution is $O(n + m)$, where n is the length of text and m is the length of pattern. The space complexity is $O(m)$, since the array used to store the longest prefix and suffix has a size of m.