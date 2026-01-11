"""Prim's algorithm for Minimum Spanning Tree (MST)."""

from __future__ import annotations

from heapq import heappush, heappop

from graph import Graph, Vertex


def prim(graph: Graph) -> float:
    """
    Find the minimum spanning tree weight using Prim's algorithm.

    Uses a priority queue (min-heap) for efficient O((V+E) log V) performance.

    Args:
        graph: The graph to find the MST for.

    Returns:
        The total weight of the minimum spanning tree.
    """
    visited: dict[Vertex, bool] = {}

    vertices = graph.vertices()

    for vertex in vertices:
        visited[vertex] = False

    # Pick first vertex as starting point
    vertex = vertices[0]
    visited[vertex] = True

    unvisited: list[tuple[float, Vertex]] = [
        (edge.distance, edge.destination) for edge in graph.edges_from_vertex(vertex)
    ]

    result = 0.0

    while unvisited:
        distance, vertex = heappop(unvisited)

        if not visited[vertex]:
            visited[vertex] = True
            result += distance
            for edge in graph.edges_from_vertex(vertex):
                if not visited[edge.destination]:
                    heappush(unvisited, (edge.distance, edge.destination))

    return result
