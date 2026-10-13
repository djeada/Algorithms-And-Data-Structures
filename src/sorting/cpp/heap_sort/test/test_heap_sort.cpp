/**
 * @file test_heap_sort.cpp
 * @brief Unit tests for the heap sort algorithm.
 */

#include "heap_sort.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <random>

/// @brief Test sorting an empty array.
TEST(HeapSortTest, EmptyArray) {
  std::vector<int> arr;
  std::vector<int> expected;
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a single element array.
TEST(HeapSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> expected{1};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in sorted order.
TEST(HeapSortTest, TwoElementsSorted) {
  std::vector<int> arr{1, 2};
  std::vector<int> expected{1, 2};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting two elements in reverse order.
TEST(HeapSortTest, TwoElementsReversed) {
  std::vector<int> arr{2, 1};
  std::vector<int> expected{1, 2};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting a reverse-sorted array.
TEST(HeapSortTest, DecreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> expected{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an already sorted array.
TEST(HeapSortTest, IncreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array in random order.
TEST(HeapSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> expected{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with duplicate values.
TEST(HeapSortTest, WithDuplicates) {
  std::vector<int> arr{3, 1, 4, 1, 5, 9, 2, 6, 5};
  std::vector<int> expected{1, 1, 2, 3, 4, 5, 5, 6, 9};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array with negative numbers.
TEST(HeapSortTest, WithNegativeNumbers) {
  std::vector<int> arr{-3, 1, -4, 1, 5};
  std::vector<int> expected{-4, -3, 1, 1, 5};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

/// @brief Test sorting an array where all elements are the same.
TEST(HeapSortTest, AllSameElements) {
  std::vector<int> arr{5, 5, 5, 5};
  std::vector<int> expected{5, 5, 5, 5};
  heap_sort(arr);
  EXPECT_EQ(expected, arr);
}

TEST(HeapSortTest, MatchesStdSortOnRandomInputs) {
  std::mt19937 rng(1234);
  std::uniform_int_distribution<int> value(-20, 20);
  std::uniform_int_distribution<int> length(0, 40);
  for (int round = 0; round < 300; ++round) {
    std::vector<int> data(length(rng));
    for (auto &x : data) {
      x = value(rng);
    }
    std::vector<int> expected = data;
    std::sort(expected.begin(), expected.end());
    heap_sort(data);
    ASSERT_EQ(expected, data);
  }
}

TEST(HeapSortTest, LargeInput) {
  std::mt19937 rng(7);
  std::vector<int> data(200000);
  for (auto &x : data) {
    x = static_cast<int>(rng());
  }
  std::vector<int> expected = data;
  std::sort(expected.begin(), expected.end());
  heap_sort(data);
  EXPECT_EQ(expected, data);
}
