## Pattern Matching

Given a string string and a pattern pattern consisting of lowercase English letters, determine whether string follows the pattern. The letters in pattern can be mapped to non-empty substrings of string.

Example 1:

```
string = "redblueredblue"
pattern = "abab"
```

In this example, the string follows the pattern represented by pattern. The function will find that the following mappings work:

* `a` maps to red
* `b` maps to blue


Example 2:

```
string = "abcdefg"
pattern = "aa"
```

In this example, the string does not follow the pattern represented by pattern. The function will try to map the character `a` in pattern to a substring of string, but it will not be able to find a mapping that works, because the character `a` must be mapped to a non-empty substring of string, and there is no non-empty substring of string that starts with `a` and also contains the character `a`.

## Approach

The function implements a depth-first search (DFS) algorithm to check whether string follows the pattern represented by pattern. The DFS algorithm works by recursively trying all possible substrings of string that can be mapped to each character in the pattern string.

At each step, the function checks if the current character of the pattern string has already been mapped to a substring of string. If it has, it checks if the substring to which it is mapped matches the corresponding substring of string, and if it does, it continues with the next character in the pattern string. If it has not been mapped, it tries all possible substrings of string that start at the current position, and maps the current character of the pattern string to each of these substrings in turn, before checking if the pattern matches the string with the new mapping. If the function reaches the end of the pattern string and has not found a mapping that works, it returns False, otherwise it returns True.

## Time and Space Complexity

The time complexity of the function is $O(n^2 * m)$, where $n$ is the length of string and $m$ is the length of pattern. This is because the function tries all possible substrings of string for each character in the pattern string, and the length of each substring is at most $n$.

The space complexity of the function is $O(m)$, because the mapping dictionary used to store the mappings between the characters in pattern and the substrings in string has at most m elements.