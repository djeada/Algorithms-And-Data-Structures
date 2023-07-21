## Stack

A stack is a linear data structure that follows the Last In First Out (LIFO) principle, meaning that the last element added to the stack is the first one to be removed. It provides various operations for inserting, deleting, and accessing elements, such as push, pop, and top.

This Stack project is a Python implementation of a stack data structure, using a list to store the elements and providing methods for manipulating the stack. It has a default maximum size of 1000 elements, which can be changed when creating a stack instance.

## Interface

The Stack class has the following methods:

* `empty(self)`: Returns True if the stack is empty, False otherwise.
* `pop(self)`: Removes and returns the top element of the stack. If the stack is empty, raises an IndexError exception.
* `push(self, data)`: Inserts the element data at the top of the stack. If the stack is full, raises an IndexError exception.
* `top(self)`: Returns the top element of the stack. If the stack is empty, raises an IndexError exception.
* `size(self)`: Returns the number of elements in the stack.

## Demo

Here is an example of how to use the Stack class:

```python
frosrc.stack import Stack

# Create a new stack with a maximum size of 5 elements
s = Stack(max_size=5)

# Push some elements
s.push(1)
s.push(2)
s.push(3)

# Check the top element
print(s.top())  # 3

# Pop an element
print(s.pop())  # 3

# Check the size of the stack
print(s.size())  # 2

# Clear the stack
s.clear()

# Check if the stack is empty
print(s.empty())  # True

```
