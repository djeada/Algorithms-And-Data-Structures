import math
import random
import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from bellman_ford import bellman_ford


def floyd_warshall(vertices, edges):
    """Brute-force all-pairs shortest paths over plain (u, v, w) tuples."""
    dist = {(u, v): (0 if u == v else math.inf) for u in vertices for v in vertices}
    for u, v, w in edges:
        dist[(u, v)] = min(dist[(u, v)], w)
    for k in vertices:
        for i in vertices:
            for j in vertices:
                if dist[(i, k)] + dist[(k, j)] < dist[(i, j)]:
                    dist[(i, j)] = dist[(i, k)] + dist[(k, j)]
    return dist


class TestBellmanFord(unittest.TestCase):
    def test_bellman_ford_str_vertices_negative(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex("A"), Vertex("D"), 2))
        graph.add_edge(Edge(Vertex("A"), Vertex("G"), 3))
        graph.add_edge(Edge(Vertex("A"), Vertex("B"), 1))
        graph.add_edge(Edge(Vertex("B"), Vertex("E"), 6))
        graph.add_edge(Edge(Vertex("B"), Vertex("F"), 7))
        graph.add_edge(Edge(Vertex("F"), Vertex("D"), 10))
        graph.add_edge(Edge(Vertex("F"), Vertex("C"), 12))
        graph.add_edge(Edge(Vertex("E"), Vertex("G"), 9))

        self.assertEqual(bellman_ford(graph, Vertex("A"), Vertex("C")), 20)
        self.assertEqual(bellman_ford(graph, Vertex("A"), Vertex("F")), 8)
        self.assertEqual(bellman_ford(graph, Vertex("B"), Vertex("G")), 15)
        self.assertEqual(bellman_ford(graph, Vertex("E"), Vertex("A")), math.inf)
        self.assertEqual(bellman_ford(graph, Vertex("C"), Vertex("D")), math.inf)

    def test_bellman_ford_int_vertices_positive(self):
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

        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(2)), 2)
        self.assertEqual(bellman_ford(graph, Vertex(1), Vertex(2)), 1)
        self.assertEqual(bellman_ford(graph, Vertex(2), Vertex(2)), 0)
        self.assertEqual(bellman_ford(graph, Vertex(3), Vertex(2)), 1)
        self.assertEqual(bellman_ford(graph, Vertex(2), Vertex(4)), 2)

    def test_bellman_ford_int_vertices_negative(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex(1), Vertex(2), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(3), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(4), Vertex(2), 1))

        self.assertEqual(bellman_ford(graph, Vertex(5), Vertex(0)), math.inf)
        self.assertEqual(bellman_ford(graph, Vertex(1), Vertex(5)), math.inf)

    def test_negative_edges_without_cycle(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 4))
        graph.add_edge(Edge(Vertex(0), Vertex(2), 5))
        graph.add_edge(Edge(Vertex(2), Vertex(1), -3))
        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(1)), 2)

    def test_negative_cycle_reachable_returns_inf(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(2), -2))
        graph.add_edge(Edge(Vertex(2), Vertex(1), 1))
        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(2)), math.inf)

    def test_negative_cycle_through_source_is_detected(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), -2))
        graph.add_edge(Edge(Vertex(1), Vertex(0), 1))
        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(0)), math.inf)

    def test_unreachable_negative_cycle_is_ignored(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 3))
        graph.add_edge(Edge(Vertex(5), Vertex(6), -4))
        graph.add_edge(Edge(Vertex(6), Vertex(5), 1))
        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(1)), 3)
        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(0)), 0)
        self.assertEqual(bellman_ford(graph, Vertex(0), Vertex(6)), math.inf)

    def test_random_graphs_match_floyd_warshall(self):
        rng = random.Random(5)
        for _ in range(150):
            n = rng.randint(1, 6)
            edges = [
                (rng.randrange(n), rng.randrange(n), rng.randint(-3, 9))
                for _ in range(rng.randint(0, 12))
            ]
            graph = Graph()
            for v in range(n):
                graph.add_vertex(Vertex(v))
            for u, v, w in edges:
                graph.add_edge(Edge(Vertex(u), Vertex(v), w))
            dist = floyd_warshall(range(n), edges)
            for s in range(n):
                reachable = [v for v in range(n) if dist[(s, v)] < math.inf]
                has_neg_cycle = any(dist[(v, v)] < 0 for v in reachable)
                for t in range(n):
                    expected = math.inf if has_neg_cycle else dist[(s, t)]
                    self.assertEqual(
                        bellman_ford(graph, Vertex(s), Vertex(t)), expected
                    )


if __name__ == "__main__":
    unittest.main()
