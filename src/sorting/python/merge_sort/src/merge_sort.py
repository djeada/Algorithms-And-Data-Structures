"""Merge sort algorithm implementations."""

from typing import List, TypeVar

T = TypeVar("T")


def merge_sort(array: List[T]) -> List[T]:
    """
    Sort an array using the merge sort algorithm with index-based merging.

    This implementation uses indices instead of slicing in the merge step,
    resulting in O(n) merge operations and O(n log n) overall complexity.

    Time complexity: O(n log n)
    Space complexity: O(n)

    Args:
        array: The list of comparable elements to sort.

    Returns:
        A new sorted list containing the same elements.
    """

    def merge(array_a: List[T], array_b: List[T]) -> List[T]:
        result: List[T] = []
        index_a = index_b = 0

        while len(array_a) + len(array_b) > index_a + index_b:
            if index_b >= len(array_b) or (
                index_a < len(array_a) and array_a[index_a] < array_b[index_b]
            ):
                result.append(array_a[index_a])
                index_a += 1
            else:
                result.append(array_b[index_b])
                index_b += 1

        return result

    n = len(array)

    if n < 2:
        return array

    return merge(merge_sort(array[: n // 2]), merge_sort(array[n // 2 :]))
