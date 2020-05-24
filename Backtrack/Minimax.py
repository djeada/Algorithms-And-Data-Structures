from copy import deepcopy

N = 3
Human = "X"
Computer = "O"

def drawBoard(board):
	for i in range(N):
		for j in range(N):
			print(board[i][j], end = '')
			
			if j != N - 1:
				print(" | ", end = '')
		
		print('')
		if i != N - 1:
			for x in range(N):
				print('_ ' , end = '')
			print('')
	
def move(x, y, board):
	board[y][x] = Human
	x, y = computerMove(board)
	print(x,y)
	board[y][x] = Computer
	
def isGameFinished(board):
	if checkForWin(board) or checkForTie(board):
		return True
	return False

def checkForWin(board):
	#horizontal
	for row in board:
		if row[0] == Computer or row[0] == Human:
			flag = True
			for i in range(1,N):
				if row[i] != row[0]:
					flag = False
					break
			if flag:
				return row[0]
	
	#vertical
	for i in range(N):
		if board[0][i] == Computer or board[0][i] == Human:
			flag = True
			for j in range(1, N):
				if board[j][i] != board[0][i]:
					flag = False
					break
			if flag:
				return board[0][i]
				
	#diagonal
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

def evaluate(board, player):
	win = checkForWin(board)
		
	if win:
		if win == player:
			return 2
		return -1
				
	if checkForTie(board):
		return 1
			
	return 0

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
	return miniMax(board, N, Computer)

def otherPlayer(player):
	if player == Human:
		return Computer
	return Human

def findTheBest(results):
	best = -2
	position = None
	
	for key in results:
		if(isinstance(results[key], int)):
			if results[key] > best:
				best = results[key]
				position = key

	return position
	
def miniMax(board, depth, player):
	
	if depth == 0 or checkForTie(board):
		return evaluate(board, player)
	
	results = {}
	
	for spot in findAllAvailableSpots(board):
		x, y = spot
		boardCopy =  deepcopy(board)
		boardCopy[y][x] = player
		results[(x,y)] = miniMax(boardCopy, depth - 1, otherPlayer(player))
	
	return findTheBest(results)

def main():
	board = [[' ' for i in range(N)] for j in range(N)]
	drawBoard(board)
	
	while not isGameFinished(board):
		x = int(input("Give x position: "))
		y = int(input("Give y position: "))
		move(x, y, board)
		drawBoard(board)
		
main()

