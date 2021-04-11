#include "bfs.h"
#include <bits/stdc++.h>

int breadthFirstSearch(const Graph& graph, Vertex source, Vertex destination)
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

    std::queue<Vertex> queue;
    queue.push(source);

    while (!queue.empty()) {
        auto u = queue.front();
        queue.pop();

        for (auto& edge : graph.edges(u)) {

            auto v = edge.destination;

            if (!visited[v]) {
                visited[v] = true;
                distances[v] = distances[u] + edge.distance;
                queue.push(v);
            }
        }
    }

    return distances[destination];
}
