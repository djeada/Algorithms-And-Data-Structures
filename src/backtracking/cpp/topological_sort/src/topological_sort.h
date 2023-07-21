#include <vector>
#include <stack>
class Graph {
  public:
    Graph(int n);
    void add_edge(int u, int v);
    std::vector<int> topological_sort();
  
  private:
    int num_vertices;
    std::vector<std::vector<int>> adjacency_list;
    void topological_sort_util(int v, std::vector<bool>& visited, std::stack<int>& Stack);
};

