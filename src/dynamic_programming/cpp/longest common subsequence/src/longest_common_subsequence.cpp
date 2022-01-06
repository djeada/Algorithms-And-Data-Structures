#include "longest_common_subsequence.h"
#include <climits>
#include <functional>
#include <unordered_map>
#include <utility>

struct hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    return h1 ^ h2;
  }
};

int longestCommonSubsequenceBasic(const std::vector<int> &arrayA,
                                  const std::vector<int> &arrayB) {

  std::function<int(const std::vector<int> &, const std::vector<int> &,
                    unsigned int, unsigned int)>
      _longestCommonSubsequenceBasic;
  _longestCommonSubsequenceBasic = [&](const std::vector<int> &arrayA,
                                       const std::vector<int> &arrayB,
                                       unsigned int m, unsigned int n) -> int {
    if (m == -1 || n == -1)
      return 0;

    if (arrayA[m] == arrayB[n])
      return _longestCommonSubsequenceBasic(arrayA, arrayB, m - 1, n - 1) + 1;

    return std::max(_longestCommonSubsequenceBasic(arrayA, arrayB, m, n - 1),
                    _longestCommonSubsequenceBasic(arrayA, arrayB, m - 1, n));
  };

  return _longestCommonSubsequenceBasic(arrayA, arrayB, arrayA.size() - 1,
                                        arrayB.size() - 1);
}

int longestCommonSubsequenceMemo(const std::vector<int> &arrayA,
                                 const std::vector<int> &arrayB) {

  std::function<int(const std::vector<int> &, const std::vector<int> &,
                    unsigned int, unsigned int,
                    std::unordered_map<std::pair<int, int>, int, hash> &)>
      _longestCommonSubsequenceMemo;
  _longestCommonSubsequenceMemo =
      [&](const std::vector<int> &arrayA, const std::vector<int> &arrayB,
          unsigned int m, unsigned int n,
          std::unordered_map<std::pair<int, int>, int, hash> &memo) -> int {
    if (m == -1 || n == -1)
      return 0;

    if (arrayA[m] == arrayB[n])
      return _longestCommonSubsequenceMemo(arrayA, arrayB, m - 1, n - 1, memo) +
             1;

    std::pair<int, int> key(n, m);
    memo[key] =
        std::max(_longestCommonSubsequenceMemo(arrayA, arrayB, m, n - 1, memo),
                 _longestCommonSubsequenceMemo(arrayA, arrayB, m - 1, n, memo));

    return memo[key];
  };

  std::unordered_map<std::pair<int, int>, int, hash> memo;

  return _longestCommonSubsequenceMemo(arrayA, arrayB, arrayA.size() - 1,
                                       arrayB.size() - 1, memo);
}

int longestCommonSubsequenceTable(const std::vector<int> &arrayA,
                                  const std::vector<int> &arrayB) {

  auto m = arrayA.size();
  auto n = arrayB.size();
  std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1));

  for (auto i = 1; i < m + 1; i++) {
    for (auto j = 1; j < n + 1; j++) {
      if (arrayA[i - 1] == arrayB[j - 1])
        table[i][j] = table[i - 1][j - 1] + 1;
      else
        table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
    }
  }

  return table[m][n];
}
