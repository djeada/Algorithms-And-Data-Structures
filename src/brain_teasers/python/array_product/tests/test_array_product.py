import unittest

from src.array_product import product_of_array_except_self


class TestArrayProduct(unittest.TestCase):
    def test_array_product(self):
        input_array = [1, 2, 3, 4, 5]
        expected = [120, 60, 40, 30, 24]
        actual = product_of_array_except_self(input_array)
        self.assertEqual(actual, expected)

    def test_empty_array(self):
        input_array = []
        expected = []
        actual = product_of_array_except_self(input_array)
        self.assertEqual(actual, expected)

    def test_array_with_one_element(self):
        input_array = [1]
        expected = [1]
        actual = product_of_array_except_self(input_array)
        self.assertEqual(actual, expected)

    def test_zeros_negatives_and_no_mutation(self):
        arr = [1, 0, -3, 4]
        self.assertEqual(product_of_array_except_self(arr), [0, -12, 0, 0])
        self.assertEqual(arr, [1, 0, -3, 4])
        self.assertEqual(product_of_array_except_self([0, 0, 2]), [0, 0, 0])


if __name__ == "__main__":
    unittest.main()
