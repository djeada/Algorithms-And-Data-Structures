## Vector

A vector is a dynamic array data structure that allows efficient insertion and deletion of elements at the end of the array, as well as random access to the elements. It grows and shrinks automatically as elements are added or removed.

This Vector project is a Python implementation of a vector data structure, using a list to store the elements and providing methods for manipulating the vector. It has a default capacity of 10000 elements, which can be changed when creating a vector instance.

## Interface

The Vector class has the following methods:

* `size(self)` -> int: Returns the number of elements in the vector.
* `empty(self)` -> bool: Returns True if the vector is empty, False otherwise.
* `front(self)` -> Any: Returns the first element of the vector. If the vector is empty, raises an IndexError exception.
* `back(self)` -> Any: Returns the last element of the vector. If the vector is empty, raises an IndexError exception.
* `push_back(self, value: Any)`: Appends the element value to the end of the vector

## Demo

Here is an example of how to use the Vector class:

```python
frosrc.vector import Vector

# Create a new vector
v = Vector()

# Insert some elements
v.push_back(1)
v.push_back(2)
v.push_back(3)

# Print the vector
print(v)  # [1, 2, 3]

# Remove an element
v.pop_back()

# Print the vector again
print(v)  # [1, 2]

# Clear the vector
v.clear()

# Check if the vector is empty
print(v.empty())  # True
```
