#include "climb.h"
#include <functional>
#include <unordered_map>
#include <vector>

int climbBasic(int n) {

  if (n < 0)
    return 0;

  if (n == 0)
    return 1;

  return climbBasic(n - 3) + climbBasic(n - 2) + climbBasic(n - 1);
}

int climbMemo(int n) {

  std::function<int(int, std::unordered_map<int, int> &)> _climbMemo;
  _climbMemo = [&](int n, std::unordered_map<int, int> &memo) -> int {
    if (n < 0)
      return 0;

    if (n == 0)
      return 1;

    if (memo.count(n))
      return memo[n];

    memo[n] = _climbMemo(n - 1, memo) + _climbMemo(n - 2, memo) +
              _climbMemo(n - 3, memo);

    return memo[n];
  };

  std::unordered_map<int, int> memo;
  return _climbMemo(n, memo);
}
