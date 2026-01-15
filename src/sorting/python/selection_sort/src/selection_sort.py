"""Selection sort algorithm implementation."""

from typing import List, TypeVar

T = TypeVar("T")


def selection_sort(array: List[T]) -> List[T]:
    """
    Sort an array using the selection sort algorithm.

    This algorithm divides the input into a sorted and unsorted region,
    repeatedly selecting the smallest element from the unsorted region
    and moving it to the end of the sorted region.

    Time complexity: O(n²)
    Space complexity: O(1)

    Args:
        array: The list of comparable elements to sort.

    Returns:
        The same list, sorted in ascending order.
    """
    for i in range(len(array)):
        min_idx = i

        for j in range(i + 1, len(array)):
            if array[j] < array[min_idx]:
                min_idx = j

        array[i], array[min_idx] = array[min_idx], array[i]

    return array
