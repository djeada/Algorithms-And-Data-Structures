from typing import List, Optional


def can_sum_basic(target: int, numbers: List[int]) -> bool:
    """
    Determine if it's possible to generate target sum using numbers from the list.

    Uses basic recursion without memoization.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        True if target sum is achievable, False otherwise.
    """
    if target == 0:
        return True

    if target < 0:
        return False

    return any(can_sum_basic(target - i, numbers) for i in numbers)


def can_sum_memo(
    target: int, numbers: List[int], memo: Optional[dict] = None
) -> bool:
    """
    Determine if it's possible to generate target sum using numbers from the list.

    Uses memoization for efficient computation.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).
        memo: Optional dictionary for memoization cache.

    Returns:
        True if target sum is achievable, False otherwise.
    """
    if memo is None:
        memo = {}

    if target == 0:
        return True

    if target < 0:
        return False

    if target in memo:
        return memo[target]

    can_sum = any(can_sum_memo(target - i, numbers, memo) for i in numbers)
    memo[target] = can_sum

    return can_sum


def can_sum_table(target: int, numbers: List[int]) -> bool:
    """
    Determine if it's possible to generate target sum using numbers from the list.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        target: The target sum to achieve.
        numbers: List of numbers that can be used (can be reused).

    Returns:
        True if target sum is achievable, False otherwise.
    """
    table = [False] * (target + 1)
    table[0] = True

    for i in range(target):
        if table[i]:
            for number in numbers:
                if i + number <= target:
                    table[i + number] = True

    return table[-1]
