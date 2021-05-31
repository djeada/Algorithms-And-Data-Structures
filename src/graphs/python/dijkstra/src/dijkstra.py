from graph import Graph


def dijkstra(graph, source, destination):

    if not (graph.contains(source) and graph.contains(destination)):
        return float("inf")

    distances = dict()
    visited = dict()

    for vertex in graph.vertices():
        distances[vertex] = float("inf")
        visited[vertex] = False

    distances[source] = 0

    def find_min_distance():
        min_distance = float("inf")
        min_vertex = None

        for vertex in graph.vertices():
            if not visited[vertex] and distances[vertex] <= min_distance:
                min_distance = distances[vertex]
                min_vertex = vertex

        return min_vertex

    for i in range(graph.size() - 1):

        u = find_min_distance()
        visited[u] = True

        for edge in graph.edges_from_vertex(u):
            v = edge.destination
            new_distance = distances[u] + edge.distance
            if new_distance < distances[v]:
                distances[v] = new_distance

    return distances[destination]
