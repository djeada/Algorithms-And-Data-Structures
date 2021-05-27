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

  ASSERT_TRUE(canSumMemo(target, numbers));
}

TEST(CanSumTest, TestNegativeMemo2) {
  std::vector<unsigned int> numbers = {3, 5, 9, 10};
  unsigned int target = 1;

  ASSERT_TRUE(canSumMemo(target, numbers));
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

  ASSERT_TRUE(canSumTable(target, numbers));
}

TEST(CanSumTest, TestNegativeTable2) {
  std::vector<unsigned int> numbers = {3, 5, 9, 10};
  unsigned int target = 1;

  ASSERT_TRUE(canSumTable(target, numbers));
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
