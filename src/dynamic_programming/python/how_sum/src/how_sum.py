from typing import List, Optional


def how_sum_basic(target: int, numbers: List[int]) -> Optional[List[int]]:
    """
    Find any combination of numbers that add up to target.

    Uses basic recursion without memoization.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        A list of numbers that sum to target, or None if impossible.
    """
    if target == 0:
        return []

    for number in numbers:
        remainder = target - number

        if remainder >= 0:
            combination = how_sum_basic(remainder, numbers)

            if combination is not None:
                return combination + [number]

    return None


def how_sum_memo(
    target: int, numbers: List[int], memo: Optional[dict] = None
) -> Optional[List[int]]:
    """
    Find any combination of numbers that add up to target.

    Uses memoization for efficient computation.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).
        memo: Optional dictionary for memoization cache.

    Returns:
        A list of numbers that sum to target, or None if impossible.
    """
    if memo is None:
        memo = {}

    if target == 0:
        return []

    if target in memo:
        return memo[target]

    for number in numbers:
        remainder = target - number

        if remainder >= 0:
            combination = how_sum_memo(remainder, numbers, memo)

            if combination is not None:
                memo[target] = combination + [number]
                return memo[target]

    memo[target] = None
    return memo[target]


def how_sum_table(target: int, numbers: List[int]) -> Optional[List[int]]:
    """
    Find any combination of numbers that add up to target.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        A list of numbers that sum to target, or None if impossible.
    """
    table: List[Optional[List[int]]] = [None] * (target + 1)
    table[0] = []

    for i in range(target):
        if table[i] is not None:
            for number in numbers:
                if i + number <= target:
                    table[i + number] = table[i] + [number]

    return table[-1]
