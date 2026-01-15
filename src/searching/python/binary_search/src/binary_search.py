"""Binary search algorithm implementation."""

from typing import List, Optional, TypeVar

T = TypeVar("T")


def binary_search(array: List[T], target: T) -> Optional[int]:
    """
    Search for a target value in a sorted array using binary search.

    This algorithm repeatedly halves the search interval by comparing the
    target to the middle element until found or the interval is empty.

    Time complexity: O(log n)
    Space complexity: O(1)

    Args:
        array: The sorted list of comparable elements to search.
        target: The value to search for.

    Returns:
        The index of the target if found, None otherwise.

    Note:
        The array must be sorted in ascending order for correct results.
    """
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return None
