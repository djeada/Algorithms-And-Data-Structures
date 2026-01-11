#include <stack>
#include <vector>

/**
 * @brief A directed graph for topological sorting.
 */
class Graph {
public:
  /**
   * @brief Constructs a graph with n vertices.
   * @param n Number of vertices.
   */
  Graph(int n);

  /**
   * @brief Adds a directed edge from u to v.
   * @param u Source vertex.
   * @param v Destination vertex.
   */
  void add_edge(int u, int v);

  /**
   * @brief Performs topological sort on the graph.
   * @return A vector of vertices in topological order.
   */
  std::vector<int> topological_sort();

private:
  int num_vertices;
  std::vector<std::vector<int>> adjacency_list;
  void topological_sort_util(int v, std::vector<bool> &visited,
                             std::stack<int> &Stack);
};

