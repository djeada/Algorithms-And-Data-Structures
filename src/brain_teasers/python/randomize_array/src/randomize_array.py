"""Randomize an array ensuring no element stays in its original position."""

from __future__ import annotations

import random


def randomize_array(array: list[int]) -> list[int]:
    """
    Randomize an array of integers.

    Ensures that no element remains in its original position (when possible).

    Args:
        array: List of integers to randomize.

    Returns:
        A new randomized list of integers.
    """
    n = len(array)
    # Check if all elements are identical or array is of length 1
    if n == 1 or all(x == array[0] for x in array):
        return array

    new_array = array.copy()
    for i in range(n):
        # Select a random index that's not equal to the current one
        swap_candidates = [x for x in range(n) if x != i and new_array[x] != array[i]]
        if swap_candidates:
            swap_with = random.choice(swap_candidates)
            new_array[i], new_array[swap_with] = new_array[swap_with], new_array[i]
    return new_array
