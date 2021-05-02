#include "insertion_sort.h"
#include "gtest/gtest.h"

TEST(InsertionSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> result;
  insertion_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(InsertionSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  insertion_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(InsertionSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  insertion_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(InsertionSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  insertion_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(InsertionSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  insertion_sort(arr);
  EXPECT_EQ(result, arr);
}
