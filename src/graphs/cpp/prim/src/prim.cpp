#include "prim.h"
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

// Prim's algorithm using a priority queue for efficient minimum edge selection.
// Edges are treated as undirected and, for a disconnected graph, the weight of
// the minimum spanning forest is returned (consistent with Kruskal).
template <class T> int prim(const Graph<T> &graph) {
  if (graph.empty())
    return 0;

  const auto vertices = graph.vertices();

  // Undirected adjacency view, since edges are stored one-way
  using Neighbor = std::pair<int, Vertex<T>>;
  std::unordered_map<Vertex<T>, std::vector<Neighbor>, HashFunction<T>>
      adjacency;

  for (const auto &vertex : vertices)
    adjacency[vertex] = {};

  for (const auto &edge : graph.edges()) {
    adjacency[edge.source].push_back({edge.distance, edge.destination});
    adjacency[edge.destination].push_back({edge.distance, edge.source});
  }

  std::unordered_map<Vertex<T>, bool, HashFunction<T>> inMST;

  for (const auto &vertex : vertices)
    inMST[vertex] = false;

  // Min-heap of (weight, vertex)
  auto cmp = [](const Neighbor &a, const Neighbor &b) {
    return a.first > b.first;
  };

  int mstWeight = 0;

  for (const auto &start : vertices) {
    if (inMST[start])
      continue;

    inMST[start] = true;

    std::priority_queue<Neighbor, std::vector<Neighbor>, decltype(cmp)> minHeap(
        cmp);

    for (const auto &neighbor : adjacency[start])
      minHeap.push(neighbor);

    while (!minHeap.empty()) {
      const Neighbor next = minHeap.top();
      minHeap.pop();

      const auto &v = next.second;

      // Skip if vertex is already in MST
      if (inMST[v])
        continue;

      inMST[v] = true;
      mstWeight += next.first;

      for (const auto &neighbor : adjacency[v]) {
        if (!inMST[neighbor.second])
          minHeap.push(neighbor);
      }
    }
  }

  return mstWeight;
}

template int prim<int>(const Graph<int> &graph);
template int prim<char>(const Graph<char> &graph);
template int prim<float>(const Graph<float> &graph);
template int prim<double>(const Graph<double> &graph);
