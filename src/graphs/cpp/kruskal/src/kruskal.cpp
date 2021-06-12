#include "kruskal.h"
#include <algorithm>
#include <functional>

// 1. Create a set of all edges
// 2. Sort the set
// 3. Build spanning tree

int kruskal(const Graph &graph) {
  int result = 0;
  std::unordered_map<Vertex, Vertex, Vertex::HashFunction> parent;
  std::unordered_map<Vertex, int, Vertex::HashFunction> rank;

  std::function<Vertex(Vertex)> find;
  find = [&](Vertex u) -> Vertex {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  };

  auto merge = [&](Vertex x, Vertex y) {
    x = find(x);
    y = find(y);

    if (rank[x] > rank[y])
      parent[y] = x;
    else
      parent[x] = y;

    if (rank[x] == rank[y])
      rank[y]++;
  };

  auto vertices = graph.vertices();

  for (const auto &vertex : vertices) {
    parent[vertex] = vertex;
  }

  auto edges = graph.edges();
  std::sort(edges.begin(), edges.end());

  for (const auto &edge : edges) {

    auto u = edge.source;
    auto v = edge.destination;

    auto set_u = find(u);
    auto set_v = find(v);

    if (set_u != set_v) {
      result += edge.distance;
      merge(set_u, set_v);
    }
  }

  return result;
}
