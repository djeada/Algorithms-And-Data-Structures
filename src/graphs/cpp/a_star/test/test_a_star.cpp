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

namespace {
double zero(int, int) { return 0.0; }
double zeroPoint(Point, Point) { return 0.0; }
} // namespace

TEST(TestAStar, SourceEqualsDestinationAndUnknownVertex) {
  Graph<Point> graph;
  graph.addEdge(Vertex<Point>(Point(0, 0)), Vertex<Point>(Point(1, 0)), 2);
  EXPECT_EQ(aStar(graph, Vertex<Point>(Point(0, 0)), Vertex<Point>(Point(0, 0)),
                  zeroPoint),
            0);
  EXPECT_EQ(aStar(graph, Vertex<Point>(Point(0, 0)), Vertex<Point>(Point(9, 9)),
                  zeroPoint),
            INT_MAX);
}

TEST(TestAStar, ImprovedPathToQueuedVertex) {
  Graph<Point> graph;
  auto V = [](int x) { return Vertex<Point>(Point(x, 0)); };
  graph.addEdge(V(0), V(1), 1);
  graph.addEdge(V(0), V(2), 10);
  graph.addEdge(V(1), V(2), 1);
  graph.addEdge(V(2), V(3), 1);
  graph.addEdge(V(0), V(3), 20);
  EXPECT_EQ(aStar(graph, V(0), V(3), zeroPoint), 3);
}

TEST(TestAStar, PointOrderingIsStrictWeak) {
  EXPECT_TRUE(Point(1, 1) < Point(1, 2));
  EXPECT_TRUE(Point(1, 5) < Point(2, 0));
  EXPECT_FALSE(Point(2, 0) < Point(1, 5));
  EXPECT_FALSE(Point(1, 1) < Point(1, 1));
}
