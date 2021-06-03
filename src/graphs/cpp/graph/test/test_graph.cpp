#include "graph.h"
#include "gtest/gtest.h"

#include <algorithm>

template <typename T>
void assertVectorsEqual(std::vector<T> x, std::vector<T> y) {
  ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  for (int i = 0; i < x.size(); ++i) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}

TEST(Vertex, EqualInt) {
  auto vertexA = Vertex<int>(1);
  auto vertexB = Vertex<int>(1);

  EXPECT_EQ(vertexA, vertexB);
}

TEST(Vertex, EqualChar) {
  auto vertexA = Vertex<char>('A');
  auto vertexB = Vertex<char>('A');

  EXPECT_EQ(vertexA, vertexB);
}

TEST(Vertex, NotEqualInt) {
  auto vertexA = Vertex<int>(1);
  auto vertexB = Vertex<int>(2);

  EXPECT_NE(vertexA, vertexB);
}

TEST(Vertex, NotEqualChar) {
  auto vertexA = Vertex<char>('A');
  auto vertexB = Vertex<char>('B');

  EXPECT_NE(vertexA, vertexB);
}

TEST(Vertex, Sort) {
  std::vector<Vertex<int>> array = {Vertex<int>(5), Vertex<int>(4), Vertex<int>(1), Vertex<int>(3), Vertex<int>(2)};
  std::vector<Vertex<int>> expectedResult = {Vertex<int>(1), Vertex<int>(2), Vertex<int>(3), Vertex<int>(4), Vertex<int>(5)};
  std::sort(array.begin(), array.end());

  assertVectorsEqual(array, expectedResult);
}

TEST(Graph, DefaultConstructor) {
  Graph<int> graph;
  ASSERT_TRUE(graph.empty());
}

TEST(Graph, AddingVertices) {
  Graph<int> graph;
  graph.addVertex(Vertex<int>(1));
  graph.addVertex(Vertex<int>(2));
  graph.addVertex(Vertex<int>(3));

  ASSERT_TRUE(graph.contains(1));
  ASSERT_TRUE(graph.contains(2));
  ASSERT_TRUE(graph.contains(3));
  EXPECT_EQ(graph.size(), 3);

  assertVectorsEqual(
      graph.vertices(),
      std::vector<Vertex<int>>{Vertex<int>(1), Vertex<int>(2), Vertex<int>(3)});
}

TEST(Graph, AddingEdges) {
  Graph<int> graph;
  graph.addEdge(Vertex<int>(1), Vertex<int>(5), 10);
  graph.addEdge(Vertex<int>(1), Vertex<int>(2), 10);
  graph.addEdge(Vertex<int>(1), Vertex<int>(3), 10);
  graph.addEdge(Vertex<int>(2), Vertex<int>(2), 1);
  graph.addEdge(Vertex<int>(3), Vertex<int>(3), 2);
  graph.addEdge(Vertex<int>(4), Vertex<int>(-5), 3);
  EXPECT_EQ(graph.size(), 6);

  ASSERT_TRUE(graph.contains(1));
  ASSERT_TRUE(graph.contains(2));
  ASSERT_TRUE(graph.contains(3));
  ASSERT_TRUE(graph.contains(4));

  assertVectorsEqual(
      graph.edges(Vertex<int>(1)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(1), Vertex<int>(5), 10),
                             Edge<int>(Vertex<int>(1), Vertex<int>(2), 10),
                             Edge<int>(Vertex<int>(1), Vertex<int>(3), 10)});

  assertVectorsEqual(
      graph.edges(Vertex<int>(2)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(2), Vertex<int>(2), 1)});

  assertVectorsEqual(
      graph.edges(Vertex<int>(3)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(3), Vertex<int>(3), 2)});

  assertVectorsEqual(
      graph.edges(Vertex<int>(4)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(4), Vertex<int>(-5), 3)});
}
