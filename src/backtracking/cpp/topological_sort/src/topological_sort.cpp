#include "topological_sort.h"

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


std::vector<int> topological_sort(Graph G) {
  std::function<int(Graph &, int, std::vector<bool> &, std::vector<int> &,
                    int)>
      dfs;
  dfs = [&](Graph &G, int v, std::vector<bool> &discovered,
            std::vector<int> &departure, int time) {
    // mark the current node as discovered
    discovered[v] = true;

    // set the arrival time of vertex `v`
    time = time + 1;

    // do for every edge (v, u)
    for (int u : G.adjacency_dict[v]) {
      // if `u` is not yet discovered
      if (!discovered[u]) {
        time = dfs(G, u, discovered, departure, time);
      }
    }

    // ready to backtrack
    // set departure time of vertex `v`
    departure[time] = v;
    time = time + 1;

    return time;
  };

  // departure[] stores the vertex number using departure time as an index
  auto departure = std::vector<int>(2 * G.num_vertices, -1);

  // to keep track of whether a vertex is discovered or not
  auto discovered = std::vector<bool>(G.num_vertices, false);
  int time = 0;

  // perform dfs on all undiscovered vertices
  for (auto v : G.adjacency_dict) {
    if (!discovered[v.first]) {
      time = dfs(G, v.first, discovered, departure, time);
    }
  }

  // Iterate over the vertices in order of their decreasing
  // departure time in dfs, i.e., in topological order
  auto topological_order = std::vector<int>();
  for (int i = 2 * G.num_vertices - 1; i >= 0; --i) {
    if (departure[i] != -1) {
      topological_order.push_back(departure[i]);
    }
  }

  return topological_order;
}  