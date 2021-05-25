#include "selection_sort.h"
#include "gtest/gtest.h"

TEST(SelectionSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> result;
  selection_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(SelectionSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  selection_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(SelectionSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  selection_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(SelectionSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  selection_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(SelectionSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  selection_sort(arr);
  EXPECT_EQ(result, arr);
}
