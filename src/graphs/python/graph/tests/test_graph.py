import unittest
import sys

sys.path.insert(0, "../src")

from graph import Vertex, Edge, Graph


class TestVertex(unittest.TestCase):
    def test_equal(self):
        vertex_a = Vertex(1)
        vertex_b = Vertex(1)

        self.assertEqual(vertex_a, vertex_b)

        vertex_a = Vertex("A")
        vertex_b = Vertex("A")

        self.assertEqual(vertex_a, vertex_b)

    def test_not_equal(self):
        vertex_a = Vertex(1)
        vertex_b = Vertex(2)

        self.assertNotEqual(vertex_a, vertex_b)

        vertex_a = Vertex("A")
        vertex_b = Vertex("B")

        self.assertNotEqual(vertex_a, vertex_b)

    def test_sorting(self):
        array = [Vertex(5), Vertex(4), Vertex(1), Vertex(3), Vertex(2)]
        expected_result = [Vertex(1), Vertex(2), Vertex(3), Vertex(4), Vertex(5)]

        self.assertListEqual(sorted(array), expected_result)


class TestEdge(unittest.TestCase):
    def test_equal(self):
        edge_a = Edge(Vertex(1), Vertex(2), 10)
        edge_b = Edge(Vertex(1), Vertex(2), 10)

        self.assertEqual(edge_a, edge_b)

        edge_a = Edge(Vertex("A"), Vertex("B"), 5)
        edge_b = Edge(Vertex("A"), Vertex("B"), 5)

        self.assertEqual(edge_a, edge_b)

    def test_not_equal(self):
        edge_a = Edge(Vertex(1), Vertex(2), 10)
        edge_b = Edge(Vertex(2), Vertex(1), 10)

        self.assertNotEqual(edge_a, edge_b)

        edge_a = Edge(Vertex(1), Vertex(2), 3)
        edge_b = Edge(Vertex(2), Vertex(2), 5)

        self.assertNotEqual(edge_a, edge_b)

        edge_a = Edge(Vertex(1), Vertex(2), 10)
        edge_b = Edge(Vertex(3), Vertex(2), 10)

        self.assertNotEqual(edge_a, edge_b)

        edge_a = Edge(Vertex("A"), Vertex("B"), 5)
        edge_b = Edge(Vertex("C"), Vertex("A"), 5)

        self.assertNotEqual(edge_a, edge_b)

    def test_sorting(self):
        array = [
            Edge(Vertex(1), Vertex(9), 8),
            Edge(Vertex(7), Vertex(2), 4),
            Edge(Vertex(3), Vertex(1), -5),
            Edge(Vertex(5), Vertex(4), 5),
        ]
        expected_result = [
            Edge(Vertex(3), Vertex(1), -5),
            Edge(Vertex(7), Vertex(2), 4),
            Edge(Vertex(5), Vertex(4), 5),
            Edge(Vertex(1), Vertex(9), 8),
        ]

        self.assertListEqual(sorted(array), expected_result)


class TestGraph(unittest.TestCase):
    def test_negative_1(self):
        pass


if __name__ == "__main__":
    unittest.main()
