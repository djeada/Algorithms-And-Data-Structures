import unittest

from src.k_closest_points import k_closest_points


class TestKClosestPoints(unittest.TestCase):
    def test_1(self):
        input_points = [(1, 3), (-2, 2)]
        input_K = 1
        expected = [(-2, 2)]
        actual = k_closest_points(input_points, input_K)
        self.assertEqual(actual, expected)

    def test_2(self):
        input_points = [(3, 3), (5, -1), (-2, 4)]
        input_K = 2
        expected = [(3, 3), (-2, 4)]
        actual = k_closest_points(input_points, input_K)
        self.assertEqual(actual, expected)

    def test_3(self):
        input_points = [(0, 1), (1, 0)]
        input_K = 2
        expected = [(0, 1), (1, 0)]
        actual = k_closest_points(input_points, input_K)
        self.assertEqual(actual, expected)

    def test_4(self):
        input_points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4)]
        input_K = 3
        expected = [(0, 0), (1, 1), (2, 2)]
        actual = k_closest_points(input_points, input_K)
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
