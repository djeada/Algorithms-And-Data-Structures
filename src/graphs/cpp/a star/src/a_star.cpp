#include "a_star.h"
#include <bits/stdc++.h>

// chose the smallest edge of which the vertex hasnt been chosen
template <class T>
int aStar(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination,
          double (*heuristic)(T a, T b)) {

  if (!graph.contains(source) || !graph.contains(destination))
    return INT_MAX;

  if (source == destination)
    return 0;

  std::unordered_map<Vertex<T>, int, HashFunction<T>> distance_from_source;
  std::unordered_map<Vertex<T>, double, HashFunction<T>>
      distance_till_destination;
  std::unordered_map<Vertex<T>, bool, HashFunction<T>> visited;

  for (const auto vertex : graph.vertices()) {
    distance_from_source[vertex] = INT_MAX;
    distance_till_destination[vertex] = INT_MAX;
    visited[vertex] = false;
  }

  distance_from_source[source] = 0;
  visited[source] = true;
  distance_till_destination[source] =
      heuristic(source.value, destination.value);

  auto cmp = [&](Vertex<T> l, Vertex<T> r) {
    return distance_till_destination[l] > distance_till_destination[r];
  };

  std::priority_queue<Vertex<T>, std::vector<Vertex<T>>, decltype(cmp)>
      nextVertex(cmp);

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
            heuristic(edge.destination.value, destination.value);

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

template int aStar<Point>(const Graph<Point> &graph, Vertex<Point> source,
                          Vertex<Point> destination,
                          double (*heuristic)(Point a, Point b));
