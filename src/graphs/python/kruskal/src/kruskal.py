def kruskal(graph):

    rank = dict()
    parent = dict()

    def find(vertex):
        if vertex != parent[vertex]:
            parent[vertex] = find(parent[vertex])

        return parent[vertex]

    def merge(x, y):
        x = find(x)
        y = find(y)

        if rank[x] > rank[y]:
            parent[y] = x
        else:
            parent[x] = y

        if rank[x] == rank[y]:
            rank[y] += 1

    for vertex in graph.vertices():
        rank[vertex] = 0
        parent[vertex] = vertex

    result = 0

    edges = graph.edges()
    edges.sort()

    for edge in edges:

        u = edge.source
        v = edge.destination

        set_u = find(u)
        set_v = find(v)

        if set_u != set_v:
            result += edge.distance
            merge(set_u, set_v)

    return result
