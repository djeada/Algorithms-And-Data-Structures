#include "longest_increasing_subarray.h"
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

int longestIncreasingSubarrayBasic(const std::vector<int> &array) {

  std::function<int(const std::vector<int> &, unsigned int, int)>
      _longestIncreasingSubarrayBasic;
  _longestIncreasingSubarrayBasic = [&](const std::vector<int> &array,
                                        unsigned int i, int prev) -> int {
    if (i == array.size())
      return 0;

    auto excl = _longestIncreasingSubarrayBasic(array, i + 1, prev);

    auto incl = 0;

    if (array[i] > prev)
      incl = _longestIncreasingSubarrayBasic(array, i + 1, array[i]) + 1;

    return std::max(incl, excl);
  };

  return _longestIncreasingSubarrayBasic(array, 0, INT_MIN);
}

int longestIncreasingSubarrayMemo(const std::vector<int> &array) {

  std::function<int(const std::vector<int> &, unsigned int, int,
                    std::unordered_map<std::pair<int, int>, int, hash> &)>
      _longestIncreasingSubarrayMemo;
  _longestIncreasingSubarrayMemo =
      [&](const std::vector<int> &array, unsigned int i, int prev,
          std::unordered_map<std::pair<int, int>, int, hash> &memo) -> int {
    if (i == array.size())
      return 0;

    std::pair<int, int> key(i, prev);

    if (memo.count(key))
      return memo[key];

    auto excl = _longestIncreasingSubarrayMemo(array, i + 1, prev, memo);

    auto incl = 0;

    if (array[i] > prev)
      incl = _longestIncreasingSubarrayMemo(array, i + 1, array[i], memo) + 1;

    memo[key] = std::max(incl, excl);
    return memo[key];
  };

  std::unordered_map<std::pair<int, int>, int, hash> memo;

  return _longestIncreasingSubarrayMemo(array, 0, INT_MIN, memo);
}

int longestIncreasingSubarrayTable(const std::vector<int> &array) {

  std::vector<std::vector<int>> table(array.size(), std::vector<int>());

  table[0].emplace_back(array[0]);

  for (auto i = 1; i < array.size(); i++) {
    for (auto j = 0; j < i; j++) {
      if (array[j] < array[i] && table[j].size() > table[i].size())
        table[i] = std::vector<int>(table[j]);
    }
    table[i].emplace_back(array[i]);
  }

  auto j = 0;
  for (auto i = 0; i < array.size(); i++) {
    if (table[j].size() < table[i].size())
      j = i;
  }

  return table[j].size();
}
