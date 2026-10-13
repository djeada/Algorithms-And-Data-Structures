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

    def test_optimal_where_local_search_fails(self):
        # Optimal: flip rows to start with 1, then flip columns -> 19
        self.assertEqual(
            score_after_flipping_matrix([[0, 0, 0], [1, 1, 1], [1, 0, 1]]), 19
        )
        self.assertEqual(
            score_after_flipping_matrix(
                [[1, 0, 0], [1, 0, 1], [0, 0, 1], [0, 1, 1], [0, 0, 1]]
            ),
            30,
        )

    def test_does_not_mutate_input(self):
        matrix = [[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]
        score_after_flipping_matrix(matrix)
        self.assertEqual(matrix, [[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]])


if __name__ == "__main__":
    unittest.main()
