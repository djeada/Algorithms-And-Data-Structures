import unittest

from src.all_construct import (
    all_construct_basic,
    all_construct_memo,
    all_construct_table,
)


def compare_2d_lists(l1, l2):
    if len(l1) != len(l2):
        return False

    for sublist1, sublist2 in zip(l1, l2):
        if set(sublist1) != set(sublist2):
            return False

    return True


class TestAllConstructBasic(unittest.TestCase):
    def test_no_combinations_possible(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = all_construct_basic(target, word_bank)
        self.assertEqual(result, [])

    def test_no_combinations_possible_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = all_construct_basic(target, word_bank)
        self.assertEqual(result, [])

    def test_single_combination_possible(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = all_construct_basic(target, word_bank)
        self.assertTrue(compare_2d_lists(result, [["a", "b", "c"]]))

    def test_multiple_combinations_possible(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = all_construct_basic(target, word_bank)
        self.assertTrue(compare_2d_lists(result, [["abc", "def"]]))


class TestAllConstructMemo(unittest.TestCase):
    def test_no_combinations_possible(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = all_construct_memo(target, word_bank)
        self.assertEqual(result, [])

    def test_no_combinations_possible_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = all_construct_memo(target, word_bank)
        self.assertEqual(result, [])

    def test_single_combination_possible(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = all_construct_memo(target, word_bank)
        self.assertTrue(compare_2d_lists(result, [["a", "b", "c"]]))

    def test_multiple_combinations_possible(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = all_construct_memo(target, word_bank)
        self.assertTrue(compare_2d_lists(result, [["abc", "def"]]))


class TestAllConstructTab(unittest.TestCase):
    def test_no_combinations_possible(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = all_construct_table(target, word_bank)
        self.assertEqual(result, [])

    def test_no_combinations_possible_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = all_construct_table(target, word_bank)
        self.assertEqual(result, [])

    def test_single_combination_possible(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = all_construct_table(target, word_bank)
        self.assertTrue(compare_2d_lists(result, [["a", "b", "c"]]))

    def test_multiple_combinations_possible(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = all_construct_table(target, word_bank)
        self.assertTrue(compare_2d_lists(result, [["abc", "def"]]))


if __name__ == "__main__":
    unittest.main()
