# Collections and containers

For our purposes, the words data structures and containers are interchangeable. Collections are a type of data structure that holds a variable number of items. We will be describing various collections in this section.

Collections can involve virtually anything, for example, a set of integers [5, 7, 2, 3 and 4] or strings [item_a, item_c, item_b] 

We can speak about them on two different levels:

1. on a very abstract level: we can define what we mean by them and what can we do with them.
2. on a machine level: we figure out how to implement them.

<h1>Linked List</h1>

A linked list's elements are made up of two cells. The element's data (or a pointer to that data)</code> is stored in the first cell. The second cell holds a reference to the next element in the list or NULL if there is no next element.

<h2>Basic operations</h2>

* <code>is_empty()</code>: it is self-explanatory.
* <code>first()</code>: access the first item in the list.
* <code>append(element)</code>: append the provided element at the end of the list.
* <code>remove(index)</code>: remove an element from the list that is stored at the provided index.
* <code>replace(index, data)</code>: store the provided data at the specified index in the list.

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>O(n)</code> | <code>O(n)</code> |
| <i>Insert</i> | <code>O(1)</code> | <code>O(1)</code> |
| <i>Delete</i> | <code>O(1)</code> | <code>O(1)</code> |
| <i>Search</i> | <code>O(n)</code> | <code>O(n)</code> |

<h2>Implementation</h2>
There are several methods for implementing lists, and the best one depends on the programming language used. Lists are the most important primitive data structure in the programming language Lisp and its derivatives. Lists are more natural to implement as arrays in certain languages, however this might be troublesome because lists are not theoretically restricted in size.

Recursion is a natural way to process collections of items stored in linked lists. To find the last element of a list we can simply keep removing the first remaining item until there are no more left. The running time of this depends on the length of the list, and is proportional to that length.

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Vector</h1>

Because they are so simple to implement in a machine, arrays were most likely the first data structures to be used. Array elements are generally kept in continuous chunks of computer memory. Arrays are represented by items separated by commas and enclosed in square brackets:

a = [8, 5, 4, 9, 3]

Because this array a has 5 elements, we refer to it as having a size of 5. We generally begin numbering at 1 in everyday life. However, when working with arrays in computer science, we frequently begin with 0. We write a[i] to signify the element in the ith position for any integer i denoting a position. For array <i>a</i> we have: a[0] = 8, a[1] = 5, a[2] = 4, and so on.

A fixed-size sequential collection of elements of the same type is stored in an array. Vectors are nearly identical, with the exception that they can manage storage and expand dynamically in an efficient manner. In reality, arrays are very low-level constructs that you should definitely avoid as much as possible. Vectors have almost the same performance as arrays, but with many more conveniences and safety features.

<h2>Applications:</h2>

- storing a list of values
- matrix operations
- implementation of search and sorting algorithms
- implementation of data structures

<h2>Basic operations</h2>

* <code>is_empty()</code>: it is self-explanatory.
* <code>push_back(elem)</code>:	append the provided element at the end of the vector.
* <code>pop_back()</code>: return the vector's last element.
* <code>clear()</code>:	remove all elements from the vector.
* <code>erase(position)</code>:	remove the element from the vector at the specified position.
* <code>sort(start, end)</code>: sort vector elements between position start and position end.
* <code>reverse(start, end)</code>:	reverse vector elements between position start and position end.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Stack</h1>
They are the ideal data structure to model a First-In-Last-Out (FILO)</code>, or Last-In-First-Out (LIFO)</code>, strategy in search. 
A number of programming languages are stack-oriented, meaning they define most basic operations (adding two numbers, printing a character)</code> as taking their arguments from the stack, and placing any return values back on the stack.

<h2>Basic operations</h2>

* <code>push(element)</code>: take an element and place it on top of an existing stack.
* <code>pop()</code>: return the top element of the stack and removes it from the stack.
* <code>top()</code>: return the top element of the stack without removing it from the stack.

<h2>Applications:</h2>

- In stack-oriented programming languages
- Graph algorithms: depth-first search can be implemented with stacks ( or with recursion )</code>
- Finding Euler-cycles in a graph
- Finding strongly connected components in a graph

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>O(n)</code> | <code>O(n)</code> |
| <i>Insert</i> | <code>O(1)</code> | <code>O(1)</code> |
| <i>Delete</i> | <code>O(1)</code> | <code>O(1)</code> |
| <i>Search</i> | <code>O(n)</code> | <code>O(n)</code> |

<h2>Implementation</h2>
In most programming languages, a stack can be easily implemented either with arrays or linked lists. There are however two approaches that could be taken:

1. The number of items in an original stack is never changed in a functional approach. A new stack is created by the push operation.
2. Another approach to think about it is to imagine a single stack that has been destructively modified, so that after applying push, the old stack no longer exists, but has been replaced by a new stack with an extra element. This is theoretically more complex, because applying top now may provide various results depending on how the system's state has changed.

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Queue</h1>
A queue is a data model that supports a First-In-First-Out (FIFO)</code> approach.

