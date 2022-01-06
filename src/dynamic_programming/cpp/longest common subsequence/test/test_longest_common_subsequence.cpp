#include "longest_common_subsequence.h"
#include "gtest/gtest.h"

TEST(LongestCommonSubsequenceTest, TestBasic1) {
  std::vector<int> arrayA{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> arrayB{2, 4, 8, 16, 32, 64};
  int result = 3;

  ASSERT_EQ(longestCommonSubsequenceBasic(arrayA, arrayB), result);
}

TEST(LongestCommonSubsequenceTest, TestBasic2) {
  std::vector<int> arrayA{1, 9, 3, 10, 4, 20, 6};
  std::vector<int> arrayB{1, 2, 3, 4, 5, 6, 7};
  int result = 4;

  ASSERT_EQ(longestCommonSubsequenceBasic(arrayA, arrayB), result);
}

TEST(LongestCommonSubsequenceTest, TestMemo1) {
  std::vector<int> arrayA{1, 9, 3, 10, 4, 20, 6};
  std::vector<int> arrayB{1, 2, 3, 4, 5, 6, 7};
  int result = 4;

  ASSERT_EQ(longestCommonSubsequenceMemo(arrayA, arrayB), result);
}

TEST(LongestCommonSubsequenceTest, TestMemo2) {
  std::vector<int> arrayA{1, 9, 3, 10, 4, 20, 6};
  std::vector<int> arrayB{1, 2, 3, 4, 5, 6, 7};
  int result = 4;

  ASSERT_EQ(longestCommonSubsequenceMemo(arrayA, arrayB), result);
}

TEST(LongestCommonSubsequenceTest, TestTable1) {
  std::vector<int> arrayA{1, 9, 3, 10, 4, 20, 6};
  std::vector<int> arrayB{1, 2, 3, 4, 5, 6, 7};
  int result = 4;

  ASSERT_EQ(longestCommonSubsequenceTable(arrayA, arrayB), result);
}

TEST(LongestCommonSubsequenceTest, TestTable2) {
  std::vector<int> arrayA{1, 9, 3, 10, 4, 20, 6};
  std::vector<int> arrayB{1, 2, 3, 4, 5, 6, 7};
  int result = 4;

  ASSERT_EQ(longestCommonSubsequenceTable(arrayA, arrayB), result);
}
