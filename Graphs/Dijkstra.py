def dijkstra(graph, node):
    dist = {}
    dist[node] = 0
    path = {}
    
    while (dist):
        opposite = min_distance(dist)
        path[opposite] = dist[opposite]
        
        del dist[opposite]
        
        for x, lenOfX in graph[opposite].items():
            
            if x not in path:
                
                if x not in dist:
                    dist[x] = path[opposite] + lenOfX
               
                elif dist[x] > path[opposite] + lenOfX:
                    dist[x] = path[opposite] + lenOfX
    return path
