/**
 * @file test_insertion_sort.cpp
 * @brief Unit tests for the insertion sort algorithm.
 */

#include "insertion_sort.h"
#include "gtest/gtest.h"

/// @brief Test sorting an empty array.
TEST(InsertionSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> expected;
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a single element array.
TEST(InsertionSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> expected{1};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in sorted order.
TEST(InsertionSortTest, TwoElementsSorted) {
  std::vector<int> arr{1, 2};
  std::vector<int> expected{1, 2};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in reverse order.
TEST(InsertionSortTest, TwoElementsReversed) {
  std::vector<int> arr{2, 1};
  std::vector<int> expected{1, 2};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a reverse-sorted array.
TEST(InsertionSortTest, DecreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> expected{1, 2, 3, 4, 5};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an already sorted array.
TEST(InsertionSortTest, IncreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array in random order.
TEST(InsertionSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> expected{1, 2, 3, 4, 5};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with duplicate values.
TEST(InsertionSortTest, WithDuplicates) {
  std::vector<int> arr{3, 1, 4, 1, 5, 9, 2, 6, 5};
  std::vector<int> expected{1, 1, 2, 3, 4, 5, 5, 6, 9};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with negative numbers.
TEST(InsertionSortTest, WithNegativeNumbers) {
  std::vector<int> arr{-3, 1, -4, 1, 5};
  std::vector<int> expected{-4, -3, 1, 1, 5};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array where all elements are the same.
TEST(InsertionSortTest, AllSameElements) {
  std::vector<int> arr{5, 5, 5, 5};
  std::vector<int> expected{5, 5, 5, 5};
  insertion_sort(arr);
  EXPECT_EQ(expected, arr);
}
