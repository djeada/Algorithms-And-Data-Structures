#include "kruskal.h"
#include "gtest/gtest.h"

TEST(TestKruskal, nonEmptyGraph)
{
    Graph g;

    g.addEdge(0, 8, 1);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 7, 6);
    g.addEdge(1, 9, 8);
    g.addEdge(1, 3, 11);
    g.addEdge(1, 5, 8);
    g.addEdge(1, 4, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 7, 6);
    g.addEdge(2, 6, 4);
    g.addEdge(2, 5, 3);
    g.addEdge(3, 5, 11);
    g.addEdge(4, 3, 12);
    g.addEdge(5, 8, 2);
    g.addEdge(6, 1, 1);
    g.addEdge(6, 2, 14);
    g.addEdge(6, 3, 10);
    g.addEdge(7, 3, 5);
    g.addEdge(7, 4, 1);
    g.addEdge(8, 5, 6);
    g.addEdge(8, 6, 7);

    EXPECT_EQ(kruskal(g), 27);
}
