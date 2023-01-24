
## Subarray Sum
This project contains a function that calculates the sum of all elements in a subarray of an input array. The start and end indices of the subarray are provided as arguments.

## Examples

```
Input: array=[1, 2, 3, 4], start=1, end=3
Output: 5
```

```
Input: array=[1, 2, 3, 4, 5, 6], start=2, end=5
Output: 12
```

## Approach

The function iterates through the subarray and adds the elements to a sum, which is returned at the end.

## Complexity

The time complexity of this function is $O(n)$, where $n$ is the number of elements in the subarray. The space complexity is $O(1)$, as the function only uses a single variable to store the sum.