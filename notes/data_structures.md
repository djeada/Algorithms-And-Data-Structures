## Data structures

Collections, also known as containers, are a type of data structure that hold a variable number of items. Collections can be used to store and organize virtually any type of data, such as integers, strings, or more complex objects.

We can think about collections on two different levels:

* On a very abstract level, we can define what we mean by collections and what we can do with them. For example, we might define a collection as a data structure that allows us to store and retrieve items in a particular order, or we might define a collection as a data structure that allows us to store items with unique keys and retrieve them quickly using those keys.
* On a machine level, we figure out how to implement collections in a way that is efficient and effective for a given task. This might involve deciding on the best data structures and algorithms to use to store and retrieve items, as well as considering trade-offs such as the amount of memory used, the speed of execution, and the flexibility of the data structure.

It is important to study collections and data structures because they are fundamental to programming. Without them, it would be difficult or impossible to efficiently store, organize, and retrieve data in a program. By understanding their different types and their trade-offs, you can make informed decisions about which one to use for a given task, and you can design programs that are efficient, scalable, and maintainable.

![G70oT](https://user-images.githubusercontent.com/37275728/185710905-8acd7541-e8ed-4439-a644-5d739b39e783.png)

## Linked List

A linked list is a linear data structure that consists of a sequence of elements, where each element contains a value and a reference to the next element in the list. The elements in a linked list are often referred to as "nodes," and the reference is typically called a "link" or "pointer." The last element in the list typically has a reference to a null value, indicating the end of the list.

Linked lists are often used to store data that does not need to be stored contiguously in memory, or when the size of the data is not known in advance. They can be used as a simple alternative to arrays, but they do not have the same fast access times and are more difficult to manipulate.

### Applications

Linked lists are a simple and flexible data structure that can be used for a variety of purposes. Some common applications of linked lists include:

* Storing a sequence of items that can be added or removed dynamically.
* Implementing stacks and queues, where elements can be added or removed from the front or back of the list.
* In a hash table or associative array, where elements are stored in a linked list and accessed using a hash function.
* In a symbol table or dictionary, where elements are stored as key-value pairs and accessed using a search algorithm.
* In a graph or tree data structure, where each node is represented as a linked list element.
* In a memory allocator, where blocks of memory are stored in a linked list and allocated or freed as needed.
* Fundation for an undo or redo mechanism, where each operation is stored in a linked list and can be undone or redone in reverse order.

### Interface

Here are some common operations that can be performed on a linked list:

* `is_empty()`: Returns a boolean value indicating whether the linked list is empty.
* `front()`: Returns a reference to the first element in the list.
* `append(element)`: Adds the provided element to the end of the list.
* `remove(index)`: Removes the element at the specified index from the list.
* `replace(index, data)`: Stores the provided data at the specified index in the list.

###  Time complexity 

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

### Implementation

There are several ways to implement a linked list in different programming languages. In some languages, it may be more natural to implement a linked list as an array, while in other languages it may be more natural to use recursive data structures.

One common way to implement a linked list is to use a class that contains a value and a reference to the next element in the list. The class may also contain methods for performing operations on the list, such as adding or removing elements, or accessing the first or last element.

* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/linked_list”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/linked_list”>Python</a>

## Vector

A vector is a dynamic array that can grow or shrink as needed to store a variable number of elements. Vectors are similar to arrays, but they are more flexible and efficient in many cases. Vectors are implemented as a sequence of elements stored in contiguous blocks of memory, and they provide fast access to individual elements using an index.

In many programming languages, arrays are a low-level data structure that should be avoided whenever possible. Vectors offer almost the same performance as arrays, but they have many additional features and safety mechanisms that make them easier to use and more convenient.

### Applications

Vectors can be used for a wide variety of tasks, including:

* Storing a list of values
* Performing matrix operations
* Implementing search and sorting algorithms
* Implementing data structures

### Interface

Here are some common operations that can be performed on a vector:

* `sort(start, end)`: Sorts the elements of the vector between the positions start and end.
* `reverse(start, end)`: Reverses the order of the elements of the vector between the positions start and end.
* `size()`: Returns the number of elements in the vector.
* `capacity()`: Returns the maximum number of elements that the vector can hold before it needs to be resized.
* `resize(new_size`): Changes the size of the vector to the specified new_size. If the new size is larger than the current size, the vector is padded with default-constructed elements. If the new size is smaller, elements are removed from the end of the vector.
* `reserve(new_capacity)`: Increases the capacity of the vector to at least new_capacity. If the current capacity is already larger than new_capacity, this operation has no effect.

