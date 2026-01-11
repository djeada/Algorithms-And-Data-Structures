from typing import List, Tuple, Optional, Dict


def transform_tour(tour: List[Tuple[int, int]], n: int) -> List[List[int]]:
    """
    Transform a list of tour positions into a grid of move numbers.

    Args:
        tour: List of (row, col) positions representing the knight's path.
        n: Size of the board.

    Returns:
        An n x n grid where each cell contains the move number (1-indexed).
    """
    # create a map from squares to move numbers
    move_map: Dict[Tuple[int, int], int] = {
        square: i + 1 for i, square in enumerate(tour)
    }

    # create a list of moves by looking up the move numbers in the map
    moves = [[move_map[(row, col)] for col in range(n)] for row in range(n)]
    return moves


def find_tours(
    board: List[List[Optional[int]]],
    row: int,
    col: int,
    move_count: int,
    tour: List[Tuple[int, int]],
    tours: List[List[Tuple[int, int]]],
) -> None:
    """
    Recursively find all knight's tour solutions using backtracking.

    Args:
        board: The current state of the board.
        row: Current row position.
        col: Current column position.
        move_count: Number of moves made so far.
        tour: Current tour path.
        tours: List to store all complete tours.
    """
    # base case: all squares on the board have been visited
    if move_count == len(board) * len(board[0]):
        tours.append(tour.copy())
        return

    # try all possible moves from the current position
    for row_offset, col_offset in [
        (2, 1),
        (2, -1),
        (-2, 1),
        (-2, -1),
        (1, 2),
        (1, -2),
        (-1, 2),
        (-1, -2),
    ]:
        new_row, new_col = row + row_offset, col + col_offset
        if (
            0 <= new_row < len(board)
            and 0 <= new_col < len(board[0])
            and board[new_row][new_col] is None
        ):
            board[new_row][new_col] = move_count
            tour.append((new_row, new_col))
            find_tours(board, new_row, new_col, move_count + 1, tour, tours)
            tour.pop()
            board[new_row][new_col] = None


def knight_tour(n: int) -> List[List[List[int]]]:
    """
    Find all knight's tour solutions for an n x n board.

    A knight's tour is a sequence of moves where the knight visits
    every square exactly once.

    Args:
        n: Size of the board.

    Returns:
        List of all valid tours, where each tour is an n x n grid
        showing the order of moves.
    """
    # initialize the board and the tours list
    board: List[List[Optional[int]]] = [[None] * n for _ in range(n)]
    board[0][0] = 0
    tour: List[Tuple[int, int]] = [(0, 0)]
    tours: List[List[Tuple[int, int]]] = []
    find_tours(board, 0, 0, 1, tour, tours)
    tours_result = [transform_tour(tour, n) for tour in tours]
    return tours_result
