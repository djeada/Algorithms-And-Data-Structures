'''
You are given list of links/connections between nodes in graph. Construct the graph from the list.
'''
        
def generateGraphFromLinksV1(links):
    graph = {}

    for link in links:
        
        for node in link:
            if node not in graph:
                graph[node] = []
                
        graph[link[0]].append(link[1])
        graph[link[1]].append(link[0])
        
    return graph

#Tests
links = [('A', 'B'), ('C', 'A'), ('E', 'B'), ('D', 'C'), ('C', 'B'), ('A', 'D')]
result = {'A': ['B', 'C', 'D'], 'B': ['A', 'E', 'C'], 'C': ['A', 'D', 'B'], 'E': ['B'], 'D': ['C', 'A']}

assert(generateGraphFromLinksV1(links) == result)

