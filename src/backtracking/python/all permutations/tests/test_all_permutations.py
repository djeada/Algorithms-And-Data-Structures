import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from all_permutations import all_permutations


class TestAllPermutations(unittest.TestCase):
    def test_1(self):
        input_list = [1, 2]
        result = [[1, 2], [2, 1]]

        self.assertEqual(sorted(all_permutations(input_list)), sorted(result))

    def test_2(self):
        input_list = [3, 1, 2]
        result = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]

        self.assertEqual(sorted(all_permutations(input_list)), sorted(result))

    def test_3(self):
        input_list = ["A", "B", "C"]
        result = [
            ["A", "B", "C"],
            ["A", "C", "B"],
            ["B", "A", "C"],
            ["B", "C", "A"],
            ["C", "A", "B"],
            ["C", "B", "A"],
        ]

        self.assertEqual(sorted(all_permutations(input_list)), sorted(result))

    def test_4(self):
        input_list = [3, 1, 2, 4]
        result = [
            [3, 1, 2, 4],
            [3, 1, 4, 2],
            [3, 2, 1, 4],
            [3, 2, 4, 1],
            [3, 4, 1, 2],
            [3, 4, 2, 1],
            [1, 3, 2, 4],
            [1, 3, 4, 2],
            [1, 2, 3, 4],
            [1, 2, 4, 3],
            [1, 4, 3, 2],
            [1, 4, 2, 3],
            [2, 3, 1, 4],
            [2, 3, 4, 1],
            [2, 1, 3, 4],
            [2, 1, 4, 3],
            [2, 4, 3, 1],
            [2, 4, 1, 3],
            [4, 3, 1, 2],
            [4, 3, 2, 1],
            [4, 1, 3, 2],
            [4, 1, 2, 3],
            [4, 2, 3, 1],
            [4, 2, 1, 3],
        ]

        self.assertEqual(sorted(all_permutations(input_list)), sorted(result))


if __name__ == "__main__":
    unittest.main()
