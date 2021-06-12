#include "bfs.h"
#include <bits/stdc++.h>

template <class T>
int bfs(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {

  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;

  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  for (const auto vertex : graph.vertices()) {
    distances[vertex] = INT_MAX;
    visited[vertex] = false;
  }

  distances[source] = 0;
  visited[source] = true;

  std::queue<Vertex<T>> queue;
  queue.push(source);

  while (!queue.empty()) {
    auto u = queue.front();
    queue.pop();

    for (auto &edge : graph.edgesFromVertex(u)) {

      auto v = edge.destination;

      if (!visited[v]) {
        visited[v] = true;
        distances[v] = distances[u] + edge.distance;
        queue.push(v);
      }
    }
  }

  if (distances[destination] < 0)
    return INT_MAX;

  return distances[destination];
}

template int bfs<int>(const Graph<int> &graph, Vertex<int> source,
                      Vertex<int> destination);
template int bfs<char>(const Graph<char> &graph, Vertex<char> source,
                       Vertex<char> destination);
template int bfs<float>(const Graph<float> &graph, Vertex<float> source,
                        Vertex<float> destination);
template int bfs<double>(const Graph<double> &graph, Vertex<double> source,
                         Vertex<double> destination);
