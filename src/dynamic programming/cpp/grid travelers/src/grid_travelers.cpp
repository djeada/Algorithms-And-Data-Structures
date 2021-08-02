#include "grid_travelers.h"
#include <vector>

int gridTravelersBasic(int n, int m) {

  if (n == 0 || m == 0)
    return 0;

  if (n < 2 && m < 2)
    return std::min(m, n);

  return gridTravelersBasic(n - 1, m) + gridTravelersBasic(n, m - 1);
}

int gridTravelersMemo(int n, int m,
                      std::unordered_map<std::pair<int, int>, int, hash> memo) {

  if (n == 0 || m == 0)
    return 0;

  if (n < 2 && m < 2)
    return std::min(m, n);

  std::pair<int, int> key(n, m);

  if (memo.count(key))
    return memo[key];

  memo[key] =
      gridTravelersMemo(n - 1, m, memo) + gridTravelersMemo(n, m - 1, memo);

  return memo[key];
}

int gridTravelersTable(int n, int m) {

  std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1));
  table[1][1] = 1;

  for (int i = 1; i <= m; i++) {

    for (int j = 1; j <= n; j++) {
      auto cur = table[i][j];

      if (i < m)
        table[i + 1][j] += cur;

      if (j < n)
        table[i][j + 1] += cur;
    }
  }

  return table[m][n];
}
