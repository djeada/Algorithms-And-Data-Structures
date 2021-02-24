class Edge:
	def __init__(self, dest, weight):
		self.dest = dest
		self.weight = weight

class Node:
	def __init__(self, value, weight):
		self.value = value

class Graph:

	def __init__(self):
		 self._adj_dict = dict()
	
	def generate_from_links(self, links):
		#add validation len(link) == 2
		for link in links:
			for node in link:
				if node not in graph:
					self._adj_dict[node] = []

			self._adj_dict[link[0]].append(link[1])
			self._adj_dict[link[1]].append(link[0])

	def display(self):
	    for vertex, edge self._adj_dict.items():
		print('({} —> {}, {})'.format(vertex, edge.dest, edge.weight))


#Tests
#links = [('A', 'B'), ('C', 'A'), ('E', 'B'), ('D', 'C'), ('C', 'B'), ('A', 'D')]
#result = {'A': ['B', 'C', 'D'], 'B': ['A', 'E', 'C'], 'C': ['A', 'D', 'B'], 'E': ['B'], 'D': ['C', 'A']}
#assert(generateGraphFromLinksV1(links) == result)

