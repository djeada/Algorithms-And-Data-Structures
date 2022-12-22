## Hamiltonian Paths

Given a graph, find all possible Hamiltonian paths in the graph. A Hamiltonian path is a path in the graph that visits every vertex exactly once.

Here is an example of a graph with 4 vertices represented as an adjacency list and the Hamiltonian paths that can be found in the graph:

```
0 --> 1, 2, 3
1 --> 0, 2, 3
2 --> 0, 1, 3
3 --> 0, 1, 2
```

An example of a Hamiltonian path in the graph is:

```
0 --> 1 --> 2 --> 3
```

## Approach

One way to find all possible Hamiltonian paths in a graph is to use a depth-first search (DFS) algorithm. The idea is to start at a given vertex and explore all the possible paths from that vertex, keeping track of the visited vertices in a separate list. If we reach a point where all the vertices in the graph have been visited, we have found a Hamiltonian path. We can then backtrack and try other paths until we have explored all the possible paths from the starting vertex.

To find all the Hamiltonian paths in the graph, we can repeat this process for each vertex in the graph as the starting vertex. This will ensure that we have explored all the possible paths in the graph.

## Complexity

The time complexity of this solution is $O(n! * n)$, where n is the number of vertices in the graph. This is because there are $n!$ (n factorial) possible Hamiltonian paths in a graph with n vertices, and it takes $O(n)$ time to explore each of these paths.

The space complexity of this solution is $O(n)$, since we only need to store the current path and the visited vertices during the search.