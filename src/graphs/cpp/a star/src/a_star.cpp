#include "a_star.h"
#include <bits/stdc++.h>

// chose the smallest edge of which the vertex hasnt been chosen
template <class T>
int aStar(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination) {

  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distance_from_source;
  std::unordered_map<Vertex<T>, int, HashFunction<T>>
      distance_till_destination;
 std::unordered_map<Vertex<T>, bool, HashFunction<T>>
      visited;

  for (const auto vertex : graph.vertices()) {
    distance_from_source[vertex] = INT_MAX;
    distance_till_destination[vertex] = INT_MAX;
    visited[vertex] = false;
  }

  distance_from_source[source] = 0;
  visited[source] = true;
  distance_till_destination[source] =
      3; // heuristic(source.value, destination.value);

    auto cmp = [&](Vertex<T> l, Vertex<T> r) { return distance_till_destination[l] < distance_till_destination[r]; };

  std::priority_queue<Vertex<T>, std::vector<Vertex<T>>, decltype(cmp)> nextVertex(
      cmp);

  nextVertex.push(source);

  while (!nextVertex.empty()) {
    auto current = nextVertex.top();
    nextVertex.pop();
    if (current == destination)
      break;

    for (auto &edge : graph.edgesFromVertex(current)) {
      auto tentativeDistanceFromSource =
          distance_from_source[current] + edge.distance;

      if (tentativeDistanceFromSource <
          distance_from_source[edge.destination]) {
        distance_from_source[edge.destination] = tentativeDistanceFromSource;

        distance_till_destination[edge.destination] =
            distance_from_source[edge.destination] +
            3; // heuristic(edge.destination.value, destination.value);

        if (!visited[edge.destination]) {
          nextVertex.push(edge.destination);
        visited[edge.destination] = true;
}

      }
    }
  }

  if (distance_from_source[destination] < 0)
    return INT_MAX;

  return distance_from_source[destination];
}

template int aStar<int>(const Graph<int> &graph, Vertex<int> source,
                        Vertex<int> destination);
template int aStar<char>(const Graph<char> &graph, Vertex<char> source,
                         Vertex<char> destination);
template int aStar<float>(const Graph<float> &graph, Vertex<float> source,
                          Vertex<float> destination);
template int aStar<double>(const Graph<double> &graph, Vertex<double> source,
                           Vertex<double> destination);
