## Data Structures: Collections and Containers

A collection (or container) is a data structure that holds multiple items, like numbers, text, or more complex objects. Collections help you store and organize different types of data.

There are two main aspects of collections:

1. Abstract Level: This is where we define what collections are and what they can do. We can define collections based on how they store and access items (e.g., in a specific order or using unique keys).
2. Machine Level: This is where we decide how to efficiently implement collections for a specific task. We need to choose the best data structures and algorithms and consider factors like memory usage, speed, and flexibility.

Studying collections is important because they are essential to programming. Understanding different types of collections helps you decide which one to use for a specific task, making your programs more efficient and easier to maintain.

![G70oT](https://user-images.githubusercontent.com/37275728/185710905-8acd7541-e8ed-4439-a644-5d739b39e783.png)

## Linked List

A linked list is a simple data structure that has a sequence of elements (nodes) with each node containing a value and a reference (link or pointer) to the next node. The last node has a reference to a null value, marking the end of the list.

Linked lists are useful when data doesn't need to be stored in a specific order in memory or when the data size is unknown. They can be an alternative to arrays, but they have slower access times and are harder to work with.

### Applications

Linked lists can be used for many things, such as:

* Storing items that can be added or removed easily
* Creating stacks and queues
* Storing elements in hash tables or associative arrays
* Storing key-value pairs in symbol tables or dictionaries
* Representing nodes in graphs or tree data structures
* Allocating or freeing memory blocks in memory allocators
* Storing operations for undo or redo functionality

### Interface

Some common operations for linked lists are:

* `is_empty()`: Check if the list is empty
* `front()`: Get the first element in the list
* `append(element)`: Add an element to the end of the list
* `remove(index)`: Remove an element at a specific index
* `replace(index, data)`: Replace the element at a specific index

### Time Complexity

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

### Implementation

Linked lists can be implemented in different ways depending on the programming language. A common method is using a class with a value and a reference to the next element, along with methods for adding, removing, or accessing elements.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/linked_list)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/linked_list)

## Vector

A vector is like a dynamic array that can change its size as needed. Vectors are similar to arrays, but they are more flexible and efficient in many cases. They store elements in continuous memory blocks and provide fast access to elements using an index.

Vectors are often preferred over low-level arrays because they offer more features and safety mechanisms, making them easier to use.

### Applications

Vectors can be used for various tasks, such as:

* Storing lists of values
* Doing matrix operations
* Implementing search and sorting algorithms
* Creating data structures

### Interface

Some common operations for vectors are:

* `sort(start, end)`: Sort elements between specific positions
* `reverse(start, end)`: Reverse the order of elements between specific positions
* `size()`: Get the number of elements in the vector
* `capacity()`: Get the maximum number of elements the vector can hold before resizing
* `resize(new_size)`: Change the vector size, adding or removing elements as needed
* `reserve(new_capacity)`: Increase the vector capacity, if needed

