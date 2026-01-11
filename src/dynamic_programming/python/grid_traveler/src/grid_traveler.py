from typing import Optional


def grid_traveller_basic(num_rows: int, num_columns: int) -> int:
    """
    Count paths from top-left to bottom-right in a grid moving only right or down.

    Uses basic recursion without memoization.

    Args:
        num_rows: Number of rows in the grid.
        num_columns: Number of columns in the grid.

    Returns:
        Number of unique paths from top-left to bottom-right.
    """
    if not num_rows or not num_columns:
        return 0

    if num_rows < 2 and num_columns < 2:
        return min(num_rows, num_columns)

    return grid_traveller_basic(num_rows - 1, num_columns) + grid_traveller_basic(
        num_rows, num_columns - 1
    )


def grid_traveller_memo(
    num_rows: int, num_columns: int, memo: Optional[dict] = None
) -> int:
    """
    Count paths from top-left to bottom-right in a grid moving only right or down.

    Uses memoization for efficient computation.

    Args:
        num_rows: Number of rows in the grid.
        num_columns: Number of columns in the grid.
        memo: Optional dictionary for memoization cache.

    Returns:
        Number of unique paths from top-left to bottom-right.
    """
    if memo is None:
        memo = {}

    if not num_rows or not num_columns:
        return 0

    if num_rows < 2 and num_columns < 2:
        return min(num_rows, num_columns)

    key = (num_rows, num_columns)
    if key in memo:
        return memo[key]

    memo[key] = grid_traveller_memo(
        num_rows - 1, num_columns, memo
    ) + grid_traveller_memo(num_rows, num_columns - 1, memo)
    return memo[key]


def grid_traveller_table(n: int, m: int) -> int:
    """
    Count paths from top-left to bottom-right in a grid moving only right or down.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        n: Number of rows in the grid.
        m: Number of columns in the grid.

    Returns:
        Number of unique paths from top-left to bottom-right.
    """
    if n < 1 or m < 1:
        return 0

    if n == 1 and m == 1:
        return 1

    table = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    table[1][1] = 1

    for i in range(n + 1):
        for j in range(m + 1):
            if i == 1 and j == 1:
                continue
            table[i][j] = table[i - 1][j] + table[i][j - 1]

    return table[n][m]
