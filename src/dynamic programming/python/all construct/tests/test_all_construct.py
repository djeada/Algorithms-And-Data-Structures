import unittest

import os
import sys
file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from all_construct import all_construct_basic, all_construct_memo, all_construct_table


def compare_2d_lists(a, b):
    for i in range(len(a)):
        a[i] = sorted(a[i])

    for i in range(len(b)):
        b[i] = sorted(b[i])

    return sorted(a, key=lambda x: x[0]) == sorted(b, key=lambda x: x[0])


class TestAllConstructBasic(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = list()
        self.assertEqual(all_construct_basic(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = list()
        self.assertEqual(all_construct_basic(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = [["a", "b", "c"]]
        self.assertTrue(
            compare_2d_lists(all_construct_basic(target, word_bank), result)
        )

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = [["abc", "def"]]
        self.assertTrue(
            compare_2d_lists(all_construct_basic(target, word_bank), result)
        )


class TestAllConstructMemo(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = list()
        self.assertEqual(all_construct_memo(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = list()
        self.assertEqual(all_construct_memo(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = [["a", "b", "c"]]
        self.assertTrue(compare_2d_lists(all_construct_memo(target, word_bank), result))

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = [["abc", "def"]]
        self.assertTrue(compare_2d_lists(all_construct_memo(target, word_bank), result))


class TestAllConstructTab(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = list()
        self.assertEqual(all_construct_table(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = list()
        self.assertEqual(all_construct_table(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = [["a", "b", "c"]]
        self.assertTrue(
            compare_2d_lists(all_construct_table(target, word_bank), result)
        )

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = [["abc", "def"]]
        self.assertTrue(
            compare_2d_lists(all_construct_table(target, word_bank), result)
        )


if __name__ == "__main__":
    unittest.main()
