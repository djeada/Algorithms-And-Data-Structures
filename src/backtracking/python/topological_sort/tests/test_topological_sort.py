import unittest
from typing import List, Tuple

from src.topological_sort import Graph, topological_sort


def build(edges: List[Tuple[int, int]], num_vertices: int = 0) -> Graph:
    g = Graph(num_vertices)
    for u, v in edges:
        g.add_edge(u, v)
    return g


class TestTopologicalSort(unittest.TestCase):
    def assert_valid_order(self, order, num_vertices, edges):
        self.assertCountEqual(order, range(num_vertices))
        position = {v: i for i, v in enumerate(order)}
        for u, v in edges:
            self.assertLess(position[u], position[v])

    def test_positive_1(self):
        edges = [(0, 6), (1, 2), (1, 4), (1, 6), (3, 0), (3, 4), (5, 1), (7, 0), (7, 1)]
        actual = topological_sort(build(edges))

        self.assertListEqual([7, 5, 3, 1, 4, 2, 0, 6], actual)

    def test_positive_2_includes_isolated_vertex(self):
        edges = [(3, 0), (3, 4), (0, 6), (4, 1), (1, 2), (1, 6)]
        actual = topological_sort(build(edges))

        # vertex 5 has no edges but must still be returned
        self.assert_valid_order(actual, 7, edges)

    def test_empty_graph(self):
        self.assertListEqual([], topological_sort(Graph()))

    def test_vertices_without_edges(self):
        self.assert_valid_order(topological_sort(Graph(3)), 3, [])

    def test_cycle_raises(self):
        with self.assertRaises(ValueError):
            topological_sort(build([(0, 1), (1, 2), (2, 0)]))

    def test_self_loop_raises(self):
        with self.assertRaises(ValueError):
            topological_sort(build([(1, 1)]))

    def test_negative_vertex_raises(self):
        with self.assertRaises(ValueError):
            Graph().add_edge(-1, 0)

    def test_deep_chain_does_not_hit_recursion_limit(self):
        n = 5000
        edges = [(i, i + 1) for i in range(n - 1)]
        self.assertListEqual(list(range(n)), topological_sort(build(edges)))


if __name__ == "__main__":
    unittest.main()
