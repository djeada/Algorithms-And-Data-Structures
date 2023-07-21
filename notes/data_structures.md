## Data Structures: Collections and Containers

In computer science, a _collection_ (often interchangeably referred to as a _container_) is a sophisticated data structure designed to hold multiple entities, these could be simple elements like numbers or text strings, or more complex objects like user-defined structures. Collections play a critical role in helping you store, organize, and manipulate different types of data in your programs.

There are two primary perspectives to view collections from:

1. **The Abstract Level**: This refers to the conceptual view of collections. Here, we define what collections are, and establish their capabilities and characteristics. For instance, we might define collections based on how they store and retrieve items. This could be based on a specific order (like arrays or lists), or using unique identifiers or keys (like dictionaries or maps).

2. **The Machine Level**: This pertains to the actual implementation of collections. In this perspective, we concern ourselves with the most efficient ways to actualize our abstract collection models. To decide the best data structures and algorithms for a specific task, we need to consider various factors, such as memory usage, speed of operations (like insertion, deletion, search), and the flexibility of the structure.

Understanding and studying collections in-depth is crucial for every programmer. This knowledge empowers you to choose the most appropriate collection type for a given task, leading to programs that are not only more efficient in terms of time and space complexities, but also much more maintainable and robust due to clear structure and organization.

![G70oT](https://user-images.githubusercontent.com/37275728/185710905-8acd7541-e8ed-4439-a644-5d739b39e783.png)

## Linked Lists

A _Linked List_ is a fundamental data structure in computer science, which comprises a sequence of elements, known as nodes. Each node in this sequence contains two distinct parts: 

1. A value (or data), which could range from simple data types to more complex structures.
2. A reference (commonly referred to as a link or a pointer) to the subsequent node in the sequence.

Importantly, the last node in the linked list points to a null value, effectively signifying the end of the list.

Linked lists can be highly valuable when the data doesn't require contiguous storage in memory or when the exact size of the data is undetermined at the time of memory allocation. While they can serve as an alternative to arrays, it's essential to note that linked lists generally have slower access times and are more challenging to manipulate due to their non-contiguous storage and absence of direct access to individual elements.

```
[HEAD]-->[1| ]-->[2| ]-->[3| ]-->[4| ]-->[NULL]
```

### Common Applications

Linked lists find utility in a wide variety of areas including, but not limited to:

* Storing items that undergo frequent addition or removal operations. This is due to the cost-effective manipulation (insertion/deletion) capabilities of linked lists.
* Implementing other high-level data structures such as stacks and queues.
* Storing buckets in hash tables or elements in associative arrays.
* Maintaining key-value pairs in symbol tables or dictionaries.
* Representing nodes in advanced structures like graphs or tree data structures.
* Managing allocation or deallocation of memory blocks in memory management systems.
* Storing sequences of operations to support undo or redo functionality in software applications.

### Typical Interface

Here are some standard operations associated with linked lists:

* `is_empty()`: This checks if the list is devoid of any elements.
* `front()`: This retrieves the first element in the list.
* `append(element)`: This adds a new element to the end of the list.
* `remove(index)`: This removes an element at a specified index.
* `replace(index, data)`: This substitutes the element at a specified index with a new value.

### Time Complexity

Understanding the time complexity of basic operations is key to efficient use of linked lists:

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert | `O(1)` | `O(1)` |
| Delete | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

Note that while insertion and deletion are constant time operations, access and search operations require traversing the list, resulting in linear time complexity.

### Implementation Details

Linked lists can be implemented in various ways, largely dependent on the programming language used. A conventional implementation strategy involves defining a custom class or structure to represent a node. This class encapsulates a value and a reference to the next node. Additionally, methods for adding, removing, and accessing elements are provided to manipulate the list.

In some languages, linked lists are provided as part of the standard library, abstracting away the underlying implementation details and providing a rich set of functionality.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/linked_list)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/linked_list)

## Vectors

In computer science, a _vector_ can be thought of as a dynamic array with the ability to adjust its size as required. While similar to traditional arrays, vectors distinguish themselves with their superior flexibility and efficiency in numerous scenarios. They store elements in contiguous blocks of memory, ensuring swift access to elements through index-based referencing.

Vectors are often favored over low-level arrays due to their augmented feature set and integrated safety mechanisms. These characteristics contribute to their easier usability and overall reliability.

