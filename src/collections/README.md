# Containers

<h1>Queue</h1>
It is an abstract data type (interface)
Basic operations: enqueue() and dequeue()
FIFO: first in first out
It can be implemented with linked lists
Enqueue operation: we just simply add the new item to the end of the queue
Dequeue operation: we just simply remove the item starting at the beginning of the queue // FIFO structure

<h2>Applications:</h2>

- BFS
- When a resource is shared with several consumers ( threads ): we store them in a queue For example: CPU scheduling
- When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes For example: IO buffers

<h1>Stack</h1>
It is an abstract data type (interface)
Basic operations: pop(), push() and peek()
LIFO structure: last in first out
In most high level languages, a stack can be easily implemented either with arrays or linked lists
A number of programming languages are stack-oriented, meaning they define most basic operations (adding two numbers, printing a character) as taking their arguments from the stack, and placing any return values back on the stack
Push operation: put the given item to the top of the stack Very simple operation, can be done in O(1)
Pop operation: we take the last item we have inserted to the top of the stack (LIFO) Very simple operation, can be done in O(1)
Peek operation: return the item from the top of the stack without removing it Very simple operation, can be done in O(1)

<h2>Applications:</h2>

- In stack-oriented programming languages
- Graph algorithms: depth-first search can be implemented with stacks ( or with recursion )
- Finding Euler-cycles in a graph
- Finding strongly connected components in a graph

<h1>Heap</h1>
It is a binary tree.

In a max heap, the keys of parent nodes are always greater than or equal to those of the children and the highest key is in the root
node. In a min heap, the keys of parent nodes are less than or equal to those of the children and the lowest key is in the root node

It is complete: it cannot be unbalanced.  
We insert every new item to the next available place.

It has nothing to do with the pool of memory from which dynamically allocated memory is allocated.

<h2> Time complexity </h2>

| Operation | Average case | Worst case |
| --- | --- | --- |
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
