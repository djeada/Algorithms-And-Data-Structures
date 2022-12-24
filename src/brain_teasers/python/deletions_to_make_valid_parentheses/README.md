## Minimum Number of Deletions to Make Parentheses Valid

This function is designed to solve the problem of determining the minimum number of deletions needed to make a string of parentheses valid. A string of parentheses is considered valid if it consists of pairs of opening and closing parentheses, with each opening parenthesis being matched with a corresponding closing parenthesis.

## Examples

```
Input: "()((())"
Output: 1
```

```
Input: "()(())"
Output: 0
```

## Approach

The function uses a stack to keep track of unmatched opening parentheses in the string. It begins by initializing an empty stack and a count of the number of deletions needed. It then loops through the string, character by character. If the current character is an opening parenthesis, it pushes it onto the stack. If the current character is a closing parenthesis, the function checks if the stack is empty. If it is, it increments the deletions count, as this closing parenthesis has no matching opening parenthesis. If the stack is not empty, the function pops the top element from the stack, effectively matching the closing parenthesis with an opening one. At the end of the loop, any remaining elements in the stack represent unmatched opening parentheses, so the function increments the deletions count by the number of elements in the stack.

## Complexity

The time complexity of the function is $O(n)$, where $n$ is the length of the input string. This is because the function processes each character in the string exactly once. The space complexity is also $O(n)$, as the stack can contain up to $n$ elements at any given time. This is because in the worst case, the stack will contain all of the opening parentheses in the string, if there are no closing parentheses or if all of the closing parentheses appear after all of the opening parentheses.