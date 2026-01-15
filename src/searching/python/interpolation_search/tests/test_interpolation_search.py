"""Tests for interpolation search algorithm."""

import unittest
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / "src"))

from interpolation_search import interpolation_search


class TestInterpolationSearch(unittest.TestCase):
    """Test cases for the interpolation_search function."""

    def test_empty_array(self):
        """Searching an empty array returns None."""
        self.assertIsNone(interpolation_search([], 5))

    def test_single_element_found(self):
        """Searching for the only element in a single-element array."""
        self.assertEqual(interpolation_search([5], 5), 0)

    def test_single_element_not_found(self):
        """Searching for a missing element in a single-element array."""
        self.assertIsNone(interpolation_search([5], 3))

    def test_target_at_beginning(self):
        """Target is at the first position."""
        self.assertEqual(interpolation_search([10, 20, 30, 40, 50], 10), 0)

    def test_target_at_end(self):
        """Target is at the last position."""
        self.assertEqual(interpolation_search([10, 20, 30, 40, 50], 50), 4)

    def test_target_in_middle(self):
        """Target is in the middle of the array."""
        self.assertEqual(interpolation_search([10, 20, 30, 40, 50], 30), 2)

    def test_target_not_found_too_small(self):
        """Target is smaller than all elements."""
        self.assertIsNone(interpolation_search([10, 20, 30, 40, 50], 5))

    def test_target_not_found_too_large(self):
        """Target is larger than all elements."""
        self.assertIsNone(interpolation_search([10, 20, 30, 40, 50], 60))

    def test_target_not_found_in_gap(self):
        """Target falls between existing elements."""
        self.assertIsNone(interpolation_search([10, 20, 30, 40, 50], 25))

    def test_uniform_distribution(self):
        """Works well on uniformly distributed data."""
        array = list(range(0, 100, 10))  # [0, 10, 20, ..., 90]
        self.assertEqual(interpolation_search(array, 50), 5)

    def test_all_same_elements_found(self):
        """Array with all same elements, target matches."""
        self.assertEqual(interpolation_search([5, 5, 5, 5], 5), 0)

    def test_all_same_elements_not_found(self):
        """Array with all same elements, target doesn't match."""
        self.assertIsNone(interpolation_search([5, 5, 5, 5], 3))

    def test_two_elements_find_first(self):
        """Find the first element in a two-element array."""
        self.assertEqual(interpolation_search([10, 20], 10), 0)

    def test_two_elements_find_second(self):
        """Find the second element in a two-element array."""
        self.assertEqual(interpolation_search([10, 20], 20), 1)


if __name__ == "__main__":
    unittest.main()
