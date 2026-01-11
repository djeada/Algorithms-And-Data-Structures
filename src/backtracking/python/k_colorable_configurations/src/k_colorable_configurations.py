from typing import List, Dict


class Graph:
    """A simple undirected graph represented using an adjacency dictionary."""

    def __init__(self) -> None:
        """Initialize an empty graph."""
        self.num_vertices: int = 0
        self.adjacency_dict: Dict[int, List[int]] = {}

    def add_edge(self, u: int, v: int) -> None:
        """
        Add an undirected edge between vertices u and v.

        Args:
            u: First vertex.
            v: Second vertex.
        """
        if u not in self.adjacency_dict:
            self.adjacency_dict[u] = []

        if v not in self.adjacency_dict:
            self.adjacency_dict[v] = []

        self.adjacency_dict[u].append(v)
        self.adjacency_dict[v].append(u)
        if len(self.adjacency_dict) > self.num_vertices:
            self.num_vertices = len(self.adjacency_dict)


def find_k_colorable_configurations(G: Graph, k: int) -> List[List[int]]:
    """
    Find all valid k-colorable configurations of the graph.

    A k-colorable configuration assigns one of k colors to each vertex
    such that no two adjacent vertices share the same color.

    Args:
        G: The graph to color.
        k: The number of available colors.

    Returns:
        List of all valid configurations, where each configuration is a list
        of color assignments for each vertex.
    """

    def dfs(
        G: Graph, v: int, colors: List[int], configuration: List[int]
    ) -> None:
        if v == G.num_vertices:
            configurations.append(configuration.copy())
            return

        for color in range(k):
            if is_colorable(G, v, color, colors):
                colors[v] = color
                configuration.append(color)
                dfs(G, v + 1, colors, configuration)
                configuration.pop()
                colors[v] = -1

    def is_colorable(G: Graph, v: int, color: int, colors: List[int]) -> bool:
        """Check if assigning color to vertex v is valid."""
        for u in G.adjacency_dict[v]:
            if colors[u] == color:
                return False
        return True

    configurations: List[List[int]] = []
    dfs(G, 0, [-1] * G.num_vertices, [])
    return configurations
