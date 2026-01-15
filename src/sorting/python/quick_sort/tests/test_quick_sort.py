"""Tests for quick sort algorithms."""

import unittest
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / "src"))

from quick_sort import quick_sort, quick_sort_three_way


class TestQuickSort(unittest.TestCase):
    """Test cases for the quick_sort function (2-way partitioning)."""

    def test_empty_array(self):
        """Sorting an empty array returns an empty array."""
        self.assertEqual(quick_sort([]), [])

    def test_single_element(self):
        """Sorting a single element array returns the same array."""
        self.assertEqual(quick_sort([1]), [1])

    def test_two_elements_sorted(self):
        """Sorting two already sorted elements."""
        self.assertEqual(quick_sort([1, 2]), [1, 2])

    def test_two_elements_reversed(self):
        """Sorting two elements in reverse order."""
        self.assertEqual(quick_sort([2, 1]), [1, 2])

    def test_increasing_order(self):
        """Sorting an already sorted array."""
        self.assertEqual(quick_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])

    def test_decreasing_order(self):
        """Sorting a reverse-sorted array."""
        self.assertEqual(quick_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])

    def test_random_order(self):
        """Sorting an array in random order."""
        self.assertEqual(quick_sort([2, 5, 1, 4, 3]), [1, 2, 3, 4, 5])

    def test_with_duplicates(self):
        """Sorting an array with duplicate values."""
        self.assertEqual(quick_sort([3, 1, 4, 1, 5, 9, 2, 6, 5]), [1, 1, 2, 3, 4, 5, 5, 6, 9])

    def test_with_negative_numbers(self):
        """Sorting an array containing negative numbers."""
        self.assertEqual(quick_sort([-3, 1, -4, 1, 5]), [-4, -3, 1, 1, 5])

    def test_all_same_elements(self):
        """Sorting an array where all elements are the same."""
        self.assertEqual(quick_sort([5, 5, 5, 5]), [5, 5, 5, 5])


class TestQuickSortThreeWay(unittest.TestCase):
    """Test cases for the quick_sort_three_way function (3-way partitioning)."""

    def test_empty_array(self):
        """Sorting an empty array returns an empty array."""
        self.assertEqual(quick_sort_three_way([]), [])

    def test_single_element(self):
        """Sorting a single element array returns the same array."""
        self.assertEqual(quick_sort_three_way([1]), [1])

    def test_two_elements_sorted(self):
        """Sorting two already sorted elements."""
        self.assertEqual(quick_sort_three_way([1, 2]), [1, 2])

    def test_two_elements_reversed(self):
        """Sorting two elements in reverse order."""
        self.assertEqual(quick_sort_three_way([2, 1]), [1, 2])

    def test_increasing_order(self):
        """Sorting an already sorted array."""
        self.assertEqual(quick_sort_three_way([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])

    def test_decreasing_order(self):
        """Sorting a reverse-sorted array."""
        self.assertEqual(quick_sort_three_way([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])

    def test_random_order(self):
        """Sorting an array in random order."""
        self.assertEqual(quick_sort_three_way([2, 5, 1, 4, 3]), [1, 2, 3, 4, 5])

    def test_with_duplicates(self):
        """Sorting an array with duplicate values."""
        self.assertEqual(quick_sort_three_way([3, 1, 4, 1, 5, 9, 2, 6, 5]), [1, 1, 2, 3, 4, 5, 5, 6, 9])

    def test_with_negative_numbers(self):
        """Sorting an array containing negative numbers."""
        self.assertEqual(quick_sort_three_way([-3, 1, -4, 1, 5]), [-4, -3, 1, 1, 5])

    def test_all_same_elements(self):
        """Sorting an array where all elements are the same."""
        self.assertEqual(quick_sort_three_way([5, 5, 5, 5]), [5, 5, 5, 5])


if __name__ == "__main__":
    unittest.main()