### Time complexity

Here is a summary of the time complexity of common operations on a vector:

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(1)` | `O(1)` |
| Insert | `O(1)` | `O(n)` |
| Delete | `O(1)` | `O(n)` |
| Search | `O(n)` | `O(n)` |

### Implementation

Vectors are typically implemented using an array of elements, with additional metadata such as the size and capacity of the vector. When the vector needs to be resized, a new array is allocated and the elements are copied to the new array. This operation can be expensive in terms of time and memory, so vectors generally try to avoid resizing whenever possible by allocating more memory than they need.

In some programming languages, vectors may be implemented using a linked list or other data structure under the hood. However, the Interface and time complexity of vectors should be similar regardless of the implementation details.

* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/vector”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/vector”>Python</a>

## Stack

They are the ideal data structure to model a First-In-Last-Out (FILO), or Last-In-First-Out (LIFO), strategy in search.
A number of programming languages are stack-oriented, meaning they define most Interface (adding two numbers, printing a character) as taking their arguments from the stack, and placing any return values back on the stack.
Interface

* `push(element)`: take an element and place it on top of an existing stack.
* `pop()`: return the top element of the stack and removes it from the stack.
* `top()`: return the top element of the stack without removing it from the stack.
* `is_empty()`: return True if the stack is empty, False otherwise.

### Applications

* In stack-oriented programming languages
* Graph algorithms: depth-first search can be implemented with stacks (or with recursion)
* Finding Euler-cycles in a graph
* Finding strongly connected components in a graph

###  Time complexity 

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

###  Implementation

In most programming languages, a stack can be easily implemented either with arrays or linked lists. 

* A stack can be implemented with arrays in a way that the top element is always stored at the highest index of the array. This way, when we remove the top element, we can simply reduce the value of the top pointer by 1. The push operation can be done by incrementing the top pointer and placing the new element at the new top index. This implementation is simple, but it is not dynamic. Once the stack size is fixed, it cannot be changed.
* A stack can be implemented with a linked list in a way that the top element is the head of the list. This way, when we remove the top element, we can simply change the head to point to the next element in the list. The push operation can be done by creating a new node and setting it as the new head of the list. This implementation is dynamic, because the stack size can be changed at any time. However, it requires the use of dynamic memory allocation, which can be slower and more complex than using arrays.

* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/stack”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/stack”>Python</a>

## Queue

A queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and the removal of entities from the other end of the sequence. It is a data structure that implements the FIFO (First In First Out) strategy.

### Interface

* `enqueue(element)`: take an element and place it at the end of the queue.
* `dequeue()`: return the front element of the queue and removes it from the queue.
* `front()`: return the front element of the queue without removing it from the queue.
* `is_empty()`: return True if the queue is empty, False otherwise.

### Applications:

* Resource scheduling: servers, printers, CPU tasks
* Communication systems: packets, messages
* Simulation: events, customers
* BFS

### Time complexity

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

### Implementation

Queues can be implemented using arrays or linked lists. One way to implement a queue is to use a circular buffer, where the head and tail indices are incremented modulo the array size. Another way is to use a dynamic array, where the head and tail indices are incremented normally and the array is resized when it becomes full.

* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/queue”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/simple_queue”>Python</a>

### Differences between stacks and queues

* Stacks are based on the LIFO (Last In First Out) strategy, while queues are based on the FIFO (First In First Out) strategy.
* In a stack, we can only access the top element, while in a queue we can access both the front and the back elements.
* Stacks are usually implemented using arrays or linked lists, while queues can also be implemented using circular arrays, heaps, or deques.
* Stacks are useful for reversing the order of elements, while queues are useful for preserving the order of elements.

## Heap
Heaps are a kind of binary tree. There are two types of heaps: maximum heaps and minimum heaps.

In a maximum heap, the keys of parent nodes are always larger than or equal to those of the children, and the root node has the largest key. In a minimum heap, the keys of parent nodes are less than or equal to those of the children, and the root node has the smallest key.

Heaps are complete, which means they can never be imbalanced. Every new item is placed in the next available space.

It is important to note that heaps have nothing to do with the pool of memory from which dynamically allocated memory is allocated.

### Interface

* `insert(value)`: insert a new element in a suitable place, preserving the heap's characteristics.
* `search(value)`: search for a value.
* `remove(value)`: remove a value, while preserving the heap's characteristics.

### Applications:

- Internally used by several graph algorithms, including the Dijkstra and Prim's algorithms.
- Used to implement a priority queue.
- Heap sort is a heap data structure-based sorting algorithm.

### Time complexity 

| Operation | Average case | 
| --- | --- | 
| Find min/max | `O(1)` |
| Delete min/max | `O(logn)` |
| Insert | `O(logn)` |
| Merge | `O(mlog(m+n))` | 

### Implementation

Since a heap is a complete binary tree, it can be efficiently represented using a one-dimensional array. This provides a very convenient way of figuring out where children belong:

1. The root of the tree is placed at index 1.
1. The left child of an element with index `i` is placed at index `2*i`.
1. The right child of an element with index `i` is placed at index `2*i + 1`.
1. The parent of an element with index `i` is placed at index `floor(i/2)`.
    
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/heap”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/heap”>Python</a>

## Binary search tree

A binary search tree (BST) is a node-based data structure that is used to store data in a sorted order. It is called a binary search tree because each node has at most two children, and it is called a search tree because it allows efficient search for a specific value in the tree.

BSTs have the following properties:

* Each node has one value (also called a key).
* The keys in the left subtree are smaller than the key in the parent node.
* The keys in the right subtree are greater than the key in the parent node.
* It is not allowed to have duplicate node values.

### Interface

* `insert(value)`: insert a new value.
* `search(value)`: search for a value.
* `remove(value)`: remove a value.
* `minimum()`: return the minimum value.
* `maximum()`: return the maximum value.

###  Time complexity 

The time complexity of BST operations depends on the height of the tree. In the worst case, the height of a BST can be as large as the number of nodes, resulting in a time complexity of O(n). However, in the average case, the height of a BST is logarithmic, resulting in a time complexity of O(log n) for most operations.

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(logn)` | `O(n)` |
| Insert | `O(logn)` | `O(n)` |
| Delete | `O(logn)` | `O(n)` |
| Search | `O(logn)` | `O(n)` |

