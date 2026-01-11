#include "dfs.h"
#include <climits>
#include <functional>
#include <limits>
#include <unordered_map>

// Depth-First Search using recursive approach
template <class T>
int dfs(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {
  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;
  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  for (const auto &vertex : graph.vertices()) {
    distances[vertex] = std::numeric_limits<int>::max();
    visited[vertex] = false;
  }

  distances[source] = 0;

  // Recursive DFS helper with early termination support
  std::function<bool(Vertex<T>)> search;
  search = [&](Vertex<T> u) -> bool {
    visited[u] = true;

    // Early termination when destination is found
    if (u == destination)
      return true;

    for (const auto &edge : graph.edgesFromVertex(u)) {
      const auto &v = edge.destination;

      if (!visited[v]) {
        distances[v] = distances[u] + edge.distance;
        if (search(v))
          return true;
      }
    }

    return false;
  };

  search(source);

  return distances[destination] == std::numeric_limits<int>::max()
             ? INT_MAX
             : distances[destination];
}

template int dfs<int>(const Graph<int> &graph, Vertex<int> source,
                      Vertex<int> destination);
template int dfs<char>(const Graph<char> &graph, Vertex<char> source,
                       Vertex<char> destination);
template int dfs<float>(const Graph<float> &graph, Vertex<float> source,
                        Vertex<float> destination);
template int dfs<double>(const Graph<double> &graph, Vertex<double> source,
                         Vertex<double> destination);
