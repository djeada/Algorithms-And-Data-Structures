#include "longest_increasing_subarray.h"
#include "gtest/gtest.h"

TEST(LongestIncreasingSubarrayTest, TestBasic1) {
  std::vector<int> array{13, 1, 15, 13, 6, 11, 10, 20, 7};
  int result = 4;

  ASSERT_EQ(longestIncreasingSubarrayBasic(array), result);
}

TEST(LongestIncreasingSubarrayTest, TestBasic2) {
  std::vector<int> array{0, 9, 7, 14, 6, 8};
  int result = 3;

  ASSERT_EQ(longestIncreasingSubarrayBasic(array), result);
}

TEST(LongestIncreasingSubarrayTest, TestMemo1) {
  std::vector<int> array{13, 1, 15, 13, 6, 11, 10, 20, 7};
  int result = 4;

  ASSERT_EQ(longestIncreasingSubarrayMemo(array), result);
}

TEST(LongestIncreasingSubarrayTest, TestMemo2) {
  std::vector<int> array{0, 9, 7, 14, 6, 8};
  int result = 3;

  ASSERT_EQ(longestIncreasingSubarrayMemo(array), result);
}

TEST(LongestIncreasingSubarrayTest, TestTable1) {
  std::vector<int> array{13, 1, 15, 13, 6, 11, 10, 20, 7};
  int result = 4;

  ASSERT_EQ(longestIncreasingSubarrayTable(array), result);
}

TEST(LongestIncreasingSubarrayTest, TestTable2) {
  std::vector<int> array{0, 9, 7, 14, 6, 8};
  int result = 3;

  ASSERT_EQ(longestIncreasingSubarrayTable(array), result);
}

#include <climits>
#include <random>

TEST(LisEdgeCases, EmptyArray) {
  std::vector<int> a;
  ASSERT_EQ(longestIncreasingSubarrayBasic(a), 0);
  ASSERT_EQ(longestIncreasingSubarrayMemo(a), 0);
  ASSERT_EQ(longestIncreasingSubarrayTable(a), 0);
}

TEST(LisEdgeCases, IntMinElement) {
  std::vector<int> a = {INT_MIN, 0, 1};
  ASSERT_EQ(longestIncreasingSubarrayBasic(a), 3);
  ASSERT_EQ(longestIncreasingSubarrayMemo(a), 3);
  ASSERT_EQ(longestIncreasingSubarrayTable(a), 3);
}

TEST(LisEdgeCases, AgainstBruteForce) {
  std::mt19937 rng(5);
  for (int iter = 0; iter < 200; ++iter) {
    std::vector<int> a(rng() % 10 + 1);
    for (auto &x : a)
      x = static_cast<int>(rng() % 8) - 4;
    std::vector<int> best(a.size(), 1);
    int expected = 0;
    for (size_t i = 0; i < a.size(); ++i) {
      for (size_t j = 0; j < i; ++j)
        if (a[j] < a[i])
          best[i] = std::max(best[i], best[j] + 1);
      expected = std::max(expected, best[i]);
    }
    ASSERT_EQ(longestIncreasingSubarrayBasic(a), expected);
    ASSERT_EQ(longestIncreasingSubarrayMemo(a), expected);
    ASSERT_EQ(longestIncreasingSubarrayTable(a), expected);
  }
}
