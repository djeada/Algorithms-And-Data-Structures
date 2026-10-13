## Topological Sort

Given a Directed Acyclic Graph (DAG), find it in topological order using topological sort algorithm. If the graph has more than one topological ordering, output any of them. The implementation raises an error if the graph contains a cycle, since no ordering exists in that case.

A Topological sort or Topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. A topological ordering is possible if and only if the graph has no directed cycles, i.e. if the graph is DAG.

## Example

```
3 --> 0 --> 6
|           ^
v           |
4 --> 1 --> +
      |
      v
      2
```

Edges: `3→0`, `3→4`, `0→6`, `4→1`, `1→2`, `1→6`.

One valid topological ordering of the above graph is $3, 0, 4, 1, 2, 6$ (vertices with no edges, such as an unused label, can appear anywhere). Orderings are generally not unique.

## Approach

The idea is to perform DFS on the graph and set the departure time of all vertices of the graph. We can keep track of whether a vertex is discovered or not using a boolean array. We will perform DFS on all undiscovered vertices and set the departure time of vertex v as the current time.

We can then print the vertices in order of their decreasing departure time in DFS, i.e., in topological order.

## Complexity

The time complexity of the topological sort algorithm is $O(V+E)$ where $V$ is the number of vertices and $E$ is the number of edges in the graph.
