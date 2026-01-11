from typing import List


def all_combinations(n: int, k: int) -> List[List[int]]:
    """
    Generate all combinations of k numbers from 0 to n.

    Uses backtracking to find all combinations of size k from the range [0, n].

    Args:
        n: The upper bound of the range (inclusive).
        k: The size of each combination.

    Returns:
        A list of all combinations, where each combination is a list of k integers.
    """

    def _all_combinations(combination: List[int]) -> None:
        if len(combination) == k:
            result.append(combination)
            return

        for i in range(combination[-1] + 1 if combination else 0, n + 1):
            _all_combinations(combination + [i])

    result: List[List[int]] = []
    _all_combinations([])
    return result
