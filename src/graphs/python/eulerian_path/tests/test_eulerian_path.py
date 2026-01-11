"""Tests for the Eulerian Path algorithm."""

import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from eulerian_path import fleury, is_connected, edges_from_adjacency


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
        self.assertEqual(fleury(graph), expected)

    def test_eulerian_path_multigraph(self):
        """Test Eulerian path on a multigraph with parallel edges."""
        graph = {1: [2, 3, 4, 4], 2: [1, 3, 3, 4], 3: [1, 2, 2, 4], 4: [1, 1, 2, 3]}
        expected = [(1, 2), (2, 3), (3, 1), (1, 4), (4, 3), (3, 2), (2, 4), (4, 1)]
        self.assertEqual(fleury(graph), expected)

    def test_eulerian_path_simple_graph(self):
        """Test Eulerian path on a simple graph with two odd-degree vertices."""
        graph = {1: [2, 3], 2: [1, 3, 4], 3: [1, 2, 4], 4: [2, 3]}
        expected = [(2, 1), (1, 3), (3, 2), (2, 4), (4, 3)]
        self.assertEqual(fleury(graph), expected)

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
