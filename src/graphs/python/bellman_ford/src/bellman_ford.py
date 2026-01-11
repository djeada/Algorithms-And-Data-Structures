"""Bellman-Ford algorithm for shortest paths with negative edges."""

from __future__ import annotations

import math

from graph import Graph, Vertex


def bellman_ford(graph: Graph, source: Vertex, destination: Vertex) -> float:
    """
    Find the shortest path between source and destination using Bellman-Ford algorithm.

    This algorithm handles negative edge weights and detects negative cycles.

    Args:
        graph: The graph to search.
        source: The starting vertex.
        destination: The target vertex.

    Returns:
        The shortest distance from source to destination, or infinity if no path exists
        or if a negative cycle is detected.
    """
    if not (graph.contains(source) and graph.contains(destination)):
        return math.inf

    if source == destination:
        return 0

    distances: dict[Vertex, float] = {}

    for vertex in graph.vertices():
        distances[vertex] = math.inf

    distances[source] = 0

    for _ in range(graph.size() - 1):
        for edge in graph.edges():
            new_distance = distances[edge.source] + edge.distance

            if (
                distances[edge.source] != math.inf
                and new_distance < distances[edge.destination]
            ):
                distances[edge.destination] = new_distance

    for edge in graph.edges():
        if (
            distances[edge.source] != math.inf
            and distances[edge.source] + edge.distance < distances[edge.destination]
        ):
            # Graph contains negative weight cycle
            return math.inf

    return distances[destination]
