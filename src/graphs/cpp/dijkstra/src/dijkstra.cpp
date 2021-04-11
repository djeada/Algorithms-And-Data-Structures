#include "dijkstra.h"
#include <bits/stdc++.h>

//chose the smallest edge of which the vertex hasnt been chosen

int dijkstra(const Graph& graph, const Vertex& source, const Vertex& destination)
{

    if (!graph.contains(source) || !graph.contains(destination))
        return -1;

    std::unordered_map<Vertex, int, Vertex::HashFunction> distances;
    std::unordered_map<Vertex, bool, Vertex::HashFunction> visited;

    auto minDistance = [&]() {
        int min = INT_MAX;
        Vertex minVertex;

        for (auto vertex : graph.vertices()) {
            if (!visited[vertex] && distances[vertex] <= min) {
                min = distances[vertex];
                minVertex = vertex;
            }
        }

        return minVertex;
    };

    for (const auto vertex : graph.vertices()) {
        distances[vertex] = INT_MAX;
        visited[vertex] = false;
    }

    distances[source] = 0;

    for (int i = 0; i < graph.size() - 1; i++) {

        auto u = minDistance();
        visited[u] = true;

        for (auto& edge : graph.edges(u)) {
            auto v = edge.destination;
            auto newDistance = distances[u] + edge.distance;
            if (newDistance < distances[v])
                distances[v] = newDistance;
        }
    }

    return distances[destination];
}
