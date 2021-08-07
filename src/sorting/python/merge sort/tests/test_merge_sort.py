import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from merge_sort import mergesort_v1, mergesort_v2


class TestMergeSortV1(unittest.TestCase):
    def test_empty_array(self):
        array = list()
        result = list()

        self.assertEqual(mergesort_v1(array), result)

    def test_single_element(self):
        array = [1]
        result = [1]

        self.assertEqual(mergesort_v1(array), result)

    def test_increasing_order(self):
        array = [1, 2, 3, 4, 5]
        result = [1, 2, 3, 4, 5]

        self.assertEqual(mergesort_v1(array), result)

    def test_decreasing_order(self):
        array = [5, 4, 3, 2, 1]
        result = [1, 2, 3, 4, 5]

        self.assertEqual(mergesort_v1(array), result)

    def test_random_order(self):
        array = [2, 5, 1, 4, 3]
        result = [1, 2, 3, 4, 5]

        self.assertEqual(mergesort_v1(array), result)


class TestMergeSortV2(unittest.TestCase):
    def test_empty_array(self):
        array = list()
        result = list()

        self.assertEqual(mergesort_v2(array), result)

    def test_single_element(self):
        array = [1]
        result = [1]

        self.assertEqual(mergesort_v2(array), result)

    def test_increasing_order(self):
        array = [1, 2, 3, 4, 5]
        result = [1, 2, 3, 4, 5]

        self.assertEqual(mergesort_v2(array), result)

    def test_decreasing_order(self):
        array = [5, 4, 3, 2, 1]
        result = [1, 2, 3, 4, 5]

        self.assertEqual(mergesort_v2(array), result)

    def test_random_order(self):
        array = [2, 5, 1, 4, 3]
        result = [1, 2, 3, 4, 5]

        self.assertEqual(mergesort_v2(array), result)


if __name__ == "__main__":
    unittest.main()
