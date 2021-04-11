#include "dfs.h"
#include <bits/stdc++.h>

int depthFirstSearch(const Graph& graph, Vertex source, Vertex destination)
{

    if (!graph.contains(source) || !graph.contains(destination))
        return -1;

    std::unordered_map<Vertex, int, Vertex::HashFunction> distances;
    std::unordered_map<Vertex, bool, Vertex::HashFunction> visited;

    for (const auto vertex : graph.vertices()) {
        distances[vertex] = INT_MAX;
        visited[vertex] = false;
    }

    distances[source] = 0;
    visited[source] = true;

    std::function<Vertex(Vertex)> search;
    search = [&](Vertex u) -> Vertex {
        visited[u] = true;

        for (auto& edge : graph.edges(u)) {

            auto v = edge.destination;
            if (!visited[v]) {
                distances[v] = distances[u] + edge.distance;
                search(v);
            }
        }
    };

    search(source);

    return distances[destination];
}