```
-------------------------
| 0 | 1 | 2 | 3 | 4 | 5 |
-------------------------
```

### Practical Applications

Vectors can be leveraged for a wide array of tasks, such as:

* Storing collections of values. Vectors are adept at storing and manipulating ordered lists of homogenous data types.
* Executing matrix operations. Vectors provide a good structure for representing matrices and performing computations on them.
* Implementing various search and sorting algorithms. Due to their continuous memory allocation and indexing, vectors are ideal for executing such algorithms.
* Creating intricate data structures. Vectors can serve as foundational building blocks in the implementation of more complex data structures.

### Typical Interface

Some of the commonly used operations for vectors are:

* `sort(start, end)`: This function sorts the elements in the specified range within the vector.
* `reverse(start, end)`: This operation reverses the order of elements between specified positions.
* `size()`: This function retrieves the current number of elements in the vector.
* `capacity()`: This retrieves the maximum number of elements the vector can hold before needing to resize.
* `resize(new_size)`: This operation alters the vector size, adding or removing elements as necessary.
* `reserve(new_capacity)`: This increases the vector capacity, if required, without changing the vector size.

### Time Complexity

A thorough understanding of the time complexity of basic operations is key to efficient use of vectors:

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(1)` | `O(1)` |
| Insert | `O(1)` | `O(n)` |
| Delete | `O(1)` | `O(n)` |
| Search | `O(n)` | `O(n)` |

While access to elements is a constant time operation, insertions and deletions can vary depending on where these operations are performed. If at the end, they are constant time operations; however, elsewhere, these operations can result in shifting of elements, causing linear time complexity.

### Implementation Details

Vectors are typically implemented using an array of elements accompanied by additional metadata such as the current size and total capacity. When a resize operation is necessary, a new, larger array is created, and the existing elements are copied over to the new array. As resizing can be time and resource-consuming, vectors often allocate extra memory ahead of time to minimize the frequency of resizing.

In some programming languages, vectors might internally use other data structures like linked lists. However, regardless of the underlying implementation, the interface presented to the programmer and the time complexity of the operations remain similar.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/vector)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/vector)

## Stacks

A _stack_ is a fundamental data structure that models a First-In-Last-Out (FILO) or Last-In-First-Out (LIFO) strategy. In essence, the most recently added element (the top of the stack) is the first one to be removed. This data structure is widely utilized across various programming languages to execute a range of operations, such as arithmetic computations, character printing, and more.

```
[5]  <- top
[4]
[3]
[2]
[1]  <- bottom
```

### Key Interface Methods

Typical operations associated with a stack include:

* `push(element)`: This method places a new element on top of the stack, effectively becoming the most recent addition.
* `pop()`: This method returns the top element of the stack and simultaneously removes it.
* `top()`: This method simply returns the top element without removing it from the stack, allowing you to inspect the most recent addition.
* `is_empty()`: This method checks if the stack is empty, a useful operation before attempting to `pop()` or `top()` to prevent errors.

### Common Applications

Stacks are incredibly versatile and are used in a multitude of applications, including:

* Stack-oriented programming languages: Languages such as Forth and PostScript heavily use the stack data structure for their operations.
* Graph algorithms: Stacks are commonly used in depth-first search (DFS) algorithms where we need to backtrack.
* Finding Eulerian cycles in graphs: An Eulerian cycle is a cycle that visits every edge exactly once. Stacks can be used to keep track of the path.
* Identifying strongly connected components in graphs: Stacks can be used in algorithms like Tarjan’s algorithm for this purpose.

### Time Complexity

Knowing the time complexity of stack operations is crucial for writing efficient code:

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert (Push) | `O(1)` | `O(1)` |
| Delete (Pop) | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

As can be seen, while push and pop operations are constant time, access (retrieving an element without popping) and search operations require linear time since, in the worst case, all elements must be inspected.

### Implementation Details

Stacks can be implemented using various underlying data structures, but arrays and linked lists are among the most common due to their inherent characteristics which nicely complement the operations and needs of a stack.

The choice between arrays and linked lists often depends on the specific requirements of the application, such as memory usage and the cost of operations. With an array, resizing can be expensive but access is faster, while with a linked list, insertion and deletion are faster but more memory is used due to the extra storage of pointers.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/stack)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/stack)

## Queues

A _queue_ is a fundamental data structure that stores elements in a sequence, with modifications made by adding elements to the end (enqueuing) and removing them from the front (dequeuing). The queue follows a First In First Out (FIFO) strategy, implying that the oldest elements are processed first.

```
[1]  <- front
[2]
[3]
[4]
[5]  <- rear
```

### Core Interface Methods

The standard operations associated with a queue are:

* `enqueue(element)`: This method adds a new element to the end of the queue.
* `dequeue()`: This method returns the front element of the queue and simultaneously removes it.
* `front()`: This method simply returns the front element without removing it from the queue, giving a peek at the next item to be dequeued.
* `is_empty()`: This method checks if the queue is empty, a crucial operation before attempting to `dequeue()` or `front()` to avoid errors.

### Practical Applications

Queues are incredibly versatile and find use in a variety of real-world scenarios, including:

* Resource scheduling: Servers, printers, CPU tasks often use queues to handle requests in the order they are received.
* Communication systems: Data packets and messages are typically handled in a FIFO manner, making queues the perfect data structure for this purpose.
* Simulations: In simulations of real-world systems, events or customers are often processed in a FIFO manner, making queues a natural fit.
* Breadth-First Search (BFS) in graph algorithms: BFS uses a queue to keep track of vertices to be processed.

### Comparing Stacks and Queues

While stacks and queues are similar data structures, they differ in several key aspects:

* Approach: Stacks follow a Last-In-First-Out (LIFO) strategy, while queues follow a First-In-First-Out (FIFO) strategy.
* Accessibility: In stacks, only the top element is accessible, while in queues, both the front and the rear elements are accessible.
* Implementation: While both stacks and queues can be implemented using arrays or linked lists, queues can additionally be implemented using circular arrays, heaps, or double-ended queues (deques).
* Usage: Stacks are useful for reversing the order of elements, while queues inherently preserve the original order of elements.

### Time Complexity

Understanding the time complexity of queue operations is critical for writing efficient code:

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(n)` | `O(n)` |
| Insert (Enqueue) | `O(1)` | `O(1)` |
| Delete (Dequeue) | `O(1)` | `O(1)` |
| Search | `O(n)` | `O(n)` |

