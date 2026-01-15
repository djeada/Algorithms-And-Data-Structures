"""Interpolation search algorithm implementation."""

from typing import List, Optional


def interpolation_search(array: List[int], target: int) -> Optional[int]:
    """
    Search for a target value in a sorted array using interpolation search.

    This algorithm estimates the likely position of the target using the values
    themselves, then probes there and narrows the search based on comparison.
    Works best on uniformly distributed sorted data.

    Time complexity: O(log log n) average for uniform data, O(n) worst case
    Space complexity: O(1)

    Args:
        array: The sorted list of integers to search.
        target: The value to search for.

    Returns:
        The index of the target if found, None otherwise.

    Note:
        The array must be sorted in ascending order for correct results.
        Works best when values are uniformly distributed.
    """
    low = 0
    high = len(array) - 1

    while low <= high and target >= array[low] and target <= array[high]:
        # Handle case where all elements are the same
        if array[high] == array[low]:
            if array[low] == target:
                return low
            return None

        # Estimate position using interpolation formula
        pos = low + ((target - array[low]) * (high - low)) // (array[high] - array[low])

        # Ensure pos is within bounds
        pos = max(low, min(pos, high))

        if array[pos] == target:
            return pos
        elif array[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return None
