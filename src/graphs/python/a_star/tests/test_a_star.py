import random
import unittest
import math

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from a_star import a_star


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


class TestAStar(unittest.TestCase):
    def test_a_star_points(self):
        class Point:
            def __init__(self, x, y):
                self.x = x
                self.y = y

            @staticmethod
            def distance(point_a, point_b):
                return math.sqrt(
                    (point_a.x - point_b.x) ** 2 + (point_a.y - point_b.y) ** 2
                )

        graph = Graph()

        a = Point(1, 1)
        b = Point(4, 3)
        c = Point(7, 2)
        d = Point(3, 8)
        e = Point(4, 1)

        graph.add_edge(Edge(Vertex(a), Vertex(e), 4))
        graph.add_edge(Edge(Vertex(a), Vertex(b), 8))
        graph.add_edge(Edge(Vertex(a), Vertex(d), 11))
        graph.add_edge(Edge(Vertex(e), Vertex(c), 18))
        graph.add_edge(Edge(Vertex(e), Vertex(b), 2))
        graph.add_edge(Edge(Vertex(b), Vertex(c), 12))

        self.assertEqual(a_star(graph, Vertex(a), Vertex(c), Point.distance), 18)
        self.assertEqual(a_star(graph, Vertex(a), Vertex(b), Point.distance), 6)
        self.assertEqual(a_star(graph, Vertex(d), Vertex(b), Point.distance), math.inf)
        self.assertEqual(a_star(graph, Vertex(b), Vertex(e), Point.distance), math.inf)

    def test_a_star_source_equals_destination_and_unknown_vertex(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 2))
        self.assertEqual(a_star(graph, Vertex(0), Vertex(0), lambda a, b: 0), 0)
        self.assertEqual(a_star(graph, Vertex(0), Vertex(9), lambda a, b: 0), math.inf)

    def test_a_star_unorderable_values_with_equal_priorities(self):
        class Opaque:
            pass

        a, b, c, d = Opaque(), Opaque(), Opaque(), Opaque()
        graph = Graph()
        graph.add_edge(Edge(Vertex(a), Vertex(b), 1))
        graph.add_edge(Edge(Vertex(a), Vertex(c), 1))
        graph.add_edge(Edge(Vertex(b), Vertex(d), 1))
        graph.add_edge(Edge(Vertex(c), Vertex(d), 1))
        self.assertEqual(a_star(graph, Vertex(a), Vertex(d), lambda x, y: 0), 2)

    def test_a_star_improved_path_to_queued_vertex(self):
        # Vertex 3 is queued with a stale priority before a cheaper path to it
        # is discovered; the answer must still be optimal.
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 1))
        graph.add_edge(Edge(Vertex(0), Vertex(2), 10))
        graph.add_edge(Edge(Vertex(1), Vertex(2), 1))
        graph.add_edge(Edge(Vertex(2), Vertex(3), 1))
        graph.add_edge(Edge(Vertex(0), Vertex(3), 20))
        self.assertEqual(a_star(graph, Vertex(0), Vertex(3), lambda a, b: 0), 3)

    def test_a_star_random_graphs_with_inconsistent_heuristic(self):
        rng = random.Random(21)
        for _ in range(200):
            n = rng.randint(1, 7)
            edges = [
                (rng.randrange(n), rng.randrange(n), rng.randint(0, 9))
                for _ in range(rng.randint(0, 16))
            ]
            graph = Graph()
            for v in range(n):
                graph.add_vertex(Vertex(v))
            for u, v, w in edges:
                graph.add_edge(Edge(Vertex(u), Vertex(v), w))
            dist = floyd_warshall(range(n), edges)
            for t in range(n):
                # Admissible but inconsistent: a random fraction of the true distance.
                h = {
                    v: (0 if dist[(v, t)] == math.inf else dist[(v, t)] * rng.random())
                    for v in range(n)
                }
                for s in range(n):
                    self.assertAlmostEqual(
                        a_star(graph, Vertex(s), Vertex(t), lambda x, y: h[x]),
                        dist[(s, t)],
                    )


if __name__ == "__main__":
    unittest.main()
