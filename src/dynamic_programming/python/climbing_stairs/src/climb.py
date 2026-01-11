from typing import Optional


def count_ways_to_climb_basic(num_steps: int) -> int:
    """
    Count the number of ways to climb stairs taking 1, 2, or 3 steps at a time.

    Uses basic recursion without memoization.

    Args:
        num_steps: Total number of steps to climb.

    Returns:
        Number of distinct ways to reach the top.
    """
    if num_steps < 0:
        return 0

    if num_steps == 0:
        return 1

    return (
        count_ways_to_climb_basic(num_steps - 3)
        + count_ways_to_climb_basic(num_steps - 2)
        + count_ways_to_climb_basic(num_steps - 1)
    )


def count_ways_to_climb_memo(
    num_steps: int, ways_to_climb: Optional[dict] = None
) -> int:
    """
    Count the number of ways to climb stairs taking 1, 2, or 3 steps at a time.

    Uses memoization for efficient computation.

    Args:
        num_steps: Total number of steps to climb.
        ways_to_climb: Optional dictionary for memoization cache.

    Returns:
        Number of distinct ways to reach the top.
    """
    if ways_to_climb is None:
        ways_to_climb = {}

    if num_steps < 0:
        return 0

    if num_steps == 0:
        return 1

    if num_steps in ways_to_climb:
        return ways_to_climb[num_steps]

    ways_to_climb[num_steps] = (
        count_ways_to_climb_memo(num_steps - 1, ways_to_climb)
        + count_ways_to_climb_memo(num_steps - 2, ways_to_climb)
        + count_ways_to_climb_memo(num_steps - 3, ways_to_climb)
    )
    return ways_to_climb[num_steps]


def count_ways_to_climb_table(n: int) -> int:
    """
    Count the number of ways to climb stairs taking 1, 2, or 3 steps at a time.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        n: Total number of steps to climb.

    Returns:
        Number of distinct ways to reach the top.
    """
    if n < 0:
        return 0

    if n == 0:
        return 1

    table = [0] * (n + 1)
    table[0] = 1

    for i in range(1, n + 1):
        table[i] = table[i - 1]
        if i >= 2:
            table[i] += table[i - 2]
        if i >= 3:
            table[i] += table[i - 3]

    return table[n]
