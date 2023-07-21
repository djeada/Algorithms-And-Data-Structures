## RedBlackTree
The RedBlackTree class implements a red-black tree. A red-black tree is a self-balancing binary search tree. It is a binary search tree with the following properties:

* Every node is either red or black.
* The root node is black.
* Every leaf node (i.e. None) is black.
* If a node is red, then both its children are black.
* For each node, all paths from the node to descendant leaf nodes contain the same number of black nodes.

## Interface

The RedBlackTree class has the following methods:

* `void insert(const T &v)`: Inserts the element v into the tree.
* `void remove(const T &v)`: Removes the element v from the tree. If the element is not found in the tree, this method has no effect.
* `bool contains(const T &v)`: Returns true if the element v is found in the tree, false otherwise.
* `void clear()`: Removes all elements from the tree.
* `int height()`: Returns the height of the tree.
* `int size()`: Returns the number of elements in the tree.
* `bool empty()`: Returns true if the tree is empty, false otherwise.
* `std::vector<T> in_order_traversal() const`: Returns a vector containing the elements of the tree in in-order traversal order.
* `std::vector<T> pre_order_traversal() const`: Returns a vector containing the elements of the tree in pre-order traversal order.
* `std::vector<T> post_order_traversal() const`: Returns a vector containing the elements of the tree in post-order traversal order.

## Demo

Here is an example of how to use the RedBlackTree class:

```cpp
#include <iostream>
#include <vector>
#includesrc/red_black_tree.h"

using namespace std;

int main() {
  // Create a new red-black tree
  RedBlackTree<int> t;

  // Insert some elements
  t.insert(10);
  t.insert(20);
  t.insert(30);

  // Check if the tree contains an element
  cout << t.contains(20) << endl;  // 1

  // Print the tree in in-order traversal order
  vector<int> v = t.in_order_traversal();
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;  // 10 20 30

  // Clear the tree
  t.clear();

  // Check if the tree is empty
  cout << t.empty() << endl;  // 1

  return 0;
}
```