from graph import Graph


def bfs(graph, source, destination):

    if not (graph.contains(source) and graph.contains(destination)):
        return -1

    distances = dict()
    visited = dict()

    for vertex in graph.vertices():
        distances[vertex] = float("inf")
        visited[vertex] = False

    queue = [source]

    distances[source] = 0
    visited[source] = True

    while queue:

        u = queue.pop(0)

        for edge in graph.edges_from_vertex(u):

            v = edge.destination

            if not visited[v]:
                visited[v] = True
                distances[v] = distances[u] + edge.distance
                queue.append(v)

    return distances[destination]
