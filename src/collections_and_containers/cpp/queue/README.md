## Queue
A queue is a linear data structure that follows the First In First Out (FIFO) principle. It allows elements to be added (enqueued) to the end of the queue and removed (dequeued) from the front of the queue.

This Queue project is a C++ implementation of a queue data structure using an array to store the elements and providing methods for manipulating the queue.

## Interface

The Queue class has the following methods:

* `enqueue(T element)`: Adds the element element to the end of the queue.
* `T dequeue()`: Removes and returns the element at the front of the queue. If the queue is empty, it throws an out_of_range exception.
* `T front()`: Returns the element at the front of the queue. If the queue is empty, it throws an out_of_range exception.
* `T back()`: Returns the element at the end of the queue. If the queue is empty, it throws an out_of_range exception.
* `int size()`: Returns the number of elements in the queue.
* `bool isEmpty()`: Returns true if the queue is empty, false otherwise.

## Demo

Here is an example of how to use the Queue class:

```cpp
#include <iostream>
#include "src/queue.h"

using namespace std;

int main() {
  // Create a new queue
  Queue<int> q;

  // Enqueue some elements
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  // Dequeue an element
  cout << q.dequeue() << endl; // 1

  // Get the front element
  cout << q.front() << endl; // 2

  // Get the back element
  cout << q.back() << endl; // 3

  // Get the size of the queue
  cout << q.size() << endl; // 2

  // Check if the queue is empty
  cout << q.isEmpty() << endl; // false

  return 0;
}
```
