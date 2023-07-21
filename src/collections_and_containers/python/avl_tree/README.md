## AvlTree

An AVL tree is a type of self-balancing binary search tree. It maintains a balance factor for each node, which is the difference in height between the left and right subtrees of that node. An AVL tree is considered balanced if the balance factor for every node is in the range [-1, 1]. This implementation provides methods for inserting and removing nodes, checking if the tree contains a given value, clearing the tree, and traversing the tree in different orders.

## Interface

The AvlTree class has the following methods:

* `insert(value)`: Inserts a new node with value value into the AVL tree.
* `remove(value)`: Removes the node with value value from the AVL tree.
* `contains(value)`: Returns True if the AVL tree contains a node with value value, and False otherwise.
* `clear()`: Removes all nodes from the AVL tree.
* `height()`: Returns the height of the AVL tree.
* `size()`: Returns the number of nodes in the AVL tree.
* `empty()`: Returns True if the AVL tree is empty, and False otherwise.
* `in_order_traversal()`: Returns a list of the values in the AVL tree, in in-order traversal order.
* `pre_order_traversal()`: Returns a list of the values in the AVL tree, in pre-order traversal order.
* `post_order_traversal()`: Returns a list of the values in the AVL tree, in post-order traversal order.

## Demo

Here is an example of how to use the AvlTree class:

```python
frosrc.avl_tree import AvlTree

# Create a new avl tree
tree = AvlTree()

# Insert some values
tree.insert(5)
tree.insert(3)
tree.insert(8)

# Check if the tree contains a given value
print(tree.contains(8))  # True
print(tree.contains(6))  # False

# Remove a value from the tree
tree.remove(8)
print(tree.contains(8))  # False

# Get the size of the tree
print(tree.size())  # 2

# Get the height of the tree
print(tree.height())  # 2

# Traverse the tree in different orders
print(tree.in_order_traversal())  # [3, 5]

# Clear the tree
tree.clear()
print(tree.size())  # 0
```
