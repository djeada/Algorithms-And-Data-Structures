import unittest
from src.k_colorable_configurations import find_k_colorable_configurations, Graph


class TestKColorableConfigurations(unittest.TestCase):
    def test_positive_1(self):
        G = Graph()
        G.add_edge(0, 1)
        G.add_edge(0, 4)
        G.add_edge(0, 5)
        G.add_edge(4, 5)
        G.add_edge(1, 4)
        G.add_edge(1, 3)
        G.add_edge(2, 3)
        G.add_edge(2, 4)
        k = 3

        expected = [
            [0, 1, 0, 2, 2, 1],
            [0, 1, 1, 0, 2, 1],
            [0, 1, 1, 2, 2, 1],
            [0, 2, 0, 1, 1, 2],
            [0, 2, 2, 0, 1, 2],
            [0, 2, 2, 1, 1, 2],
            [1, 0, 0, 1, 2, 0],
            [1, 0, 0, 2, 2, 0],
            [1, 0, 1, 2, 2, 0],
            [1, 2, 1, 0, 0, 2],
            [1, 2, 2, 0, 0, 2],
            [1, 2, 2, 1, 0, 2],
            [2, 0, 0, 1, 1, 0],
            [2, 0, 0, 2, 1, 0],
            [2, 0, 2, 1, 1, 0],
            [2, 1, 1, 0, 0, 1],
            [2, 1, 1, 2, 0, 1],
            [2, 1, 2, 0, 0, 1],
        ]

        actual = find_k_colorable_configurations(G, k)
        self.assertEqual(len(expected), len(actual))

        for configuration in actual:
            self.assertTrue(configuration in expected)

    def test_negative_1(self):
        G = Graph()
        G.add_edge(0, 1)
        G.add_edge(1, 2)
        G.add_edge(2, 0)
        k = 2

        expected = []
        actual = find_k_colorable_configurations(G, k)
        self.assertEqual(expected, actual)


if __name__ == "__main__":
    unittest.main()
