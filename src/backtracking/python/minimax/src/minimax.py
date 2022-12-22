def is_player_winning(board, player):
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


def final_score(board):
    # check for a win by player A
    if is_player_winning(board, -1):
        return 1

    # check for a win by player B
    if is_player_winning(board, 1):
        return -1

    # no winner, return 0
    return 0


def game_over(board):
    if is_player_winning(board, -1) or is_player_winning(board, 1):
        return True

    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 0:
                return False

    return True


def minimax(board, player):
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
    return best_score


def find_best_move(board, player):
    # initialize the best score and the best move
    best_score = float("-inf") if player == -1 else float("inf")
    best_move = None

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
