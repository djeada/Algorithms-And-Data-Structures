"""Jump search algorithm implementation."""

import math
from typing import List, Optional, TypeVar

T = TypeVar("T")


def jump_search(array: List[T], target: T) -> Optional[int]:
    """
    Search for a target value in a sorted array using jump search.

    This algorithm jumps ahead by fixed block sizes to find the block that may
    contain the target, then performs a linear scan inside that block.

    Time complexity: O(√n)
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

    step = int(math.sqrt(n))
    prev = 0

    # Jump ahead until we find a block where target could be
    while array[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return None

    # Linear search within the block
    while array[prev] < target:
        prev += 1
        if prev == min(step, n):
            return None

    if array[prev] == target:
        return prev

    return None
