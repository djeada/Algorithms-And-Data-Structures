from typing import List, Optional


def lis_basic(a: List[int], i: int = 0, prev: float = float("-inf")) -> int:
    """
    Find the length of the longest increasing subsequence using basic recursion.

    Args:
        a: List of integers.
        i: Current index (used internally).
        prev: Previous element value (used internally).

    Returns:
        Length of the longest increasing subsequence.
    """
    if i == len(a):
        return 0
    excl = lis_basic(a, i + 1, prev)
    incl = 0
    if a[i] > prev:
        incl = 1 + lis_basic(a, i + 1, a[i])
    return max(incl, excl)


def lis_memo(
    a: List[int], i: int = 0, prev_idx: int = -1, memo: Optional[dict] = None
) -> int:
    """
    Find the length of the longest increasing subsequence using memoization.

    Args:
        a: List of integers.
        i: Current index (used internally).
        prev_idx: Previous element index (used internally), -1 means no previous.
        memo: Optional dictionary for memoization cache.

    Returns:
        Length of the longest increasing subsequence.
    """
    if memo is None:
        memo = {}

    if i == len(a):
        return 0

    key = (i, prev_idx)
    if key in memo:
        return memo[key]

    excl = lis_memo(a, i + 1, prev_idx, memo)
    incl = 0
    prev_val = a[prev_idx] if prev_idx >= 0 else float("-inf")
    if a[i] > prev_val:
        incl = 1 + lis_memo(a, i + 1, i, memo)

    memo[key] = max(incl, excl)
    return memo[key]


def lis_tab(a: List[int]) -> int:
    """
    Find the length of the longest increasing subsequence using tabulation.

    Args:
        a: List of integers.

    Returns:
        Length of the longest increasing subsequence.
    """
    if not a:
        return 0

    table = [1] * len(a)
    for i in range(1, len(a)):
        for j in range(i):
            if a[i] > a[j] and table[i] < table[j] + 1:
                table[i] = table[j] + 1
    return max(table)
