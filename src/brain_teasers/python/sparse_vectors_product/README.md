## Sparse Vectors Product
A function that calculates the product of two sparse vectors represented as dictionaries. A sparse vector is a vector with mostly zero elements, so it is stored as a dictionary with the non-zero element indices as keys and their corresponding values as the values.

## Examples

```
Input: v1 = {0: 1, 2: 3}, v2 = {1: 5, 2: 4}
Output: 12
```

```
Input: v1 = {0: 3, 3: 1}, v2 = {1: 5, 2: 4}
Output: 0
```

## Approach

The function initializes the product to 0 and iterates through the elements of the first vector. For each element, if the index is also present in the second vector, the product of the values is added to the overall product.

## Complexity

The time complexity is $O(n)$, where $n$ is the number of elements in the first vector, since the function iterates through all the elements of the first vector. The space complexity is $O(1)$, since the function does not create any additional data structures.