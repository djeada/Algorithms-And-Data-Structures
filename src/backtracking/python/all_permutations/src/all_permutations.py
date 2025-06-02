from typing import Any, List
import itertools


def all_permutations_itertools(input_list: List[Any]) -> List[List[Any]]:
    """
    Return all permutations of input_list using itertools.permutations,
    converted into lists.

    Time complexity:
        O(n! * n) where n = len(input_list).  itertools.permutations generates each
        of the n! permutations in O(1) amortized time, but converting each tuple to a list
        costs O(n), so the overall complexity is O(n! * n).
    """
    return [list(p) for p in itertools.permutations(input_list)]


def all_permutations_backtracking(input_list: List[Any]) -> List[List[Any]]:
    """
    Return all permutations of input_list using in-place backtracking.

    Time complexity:
        O(n! * n) where n = len(input_list).
        We generate n! permutations, and each time we reach a full permutation,
        we append a copy of length-n list (O(n) copy cost). Swapping operations
        also contribute lower-order overhead but do not change the factorial growth.
    """

    def _backtrack(start_index: int):
        # If we have fixed positions up to the end, record a copy of the current list
        if start_index == n:
            result.append(input_list.copy())
            return

        for i in range(start_index, n):
            # Swap element i into the 'start_index' position
            input_list[start_index], input_list[i] = input_list[i], input_list[start_index]
            _backtrack(start_index + 1)
            # Swap back to restore original order before the next iteration
            input_list[start_index], input_list[i] = input_list[i], input_list[start_index]

    n = len(input_list)
    result: List[List[Any]] = []
    _backtrack(0)
    return result
