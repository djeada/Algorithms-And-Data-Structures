/**
 * @file test_selection_sort.cpp
 * @brief Unit tests for the selection sort algorithm.
 */

#include "selection_sort.h"
#include "gtest/gtest.h"

/// @brief Test sorting an empty array.
TEST(SelectionSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> expected;
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a single element array.
TEST(SelectionSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> expected{1};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in sorted order.
TEST(SelectionSortTest, TwoElementsSorted) {
  std::vector<int> arr{1, 2};
  std::vector<int> expected{1, 2};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in reverse order.
TEST(SelectionSortTest, TwoElementsReversed) {
  std::vector<int> arr{2, 1};
  std::vector<int> expected{1, 2};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a reverse-sorted array.
TEST(SelectionSortTest, DecreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> expected{1, 2, 3, 4, 5};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an already sorted array.
TEST(SelectionSortTest, IncreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array in random order.
TEST(SelectionSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> expected{1, 2, 3, 4, 5};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with duplicate values.
TEST(SelectionSortTest, WithDuplicates) {
  std::vector<int> arr{3, 1, 4, 1, 5, 9, 2, 6, 5};
  std::vector<int> expected{1, 1, 2, 3, 4, 5, 5, 6, 9};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with negative numbers.
TEST(SelectionSortTest, WithNegativeNumbers) {
  std::vector<int> arr{-3, 1, -4, 1, 5};
  std::vector<int> expected{-4, -3, 1, 1, 5};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array where all elements are the same.
TEST(SelectionSortTest, AllSameElements) {
  std::vector<int> arr{5, 5, 5, 5};
  std::vector<int> expected{5, 5, 5, 5};
  selection_sort(arr);
  EXPECT_EQ(expected, arr);
}
