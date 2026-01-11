"""Breadth-First Search (BFS) algorithm for unweighted shortest paths."""

from __future__ import annotations

import math
from collections import deque

from graph import Graph, Vertex


def bfs(graph: Graph, source: Vertex, destination: Vertex) -> float:
    """
    Find the shortest path between source and destination using BFS.

    Note: BFS finds the shortest path in terms of number of edges, but this
    implementation also tracks edge weights for consistency with other algorithms.

    Args:
        graph: The graph to search.
        source: The starting vertex.
        destination: The target vertex.

    Returns:
        The distance from source to destination, or infinity if no path exists.
    """
    if not (graph.contains(source) and graph.contains(destination)):
        return math.inf

    distances: dict[Vertex, float] = {}
    visited: dict[Vertex, bool] = {}

    for vertex in graph.vertices():
        distances[vertex] = math.inf
        visited[vertex] = False

    queue: deque[Vertex] = deque([source])

    distances[source] = 0
    visited[source] = True

    while queue:
        u = queue.popleft()

        for edge in graph.edges_from_vertex(u):
            v = edge.destination

            if not visited[v]:
                visited[v] = True
                distances[v] = distances[u] + edge.distance
                queue.append(v)

    return distances[destination]
