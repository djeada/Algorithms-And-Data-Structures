import math
import random
import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from dijkstra import dijkstra


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


class TestDijkstra(unittest.TestCase):
    def test_dijkstra_str_vertices_negative(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex("A"), Vertex("D"), 2))
        graph.add_edge(Edge(Vertex("A"), Vertex("G"), 3))
        graph.add_edge(Edge(Vertex("A"), Vertex("B"), 1))
        graph.add_edge(Edge(Vertex("B"), Vertex("E"), 6))
        graph.add_edge(Edge(Vertex("B"), Vertex("F"), 7))
        graph.add_edge(Edge(Vertex("F"), Vertex("D"), 10))
        graph.add_edge(Edge(Vertex("F"), Vertex("C"), 12))
        graph.add_edge(Edge(Vertex("E"), Vertex("G"), 9))

        self.assertEqual(dijkstra(graph, Vertex("A"), Vertex("C")), 20)
        self.assertEqual(dijkstra(graph, Vertex("A"), Vertex("F")), 8)
        self.assertEqual(dijkstra(graph, Vertex("B"), Vertex("G")), 15)
        self.assertEqual(dijkstra(graph, Vertex("E"), Vertex("A")), math.inf)
        self.assertEqual(dijkstra(graph, Vertex("C"), Vertex("D")), math.inf)

    def test_dijkstra_int_vertices_positive(self):
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

        self.assertEqual(dijkstra(graph, Vertex(0), Vertex(2)), 2)
        self.assertEqual(dijkstra(graph, Vertex(1), Vertex(2)), 1)
        self.assertEqual(dijkstra(graph, Vertex(2), Vertex(2)), 0)
        self.assertEqual(dijkstra(graph, Vertex(3), Vertex(2)), 1)
        self.assertEqual(dijkstra(graph, Vertex(2), Vertex(4)), 2)

    def test_dijkstra_int_vertices_negative(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex(1), Vertex(2), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(3), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(4), Vertex(2), 1))

        self.assertEqual(dijkstra(graph, Vertex(5), Vertex(0)), math.inf)
        self.assertEqual(dijkstra(graph, Vertex(1), Vertex(5)), math.inf)

    def test_dijkstra_source_equals_destination(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex("A"), Vertex("B"), 3))
        self.assertEqual(dijkstra(graph, Vertex("A"), Vertex("A")), 0)

    def test_dijkstra_unorderable_vertex_values_with_ties(self):
        class Opaque:
            pass

        a, b, c, d = Opaque(), Opaque(), Opaque(), Opaque()
        graph = Graph()
        graph.add_edge(Edge(Vertex(a), Vertex(b), 1))
        graph.add_edge(Edge(Vertex(a), Vertex(c), 1))
        graph.add_edge(Edge(Vertex(b), Vertex(d), 1))
        graph.add_edge(Edge(Vertex(c), Vertex(d), 1))
        self.assertEqual(dijkstra(graph, Vertex(a), Vertex(d)), 2)

    def test_dijkstra_unknown_vertex_and_parallel_edges(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(1), Vertex(2), 5))
        graph.add_edge(Edge(Vertex(1), Vertex(2), 2))
        self.assertEqual(dijkstra(graph, Vertex(1), Vertex(2)), 2)
        self.assertEqual(dijkstra(graph, Vertex(1), Vertex(99)), math.inf)

    def test_dijkstra_random_graphs_match_floyd_warshall(self):
        rng = random.Random(11)
        for _ in range(100):
            n = rng.randint(1, 7)
            edges = [
                (rng.randrange(n), rng.randrange(n), rng.randint(0, 9))
                for _ in range(rng.randint(0, 15))
            ]
            graph = Graph()
            for v in range(n):
                graph.add_vertex(Vertex(v))
            for u, v, w in edges:
                graph.add_edge(Edge(Vertex(u), Vertex(v), w))
            dist = floyd_warshall(range(n), edges)
            for u in range(n):
                for v in range(n):
                    self.assertEqual(
                        dijkstra(graph, Vertex(u), Vertex(v)), dist[(u, v)]
                    )


if __name__ == "__main__":
    unittest.main()
