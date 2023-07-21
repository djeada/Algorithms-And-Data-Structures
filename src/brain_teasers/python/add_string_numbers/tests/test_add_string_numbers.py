import unittest

from src.add_string_numbers import add_string_numbers


class TestAddStringNumbers(unittest.TestCase):
    def test_add_two_single_digit_numbers(self):
        self.assertEqual(add_string_numbers("1", "2"), "3")

    def test_add_two_double_digit_numbers(self):
        self.assertEqual(add_string_numbers("11", "22"), "33")

    def test_add_two_numbers_with_different_number_of_digits(self):
        self.assertEqual(add_string_numbers("1", "22"), "23")

    def test_add_two_big_numbers(self):
        self.assertEqual(add_string_numbers("123456789", "987654321"), "1111111110")

    def test_add_two_float_numbers(self):
        self.assertEqual(add_string_numbers("1.1", "2.2"), "3.3")

    def test_add_two_numbers_with_different_number_of_digits_and_floats(self):
        self.assertEqual(add_string_numbers("1.1344", "22.99999999"), "24.13439999")


if __name__ == "__main__":
    unittest.main()
