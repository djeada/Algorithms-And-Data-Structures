"""Heap sort algorithm implementation."""

from typing import List, TypeVar

T = TypeVar("T")


def heap_sort(array: List[T]) -> List[T]:
    """
    Sort an array using the heap sort algorithm.

    This implementation builds a min-heap and repeatedly extracts the minimum
    element to produce a sorted array in-place.

    Time complexity: O(n log n)
    Space complexity: O(log n) due to recursion stack

    Args:
        array: The list of comparable elements to sort.

    Returns:
        The same list, sorted in ascending order.
    """

    def parent(i: int) -> int:
        return i >> 1

    def left_child(i: int) -> int:
        return i << 1

    def right_child(i: int) -> int:
        return (i << 1) + 1

    def heapify(arr: List[T], curr: int, offset: int) -> None:
        if curr + offset > len(arr):
            return

        heapify(arr, left_child(curr), offset)
        heapify(arr, right_child(curr), offset)

        if curr > 1 and arr[curr + offset - 1] < arr[parent(curr) + offset - 1]:
            arr[curr + offset - 1], arr[parent(curr) + offset - 1] = (
                arr[parent(curr) + offset - 1],
                arr[curr + offset - 1],
            )

    for i in range(len(array)):
        heapify(array, 1, i)

    return array
