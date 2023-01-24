## Binary Search Tree to Double Linked List
This function is designed to convert a binary search tree (BST) to a double linked list. A double linked list is a linear data structure that consists of a set of nodes, each containing a value and pointers to the previous and next nodes.

## Examples


```
Input:

    4
   / \
  2   5
 / \
1   3

Output:

1 <-> 2 <-> 3 <-> 4 <-> 5
```

```
Input:

      5
     / \
    3   8
   /   / \
  2   6   9
 /     \
1       7

Output:

1 <-> 2 <-> 3 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9
```

## Approach

The function uses an in-order traversal of the BST to convert it to a double linked list. It begins by creating an empty double linked list and a stack to store the nodes. It then sets the current node to the root of the BST and enters a loop that continues until the stack is empty and the current node is None. In each iteration, the function checks if the current node is None. If it is, it pops the top node from the stack, adds it to the double linked list, and sets the current node to the right child of the popped node. If the current node is not None, the function pushes it onto the stack and sets the current node to the left child.

## Complexity

The time complexity of the function is $O(n)$, where $n$ is the number of nodes in the BST. This is because the function processes each node in the BST exactly once. The space complexity is also $O(n)$, as the stack can contain up to $n$ nodes at any given time.
