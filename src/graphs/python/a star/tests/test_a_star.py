import unittest
import math

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from graph import Vertex, Edge, Graph
from a_star import a_star


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
        self.assertEqual(
            a_star(graph, Vertex(d), Vertex(b), Point.distance), float("inf")
        )
        self.assertEqual(
            a_star(graph, Vertex(b), Vertex(e), Point.distance), float("inf")
        )


if __name__ == "__main__":
    unittest.main()
