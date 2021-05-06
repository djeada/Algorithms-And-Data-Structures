class Node(object):

	def __init__(self, name):
		self.name = name;
		self.adjacenciesList = [];
		self.visited = False;
		self.predecessor = None;
		
class DepthFirstSearch(object): # BFS -> queue + layer by layer algorithm   DFS -> stack + goes as deep aspossible into the tree !!!

	def dfs(self, node):
	
		node.visited = True;
		print("%s " % node.name);
		
		for n in node.adjacenciesList:
			if not n.visited:
				self.dfs(n);
		
	
node1 = Node("A");
node2 = Node("B");
node3 = Node("C");
node4 = Node("D");
node5 = Node("E");		
	
node1.adjacenciesList.append(node2);
node1.adjacenciesList.append(node3);
node2.adjacenciesList.append(node4);
node4.adjacenciesList.append(node5);	

dfs = DepthFirstSearch();
dfs.dfs(node1);
