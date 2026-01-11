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
    rows = len(matrix)
    columns = len(matrix[0])
    max_score = matrix_score(matrix)

    for i in range(rows - 1, -1, -1):
        for j in range(columns):
            # Try toggling the current row
            toggle_row(matrix, i)
            score = matrix_score(matrix)
            if score > max_score:
                max_score = score
            else:
                toggle_row(matrix, i)

            # Try toggling the current column
            toggle_column(matrix, j)
            score = matrix_score(matrix)
            if score > max_score:
                max_score = score
            else:
                toggle_column(matrix, j)

    return max_score
