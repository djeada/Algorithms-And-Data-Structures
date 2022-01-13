#include "bellman_ford.h"
#include "gtest/gtest.h"
#include <climits>

TEST(TestBellmanFord, charVertices) {
  Graph<char> graph;
  graph.addEdge(Vertex<char>('A'), Vertex<char>('D'), 2);
  graph.addEdge(Vertex<char>('A'), Vertex<char>('G'), 3);
  graph.addEdge(Vertex<char>('A'), Vertex<char>('B'), 1);
  graph.addEdge(Vertex<char>('B'), Vertex<char>('E'), 6);
  graph.addEdge(Vertex<char>('B'), Vertex<char>('F'), 7);
  graph.addEdge(Vertex<char>('F'), Vertex<char>('D'), 10);
  graph.addEdge(Vertex<char>('F'), Vertex<char>('C'), 12);
  graph.addEdge(Vertex<char>('E'), Vertex<char>('G'), 9);

  EXPECT_EQ(bellmanFord(graph, Vertex<char>('A'), Vertex<char>('C')), 20);
  EXPECT_EQ(bellmanFord(graph, Vertex<char>('A'), Vertex<char>('F')), 8);
  EXPECT_EQ(bellmanFord(graph, Vertex<char>('B'), Vertex<char>('G')), 15);
  EXPECT_EQ(bellmanFord(graph, Vertex<char>('E'), Vertex<char>('A')), INT_MAX);
  EXPECT_EQ(bellmanFord(graph, Vertex<char>('C'), Vertex<char>('D')), INT_MAX);
}

TEST(TestBellmanFord, nonEmptyGraph) {
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

  EXPECT_EQ(bellmanFord(graph, Vertex<int>(2), Vertex<int>(0)), 2);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(2), Vertex<int>(1)), 1);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(2), Vertex<int>(2)), 0);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(2), Vertex<int>(3)), 1);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(2), Vertex<int>(4)), 2);
}

TEST(TestBellmanFord, nonExistentVertices) {

  Graph<int> graph;

  EXPECT_EQ(bellmanFord(graph, Vertex<int>(1), Vertex<int>(1)), INT_MAX);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(1), Vertex<int>(2)), INT_MAX);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(1), Vertex<int>(3)), INT_MAX);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(1), Vertex<int>(4)), INT_MAX);
  EXPECT_EQ(bellmanFord(graph, Vertex<int>(1), Vertex<int>(5)), INT_MAX);
}
