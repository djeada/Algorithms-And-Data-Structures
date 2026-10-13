from collections import defaultdict
from typing import Dict, List


class Graph:
    """A directed graph represented using an adjacency list."""

    def __init__(self, num_vertices: int = 0) -> None:
        """
        Initialize a graph with the specified number of vertices.

        Vertices are labelled 0..num_vertices-1; adding an edge that
        mentions a larger label grows the graph accordingly.

        Args:
            num_vertices: Initial number of vertices (default 0).
        """
        self.adjacency_dict: Dict[int, List[int]] = defaultdict(list)
        self.num_vertices: int = num_vertices

    def add_edge(self, u: int, v: int) -> None:
        """
        Add a directed edge from u to v.

        Args:
            u: Source vertex.
            v: Destination vertex.

        Raises:
            ValueError: If u or v is negative.
        """
        if u < 0 or v < 0:
            raise ValueError("vertices must be non-negative")
        self.adjacency_dict[u].append(v)
        self.num_vertices = max(self.num_vertices, u + 1, v + 1)


def topological_sort(G: Graph) -> List[int]:
    """
    Perform topological sort on a directed acyclic graph (DAG).

    Every vertex 0..G.num_vertices-1 appears in the result, including
    isolated ones.

    Args:
        G: The directed graph to sort.

    Returns:
        A list of vertices in which u precedes v for every edge (u, v).

    Raises:
        ValueError: If the graph contains a cycle.
    """
    unvisited, in_progress, done = 0, 1, 2
    state = [unvisited] * G.num_vertices
    post_order: List[int] = []

    for start in range(G.num_vertices):
        if state[start] != unvisited:
            continue

        # Iterative DFS holding (vertex, iterator over its neighbours).
        state[start] = in_progress
        stack = [(start, iter(G.adjacency_dict.get(start, ())))]
        while stack:
            v, neighbours = stack[-1]
            for u in neighbours:
                if state[u] == in_progress:
                    raise ValueError("graph contains a cycle")
                if state[u] == unvisited:
                    state[u] = in_progress
                    stack.append((u, iter(G.adjacency_dict.get(u, ()))))
                    break
            else:
                state[v] = done
                post_order.append(v)
                stack.pop()

    # Reverse post-order is a topological order.
    post_order.reverse()
    return post_order
