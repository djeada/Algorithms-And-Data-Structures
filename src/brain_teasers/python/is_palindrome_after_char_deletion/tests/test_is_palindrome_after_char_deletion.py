import unittest

from src.is_palindrome_after_char_deletion import is_palindrome_after_char_deletion


class TestIsPalindromeAfterCharDeletion(unittest.TestCase):
    def test_1(self):
        input_string = "racecar"
        expected = True
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_2(self):
        input_string = "hello"
        expected = False
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_3(self):
        input_string = "abcba"
        expected = True
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_4(self):
        input_string = "abcdefghhgfedcba"
        expected = True
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_5(self):
        input_string = "abcdefgfedcba"
        expected = True
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_6(self):
        input_string = "abcdefghijklmnonmlkjihgfedcba"
        expected = True
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_7(self):
        input_string = "abcdefghijklmnopqrstuvwxyzdcba"
        expected = False
        actual = is_palindrome_after_char_deletion(input_string)
        self.assertEqual(actual, expected)

    def test_delete_right_character_when_left_also_matches(self):
        self.assertTrue(is_palindrome_after_char_deletion("cuucu"))
        self.assertTrue(is_palindrome_after_char_deletion("ucuuc"))

    def test_empty_and_short(self):
        self.assertTrue(is_palindrome_after_char_deletion(""))
        self.assertTrue(is_palindrome_after_char_deletion("a"))
        self.assertTrue(is_palindrome_after_char_deletion("ab"))
        self.assertFalse(is_palindrome_after_char_deletion("abc"))


if __name__ == "__main__":
    unittest.main()