### Implementation

There are multiple ways to implement a BST, but one common way is to use a Node class with a left and right attribute to represent the left and right subtrees, respectively. The insert, search, and remove operations can then be implemented using recursive functions that traverse the tree and make appropriate modifications.

To add a new value to the BST, we should do the following:

1. If the tree is empty, just assign the new value to the root while leaving the left and right subtrees empty.
1. If the tree is non-empty, then do the following:
  - If the new value is less than the root value, place it into the left sub-tree.
  - If the new value is greater than the root value, place it into the right sub-tree.
  - If the new value equals the value of the root, throw an exception.

To search for a value in the BST, we should do the following:

1. If the tree is empty, return False.
1. If the tree is non-empty, do the following:
  - If the search value is equal to the root value, return True.
  - If the search value is less than the root value, search the left sub-tree.
  - If the search value is greater than the root value, search the right sub-tree.

To remove a value from the BST, we should do the following:

1. If the tree is empty, return False.
1. If the tree is non-empty, do the following:
  - If the search value is equal to the root value:
    - If the root has no children, simply remove it.
    - If the root has one child, replace the root with its child.
    - If the root has two children, find the minimum value in the right subtree, replace the root with that value, and then remove the minimum value from the right subtree.
  - If the search value is less than the root value, remove it from the left sub-tree.
  - If the search value is greater than the root value, remove it from the right sub-tree.    
  
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/binary_search_tree”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/binary_search_tree”>Python</a>

