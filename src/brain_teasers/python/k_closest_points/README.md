## K Closest Points to Origin
This function is designed to find the *K* closest points to the origin $(0, 0)$ in a list of points.

## Examples

```
Input: points=[(1, 2), (3, 4), (-1, -2), (-3, -4)], K=2
Output: [(1, 2), (-1, -2)]
```

```
Input: points=[(1, 1), (1, 2), (3, 4), (-1, -2), (-3, -4)], K=3
Output: [(1, 1), (1, 2), (-1, -2)]
```

## Approach
The function calculates the distance of each point from the origin using the Pythagorean theorem, and then sorts the points by their distance from the origin. It then returns the first K points in the sorted list.

## Complexity

The time complexity of the function is $O(n\log n)$, where $n$ is the length of the input list points. This is because the function uses the sort() function to sort the list of distances, which has a time complexity of $O(n\log n)$. The space complexity is $O(n)$, as the function creates a new list of distances with the same length as the input list.