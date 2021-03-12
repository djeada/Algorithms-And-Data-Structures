def grid_traveler(m, n, grid=list(), memo=dict()):

	if len(grid) == 0:
		x = max(m,n)
		grid = [[0] * (x+1) for _ in range(x+1)]

	if m==1 and n==1:
		return 1

	if m==0 or n==0:
		return 0

	key = str(m) + "," + str(n)

	if key in memo:
		return memo[key]

	if grid[m][n] != 0:
		return grid[m][n]
	
	else:
		memo[key] = grid_traveler(m-1,n,grid) + grid_traveler(m,n-1,grid)
		grid[m][n] = memo[key]
		grid[n][m] = memo[key]

	return memo[key]
      
