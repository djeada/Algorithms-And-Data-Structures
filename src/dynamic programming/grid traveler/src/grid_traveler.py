def grid_traveler(m, n, grid=list()):

	if len(grid) == 0:
		x = max(m,n)
		grid = [[0] * (x+1) for _ in range(x+1)]

	if m==1 and n==1:
		return 1

	if m==0 or n==0:
		return 0

	if grid[m][n] != 0:
		return grid[m][n]
	
	else:
		number_of_steps = grid_traveler(m-1,n,grid) + grid_traveler(m,n-1,grid)
		grid[m][n] = number_of_steps
		grid[n][m] = number_of_steps

	return number_of_steps
      
