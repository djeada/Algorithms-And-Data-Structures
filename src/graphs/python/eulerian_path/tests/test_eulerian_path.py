"""Tests for the Eulerian Path algorithm."""

import random
import unittest
from collections import Counter

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from eulerian_path import fleury, is_connected, edges_from_adjacency


def is_valid_trail(graph, trail):
    """Check that trail is a walk using every undirected edge exactly once."""
    remaining = Counter((u, v) for u in graph for v in graph[u])
    if 2 * len(trail) != sum(remaining.values()):
        return False
    for i, (a, b) in enumerate(trail):
        if i > 0 and trail[i - 1][1] != a:
            return False
        if remaining[(a, b)] <= 0 or remaining[(b, a)] <= 0:
            return False
        remaining[(a, b)] -= 1
        remaining[(b, a)] -= 1
    return True


def edges_connected(graph):
    start = next((v for v in graph if graph[v]), None)
    if start is None:
        return True
    seen, stack = {start}, [start]
    while stack:
        for v in graph[stack.pop()]:
            if v not in seen:
                seen.add(v)
                stack.append(v)
    return all(v in seen for v in graph if graph[v])


class TestEulerianPath(unittest.TestCase):
    def test_no_eulerian_path_odd_degree_vertices(self):
        """Graph with 4 odd-degree vertices has no Eulerian path."""
        graph = {0: [2, 2, 3], 1: [2, 2, 3], 2: [0, 0, 1, 1, 3], 3: [0, 1, 2]}
        self.assertFalse(fleury(graph))

    def test_eulerian_path_complex_graph(self):
        """Test Eulerian path on a more complex graph."""
        graph = {
            0: [1, 4, 6, 8],
            1: [0, 2, 3, 8],
            2: [1, 3],
            3: [1, 2, 4, 5],
            4: [0, 3],
            5: [3, 6],
            6: [0, 5, 7, 8],
            7: [6, 8],
            8: [0, 1, 6, 7],
        }
        expected = [
            (0, 1),
            (1, 2),
            (2, 3),
            (3, 1),
            (1, 8),
            (8, 0),
            (0, 4),
            (4, 3),
            (3, 5),
            (5, 6),
            (6, 8),
            (8, 7),
            (7, 6),
            (6, 0),
        ]
        result = fleury(graph)
        self.assertEqual(len(expected), len(result))
        self.assertTrue(is_valid_trail(graph, result))

    def test_eulerian_path_multigraph(self):
        """Test Eulerian path on a multigraph with parallel edges."""
        graph = {1: [2, 3, 4, 4], 2: [1, 3, 3, 4], 3: [1, 2, 2, 4], 4: [1, 1, 2, 3]}
        expected = [(1, 2), (2, 3), (3, 1), (1, 4), (4, 3), (3, 2), (2, 4), (4, 1)]
        result = fleury(graph)
        self.assertEqual(len(expected), len(result))
        self.assertTrue(is_valid_trail(graph, result))

    def test_eulerian_path_simple_graph(self):
        """Test Eulerian path on a simple graph with two odd-degree vertices."""
        graph = {1: [2, 3], 2: [1, 3, 4], 3: [1, 2, 4], 4: [2, 3]}
        expected = [(2, 1), (1, 3), (3, 2), (2, 4), (4, 3)]
        self.assertEqual(fleury(graph), expected)

    def test_isolated_vertices_are_ignored(self):
        """Vertices without edges must not break the search."""
        graph = {0: [], 1: [2, 3, 2, 3], 2: [1, 1], 3: [1, 1], 4: []}
        result = fleury(graph)
        self.assertTrue(is_valid_trail(graph, result))

    def test_disconnected_edges_have_no_path(self):
        """Edges in two components cannot form one trail."""
        graph = {0: [1, 1], 1: [0, 0], 2: [3, 3], 3: [2, 2]}
        self.assertFalse(fleury(graph))

    def test_no_edges(self):
        self.assertEqual(fleury({0: [], 1: []}), [])

    def test_fleury_random_graphs_against_criterion(self):
        """Eulerian path exists iff edges are connected and 0 or 2 odd vertices."""
        rng = random.Random(7)
        for _ in range(500):
            n = rng.randint(1, 6)
            graph = {i: [] for i in range(n)}
            for _ in range(rng.randint(0, 9)):
                a, b = rng.randrange(n), rng.randrange(n)
                if a != b:
                    graph[a].append(b)
                    graph[b].append(a)
            odd = sum(len(graph[u]) % 2 for u in graph)
            exists = edges_connected(graph) and odd in (0, 2)
            result = fleury(graph)
            if exists:
                self.assertIsNot(result, False, graph)
                self.assertTrue(is_valid_trail(graph, result), graph)
            else:
                self.assertIs(result, False, graph)

    def test_is_connected_single_vertex(self):
        """Single vertex graph is connected."""
        graph = {0: []}
        self.assertTrue(is_connected(graph))

    def test_is_connected_empty_graph(self):
        """Empty graph is considered connected."""
        graph = {}
        self.assertTrue(is_connected(graph))

    def test_edges_from_adjacency(self):
        """Test edge list conversion."""
        graph = {0: [1, 2], 1: [0], 2: [0]}
        edges = edges_from_adjacency(graph)
        self.assertEqual(len(edges), 4)
        self.assertIn((0, 1), edges)
        self.assertIn((0, 2), edges)


if __name__ == "__main__":
    unittest.main()
