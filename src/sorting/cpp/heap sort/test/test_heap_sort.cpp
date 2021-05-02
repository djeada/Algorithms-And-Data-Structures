#include "heap_sort.h"
#include "gtest/gtest.h"

TEST(HeapSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> result;
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}
