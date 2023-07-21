#include "topological_sort.h"


Graph::Graph(int V) : num_vertices(V) {
    adjacency_list.resize(V);
}

void Graph::add_edge(int u, int v) {
    adjacency_list[u].push_back(v);
}

void Graph::topological_sort_util(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
    visited[v] = true;
    for (int i : adjacency_list[v])
        if (!visited[i])
            topological_sort_util(i, visited, Stack);
    Stack.push(v);
}

std::vector<int> Graph::topological_sort() {
    std::stack<int> Stack;
    std::vector<bool> visited(num_vertices, false);

    for (int i = 0; i < num_vertices; i++)
        if (!visited[i])
            topological_sort_util(i, visited, Stack);

    std::vector<int> result;
    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }
    return result;
}

