/**
 * @file test_quick_sort.cpp
 * @brief Unit tests for the quick sort algorithm.
 */

#include "quick_sort.h"
#include "gtest/gtest.h"

/// @brief Test sorting an empty array.
TEST(QuickSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> expected;
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a single element array.
TEST(QuickSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> expected{1};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in sorted order.
TEST(QuickSortTest, TwoElementsSorted) {
  std::vector<int> arr{1, 2};
  std::vector<int> expected{1, 2};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in reverse order.
TEST(QuickSortTest, TwoElementsReversed) {
  std::vector<int> arr{2, 1};
  std::vector<int> expected{1, 2};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a reverse-sorted array.
TEST(QuickSortTest, DecreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> expected{1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an already sorted array.
TEST(QuickSortTest, IncreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array in random order.
TEST(QuickSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> expected{1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with duplicate values.
TEST(QuickSortTest, WithDuplicates) {
  std::vector<int> arr{3, 1, 4, 1, 5, 9, 2, 6, 5};
  std::vector<int> expected{1, 1, 2, 3, 4, 5, 5, 6, 9};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with negative numbers.
TEST(QuickSortTest, WithNegativeNumbers) {
  std::vector<int> arr{-3, 1, -4, 1, 5};
  std::vector<int> expected{-4, -3, 1, 1, 5};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array where all elements are the same.
TEST(QuickSortTest, AllSameElements) {
  std::vector<int> arr{5, 5, 5, 5};
  std::vector<int> expected{5, 5, 5, 5};
  quick_sort(arr);
  EXPECT_EQ(expected, arr);
}
