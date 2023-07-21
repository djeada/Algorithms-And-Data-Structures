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


if __name__ == "__main__":
    unittest.main()
