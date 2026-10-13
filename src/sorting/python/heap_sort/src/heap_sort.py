"""Heap sort algorithm implementation."""

from typing import List, TypeVar

T = TypeVar("T")


def heap_sort(array: List[T]) -> List[T]:
    """
    Sort a list in place in ascending order using heap sort.

    Builds a max-heap in place, then repeatedly swaps the maximum to the end
    of the shrinking heap and sifts the new root down.

    Time complexity: O(n log n)
    Space complexity: O(1)

    Args:
        array: The list of comparable elements to sort.

    Returns:
        The same list, sorted in ascending order.
    """

    def sift_down(root: int, size: int) -> None:
        while True:
            largest = root
            left = 2 * root + 1
            right = left + 1

            if left < size and array[largest] < array[left]:
                largest = left
            if right < size and array[largest] < array[right]:
                largest = right
            if largest == root:
                return
            array[root], array[largest] = array[largest], array[root]
            root = largest

    n = len(array)

    # Build a max-heap in O(n).
    for i in range(n // 2 - 1, -1, -1):
        sift_down(i, n)

    # Move the maximum to the end and restore the heap on the remainder.
    for end in range(n - 1, 0, -1):
        array[0], array[end] = array[end], array[0]
        sift_down(0, end)

    return array
