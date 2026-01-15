/**
 * @file test_binary_search.cpp
 * @brief Unit tests for the binary search algorithm.
 */

#include "binary_search.h"
#include "gtest/gtest.h"

/// @brief Test searching an empty array.
TEST(BinarySearchTest, EmptyArray) {
  std::vector<int> arr;
  EXPECT_EQ(binary_search(arr, 5), std::nullopt);
}

/// @brief Test finding the only element in a single-element array.
TEST(BinarySearchTest, SingleElementFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(binary_search(arr, 5), 0);
}

/// @brief Test not finding element in a single-element array.
TEST(BinarySearchTest, SingleElementNotFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(binary_search(arr, 3), std::nullopt);
}

/// @brief Test target at the first position.
TEST(BinarySearchTest, TargetAtBeginning) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(binary_search(arr, 1), 0);
}

/// @brief Test target at the last position.
TEST(BinarySearchTest, TargetAtEnd) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(binary_search(arr, 5), 4);
}

/// @brief Test target in the middle of the array.
TEST(BinarySearchTest, TargetInMiddle) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(binary_search(arr, 3), 2);
}

/// @brief Test target smaller than all elements.
TEST(BinarySearchTest, TargetTooSmall) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(binary_search(arr, 1), std::nullopt);
}

/// @brief Test target larger than all elements.
TEST(BinarySearchTest, TargetTooLarge) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(binary_search(arr, 12), std::nullopt);
}

/// @brief Test target in gap between elements.
TEST(BinarySearchTest, TargetInGap) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(binary_search(arr, 5), std::nullopt);
}

/// @brief Test searching with negative numbers.
TEST(BinarySearchTest, WithNegativeNumbers) {
  std::vector<int> arr{-10, -5, 0, 5, 10};
  EXPECT_EQ(binary_search(arr, -5), 1);
}
