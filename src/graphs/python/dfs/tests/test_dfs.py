import math
import random
import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from dfs import dfs


class TestDFS(unittest.TestCase):
    def test_dfs_str_vertices_negative(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex("A"), Vertex("D"), 2))
        graph.add_edge(Edge(Vertex("A"), Vertex("G"), 3))
        graph.add_edge(Edge(Vertex("A"), Vertex("B"), 1))
        graph.add_edge(Edge(Vertex("B"), Vertex("E"), 6))
        graph.add_edge(Edge(Vertex("B"), Vertex("F"), 7))
        graph.add_edge(Edge(Vertex("F"), Vertex("D"), 10))
        graph.add_edge(Edge(Vertex("F"), Vertex("C"), 12))
        graph.add_edge(Edge(Vertex("E"), Vertex("G"), 9))

        self.assertEqual(dfs(graph, Vertex("A"), Vertex("C")), 20)
        self.assertEqual(dfs(graph, Vertex("A"), Vertex("F")), 8)
        self.assertEqual(dfs(graph, Vertex("B"), Vertex("G")), 15)
        self.assertEqual(dfs(graph, Vertex("E"), Vertex("A")), math.inf)
        self.assertEqual(dfs(graph, Vertex("C"), Vertex("D")), math.inf)

    def test_dfs_int_vertices_positive(self):
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

        self.assertEqual(dfs(graph, Vertex(2), Vertex(0)), 3)
        self.assertEqual(dfs(graph, Vertex(2), Vertex(1)), 2)
        self.assertEqual(dfs(graph, Vertex(2), Vertex(2)), 0)
        self.assertEqual(dfs(graph, Vertex(2), Vertex(3)), 1)
        self.assertEqual(dfs(graph, Vertex(2), Vertex(4)), 4)

    def test_dfs_int_vertices_negative(self):
        graph = Graph()

        graph.add_edge(Edge(Vertex(1), Vertex(2), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(3), Vertex(4), 1))
        graph.add_edge(Edge(Vertex(4), Vertex(2), 1))

        self.assertEqual(dfs(graph, Vertex(5), Vertex(0)), math.inf)
        self.assertEqual(dfs(graph, Vertex(1), Vertex(5)), math.inf)

    def test_dfs_deep_path_does_not_overflow_stack(self):
        graph = Graph()
        n = 5000
        for i in range(n):
            graph.add_edge(Edge(Vertex(i), Vertex(i + 1), 1))
        self.assertEqual(dfs(graph, Vertex(0), Vertex(n)), n)

    def test_dfs_cycle_and_source_equals_destination(self):
        graph = Graph()
        graph.add_edge(Edge(Vertex(0), Vertex(1), 1))
        graph.add_edge(Edge(Vertex(1), Vertex(0), 1))
        self.assertEqual(dfs(graph, Vertex(0), Vertex(0)), 0)
        self.assertEqual(dfs(graph, Vertex(0), Vertex(1)), 1)

    def test_dfs_reachability_matches_brute_force(self):
        rng = random.Random(3)
        for _ in range(100):
            n = rng.randint(1, 7)
            edges = [
                (rng.randrange(n), rng.randrange(n), rng.randint(1, 5))
                for _ in range(rng.randint(0, 12))
            ]
            graph = Graph()
            for v in range(n):
                graph.add_vertex(Vertex(v))
            for u, v, w in edges:
                graph.add_edge(Edge(Vertex(u), Vertex(v), w))
            reach = {(v, v) for v in range(n)} | {(u, v) for u, v, _ in edges}
            for k in range(n):
                for i in range(n):
                    for j in range(n):
                        if (i, k) in reach and (k, j) in reach:
                            reach.add((i, j))
            for s in range(n):
                for t in range(n):
                    result = dfs(graph, Vertex(s), Vertex(t))
                    self.assertEqual((s, t) in reach, result != math.inf)


if __name__ == "__main__":
    unittest.main()
