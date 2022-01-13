#include "bellman_ford.h"
#include <bits/stdc++.h>

template <class T>
int bellmanFord(const Graph<T> &graph, Vertex<T> source,
                Vertex<T> destination) {

  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;
  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  for (const auto vertex : graph.vertices()) {
    distances[vertex] = INT_MAX;
    visited[vertex] = false;
  }

  distances[source] = 0;

  for (int i = 0; i < graph.size() - 1; i++) {

    for (auto &edge : graph.edges()) {
      auto newDistance = distances[edge.source] + edge.distance;

      if (distances[edge.source] != INT_MAX &&
          newDistance < distances[edge.destination])
        distances[edge.destination] = newDistance;
    }
  }

  for (auto &edge : graph.edges()) {
    if (distances[edge.source] != INT_MAX &&
        distances[edge.source] + edge.distance < distances[edge.destination])
      return INT_MAX;
  }

  if (distances[destination] < 0)
    return INT_MAX;

  return distances[destination];
}

template int bellmanFord<int>(const Graph<int> &graph, Vertex<int> source,
                              Vertex<int> destination);
template int bellmanFord<char>(const Graph<char> &graph, Vertex<char> source,
                               Vertex<char> destination);
template int bellmanFord<float>(const Graph<float> &graph, Vertex<float> source,
                                Vertex<float> destination);
template int bellmanFord<double>(const Graph<double> &graph,
                                 Vertex<double> source,
                                 Vertex<double> destination);