## AVL tree
AVL trees (Adelson-Velsky and Landis trees) are self-balancing binary search trees. An AVL tree is a binary search tree that satisfies the following height-balanced property: for every node in the tree, the height of its left and right subtrees differ by at most 1.

AVL trees have the following properties:

* The left and right subtrees of a node differ in height by at most 1.
* The left and right subtrees are also AVL trees.

### Applications

* Implementing set data structures in computer programming languages that support them.
* Storing and indexing data in databases.
* Implementing priority queues and dictionary data structures.
* Used in spell checkers and word suggestion tools, since they allow for fast insertion and retrieval of words.
* Used in data compression algorithms, since they allow for fast insertion and retrieval of data.
* Used in networking algorithms, such as routing tables and packet filtering systems.

### Interface

* `insert(value)`: place the provided value into an appropriate node.
* `search(value)`: look for a node with the specified value.
* `remove(value)`: remove a node with the specified value.
* `rotate_left()`: perform a left rotation.
* `rotate_right()`: perform a right rotation.

###  Time complexity 

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(logn)` | `O(logn)` |
| Insert | `O(logn)` | `O(logn)` |
| Delete | `O(logn)` | `O(logn)` |
| Search | `O(logn)` | `O(logn)` |

### Implementation
To maintain the balance, AVL trees use what are known as rotation operations. There are four different types of rotations:

1. Right rotation: This operation is performed when the left subtree of the root node is taller than the right subtree. To perform a right rotation, we follow these steps:
  - Set the root node's left child as the new root.
  - Set the old root as the right child of the new root.
  - Update the heights of the old and new root nodes.

2. Left rotation: This operation is performed when the right subtree of the root node is taller than the left subtree. To perform a left rotation, we follow these steps:
  - Set the root node's right child as the new root.
  - Set the old root as the left child of the new root.
  - Update the heights of the old and new root nodes.

3. Right-left rotation: This operation is performed when the right subtree of the root node is taller than the left subtree, and the left subtree of the right child is taller than the right subtree. To perform a right-left rotation, we follow these steps:
  - Perform a right rotation on the root node's right child.
  - Perform a left rotation on the root node.
  - Update the heights of the affected nodes.
        
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/avl_tree”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/avl_tree”>Python</a>

## Red-black tree
A red-black tree is a self-balancing binary search tree that enforces a particular pattern of color assignment to the nodes. The height of the binary search tree determines how long it takes for BST operations to finish. In order to obtain the best results, we need keep the tree balanced. The main advantage of red-black trees is that they allow insertion and deletion operations to run in O(logn) time on average, while also ensuring that the tree remains balanced.

Red-black trees have the following properties:

* Each node is either red or black.
* The root node is always black.
* All leaves (NIL) are black.
* Every red node must have two black child nodes and no other children -> it must have a black parent.
* Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.

###  Applications

* Internally used by many operating systems.
* Used in programming languages (Java, C++) for their implementation of maps and sets.
* Used in the implementation of other data structures and algorithms, such as the splay tree, treap, and others.

### Interface

* `insert(value)`: place the provided value into an appropriate node.
* `search(value)`: look for a node with the specified value.
* `remove(value)`: remove a node with the specified value.
* `rotate_left()`: perform a left rotation.
* `rotate_right()`: perform a right rotation.

###  Time complexity 

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(logn)` | `O(logn)` |
| Insert | `O(logn)` | `O(logn)` |
| Delete | `O(logn)` | `O(logn)` |
| Search | `O(logn)` | `O(logn)` |

### Implementation
Red-black trees are implemented using the same basic structure as binary search trees, with the added requirement that each node has an extra field to store its color. The color field can be either red or black, and the rules for maintaining the balance of the tree are enforced by modifying the colors of the nodes as necessary during insertions and deletions.

To insert a new node into a red-black tree, the following steps can be followed:

