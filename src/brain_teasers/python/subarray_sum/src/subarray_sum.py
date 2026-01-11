"""Calculate the sum of a subarray."""

from __future__ import annotations


def subarray_sum(array: list[int], start: int, end: int) -> int:
    """
    Calculate the sum of elements in a subarray.

    Args:
        array: The input array of integers.
        start: The starting index (inclusive).
        end: The ending index (exclusive).

    Returns:
        The sum of elements from index start to end-1.
    """
    total = 0
    for i in range(start, end):
        total += array[i]
    return total