Enqueue and dequeue operations are constant time, while accessing or searching for a specific element require linear time as all elements may need to be inspected.

### Implementation Details

Queues can be implemented using various underlying data structures, including arrays, linked lists, circular buffers, and dynamic arrays. The choice of implementation depends on the specific requirements of the application, such as memory usage, the cost of operations, and whether the size of the queue changes frequently.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/queue)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/simple_queue)

## Heaps

A _heap_ is a specialized tree-based data structure that satisfies the heap property. There are two main types of heaps: _max-heaps_ and _min-heaps_. 

- In a _max-heap_, the keys of parent nodes are always greater than or equal to those of the children, with the maximum key present at the root node.
- In a _min-heap_, the keys of parent nodes are always less than or equal to those of the children, with the minimum key present at the root node. 

Heaps are always complete binary trees, which means they are filled at all levels, except the last, which is filled from left to right. This structure ensures that the heap remains balanced.

```
        [100]
       /     \
    [19]     [36]
   /   \     /   \
 [17] [3]  [25]  [1]
```

### Key Methods of the Heap Interface

The basic operations of a heap are as follows:

* `insert(value)`: Adds a new element to the heap while ensuring that the heap property is preserved.
* `search(value)`: Searches for a specific value in the heap. Note that heaps do not allow efficient arbitrary searches.
* `remove(value)`: Deletes a specific value from the heap, then restructures the heap to maintain its properties.

### Practical Applications of Heaps

Heaps are versatile and find widespread use across various computational problems:

- Graph algorithms: Heaps are used in famous graph algorithms like Dijkstra's algorithm for shortest paths and Prim's algorithm for finding the minimum spanning tree.
- Priority queues: Heaps are the underlying data structure for efficient implementation of priority queues.
- Sorting: The heap sort algorithm leverages the properties of heaps to sort an array in-place with a worst-case time complexity of `O(n log n)`.

### Time Complexity of Heap Operations

The time complexity of standard heap operations is as follows:

| Operation | Average case |
| --- | --- |
| Find min/max | `O(1)` |
| Delete min/max | `O(log n)` |
| Insert | `O(log n)` |
| Merge | `O(m log(m+n))` |

These time complexities make heaps especially useful in situations where we need to repeatedly remove the minimum (or maximum) element.

### Implementation Details

