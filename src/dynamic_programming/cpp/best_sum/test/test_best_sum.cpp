#include "best_sum.h"
#include "gtest/gtest.h"

#include <algorithm>

bool equal(std::vector<unsigned int> v1, std::vector<unsigned int> v2) {

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  return v1 == v2;
}

TEST(BestSumTest, TestNegativeBasic1) {
  std::vector<unsigned int> numbers = {10, 15, 20};
  unsigned int target = 5;

  ASSERT_TRUE(bestSumBasic(target, numbers).empty());
}

TEST(BestSumTest, TestNegativeBasic2) {
  std::vector<unsigned int> numbers = {3, 6, 8, 9};
  unsigned int target = 10;

  ASSERT_TRUE(bestSumBasic(target, numbers).empty());
}

TEST(BestSumTest, TestPositiveBasic1) {
  std::vector<unsigned int> numbers = {2, 2, 4, 5};
  unsigned int target = 8;

  std::vector<unsigned int> expectedResult = {4, 4};
  ASSERT_TRUE(equal(bestSumBasic(target, numbers), expectedResult));
}

TEST(BestSumTest, TestPositiveBasic2) {
  std::vector<unsigned int> numbers = {3, 8, 6};
  unsigned int target = 9;

  std::vector<unsigned int> expectedResult = {3, 6};
  ASSERT_TRUE(equal(bestSumBasic(target, numbers), expectedResult));
}

TEST(BestSumTest, TestNegativeMemo1) {
  std::vector<unsigned int> numbers = {10, 15, 20};
  unsigned int target = 5;

  ASSERT_TRUE(bestSumMemo(target, numbers).empty());
}

TEST(BestSumTest, TestNegativeMemo2) {
  std::vector<unsigned int> numbers = {3, 6, 8, 9};
  unsigned int target = 10;

  ASSERT_TRUE(bestSumMemo(target, numbers).empty());
}

TEST(BestSumTest, TestPositiveMemo1) {
  std::vector<unsigned int> numbers = {2, 2, 4, 5};
  unsigned int target = 8;

  std::vector<unsigned int> expectedResult = {4, 4};
  ASSERT_TRUE(equal(bestSumMemo(target, numbers), expectedResult));
}

TEST(BestSumTest, TestPositiveMemo2) {
  std::vector<unsigned int> numbers = {3, 8, 6};
  unsigned int target = 9;

  std::vector<unsigned int> expectedResult = {3, 6};
  ASSERT_TRUE(equal(bestSumMemo(target, numbers), expectedResult));
}

TEST(BestSumTest, TestNegativeTabulation1) {
  std::vector<unsigned int> numbers = {10, 15, 20};
  unsigned int target = 5;

  ASSERT_TRUE(bestSumTabulation(target, numbers).empty());
}

TEST(BestSumTest, TestNegativeTabulation2) {
  std::vector<unsigned int> numbers = {3, 6, 8, 9};
  unsigned int target = 10;

  ASSERT_TRUE(bestSumTabulation(target, numbers).empty());
}

TEST(BestSumTest, TestPositiveTabulation1) {
  std::vector<unsigned int> numbers = {2, 2, 4, 5};
  unsigned int target = 8;

  std::vector<unsigned int> expectedResult = {4, 4};
  ASSERT_TRUE(equal(bestSumTabulation(target, numbers), expectedResult));
}

TEST(BestSumTest, TestPositiveTabulation2) {
  std::vector<unsigned int> numbers = {3, 8, 6};
  unsigned int target = 9;

  std::vector<unsigned int> expectedResult = {3, 6};
  ASSERT_TRUE(equal(bestSumTabulation(target, numbers), expectedResult));
}
