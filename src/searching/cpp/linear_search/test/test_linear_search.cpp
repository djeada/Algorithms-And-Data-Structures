/**
 * @file test_linear_search.cpp
 * @brief Unit tests for the linear search algorithm.
 */

#include "linear_search.h"
#include "gtest/gtest.h"

/// @brief Test searching an empty array.
TEST(LinearSearchTest, EmptyArray) {
  std::vector<int> arr;
  EXPECT_EQ(linear_search(arr, 5), std::nullopt);
}

/// @brief Test finding the only element in a single-element array.
TEST(LinearSearchTest, SingleElementFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(linear_search(arr, 5), 0);
}

/// @brief Test not finding element in a single-element array.
TEST(LinearSearchTest, SingleElementNotFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(linear_search(arr, 3), std::nullopt);
}

/// @brief Test target at the first position.
TEST(LinearSearchTest, TargetAtBeginning) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(linear_search(arr, 1), 0);
}

/// @brief Test target at the last position.
TEST(LinearSearchTest, TargetAtEnd) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(linear_search(arr, 5), 4);
}

/// @brief Test target in the middle of the array.
TEST(LinearSearchTest, TargetInMiddle) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(linear_search(arr, 3), 2);
}

/// @brief Test target not in the array.
TEST(LinearSearchTest, TargetNotFound) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(linear_search(arr, 6), std::nullopt);
}

/// @brief Test returns first occurrence when duplicates exist.
TEST(LinearSearchTest, WithDuplicatesReturnsFirst) {
  std::vector<int> arr{1, 2, 3, 2, 1};
  EXPECT_EQ(linear_search(arr, 2), 1);
}

/// @brief Test searching with negative numbers.
TEST(LinearSearchTest, WithNegativeNumbers) {
  std::vector<int> arr{-5, -3, -1, 0, 2, 4};
  EXPECT_EQ(linear_search(arr, -3), 1);
}

/// @brief Test works correctly on unsorted arrays.
TEST(LinearSearchTest, UnsortedArray) {
  std::vector<int> arr{5, 2, 8, 1, 9};
  EXPECT_EQ(linear_search(arr, 8), 2);
}
