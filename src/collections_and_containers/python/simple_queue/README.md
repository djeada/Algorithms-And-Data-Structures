## Queue

A queue is a linear data structure that follows the First In First Out (FIFO) principle, meaning that the first element added to the queue is the first one to be removed. It provides various operations for inserting, deleting, and accessing elements, such as enqueue, dequeue, and front.

This Queue project is a Python implementation of a queue data structure, using a list to store the elements and providing methods for manipulating the queue. The queue has a default maximum size of 10 elements, which is dynamically expanded as needed when inserting elements.

## Interface

The Queue class has the following methods:

* `enqueue(self, element)`: Inserts the element element at the end of the queue. If the queue is full, expands the queue to double its current size.
* `dequeue(self)`: Removes and returns the first element of the queue. If the queue is empty, returns None.
* `front(self)`: Returns the first element of the queue. If the queue is empty, raises an IndexError exception.
* `back(self)`: Returns the last element of the queue. If the queue is empty, raises an IndexError exception.
* `size(self)`: Returns the number of elements in the queue.
* `empty(self)`: Returns True if the queue is empty, False otherwise.
* `clear(self)`: Removes all elements from the queue.

## Demo

Here is an example of how to use the Queue class:

```python
from src.simple_queue import Queue

# Create a new queue
q = Queue()

# Insert some elements
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)

# Print the queue
print(q)  # [1, 2, 3]

# Remove an element
q.dequeue()

# Print the queue again
print(q)  # [2, 3]

# Clear the queue
q.clear()

# Check if the queue is empty
print(q.empty())  # True
```
