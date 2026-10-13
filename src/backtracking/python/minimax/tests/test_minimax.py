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

    def test_blocks_opponent_win(self):
        board = [[0, 0, 0], [0, -1, 0], [1, 1, 0]]
        self.assertEqual((2, 2), find_best_move(board, -1))

    def test_minimax_scores_each_side_by_its_own_goal(self):
        # player 1 to move and can win immediately -> score -1
        board = [[1, 1, 0], [-1, -1, 0], [0, 0, 0]]
        self.assertEqual(-1, minimax(board, 1))
        # player -1 to move and can win immediately -> score 1
        self.assertEqual(1, minimax(board, -1))
