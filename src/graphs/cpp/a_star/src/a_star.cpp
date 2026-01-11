#include "a_star.h"
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

// A* search algorithm with heuristic-guided exploration
template <class T>
int aStar(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination,
          double (*heuristic)(T a, T b)) {
  constexpr int INF = std::numeric_limits<int>::max();

  if (!graph.contains(source) || !graph.contains(destination))
    return INF;

  if (source == destination)
    return 0;

  // g(n) - actual cost from source to n
  std::unordered_map<Vertex<T>, int, HashFunction<T>> gScore;
  // f(n) = g(n) + h(n) - estimated total cost
  std::unordered_map<Vertex<T>, double, HashFunction<T>> fScore;

  for (const auto &vertex : graph.vertices()) {
    gScore[vertex] = INF;
    fScore[vertex] = std::numeric_limits<double>::max();
  }

  gScore[source] = 0;
  fScore[source] = heuristic(source.value, destination.value);

  // Min-heap ordered by fScore
  auto cmp = [&](const Vertex<T> &l, const Vertex<T> &r) {
    return fScore[l] > fScore[r];
  };

  std::priority_queue<Vertex<T>, std::vector<Vertex<T>>, decltype(cmp)> openSet(
      cmp);

  std::unordered_map<Vertex<T>, bool, HashFunction<T>> inOpenSet;
  openSet.push(source);
  inOpenSet[source] = true;

  while (!openSet.empty()) {
    Vertex<T> current = openSet.top();
    openSet.pop();
    inOpenSet[current] = false;

    // Goal reached
    if (current == destination)
      return gScore[destination];

    for (const auto &edge : graph.edgesFromVertex(current)) {
      const auto &neighbor = edge.destination;
      int tentativeGScore = gScore[current] + edge.distance;

      if (tentativeGScore < gScore[neighbor]) {
        gScore[neighbor] = tentativeGScore;
        fScore[neighbor] =
            tentativeGScore + heuristic(neighbor.value, destination.value);

        if (!inOpenSet[neighbor]) {
          openSet.push(neighbor);
          inOpenSet[neighbor] = true;
        }
      }
    }
  }

  // No path found
  return gScore[destination] < INF ? gScore[destination] : INF;
}

template int aStar<Point>(const Graph<Point> &graph, Vertex<Point> source,
                          Vertex<Point> destination,
                          double (*heuristic)(Point a, Point b));
