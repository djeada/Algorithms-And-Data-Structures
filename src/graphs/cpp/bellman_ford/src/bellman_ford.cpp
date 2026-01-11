#include "bellman_ford.h"
#include <climits>
#include <limits>
#include <unordered_map>

// Bellman-Ford algorithm: handles negative edge weights and detects negative cycles
template <class T>
int bellmanFord(const Graph<T> &graph, Vertex<T> source,
                Vertex<T> destination) {
  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;

  for (const auto &vertex : graph.vertices()) {
    distances[vertex] = std::numeric_limits<int>::max();
  }

  distances[source] = 0;

  const auto allEdges = graph.edges();
  const size_t numVertices = graph.size();

  // Relax all edges V-1 times
  for (size_t i = 0; i < numVertices - 1; ++i) {
    bool updated = false;

    for (const auto &edge : allEdges) {
      if (distances[edge.source] != std::numeric_limits<int>::max()) {
        int newDistance = distances[edge.source] + edge.distance;
        if (newDistance < distances[edge.destination]) {
          distances[edge.destination] = newDistance;
          updated = true;
        }
      }
    }

    // Early termination if no updates were made
    if (!updated)
      break;
  }

  // Check for negative-weight cycles
  for (const auto &edge : allEdges) {
    if (distances[edge.source] != std::numeric_limits<int>::max() &&
        distances[edge.source] + edge.distance < distances[edge.destination]) {
      // Negative cycle detected
      return INT_MAX;
    }
  }

  return distances[destination] == std::numeric_limits<int>::max()
             ? INT_MAX
             : distances[destination];
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
