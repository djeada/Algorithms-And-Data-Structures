#include "kruskal.h"
#include <algorithm>
#include <functional>
#include <unordered_map>

// Kruskal's algorithm using Union-Find with path compression and union by rank
template <class T> int kruskal(const Graph<T> &graph) {
  if (graph.empty())
    return 0;

  std::unordered_map<Vertex<T>, Vertex<T>, HashFunction<T>> parent;
  std::unordered_map<Vertex<T>, int, HashFunction<T>> rank;

  // Find with path compression
  std::function<Vertex<T>(const Vertex<T> &)> find;
  find = [&](const Vertex<T> &u) -> Vertex<T> {
    if (parent[u] != u)
      parent[u] = find(parent[u]);
    return parent[u];
  };

  // Union by rank
  auto unite = [&](const Vertex<T> &x, const Vertex<T> &y) {
    Vertex<T> rootX = find(x);
    Vertex<T> rootY = find(y);

    if (rootX == rootY)
      return;

    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  };

  // Initialize each vertex as its own parent with rank 0
  for (const auto &vertex : graph.vertices()) {
    parent[vertex] = vertex;
    rank[vertex] = 0;
  }

  // Sort edges by weight
  auto edges = graph.edges();
  std::sort(edges.begin(), edges.end());

  int mstWeight = 0;
  size_t edgesAdded = 0;
  const size_t maxEdges = graph.size() - 1;

  for (const auto &edge : edges) {
    const auto &u = edge.source;
    const auto &v = edge.destination;

    if (find(u) != find(v)) {
      mstWeight += edge.distance;
      unite(u, v);
      edgesAdded++;

      // Early termination when MST is complete
      if (edgesAdded == maxEdges)
        break;
    }
  }

  return mstWeight;
}

template int kruskal<int>(const Graph<int> &graph);
template int kruskal<char>(const Graph<char> &graph);
template int kruskal<float>(const Graph<float> &graph);
template int kruskal<double>(const Graph<double> &graph);
