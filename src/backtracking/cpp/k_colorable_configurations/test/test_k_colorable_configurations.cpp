#include "k_colorable_configurations.h"
#include "gtest/gtest.h"

TEST(TestKColorableConfigurations, TestPositive1) {
  Graph G;
  G.add_edge(0, 1);
  G.add_edge(0, 4);
  G.add_edge(0, 5);
  G.add_edge(4, 5);
  G.add_edge(1, 4);
  G.add_edge(1, 3);
  G.add_edge(2, 3);
  G.add_edge(2, 4);
  int k = 3;

  std::vector<std::vector<int>> expected = {
      {0, 1, 0, 2, 2, 1}, {0, 1, 1, 0, 2, 1}, {0, 1, 1, 2, 2, 1},
      {0, 2, 0, 1, 1, 2}, {0, 2, 2, 0, 1, 2}, {0, 2, 2, 1, 1, 2},
      {1, 0, 0, 1, 2, 0}, {1, 0, 0, 2, 2, 0}, {1, 0, 1, 2, 2, 0},
      {1, 2, 1, 0, 0, 2}, {1, 2, 2, 0, 0, 2}, {1, 2, 2, 1, 0, 2},
      {2, 0, 0, 1, 1, 0}, {2, 0, 0, 2, 1, 0}, {2, 0, 2, 1, 1, 0},
      {2, 1, 1, 0, 0, 1}, {2, 1, 1, 2, 0, 1}, {2, 1, 2, 0, 0, 1},
  };

  std::vector<std::vector<int>> actual = find_k_colorable_configurations(G, k);
  EXPECT_EQ(expected.size(), actual.size());

  for (auto configuration : actual) {
    EXPECT_TRUE(std::find(expected.begin(), expected.end(), configuration) !=
                expected.end());
  }
}

TEST(TestKColorableConfigurations, TestNegative1) {
  Graph G;
  G.add_edge(0, 1);
  G.add_edge(1, 2);
  G.add_edge(2, 0);
  int k = 2;

  std::vector<std::vector<int>> expected = {};
  std::vector<std::vector<int>> actual = find_k_colorable_configurations(G, k);
  EXPECT_EQ(expected, actual);
}
