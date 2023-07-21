from src.all_combinations import all_combinations
import unittest


class TestAllCombinations(unittest.TestCase):
    def test_n4_k2(self):
        n = 4
        k = 2
        expected = [
            [0, 1],
            [0, 2],
            [0, 3],
            [0, 4],
            [1, 2],
            [1, 3],
            [1, 4],
            [2, 3],
            [2, 4],
            [3, 4],
        ]
        actual = all_combinations(n, k)

        self.assertListEqual(sorted(expected), sorted(actual))

    def test_n2_k1(self):
        n = 2
        k = 1
        expected = [[0], [1], [2]]

        actual = all_combinations(n, k)

        self.assertListEqual(sorted(expected), sorted(actual))

    def test_n10_k1(self):
        n = 10
        k = 1
        expected = [[0], [1], [2], [3], [4], [5], [6], [7], [8], [9], [10]]

        actual = all_combinations(n, k)

        self.assertListEqual(sorted(expected), sorted(actual))


if __name__ == "__main__":
    unittest.main()
