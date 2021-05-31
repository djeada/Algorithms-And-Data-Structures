from graph import Graph


def dfs(graph, source, destination):

    if not (graph.contains(source) and graph.contains(destination)):
        return float("inf")

    distances = dict()
    visited = dict()

    for vertex in graph.vertices():
        distances[vertex] = float("inf")
        visited[vertex] = False

    distances[source] = 0
    visited[source] = True

    def search(u):
        visited[u] = True

        for edge in graph.edges_from_vertex(u):

            v = edge.destination

            if not visited[v]:
                distances[v] = distances[u] + edge.distance
                search(v)

    search(source)

    return distances[destination]
