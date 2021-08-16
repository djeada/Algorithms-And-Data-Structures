import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from all_combinations import all_combinations


class TestAllCombinations(unittest.TestCase):
    def test_1(self):
        n = 4
        k = 2
        result = [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]

        self.assertEqual(sorted(all_combinations(n, k)), sorted(result))

    def test_2(self):
        n = 3
        k = 3
        result = [[1, 2, 3]]

        self.assertEqual(sorted(all_combinations(n, k)), sorted(result))

    def test_3(self):
        n = 5
        k = 3
        result = [
            [1, 2, 3],
            [1, 2, 4],
            [1, 2, 5],
            [1, 3, 4],
            [1, 3, 5],
            [1, 4, 5],
            [2, 3, 4],
            [2, 3, 5],
            [2, 4, 5],
            [3, 4, 5],
        ]

        self.assertEqual(sorted(all_combinations(n, k)), sorted(result))

    def test_4(self):
        n = 2
        k = 5
        result = list()

        self.assertEqual(sorted(all_combinations(n, k)), sorted(result))


if __name__ == "__main__":
    unittest.main()
