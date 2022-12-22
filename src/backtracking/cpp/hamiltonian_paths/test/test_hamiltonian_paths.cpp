#include "hamiltonian_paths.h"
#include "gtest/gtest.h"

TEST(HamiltonianPathsTest, TestPositive1) {
  Graph G;
  G.add_edge(0, 1);
  G.add_edge(0, 2);
  G.add_edge(0, 3);
  G.add_edge(1, 2);
  G.add_edge(1, 3);
  G.add_edge(2, 3);

  std::vector<std::vector<int>> expected = {
      {0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2},
      {0, 3, 2, 1}, {1, 0, 2, 3}, {1, 0, 3, 2}, {1, 2, 0, 3}, {1, 2, 3, 0},
      {1, 3, 0, 2}, {1, 3, 2, 0}, {2, 0, 1, 3}, {2, 0, 3, 1}, {2, 1, 0, 3},
      {2, 1, 3, 0}, {2, 3, 0, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 0, 2, 1},
      {3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0},
  };

  std::vector<std::vector<int>> actual = find_hamiltonian_paths(G);
  EXPECT_EQ(expected.size(), actual.size());

  for (auto configuration : actual) {
    EXPECT_TRUE(std::find(expected.begin(), expected.end(), configuration) !=
                expected.end());
  }
}

TEST(HamiltonianPathsTest, TestNegative1) {
  Graph G;
  G.add_edge(0, 2);
  G.add_edge(1, 1);
  G.add_edge(2, 3);
  G.add_edge(2, 4);
  G.add_edge(4, 5);

  std::vector<std::vector<int>> expected = {};
  std::vector<std::vector<int>> actual = find_hamiltonian_paths(G);
  EXPECT_EQ(expected, actual);
}