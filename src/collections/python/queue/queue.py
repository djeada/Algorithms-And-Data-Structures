'''
It is an abstract data type (interface)

Basic operations: enqueue() and dequeue()

FIFO: first in first out

It can be implemented with linked lists

Applications: BFS

Enqueue operation: we just simply add the new item to the end of the queue

Dequeue operation: we just simply remove the item starting at the beginning of the queue // FIFO structure

Applications:

When a resource is shared with several consumers ( threads ): we store them in a queue For example: CPU scheduling

When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes For example: IO buffers
'''

#FIFO - first -> first

class Queue:

	def __init__(self):
		self.queue = []
		
	def empty(self):
		return self.queue == []
		
	def enqueue(self, data):
		self.queue.append(data)
		
	def dequeue(self):
		data = self.queue[0]
		del self.queue[0]
		return data
		
	def peek(self):
		return self.queue[0]
		
	def size(self):
		return len(self.queue)
