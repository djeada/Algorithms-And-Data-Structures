## Binary Tree Right Side View
This function is designed to solve the problem of finding the right-side view of a binary tree. The right-side view of a binary tree is a list of the values of all the nodes visible from the right side of the tree.

## Examples

Here are some examples of how the function can be used:
```
Input:

    1
   / \
  2   3
 /   / \
4   5   6

Output: [1, 3, 6]
```

```
Input:

      1
     / \
    2   3
   /     \
  4       5
 /         \
6           7

Output: [1, 3, 5, 7]
```

## Approach

The function uses a breadth-first search approach to traverse the tree and find the right-side view. It begins by initializing a queue with the root node and a result list. Then, it enters a loop that continues until the queue is empty. In each iteration of the loop, it removes the first node from the queue and checks if it is the last node in its level. If it is, its value is added to the result list. The function then checks if the node has a left child and, if it does, adds it to the queue. It also checks if the node has a right child and, if it does, adds it to the queue.

## Complexity

The time complexity of the function is $O(n)$, where $n$ is the number of nodes in the tree. This is because the function processes each node in the tree exactly once. The space complexity is also $O(n)$, as the queue can contain up to $n$ nodes at any given time.