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
  std::vector<Vertex<int>> array = {Vertex<int>(5), Vertex<int>(4),
                                    Vertex<int>(1), Vertex<int>(3),
                                    Vertex<int>(2)};
  std::vector<Vertex<int>> expectedResult = {Vertex<int>(1), Vertex<int>(2),
                                             Vertex<int>(3), Vertex<int>(4),
                                             Vertex<int>(5)};
  std::sort(array.begin(), array.end());

  assertVectorsEqual(array, expectedResult);
}

TEST(Edge, EqualInt) {
  auto edgeA = Edge<int>(Vertex<int>(1), Vertex<int>(2), 10);
  auto edgeB = Edge<int>(Vertex<int>(1), Vertex<int>(2), 10);

  EXPECT_EQ(edgeA, edgeB);
}

TEST(Edge, EqualChar) {
  auto edgeA = Edge<char>(Vertex<char>('A'), Vertex<char>('B'), 5);
  auto edgeB = Edge<char>(Vertex<char>('A'), Vertex<char>('B'), 5);

  EXPECT_EQ(edgeA, edgeB);
}

TEST(Edge, NotEqualInt) {
  auto edgeA = Edge<int>(Vertex<int>(1), Vertex<int>(2), 10);
  auto edgeB = Edge<int>(Vertex<int>(1), Vertex<int>(2), 3);

  EXPECT_NE(edgeA, edgeB);

  edgeA = Edge<int>(Vertex<int>(3), Vertex<int>(2), 10);
  edgeB = Edge<int>(Vertex<int>(1), Vertex<int>(2), 10);

  EXPECT_NE(edgeA, edgeB);
}

TEST(Edge, NotEqualChar) {
  auto edgeA = Edge<char>(Vertex<char>('A'), Vertex<char>('B'), 5);
  auto edgeB = Edge<char>(Vertex<char>('A'), Vertex<char>('C'), 5);

  EXPECT_NE(edgeA, edgeB);
}

TEST(Edge, Sort) {
  std::vector<Edge<int>> array = {Edge<int>(Vertex<int>(1), Vertex<int>(2), 10),
                                  Edge<int>(Vertex<int>(3), Vertex<int>(7), 2),
                                  Edge<int>(Vertex<int>(5), Vertex<int>(4), 7),
                                  Edge<int>(Vertex<int>(6), Vertex<int>(2), 5),
                                  Edge<int>(Vertex<int>(9), Vertex<int>(3), 8)};

  std::vector<Edge<int>> expectedResult = {
      Edge<int>(Vertex<int>(3), Vertex<int>(7), 2),
      Edge<int>(Vertex<int>(6), Vertex<int>(2), 5),
      Edge<int>(Vertex<int>(5), Vertex<int>(4), 7),
      Edge<int>(Vertex<int>(9), Vertex<int>(3), 8),
      Edge<int>(Vertex<int>(1), Vertex<int>(2), 10)};
  std::sort(array.begin(), array.end());

  assertVectorsEqual(array, expectedResult);
}

TEST(Graph, Empty) {
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
      graph.edgesFromVertex(Vertex<int>(1)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(1), Vertex<int>(5), 10),
                             Edge<int>(Vertex<int>(1), Vertex<int>(2), 10),
                             Edge<int>(Vertex<int>(1), Vertex<int>(3), 10)});

  assertVectorsEqual(
      graph.edgesFromVertex(Vertex<int>(2)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(2), Vertex<int>(2), 1)});

  assertVectorsEqual(
      graph.edgesFromVertex(Vertex<int>(3)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(3), Vertex<int>(3), 2)});

  assertVectorsEqual(
      graph.edgesFromVertex(Vertex<int>(4)),
      std::vector<Edge<int>>{Edge<int>(Vertex<int>(4), Vertex<int>(-5), 3)});
}

TEST(Graph, EdgesFromVertex) {
  Graph<int> graph;

  auto vertex = Vertex<int>(1);

  auto edgeA = Edge<int>(vertex, Vertex<int>(9), 8);
  auto edgeB = Edge<int>(vertex, Vertex<int>(4), 5);
  auto edgeC = Edge<int>(vertex, Vertex<int>(3), -5);

  graph.addEdge(edgeA);
  graph.addEdge(edgeB);
  graph.addEdge(edgeC);

  auto expectedResult = std::vector<Edge<int>>{edgeA, edgeB, edgeC};

  assertVectorsEqual(graph.edgesFromVertex(vertex), expectedResult);
}

TEST(Graph, Contains) {
  Graph<char> graph;

  auto vertex = Vertex<char>('A');
  ASSERT_FALSE(graph.contains(vertex));

  graph.addVertex(vertex);

  ASSERT_TRUE(graph.contains(vertex));
}

TEST(Graph, size) {
  Graph<int> graph;
  graph.addEdge(Vertex<int>(1), Vertex<int>(9), 10);
  graph.addEdge(Vertex<int>(5), Vertex<int>(4), 10);
  graph.addEdge(Vertex<int>(3), Vertex<int>(1), 10);
  EXPECT_EQ(graph.size(), 5);
}
