import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from prim import prim


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


if __name__ == "__main__":
    unittest.main()
