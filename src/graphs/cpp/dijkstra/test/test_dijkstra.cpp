#include "dijkstra.h"
#include "gtest/gtest.h"

TEST(TestDijkstra, nonEmptyGraph)
{
    Graph graph;
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 2);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 5, 3);
    graph.addEdge(3, 2, 1);
    graph.addEdge(3, 4, 4);
    graph.addEdge(3, 5, 5);
    graph.addEdge(5, 4, 1);

    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(1)), 0);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(2)), 3);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(3)), 2);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(4)), 5);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(5)), 6);
}

TEST(TestDijkstra, nonExistentVertices)
{
    Graph graph;

    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(1)), -1);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(2)), -1);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(3)), -1);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(4)), -1);
    EXPECT_EQ(dijkstra(graph, Vertex(1), Vertex(5)), -1);
}
