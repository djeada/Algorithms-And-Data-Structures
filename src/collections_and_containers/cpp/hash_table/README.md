## HashTable
A hash table is a data structure that stores (key, value) pairs and uses a hash function to map keys to indices in an array, allowing for efficient insertion, retrieval, and deletion of elements.

This HashTable project is a C++ implementation of a hash table data structure using a vector of shared pointers to vectors to store the (key, value) pairs and providing methods for manipulating the table. It has a default size of 10, but this can be changed when creating a HashTable instance.

## Interface

The HashTable class has the following methods:

* `void add(Key key, Value value)`: Adds the (key, value) pair to the table. If the key is already present in the table, it updates the value associated with the key.
* `Value get(Key key)`: Returns the value associated with the given key. If the key is not found in the table, it throws a std::out_of_range exception.
* `void remove(Key key)`: Removes the (key, value) pair with the given key from the table. If the key is not found in the table, this method has no effect.
* `bool contains(Key key)`: Returns true if the table contains the given key, false otherwise.
unsigned int size() const: Returns the number of (key, value) pairs in the table.
* `void clear()`: Removes all (key, value) pairs from the table.

## Demo

Here is an example of how to use the HashTable class:

```cpp
#include <iostream>
#includesrc/hash_table.h"

using namespace std;

int main() {
  // Create a new hash table
  HashTable<std::string, int> h([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  // Add some elements
  h["one"] = 1;
  h["two"] = 2;
  h["three"] = 3;

  // Get an element
  cout << h["one"] << endl; // 1

  // Get the size of the table
  cout << h.size() << endl; // 3

  // Check if the table contains a key
  cout << h.contains("one") << endl; // true

  // Remove an element
  h.remove("one");

  // Get the size of the table
  cout << h.size() << endl; // 2

  // Clear the table
  h.clear();

  // Get the size of the table
  cout << h.size() << endl; // 0
}

```
