## Product of Array Except Self

An implementation of a function calculating the product of all elements in an array, except for the element at each index. The result is returned as a new array with the same length as the input array.

## Examples

```
Input: [1, 2, 3, 4]
Output: [24, 12, 8, 6]
```

```
Input: [1, 2, 0, 4]
Output: [0, 0, 8, 0]
```

```
Input: [4, 2, 1, 3]
Output: [6, 12, 24, 8]
```

## Approach

The function begins by initializing a result array with all elements equal to 1. It then iterates through the input array and calculates the product of all elements to the left of each index, storing the result in the corresponding element of the result array. Next, it iterates through the input array in reverse and calculates the product of all elements to the right of each index, updating the result array with the products.

## Complexity

The time complexity is $O(n)$ and a space complexity of $O(n)$, as it iterates through the input array twice and creates a new array with the same length as the input array.