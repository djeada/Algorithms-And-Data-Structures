# Containers

<h1>Queue</h1>
It is an abstract data type (interface)
Basic operations: enqueue() and dequeue()
FIFO: first in first out
It can be implemented with linked lists
Applications: BFS
Enqueue operation: we just simply add the new item to the end of the queue
Dequeue operation: we just simply remove the item starting at the beginning of the queue // FIFO structure

Applications:
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

<h1>Red-black tree</h1>
The length of time it takes for BST operations to complete is determined by the height of the binary search tree; in order to achieve the best results, we should keep the tree balanced.

The heights of any node's two child subtrees vary by no more than one in an AVL tree.

Since they are more rigidly balanced, AVL trees are faster than red-black trees, but they need more memory.

<h2> Applications:</h2>
- Used internally by Operating Systems.

| Operation | Average case | Worst case |
| --- | --- | --- |
| <i>Space</i> | O(n) | O(n) |
| <i>Insert</i> | O(logn) | O(logn) |
| <i>Delete</i> | O(logn) | O(logn) |
| <i>Search</i> | O(logn) | O(logn) |

<h2> Properties </h2>

- Each node is either red or black
- The root node is always black
- All leaves (NIL) are black
- Every red node must have two black child nodes and no other children -> it must have a black parent
- Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes
- On every insertion -> we have to check whether we have violated the red-black properties or not

- If we have violated the RB properties: we have to rebalance the tree:
* make rotations
* OR just recolor the nodes
