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

#include <climits>
#include <numeric>
#include <random>

TEST(BestSumEdgeCases, ZeroIsIgnored) {
  std::vector<unsigned int> numbers = {0, 5, 1};
  for (auto f : {bestSumBasic, bestSumMemo, bestSumTabulation}) {
    auto r = f(5, numbers);
    ASSERT_EQ(r.size(), 1u);
    ASSERT_EQ(r[0], 5u);
  }
}

TEST(BestSumEdgeCases, HugeNumberDoesNotOverflow) {
  std::vector<unsigned int> numbers = {UINT_MAX, 4};
  ASSERT_TRUE(bestSumTabulation(10, numbers).empty());
  ASSERT_EQ(bestSumTabulation(12, numbers).size(), 3u);
}

TEST(BestSumEdgeCases, AgainstBruteForce) {
  std::mt19937 rng(7);
  for (int iter = 0; iter < 200; ++iter) {
    unsigned int target = rng() % 15 + 1;
    std::vector<unsigned int> numbers(rng() % 4 + 1);
    for (auto &n : numbers)
      n = rng() % 9 + 1;
    std::vector<int> best(target + 1, -1);
    best[0] = 0;
    for (unsigned int t = 1; t <= target; ++t)
      for (auto n : numbers)
        if (n <= t && best[t - n] >= 0 &&
            (best[t] < 0 || best[t - n] + 1 < best[t]))
          best[t] = best[t - n] + 1;
    for (auto f : {bestSumBasic, bestSumMemo, bestSumTabulation}) {
      auto r = f(target, numbers);
      if (best[target] < 0) {
        ASSERT_TRUE(r.empty());
      } else {
        ASSERT_EQ(static_cast<int>(r.size()), best[target]);
        ASSERT_EQ(std::accumulate(r.begin(), r.end(), 0u), target);
      }
    }
  }
}
