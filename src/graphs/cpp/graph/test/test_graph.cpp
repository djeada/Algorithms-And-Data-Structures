#include "graph.h"
#include "gtest/gtest.h"

#include <algorithm>

template <typename T>
void assertVectorsEqual(std::vector<T> x, std::vector<T> y)
{
    ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < x.size(); ++i) {
        EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}
TEST(Graph, DefaultConstructor)
{
    Graph graph;
    ASSERT_TRUE(graph.empty());
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
    EXPECT_EQ(graph.size(), 6);
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

TEST(Graph, AddingVertices)
{
    Graph graph;
    graph.addVertex(Vertex(1));
    graph.addVertex(Vertex(2));
    graph.addVertex(Vertex(3));

    ASSERT_TRUE(graph.contains(1));
    ASSERT_TRUE(graph.contains(2));
    ASSERT_TRUE(graph.contains(3));
    EXPECT_EQ(graph.size(), 3);

    assertVectorsEqual(graph.vertices(),
        std::vector<Vertex>{
            Vertex(1),
            Vertex(2),
            Vertex(3) });
}
