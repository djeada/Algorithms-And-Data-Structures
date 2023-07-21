import unittest

from src.randomize_array import randomize_array


class TestRandomizeArray(unittest.TestCase):
    def test_randomize_array(self):
        original_array = [1, 2, 3, 4, 5]
        randomized_array = randomize_array(original_array.copy())
        self.assertNotEqual(original_array, randomized_array)
        self.assertEqual(sorted(original_array), sorted(randomized_array))

    def test_randomize_array_empty(self):
        original_array = []
        randomized_array = randomize_array(original_array.copy())
        self.assertEqual(original_array, randomized_array)

    def test_randomize_array_single(self):
        original_array = [1]
        randomized_array = randomize_array(original_array.copy())
        self.assertEqual(original_array, randomized_array)


if __name__ == "__main__":
    unittest.main()
