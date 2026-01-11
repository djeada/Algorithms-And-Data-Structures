/**
 * @brief Counts paths in a grid from top-left to bottom-right.
 * @param n Number of rows in the grid.
 * @param m Number of columns in the grid.
 * @return Number of unique paths moving only right or down.
 */
int gridTravelersBasic(int n, int m);

/**
 * @brief Counts paths in a grid using memoization.
 * @param n Number of rows in the grid.
 * @param m Number of columns in the grid.
 * @return Number of unique paths moving only right or down.
 */
int gridTravelersMemo(int n, int m);

/**
 * @brief Counts paths in a grid using tabulation (bottom-up DP).
 * @param n Number of rows in the grid.
 * @param m Number of columns in the grid.
 * @return Number of unique paths moving only right or down.
 */
int gridTravelersTable(int n, int m);
