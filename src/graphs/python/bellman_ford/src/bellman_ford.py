from graph import Graph


def bellman_ford(graph, source, destination):

    if not (graph.contains(source) and graph.contains(destination)):
        return float("inf")

    if source == destination:
        return 0

    distances = dict()
    visited = dict()

    for vertex in graph.vertices():
        distances[vertex] = float("inf")
        visited[vertex] = False

    distances[source] = 0

    for i in range(graph.size() - 1):
        for edge in graph.edges():

            new_distance = distances[edge.source] + edge.distance

            if (
                distances[edge.source] != float("Inf")
                and new_distance < distances[edge.destination]
            ):
                distances[edge.destination] = new_distance

    for edge in graph.edges():
        if (
            distances[edge.source] != float("Inf")
            and distances[edge.source] + edge.distance < distances[edge.destination]
        ):
            # Graph contains negative weight cycle
            return float("inf")

    return distances[destination]
