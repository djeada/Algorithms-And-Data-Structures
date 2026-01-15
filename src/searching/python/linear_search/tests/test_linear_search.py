"""Tests for linear search algorithm."""

import unittest
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / "src"))

from linear_search import linear_search


class TestLinearSearch(unittest.TestCase):
    """Test cases for the linear_search function."""

    def test_empty_array(self):
        """Searching an empty array returns None."""
        self.assertIsNone(linear_search([], 5))

    def test_single_element_found(self):
        """Searching for the only element in a single-element array."""
        self.assertEqual(linear_search([5], 5), 0)

    def test_single_element_not_found(self):
        """Searching for a missing element in a single-element array."""
        self.assertIsNone(linear_search([5], 3))

    def test_target_at_beginning(self):
        """Target is at the first position."""
        self.assertEqual(linear_search([1, 2, 3, 4, 5], 1), 0)

    def test_target_at_end(self):
        """Target is at the last position."""
        self.assertEqual(linear_search([1, 2, 3, 4, 5], 5), 4)

    def test_target_in_middle(self):
        """Target is in the middle of the array."""
        self.assertEqual(linear_search([1, 2, 3, 4, 5], 3), 2)

    def test_target_not_found(self):
        """Target is not in the array."""
        self.assertIsNone(linear_search([1, 2, 3, 4, 5], 6))

    def test_with_duplicates_returns_first(self):
        """Returns the index of the first occurrence when duplicates exist."""
        self.assertEqual(linear_search([1, 2, 3, 2, 1], 2), 1)

    def test_with_negative_numbers(self):
        """Searching in an array with negative numbers."""
        self.assertEqual(linear_search([-5, -3, -1, 0, 2, 4], -3), 1)

    def test_unsorted_array(self):
        """Works correctly on unsorted arrays."""
        self.assertEqual(linear_search([5, 2, 8, 1, 9], 8), 2)


if __name__ == "__main__":
    unittest.main()
