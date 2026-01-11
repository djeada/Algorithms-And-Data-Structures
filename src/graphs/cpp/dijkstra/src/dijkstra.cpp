#include "dijkstra.h"
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

// Dijkstra's algorithm using a priority queue for O((V+E) log V) complexity
template <class T>
int dijkstra(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {
  constexpr int INF = std::numeric_limits<int>::max();

  if (!graph.contains(source) || !graph.contains(destination))
    return INF;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;

  for (const auto &vertex : graph.vertices()) {
    distances[vertex] = INF;
  }

  distances[source] = 0;

  // Min-heap: pair of (distance, vertex)
  auto cmp = [](const std::pair<int, Vertex<T>> &a,
                const std::pair<int, Vertex<T>> &b) {
    return a.first > b.first;
  };

  std::priority_queue<std::pair<int, Vertex<T>>,
                      std::vector<std::pair<int, Vertex<T>>>, decltype(cmp)>
      pq(cmp);

  pq.push({0, source});

  while (!pq.empty()) {
    auto [currentDist, u] = pq.top();
    pq.pop();

    // Early termination when destination is reached
    if (u == destination)
      return distances[destination];

    // Skip if we've already found a shorter path
    if (currentDist > distances[u])
      continue;

    for (const auto &edge : graph.edgesFromVertex(u)) {
      const auto &v = edge.destination;
      int newDist = distances[u] + edge.distance;

      if (newDist < distances[v]) {
        distances[v] = newDist;
        pq.push({newDist, v});
      }
    }
  }

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
