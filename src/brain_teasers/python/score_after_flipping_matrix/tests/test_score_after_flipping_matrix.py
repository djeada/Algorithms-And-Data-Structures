import unittest

from src.score_after_flipping_matrix import score_after_flipping_matrix


class TestScoreAfterFlippingMatrix(unittest.TestCase):
    def test_1(self):
        input_matrix = [[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]
        expected = 39
        actual = score_after_flipping_matrix(input_matrix)
        self.assertEqual(actual, expected)

    def test_2(self):
        input_matrix = [[1, 1, 1], [1, 0, 1], [0, 0, 0]]
        expected = 19
        actual = score_after_flipping_matrix(input_matrix)
        self.assertEqual(actual, expected)

    def test_3(self):
        input_matrix = [[1]]
        expected = 1
        actual = score_after_flipping_matrix(input_matrix)
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
