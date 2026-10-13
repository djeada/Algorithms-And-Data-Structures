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


class TestAllConstructEdgeCases(unittest.TestCase):
    FUNCS = (all_construct_basic, all_construct_memo, all_construct_table)

    def test_empty_target(self):
        for f in self.FUNCS:
            self.assertEqual(f("", ["a"]), [[]], f.__name__)

    def test_empty_word_is_ignored(self):
        for f in self.FUNCS:
            self.assertEqual(f("ab", ["", "a", "b"]), [["a", "b"]], f.__name__)

    def test_impossible(self):
        for f in self.FUNCS:
            self.assertEqual(f("abc", ["a", "b"]), [], f.__name__)

    def test_words_are_in_target_order(self):
        # Every returned combination must concatenate to the target.
        target = "abcdef"
        word_bank = ["a", "b", "c", "d", "e", "f", "ab", "cd", "ef", "abc", "def"]
        for f in self.FUNCS:
            result = f(target, word_bank)
            self.assertTrue(result, f.__name__)
            for combination in result:
                self.assertEqual("".join(combination), target, f.__name__)
            self.assertEqual(len(result), 13, f.__name__)

    def test_all_variants_agree(self):
        word_bank = ["a", "ab", "b", "ba"]
        target = "abababa"
        expected = sorted(all_construct_table(target, word_bank))
        self.assertEqual(sorted(all_construct_basic(target, word_bank)), expected)
        self.assertEqual(sorted(all_construct_memo(target, word_bank)), expected)


if __name__ == "__main__":
    unittest.main()
