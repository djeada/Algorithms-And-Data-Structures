from typing import List, Optional


def find_shortest_combination_sum_basic(
    target: int, numbers: List[int]
) -> Optional[List[int]]:
    """
    Find the shortest combination of numbers that add up to target.

    Uses basic recursion without memoization.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        Shortest list of numbers that sum to target, or None if impossible.
    """

    def recurse(target: int) -> float:
        if target < 0:
            return float("inf")

        if target == 0:
            return 0

        min_length = float("inf")
        for number in numbers:
            combination_length = recurse(target - number) + 1
            min_length = min(min_length, combination_length)

        return min_length

    min_length = recurse(target)
    if min_length == float("inf"):
        return None

    combination: List[int] = []
    while target > 0:
        for number in numbers:
            if recurse(target - number) == min_length - 1:
                combination.append(number)
                target -= number
                min_length -= 1
                break

    return combination


def find_shortest_combination_sum_memo(
    target: int, numbers: List[int]
) -> Optional[List[int]]:
    """
    Find the shortest combination of numbers that add up to target.

    Uses memoization for efficient computation.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        Shortest list of numbers that sum to target, or None if impossible.
    """

    def recurse(target: int, memo: dict) -> float:
        if target in memo:
            return memo[target]

        if target < 0:
            return float("inf")

        if target == 0:
            return 0

        min_length = float("inf")
        for number in numbers:
            combination_length = recurse(target - number, memo) + 1
            min_length = min(min_length, combination_length)

        memo[target] = min_length
        return min_length

    memo: dict = {}
    min_length = recurse(target, memo)
    if min_length == float("inf"):
        return None

    combination: List[int] = []
    while target > 0:
        for number in numbers:
            if recurse(target - number, memo) == min_length - 1:
                combination.append(number)
                target -= number
                min_length -= 1
                break

    return combination


def find_shortest_combination_sum_table(
    target: int, numbers: List[int]
) -> Optional[List[int]]:
    """
    Find the shortest combination of numbers that add up to target.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        Shortest list of numbers that sum to target, or None if impossible.
    """
    if target < 0:
        return None

    table: List[Optional[List[int]]] = [None] * (target + 1)
    table[0] = []

    for i in range(target + 1):
        if table[i] is not None:
            for number in numbers:
                if i + number <= target:
                    if table[i + number] is None or len(table[i]) < len(
                        table[i + number]
                    ):
                        table[i + number] = table[i] + [number]

    return table[-1]
