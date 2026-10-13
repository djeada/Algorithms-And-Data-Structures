#include "dijkstra.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <climits>
#include <random>
#include <vector>

TEST(TestDijkstra, charVertices) {
  Graph<char> graph;
  graph.addEdge(Vertex<char>('A'), Vertex<char>('D'), 2);
  graph.addEdge(Vertex<char>('A'), Vertex<char>('G'), 3);
  graph.addEdge(Vertex<char>('A'), Vertex<char>('B'), 1);
  graph.addEdge(Vertex<char>('B'), Vertex<char>('E'), 6);
  graph.addEdge(Vertex<char>('B'), Vertex<char>('F'), 7);
  graph.addEdge(Vertex<char>('F'), Vertex<char>('D'), 10);
  graph.addEdge(Vertex<char>('F'), Vertex<char>('C'), 12);
  graph.addEdge(Vertex<char>('E'), Vertex<char>('G'), 9);

  EXPECT_EQ(dijkstra(graph, Vertex<char>('A'), Vertex<char>('C')), 20);
  EXPECT_EQ(dijkstra(graph, Vertex<char>('A'), Vertex<char>('F')), 8);
  EXPECT_EQ(dijkstra(graph, Vertex<char>('B'), Vertex<char>('G')), 15);
  EXPECT_EQ(dijkstra(graph, Vertex<char>('E'), Vertex<char>('A')), INT_MAX);
  EXPECT_EQ(dijkstra(graph, Vertex<char>('C'), Vertex<char>('D')), INT_MAX);
}

TEST(TestDijkstra, nonEmptyGraph) {
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

  EXPECT_EQ(dijkstra(graph, Vertex<int>(2), Vertex<int>(0)), 2);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(2), Vertex<int>(1)), 1);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(2), Vertex<int>(2)), 0);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(2), Vertex<int>(3)), 1);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(2), Vertex<int>(4)), 2);
}

TEST(TestDijkstra, nonExistentVertices) {

  Graph<int> graph;

  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(1)), INT_MAX);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(2)), INT_MAX);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(3)), INT_MAX);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(4)), INT_MAX);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(5)), INT_MAX);
}

namespace {
struct RawEdge {
  int u, v, w;
};

std::vector<std::vector<long long>> floyd(int n,
                                          const std::vector<RawEdge> &edges) {
  const long long INF = 1LL << 50;
  std::vector<std::vector<long long>> d(n, std::vector<long long>(n, INF));
  for (int i = 0; i < n; ++i)
    d[i][i] = 0;
  for (const auto &e : edges)
    d[e.u][e.v] = std::min<long long>(d[e.u][e.v], e.w);
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (d[i][k] + d[k][j] < d[i][j])
          d[i][j] = d[i][k] + d[k][j];
  return d;
}
} // namespace

TEST(TestDijkstra, SourceEqualsDestinationAndUnknownVertex) {
  Graph<int> graph;
  graph.addEdge(Vertex<int>(1), Vertex<int>(2), 3);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(1)), 0);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(7)), INT_MAX);
}

TEST(TestDijkstra, ParallelEdgesAndZeroWeights) {
  Graph<int> graph;
  graph.addEdge(Vertex<int>(1), Vertex<int>(2), 5);
  graph.addEdge(Vertex<int>(1), Vertex<int>(2), 2);
  graph.addEdge(Vertex<int>(2), Vertex<int>(3), 0);
  EXPECT_EQ(dijkstra(graph, Vertex<int>(1), Vertex<int>(3)), 2);
}

TEST(TestDijkstra, RandomGraphsMatchFloydWarshall) {
  std::mt19937 rng(11);
  for (int iter = 0; iter < 100; ++iter) {
    int n = 1 + rng() % 7;
    int m = rng() % 16;
    std::vector<RawEdge> edges;
    Graph<int> graph;
    for (int v = 0; v < n; ++v)
      graph.addVertex(Vertex<int>(v));
    for (int i = 0; i < m; ++i) {
      RawEdge e{int(rng() % n), int(rng() % n), int(rng() % 10)};
      edges.push_back(e);
      graph.addEdge(Vertex<int>(e.u), Vertex<int>(e.v), e.w);
    }
    auto d = floyd(n, edges);
    for (int s = 0; s < n; ++s)
      for (int t = 0; t < n; ++t) {
        int expected = d[s][t] >= (1LL << 50) ? INT_MAX : int(d[s][t]);
        EXPECT_EQ(dijkstra(graph, Vertex<int>(s), Vertex<int>(t)), expected);
      }
  }
}
