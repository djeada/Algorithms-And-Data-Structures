"""Depth-First Search (DFS) algorithm for graph traversal."""

from __future__ import annotations

import math

from graph import Graph, Vertex


def dfs(graph: Graph, source: Vertex, destination: Vertex) -> float:
    """
    Find a path between source and destination using DFS.

    Note: DFS does not guarantee the shortest path. For shortest paths,
    use BFS (unweighted) or Dijkstra/Bellman-Ford (weighted).

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

    distances[source] = 0
    visited[source] = True

    def search(u: Vertex) -> None:
        visited[u] = True

        for edge in graph.edges_from_vertex(u):
            v = edge.destination

            if not visited[v]:
                distances[v] = distances[u] + edge.distance
                search(v)

    search(source)

    return distances[destination]
