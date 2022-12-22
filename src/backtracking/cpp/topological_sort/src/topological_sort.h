#include <unordered_map>
#include <vector>

struct Graph {

  Graph();
  void add_edge(int u, int v);

  int num_vertices;
  std::unordered_map<int, std::vector<int>> adjacency_dict;
};

std::vector<int> topological_sort(Graph G);