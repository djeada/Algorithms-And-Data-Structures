#include "a_star.h"
#include "gtest/gtest.h"
#include <climits>
#include <cmath>

double distance(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

TEST(TestAStar, PointVertices) {
  Graph<Point> graph;

  Point a(1, 1);
  Point b(4, 3);
  Point c(7, 2);
  Point d(3, 8);
  Point e(4, 1);

  graph.addEdge(Vertex<Point>(a), Vertex<Point>(e), 4);
  graph.addEdge(Vertex<Point>(a), Vertex<Point>(b), 8);
  graph.addEdge(Vertex<Point>(a), Vertex<Point>(d), 11);
  graph.addEdge(Vertex<Point>(e), Vertex<Point>(c), 18);
  graph.addEdge(Vertex<Point>(e), Vertex<Point>(b), 2);
  graph.addEdge(Vertex<Point>(b), Vertex<Point>(c), 12);

  EXPECT_EQ(aStar(graph, Vertex<Point>(a), Vertex<Point>(c), distance), 18);
  EXPECT_EQ(aStar(graph, Vertex<Point>(a), Vertex<Point>(b), distance), 6);
  EXPECT_EQ(aStar(graph, Vertex<Point>(d), Vertex<Point>(b), distance),
            INT_MAX);
  EXPECT_EQ(aStar(graph, Vertex<Point>(b), Vertex<Point>(e), distance),
            INT_MAX);
}
