## Heap

A heap is a complete binary tree data structure that satisfies the heap property, which determines the order of the elements in the tree. There are two types of heaps: min-heaps and max-heaps. In a min-heap, the value of each element is greater than or equal to the value of its children, and in a max-heap, the value of each element is less than or equal to the value of its children. Heaps provide efficient operations for inserting and deleting elements, such as push and pop, and for accessing the minimum or maximum element, such as peek.

This Heap project is a Python implementation of a heap data structure, using a list to store the elements and providing methods for manipulating the heap. It has a default comparison function that determines the order of the elements in the heap based on their values. The project includes two subclasses of the Heap class: MinHeap and MaxHeap, which implement min-heaps and max-heaps, respectively.

## Interface

The Heap class has the following methods:

* `push(self, val)`: Inserts the element val into the heap.
* `pop(self)`: Removes and returns the minimum or maximum element of the heap, depending on the comparison function. If the heap is empty, raises an IndexError exception.
* `peek(self)`: Returns the minimum or maximum element of the heap, depending on the comparison function. If the heap is empty, raises an IndexError exception.
* `size(self)`: Returns the number of elements in the heap.
* `empty(self)`: Returns True if the heap is empty, False otherwise.
* `clear(self)`: Removes all elements from the heap.

## Demo

Here is an example of how to use the Heap class:

```python
from src.heap import Heap

# Create a new heap
h = Heap()

# Insert some elements
h.push(1)
h.push(2)
h.push(3)

# Print the heap
print(h)  # [1, 2, 3]

# Remove an element
h.pop()

# Print the heap again
print(h)  # [2, 3]

# Clear the heap
h.clear()

# Check if the heap is empty
print(h.empty())  # True
```
