#include "all_permutations.h"
#include "gtest/gtest.h"

TEST(TestAllPermutations, TwoElements) {
  std::vector<int> input_list = {1, 2};
  std::vector<std::vector<int>> excepted = {{1, 2}, {2, 1}};
  std::vector<std::vector<int>> actual = all_permutations(input_list);

  // sort the vectors
  std::sort(excepted.begin(), excepted.end());
  std::sort(actual.begin(), actual.end());

  EXPECT_EQ(excepted, actual);
}

TEST(TestAllPermutations, ThreeElements) {
  std::vector<int> input_list = {3, 1, 2};
  std::vector<std::vector<int>> excepted = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                            {2, 3, 1}, {3, 2, 1}, {3, 1, 2}};

  std::vector<std::vector<int>> actual = all_permutations(input_list);

  // sort the vectors
  std::sort(excepted.begin(), excepted.end());
  std::sort(actual.begin(), actual.end());

  EXPECT_EQ(excepted, actual);
}

/*
TEST(TestAllPermutations, FourElements) {
  std::vector<int> input_list = {3, 1, 2, 4};
  std::vector<std::vector<int>> excepted = {
      {3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4}, {3, 2, 4, 1}, {3, 4, 1, 2},
      {3, 4, 2, 1}, {1, 3, 2, 4}, {1, 3, 4, 2}, {1, 2, 3, 4}, {1, 2, 4, 3},
      {1, 4, 3, 2}, {1, 4, 2, 3}, {2, 3, 1, 4}, {2, 3, 4, 1}, {2, 1, 3, 4},
      {2, 1, 4, 3}, {2, 4, 3, 1}, {2, 4, 1, 3}, {4, 3, 1, 2}, {4, 3, 2, 1},
      {4, 1, 3, 2}, {4, 1, 2, 3}, {4, 2, 3, 1}, {4, 2, 1, 3},
  };

  std::vector<std::vector<int>> actual = all_permutations(input_list);

  // sort the vectors
  std::sort(excepted.begin(), excepted.end());
  std::sort(actual.begin(), actual.end());

  EXPECT_EQ(excepted, actual);
}
*/
