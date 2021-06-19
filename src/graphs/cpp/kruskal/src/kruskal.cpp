#include "kruskal.h"
#include <algorithm>
#include <functional>

// 1. Create a set of all edges
// 2. Sort the set
// 3. Build spanning tree

template <class T> int kruskal(const Graph<T> &graph) {

  std::unordered_map<Vertex<T>, Vertex<T>, HashFunction<T>> parent;
  std::unordered_map<Vertex<T>, int, HashFunction<T>> rank;

  std::function<Vertex<T>(const Vertex<T> &)> find;
  find = [&](const Vertex<T> &u) -> Vertex<T> {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  };

  auto merge = [&](const Vertex<T> &x, const Vertex<T> &y) {
    auto _x = find(x);
    auto _y = find(y);

    if (rank[_x] > rank[_y])
      parent[_y] = _x;
    else
      parent[_x] = _y;

    if (rank[_x] == rank[_y])
      rank[_y]++;
  };

  auto vertices = graph.vertices();

  for (const auto &vertex : vertices) {
    parent[vertex] = vertex;
  }

  auto edges = graph.edges();
  std::sort(edges.begin(), edges.end());
  int result = 0;

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

template int kruskal<int>(const Graph<int> &graph);
template int kruskal<char>(const Graph<char> &graph);
template int kruskal<float>(const Graph<float> &graph);
template int kruskal<double>(const Graph<double> &graph);
