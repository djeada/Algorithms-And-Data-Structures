from typing import List, Tuple, Optional


def is_player_winning(board: List[List[int]], player: int) -> bool:
    """
    Check if the specified player has won the game.

    Args:
        board: The game board (3x3 grid).
        player: The player to check (-1 or 1).

    Returns:
        True if the player has won, False otherwise.
    """
    # check all rows
    for row in range(len(board)):
        if all(board[row][col] == player for col in range(len(board[0]))):
            return True

    # check all columns
    for col in range(len(board[0])):
        if all(board[row][col] == player for row in range(len(board))):
            return True

    # check both diagonals
    return all(board[i][i] == player for i in range(len(board))) or all(
        board[i][len(board) - 1 - i] == player for i in range(len(board))
    )


def final_score(board: List[List[int]]) -> int:
    """
    Calculate the final score of the game.

    Args:
        board: The game board.

    Returns:
        1 if player -1 wins, -1 if player 1 wins, 0 for a draw.
    """
    # check for a win by player A
    if is_player_winning(board, -1):
        return 1

    # check for a win by player B
    if is_player_winning(board, 1):
        return -1

    # no winner, return 0
    return 0


def game_over(board: List[List[int]]) -> bool:
    """
    Check if the game has ended.

    Args:
        board: The game board.

    Returns:
        True if the game is over (someone won or board is full), False otherwise.
    """
    if is_player_winning(board, -1) or is_player_winning(board, 1):
        return True

    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 0:
                return False

    return True


def minimax(board: List[List[int]], player: int) -> int:
    """
    Evaluate the game state using the minimax algorithm.

    Args:
        board: The current game board.
        player: The current player (-1 or 1).

    Returns:
        The best score achievable from this position.
    """
    # base case: the game has ended, return the score
    if game_over(board):
        return final_score(board)

    # initialize the best score
    best_score = float("-inf") if player == 1 else float("inf")

    # try all possible moves
    for row in range(3):
        for col in range(3):
            if board[row][col] == 0:
                # make the move
                board[row][col] = player
                # evaluate the resulting game state
                score = minimax(board, -player)
                # undo the move
                board[row][col] = 0

                # update the best score
                if player == 1:
                    best_score = max(best_score, score)
                else:
                    best_score = min(best_score, score)

    # return the best score
    return int(best_score)


def find_best_move(
    board: List[List[int]], player: int
) -> Optional[Tuple[int, int]]:
    """
    Find the best move for the current player using minimax.

    Args:
        board: The current game board.
        player: The current player (-1 or 1).

    Returns:
        The (row, col) tuple for the best move, or None if no move is available.
    """
    # initialize the best score and the best move
    best_score = float("-inf") if player == -1 else float("inf")
    best_move: Optional[Tuple[int, int]] = None

    # try all possible moves
    for row in range(3):
        for col in range(3):
            if board[row][col] == 0:
                # make the move
                board[row][col] = player
                # evaluate the resulting game state
                score = minimax(board, -player)
                # undo the move
                board[row][col] = 0

                # update the best score and the best move
                if player == -1:
                    if score > best_score:
                        best_score = score
                        best_move = (row, col)
                else:
                    if score < best_score:
                        best_score = score
                        best_move = (row, col)

    # return the best move
    return best_move
