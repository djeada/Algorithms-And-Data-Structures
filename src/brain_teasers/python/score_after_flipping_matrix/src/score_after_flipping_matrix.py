"""Maximize binary matrix score by flipping rows and columns."""

from __future__ import annotations


def matrix_score(matrix: list[list[int]]) -> int:
    """
    Calculate the score of a binary matrix.

    Each row is interpreted as a binary number, and the score is their sum.

    Args:
        matrix: A 2D list of 0s and 1s.

    Returns:
        The sum of all rows interpreted as binary numbers.
    """
    rows = len(matrix)
    columns = len(matrix[0])
    score = 0

    for j in range(columns):
        ones = sum(1 for i in range(rows) if matrix[i][j] == 1)
        score += max(ones, rows - ones) * (2 ** (columns - j - 1))

    return score


def toggle_row(matrix: list[list[int]], row: int) -> None:
    """
    Toggle all values in a row (0 becomes 1, 1 becomes 0).

    Args:
        matrix: The matrix to modify.
        row: The row index to toggle.
    """
    columns = len(matrix[0])
    for j in range(columns):
        matrix[row][j] = 1 - matrix[row][j]


def toggle_column(matrix: list[list[int]], column: int) -> None:
    """
    Toggle all values in a column (0 becomes 1, 1 becomes 0).

    Args:
        matrix: The matrix to modify.
        column: The column index to toggle.
    """
    rows = len(matrix)
    for i in range(rows):
        matrix[i][column] = 1 - matrix[i][column]


def score_after_flipping_matrix(matrix: list[list[int]]) -> int:
    """
    Find the maximum score achievable by flipping rows and columns.

    Args:
        matrix: A 2D list of 0s and 1s.

    Returns:
        The maximum possible score after any number of flips.
    """
    if not matrix or not matrix[0]:
        return 0

    rows = len(matrix)
    columns = len(matrix[0])
    score = 0

    # Greedy: flip every row so its leading bit is 1, then flip each column
    # independently if that gives more ones. Works on a virtual view so the
    # input matrix is not mutated.
    for j in range(columns):
        ones = sum(1 for i in range(rows) if matrix[i][j] == matrix[i][0])
        score += max(ones, rows - ones) * (1 << (columns - j - 1))

    return score
