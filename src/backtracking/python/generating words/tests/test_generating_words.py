import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from generate_words import generate_words


class TestGenerateWords(unittest.TestCase):
    def test_positive_1(self):
        board = (("A", "B", "C"), ("D", "E", "F"), ("G", "H", "I"))

        word_dict = ("ABC", "ABCD", "CEG", "BEHI", "XXX")
        result = ("ABC", "CEG", "BEHI")

        self.assertEqual(sorted(generate_words(board, word_dict)), sorted(result))

    def test_positive_2(self):
        board = (
            ("A", "B", "C", "D"),
            ("E", "F", "G", "H"),
            ("I", "J", "K", "L"),
            ("M", "N", "O", "P"),
        )

        word_dict = ("AFKP", "ABCD", "HGFJN", "BEHI", "XXX")
        result = ("AFKP", "ABCD", "HGFJN")

        self.assertEqual(sorted(generate_words(board, word_dict)), sorted(result))

    def test_negative_1(self):
        board = list()
        word_dict = list()
        result = tuple()

        self.assertEqual(generate_words(board, word_dict), result)


if __name__ == "__main__":
    unittest.main()
