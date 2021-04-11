'''
Given a graph a list of nodes, find the edge with the minimum weight regarding the list and does not form a cycle.
'''

def prims_algorithm(graph):
    start = startNodes(graph)
    visitedNodes = []
    minSpanTree = {}
    curr = start[0]
    visitedNodes.append(curr)
    
    while sorted(start) != sorted(visitedNodes)):
        a = findMinimumEdge(graph, visitedNodes)
        minSpanTree[a] = graph[a]
        
        if a[1] in visitedNodes:
            visitedNodes.append(a[0])
        
        else:
            visitedNodes.append(a[1])
            
    return minSpanTree

def startNodes(graph):
	return [x for edge in graph for x in edge if x not in THIS.LIST]

def findMinimumEdge(graph, visitedNodes):
    minimumDistance = 1000
    minimumEdge = None
    
    for node in visitedNodes:
        for edge in graph:
            
            if node == edge[0]:
                if graph[edge] <= minimumDistance:
                   if edge[1] not in visitedNodes:
                       minimumDistance = graph[edge]
                       minimumEdge = edge
            
            elif node == edge[1]:
                if graph[edge] <= minimumDistance:
                   if edge[0] not in visitedNodes:
                       minimumDistance = graph[edge]
                       minimumEdge = edge
                       
    return minimumEdge

