"""Quick sort algorithm implementations."""

import random
from typing import List, TypeVar

T = TypeVar("T")


def quick_sort(array: List[T]) -> List[T]:
    """
    Sort an array using quick sort with 2-way partitioning.

    This implementation uses a random pivot selection to avoid worst-case
    performance on already sorted arrays.

    Time complexity: O(n log n) average, O(n²) worst case
    Space complexity: O(log n) average due to recursion

    Args:
        array: The list of comparable elements to sort.

    Returns:
        The same list, sorted in ascending order.
    """

    def partition(arr: List[T], start: int, stop: int) -> int:
        i = start
        j = stop - 2
        pivot = arr[stop - 1]

        while i <= j:
            if arr[i] <= pivot:
                i += 1
            elif arr[j] >= pivot:
                j -= 1
            else:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1

        arr[i], arr[stop - 1] = arr[stop - 1], arr[i]
        return i

    def _quick_sort(arr: List[T], start: int, stop: int) -> None:
        if stop - start < 2:
            return

        pivot_idx = random.randint(start, stop - 1)
        arr[pivot_idx], arr[stop - 1] = arr[stop - 1], arr[pivot_idx]
        pivot_pos = partition(arr, start, stop)
        _quick_sort(arr, start, pivot_pos)
        _quick_sort(arr, pivot_pos + 1, stop)

    _quick_sort(array, 0, len(array))
    return array


def quick_sort_three_way(array: List[T]) -> List[T]:
    """
    Sort an array using quick sort with 3-way partitioning.

    This variant handles duplicate elements more efficiently by partitioning
    the array into three parts: less than pivot, equal to pivot, and greater
    than pivot.

    Time complexity: O(n log n) average, O(n²) worst case
    Space complexity: O(log n) average due to recursion

    Args:
        array: The list of comparable elements to sort.

    Returns:
        The same list, sorted in ascending order.
    """

    def _quick_sort_three_way(arr: List[T], start: int, stop: int) -> None:
        if stop - start < 2:
            return

        pivot = arr[random.randint(start, stop - 1)]
        less_than = equal_to = start
        greater_than = stop

        while equal_to < greater_than:
            if arr[equal_to] < pivot:
                arr[equal_to], arr[less_than] = arr[less_than], arr[equal_to]
                less_than += 1
                equal_to += 1
            elif arr[equal_to] == pivot:
                equal_to += 1
            else:
                greater_than -= 1
                arr[equal_to], arr[greater_than] = arr[greater_than], arr[equal_to]

        _quick_sort_three_way(arr, start, less_than)
        _quick_sort_three_way(arr, greater_than, stop)

    _quick_sort_three_way(array, 0, len(array))
    return array
