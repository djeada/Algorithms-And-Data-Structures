#include <unordered_map>
#include <vector>

/**
 * @brief A simple undirected graph represented using an adjacency map.
 */
struct Graph {
  /**
   * @brief Constructs an empty graph.
   */
  Graph();

  /**
   * @brief Adds an undirected edge between vertices u and v.
   * @param u First vertex.
   * @param v Second vertex.
   */
  void add_edge(int u, int v);

  int num_vertices;
  std::unordered_map<int, std::vector<int>> adjacency_dict;
};

/**
 * @brief Finds all valid k-colorable configurations of the graph.
 *
 * A k-colorable configuration assigns one of k colors to each vertex
 * such that no two adjacent vertices share the same color.
 *
 * @param G The graph to color.
 * @param k The number of available colors.
 * @return Vector of all valid configurations.
 */
std::vector<std::vector<int>> find_k_colorable_configurations(Graph &G, int k);