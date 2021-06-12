#include "dfs.h"
#include <bits/stdc++.h>

template <class T>
int dfs(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {

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

  std::function<void(Vertex<T>)> search;
  search = [&](Vertex<T> u) -> void {
    visited[u] = true;

    for (auto &edge : graph.edgesFromVertex(u)) {

      auto v = edge.destination;
      if (!visited[v]) {
        distances[v] = distances[u] + edge.distance;
        search(v);
      }
    }
  };

  search(source);

  if (distances[destination] < 0)
    return INT_MAX;

  return distances[destination];
}

template int dfs<int>(const Graph<int> &graph, Vertex<int> source,
                      Vertex<int> destination);
template int dfs<char>(const Graph<char> &graph, Vertex<char> source,
                       Vertex<char> destination);
template int dfs<float>(const Graph<float> &graph, Vertex<float> source,
                        Vertex<float> destination);
template int dfs<double>(const Graph<double> &graph, Vertex<double> source,
                         Vertex<double> destination);
