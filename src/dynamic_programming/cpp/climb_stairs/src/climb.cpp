#include "climb.h"
#include <functional>
#include <vector>

int countWaysToClimbBasic(int numSteps) {
  if (numSteps < 0)
    return 0;

  if (numSteps == 0)
    return 1;

  return countWaysToClimbBasic(numSteps - 1) +
         countWaysToClimbBasic(numSteps - 2) +
         countWaysToClimbBasic(numSteps - 3);
}

int countWaysToClimbMemo(int n) {
  std::unordered_map<int, int> memo;
  std::function<int(int)> countWaysToClimbMemoHelper = [&](int n) {
    if (n < 0)
      return 0;

    if (n == 0)
      return 1;

    if (memo.find(n) == memo.end())
      memo[n] = countWaysToClimbMemoHelper(n - 1) +
                countWaysToClimbMemoHelper(n - 2) +
                countWaysToClimbMemoHelper(n - 3);

    return memo[n];
  };

  return countWaysToClimbMemoHelper(n);
}

int countWaysToClimbTable(int n) {
  std::vector<int> table(n + 1, 0);
  table[0] = 1;

  for (int i = 1; i <= n; i++) {
    if (i - 1 >= 0)
      table[i] += table[i - 1];

    if (i - 2 >= 0)
      table[i] += table[i - 2];

    if (i - 3 >= 0)
      table[i] += table[i - 3];
  }

  return table[n];
}