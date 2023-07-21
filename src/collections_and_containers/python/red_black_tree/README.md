## RedBlackTree

The RedBlackTree class implements a red-black tree. A red-black tree is a self-balancing binary search tree. It is a binary search tree with the following properties:

* Every node is either red or black.
* The root node is black.
* Every leaf node (i.e. None) is black.
* If a node is red, then both its children are black.
* For each node, all paths from the node to descendant leaf nodes contain the same number of black nodes.

## Interface

The RedBlackTree class has the following methods:

* `insert(value)`: Inserts a new node with value value into the red-black tree.
* `remove(value)`: Removes the node with value value from the red-black tree.
* `contains(value)`: Returns True if the red-black tree contains a node with value value, and False otherwise.
* `clear()`: Removes all nodes from the red-black tree.
* `height()`: Returns the height of the red-black tree.
* `size()`: Returns the number of nodes in the red-black tree.
* `empty()`: Returns True if the red-black tree is empty, and False otherwise.
* `in_order_traversal()`: Returns a list of the values in the red-black tree, in in-order traversal order.
* `pre_order_traversal()`: Returns a list of the values in the red-black tree, in pre-order traversal order.
* `post_order_traversal()`: Returns a list of the values in the red-black tree, in post-order traversal order.

## Demo

Here is an example of how to use the RedBlackTree class:

```python
frosrc.red_black_tree import RedBlackTree

# Create a new red-black tree
tree = RedBlackTree()

# Insert some values
tree.insert(5)
tree.insert(3)
tree.insert(8)
tree.insert(1)
tree.insert(4)
tree.insert(6)

# Check if the tree contains a given value
print(tree.contains(8))  # True
print(tree.contains(6))  # True

# Remove a value from the tree
tree.remove(8)

# Get the size of the tree
print(tree.size())  # 5

# Get the height of the tree
print(tree.height())  # 3

# Traverse the tree in different orders
print(tree.in_order_traversal())  # [1, 3, 4, 5, 6]
print(tree.pre_order_traversal())  # [5, 3, 1, 4, 6]
print(tree.post_order_traversal())  # [1, 4, 3, 6, 5]

# Clear the tree
tree.clear()

print(tree.size())  # 0
```