Heaps can be represented efficiently using a one-dimensional array, which allows for easy calculation of the parent, left, and right child positions. The standard mapping from the heap to this array representation is as follows:

1. The root of the tree is placed at index 1.
2. For an element at index `i` in the array:
   - The left child is placed at index `2*i`.
   - The right child is placed at index `2*i + 1`.
3. The parent of an element at index `i` is placed at index `floor(i/2)`.

This layout keeps the parent-child relationships consistent and makes navigation within the heap straightforward and efficient.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/heap)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/heap)

## Binary Search Trees (BST)

A Binary Search Tree (BST) is a type of binary tree where each node has up to two children and maintains a specific ordering property among its values. For every node, the values of all nodes in its left subtree are less than its own value, and the values of all nodes in its right subtree are greater than its own value. In a well-balanced BST, this property enables efficient lookup, addition, and deletion operations, ideally distributing the nodes evenly across the left and right subtrees. Note that BSTs typically disallow duplicate values.

```
        [1]
       /   \
     [2]   [3]
    /   \     \
  [4]   [5]   [6]
```

### Key Operations of the BST Interface

The fundamental operations provided by a BST are:

* `insert(value)`: Inserts a new value into the tree, maintaining the BST property.
* `search(value)`: Searches for a specific value in the tree. If the value exists, the operation returns the node. If not, it typically returns `null`.
* `remove(value)`: Deletes a value from the tree, preserving the BST property. If the node to be removed has two children, it's replaced with its in-order predecessor or successor.
* `minimum()`: Retrieves the smallest value in the tree, which is the leftmost node.
* `maximum()`: Retrieves the largest value in the tree, which is the rightmost node.

### Time Complexity of BST Operations

The efficiency of BST operations depends on the height of the tree. In a balanced tree, this results in an average-case time complexity of `O(log n)`. However, in the worst-case scenario (a degenerate or unbalanced tree), the time complexity degrades to `O(n)`.

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `O(log n)` | `O(n)` |
| Insert | `O(log n)` | `O(n)` |
| Delete | `O(log n)` | `O(n)` |
| Search | `O(log n)` | `O(n)` |

### BST Implementation Details

A BST is typically implemented using a node-based model where each node encapsulates a value and pointers to the left and right child nodes. A special root pointer points to the first node, if any.

Insertion, deletion, and search operations are often implemented recursively to traverse the tree starting from the root, making comparisons at each node to guide the direction of traversal (left or right). This design pattern exploits the recursive nature of the tree structure and results in clean, comprehensible code.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/binary_search_tree)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/binary_search_tree)

## AVL Trees

Named after its inventors, G.M. Adelson-Velsky and E.M. Landis, AVL trees are a subtype of binary search trees (BSTs) that self-balance. Unlike regular BSTs, AVL trees maintain a stringent balance by ensuring the height difference between the left and right subtrees of any node is at most one. This tight control on balance guarantees optimal performance for lookups, insertions, and deletions, making AVL trees highly efficient.

```
       [20]       
      /    \
   [10]    [30]
  /   \     /   \
[5]  [15] [25]  [35]
```

### Key Characteristics of AVL Trees

The defining characteristics of AVL trees include:

- Every node's left and right subtrees differ in height by at most one.
- Both left and right subtrees of any node are also AVL trees, recursively applying the AVL property across the tree.

### Applications of AVL Trees

The AVL tree's self-balancing property lends itself to various applications, such as:

- Implementing associative arrays or sets in programming languages.
- Database storage and indexing, where rapid data retrieval is essential.
- Priority queues and dictionaries, where maintaining order is crucial.
- Word suggestion systems and spell checkers, which benefit from fast lookups.
- Networking algorithms and data compression, requiring efficient data structure.

### AVL Tree Interface and Methods

AVL trees support standard BST operations with some modifications to maintain balance:

- `insert(value)`: Add a value to the tree while preserving the AVL properties.
- `search(value)`: Find and return a node with the given value in the tree.
- `remove(value)`: Delete a node with the given value while keeping the tree balanced.
- `rotate_left()`, `rotate_right()`: Perform rotation operations to balance the tree after insertions or deletions.

### Time Complexity of AVL Tree Operations

Thanks to their self-balancing property, AVL trees ensure logarithmic time complexity for essential operations, even in the worst-case scenario.

| Operation | Average | Worst |
| --- | --- | --- |
| Access | `O(log n)` | `O(log n)` |
| Insert | `O(log n)` | `O(log n)` |
| Delete | `O(log n)` | `O(log n)` |
| Search | `O(log n)` | `O(log n)` |

