#include "graph.h"
#include "gtest/gtest.h"

template <typename T>
void assertVectorsEqual(const std::vector<T> x, const std::vector<T> y)
{
    ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

    for (int i = 0; i < x.size(); ++i) {
        EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}

TEST(Graph, AddingEdges)
{
    Graph graph;
    graph.addEdge(Vertex(1), Vertex(5), 10);
    graph.addEdge(Vertex(1), Vertex(2), 10);
    graph.addEdge(Vertex(1), Vertex(3), 10);
    graph.addEdge(Vertex(2), Vertex(2), 1);
    graph.addEdge(Vertex(3), Vertex(3), 2);
    graph.addEdge(Vertex(4), Vertex(-5), 3);
    EXPECT_EQ(graph.size(), 4);
    ASSERT_TRUE(graph.contains(1));
    ASSERT_TRUE(graph.contains(2));
    ASSERT_TRUE(graph.contains(3));
    ASSERT_TRUE(graph.contains(4));

    assertVectorsEqual(graph.edges(Vertex(1)),
        std::vector<Edge>{
            Edge(Vertex(1), Vertex(5), 10),
            Edge(Vertex(1), Vertex(2), 10),
            Edge(Vertex(1), Vertex(3), 10) });

    assertVectorsEqual(graph.edges(Vertex(2)),
        std::vector<Edge>{
            Edge(Vertex(2), Vertex(2), 1) });

    assertVectorsEqual(graph.edges(Vertex(3)),
        std::vector<Edge>{
            Edge(Vertex(3), Vertex(3), 2) });

    assertVectorsEqual(graph.edges(Vertex(4)),
        std::vector<Edge>{
            Edge(Vertex(4), Vertex(-5), 3) });
}
