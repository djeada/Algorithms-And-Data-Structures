#include "topological_sort.h"

#include <cstddef>
#include <stdexcept>
#include <utility>

Graph::Graph(int n) : num_vertices(n) {
  if (n < 0) {
    throw std::invalid_argument("number of vertices must be non-negative");
  }
  adjacency_list.resize(n);
}

void Graph::add_edge(int u, int v) {
  if (u < 0 || u >= num_vertices || v < 0 || v >= num_vertices) {
    throw std::out_of_range("vertex out of range");
  }
  adjacency_list[u].push_back(v);
}

std::vector<int> Graph::topological_sort() const {
  enum class State { Unvisited, InProgress, Done };
  std::vector<State> state(num_vertices, State::Unvisited);
  std::vector<int> order;
  order.reserve(num_vertices);

  // Iterative DFS: (vertex, index of the next neighbour to explore).
  std::vector<std::pair<int, std::size_t>> stack;
  for (int start = 0; start < num_vertices; ++start) {
    if (state[start] != State::Unvisited) {
      continue;
    }
    state[start] = State::InProgress;
    stack.emplace_back(start, 0);

    while (!stack.empty()) {
      const int v = stack.back().first;
      std::size_t &next = stack.back().second;
      if (next < adjacency_list[v].size()) {
        const int u = adjacency_list[v][next++];
        if (state[u] == State::InProgress) {
          throw std::invalid_argument("graph contains a cycle");
        }
        if (state[u] == State::Unvisited) {
          state[u] = State::InProgress;
          stack.emplace_back(u, 0);
        }
      } else {
        state[v] = State::Done;
        order.push_back(v);
        stack.pop_back();
      }
    }
  }

  // Reverse post-order is a topological order.
  return {order.rbegin(), order.rend()};
}