### Implementation of AVL Trees

The key to maintaining AVL trees' balance is the application of rotation operations. Four types of rotations can occur based on the tree's balance state:

1. **Right rotation**: Applies when the left subtree of a node is taller than its right subtree. This rotation sets the node's left child as the new root, making the old root the right child of the new root. It concludes by updating the nodes' heights.

2. **Left rotation**: Applies when the right subtree of a node is taller than its left subtree. This rotation sets the node's right child as the new root and the old root as the left child of the new root. It concludes by updating the nodes' heights.

3. **Right-left rotation**: Applies when the right subtree of a node is taller, and the right child's left subtree is taller than its right. This rotation first applies a right rotation on the right child, followed by a left rotation on the initial node, updating node heights as needed.

4. **Left-right rotation**: Applies when the left subtree of a node is taller, and the left child's right subtree is taller than its left. This rotation first applies a left rotation on the left child, followed by a right rotation on the initial node, updating node heights as needed.

These rotations ensure that AVL trees maintain their crucial property of balance, offering consistently high performance.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/avl_tree)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/avl_tree)

## Red-Black Trees

Red-Black trees are a type of self-balancing binary search trees, with each node bearing an additional attribute: color. Each node in a Red-Black tree is colored either red or black, and these color attributes follow specific rules to maintain the tree's balance. This balance ensures that fundamental tree operations such as insertions, deletions, and searches remain efficient.

```
          (30B)      
         /     \
     (20R)    (40B)
    /   \      /   \
(10B) (25B) (35B) (50B)
```

### Key Properties of Red-Black Trees

Red-Black trees abide by the following essential properties:

- Every node in the tree is colored either red or black.
- The root node of the tree is always black.
- All leaves (NIL or null nodes) are always black.
- If a node is red, then both its parent and its children nodes must be black. 
- For each node, any simple path from this node to any of its descendant NIL nodes contains the same number of black nodes.

### Applications of Red-Black Trees

Red-Black trees find application in several areas, including:

- Kernel and system programming, where they are used in the internals of many operating systems.
- Implementing maps, sets, and multi-maps in programming languages like C++ (as part of the Standard Template Library) and Java (in the TreeMap and TreeSet classes).
- Underlying data structures for various advanced tree-based data structures and algorithms, such as splay trees and treaps.

### Red-Black Tree Interface and Methods

Red-Black trees support typical BST operations, albeit with additional steps to manage node colors and balance:

- `insert(value)`: Add a value to the tree, managing colors and rotations to maintain balance.
- `search(value)`: Find and return a node with the given value in the tree.
- `remove(value)`: Delete a node with the given value, adjusting colors and performing rotations as necessary to keep the tree balanced.
- `rotate_left()`, `rotate_right()`: Perform rotation operations to maintain balance after insertions or deletions.

### Time Complexity of Red-Black Tree Operations

Due to their self-balancing nature, Red-Black trees ensure efficient performance even in the worst-case scenarios, with a logarithmic time complexity for key operations:

| Operation | Average | Worst |
| --- | --- | --- |
| Access | `O(log n)` | `O(log n)` |
| Insert | `O(log n)` | `O(log n)` |
| Delete | `O(log n)` | `O(log n)` |
| Search | `O(log n)` | `O(log n)` |

### Implementation of Red-Black Trees

Red-Black trees are a sophisticated binary search tree variant. They require careful management of node colors during insertions and deletions, often involving multiple rebalancing steps:

1. Standard BST insertion is performed initially.
2. If the new node is the tree root, it's colored black to satisfy the Red-Black tree properties.
3. If the new node's parent is black, no further action is needed.
4. If the new node's parent is red, and its uncle (the sibling of its parent) is also red, both the parent and uncle are recolored black, and the grandparent is recolored red (if not the root). This step is known as "recoloring."
5. If the new node's parent is red, but its uncle is black or NIL, the tree might need a rotation or a series of rotations. These rotations can be left, right, or a combination of both based on the relative placements of the new node, its parent, and its grandparent. These rotations aim to restructure the tree while preserving the BST property and restoring the Red-Black tree properties.

These careful rotations and recoloring steps enable Red-Black trees to maintain balance and ensure efficient performance across various operations.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/red_black_tree)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/red_black_tree)

## Hash Tables

