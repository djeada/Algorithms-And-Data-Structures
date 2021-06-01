from heapq import heappush, heappop


def prim(graph):

    visited = dict()

    vertices = graph.vertices()

    for vertex in vertices:
        visited[vertex] = False

    # pick random vertex
    vertex = vertices[0]
    visited[vertex] = True

    unvisited = [
        (edge.distance, edge.destination) for edge in graph.edges_from_vertex(vertex)
    ]

    result = 0

    while unvisited:
        distance, vertex = heappop(unvisited)

        if not visited[vertex]:
            visited[vertex] = True
            result += distance
            for edge in graph.edges_from_vertex(vertex):
                if not visited[edge.destination]:
                    heappush(unvisited, (edge.distance, edge.destination))
    return result
