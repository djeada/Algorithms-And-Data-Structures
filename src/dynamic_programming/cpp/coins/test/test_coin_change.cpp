#include "coin_change.h"
#include "gtest/gtest.h"

TEST(CoinChangeTest, TestBasicNegative) {
  int num = 0;
  std::vector<int> coins = {3, 2, 1};
  int result = 0;

  ASSERT_EQ(coinChangeBasic(num, coins), result);
}

TEST(CoinChangeTest, TestBasicPositive) {
  // Kept small: the plain recursion is exponential in the amount.
  int num = 41;
  std::vector<int> coins = {1, 5, 10, 25};
  int result = 4;

  ASSERT_EQ(coinChangeBasic(num, coins), result);
}

TEST(CoinChangeTest, TestMemoNegative) {
  int num = 0;
  std::vector<int> coins = {3, 2, 1};
  int result = 0;

  ASSERT_EQ(coinChangeMemo(num, coins), result);
}

TEST(CoinChangeTest, TestMemoPositive) {
  int num = 67;
  std::vector<int> coins = {1, 5, 10, 25};
  int result = 6;

  ASSERT_EQ(coinChangeMemo(num, coins), result);
}
TEST(CoinChangeTest, TestTableNegative) {
  int num = 0;
  std::vector<int> coins = {3, 2, 1};
  int result = 0;

  ASSERT_EQ(coinChangeTable(num, coins), result);
}

TEST(CoinChangeTest, TestTablePositive) {
  int num = 67;
  std::vector<int> coins = {1, 5, 10, 25};
  int result = 6;

  ASSERT_EQ(coinChangeTable(num, coins), result);
}

#include <climits>
#include <random>

TEST(CoinChangeEdgeCases, FirstCoinIsNotOne) {
  // The old table implementation implicitly assumed a coin of value 1.
  std::vector<int> coins = {2, 5};
  ASSERT_EQ(coinChangeTable(3, coins), INT_MAX);
  ASSERT_EQ(coinChangeBasic(3, coins), INT_MAX);
  ASSERT_EQ(coinChangeMemo(3, coins), INT_MAX);
  ASSERT_EQ(coinChangeTable(9, coins), 3);
}

TEST(CoinChangeEdgeCases, FirstCoinIsUsed) {
  std::vector<int> coins = {5, 2, 1};
  ASSERT_EQ(coinChangeTable(10, coins), 2);
  ASSERT_EQ(coinChangeBasic(10, coins), 2);
}

TEST(CoinChangeEdgeCases, EmptyCoins) {
  std::vector<int> coins;
  ASSERT_EQ(coinChangeTable(0, coins), 0);
  ASSERT_EQ(coinChangeTable(4, coins), INT_MAX);
  ASSERT_EQ(coinChangeBasic(4, coins), INT_MAX);
  ASSERT_EQ(coinChangeMemo(4, coins), INT_MAX);
}

TEST(CoinChangeEdgeCases, NegativeAmountIsImpossible) {
  std::vector<int> coins = {1, 2};
  ASSERT_EQ(coinChangeBasic(-1, coins), INT_MAX);
  ASSERT_EQ(coinChangeMemo(-1, coins), INT_MAX);
  ASSERT_EQ(coinChangeTable(-1, coins), INT_MAX);
}

TEST(CoinChangeEdgeCases, NonPositiveCoinsAreIgnored) {
  std::vector<int> coins = {0, -1, 2};
  ASSERT_EQ(coinChangeBasic(4, coins), 2);
  ASSERT_EQ(coinChangeMemo(4, coins), 2);
  ASSERT_EQ(coinChangeTable(4, coins), 2);
}

TEST(CoinChangeEdgeCases, AgainstBruteForce) {
  std::mt19937 rng(99);
  for (int iter = 0; iter < 200; ++iter) {
    int amount = rng() % 25;
    std::vector<int> coins(rng() % 4);
    for (auto &c : coins)
      c = rng() % 7 + 1;
    std::vector<int> best(amount + 1, INT_MAX);
    best[0] = 0;
    for (int a = 1; a <= amount; ++a)
      for (auto c : coins)
        if (c <= a && best[a - c] != INT_MAX)
          best[a] = std::min(best[a], best[a - c] + 1);
    ASSERT_EQ(coinChangeBasic(amount, coins), best[amount]);
    ASSERT_EQ(coinChangeMemo(amount, coins), best[amount]);
    ASSERT_EQ(coinChangeTable(amount, coins), best[amount]);
  }
}
