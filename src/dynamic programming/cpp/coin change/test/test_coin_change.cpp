#include "coin_change.h"
#include "gtest/gtest.h"

TEST(CoinChangeTest, TestBasicNegative) {
  int num = 0;
  std::vector<int> coins = {3, 2, 1};
  int result = 0;

  ASSERT_EQ(coinChangeBasic(num, coins), result);
}

TEST(CoinChangeTest, TestBasicPositive) {
  int num = 67;
  std::vector<int> coins = {1, 5, 10, 25};
  int result = 6;

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
