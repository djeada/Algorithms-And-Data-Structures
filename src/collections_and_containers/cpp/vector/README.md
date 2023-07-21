## Vector
A vector is a dynamic array data structure that allows efficient insertion and deletion of elements at the end of the array, as well as random access to the elements. It grows and shrinks automatically as elements are added or removed.

This Vector project is a C++ implementation of a vector data structure, using an array to store the elements and providing methods for manipulating the vector. It has a default capacity of 10000 elements, which can be changed when creating a vector instance.

## Interface

The Vector class has the following methods:

* `int size()`: Returns the number of elements in the vector.
* `bool empty()`: Returns true if the vector is empty, false otherwise.
* `T &front()`: Returns a reference to the first element of the vector. If the vector is empty, it throws an out_of_range exception.
* `T &back()`: Returns a reference to the last element of the vector. If the vector is empty, it throws an out_of_range exception.
* `void push_back(const T &value)`: Appends the element value to the end of the vector.
* `T pop_back()`: Removes the last element of the vector and returns it. If the vector is empty, it throws an out_of_range exception.
* `void resize(unsigned int size)`: Resizes the vector to have the specified number of elements. If the new size is larger than the current size, the new elements are default-initialized.
* `void clear()`: Removes all elements from the vector.

The Vector class also has a nested type iterator, which is a pointer to an element of type T. You can use the iterator type to traverse the elements of the vector using the begin() and end() methods.

## Demo

Here is an example of how to use the Vector class:

```cpp
#include <iostream>
#includesrc/vector.h"

using namespace std;

int main() {
  // Create a new vector
  Vector<int> v;

  // Insert some elements
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // Print the vector
  for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
  }
```
