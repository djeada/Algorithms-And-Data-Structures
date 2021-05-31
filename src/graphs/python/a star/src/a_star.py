from heapq import heappush, heappop


def a_star(graph, source, destination, heuristic):

    if not (graph.contains(source) and graph.contains(destination)):
        return float("inf")

    distance_from_source = dict()
    distance_till_destination = dict()
    # previous_vertex = dict()

    for vertex in graph.vertices():
        distance_from_source[vertex] = float("inf")
        distance_till_destination[vertex] = float("inf")

    distance_from_source[source] = 0
    distance_till_destination[source] = heuristic(source.value, destination.value)

    visited = list()
    heappush(visited, (distance_till_destination[source], source))

    while visited:

        current = heappop(visited)[1]

        if current == destination:
            return distance_from_source[destination]
            # return reconstruct_path(previous_vertex, current)

        for edge in graph.edges_from_vertex(current):

            tentative_distance_from_source = (
                distance_from_source[current] + edge.distance
            )

            if tentative_distance_from_source < distance_from_source[edge.destination]:
                # previous_vertex[edge.destination] = current
                distance_from_source[edge.destination] = tentative_distance_from_source
                distance_till_destination[edge.destination] = distance_from_source[
                    edge.destination
                ] + heuristic(edge.destination.value, destination.value)

                if edge.destination not in visited:
                    heappush(
                        visited,
                        (distance_till_destination[edge.destination], edge.destination),
                    )

    return float("inf")