1. Perform a standard insertion into the tree as with a binary search tree.
1. If the new node is the root of the tree, color it black to satisfy the first red-black property.
1. If the new node's parent is black, no further action is needed since the red-black properties are still satisfied.
1. If the new node's parent is red, check the color of its uncle (the sibling of its parent). If the uncle is also red, recolore both the parent and uncle nodes black, and the grandparent red. This operation is known as "recoloring".
1. If the uncle is black, we may need to perform rotations to balance the tree. There are four possible cases to consider:
  - The new node is the right child of its parent and its parent is the left child of the grandparent. In this case, we perform a left rotation on the parent node to balance the tree.
  - The new node is the left child of its parent and its parent is the left child of the grandparent. In this case, we perform a right rotation on the grandparent node to balance the tree.
  - The new node is the left child of its parent and its parent is the right child of the grandparent. In this case, we perform a right rotation on the parent node and a left rotation on the grandparent node to balance the tree.
  - The new node is the right child of its parent and its parent is the right child of the grandparent. In this case, we perform a left rotation on the grandparent node to balance the tree.

After performing these steps, the red-black tree should be balanced and all the red-black properties should be satisfied. If the tree was unbalanced before the insertion or deletion, it will now be balanced.

It is important to note that these rebalancing steps may need to be performed multiple times, depending on the structure of the tree and the location of the inserted or deleted node.

* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/red_black_tree”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/red_black_tree”>Python</a>

## Hash table

A hash table is a data structure that maps keys to values using a hash function. It allows for efficient insertion, deletion, and lookup of values in a collection. Hash tables are also known as hash maps or dictionaries.

###  Applications:

* commonly used in applications where fast lookup and insertion are important, such as databases and networking applications. 
* in algorithms such as the Rabin-Karp algorithm for substring search.
* in histograms for data visualization. 

### Interface

* `is_empty()`: Returns True if the hash table is empty, False otherwise.
* `insert(key, value)`: Inserts a key-value pair into the hash table.
* `retrieve(key)`: Returns the value associated with the given key.
* `update(key, value)`: Updates the value associated with the given key.
* `delete(key)`: Deletes the key-value pair with the given key from the hash table.
* `traverse()`: Iterates through all the key-value pairs in the hash table.

###  Time complexity 

The time complexity of hash table operations depends on the hash function, the collision resolution strategy, and the load factor (the number of key-value pairs in the table divided by the number of buckets).

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `-` | `-` |
| Insert | `O(1)` | `O(n)` |
| Delete | `O(1)` | `O(n)` |
| Search | `O(1)` | `O(n)` |

### Implementation

To implement a hash table, we need to define a data structure to store the key-value pairs, a hash function to map keys to positions in the data structure, and a collision resolution strategy to handle cases where multiple keys map to the same position.

The most common data structure for a hash table is an array, but it can also be implemented using a linked list or a balanced tree. The array approach is known as open addressing, while the linked list and tree approaches are known as chaining.

#### Hash Function

The key to a hash table's performance is the hash function, which determines the position of a key-value pair in the table. A good hash function should distribute the keys uniformly in the table, so that each bucket has approximately the same number of keys. To ensure a uniform distribution, we can use prime numbers both for the size of the array and in the hash function. For strings, we can compute the ASCII value for each character, add them together, and calculate the modulo.

```
# n: number of keys
# m: number of buckets 
h(x) = n % m
```

#### Collisions

Collisions occur when two or more keys are mapped to the same bucket by the hash function. There are two common approaches to handling collisions: chaining and open addressing.

#### Chaining

In chaining, each bucket is a linked list, and each key-value pair is inserted into the appropriate list. This allows for efficient insertion and deletion, but the worst-case time complexity for lookup is O(n), where n is the number of keys in the hash table.

#### Open Addressing

In open addressing, the hash table is an array, and each key-value pair is stored in an array element. When a collision occurs, the hash table uses a probing sequence to find the next available array element to store the key-value pair. The most common probing sequences are linear probing and quadratic probing.

* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/hash_table”>C++</a>
* <a href=”https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/hash_table”>Python</a>
