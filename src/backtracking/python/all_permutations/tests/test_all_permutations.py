# tests/test_all_permutations.py

import unittest

from src.all_permutations import (
    all_permutations_itertools,
    all_permutations_backtracking
)


class TestAllPermutations(unittest.TestCase):
    def setUp(self):
        # We will test these two implementations side by side in every test.
        self.funcs_to_test = [
            all_permutations_itertools,
            all_permutations_backtracking,
        ]

    def test_two_elements(self):
        input_list = [1, 2]
        expected = [[1, 2], [2, 1]]

        for func in self.funcs_to_test:
            with self.subTest(func=func.__name__):
                actual = func(input_list[:])  # pass a fresh copy to avoid side‐effects
                # Sort both lists of lists before comparing
                self.assertListEqual(sorted(expected), sorted(actual))

    def test_three_elements(self):
        input_list = [3, 1, 2]
        expected = [
            [1, 2, 3],
            [1, 3, 2],
            [2, 1, 3],
            [2, 3, 1],
            [3, 2, 1],
            [3, 1, 2],
        ]

        for func in self.funcs_to_test:
            with self.subTest(func=func.__name__):
                actual = func(input_list[:])
                self.assertListEqual(sorted(expected), sorted(actual))

    def test_three_strings(self):
        input_list = ["A", "B", "C"]
        expected = [
            ["A", "B", "C"],
            ["A", "C", "B"],
            ["B", "A", "C"],
            ["B", "C", "A"],
            ["C", "A", "B"],
            ["C", "B", "A"],
        ]

        for func in self.funcs_to_test:
            with self.subTest(func=func.__name__):
                actual = func(input_list[:])
                self.assertListEqual(sorted(expected), sorted(actual))

    def test_four_elements(self):
        input_list = [3, 1, 2, 4]
        expected = [
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

        for func in self.funcs_to_test:
            with self.subTest(func=func.__name__):
                actual = func(input_list[:])
                self.assertListEqual(sorted(expected), sorted(actual))


if __name__ == "__main__":
    unittest.main()
