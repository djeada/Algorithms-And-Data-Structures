#include "grid_travelers.h"
#include <functional>
#include <unordered_map>
#include <utility>
#include <vector>

struct hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    return h1 ^ h2;
  }
};

int gridTravelersBasic(int n, int m) {

  if (n == 0 || m == 0)
    return 0;

  if (n < 2 && m < 2)
    return std::min(m, n);

  return gridTravelersBasic(n - 1, m) + gridTravelersBasic(n, m - 1);
}

int gridTravelersMemo(int n, int m) {

  std::function<int(int, int,
                    std::unordered_map<std::pair<int, int>, int, hash> &)>
      _gridTravelersMemo;
  _gridTravelersMemo =
      [&](int n, int m,
          std::unordered_map<std::pair<int, int>, int, hash> &memo) -> int {
    if (n == 0 || m == 0)
      return 0;

    if (n < 2 && m < 2)
      return std::min(m, n);

    std::pair<int, int> key(n, m);

    if (memo.count(key))
      return memo[key];

    memo[key] =
        _gridTravelersMemo(n - 1, m, memo) + _gridTravelersMemo(n, m - 1, memo);

    return memo[key];
  };

  std::unordered_map<std::pair<int, int>, int, hash> memo;
  return _gridTravelersMemo(n, m, memo);
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
