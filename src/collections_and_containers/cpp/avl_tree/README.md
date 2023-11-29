## AvlTree
An AVL tree is a self-balancing binary search tree data structure that stores (key, value) pairs and allows for efficient insertion, retrieval, and deletion of elements. It is called an "AVL tree" because it was invented by Georgy Adelson-Velsky and Evgenii Landis in 1962. An AVL tree is a binary search tree that maintains the balance property: for every node in the tree, the height of the left and right subtrees differ by at most 1. This balance property allows for efficient search and insertion operations in the tree.

This AvlTree project is a C++ implementation of an AVL tree data structure using unique pointers to store the nodes and providing methods for manipulating the tree.

## Interface

The AvlTree class has the following methods:

* `void insert(const T &v)`: Inserts the element v into the tree. If the element is already present in the tree, this method has no effect.
* `void remove(const T &v)`: Removes the element v from the tree. If the element is not present in the tree, this method has no effect.
* `bool contains(const T &v)`: Returns true if the tree contains the element v, false otherwise.
* `void clear()`: Removes all elements from the tree.
* `int height()`: Returns the height of the tree (the maximum depth of any node). An empty tree has a height of 0.
* `int size()`: Returns the number of elements in the tree.
* `bool empty()`: Returns true if the tree is empty, false otherwise.
* `std::vector<T> in_order_traversal() const`: Returns a vector containing the elements of the tree in in-order traversal order (left subtree, root, right subtree).
* `std::vector<T> pre_order_traversal() const`: Returns a vector containing the elements of the tree in pre-order traversal order (root, left subtree, right subtree).
* `std::vector<T> post_order_traversal() const`: Returns a vector containing the elements of the tree in post-order traversal order (left subtree, right subtree, root).

## Demo

Here is an example of how to use the AvlTree class:

```cpp
#include <iostream>
#include "src/avl_tree.h"

using namespace std;

int main() {
  // Create a new AVL tree
  AvlTree<int> t;

  // Add some elements
  t.insert(1);
  t.insert(2);
  t.insert(3);

  // Get the size of the tree
  cout << t.size() << endl; // 3

  // Check if the tree contains an element
  cout << t.contains(1) << endl; // true

  // Remove an element
  t.remove(1);

  // Get the size of the tree
  cout << t.size() << endl; // 2

  // Clear the tree
  t.clear();

  // Get the size of the tree
  cout << t.size() << endl; // 0
}
```
