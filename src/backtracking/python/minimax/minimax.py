from copy import deepcopy

N = 3
Human = "X"
Computer = "O"
EmptySpot = " "


def drawBoard(board):
    print(board)
    for i in range(N):
        for j in range(N):
            print(" " + board[i][j], end="")

            if j != N - 1:
                print(" |", end="")
        print("")
        if i != N - 1:
            for x in range(N):
                print("--- ", end="")
            print("")


def move(x, y, board):
    board[y][x] = Human
    x, y = computerMove(board)
    print(x, y)
    board[y][x] = Computer


def isGameFinished(board):
    if checkForWin(board) or checkForTie(board):
        return True
    return False


def checkForWin(board):
    # horizontal
    for row in board:
        if row[0] == Computer or row[0] == Human:
            flag = True
            for i in range(1, N):
                if row[i] != row[0]:
                    flag = False
                    break
            if flag:
                return row[0]

    # vertical
    for i in range(N):
        if board[0][i] == Computer or board[0][i] == Human:
            flag = True
            for j in range(1, N):
                if board[j][i] != board[0][i]:
                    flag = False
                    break
            if flag:
                return board[0][i]

    # diagonal
    if board[0][0] == Computer or board[0][0] == Human:
        flag = True
        for i in range(1, N):
            if board[i][i] != board[0][0]:
                flag = False
                break

        if flag:
            return board[0][0]

    if board[0][N - 1] == Computer or board[0][N - 1] == Human:
        flag = True
        for i in range(1, N):
            if board[i][N - i] != board[0][N - 1]:
                flag = False
                break

        if flag:
            return board[0][N - 1]

    return False


def checkForTie(board):
    for row in board:
        for cell in row:
            if cell != Human and cell != Computer:
                return False

    return True


def checkForBloc(board, player, new_pos):
    copyBoard = deepcopy(board)

    copyBoard[new_pos[1]][new_pos[0]] = otherPlayer(player)

    return checkForWin(copyBoard)


def evaluate(board, player, points):
    win = checkForWin(board)

    if win:
        if win == player:
            return points["win"]
        return points["lose"]

    return points["other"]


def isSpotAvailable(x, y, board):
    if board[y][x] != Human and board[y][x] != Computer:
        return True
    return False


def findAllAvailableSpots(board):
    spots = []
    for i in range(N):
        for j in range(N):
            if isSpotAvailable(j, i, board):
                spots.append((j, i))
    return spots


def computerMove(board):

    bestVal = -1000
    bestMove = (-1, -1)
    initial_points = {"win": 200, "block": 195, "lose": -100, "other": 0}

    for spot in findAllAvailableSpots(board):
        x, y = spot

        board[y][x] = Computer

        moveVal = miniMax(board, Computer, initial_points)

        print("x: ", x, " y: ", y, " result: ", moveVal)
        board[y][x] = EmptySpot

        if moveVal > bestVal:
            bestMove = (x, y)
            bestVal = moveVal

    return bestMove


def decreasePoints(points):
    new_points = {}
    for key in points:
        if points[key] > 0:
            new_points[key] = points[key] - 10
        elif points[key] < 0:
            new_points[key] = points[key] + 10
        else:
            new_points[key] = points[key]

    return new_points


def otherPlayer(player):
    if player == Human:
        return Computer
    return Human


def miniMax(board, player, points):

    if isGameFinished(board):
        return evaluate(board, player, points)

    copyBoard = deepcopy(board)
    best = -1000

    for spot in findAllAvailableSpots(copyBoard):
        x, y = spot
        copyBoard[y][x] = player
        if checkForBloc(copyBoard, player, (x, y)):
            return max(best, points["block"])
        best = max(
            best, miniMax(copyBoard, otherPlayer(player), decreasePoints(points))
        )
        copyBoard[y][x] = EmptySpot

    return best


def main():
    board = [[" " for i in range(N)] for j in range(N)]
    drawBoard(board)

    while not isGameFinished(board):
        x = int(input("Give x position: "))
        y = int(input("Give y position: "))
        move(x, y, board)
        drawBoard(board)


main()
