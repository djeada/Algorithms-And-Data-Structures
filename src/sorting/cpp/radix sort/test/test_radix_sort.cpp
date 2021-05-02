#include "radix_sort.h"
#include "gtest/gtest.h"

TEST(RadixSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> result;
  radix_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(RadixSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  radix_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(RadixSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  radix_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(RadixSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  radix_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(RadixSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  radix_sort(arr);
  EXPECT_EQ(result, arr);
}
