import unittest

from src.minimum_insertions_for_palindrome import (
    minimum_insertions_for_palindrome_basic,
    minimum_insertions_for_palindrome_memo,
    minimum_insertions_for_palindrome_tab,
)


class TestMinimumInsertionsForPalindromeBasic(unittest.TestCase):
    def test_1(self):
        s = "ab"
        result = 1
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_2(self):
        s = "aa"
        result = 0
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_3(self):
        s = "abcd"
        result = 3
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_4(self):
        s = "abcda"
        result = 2
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_5(self):
        s = "abcde"
        result = 4
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)


class TestMinimumInsertionsForPalindromeMemo(unittest.TestCase):
    def test_1(self):
        s = "ab"
        result = 1
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_2(self):
        s = "aa"
        result = 0
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_3(self):
        s = "abcd"
        result = 3
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_4(self):
        s = "abcda"
        result = 2
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_5(self):
        s = "abcde"
        result = 4
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)


class TestMinimumInsertionsForPalindromeTab(unittest.TestCase):
    def test_1(self):
        s = "ab"
        result = 1
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_2(self):
        s = "aa"
        result = 0
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_3(self):
        s = "abcd"
        result = 3
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_4(self):
        s = "abcda"
        result = 2
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_5(self):
        s = "abcde"
        result = 4
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)


if __name__ == "__main__":
    unittest.main()
