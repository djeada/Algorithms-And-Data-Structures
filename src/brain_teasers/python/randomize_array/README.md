## Randomize Array

A function that takes an array as input and returns a randomly shuffled version of the array.

## Examples

```
Input: [1, 2, 3, 4, 5]
Output: [2, 3, 5, 4, 1]
```

## Approach

This function uses the Fisher-Yates shuffle algorithm to randomly shuffle the input array. The algorithm works by iterating through the array in reverse and swapping each element with a randomly selected element from the subarray to the left of the current element.

## Complexity

The time complexity of this function is $O(n)$, as it iterates through the input array once. The space complexity is $O(1)$, as it only requires a constant amount of additional space.
