"""Graph data structures for graph algorithms."""

from __future__ import annotations

import math
from typing import Any, TypeVar

T = TypeVar("T")


class Vertex:
    """A vertex in a graph with an associated value."""

    def __init__(self, value: T) -> None:
        self.value = value

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Vertex):
            return self.value == other.value
        return False

    def __lt__(self, other: object) -> bool:
        if not isinstance(other, Vertex):
            raise NotImplementedError
        return self.value < other.value

    def __repr__(self) -> str:
        return str(self.value)

    def __hash__(self) -> int:
        return hash(self.value)


class Edge:
    """A weighted directed edge connecting two vertices."""

    def __init__(self, source: Vertex, destination: Vertex, distance: float) -> None:
        self.source = source
        self.destination = destination
        self.distance = distance

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Edge):
            return (
                self.source == other.source
                and self.destination == other.destination
                and self.distance == other.distance
            )
        return False

    def __lt__(self, other: object) -> bool:
        if not isinstance(other, Edge):
            raise NotImplementedError
        return self.distance < other.distance

    def __repr__(self) -> str:
        return f"({self.source}, {self.destination}, {self.distance})"


class Graph:
    """A directed weighted graph using adjacency list representation."""

    def __init__(self) -> None:
        self._adj_dict: dict[Vertex, list[Edge]] = {}

    def add_edge(self, edge: Edge) -> None:
        """Add an edge to the graph."""
        if edge.source in self._adj_dict:
            self._adj_dict[edge.source].append(edge)
        else:
            self._adj_dict[edge.source] = [edge]

        if edge.destination not in self._adj_dict:
            self._adj_dict[edge.destination] = []

    def add_vertex(self, vertex: Vertex) -> None:
        """Add a vertex to the graph."""
        if vertex not in self._adj_dict:
            self._adj_dict[vertex] = []

    def vertices(self) -> list[Vertex]:
        """Return a list of all vertices in the graph."""
        return list(self._adj_dict.keys())

    def edges(self) -> list[Edge]:
        """Return a list of all edges in the graph."""
        return [elem for array in self._adj_dict.values() for elem in array if array]

    def edges_from_vertex(self, vertex: Vertex) -> list[Edge]:
        """Return all edges originating from the given vertex."""
        self._assert_graph_contains_vertex(vertex)
        return self._adj_dict[vertex]

    def contains(self, vertex: Vertex) -> bool:
        """Check if the graph contains the given vertex."""
        return vertex in self._adj_dict

    def connected(self, vertex_a: Vertex, vertex_b: Vertex) -> bool:
        """Check if two vertices are directly connected by an edge."""
        self._assert_graph_contains_vertex(vertex_a)
        self._assert_graph_contains_vertex(vertex_b)

        for edge in self._adj_dict[vertex_a]:
            if edge.destination == vertex_b:
                return True

        for edge in self._adj_dict[vertex_b]:
            if edge.destination == vertex_a:
                return True

        return False

    def empty(self) -> bool:
        """Check if the graph has no vertices."""
        return len(self._adj_dict) == 0

    def size(self) -> int:
        """Return the number of vertices in the graph."""
        return len(self._adj_dict)

    def __repr__(self) -> str:
        result = ""
        for vertex, edges in self._adj_dict.items():
            result += f"{vertex} —> "
            for edge in edges:
                result += str(edge)
            result += "\n"
        return result

    def _assert_graph_contains_vertex(self, vertex: Vertex) -> None:
        if vertex not in self._adj_dict:
            raise KeyError(f"Graph doesn't contain the {vertex} vertex!")
