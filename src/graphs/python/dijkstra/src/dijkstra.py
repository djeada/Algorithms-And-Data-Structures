"""Dijkstra's algorithm for shortest paths in graphs with non-negative weights."""

from __future__ import annotations

import math
from heapq import heappush, heappop

from graph import Graph, Vertex


def dijkstra(graph: Graph, source: Vertex, destination: Vertex) -> float:
    """
    Find the shortest path between source and destination using Dijkstra's algorithm.

    This implementation uses a priority queue (min-heap) for efficient O((V+E) log V)
    performance.

    Args:
        graph: The graph to search (must have non-negative edge weights).
        source: The starting vertex.
        destination: The target vertex.

    Returns:
        The shortest distance from source to destination, or infinity if no path exists.
    """
    if not (graph.contains(source) and graph.contains(destination)):
        return math.inf

    distances: dict[Vertex, float] = {}
    visited: dict[Vertex, bool] = {}

    for vertex in graph.vertices():
        distances[vertex] = math.inf
        visited[vertex] = False

    distances[source] = 0

    priority_queue: list[tuple[float, Vertex]] = [(0, source)]

    while priority_queue:
        current_distance, u = heappop(priority_queue)

        if visited[u]:
            continue

        visited[u] = True

        if u == destination:
            return distances[destination]

        for edge in graph.edges_from_vertex(u):
            v = edge.destination
            new_distance = distances[u] + edge.distance

            if new_distance < distances[v]:
                distances[v] = new_distance
                heappush(priority_queue, (new_distance, v))

    return distances[destination]
