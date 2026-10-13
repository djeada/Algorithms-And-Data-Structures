#include "dfs.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <climits>
#include <random>
#include <vector>

TEST(TestDfs, charVertices) {
  Graph<char> graph;
  graph.addEdge(Vertex<char>('A'), Vertex<char>('D'), 2);
  graph.addEdge(Vertex<char>('A'), Vertex<char>('G'), 3);
  graph.addEdge(Vertex<char>('A'), Vertex<char>('B'), 1);
  graph.addEdge(Vertex<char>('B'), Vertex<char>('E'), 6);
  graph.addEdge(Vertex<char>('B'), Vertex<char>('F'), 7);
  graph.addEdge(Vertex<char>('F'), Vertex<char>('D'), 10);
  graph.addEdge(Vertex<char>('F'), Vertex<char>('C'), 12);
  graph.addEdge(Vertex<char>('E'), Vertex<char>('G'), 9);

  EXPECT_EQ(dfs(graph, Vertex<char>('A'), Vertex<char>('C')), 20);
  EXPECT_EQ(dfs(graph, Vertex<char>('A'), Vertex<char>('F')), 8);
  EXPECT_EQ(dfs(graph, Vertex<char>('B'), Vertex<char>('G')), 15);
  EXPECT_EQ(dfs(graph, Vertex<char>('E'), Vertex<char>('A')), INT_MAX);
  EXPECT_EQ(dfs(graph, Vertex<char>('C'), Vertex<char>('D')), INT_MAX);
}

TEST(TestDfs, intVertices) {
  Graph<int> graph;
  graph.addEdge(Vertex<int>(0), Vertex<int>(1), 1);
  graph.addEdge(Vertex<int>(0), Vertex<int>(4), 1);
  graph.addEdge(Vertex<int>(1), Vertex<int>(0), 1);
  graph.addEdge(Vertex<int>(1), Vertex<int>(3), 1);
  graph.addEdge(Vertex<int>(1), Vertex<int>(4), 1);
  graph.addEdge(Vertex<int>(1), Vertex<int>(2), 1);
  graph.addEdge(Vertex<int>(2), Vertex<int>(3), 1);
  graph.addEdge(Vertex<int>(2), Vertex<int>(1), 1);
  graph.addEdge(Vertex<int>(3), Vertex<int>(1), 1);
  graph.addEdge(Vertex<int>(3), Vertex<int>(2), 1);
  graph.addEdge(Vertex<int>(3), Vertex<int>(4), 1);

  EXPECT_EQ(dfs(graph, Vertex<int>(2), Vertex<int>(0)), 3);
  EXPECT_EQ(dfs(graph, Vertex<int>(2), Vertex<int>(1)), 2);
  EXPECT_EQ(dfs(graph, Vertex<int>(2), Vertex<int>(2)), 0);
  EXPECT_EQ(dfs(graph, Vertex<int>(2), Vertex<int>(3)), 1);
  EXPECT_EQ(dfs(graph, Vertex<int>(2), Vertex<int>(4)), 4);
}

TEST(TestDfs, nonExistentVertices) {
  Graph<int> graph;

  EXPECT_EQ(dfs(graph, Vertex<int>(1), Vertex<int>(1)), INT_MAX);
  EXPECT_EQ(dfs(graph, Vertex<int>(1), Vertex<int>(2)), INT_MAX);
  EXPECT_EQ(dfs(graph, Vertex<int>(1), Vertex<int>(3)), INT_MAX);
  EXPECT_EQ(dfs(graph, Vertex<int>(1), Vertex<int>(4)), INT_MAX);
  EXPECT_EQ(dfs(graph, Vertex<int>(1), Vertex<int>(5)), INT_MAX);
}

TEST(TestDFS, DeepPathDoesNotOverflowStack) {
  Graph<int> graph;
  const int n = 200000;
  for (int i = 0; i < n; ++i)
    graph.addEdge(Vertex<int>(i), Vertex<int>(i + 1), 1);
  EXPECT_EQ(dfs(graph, Vertex<int>(0), Vertex<int>(n)), n);
}

TEST(TestDFS, CycleAndSourceEqualsDestination) {
  Graph<int> graph;
  graph.addEdge(Vertex<int>(0), Vertex<int>(1), 1);
  graph.addEdge(Vertex<int>(1), Vertex<int>(0), 1);
  EXPECT_EQ(dfs(graph, Vertex<int>(0), Vertex<int>(0)), 0);
  EXPECT_EQ(dfs(graph, Vertex<int>(0), Vertex<int>(1)), 1);
  EXPECT_EQ(dfs(graph, Vertex<int>(0), Vertex<int>(5)), INT_MAX);
}

TEST(TestDFS, ReachabilityMatchesBruteForce) {
  std::mt19937 rng(3);
  for (int iter = 0; iter < 100; ++iter) {
    int n = 1 + rng() % 7;
    int m = rng() % 13;
    Graph<int> graph;
    std::vector<std::vector<bool>> reach(n, std::vector<bool>(n, false));
    for (int v = 0; v < n; ++v) {
      graph.addVertex(Vertex<int>(v));
      reach[v][v] = true;
    }
    for (int i = 0; i < m; ++i) {
      int u = rng() % n, v = rng() % n;
      graph.addEdge(Vertex<int>(u), Vertex<int>(v), 1 + rng() % 5);
      reach[u][v] = true;
    }
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (reach[i][k] && reach[k][j])
            reach[i][j] = true;
    for (int s = 0; s < n; ++s)
      for (int t = 0; t < n; ++t)
        EXPECT_EQ(dfs(graph, Vertex<int>(s), Vertex<int>(t)) != INT_MAX,
                  bool(reach[s][t]));
  }
}
