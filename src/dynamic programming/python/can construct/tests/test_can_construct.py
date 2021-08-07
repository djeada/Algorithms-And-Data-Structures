import unittest

import os
import sys
file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from can_construct import can_construct_basic, can_construct_memo, can_construct_table


class TestCanConstructBasic(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = False
        self.assertEqual(can_construct_basic(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = False
        self.assertEqual(can_construct_basic(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = True
        self.assertEqual(can_construct_basic(target, word_bank), result)

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = True
        self.assertEqual(can_construct_basic(target, word_bank), result)


class TestCanConstructMemo(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = False
        self.assertEqual(can_construct_memo(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = False
        self.assertEqual(can_construct_memo(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = True
        self.assertEqual(can_construct_memo(target, word_bank), result)

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = True
        self.assertEqual(can_construct_memo(target, word_bank), result)


class TestCanConstructTab(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = False
        self.assertEqual(can_construct_table(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = False
        self.assertEqual(can_construct_table(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = True
        self.assertEqual(can_construct_table(target, word_bank), result)

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = True
        self.assertEqual(can_construct_table(target, word_bank), result)


if __name__ == "__main__":
    unittest.main()
