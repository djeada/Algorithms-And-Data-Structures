#include <unordered_map>
#include <vector>

struct Graph {

  Graph();
  void add_edge(int u, int v);

  int num_vertices;
  std::unordered_map<int, std::vector<int>> adjacency_dict;
};

std::vector<std::vector<int>> find_hamiltonian_paths(Graph &G);