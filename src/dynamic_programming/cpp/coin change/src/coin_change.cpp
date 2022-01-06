#include "coin_change.h"
#include <climits>
#include <functional>
#include <unordered_map>

int coinChangeBasic(int amount, const std::vector<int> &coins) {

  if (amount <= 0)
    return 0;

  auto minCoins = INT_MAX;

  for (const auto &coin : coins) {
    if (coin <= amount) {

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
    if (amount <= 0)
      return 0;

    if (memo.count(amount))
      return memo[amount];

    auto minCoins = INT_MAX;

    for (const auto &coin : coins) {
      if (coin <= amount) {

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

  std::vector<std::vector<int>> table(coins.size() + 1,
                                      std::vector<int>(amount + 1));

  for (int i = 0; i <= amount; i++)
    table[0][i] = i;

  for (int i = 1; i < coins.size(); i++) {

    for (int j = 0; j <= amount; j++) {
      if (j < coins[i])
        table[i][j] = table[i - 1][j];

      else
        table[i][j] = std::min(table[i - 1][j], table[i][j - coins[i]] + 1);
    }
  }

  return table[coins.size() - 1][amount];
}
