import unittest

from src.subarray_sum import subarray_sum


class TestSubarraySum(unittest.TestCase):
    def test_1(self):
        input_array = [1, 2, 3]
        start_index = 0
        end_index = 2
        expected = 3
        actual = subarray_sum(input_array, start_index, end_index)

        self.assertEqual(actual, expected)

    def test_2(self):
        input_array = [5, 5, 1, 9, 3, 4]
        start_index = 3
        end_index = 5
        expected = 12
        actual = subarray_sum(input_array, start_index, end_index)

        self.assertEqual(actual, expected)

    def test_3(self):
        input_array = [1, 2, 3, 4, 5]
        start_index = 0
        end_index = 5
        expected = 15
        actual = subarray_sum(input_array, start_index, end_index)

        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
