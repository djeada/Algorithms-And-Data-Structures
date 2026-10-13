"""Prim's algorithm for Minimum Spanning Tree (MST)."""

from __future__ import annotations

from heapq import heappush, heappop
from itertools import count

from graph import Graph, Vertex


def prim(graph: Graph) -> float:
    """
    Find the minimum spanning tree weight using Prim's algorithm.

    Edges are treated as undirected. For a disconnected graph the weight of the
    minimum spanning forest is returned (consistent with Kruskal's algorithm).
    Uses a priority queue (min-heap) for efficient O((V+E) log V) performance.

    Args:
        graph: The graph to find the MST for.

    Returns:
        The total weight of the minimum spanning tree (or forest).
    """
    # Build an undirected adjacency view, since edges are stored one-way.
    adjacency: dict[Vertex, list[tuple[float, Vertex]]] = {
        vertex: [] for vertex in graph.vertices()
    }
    for edge in graph.edges():
        adjacency[edge.source].append((edge.distance, edge.destination))
        adjacency[edge.destination].append((edge.distance, edge.source))

    visited: set[Vertex] = set()
    result = 0.0
    counter = count()  # tie-breaker so vertices never need to be comparable

    for start in graph.vertices():
        if start in visited:
            continue

        visited.add(start)
        heap: list[tuple[float, int, Vertex]] = []
        for distance, neighbor in adjacency[start]:
            heappush(heap, (distance, next(counter), neighbor))

        while heap:
            distance, _, vertex = heappop(heap)

            if vertex in visited:
                continue

            visited.add(vertex)
            result += distance
            for next_distance, neighbor in adjacency[vertex]:
                if neighbor not in visited:
                    heappush(heap, (next_distance, next(counter), neighbor))

    return result
