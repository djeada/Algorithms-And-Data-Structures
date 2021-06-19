#include "dijkstra.h"
#include <bits/stdc++.h>

// chose the smallest edge of which the vertex hasnt been chosen
template <class T>
int dijkstra(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {

  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;
  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  auto minDistance = [&]() {
    auto vertices = graph.vertices();
    std::sort(vertices.begin(), vertices.end(),
              [&](const auto &r, const auto &l) {
                return distances[r] < distances[l];
              });
    for (auto vertex : vertices) {
      if (!visited[vertex])
        return vertex;
    }
    return source;
  };

  for (const auto vertex : graph.vertices()) {
    distances[vertex] = INT_MAX;
    visited[vertex] = false;
  }

  distances[source] = 0;

  for (int i = 0; i < graph.size() - 1; i++) {

    auto u = minDistance();
    visited[u] = true;

    for (auto &edge : graph.edgesFromVertex(u)) {
      auto v = edge.destination;
      auto newDistance = distances[u] + edge.distance;
      if (newDistance < distances[v])
        distances[v] = newDistance;
    }
  }

  if (distances[destination] < 0)
    return INT_MAX;

  return distances[destination];
}

template int dijkstra<int>(const Graph<int> &graph, Vertex<int> source,
                           Vertex<int> destination);
template int dijkstra<char>(const Graph<char> &graph, Vertex<char> source,
                            Vertex<char> destination);
template int dijkstra<float>(const Graph<float> &graph, Vertex<float> source,
                             Vertex<float> destination);
template int dijkstra<double>(const Graph<double> &graph, Vertex<double> source,
                              Vertex<double> destination);
