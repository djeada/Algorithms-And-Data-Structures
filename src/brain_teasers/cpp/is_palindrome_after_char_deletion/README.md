## Is Palindrome After Character Deletion
This function is designed to determine whether a given string can be made into a palindrome by deleting at most one character.

## Examples


```
Input: "racecar"
Output: True
```

```
Input: "hello"
Output: False
```
## Approach

The function uses two pointers, one at the beginning and one at the end of the string, to compare characters from opposite ends of the string. If the characters are the same, the pointers are moved inward. If the characters are different, the function checks whether deleting one of the characters will create a palindrome. If it does, the pointer corresponding to the deleted character is moved inward. If deleting either character does not create a palindrome, the function returns False. If the pointers meet in the middle of the string, the function returns True.

## Complexity

The time complexity of the function is $O(n)$, where $n$ is the length of the input string. This is because the function processes each character in the string exactly once. The space complexity is $O(1)$, as the function only uses a constant amount of space regardless of the size of the input string.
