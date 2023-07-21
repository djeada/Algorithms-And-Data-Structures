import unittest
from src.topological_sort import Graph, topological_sort


class TestTopologicalSort(unittest.TestCase):
    def test_positive_1(self):
        g = Graph()
        g.add_edge(0, 6)
        g.add_edge(1, 2)
        g.add_edge(1, 4)
        g.add_edge(1, 6)
        g.add_edge(3, 0)
        g.add_edge(3, 4)
        g.add_edge(5, 1)
        g.add_edge(7, 0)
        g.add_edge(7, 1)

        expected = [7, 5, 3, 1, 4, 2, 0, 6]
        actual = topological_sort(g)

        self.assertListEqual(expected, actual)

    def test_positive_2(self):
        g = Graph()
        g.add_edge(3, 0)
        g.add_edge(3, 4)
        g.add_edge(0, 6)
        g.add_edge(4, 1)
        g.add_edge(1, 2)
        g.add_edge(1, 4)
        g.add_edge(1, 6)

        expected = [3, 4, 1, 2, 0, 6]
        actual = topological_sort(g)

        self.assertListEqual(expected, actual)


if __name__ == "__main__":
    unittest.main()
