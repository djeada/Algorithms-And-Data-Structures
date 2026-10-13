#include "dfs.h"
#include <limits>
#include <unordered_map>
#include <vector>

// Depth-First Search using recursive approach
template <class T>
int dfs(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {
  constexpr int INF = std::numeric_limits<int>::max();

  if (!graph.contains(source) || !graph.contains(destination))
    return INF;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distances;
  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  for (const auto &vertex : graph.vertices()) {
    distances[vertex] = INF;
    visited[vertex] = false;
  }

  distances[source] = 0;

  // Iterative DFS with an explicit stack (same visiting order as the recursive
  // version) so that long paths cannot overflow the call stack.
  struct Frame {
    Vertex<T> vertex;
    std::vector<Edge<T>> edges;
    size_t next;
  };

  std::vector<Frame> stack;
  visited[source] = true;
  stack.push_back({source, graph.edgesFromVertex(source), 0});

  while (!stack.empty()) {
    Frame &frame = stack.back();

    if (frame.next == frame.edges.size()) {
      stack.pop_back();
      continue;
    }

    const Edge<T> edge = frame.edges[frame.next++];
    const Vertex<T> u = frame.vertex;
    const Vertex<T> v = edge.destination;

    if (visited[v])
      continue;

    visited[v] = true;
    distances[v] = distances[u] + edge.distance;

    // Early termination when destination is found
    if (v == destination)
      break;

    stack.push_back({v, graph.edgesFromVertex(v), 0});
  }

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
