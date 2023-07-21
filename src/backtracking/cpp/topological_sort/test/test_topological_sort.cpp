#include "topological_sort.h"
#include "gtest/gtest.h"

TEST(TestTopologicalSort, TestPositive1) {
  Graph g(8);
  g.add_edge(0, 6);
  g.add_edge(1, 2);
  g.add_edge(1, 4);
  g.add_edge(1, 6);
  g.add_edge(3, 0);
  g.add_edge(3, 4);
  g.add_edge(5, 1);
  g.add_edge(7, 0);
  g.add_edge(7, 1);

  std::vector<int> expected = {7, 5, 3, 1, 4, 2, 0, 6};
  std::vector<int> actual = g.topological_sort();

  EXPECT_EQ(expected, actual);
}

TEST(TestTopologicalSort, TestPositive2) {
  Graph g(7);
  g.add_edge(3, 0);
  g.add_edge(3, 4);
  g.add_edge(0, 6);
  g.add_edge(4, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 4);
  g.add_edge(1, 6);

  std::vector<int> expected = {3, 4, 1, 2, 0, 6};
  std::vector<int> actual = g.topological_sort();

  EXPECT_EQ(expected, actual);
}

