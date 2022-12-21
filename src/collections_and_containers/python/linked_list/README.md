## LinkedList

This LinkedList project is a Python implementation of a singly-linked list, which means that each element has a "next" link to the following element. It provides various methods for manipulating the list, such as inserting and deleting elements, as well as accessing and querying the list.

## Interface

The LinkedList class has the following methods:

* `push_back(v)`: Appends the element v to the end of the list.
* `push_front(v)`: Inserts the element v at the beginning of the list.
* `pop_back()`: Removes and returns the last element of the list.
* `pop_front()`: Removes and returns the first element of the list.
* `front()`: Returns the first element of the list.
* `back()`: Returns the last element of the list.
* `empty()`: Returns True if the list is empty, False otherwise.
* `clear()`: Removes all elements from the list.
* `size()`: Returns the number of elements in the list.
* `remove(v)`: Removes the first occurrence of the element v from the list.

## Demo

Here is an example of how to use the LinkedList class:

```python
from src.linked_list import LinkedList

# Create a new linked list
lst = LinkedList()

# Insert some elements
lst.push_back(1)
lst.push_back(2)
lst.push_front(3)

# Print the list
print(lst)  # [3, 1, 2]

# Remove an element
lst.remove(1)

# Print the list again
print(lst)  # [3, 2]

# Clear the list
lst.clear()

# Check if the list is empty
print(lst.empty())  # True
```
