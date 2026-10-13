import unittest


from src.count_construct import (
    count_construct_basic,
    count_construct_memo,
    count_construct_table,
)


class TestCountConstructBasic(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = 0
        self.assertEqual(count_construct_basic(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = 0
        self.assertEqual(count_construct_basic(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = 1
        self.assertEqual(count_construct_basic(target, word_bank), result)

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = 1
        self.assertEqual(count_construct_basic(target, word_bank), result)


class TestCountConstructMemo(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = 0
        self.assertEqual(count_construct_memo(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = 0
        self.assertEqual(count_construct_memo(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = 1
        self.assertEqual(count_construct_memo(target, word_bank), result)

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = 1
        self.assertEqual(count_construct_memo(target, word_bank), result)


class TestCountConstructTab(unittest.TestCase):
    def test_negative_1(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        result = 0
        self.assertEqual(count_construct_table(target, word_bank), result)

    def test_negative_2(self):
        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        result = 0
        self.assertEqual(count_construct_table(target, word_bank), result)

    def test_positive_1(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        result = 1
        self.assertEqual(count_construct_table(target, word_bank), result)

    def test_positive_2(self):
        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        result = 1
        self.assertEqual(count_construct_table(target, word_bank), result)


class TestCountConstructEdgeCases(unittest.TestCase):
    FUNCS = (count_construct_basic, count_construct_memo, count_construct_table)

    def test_empty_target(self):
        for f in self.FUNCS:
            self.assertEqual(f("", ["a"]), 1, f.__name__)

    def test_empty_word_is_ignored(self):
        for f in self.FUNCS:
            self.assertEqual(f("ab", ["", "a", "b"]), 1, f.__name__)

    def test_overlapping_words(self):
        for f in self.FUNCS:
            self.assertEqual(f("aaaa", ["a", "aa"]), 5, f.__name__)


if __name__ == "__main__":
    unittest.main()
