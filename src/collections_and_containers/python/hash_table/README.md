## HashTable

A hash table is a data structure that is used to store key-value pairs. It uses a hash function to compute an index into an array in which an element will be inserted or searched. The efficiency of a hash table depends on two factors: the efficiency of the hash function and the load factor, which is the ratio of the number of elements in the table to the size of the array.

## Interface

The HashTable class has the following methods:

* `insert(key, value)`: Inserts the key-value pair into the hash table. If the key already exists, the value is updated.
* `remove(key)`: Removes the key-value pair from the hash table. If the key does not exist, raises a KeyError exception.
* `get(key)`: Returns the value associated with the key. If the key does not exist, raises a KeyError exception.
* `size(self)` -> int: Returns the number of elements in the hash table.
* `empty(self)` -> bool: Returns True if the hash table is empty, False otherwise.
* `clear(self)`: Removes all elements from the hash table.

## Demo

Here is an example of how to use the HashTable class:

```python
frosrc.hash_table import HashTable

# Create a new hash table
ht = HashTable(lambda key: sum(ord(c) for c in key))

# Insert some elements
ht.insert("foo", 1)
ht.insert("bar", 2)
ht.insert("baz", 3)

# Print the hash table
print(ht)  # {"foo": 1, "bar": 2, "baz": 3}

# Remove an element
ht.remove("bar")

# Print the hash table again
print(ht)  # {"foo": 1, "baz": 3}

# Clear the hash table
ht.clear()

# Check if the hash table is empty
print(ht.empty())  # True
```
