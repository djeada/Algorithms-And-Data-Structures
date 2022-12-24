## Lowest Common Ancestor

This function finds the lowest common ancestor (LCA) of two nodes in a binary tree, given the values of the nodes and the root of the tree. The LCA is defined as the lowest node in the tree that has both nodes as descendants.

## Examples

```
Input Tree:
    3
   / \
  5   1
 / \ / \
6  2 0  8
  / \
 7   4

Input Nodes: 7, 4

Output: 2
```

## Approach

The function uses a recursive approach to search for the nodes with values p_val and q_val in the tree. If both nodes are found in the same subtree, then their LCA must be in that subtree. If they are found in different subtrees, then the root of the tree must be their LCA.

## Complexity

The time complexity of the function is $O(n)$, where $n$ is the number of nodes in the tree. This is because the function performs a single pass through the tree and visits each node once. The space complexity is also $O(n)$, as the function uses recursion and the call stack may require up to $O(n)$ space.