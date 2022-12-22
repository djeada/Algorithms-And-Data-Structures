#include "all_combinations.h"
#include "gtest/gtest.h"

TEST(TestAllCombinations, TestN4K2) {
  int n = 4;
  int k = 2;
  std::vector<std::vector<int>> expected = {
      {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2},
      {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
  };
  std::vector<std::vector<int>> actual = all_combinations(n, k);

  EXPECT_EQ(expected, actual);
}

TEST(TestAllCombinations, TestN2K1) {
  int n = 2;
  int k = 1;
  std::vector<std::vector<int>> expected = {
      {0},
      {1},
      {2},
  };

  std::vector<std::vector<int>> actual = all_combinations(n, k);

  EXPECT_EQ(expected, actual);
}

TEST(TestAllCombinations, TestN10K1) {
  int n = 10;
  int k = 1;
  std::vector<std::vector<int>> expected = {
      {0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10},
  };

  std::vector<std::vector<int>> actual = all_combinations(n, k);

  EXPECT_EQ(expected, actual);
}