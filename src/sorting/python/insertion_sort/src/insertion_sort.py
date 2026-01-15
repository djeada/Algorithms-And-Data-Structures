"""Insertion sort algorithm implementation."""

from typing import List, TypeVar

T = TypeVar("T")


def insertion_sort(array: List[T]) -> List[T]:
    """
    Sort an array using the insertion sort algorithm.

    This algorithm builds the sorted array one element at a time by repeatedly
    picking the next element and inserting it into its correct position among
    the previously sorted elements.

    Time complexity: O(n²) worst/average case, O(n) best case (already sorted)
    Space complexity: O(1)

    Args:
        array: The list of comparable elements to sort.

    Returns:
        The same list, sorted in ascending order.
    """
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1

        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1

        array[j + 1] = key

    return array
