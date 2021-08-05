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
