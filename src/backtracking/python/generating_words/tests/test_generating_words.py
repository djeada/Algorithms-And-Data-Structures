from src.generate_words import generate_words
import unittest


class TestGenerateWords(unittest.TestCase):
    def test_3x3_board(self):
        board = (("A", "B", "C"), ("D", "E", "F"), ("G", "H", "I"))

        word_dict = ("ABC", "ABCD", "CEG", "BEHI", "XXX")
        expected = ("ABC", "CEG", "BEHI")
        actual = generate_words(board, word_dict)

        self.assertEqual(sorted(expected), sorted(actual))

    def test_empty_board(self):
        board = list()
        word_dict = list()
        expected = tuple()
        actual = generate_words(board, word_dict)

        self.assertEqual(sorted(expected), sorted(actual))

    def test_empty_word_dict(self):
        board = (("A", "B", "C"), ("D", "E", "F"), ("G", "H", "I"))
        word_dict = list()
        expected = tuple()
        actual = generate_words(board, word_dict)

        self.assertEqual(sorted(expected), sorted(actual))


if __name__ == "__main__":
    unittest.main()
