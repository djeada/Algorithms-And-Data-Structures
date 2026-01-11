"""Kruskal's algorithm for Minimum Spanning Tree (MST)."""

from __future__ import annotations

from graph import Graph, Vertex


def kruskal(graph: Graph) -> float:
    """
    Find the minimum spanning tree weight using Kruskal's algorithm.

    Uses Union-Find data structure with path compression and union by rank
    for efficient O(E log E) performance.

    Args:
        graph: The graph to find the MST for.

    Returns:
        The total weight of the minimum spanning tree.
    """
    rank: dict[Vertex, int] = {}
    parent: dict[Vertex, Vertex] = {}

    def find(vertex: Vertex) -> Vertex:
        if vertex != parent[vertex]:
            parent[vertex] = find(parent[vertex])
        return parent[vertex]

    def merge(x: Vertex, y: Vertex) -> None:
        x = find(x)
        y = find(y)

        if rank[x] > rank[y]:
            parent[y] = x
        else:
            parent[x] = y

        if rank[x] == rank[y]:
            rank[y] += 1

    for vertex in graph.vertices():
        rank[vertex] = 0
        parent[vertex] = vertex

    result = 0.0

    edges = graph.edges()
    edges.sort()

    for edge in edges:
        u = edge.source
        v = edge.destination

        set_u = find(u)
        set_v = find(v)

        if set_u != set_v:
            result += edge.distance
            merge(set_u, set_v)

    return result
