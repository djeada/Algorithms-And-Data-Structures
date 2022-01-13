#include "quick_sort.h"
#include "gtest/gtest.h"

TEST(QuickSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> result;
  quick_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(QuickSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  quick_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(QuickSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(QuickSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(QuickSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(result, arr);
}