<h2>Basic operations</h2>

* <code>enqueue(element)</code>: append the provided element at the end of the queue.
* <code>dequeue()</code>: remove the first element from the queue.

<h2>Applications:</h2>

- BFS
- When a resource is shared with several consumers ( threads )</code>: we store them in a queue For example: CPU scheduling.
- When data is transferred asynchronously (data not necessarily received at same rate as sent)</code> between two processes For example: IO buffers.


<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>O(n)</code> | <code>O(n)</code> |
| <i>Insert</i> | <code>O(1)</code> | <code>O(1)</code> |
| <i>Delete</i> | <code>O(1)</code> | <code>O(1)</code> |
| <i>Search</i> | <code>O(n)</code> | <code>O(n)</code> |

<h2>Implementation</h2>
In most programming languages, a queue can be easily implemented with linked lists. 

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Heap</h1>
Heaps are a kind of binary tree. There are two types of heaps: maximum heaps and minimum heaps.

The keys of parent nodes are always larger than or equal to those of the children in a max heap, and the root node has the largest key. The keys of parent nodes in a min heap are less than or equal to those of the children, and the root node has the smallest key.

Heaps are complete, which means they can never be imbalanced. Every new item is placed in the next available space.

Important: It has nothing to do with the pool of memory from which dynamically allocated memory is allocated.

<h2>Basic operations</h2>

* <code>insert(element)</code>: the new element is inserted in a suitable place, preserving the heap's characteristics.
* <code>delete(node)</code>: remove the given node and re-heap any nodes located beneath it.
* <code>merge(heap_b)</code>: merging heap_b and heap_a means including all nodes from heap_b to heap_a. The heap type returned will be the same as heap_a.

<h2>Applications:</h2>

- Internally used by several graph algorithms, including the Dijkstra and Prims algorithms.
- Used to implement a priority queue.
- Heap sort is a heap data structure-based sorting algorithm.

<h2>Time complexity </h2>

| Operation | Average case | 
| --- | --- | 
| <i>Find min/max</i> | <code>O(1)</code> |
| <i>Delete min/max</i> | <code>O(logn)</code> |
| <i>Insert</i> | <code>O(logn)</code> |
| <i>Merge</i> | <code>O(mlog(m+n)</code>)</code> | 

<h2>Implementation</h2>

Since heap is a complete binary tree, a heap tree can be efficiently represented using one dimensional array. This provides a very convenient way of figuring out where children belong to.

* The root of the tree is placed at index 1.
* The left child of an element with index <code>i</code> is placed at index <code>2*i</code>.
* The right child of an element with index <code>i</code> is placed at index <code>2*i + 1</code>.
* The parent of an element with index <code>i</code> is placed at index<code>floor(i/2)</code>.

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Binary search tree</h1>

To fully comprehend the idea of binary search trees, let us first define trees and binary trees.

<h2>Tree</h2>
In programming, a tree is a fairly general and powerful data structure that resembles a real tree. It is composed of an ordered collection of connected nodes, with each node having no more than one parent node and zero or more children nodes.

* Nodes are frequently, but not always, labeled with a data item (e.g. an integer)</code>. The label of a node will be referred to as its value.
* There must always be a distinct ‘top level' node known as the root. 
* Then, given a node, any node on the following level "down" that is related to it through a branch is a child of that node.
* In contrast, the node (there can only be one)</code> on the level above that is connected to the provided node (through an edge)</code> is its parent.
* A path is a series of linked edges connecting one node to another. 
* Trees have the characteristic that each node has a distinct path connecting it to the root.
* The length of the path linking a node to the root determines its depth or level. As a result, the root has a level of 0, its children have a level of 1, and so on.

<h2>Binary Tree</h2>
In computer science, binary trees are the most prevalent form of tree. 
A binary tree is one in which each node has no more than two children.
In contrast with binary search trees there is no constraint imposed on the values.

<h2>Properties</h2>
Binary search trees are binary trees that satisfy the following conditions:

* Each node has one value (key)</code>.
* The keys in the left subtree are smaller than the keys in the parent node.
* The keys in the right subtree are greater than the key in its parent node.
* It is not permitted to have duplicate node values.

<h2>Building binary search trees</h2>

To add <i>new_value</i> to the BST, we should do the following:

1. If the tree is empty, just assign the <i>new_value</i> to the root while leaving the left and right subtrees empty.
2. If the tree is non-empty, then do the following:
  - If <i>new_value</i> is less than the root value, place it into the left sub-tree.
  - If <i>new_value</i> is greater than the root value, place it into the right sub-tree.
  - If <i>new_value</i> equals the value of the root, throw an exception.
  
