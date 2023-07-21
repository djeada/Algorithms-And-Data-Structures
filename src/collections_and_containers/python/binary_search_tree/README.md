## BinarySearchTree

A binary search tree (BST) is a type of tree-based data structure that stores data in a sorted, ordered fashion such that for any given node, the value stored in that node is greater than the values in its left child and less than the values in its right child. This implementation provides methods for inserting and removing nodes, checking if the tree contains a given value, clearing the tree, and traversing the tree in different orders.

## Interface

The BinarySearchTree class has the following methods:

* `insert(v)`: Inserts a new node with value v into the BST.
* `remove(v)`: Removes the node with value v from the BST.
* `contains(v)`: Returns True if the BST contains a node with value v, and False otherwise.
* `clear()`: Removes all nodes from the BST.
* `height()`: Returns the height of the BST.
* `size()`: Returns the number of nodes in the BST.
* `empty()`: Returns True if the BST is empty, and False otherwise.
* `in_order_traversal()`: Returns a list of the values in the BST, in in-order traversal order.
* `pre_order_traversal()`: Returns a list of the values in the BST, in pre-order traversal order.
* `post_order_traversal()`: Returns a list of the values in the BST, in post-order traversal order.

## Demo

Here is an example of how to use the BinarySearchTree class:

```python
frosrc.binary_search_tree import BinarySearchTree

# Create a new binary search tree
tree = BinarySearchTree()

# Insert some values
tree.insert(5)
tree.insert(3)
tree.insert(8)
tree.insert(1)
tree.insert(4)
tree.insert(7)
tree.insert(10)

# Check if the tree contains a given value
print(tree.contains(8))  # True
print(tree.contains(6))  # False

# Remove a value from the tree
tree.remove(8)
print(tree.contains(8))  # False

# Get the size of the tree
print(tree.size())  # 6

# Get the height of the tree
print(tree.height())  # 3

# Traverse the tree in different orders
print(tree.in_order_traversal())  # [1, 3, 4, 5, 7, 10]
print(tree.pre_order_traversal())  # [5, 3, 1, 4, 8, 7, 10]
print(tree.post_order_traversal())  # [1, 4, 3, 7, 10, 8, 5]

# Clear the tree
tree.clear()
print(tree.size())  # 0
```
