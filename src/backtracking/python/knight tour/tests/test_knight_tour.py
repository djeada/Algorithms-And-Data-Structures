import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from knight_tour import knight_tour


class TestKnightTour(unittest.TestCase):
    def test_1(self):
        n = 1
        result = [[1]]

        self.assertEqual(sorted(knight_tour(n)), sorted(result))

    def test_2(self):
        n = 2
        result = list()

        self.assertEqual(sorted(knight_tour(n)), sorted(result))

    def test_3(self):
        n = 3
        result = list()

        self.assertEqual(sorted(knight_tour(n)), sorted(result))

    def test_4(self):
        n = 4
        result = list()

        self.assertEqual(sorted(knight_tour(n)), sorted(result))

    def test_5(self):
        n = 5
        result = [
            [1, 14, 19, 8, 25],
            [6, 9, 2, 13, 18],
            [15, 20, 7, 24, 3],
            [10, 5, 22, 17, 12],
            [21, 16, 11, 4, 23],
        ]

        self.assertEqual(sorted(knight_tour(n)), sorted(result))

    def test_6(self):
        n = 6
        result = [
            [1, 22, 13, 30, 33, 36],
            [12, 29, 2, 35, 14, 31],
            [21, 8, 23, 32, 3, 34],
            [28, 11, 4, 17, 24, 15],
            [7, 20, 9, 26, 5, 18],
            [10, 27, 6, 19, 16, 25],
        ]

        self.assertEqual(sorted(knight_tour(n)), sorted(result))


if __name__ == "__main__":
    unittest.main()
