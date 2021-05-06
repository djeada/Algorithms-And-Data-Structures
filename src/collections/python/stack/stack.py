'''
It is an abstract data type (interface)

Basic operations: pop(), push() and peek()

LIFO structure: last in first out

In most high level languages, a stack can be easily implemented either with arrays or linked lists

A number of programming languages are stack-oriented, meaning they define most basic operations (adding two numbers, printing a character) as taking their arguments from the stack, and placing any return values back on the stack

Push operation: put the given item to the top of the stack Very simple operation, can be done in O(1)

Pop operation: we take the last item we have inserted to the top of the stack (LIFO) Very simple operation, can be done in O(1)

Peek operation: return the item from the top of the stack without removing it Very simple operation, can be done in O(1)

Applications:

In stack-oriented programming languages

Graph algorithms: depth-first search can be implemented with stacks ( or with recursion )

Finding Euler-cycles in a graph

Finding strongly connected components in a graph
'''
class Stack:

	def __init__(self):
		self.stack = []
		
	def empty(self):
		return len(self.stack) == 0
		
	def push(self, data):
		self.stack.append(data)
		
	def pop(self):
		data = self.stack[-1]
		del self.stack[-1]
		return data
		
	def peek(self):
		return self.stack[-1]
		
	def size(self):
		return len(self.stack)
