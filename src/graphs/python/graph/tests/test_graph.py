import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

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
    def test_add_edge(self):
        graph = Graph()

        self.assertDictEqual(graph._adj_dict, dict())

        edge_a = Edge(Vertex(1), Vertex(9), 8)
        edge_b = Edge(Vertex(5), Vertex(4), 5)
        edge_c = Edge(Vertex(3), Vertex(1), -5)

        graph.add_edge(edge_a)
        graph.add_edge(edge_b)
        graph.add_edge(edge_c)

        expected_result = {
            edge_a.source: [edge_a],
            edge_b.source: [edge_b],
            edge_c.source: [edge_c],
            edge_a.destination: list(),
            edge_b.destination: list(),
        }

        self.assertDictEqual(graph._adj_dict, expected_result)

    def test_add_vertex(self):
        graph = Graph()

        self.assertDictEqual(graph._adj_dict, dict())

        vertex_a = Vertex("A")
        vertex_b = Vertex("B")
        vertex_c = Vertex("C")

        graph.add_vertex(vertex_a)
        graph.add_vertex(vertex_b)
        graph.add_vertex(vertex_c)

        expected_result = {vertex_a: list(), vertex_b: list(), vertex_c: list()}

        self.assertDictEqual(graph._adj_dict, expected_result)

    def test_vertices(self):
        graph = Graph()

        vertex_a = Vertex("A")
        vertex_b = Vertex("B")
        vertex_c = Vertex("C")

        graph.add_vertex(vertex_a)
        graph.add_vertex(vertex_b)
        graph.add_vertex(vertex_c)

        expected_result = [vertex_a, vertex_b, vertex_c]

        self.assertSetEqual(set(graph.vertices()), set(expected_result))

    def test_edges(self):
        graph = Graph()

        self.assertDictEqual(graph._adj_dict, dict())

        edge_a = Edge(Vertex(1), Vertex(9), 8)
        edge_b = Edge(Vertex(5), Vertex(4), 5)
        edge_c = Edge(Vertex(3), Vertex(1), -5)

        graph.add_edge(edge_a)
        graph.add_edge(edge_b)
        graph.add_edge(edge_c)

        expected_result = [edge_a, edge_b, edge_c]

        self.assertListEqual(graph.edges(), expected_result)

    def test_edges_from_vertex(self):
        graph = Graph()

        vertex = Vertex(1)
        edge_a = Edge(vertex, Vertex(9), 8)
        edge_b = Edge(vertex, Vertex(4), 5)
        edge_c = Edge(vertex, Vertex(3), -5)

        graph.add_edge(edge_a)
        graph.add_edge(edge_b)
        graph.add_edge(edge_c)

        expected_result = [edge_a, edge_b, edge_c]

        self.assertListEqual(graph.edges_from_vertex(vertex), expected_result)

    def test_contains(self):
        graph = Graph()

        vertex = Vertex("A")

        self.assertFalse(graph.contains(vertex))
        graph.add_vertex(vertex)

        self.assertTrue(graph.contains(vertex))

    def test_connected(self):
        graph = Graph()

        edge_a = Edge(Vertex(1), Vertex(9), 8)
        edge_b = Edge(Vertex(5), Vertex(4), 5)
        edge_c = Edge(Vertex(3), Vertex(1), -5)

        graph.add_edge(edge_a)
        graph.add_edge(edge_b)
        graph.add_edge(edge_c)

        self.assertTrue(graph.connected(Vertex(1), Vertex(9)))
        self.assertTrue(graph.connected(Vertex(9), Vertex(1)))
        self.assertTrue(graph.connected(Vertex(4), Vertex(5)))
        self.assertTrue(graph.connected(Vertex(5), Vertex(4)))
        self.assertTrue(graph.connected(Vertex(1), Vertex(3)))
        self.assertTrue(graph.connected(Vertex(3), Vertex(1)))

        self.assertFalse(graph.connected(Vertex(1), Vertex(5)))
        self.assertFalse(graph.connected(Vertex(5), Vertex(1)))
        self.assertFalse(graph.connected(Vertex(1), Vertex(4)))
        self.assertFalse(graph.connected(Vertex(4), Vertex(1)))
        self.assertFalse(graph.connected(Vertex(9), Vertex(5)))
        self.assertFalse(graph.connected(Vertex(5), Vertex(9)))
        self.assertFalse(graph.connected(Vertex(9), Vertex(4)))
        self.assertFalse(graph.connected(Vertex(4), Vertex(9)))

    def test_empty(self):
        graph = Graph()
        self.assertTrue(graph.empty())

    def test_size(self):
        graph = Graph()

        self.assertTrue(graph.size() == 0)

        edge_a = Edge(Vertex(1), Vertex(9), 8)
        edge_b = Edge(Vertex(5), Vertex(4), 5)
        edge_c = Edge(Vertex(3), Vertex(1), -5)

        graph.add_edge(edge_a)
        graph.add_edge(edge_b)
        graph.add_edge(edge_c)

        self.assertTrue(graph.size() == 5)


if __name__ == "__main__":
    unittest.main()
