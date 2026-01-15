/**
 * @file test_interpolation_search.cpp
 * @brief Unit tests for the interpolation search algorithm.
 */

#include "interpolation_search.h"
#include "gtest/gtest.h"

/// @brief Test searching an empty array.
TEST(InterpolationSearchTest, EmptyArray) {
  std::vector<int> arr;
  EXPECT_EQ(interpolation_search(arr, 5), std::nullopt);
}

/// @brief Test finding the only element in a single-element array.
TEST(InterpolationSearchTest, SingleElementFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(interpolation_search(arr, 5), 0);
}

/// @brief Test not finding element in a single-element array.
TEST(InterpolationSearchTest, SingleElementNotFound) {
  std::vector<int> arr{5};
  EXPECT_EQ(interpolation_search(arr, 3), std::nullopt);
}

/// @brief Test target at the first position.
TEST(InterpolationSearchTest, TargetAtBeginning) {
  std::vector<int> arr{10, 20, 30, 40, 50};
  EXPECT_EQ(interpolation_search(arr, 10), 0);
}

/// @brief Test target at the last position.
TEST(InterpolationSearchTest, TargetAtEnd) {
  std::vector<int> arr{10, 20, 30, 40, 50};
  EXPECT_EQ(interpolation_search(arr, 50), 4);
}

/// @brief Test target in the middle of the array.
TEST(InterpolationSearchTest, TargetInMiddle) {
  std::vector<int> arr{10, 20, 30, 40, 50};
  EXPECT_EQ(interpolation_search(arr, 30), 2);
}

/// @brief Test target smaller than all elements.
TEST(InterpolationSearchTest, TargetTooSmall) {
  std::vector<int> arr{10, 20, 30, 40, 50};
  EXPECT_EQ(interpolation_search(arr, 5), std::nullopt);
}

/// @brief Test target larger than all elements.
TEST(InterpolationSearchTest, TargetTooLarge) {
  std::vector<int> arr{10, 20, 30, 40, 50};
  EXPECT_EQ(interpolation_search(arr, 60), std::nullopt);
}

/// @brief Test target in gap between elements.
TEST(InterpolationSearchTest, TargetInGap) {
  std::vector<int> arr{10, 20, 30, 40, 50};
  EXPECT_EQ(interpolation_search(arr, 25), std::nullopt);
}

/// @brief Test array with all same elements, target matches.
TEST(InterpolationSearchTest, AllSameElementsFound) {
  std::vector<int> arr{5, 5, 5, 5};
  EXPECT_EQ(interpolation_search(arr, 5), 0);
}

/// @brief Test array with all same elements, target doesn't match.
TEST(InterpolationSearchTest, AllSameElementsNotFound) {
  std::vector<int> arr{5, 5, 5, 5};
  EXPECT_EQ(interpolation_search(arr, 3), std::nullopt);
}
