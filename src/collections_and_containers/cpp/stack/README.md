## Stack

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. It allows elements to be added (pushed) and removed (popped) from the top of the stack.

This Stack project is a C++ implementation of a stack data structure using an array to store the elements and providing methods for manipulating the stack.

## Interface

The Stack class has the following methods:
* `T pop()`: Removes and returns the element at the top of the stack. If the stack is empty, it throws an out_of_range exception.
* `void push(T element)* `: Adds the element element to the top of the stack.
* `T top()`: Returns the element at the top of the stack. If the stack is empty, it throws an out_of_range exception.
* `int size()`: Returns the number of elements in the stack.
* `bool isEmpty()`: Returns true if the stack is empty, false otherwise.

## Demo

Here is an example of how to use the Stack class:

```cpp
#include <iostream>
#includesrc/stack.h"

using namespace std;

int main() {
  // Create a new stack
  Stack<int> s;

  // Push some elements
  s.push(1);
  s.push(2);
  s.push(3);

  // Print the stack
  while (!s.isEmpty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;

  return 0;
}
```