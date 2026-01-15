/**
 * @file test_merge_sort.cpp
 * @brief Unit tests for the merge sort algorithm.
 */

#include "merge_sort.h"
#include "gtest/gtest.h"

/// @brief Test sorting an empty array.
TEST(MergeSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> expected;
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a single element array.
TEST(MergeSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> expected{1};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in sorted order.
TEST(MergeSortTest, TwoElementsSorted) {
  std::vector<int> arr{1, 2};
  std::vector<int> expected{1, 2};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in reverse order.
TEST(MergeSortTest, TwoElementsReversed) {
  std::vector<int> arr{2, 1};
  std::vector<int> expected{1, 2};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a reverse-sorted array.
TEST(MergeSortTest, DecreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> expected{1, 2, 3, 4, 5};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an already sorted array.
TEST(MergeSortTest, IncreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array in random order.
TEST(MergeSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> expected{1, 2, 3, 4, 5};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with duplicate values.
TEST(MergeSortTest, WithDuplicates) {
  std::vector<int> arr{3, 1, 4, 1, 5, 9, 2, 6, 5};
  std::vector<int> expected{1, 1, 2, 3, 4, 5, 5, 6, 9};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with negative numbers.
TEST(MergeSortTest, WithNegativeNumbers) {
  std::vector<int> arr{-3, 1, -4, 1, 5};
  std::vector<int> expected{-4, -3, 1, 1, 5};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array where all elements are the same.
TEST(MergeSortTest, AllSameElements) {
  std::vector<int> arr{5, 5, 5, 5};
  std::vector<int> expected{5, 5, 5, 5};
  merge_sort(arr);
  EXPECT_EQ(expected, arr);
}