<h2>Basic operations</h2>

* <code>root()</code>: return the value of the root node of binary tree <code>O(1)</code>.
* <code>height()</code>: returns the height of the BST <code>O(1)</code>.
* <code>insert(value)</code>: place the provided value into an appropriate node in the BST.
* <code>search(value)</code>: look for a node with the specified value in the BST.
* <code>remove(value)</code>: remove a node with the specified value from the BST.

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>O(logn)</code> | <code>O(n)</code> |
| <i>Insert</i> | <code>O(logn)</code> | <code>O(n)</code> |
| <i>Delete</i> | <code>O(logn)</code> | <code>O(n)</code> |
| <i>Search</i> | <code>O(logn)</code> | <code>O(n)</code> |

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>AVL tree</h1>
TODO

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>O(logn)</code> | <code>O(logn)</code> |
| <i>Insert</i> | <code>O(logn)</code> | <code>O(logn)</code> |
| <i>Delete</i> | <code>O(logn)</code> | <code>O(logn)</code> |
| <i>Search</i> | <code>O(logn)</code> | <code>O(logn)</code> |

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Red-black tree</h1>
The height of the binary search tree determines how long it takes for BST operations to finish. In order to obtain the best results, we need keep the tree balanced.

In an AVL tree, the heights of each node's two child subtrees differ by no more than one.

AVL trees are quicker than red-black trees because they are more strictly balanced, but they require more memory.

<h2> Properties </h2>

- Each node is either red or black.
- The root node is always black.
- All leaves (NIL)</code> are black.
- Every red node must have two black child nodes and no other children -> it must have a black parent.
- Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.
- On every insertion -> we have to check whether we have violated the red-black properties or not.

- If we have violated the RB properties: we have to re balance the tree:
1. make rotations.
1. OR just recolor the nodes.

<h2> Applications:</h2>
- Used internally by Operating Systems.

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>O(logn)</code> | <code>O(logn)</code> |
| <i>Insert</i> | <code>O(logn)</code> | <code>O(logn)</code> |
| <i>Delete</i> | <code>O(logn)</code> | <code>O(logn)</code> |
| <i>Search</i> | <code>O(logn)</code> | <code>O(logn)</code> |

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1>Hash table</h1>

We have already discussed the several types of trees that may reach O(logn) time complexity for a variety of tasks, including search. It's an incredible progression from our humble beginnings, but the question remains: can we get better? What if we placed each item in a readily defined position, eliminating the need to look for it and eliminating the necessity to preserve ordering while inserting or removing items? Yes, we can potentially achieve O(1) time complexity in a data structure known as a "hash table." This data structure has an amazing performance in terms of time, but that benefit is offset by the requirement for greater space, as well as by being more complex and hence more difficult to understand and implement.

<h2>Basic operations</h2>

* <code>is_empty()</code>: it is self-explanatory.
* <code>insert(elem)</code>:	append the provided element at the end of the vector.
* <code>retrive(key)</code>: return the vector's last element.
* <code>update(elem)</code>:	remove all elements from the vector.
* <code>delete(position)</code>:	remove the element from the vector at the specified position.
* <code>traverse()</code>: sort vector elements between position start and position end.

<h2>Hash function</h2>

This is a function that return an index for any input. 

- Purpose: Distribute the keys uniformly into buckets.
- Example:
1. n: number of keys
1. m: number of buckets 
1. h(x)</code> = n % m

To ensure that the distribution is uniform, we can use prime numbers both for the size of the array and in our hash function. For string we could compute the ASCII value for each character, add them together, and calculate modulo.

<h2>Collisions</h2>

Problem: Two or more inputs give the same output.

Solutions:
1. Collision resolution with chaining: we put multiple entries into the same slot with the help of a linked list.
- If there are many collisions: <code>O(1)</code> complexity gets worse!
- It has an additional memory cost due to the references.

2. Open addressing: better solution.
- If collision occurs, we find an empty slot instead.
- Linear probing: if a collision occurs, we try the next slot ... if there is a collision too we keep trying the next slot until we find an empty slot.
- Quadratic probing: we trying slots 1,2,4,8... units far away.
- Rehashing: we hash the result again in order to find an empty slot.

<h2> Applications:</h2>

- Databases: hashing is often easier than searching trees.
- In large networks, lookup tables (lookup for IP addresses)</code>.
- Histograms are a type of graph that shows the distribution of data (ex. frequencies of character occurrences in a string)</code>.
- For substring search, the Rabin-Karp algorithm uses the hashing technique.

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Access</i> | <code>-</code> | <code>-</code> |
| <i>Insert</i> | <code>O(1)</code> | <code>O(n)</code> |
| <i>Delete</i> | <code>O(1)</code> | <code>O(n)</code> |
| <i>Search</i> | <code>O(1)</code> | <code>O(n)</code> |

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>
