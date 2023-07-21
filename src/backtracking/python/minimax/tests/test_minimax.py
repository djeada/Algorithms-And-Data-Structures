import unittest
from src.minimax import minimax, find_best_move


class TestMinimax(unittest.TestCase):
    def test_empty_board(self):
        board = [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0],
        ]
        player = -1
        expected = (0, 0)
        actual = find_best_move(board, player)

        self.assertEqual(expected, actual)

    def test_two_moves_already_made(self):
        board = [[-1, 0, 0], [0, 1, 0], [0, 0, 0]]
        player = -1

        expected = (0, 1)
        actual = find_best_move(board, player)

        self.assertEqual(expected, actual)

    def test_draw(self):
        board = [[-1, 1, -1], [1, -1, 1], [-1, 1, -1]]
        player = -1

        actual = find_best_move(board, player)

        self.assertIsNone(actual)

    def test_player_a_wins(self):
        board = [[-1, 1, -1], [1, 1, 0], [-1, 0, -1]]
        player = -1
        expected = (1, 2)
        actual = find_best_move(board, player)

        self.assertEqual(expected, actual)
