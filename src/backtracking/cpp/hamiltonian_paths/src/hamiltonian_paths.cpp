#include "hamiltonian_paths.h"

#include <functional>

Graph::Graph() { num_vertices = 0; }

void Graph::add_edge(int u, int v) {
  if (adjacency_dict.count(u) == 0) {
    adjacency_dict[u] = {};
  }

  if (adjacency_dict.count(v) == 0) {
    adjacency_dict[v] = {};
  }

  adjacency_dict[u].push_back(v);
  adjacency_dict[v].push_back(u);
  if (adjacency_dict.size() > num_vertices) {
    num_vertices = adjacency_dict.size();
  }
}

std::vector<std::vector<int>> find_hamiltonian_paths(Graph &G) {
  std::vector<std::vector<int>> paths;
  std::function<void(Graph &, int, std::vector<bool>, std::vector<int>)> dfs;
  dfs = [&](Graph &G, int v, std::vector<bool> visited, std::vector<int> path) {
    // if all the vertices are visited, then the Hamiltonian path exists
    if (path.size() == G.adjacency_dict.size()) {
      // add the Hamiltonian path to the list of paths
      paths.push_back(path);
      return;
    }

    // Check if vertex `v` has any outgoing edges
    if (G.adjacency_dict.count(v) == 0) {
      return;
    }

    // Check if every edge starting from vertex `v` leads to a solution or not
    for (int w : G.adjacency_dict[v]) {
      // process only unvisited vertices as the Hamiltonian
      // path visit each vertex exactly once
      if (!visited[w]) {
        visited[w] = true;
        path.push_back(w);

        // check if adding vertex `w` to the path leads to the solution or not
        dfs(G, w, visited, path);

        // backtrack
        visited[w] = false;
        path.pop_back();
      }
    }
  };

  // start with every node
  for (int start = 0; start < G.adjacency_dict.size(); ++start) {
    // add starting node to the path
    std::vector<int> path = {start};

    // mark the node as visited
    std::vector<bool> visited(G.adjacency_dict.size(), false);
    visited[start] = true;

    // start DFS traversal from the current node
    dfs(G, start, visited, path);

    // backtrack
    visited[start] = false;

    // remove sta
    dfs(G, 0, std::vector<int>(G.num_vertices, -1), {});
    return configurations;
  }
  rting node from the path path.pop_back();
}

return paths;
}
