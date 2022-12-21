## BinarySearchTree
A binary search tree (BST) is a data structure that stores (key, value) pairs and allows for efficient insertion, retrieval, and deletion of elements. It is called a "binary search tree" because each node has at most two children and the keys in the left subtree of a node are less than the key of the node, while the keys in the right subtree are greater than the key of the node.

This BinarySearchTree project is a C++ implementation of a binary search tree data structure using unique pointers to store the nodes and providing methods for manipulating the tree.

## Interface

The BinarySearchTree class has the following methods:

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

Here is an example of how to use the BinarySearchTree class:

```cpp
#include <iostream>
#include "src/binary_search_tree.h"

using namespace std;

int main() {
  // Create a new BinarySearchTree
  BinarySearchTree<int> bst;

  // Insert some elements
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);

  // Get the size of the tree
  cout << bst.size() << endl; // 3

  // In-order traversal
  vector<int> in_order = bst.in_order_traversal();
  for (int i : in_order) {
    cout << i << " "; // 3 5 7
  }

  // Pre-order traversal
  vector<int> pre_order = bst.pre_order_traversal();
  for (int i : pre_order) {
    cout << i << " "; // 5 3 7
  }

  // Post-order traversal
  vector<int> post_order = bst.post_order_traversal();
  for (int i : post_order) {
    cout << i << " "; // 3 7 5
  }

  // Check if the tree contains an element
  cout << bst.contains(5) << endl; // true

  // Remove an element
  bst.remove(5);

  // Get the size of the tree
  cout << bst.size() << endl; // 2

  // Clear the tree
  bst.clear();

  return 0;
}

```
