#include "prim.h"
#include <queue>
#include <unordered_map>
#include <vector>

// Prim's algorithm using a priority queue for efficient minimum edge selection
template <class T> int prim(const Graph<T> &graph) {
  if (graph.empty())
    return 0;

  auto vertices = graph.vertices();
  if (vertices.empty())
    return 0;

  std::unordered_map<Vertex<T>, bool, HashFunction<T>> inMST;

  for (const auto &vertex : vertices)
    inMST[vertex] = false;

  // Start from the first vertex
  Vertex<T> source = vertices.front();
  inMST[source] = true;

  // Min-heap of edges ordered by weight
  auto cmp = [](const Edge<T> &a, const Edge<T> &b) {
    return a.distance > b.distance;
  };

  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> minHeap(
      cmp);

  // Add all edges from source to the heap
  for (const auto &edge : graph.edgesFromVertex(source))
    minHeap.push(edge);

  int mstWeight = 0;
  size_t verticesInMST = 1;
  const size_t totalVertices = vertices.size();

  while (!minHeap.empty() && verticesInMST < totalVertices) {
    Edge<T> minEdge = minHeap.top();
    minHeap.pop();

    const auto &v = minEdge.destination;

    // Skip if vertex is already in MST
    if (inMST[v])
      continue;

    // Add vertex to MST
    inMST[v] = true;
    mstWeight += minEdge.distance;
    verticesInMST++;

    // Add all edges from newly added vertex
    for (const auto &edge : graph.edgesFromVertex(v)) {
      if (!inMST[edge.destination])
        minHeap.push(edge);
    }
  }

  return mstWeight;
}

template int prim<int>(const Graph<int> &graph);
template int prim<char>(const Graph<char> &graph);
template int prim<float>(const Graph<float> &graph);
template int prim<double>(const Graph<double> &graph);
