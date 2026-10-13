#include "coin_change.h"
#include <algorithm>
#include <climits>
#include <functional>
#include <unordered_map>

int coinChangeBasic(int amount, const std::vector<int> &coins) {

  if (amount < 0)
    return INT_MAX;
  if (amount == 0)
    return 0;

  auto minCoins = INT_MAX;

  for (const auto &coin : coins) {
    if (coin > 0 && coin <= amount) {

      auto temp = coinChangeBasic(amount - coin, coins);
      if (temp != INT_MAX)
        minCoins = std::min(minCoins, temp + 1);
    }
  }

  return minCoins;
}

int coinChangeMemo(int amount, const std::vector<int> &coins) {

  std::function<int(int, const std::vector<int> &,
                    std::unordered_map<int, int> &)>
      _coinChangeMemo;
  _coinChangeMemo = [&](int amount, const std::vector<int> &coins,
                        std::unordered_map<int, int> &memo) -> int {
    if (amount < 0)
      return INT_MAX;
    if (amount == 0)
      return 0;

    if (memo.count(amount))
      return memo[amount];

    auto minCoins = INT_MAX;

    for (const auto &coin : coins) {
      if (coin > 0 && coin <= amount) {

        auto temp = _coinChangeMemo(amount - coin, coins, memo);
        if (temp != INT_MAX)
          minCoins = std::min(minCoins, temp + 1);
      }
    }

    memo[amount] = minCoins;
    return memo[amount];
  };

  std::unordered_map<int, int> memo;
  return _coinChangeMemo(amount, coins, memo);
}

int coinChangeTable(int amount, const std::vector<int> &coins) {
  if (amount < 0)
    return INT_MAX;

  std::vector<int> table(amount + 1, INT_MAX);
  table[0] = 0;

  for (int i = 1; i <= amount; i++) {
    for (const auto &coin : coins) {
      if (coin > 0 && coin <= i && table[i - coin] != INT_MAX)
        table[i] = std::min(table[i], table[i - coin] + 1);
    }
  }

  return table[amount];
}
