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
 * @brief Finds all Hamiltonian paths in the graph.
 *
 * A Hamiltonian path visits each vertex exactly once.
 *
 * @param G The graph to search.
 * @return Vector of all Hamiltonian paths, where each path is a list of vertex indices.
 */
std::vector<std::vector<int>> find_hamiltonian_paths(Graph &G);