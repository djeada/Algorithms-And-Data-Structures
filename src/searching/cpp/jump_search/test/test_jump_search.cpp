/**
 * @file test_jump_search.cpp
 * @brief Unit tests for the jump search algorithm.
 */

#include "jump_search.h"
#include "gtest/gtest.h"

/// @brief Test searching an empty array.
TEST(JumpSearchTest, EmptyArray) {
  std::vector<int> arr;
  EXPECT_EQ(jump_search(arr, 5), std::nullopt);
}

/// @brief Test finding the only element in a single-element array.
TEST(JumpSearchTest, SingleElementFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(jump_search(arr, 5), 0);
}

/// @brief Test not finding element in a single-element array.
TEST(JumpSearchTest, SingleElementNotFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(jump_search(arr, 3), std::nullopt);
}

/// @brief Test target at the first position.
TEST(JumpSearchTest, TargetAtBeginning) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(jump_search(arr, 1), 0);
}

/// @brief Test target at the last position.
TEST(JumpSearchTest, TargetAtEnd) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(jump_search(arr, 5), 4);
}

/// @brief Test target in the middle of the array.
TEST(JumpSearchTest, TargetInMiddle) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(jump_search(arr, 3), 2);
}

/// @brief Test target smaller than all elements.
TEST(JumpSearchTest, TargetTooSmall) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(jump_search(arr, 1), std::nullopt);
}

/// @brief Test target larger than all elements.
TEST(JumpSearchTest, TargetTooLarge) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(jump_search(arr, 12), std::nullopt);
}

/// @brief Test target in gap between elements.
TEST(JumpSearchTest, TargetInGap) {
  std::vector<int> arr{2, 4, 6, 8, 10};
  EXPECT_EQ(jump_search(arr, 5), std::nullopt);
}

/// @brief Test searching with negative numbers.
TEST(JumpSearchTest, WithNegativeNumbers) {
  std::vector<int> arr{-10, -5, 0, 5, 10};
  EXPECT_EQ(jump_search(arr, -5), 1);
}