### Time Complexity

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(1)` | `O(1)` |
| Insert | `O(1)` | `O(n)` |
| Delete | `O(1)` | `O(n)` |
| Search | `O(n)` | `O(n)` |

### Implementation

Vectors are usually implemented using an array of elements with additional metadata, such as size and capacity. When resizing, a new array is created and elements are copied over. Resizing can be time and memory-consuming, so vectors try to minimize resizing by allocating extra memory.

In some languages, vectors might use a linked list or other data structure under the hood, but the interface and time complexity should be similar regardless of implementation details.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/vector)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/vector)

## Stack

Stacks are perfect for modeling a First-In-Last-Out (FILO) or Last-In-First-Out (LIFO) approach in searching. Many programming languages use stacks to perform operations, such as adding numbers or printing characters.

### Interface

* `push(element)`: Place an element on top of the stack
* `pop()`: Return and remove the top element from the stack
* `top()`: Return the top element without removing it from the stack
* `is_empty()`: Check if the stack is empty

### Applications

* Stack-oriented programming languages
* Graph algorithms (e.g., depth-first search)
* Finding Euler cycles in graphs
* Finding strongly connected components in graphs

### Time Complexity

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

### Implementation

Stacks can be easily implemented using arrays or linked lists in most programming languages.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/stack)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/stack)

## Queue

Queues store elements in a sequence and allow modifications by adding elements to one end and removing them from the other. Queues follow a First In First Out (FIFO) strategy.

### Interface

* `enqueue(element)`: Add an element to the end of the queue
* `dequeue()`: Return and remove the front element from the queue
* `front()`: Return the front element without removing it from the queue
* `is_empty()`: Check if the queue is empty

### Applications

* Resource scheduling (e.g., servers, printers, CPU tasks)
* Communication systems (e.g., packets, messages)
* Simulation (e.g., events, customers)
* BFS

### Time Complexity

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

### Implementation

Queues can be implemented using arrays, linked lists, circular buffers, or dynamic arrays.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/queue)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/simple_queue)

### Differences between Stacks and Queues

* Stacks use a LIFO strategy, while queues use a FIFO strategy
* In stacks, only the top element is accessible, but in queues, both front and back elements are accessible
* Stacks can be implemented with arrays or linked lists, while queues can use circular arrays, heaps, or deques
* Stacks are useful for reversing element order, while queues preserve element order

## Heap

Heaps are a type of binary tree, with two kinds: maximum heaps and minimum heaps. In maximum heaps, parent nodes have larger keys than their children, and the root node has the largest key. In minimum heaps, parent nodes have smaller keys than their children, and the root node has the smallest key. Heaps are always complete and balanced.

### Interface

* `insert(value)`: Add a new element while maintaining the heap properties
* `search(value)`: Look for a specific value in the heap
* `remove(value)`: Delete a value and keep the heap properties

### Applications

- Used by graph algorithms like Dijkstra and Prim's
- Implementing priority queues
- Heap sort algorithm

### Time Complexity

| Operation | Average case |
| --- | --- |
| Find min/max | `O(1)` |
| Delete min/max | `O(logn)` |
| Insert | `O(logn)` |
| Merge | `O(mlog(m+n))` |

### Implementation

Heaps can be represented efficiently using a one-dimensional array. The array allows easy calculation of parent, left, and right children positions.

1. The root of the tree is placed at index 1.
1. The left child of an element with index `i` is placed at index `2*i`.
1. The right child of an element with index `i` is placed at index `2*i + 1`.
1. The parent of an element with index `i` is placed at index `floor(i/2)`.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/heap)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/heap)

## Binary Search Tree (BST)

BSTs store data in a sorted order and have up to two children per node. Each node has a value, with left subtree values smaller and right subtree values larger than the parent node value. Duplicate node values are not allowed.

### Interface

* `insert(value)`: Add a new value to the tree
* `search(value)`: Look for a specific value in the tree
* `remove(value)`: Delete a value from the tree
* `minimum()`: Get the smallest value in the tree
* `maximum()`: Get the largest value in the tree

### Time Complexity

BST operations depend on tree height. Worst-case time complexity is O(n), while average case is O(log n).

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(logn)` | `O(n)` |
| Insert | `O(logn)` | `O(n)` |
| Delete | `O(logn)` | `O(n)` |
| Search | `O(logn)` | `O(n)` |

### Implementation

BSTs can be implemented using a Node class with left and right attributes. Recursive functions can be used for insert, search, and remove operations.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/binary_search_tree)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/binary_search_tree)


## AVL Tree
AVL trees, named after Adelson-Velsky and Landis, are self-balancing binary search trees. They maintain a height difference of at most 1 between left and right subtrees of every node. This ensures that the tree remains balanced for efficient operations.

### Properties
- Left and right subtrees' heights differ by at most 1.
- Both subtrees are also AVL trees.

### Applications
- Sets in programming languages.
- Database storage and indexing.
- Priority queues, dictionaries.
- Spell checkers, word suggestions.
- Data compression, networking algorithms.

### Methods
- insert(value): Add a value to the tree.
- search(value): Find a node with the given value.
- remove(value): Delete a node with the given value.
- rotate_left(): Perform a left rotation.
- rotate_right(): Perform a right rotation.

### Time Complexity
| Operation | Average | Worst |
| --- | --- | --- |
| Access | O(logn) | O(logn) |
| Insert | O(logn) | O(logn) |
| Delete | O(logn) | O(logn) |
| Search | O(logn) | O(logn) |

### Implementation
AVL trees use rotations to maintain balance. There are 4 types of rotations:

1. Right rotation: Performed when the left subtree of the root node is taller than the right subtree.
   - Set the root node's left child as the new root.
   - Set the old root as the right child of the new root.
   - Update the heights of the old and new root nodes.

2. Left rotation: Performed when the right subtree of the root node is taller than the left subtree.
   - Set the root node's right child as the new root.
   - Set the old root as the left child of the new root.
   - Update the heights of the old and new root nodes.

3. Right-left rotation: Performed when the right subtree of the root node is taller than the left subtree, and the left subtree of the right child is taller than the right subtree.
   - Perform a right rotation on the root node's right child.
   - Perform a left rotation on the root node.
   - Update the heights of the affected nodes.

4. Left-right rotation: Performed when the left subtree of the root node is taller than the right subtree, and the right subtree of the left child is taller than the left subtree.
   - Perform a left rotation on the root node's left child.
   - Perform a right rotation on the root node.
   - Update the heights of the affected nodes.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/avl_tree)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/avl_tree)

## Red-Black Tree
Red-black trees are self-balancing binary search trees with nodes colored either red or black. They maintain specific color patterns to keep the tree balanced, ensuring efficient operations.

