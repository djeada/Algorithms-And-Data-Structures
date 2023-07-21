import unittest
from src.hamiltonian_paths import Graph, find_hamiltonian_paths


class TestHamiltonianPaths(unittest.TestCase):
    def test_positive_1(self):
        G = Graph()
        G.add_edge(0, 1)
        G.add_edge(0, 2)
        G.add_edge(0, 3)
        G.add_edge(1, 2)
        G.add_edge(1, 3)
        G.add_edge(2, 3)

        expected = [
            [0, 1, 2, 3],
            [0, 1, 3, 2],
            [0, 2, 1, 3],
            [0, 2, 3, 1],
            [0, 3, 1, 2],
            [0, 3, 2, 1],
            [1, 0, 2, 3],
            [1, 0, 3, 2],
            [1, 2, 0, 3],
            [1, 2, 3, 0],
            [1, 3, 0, 2],
            [1, 3, 2, 0],
            [2, 0, 1, 3],
            [2, 0, 3, 1],
            [2, 1, 0, 3],
            [2, 1, 3, 0],
            [2, 3, 0, 1],
            [2, 3, 1, 0],
            [3, 0, 1, 2],
            [3, 0, 2, 1],
            [3, 1, 0, 2],
            [3, 1, 2, 0],
            [3, 2, 0, 1],
            [3, 2, 1, 0],
        ]

        actual = find_hamiltonian_paths(G)
        self.assertEqual(len(expected), len(actual))

        for configuration in actual:
            self.assertTrue(configuration in expected)

    def test_negative_1(self):
        G = Graph()
        G.add_edge(0, 2)
        G.add_edge(1, 1)
        G.add_edge(2, 3)
        G.add_edge(2, 4)
        G.add_edge(4, 5)

        expected = []
        actual = find_hamiltonian_paths(G)
        self.assertEqual(expected, actual)


if __name__ == "__main__":
    unittest.main()
