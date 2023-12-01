## LinkedList
A linked list is a linear data structure that consists of a sequence of nodes, where each node stores a reference to its next node. Linked lists allow efficient insertion and deletion of elements, but do not provide constant-time access to individual elements like arrays do.

This LinkedList project is a C++ implementation of a linked list data structure using unique pointers to store the nodes and providing methods for manipulating the list.

## Interface

The LinkedList class has the following methods:

* `void push_back(const T &v)`: Adds the element v to the end of the list.
* `void push_front(const T &v)`: Adds the element v to the front of the list.
* `void pop_back()`: Removes the element at the end of the list. If the list is empty, it throws an out_of_range exception.
* `void pop_front()`: Removes the element at the front of the list. If the list is empty, it throws an out_of_range exception.
* `T &front()`: Returns a reference to the element at the front of the list. If the list is empty, it throws an out_of_range exception.
* `T &back()`: Returns a reference to the element at the end of the list. If the list is empty, it throws an out_of_range exception.
* `bool empty()`: Returns true if the list is empty, false otherwise.
* `void clear()`: Removes all elements from the list.
* `int size()`: Returns the number of elements in the list.
* `void remove(const T &v)`: Removes the first occurrence of the element v in the list. If the element is not found in the list, this method has no effect.

## Demo

Here is an example of how to use the LinkedList class:

```cpp
#include <iostream>
#include "src/linked_list.h"

using namespace std;

int main() {
  // Create a new linked list
  LinkedList<int> l;

  // Push some elements
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  // Pop an element
  l.pop_back();

  // Get the front element
  cout << l.front() << endl; // 1

  // Get the back element
  cout << l.back() << endl; // 2

  // Get the size of the list
  cout << l.size() << endl; // 2

  // Check if the list is empty
  cout << l.empty() << endl; // false

  // Remove an element
  l.remove(1);

  // Get the size of the list
  cout << l.size() << endl; // 1

  // Clear the list
  l.clear();

  // Check if the list is empty
  cout << l.empty() << endl; // true

  return 0;
}
```
