#pragma once

#include <vector>

/**
 * @brief A directed graph for topological sorting.
 */
class Graph {
public:
  /**
   * @brief Constructs a graph with n vertices labelled 0..n-1.
   * @param n Number of vertices.
   * @throws std::invalid_argument if n is negative.
   */
  explicit Graph(int n);

  /**
   * @brief Adds a directed edge from u to v.
   * @param u Source vertex.
   * @param v Destination vertex.
   * @throws std::out_of_range if u or v is not a valid vertex.
   */
  void add_edge(int u, int v);

  /**
   * @brief Performs topological sort on the graph.
   * @return Every vertex, ordered so that u precedes v for each edge (u, v).
   * @throws std::invalid_argument if the graph contains a cycle.
   */
  std::vector<int> topological_sort() const;

private:
  int num_vertices;
  std::vector<std::vector<int>> adjacency_list;
};
