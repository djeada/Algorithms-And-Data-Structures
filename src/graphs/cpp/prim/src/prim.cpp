#include "prim.h"
#include <bits/stdc++.h>

template <class T> int prim(const Graph<T> &graph) {

  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  auto vertices = graph.vertices();

  for (const auto vertex : vertices)
    visited[vertex] = false;

  // pick random vertex
  auto source = vertices.front();
  visited[source] = true;

  auto cmp = [&](Edge<T> l, Edge<T> r) { return l.distance > r.distance; };

  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> unvisited(
      cmp);

  for (auto edge : graph.edgesFromVertex(source))
    unvisited.push(edge);

  int result = 0;

  while (!unvisited.empty()) {

    auto currentEdge = unvisited.top();
    unvisited.pop();
    auto distance = currentEdge.distance;
    auto vertex = currentEdge.destination;

    if (!visited[vertex]) {
      visited[vertex] = true;
      result += distance;
      for (auto edge : graph.edgesFromVertex(vertex)) {
        if (!visited[edge.destination])
          unvisited.push(edge);
      }
    }
  }

  return result;
}

template int prim<int>(const Graph<int> &graph);
template int prim<char>(const Graph<char> &graph);
template int prim<float>(const Graph<float> &graph);
template int prim<double>(const Graph<double> &graph);
