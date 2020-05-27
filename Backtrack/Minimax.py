from copy import deepcopy

N = 3
Human = "X"
Computer = "O"
EmptySpot = " "

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

    bestVal = -1000; 
	betMove = (-1, -1)
  
   	for spot in findAllAvailableSpots(board):
		x, y = spot

    	board[y][x] = Computer; 

    	moveVal = minimax(board, N, Computer); 

    	board[y][x] = EmptySpot; 

   		if moveVal > bestVal:
        	betMove = (x, y) 
        	bestVal = moveVal
 
	return betMove

def otherPlayer(player):
	if player == Human:
		return Computer
	return Human

def miniMax(board, depth, player):
	
	if depth == 0 or checkForTie(board):
		return evaluate(board, player)
	
	copyBoard = deepcopy(board)
	best = -1000
	
	for spot in findAllAvailableSpots(copyBoard):
		x, y = spot
		copyBoard[y][x] = Computer; 
    	best = max(best, minimax(board, N, otherPlayer(player)); 

    return best

def main():
	board = [[' ' for i in range(N)] for j in range(N)]
	drawBoard(board)
	
	while not isGameFinished(board):
		x = int(input("Give x position: "))
		y = int(input("Give y position: "))
		move(x, y, board)
		drawBoard(board)
		
main()

