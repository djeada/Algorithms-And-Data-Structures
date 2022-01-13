#include "how_sum.h"
#include "gtest/gtest.h"

#include <algorithm>

bool equal(std::vector<unsigned int> v1, std::vector<unsigned int> v2) {

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  return v1 == v2;
}

TEST(HowSumTest, TestNegativeBasic1) {
  std::vector<unsigned int> numbers = {10, 15, 20};
  unsigned int target = 5;

  ASSERT_TRUE(howSumBasic(target, numbers).empty());
}

TEST(HowSumTest, TestNegativeBasic2) {
  std::vector<unsigned int> numbers = {3, 6, 8, 9};
  unsigned int target = 10;

  ASSERT_TRUE(howSumBasic(target, numbers).empty());
}

TEST(HowSumTest, TestPositiveBasic1) {
  std::vector<unsigned int> numbers = {2, 2, 4, 5};
  unsigned int target = 8;

  std::vector<unsigned int> expectedResult = {2, 2, 2, 2};
  ASSERT_TRUE(equal(howSumBasic(target, numbers), expectedResult));
}

TEST(HowSumTest, TestPositiveBasic2) {
  std::vector<unsigned int> numbers = {3, 8, 6};
  unsigned int target = 9;

  std::vector<unsigned int> expectedResult = {3, 3, 3};
  ASSERT_TRUE(equal(howSumBasic(target, numbers), expectedResult));
}

TEST(HowSumTest, TestNegativeMemo1) {
  std::vector<unsigned int> numbers = {10, 15, 20};
  unsigned int target = 5;

  ASSERT_TRUE(howSumMemo(target, numbers).empty());
}

TEST(HowSumTest, TestNegativeMemo2) {
  std::vector<unsigned int> numbers = {3, 6, 8, 9};
  unsigned int target = 10;

  ASSERT_TRUE(howSumMemo(target, numbers).empty());
}

TEST(HowSumTest, TestPositiveMemo1) {
  std::vector<unsigned int> numbers = {2, 2, 4, 5};
  unsigned int target = 8;

  std::vector<unsigned int> expectedResult = {2, 2, 2, 2};
  ASSERT_TRUE(equal(howSumMemo(target, numbers), expectedResult));
}

TEST(HowSumTest, TestPositiveMemo2) {
  std::vector<unsigned int> numbers = {3, 8, 6};
  unsigned int target = 9;

  std::vector<unsigned int> expectedResult = {3, 3, 3};
  ASSERT_TRUE(equal(howSumMemo(target, numbers), expectedResult));
}

TEST(HowSumTest, TestNegativeTable1) {
  std::vector<unsigned int> numbers = {10, 15, 20};
  unsigned int target = 5;

  ASSERT_TRUE(howSumTable(target, numbers).empty());
}

TEST(HowSumTest, TestNegativeTable2) {
  std::vector<unsigned int> numbers = {3, 6, 8, 9};
  unsigned int target = 10;

  ASSERT_TRUE(howSumTable(target, numbers).empty());
}

TEST(HowSumTest, TestPositiveTable1) {
  std::vector<unsigned int> numbers = {2, 2, 4, 5};
  unsigned int target = 8;

  std::vector<unsigned int> expectedResult = {2, 2, 2, 2};
  ASSERT_TRUE(equal(howSumTable(target, numbers), expectedResult));
}

TEST(HowSumTest, TestPositiveTable2) {
  std::vector<unsigned int> numbers = {3, 8, 6};
  unsigned int target = 9;

  std::vector<unsigned int> expectedResult = {3, 3, 3};
  ASSERT_TRUE(equal(howSumTable(target, numbers), expectedResult));
}
