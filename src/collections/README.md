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

Applications:
- In stack-oriented programming languages
- Graph algorithms: depth-first search can be implemented with stacks ( or with recursion )
- Finding Euler-cycles in a graph
- Finding strongly connected components in a graph
