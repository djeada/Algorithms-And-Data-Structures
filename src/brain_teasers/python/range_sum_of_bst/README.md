## Range Sum of BST

This function calculates the sum of all values in a binary search tree that fall within a given range, L and R.

## Examples

```
Input Tree:
    10
   /  \
  5   15
 / \    \
3   7    18

L = 7
R = 15
Output: 32

Explanation:

The root node's value is 10. The left subtree has values 5, 3, and 7, and the right subtree has values 15 and 18.
The range sum is the sum of all values in the left and right subtrees that fall within the range [7, 15], which is 32.
```

```
Input Tree:
    10
   /  \
  5   15
 / \   / \
3   7 13  18
/   /
1   6

L = 6
R = 10
Output: 23

Explanation:

The root node's value is 10. The left subtree has values 5, 3, 7, 1, and 6, and the right subtree has values 15, 13, and 18.
The range sum is the sum of all values in the left and right subtrees that fall within the range [6, 10], which is 23.
```

## Approach

The function uses a recursive approach, where the base case is when the root is None (in which case it returns 0). If the root's value is outside the range, it returns the range sum of the left or right subtree (whichever is in range). Otherwise, it returns the root's value plus the range sum of the left and right subtrees.

## Complexity

The time complexity of this function is $O(n)$, where $n$ is the number of nodes in the tree. This is because the function needs to visit every node in the tree in order to calculate the range sum. The space complexity is also $O(n)$, as the function uses a recursive approach and the maximum depth of the recursion tree is equal to the height of the tree.
