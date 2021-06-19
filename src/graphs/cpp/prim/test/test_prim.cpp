#include "prim.h"
#include "gtest/gtest.h"

TEST(TestPrim, nonEmptyGraph) {
  Graph<int> graph;

  graph.addEdge(Vertex<int>(0), Vertex<int>(8), 1);
  graph.addEdge(Vertex<int>(0), Vertex<int>(3), 10);
  graph.addEdge(Vertex<int>(1), Vertex<int>(2), 1);
  graph.addEdge(Vertex<int>(1), Vertex<int>(7), 6);
  graph.addEdge(Vertex<int>(1), Vertex<int>(9), 8);
  graph.addEdge(Vertex<int>(1), Vertex<int>(3), 11);
  graph.addEdge(Vertex<int>(1), Vertex<int>(5), 8);
  graph.addEdge(Vertex<int>(1), Vertex<int>(4), 11);
  graph.addEdge(Vertex<int>(2), Vertex<int>(3), 7);
  graph.addEdge(Vertex<int>(2), Vertex<int>(8), 2);
  graph.addEdge(Vertex<int>(2), Vertex<int>(1), 4);
  graph.addEdge(Vertex<int>(2), Vertex<int>(7), 6);
  graph.addEdge(Vertex<int>(2), Vertex<int>(6), 4);
  graph.addEdge(Vertex<int>(2), Vertex<int>(5), 3);
  graph.addEdge(Vertex<int>(3), Vertex<int>(5), 11);
  graph.addEdge(Vertex<int>(4), Vertex<int>(3), 12);
  graph.addEdge(Vertex<int>(5), Vertex<int>(8), 2);
  graph.addEdge(Vertex<int>(6), Vertex<int>(1), 1);
  graph.addEdge(Vertex<int>(6), Vertex<int>(2), 14);
  graph.addEdge(Vertex<int>(6), Vertex<int>(3), 10);
  graph.addEdge(Vertex<int>(7), Vertex<int>(3), 5);
  graph.addEdge(Vertex<int>(7), Vertex<int>(4), 1);
  graph.addEdge(Vertex<int>(8), Vertex<int>(5), 6);
  graph.addEdge(Vertex<int>(8), Vertex<int>(6), 7);

  EXPECT_EQ(prim(graph), 27);
}
