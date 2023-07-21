## Heap
A heap is a complete binary tree that satisfies the heap property: the value of each node is greater than or equal to the values of its children (max-heap) or less than or equal to the values of its children (min-heap). Heaps are used to implement priority queues, where the element with the highest or lowest priority is always at the root of the tree.

This Heap project is a C++ implementation of a heap data structure using a vector to store the elements and providing methods for manipulating the heap. It also includes two subclasses: MinHeap and MaxHeap, which are specialized heap implementations for minimum and maximum values, respectively.

## Interface

The Heap class has the following methods:

* `void push(const T &val)`: Adds the element val to the heap.
* `T pop()`: Removes and returns the root element of the heap. If the heap is empty, it throws an out_of_range exception.
* `T peek()`: Returns the root element of the heap. If the heap is empty, it throws an out_of_range exception.
* `unsigned int size()`: Returns the number of elements in the heap.
* `bool empty()`: Returns true if the heap is empty, false otherwise.
* `bool isMaxHeap()`: Returns true if the heap is a max-heap, false otherwise.
* `bool isMinHeap()`: Returns true if the heap is a min-heap, false otherwise.

## Demo

Here is an example of how to use the Heap class:

```cpp
#include <iostream>
#includesrc/heap.h"

using namespace std;

int main() {
  // Create a new heap
  MaxHeap<int> h;

  // Push some elements
  h.push(1);
  h.push(2);
  h.push(3);

  // Pop an element
  std::cout << h.pop() << std::endl; // 3

  // Get the size of the heap
  std::cout << h.size() << std::endl; // 2

  // Check if the heap is empty
  std::cout << h.empty() << std::endl; // false

  // Peek the root element
  std::cout << h.peek() << std::endl; // 2

  // Check if the heap is a max-heap
  std::cout << h.isMaxHeap() << std::endl; // true

  // Check if the heap is a min-heap
  std::cout << h.isMinHeap() << std::endl; // false
}
```
