import unittest


from src.can_construct import (
    can_construct_basic,
    can_construct_memo,
    can_construct_table,
)


class TestCanConstructBasic(unittest.TestCase):
    def test_negative(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        self.assertFalse(can_construct_basic(target, word_bank))

        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        self.assertFalse(can_construct_basic(target, word_bank))

    def test_positive(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        self.assertTrue(can_construct_basic(target, word_bank))

        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        self.assertTrue(can_construct_basic(target, word_bank))


class TestCanConstructMemo(unittest.TestCase):
    def test_negative(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        self.assertFalse(can_construct_memo(target, word_bank))

        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        self.assertFalse(can_construct_memo(target, word_bank))

    def test_positive(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        self.assertTrue(can_construct_memo(target, word_bank))

        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        self.assertTrue(can_construct_memo(target, word_bank))


class TestCanConstructTab(unittest.TestCase):
    def test_negative(self):
        word_bank = ["bo", "rd", "ate", "t", "ska", "sk", "boar"]
        target = "skateboard"
        self.assertFalse(can_construct_table(target, word_bank))

        word_bank = ["mo", "ha", "cz"]
        target = "mocha"
        self.assertFalse(can_construct_table(target, word_bank))

    def test_positive(self):
        word_bank = ["a", "b", "c"]
        target = "abc"
        self.assertTrue(can_construct_table(target, word_bank))

        word_bank = ["ab", "abc", "cd", "def", "abcd"]
        target = "abcdef"
        self.assertTrue(can_construct_table(target, word_bank))


if __name__ == "__main__":
    unittest.main()
