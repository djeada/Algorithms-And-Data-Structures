from typing import Optional


def fib_basic(n: int) -> int:
    """
    Compute the nth Fibonacci number using basic recursion.

    Args:
        n: The index of the Fibonacci number to compute (0-indexed).

    Returns:
        The nth Fibonacci number.
    """
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib_basic(n - 2) + fib_basic(n - 1)


def fib_memo(n: int, memo: Optional[dict] = None) -> int:
    """
    Compute the nth Fibonacci number using memoization.

    Args:
        n: The index of the Fibonacci number to compute (0-indexed).
        memo: Optional dictionary for memoization cache.

    Returns:
        The nth Fibonacci number.
    """
    if memo is None:
        memo = {}

    if n < 1:
        return 0
    if n <= 2:
        return 1

    if n in memo:
        return memo[n]

    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo)
    return memo[n]


def fib_tab(n: int) -> int:
    """
    Compute the nth Fibonacci number using tabulation (bottom-up DP).

    Args:
        n: The index of the Fibonacci number to compute (0-indexed).

    Returns:
        The nth Fibonacci number.
    """
    if n < 1:
        return 0

    if n == 1:
        return 1

    table = [0] * (n + 1)
    table[1] = 1

    for i in range(2, n + 1):
        table[i] = table[i - 1] + table[i - 2]

    return table[n]
