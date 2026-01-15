"""Tests for jump search algorithm."""

import unittest
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / "src"))

from jump_search import jump_search


class TestJumpSearch(unittest.TestCase):
    """Test cases for the jump_search function."""

    def test_empty_array(self):
        """Searching an empty array returns None."""
        self.assertIsNone(jump_search([], 5))

    def test_single_element_found(self):
        """Searching for the only element in a single-element array."""
        self.assertEqual(jump_search([5], 5), 0)

    def test_single_element_not_found(self):
        """Searching for a missing element in a single-element array."""
        self.assertIsNone(jump_search([5], 3))

    def test_target_at_beginning(self):
        """Target is at the first position."""
        self.assertEqual(jump_search([1, 2, 3, 4, 5], 1), 0)

    def test_target_at_end(self):
        """Target is at the last position."""
        self.assertEqual(jump_search([1, 2, 3, 4, 5], 5), 4)

    def test_target_in_middle(self):
        """Target is in the middle of the array."""
        self.assertEqual(jump_search([1, 2, 3, 4, 5], 3), 2)

    def test_target_not_found_too_small(self):
        """Target is smaller than all elements."""
        self.assertIsNone(jump_search([2, 4, 6, 8, 10], 1))

    def test_target_not_found_too_large(self):
        """Target is larger than all elements."""
        self.assertIsNone(jump_search([2, 4, 6, 8, 10], 12))

    def test_target_not_found_in_gap(self):
        """Target falls between existing elements."""
        self.assertIsNone(jump_search([2, 4, 6, 8, 10], 5))

    def test_with_negative_numbers(self):
        """Searching in a sorted array with negative numbers."""
        self.assertEqual(jump_search([-10, -5, 0, 5, 10], -5), 1)

    def test_large_sorted_array(self):
        """Searching in a large sorted array."""
        array = list(range(0, 100))
        self.assertEqual(jump_search(array, 75), 75)

    def test_two_elements_find_first(self):
        """Find the first element in a two-element array."""
        self.assertEqual(jump_search([1, 2], 1), 0)

    def test_two_elements_find_second(self):
        """Find the second element in a two-element array."""
        self.assertEqual(jump_search([1, 2], 2), 1)


if __name__ == "__main__":
    unittest.main()
