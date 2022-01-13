#include "merge_sort.h"
#include "gtest/gtest.h"

TEST(MergeSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> result;
  merge_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(MergeSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  merge_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(MergeSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  merge_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(MergeSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  merge_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(MergeSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  merge_sort(arr);
  EXPECT_EQ(result, arr);
}
