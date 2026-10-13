#include "topological_sort.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace {

// True if `order` is a permutation of 0..n-1 that respects every edge.
bool IsValidOrder(const std::vector<int> &order, int n,
                  const std::vector<std::pair<int, int>> &edges) {
  if (static_cast<int>(order.size()) != n) {
    return false;
  }
  std::vector<int> position(n, -1);
  for (int i = 0; i < n; ++i) {
    if (order[i] < 0 || order[i] >= n || position[order[i]] != -1) {
      return false;
    }
    position[order[i]] = i;
  }
  return std::all_of(edges.begin(), edges.end(), [&](const auto &e) {
    return position[e.first] < position[e.second];
  });
}

} // namespace

TEST(TestTopologicalSort, TestPositive1) {
  Graph g(8);
  const std::vector<std::pair<int, int>> edges = {
      {0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4}, {5, 1}, {7, 0}, {7, 1}};
  for (const auto &e : edges) {
    g.add_edge(e.first, e.second);
  }

  std::vector<int> expected = {7, 5, 3, 1, 4, 2, 0, 6};
  EXPECT_EQ(expected, g.topological_sort());
}

TEST(TestTopologicalSort, TestPositive2) {
  Graph g(7);
  const std::vector<std::pair<int, int>> edges = {{3, 0}, {3, 4}, {0, 6},
                                                  {4, 1}, {1, 2}, {1, 6}};
  for (const auto &e : edges) {
    g.add_edge(e.first, e.second);
  }

  // Vertex 5 is isolated and must still appear in the result.
  EXPECT_TRUE(IsValidOrder(g.topological_sort(), 7, edges));
}

TEST(TestTopologicalSort, EmptyGraph) {
  Graph g(0);
  EXPECT_TRUE(g.topological_sort().empty());
}

TEST(TestTopologicalSort, NoEdges) {
  Graph g(3);
  EXPECT_TRUE(IsValidOrder(g.topological_sort(), 3, {}));
}

TEST(TestTopologicalSort, CycleThrows) {
  Graph g(3);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  EXPECT_THROW(g.topological_sort(), std::invalid_argument);
}

TEST(TestTopologicalSort, SelfLoopThrows) {
  Graph g(2);
  g.add_edge(1, 1);
  EXPECT_THROW(g.topological_sort(), std::invalid_argument);
}

TEST(TestTopologicalSort, InvalidVertexThrows) {
  Graph g(2);
  EXPECT_THROW(g.add_edge(0, 2), std::out_of_range);
  EXPECT_THROW(g.add_edge(-1, 0), std::out_of_range);
}