### Properties
- Nodes are red or black.
- Root is always black.
- Leaves (NIL) are black.
- Red nodes have two black children and a black parent.
- Paths from a node to its descendant NIL nodes have the same number of black nodes.

### Applications
- Operating systems internals.
- Maps and sets in programming languages.
- Data structures and algorithms like splay tree, treap, etc.

### Methods
- insert(value): Add a value to the tree.
- search(value): Find a node with the given value.
- remove(value): Delete a node with the given value.
- rotate_left(): Perform a left rotation.
- rotate_right(): Perform a right rotation.

### Time Complexity
| Operation | Average | Worst |
| --- | --- | --- |
| Access | O(logn) | O(logn) |
| Insert | O(logn) | O(logn) |
| Delete | O(logn) | O(logn) |
| Search | O(logn) | O(logn) |

### Implementation
Red-black trees are binary search trees with an additional color field for each node. The tree remains balanced by modifying node colors during insertions and deletions. Rebalancing steps may need to be performed multiple times:

1. Perform a standard insertion into the tree as with a binary search tree.
2. If the new node is the root of the tree, color it black to satisfy the first red-black property.
3. If the new node's parent is black, no further action is needed since the red-black properties are still satisfied.
4. If the new node's parent is red, check the color of its uncle (the sibling of its parent). If the uncle is also red, recolor both the parent and uncle nodes black, and the grandparent red. This operation is known as "recoloring".
5. If the uncle is black, we may need to perform rotations to balance the tree. There are four possible cases to consider:
   - The new node is the right child of its parent and its parent is the left child of the grandparent. In this case, we perform a left rotation on the parent node to balance the tree.
   - The new node is the left child of its parent and its parent is the left child of the grandparent. In this case, we perform a right rotation on the grandparent node to balance the tree.
   - The new node is the left child of its parent and its parent is the right child of the grandparent. In this case, we perform a right rotation on the parent node and a left rotation on the grandparent node to balance the tree.
   - The new node is the right child of its parent and its parent is the right child of the grandparent. In this case, we perform a left rotation on the grandparent node to balance the tree.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/red_black_tree)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/red_black_tree)

## Hash table

A hash table, also called a hash map or dictionary, is a data structure that uses a hash function to connect keys with their corresponding values. This allows for efficient insertion, deletion, and lookup of items in a collection. Hash tables are often utilized in situations where rapid lookup and insertion are crucial, like in databases or networking applications.

### Applications

- They are commonly used in applications requiring quick insertion and lookup, such as databases and networking programs.
- They are employed in algorithms like the Rabin-Karp algorithm for searching substrings.
- Hash tables are used to create histograms for visualizing data.

### Interface

- `is_empty()`: Determines if the hash table is empty and returns True if so, False if not.
- `insert(key, value)`: Adds a key-value pair to the hash table.
- `retrieve(key)`: Retrieves the value connected to the specified key.
- `update(key, value)`: Updates the value linked to the given key.
- `delete(key)`: Removes the key-value pair with the provided key from the hash table.
- `traverse()`: Iterates over all key-value pairs within the hash table.

### Time Complexity

The time complexity of hash table operations is influenced by the hash function, the collision resolution strategy, and the load factor (the ratio of the number of key-value pairs in the table to the number of buckets).

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `-` | `-` |
| Insert | `O(1)` | `O(n)` |
| Delete | `O(1)` | `O(n)` |
| Search | `O(1)` | `O(n)` |

### Implementation

To create a hash table, we must define a data structure to hold key-value pairs, a hash function to assign keys to positions in the data structure, and a collision resolution strategy for instances when multiple keys are assigned the same position.

While an array is the most typical data structure for a hash table, it can also be implemented using a linked list or a balanced tree. The array method is called open addressing, and the linked list and tree methods are known as chaining.

#### Hash Function

The hash function is critical to the hash table's performance, as it determines the position of a key-value pair within the table. A good hash function should uniformly distribute keys across the table, ensuring that each bucket holds roughly the same number of keys. To achieve a uniform distribution, we can use prime numbers for both the array size and in the hash function. For strings, we can compute the ASCII value for each character, add them together, and calculate the modulo.

```
# n: number of keys
# m: number of buckets 
h(x) = n % m
```

#### Collisions

When the hash function assigns two or more keys to the same bucket, collisions occur. There are two common methods for dealing with collisions: chaining and open addressing.

#### Chaining

In chaining, each bucket is a linked list, and each key-value pair is inserted into the appropriate list. This allows for efficient insertion and deletion, but the worst-case time complexity for lookup is O(n), where n is the number of keys in the hash table.

#### Open Addressing

In open addressing, the hash table is an array, and each key-value pair is stored in an array element. When a collision occurs, the hash table uses a probing sequence to find the next available array element to store the key-value pair. The most common probing sequences are linear probing and quadratic probing.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/hash_table)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/hash_table)
