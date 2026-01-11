"""
Eulerian Path Algorithm.

An Eulerian path is a trail in a finite graph that visits every edge exactly once.
Vertices can be revisited.

This module implements Fleury's algorithm for finding Eulerian paths in graphs.
"""

from __future__ import annotations

from copy import copy
from typing import TypeAlias

# Type alias for adjacency list graph representation
AdjacencyGraph: TypeAlias = dict[int, list[int]]


def is_connected(graph: AdjacencyGraph) -> bool:
    """
    Check if the graph is connected using BFS.

    Args:
        graph: The graph as an adjacency list.

    Returns:
        True if all vertices are reachable from the first vertex.
    """
    if not graph:
        return True

    start_node = list(graph)[0]
    color: dict[int, str] = {v: "white" for v in graph}
    color[start_node] = "gray"
    stack = [start_node]

    while stack:
        u = stack.pop()
        for v in graph[u]:
            if color[v] == "white":
                color[v] = "gray"
                stack.append(v)
        color[u] = "black"

    return list(color.values()).count("black") == len(graph)


def edges_from_adjacency(graph: AdjacencyGraph) -> list[tuple[int, int]]:
    """
    Convert adjacency list to list of edges.

    Args:
        graph: The graph as an adjacency list.

    Returns:
        List of (source, destination) tuples.
    """
    return [(u, v) for u in graph for v in graph[u]]


def fleury(graph: AdjacencyGraph) -> list[tuple[int, int]] | bool:
    """
    Find an Eulerian path using Fleury's algorithm.

    Fleury's algorithm works by:
    1. Starting from a vertex with odd degree (or any vertex if all have even degree)
    2. At each step, choosing an edge that is not a bridge (unless there's no choice)
    3. Removing the edge and continuing until all edges are visited

    Args:
        graph: The graph as an adjacency list (undirected graph represented
               by having edges in both directions).

    Returns:
        A list of edges forming the Eulerian path, or False if no Eulerian path exists.
    """
    odd_degree_nodes = [u for u in graph if len(graph[u]) % 2 != 0]

    # Eulerian path exists only if 0 or 2 vertices have odd degree
    if len(odd_degree_nodes) > 2 or len(odd_degree_nodes) == 1:
        return False

    g = {k: list(v) for k, v in graph.items()}  # Deep copy
    trail: list[tuple[int, int]] = []

    # Start from odd-degree vertex if exists, otherwise from any vertex
    u = odd_degree_nodes[0] if len(odd_degree_nodes) == 2 else list(g)[0]

    while edges_from_adjacency(g):
        current_vertex = u

        for u in g[current_vertex]:
            g[current_vertex].remove(u)
            g[u].remove(current_vertex)
            bridge = not is_connected(g)

            if bridge:
                g[current_vertex].append(u)
                g[u].append(current_vertex)
            else:
                break

        if bridge:
            g[current_vertex].remove(u)
            g[u].remove(current_vertex)
            g.pop(current_vertex)

        trail.append((current_vertex, u))

    return trail
