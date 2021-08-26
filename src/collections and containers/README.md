# Collections and containers

For our purposes, the words data structures and containers are interchangeable. Collections are a type of data structure that holds a variable number of objects. We will be describing various collections in this section.

Collections can involve virtually anything, for example, a set of integers [5, 7, 2, 3 and 4] or strings [item_a, item_c, item_b] 

We can speak about them on two different levels:

1. on a very abstract level: we can define what we mean by them and what can we do with them.
2. on a machine level: we figure out how to implement them.

<h1>Linked List</h1>

A linked list's elements are made up of two cells. The element's data (or a pointer to that data) is stored in the first cell. The second cell holds a reference to the next element in the list or NULL if there is no next element.

<h2>Basic operations</h2>

* is_empty(): it is self-explanatory.
* first(): access the first item in the list.
* append(element): append the provided element at the end of the list.
* remove(index): remove an element from the list that is stored at the provided index.
* replace(index, data): store the provided data at the specified index in the list.

<h2>Implementation</h2>
There are several methods for implementing lists, and the best one depends on the programming language used. Lists are the most important primitive data structure in the programming language Lisp and its derivates. Lists are more natural to implement as arrays in certain languages, however this might be troublesome because lists are not theoretically restricted in size.

Recursion is a natural way to process collections of items stored in linked lists. To find the last element of a list we can simply keep removing the first remaining item until there are no more left. The running time of this depends on the length of the list, and is proportional to that length.

<h1>Vector</h1>
TODO

<h1>Stack</h1>
They are the ideal data structure to model a First-In-Last-Out (FILO), or Last-In-First-Out (LIFO), strategy in search. 
A number of programming languages are stack-oriented, meaning they define most basic operations (adding two numbers, printing a character) as taking their arguments from the stack, and placing any return values back on the stack.

<h2>Basic operations</h2>

* push(element): it takes an element and places it on top of an existing stack O(1)
* pop(): it returns the top element of a stack and removes it from the stack O(1)
* top(): it returns the top element of a stack without removing it from the stack O(1)

<h2>Implementation</h2>
In most programming languages, a stack can be easily implemented either with arrays or linked lists. There are however two approaches that could be taken:

1. The number of items in an original stack is never changed in a functional approach. A new stack is created by the push operation.
2. Another approach to think about it is to imagine a single stack that has been destructively modified, so that after applying push, the old stack no longer exists, but has been replaced by a new stack with an extra element. This is theoretically more complex, because applying top now may provide various results depending on how the system's state has changed.

<h2>Applications:</h2>

- In stack-oriented programming languages
- Graph algorithms: depth-first search can be implemented with stacks ( or with recursion )
- Finding Euler-cycles in a graph
- Finding strongly connected components in a graph

<h1>Queue</h1>
A queue is a data model that supports a First-In-First-Out (FIFO) approach.

<h2>Basic operations</h2>

* enqueue(element): append the provided element at the end of the queue.
* dequeue(): remove the first element from the queue.

<h2>Implementation</h2>
In most programming languages, a queue can be easily implemented with linked lists. 

<h2>Applications:</h2>

- BFS
- When a resource is shared with several consumers ( threads ): we store them in a queue For example: CPU scheduling
- When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes For example: IO buffers

<h1>Heap</h1>
It is a binary tree.

In a max heap, the keys of parent nodes are always greater than or equal to those of the children and the highest key is in the root
node. In a min heap, the keys of parent nodes are less than or equal to those of the children and the lowest key is in the root node

It is complete: it cannot be unbalanced.  
We insert every new item to the next available place.

It has nothing to do with the pool of memory from which dynamically allocated memory is allocated.

<h2> Time complexity </h2>

| Operation | Average case | 
| --- | --- | 
| <i>Find min/max</i> | O(1) |
| <i>Delete min/max</i> | O(logn) |
| <i>Insert</i> | O(logn) |
| <i>merge</i> | O(mlog(m+n)) | 

<h2>Applications:</h2>

- Graph algorithms: Dijkstra algorithm, Prims algorithm
- Used to implement a priority queue

<h2>Heapsort</h2>

- comparison-based sorting algorithm
- uses heap data structure
- in-place
- unstable
- does not need additional memory
- while it is slightly slower in practice on most machines than a well-implemented quicksort, it has a better worst-case O(n log n) runtime.

<h1>Hash table</h1>

In a balanced BST we can achieve O(logn) time complexity for several operations including search.

Can it get better?

Yes, we can theoretically reach O(1) in hash tables.

If we know index in an array we can retrive and insert element in O(1).
What if we had a function that could give us that index for any input?

This function is called hash function.

<h2>Hash function</h2>

- Purpose: Distribute the keys uniformly into buckets
- Example:
1. n: number of keys
1. m: number of buckets 
1. h(x) = n % m

To ensure that the distribution is uniform, we can use prime numbers both for the size of the array and in our hash function.
For string we could compute the ASCII value for each character, add them together, and calculate modulo.

<h2>Collisions</h2>

Problem: Two or more inputs give the same output.

Solutions:
1. Collision resolution with chaining: we put multiple entries into the same slot with the help of a linked list
- If theere are many collisions: O(1) complexity gets worse !
- It has an additional memory cost due to the references

2. Open addressing: better solution
- If collision occurs, we find an empty slot instead
- Linear probing: if a collision occures, we try the next slot ... if there is a collision too we keep trying the next slot until we find an empty slot
- Quadratic probing: we trying slots 1,2,4,8... units far away
- Rehashing: we hash the result again in order to find an empty slot

<h2> Applications:</h2>

- Databases: hashing is often easier than searching trees.
- In large networks, lookup tables ( lookup for IP addresses )
- Histograms are a type of graph that shows the distribution of data (ex. frequencies of charachter occurences in a string)
- For substring search, the Rabin-Karp algorithm uses the hashing technique.

<h1>Red-black tree</h1>
The length of time it takes for BST operations to complete is determined by the height of the binary search tree; in order to achieve the best results, we should keep the tree balanced.

The heights of any node's two child subtrees vary by no more than one in an AVL tree.

Since they are more rigidly balanced, AVL trees are faster than red-black trees, but they need more memory.

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Space</i> | O(n) | O(n) |
| <i>Insert</i> | O(logn) | O(logn) |
| <i>Delete</i> | O(logn) | O(logn) |
| <i>Search</i> | O(logn) | O(logn) |

<h2> Applications:</h2>
- Used internally by Operating Systems.

<h2> Properties </h2>

- Each node is either red or black
- The root node is always black
- All leaves (NIL) are black
- Every red node must have two black child nodes and no other children -> it must have a black parent
- Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes
- On every insertion -> we have to check whether we have violated the red-black properties or not

- If we have violated the RB properties: we have to rebalance the tree:
1. make rotations
1. OR just recolor the nodes
