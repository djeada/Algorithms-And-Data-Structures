## K-Colorable Configurations

Given a graph G and an integer k, find all the k-colorable configurations of G. A k-colorable configuration of a graph G is a way of coloring the vertices of G using k colors such that no two adjacent vertices are colored with the same color.

## Approach

The find_k_colorable_configurations function uses a depth-first search (DFS) algorithm to find all the k-colorable configurations of the given graph G. The DFS algorithm works by recursively trying all possible colorings of the vertices of G.

At each step, the function tries all k colors on the current vertex, and checks if the color can be assigned to the vertex without violating the k-colorability condition (i.e., no two adjacent vertices are colored with the same color). If the color can be assigned, the function continues the search with the next vertex, and if it reaches the last vertex, it adds the current configuration to the list of configurations. If it cannot find a valid color for the current vertex, it backtracks to the previous vertex

## Time and Space Complexity

The time complexity of the find_k_colorable_configurations function is $O(k^n)$, where $n$ is the number of vertices in the graph G. This is because the function tries all $k$ colors for each of the n vertices in the graph.

The space complexity of the function is $O(n)$, because the colors array used to store the colors of the vertices has n elements, and the configurations list used to store the configurations has at most $k^n$ elements.
