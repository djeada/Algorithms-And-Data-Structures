## Design LRU Cache
This is a class that implements a Least Recently Used (LRU) cache. The cache has a fixed capacity and stores key-value pairs. When the cache is full and a new key-value pair is added, the least recently used pair is evicted to make room for the new one.

## Examples

Here are some examples of how the class can be used:

```python
cache = LRUCache(2)

cache.put(1, 1)
cache.put(2, 2)
assert cache.get(1) == 1   # returns 1

cache.put(3, 3)              # evicts key 2
assert cache.get(2) == -1   # returns -1 (not found)

cache.put(4, 4)              # evicts key 1
assert cache.get(1) == -1   # returns -1 (not found)
assert cache.get(3) == 3    # returns 3
assert cache.get(4) == 4    # returns 4
```

## Approach

The class uses a double linked list to keep track of the order of the key-value pairs in the cache. The double linked list has a head node that points to the most recently used pair. The class also uses a dictionary to store the nodes in the double linked list, which allows for constant time access to the nodes.

When a key is accessed, the corresponding node is removed from the double linked list and added after the head node, making it the most recently used pair. When a new key-value pair is added, it is added after the head node. If the cache is at capacity, the least recently used pair (the node at the tail of the double linked list) is removed from the list and the dictionary.

## Complexity

The time complexity of the get and put methods is $O(1)$, as they only require constant time operations. The space complexity is $O(n)$, where $n$ is the capacity of the cache.