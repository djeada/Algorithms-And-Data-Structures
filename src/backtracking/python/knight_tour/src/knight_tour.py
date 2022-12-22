def transform_tour(tour, n):
    # create a map from squares to move numbers
    move_map = {square: i + 1 for i, square in enumerate(tour)}

    # create a list of moves by looking up the move numbers in the map
    moves = [[move_map[(row, col)] for col in range(n)] for row in range(n)]
    return moves


def find_tours(board, row, col, move_count, tour, tours):
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


def knight_tour(n):
    # initialize the board and the tours list
    board = [[None] * n for _ in range(n)]
    board[0][0] = 0
    tour = [(0, 0)]
    tours = []
    find_tours(board, 0, 0, 1, tour, tours)
    tours = [transform_tour(tour, n) for tour in tours]
    return tours
