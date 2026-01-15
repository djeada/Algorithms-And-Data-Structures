"""Exponential search algorithm implementation."""

from typing import List, Optional, TypeVar

T = TypeVar("T")


def exponential_search(array: List[T], target: T) -> Optional[int]:
    """
    Search for a target value in a sorted array using exponential search.

    This algorithm grows the right boundary exponentially (1, 2, 4, 8, ...) to
    find a containing range, then finishes with binary search in that range.
    Useful when target is likely near the beginning or the array is unbounded.

    Time complexity: O(log p) where p is the position of the target
    Space complexity: O(1)

    Args:
        array: The sorted list of comparable elements to search.
        target: The value to search for.

    Returns:
        The index of the target if found, None otherwise.

    Note:
        The array must be sorted in ascending order for correct results.
    """
    n = len(array)
    if n == 0:
        return None

    # Check if target is at the first position
    if array[0] == target:
        return 0

    # Find range for binary search by repeated doubling
    bound = 1
    while bound < n and array[bound] <= target:
        bound *= 2

    # Binary search in the found range
    low = bound // 2
    high = min(bound, n - 1)

    while low <= high:
        mid = (low + high) // 2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return None
