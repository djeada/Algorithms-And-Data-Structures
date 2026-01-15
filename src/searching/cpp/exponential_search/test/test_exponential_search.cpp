/**
 * @file test_exponential_search.cpp
 * @brief Unit tests for the exponential search algorithm.
 */

#include "exponential_search.h"
#include "gtest/gtest.h"

/// @brief Test searching an empty array.
TEST(ExponentialSearchTest, EmptyArray) {
  std::vector<int> arr;
  EXPECT_EQ(exponential_search(arr, 5), std::nullopt);
}

/// @brief Test finding the only element in a single-element array.
TEST(ExponentialSearchTest, SingleElementFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(exponential_search(arr, 5), 0);
}

/// @brief Test not finding element in a single-element array.
TEST(ExponentialSearchTest, SingleElementNotFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(exponential_search(arr, 3), std::nullopt);
}

/// @brief Test target at the first position - optimal case.
TEST(ExponentialSearchTest, TargetAtBeginning) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(exponential_search(arr, 1), 0);
}

/// @brief Test target at the last position.
TEST(ExponentialSearchTest, TargetAtEnd) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(exponential_search(arr, 5), 4);
}

/// @brief Test target in the middle of the array.
TEST(ExponentialSearchTest, TargetInMiddle) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(exponential_search(arr, 3), 2);
}

/// @brief Test target smaller than all elements.
TEST(ExponentialSearchTest, TargetTooSmall) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(exponential_search(arr, 1), std::nullopt);
}

/// @brief Test target larger than all elements.
TEST(ExponentialSearchTest, TargetTooLarge) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(exponential_search(arr, 12), std::nullopt);
}

/// @brief Test target in gap between elements.
TEST(ExponentialSearchTest, TargetInGap) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(exponential_search(arr, 5), std::nullopt);
}

/// @brief Test searching with negative numbers.
TEST(ExponentialSearchTest, WithNegativeNumbers) {
  std::vector<int> arr{-10, -5, 0, 5, 10};
  EXPECT_EQ(exponential_search(arr, -5), 1);
}
