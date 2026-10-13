#include "can_sum.h"
#include "gtest/gtest.h"

TEST(CanSumTest, TestNegativeBasic1) {
  std::vector<unsigned int> numbers = {2, 2, 4};
  unsigned int target = 7;

  ASSERT_FALSE(canSumBasic(target, numbers));
}

TEST(CanSumTest, TestNegativeBasic2) {
  std::vector<unsigned int> numbers = {3, 5, 9, 10};
  unsigned int target = 1;

  ASSERT_FALSE(canSumBasic(target, numbers));
}

TEST(CanSumTest, TestPositiveBasic1) {
  std::vector<unsigned int> numbers = {3, 3, 8, 9, 11};
  unsigned int target = 20;

  ASSERT_TRUE(canSumBasic(target, numbers));
}

TEST(CanSumTest, TestPositiveBasic2) {
  std::vector<unsigned int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  unsigned int target = 25;

  ASSERT_TRUE(canSumBasic(target, numbers));
}

TEST(CanSumTest, TestNegativeMemo1) {
  std::vector<unsigned int> numbers = {2, 2, 4};
  unsigned int target = 7;

  ASSERT_FALSE(canSumMemo(target, numbers));
}

TEST(CanSumTest, TestNegativeMemo2) {
  std::vector<unsigned int> numbers = {3, 5, 9, 10};
  unsigned int target = 1;

  ASSERT_FALSE(canSumMemo(target, numbers));
}

TEST(CanSumTest, TestPositiveMemo1) {
  std::vector<unsigned int> numbers = {3, 3, 8, 9, 11};
  unsigned int target = 20;

  ASSERT_TRUE(canSumMemo(target, numbers));
}

TEST(CanSumTest, TestPositiveMemo2) {
  std::vector<unsigned int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  unsigned int target = 25;

  ASSERT_TRUE(canSumMemo(target, numbers));
}

TEST(CanSumTest, TestNegativeTable1) {
  std::vector<unsigned int> numbers = {2, 2, 4};
  unsigned int target = 7;

  ASSERT_FALSE(canSumTable(target, numbers));
}

TEST(CanSumTest, TestNegativeTable2) {
  std::vector<unsigned int> numbers = {3, 5, 9, 10};
  unsigned int target = 1;

  ASSERT_FALSE(canSumTable(target, numbers));
}

TEST(CanSumTest, TestPositiveTable1) {
  std::vector<unsigned int> numbers = {3, 3, 8, 9, 11};
  unsigned int target = 20;

  ASSERT_TRUE(canSumTable(target, numbers));
}

TEST(CanSumTest, TestPositiveTable2) {
  std::vector<unsigned int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  unsigned int target = 25;

  ASSERT_TRUE(canSumTable(target, numbers));
}

#include <climits>
#include <random>

TEST(CanSumEdgeCases, LargeNumberBeforeUsableOne) {
  // A number larger than the target must be skipped, not end the search.
  std::vector<unsigned int> numbers = {8, 7};
  ASSERT_TRUE(canSumBasic(7, numbers));
  ASSERT_TRUE(canSumMemo(7, numbers));
  ASSERT_TRUE(canSumTable(7, numbers));
}

TEST(CanSumEdgeCases, ZeroTargetAndEmptyNumbers) {
  std::vector<unsigned int> empty;
  ASSERT_TRUE(canSumBasic(0, empty));
  ASSERT_TRUE(canSumMemo(0, empty));
  ASSERT_TRUE(canSumTable(0, empty));
  ASSERT_FALSE(canSumBasic(5, empty));
  ASSERT_FALSE(canSumMemo(5, empty));
  ASSERT_FALSE(canSumTable(5, empty));
}

TEST(CanSumEdgeCases, ZeroIsIgnored) {
  std::vector<unsigned int> numbers = {0, 3};
  ASSERT_TRUE(canSumBasic(6, numbers));
  ASSERT_TRUE(canSumMemo(6, numbers));
  ASSERT_TRUE(canSumTable(6, numbers));
  ASSERT_FALSE(canSumBasic(7, numbers));
  ASSERT_FALSE(canSumMemo(7, numbers));
  ASSERT_FALSE(canSumTable(7, numbers));
}

TEST(CanSumEdgeCases, HugeNumberDoesNotOverflow) {
  std::vector<unsigned int> numbers = {UINT_MAX, 4};
  ASSERT_FALSE(canSumTable(10, numbers));
  ASSERT_TRUE(canSumTable(12, numbers));
}

TEST(CanSumEdgeCases, AgainstBruteForce) {
  std::mt19937 rng(42);
  for (int iter = 0; iter < 300; ++iter) {
    unsigned int target = rng() % 30;
    std::vector<unsigned int> numbers(rng() % 5);
    for (auto &n : numbers)
      n = rng() % 10 + 1;
    std::vector<bool> reachable(target + 1, false);
    reachable[0] = true;
    for (unsigned int t = 1; t <= target; ++t)
      for (auto n : numbers)
        if (n <= t && reachable[t - n])
          reachable[t] = true;
    ASSERT_EQ(canSumBasic(target, numbers), reachable[target]);
    ASSERT_EQ(canSumMemo(target, numbers), reachable[target]);
    ASSERT_EQ(canSumTable(target, numbers), reachable[target]);
  }
}
