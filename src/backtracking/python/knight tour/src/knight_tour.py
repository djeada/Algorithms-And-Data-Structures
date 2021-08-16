"""
Find the solution to the knight tour problem on an n-dimensional board.
Determine if a knight piece can travel all of the available chess squares 
from the chessboard's starting position. If the tour cannot be done for 
the provided size, return an empty list.
"""

# Time complexity: O(8^(n^2))
def knight_tour(n):
    def _neighbors(position, n):

        x, y = position
        result = []

        if y + 1 < n and x + 2 < n:
            result.append((x + 2, y + 1))

        if 0 <= y - 1 and x + 2 < n:
            result.append((x + 2, y - 1))

        if y + 1 < n and 0 <= x - 2:
            result.append((x - 2, y + 1))

        if 0 <= y - 1 and 0 <= x - 2:
            result.append((x - 2, y - 1))

        if y + 2 < n and x + 1 < n:
            result.append((x + 1, y + 2))

        if 0 <= y - 2 and x + 1 < n:
            result.append((x + 1, y - 2))

        if y + 2 < n and 0 <= x - 1:
            result.append((x - 1, y + 2))

        if 0 <= y - 2 and 0 <= x - 1:
            result.append((x - 1, y - 2))

        return result

    def _knight_tour(board, pos, curr):

        # check to see if each square on the board has already been visited.
        if not any(elem == 0 for row in board for elem in row):
            return True

        for x, y in _neighbors(pos, len(board)):

            if board[y][x] == 0:
                board[y][x] = curr + 1
                if _knight_tour(board, (x, y), curr + 1):
                    return True
                board[y][x] = 0

        return False

    board = [[0 for i in range(n)] for j in range(n)]

    for i in range(n):
        for j in range(n):
            board[i][j] = 1
            if _knight_tour(board, (j, i), 1):
                return board
            board[i][j] = 0

    return list()
