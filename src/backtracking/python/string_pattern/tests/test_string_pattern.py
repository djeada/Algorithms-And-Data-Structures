import unittest
from src.string_pattern import string_pattern


class TestStringPattern(unittest.TestCase):
    def test_positive_1(self):
        string = "basetestcasebase"
        pattern = "ABCDA"
        self.assertTrue(string_pattern(string, pattern))

    def test_positive_2(self):
        string = "basetestcasebase"
        pattern = "A"
        self.assertTrue(string_pattern(string, pattern))

    def test_positive_3(self):
        string = "basetestcasebase"
        pattern = "ABA"
        self.assertTrue(string_pattern(string, pattern))

    def test_negative_1(self):
        string = "basetestcasebase"
        pattern = "AA"
        self.assertFalse(string_pattern(string, pattern))

    def test_negative_2(self):
        string = "abcdefg"
        pattern = "aa"
        self.assertFalse(string_pattern(string, pattern))


if __name__ == "__main__":
    unittest.main()
