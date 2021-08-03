#include "climb.h"
#include <vector>

int climbBasic(int n) {

  if (n < 0)
    return 0;

  if (n == 0)
    return 1;

  return climbBasic(n - 3) + climbBasic(n - 2) + climbBasic(n - 1);
}

int climbMemo(int n, std::unordered_map<int, int> memo) {

  if (n < 0)
    return 0;

  if (n == 0)
    return 1;

  if (memo.count(n))
    return memo[n];

  memo[n] = climbMemo(n - 1, memo) + climbMemo(n - 2, memo) + climbMemo(n - 3, memo);

  return memo[n];
}
