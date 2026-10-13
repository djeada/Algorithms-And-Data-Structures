import random
import itertools
import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from prim import prim


def brute_force_msf(n, edges):
    """Minimum spanning forest weight by trying every edge subset."""

    def components(subset):
        parent = list(range(n))

        def find(x):
            while parent[x] != x:
                x = parent[x]
            return x

        for u, v, _ in subset:
            parent[find(u)] = find(v)
        return len({find(x) for x in range(n)})

    target = components(edges)
    best = float("inf")
    for size in range(len(edges) + 1):
        for subset in itertools.combinations(edges, size):
            if components(subset) == target:
                best = min(best, sum(w for _, _, w in subset))
    return best


class TestPrim(unittest.TestCase):
    def test_prim_str_vertices(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex("A"), Vertex("D"), 2))
        graph.add_edge(Edge(Vertex("A"), Vertex("G"), 3))
        graph.add_edge(Edge(Vertex("A"), Vertex("B"), 1))
        graph.add_edge(Edge(Vertex("B"), Vertex("E"), 6))
        graph.add_edge(Edge(Vertex("B"), Vertex("F"), 7))
        graph.add_edge(Edge(Vertex("F"), Vertex("D"), 10))
        graph.add_edge(Edge(Vertex("F"), Vertex("C"), 12))
        graph.add_edge(Edge(Vertex("E"), Vertex("G"), 9))

        self.assertEqual(prim(graph), 31)

    def test_prim_int_vertices(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex(0), Vertex(1), 1))
        graph.add_edge(Edge(Vertex(0), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(0), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(3), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(2), 1))
        graph.add_edge(Edge(Vertex(2), Vertex(3), 1))
        graph.add_edge(Edge(Vertex(2), Vertex(1), 1))
        graph.add_edge(Edge(Vertex(3), Vertex(1), 1))
        graph.add_edge(Edge(Vertex(3), Vertex(2), 1))
        graph.add_edge(Edge(Vertex(3), Vertex(4), 1))

        self.assertEqual(prim(graph), 4)

    def test_prim_disconnected_graph_returns_forest_weight(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 2))
        graph.add_edge(Edge(Vertex(2), Vertex(3), 5))
        graph.add_vertex(Vertex(9))
        self.assertEqual(prim(graph), 7)

    def test_prim_empty_graph_and_self_loops(self):
        self.assertEqual(prim(Graph()), 0)
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(0), 4))
        graph.add_edge(Edge(Vertex(0), Vertex(1), 1))
        self.assertEqual(prim(graph), 1)

    def test_prim_direction_does_not_matter_and_negative_weights(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(1), Vertex(0), 3))
        graph.add_edge(Edge(Vertex(1), Vertex(2), -1))
        graph.add_edge(Edge(Vertex(2), Vertex(0), 4))
        self.assertEqual(prim(graph), 2)

    def test_prim_random_graphs_match_brute_force(self):
        rng = random.Random(9)
        for _ in range(100):
            n = rng.randint(1, 6)
            edges = [
                (rng.randrange(n), rng.randrange(n), rng.randint(0, 9))
                for _ in range(rng.randint(0, 9))
            ]
            graph = Graph()
            for v in range(n):
                graph.add_vertex(Vertex(v))
            for u, v, w in edges:
                graph.add_edge(Edge(Vertex(u), Vertex(v), w))
            self.assertEqual(prim(graph), brute_force_msf(n, edges))

    def test_prim_edges_only_pointing_into_first_vertex(self):
        # Only incoming edges at the first vertex: edges are undirected for MST.
        graph = Graph()
        graph.add_edge(Edge(Vertex("A"), Vertex("B"), 1))
        graph.add_edge(Edge(Vertex("C"), Vertex("B"), 2))
        self.assertEqual(prim(graph), 3)


if __name__ == "__main__":
    unittest.main()
