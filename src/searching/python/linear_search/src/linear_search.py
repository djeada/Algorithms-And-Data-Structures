"""Linear search algorithm implementation."""

from typing import List, Optional, TypeVar

T = TypeVar("T")


def linear_search(array: List[T], target: T) -> Optional[int]:
    """
    Search for a target value in an array using linear search.

    This algorithm scans the array from left to right, comparing each element
    with the target until a match is found or the end is reached.

    Time complexity: O(n)
    Space complexity: O(1)

    Args:
        array: The list of elements to search.
        target: The value to search for.

    Returns:
        The index of the target if found, None otherwise.
    """
    for i, value in enumerate(array):
        if value == target:
            return i
    return None