Hash tables, often referred to as hash maps or dictionaries, are a type of data structure that employs a hash function to pair keys with their corresponding values. This mechanism enables efficient insertion, deletion, and lookup of items within a collection, making hash tables a fundamental tool in many computing scenarios. They are typically used in contexts where swift lookup and insertion operations are critical, such as in database management and networking applications.

```
+-----------------+
| Key | Value     |
|-----|-----------|
| K1  | V1        |
| K2  | V2        |
| K3  | V3        |
| K4  | V4        |
| ... | ...       |
+-----------------+
```

### Key Applications of Hash Tables

Hash tables are ubiquitous across various domains, including:

- Databases and caching systems leverage hash tables to achieve quick insertion, deletion, and lookup operations.
- Networking applications use hash tables for rapid data retrieval and updates.
- They are employed within string searching algorithms, such as the Rabin-Karp algorithm, enabling efficient substring search.
- Data visualization often involves creating histograms, which use hash tables for binning data.

### Basic Operations of a Hash Table

Hash tables support a range of operations, which include:

- `is_empty()`: This method checks if the hash table is empty and returns `True` if so, or `False` otherwise.
- `insert(key, value)`: This method adds a new key-value pair to the hash table.
- `retrieve(key)`: This function fetches the value associated with a specified key.
- `update(key, value)`: This operation modifies the value associated with a given key.
- `delete(key)`: This function removes the key-value pair corresponding to the provided key from the hash table.
- `traverse()`: This method allows iteration over all the key-value pairs in the hash table.

### Time Complexity of Hash Table Operations

The performance of hash table operations depends on the hash function's quality, the strategy for resolving collisions, and the load factor (the ratio of the number of key-value pairs to the number of slots or buckets in the table).

| Operation | Average case | Worst case |
| --- | --- | --- |
| Access | `-` | `-` |
| Insert | `O(1)` | `O(n)` |
| Delete | `O(1)` | `O(n)` |
| Search | `O(1)` | `O(n)` |

### Implementing Hash Tables

The creation of a hash table involves setting up a data structure to store key-value pairs, designing a hash function to map keys to slots in the data structure, and devising a collision resolution strategy to handle instances where multiple keys hash to the same slot. 

Common data structures used include arrays (for open addressing) and linked lists or balanced trees (for separate chaining).

#### Hash Function

The hash function plays a pivotal role in a hash table's performance as it determines where a key-value pair will be stored within the table. An ideal hash function distributes keys evenly across the table, balancing the number of keys in each bucket. This uniform distribution can be achieved by leveraging prime numbers both for the size of the hash table and within the hash function itself. When hashing strings, a common approach is to calculate the ASCII value for each character, add them, and then compute the modulo with respect to the size of the table.

```
# n: number of keys
# m: number of buckets 
h(x) = n % m
```

#### Collision Resolution

Collisions occur when two or more keys hash to the same slot. There are two common strategies to handle these collisions: chaining and open addressing.

##### Chaining

With chaining, each slot or bucket in the hash table acts as a linked list. Each new key-value pair is appended to its designated list. While this approach allows for efficient insertions and deletions, the worst-case time complexity for lookups escalates to `O(n)`, where `n` is the number of keys stored.

The following is an example:

```
index  Bucket
---------------------
0      -> ["apple"]
1      -> ["banana", "mango"]
2      -> ["cherry"]
3      -> []
4      -> ["dates", "elderberry", "fig"]
...
```

In the above example, "banana" and "mango" hash to the same index (1), so they are stored in the same linked list.

##### Open Addressing

In open addressing, the hash table is an array, and each key-value pair is stored directly in an array slot. When a collision arises, the hash table searches for the next available slot according to a predefined probe sequence. Common probing techniques include linear probing, where the table checks each slot one by one, and quadratic probing, which checks slots based on a quadratic function of the distance from the original hash.

Here's an example using linear probing:

```
index  Bucket
---------------------
0      -> "apple"
1      -> "cherry"
2      -> "banana"  (originally hashed to 1, moved due to collision)
3      -> "mango"   (originally hashed to 1, moved due to collision)
4      -> "dates"
5      -> "elderberry"
6      -> "fig"
...
```

In this case, "banana" and "mango" were hashed to index 1, but since it was already occupied by "cherry", they were moved to the next available slots (2 and 3, respectively).

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/cpp/hash_table)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/collections_and_containers/python/hash_table)
