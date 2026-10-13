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

    def test_no_element_stays_in_place(self):
        original = [1, 2, 3, 4, 5]
        for _ in range(200):
            result = randomize_array(original)
            self.assertEqual(sorted(result), original)
            self.assertTrue(all(a != b for a, b in zip(original, result)))

    def test_duplicates_with_possible_derangement(self):
        original = [1, 1, 2, 2, 3, 3]
        for _ in range(200):
            result = randomize_array(original)
            self.assertEqual(sorted(result), original)
            self.assertTrue(all(a != b for a, b in zip(original, result)))

    def test_returns_new_list_and_keeps_input(self):
        for original in ([], [7], [4, 4, 4]):
            snapshot = list(original)
            result = randomize_array(original)
            self.assertEqual(result, snapshot)
            self.assertIsNot(result, original)
            self.assertEqual(original, snapshot)


if __name__ == "__main__":
    unittest.main()
