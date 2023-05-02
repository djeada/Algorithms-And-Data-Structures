## Graphs

Many real-life situations involve objects that are connected in some way to other objects. Examples of such situations include:

* Underground tunnel networks
* Network of pipes
* Carbon atoms in a molecule
* Task scheduling
* Spread of a disease
* Railway map
* Cities linked by flights
* Countries and their political alliances

To model such examples, we use a data structure known as a graph.

## Graph Terminology

There is a lot of vocabulary that allows us to precisely define graphs.

A graph $G$ consists of a set $V(G)$ called vertices (or points or nodes) together with a set $E(G)$ of pairs of vertices. Each pair ${x, y} \in E(G)$ is called an edge (or link or line) of $G$.

If ${x, y} \in E(G)$, we say that $x$ and $y$ are **adjacent** to each other. The number of vertices adjacent to $v$ is called the degree of $v$. The sum of the degrees of the vertices of a graph is even.

A **path** of length $n$ in a graph is a sequence of vertices $v_1 ∼ v_2 ∼ ··· ∼ v_{n+1}$ such that $(v_i, v_{i+1}) \in E(G)$ and vertices ${v_1, v_2,...,v_{n+1}}$ are distinct.

A **cycle** of length n is a sequence of vertices $v_1 ∼ v_2 ∼ ··· ∼ v_{n+1}$ such that $v_1 = v_{n+1}, (v_i, v_{i+1}) \in E(G)$ and only vertices ${v_1, v_2,...,v_n}$ are distinct.

**The distance** between two vertices $x$ and $y$ in a graph is the length of the shortest path between them.

A **simple graph** has no self-loops (i.e., edges connected at both ends to the same vertex) and no more than one edge connecting any pair of vertices.

In a **directed graph**, an edge is an ordered pair of vertices, and hence has a direction. In directed graphs, edges are often called arcs. In **undirected graphs**, we assume that every edge can be considered as going both ways, that is, an edge between A and B can be viewed as a way from A to B and from B to A.

In a **weighted graph**, each of the edges is assigned a weight (usually a non-negative integer).

* Binary weight: A weight of 0 or 1 indicates whether or not a connection exists between two nodes.
* Numeric weight: Reflects the strength of a node's relationship to other nodes.
* Normalized weight: A numeric weight option in which all of a node's outgoing edges add up to one.

An undirected graph is **connected** if every pair of vertices is connected by a path. The concept of connection has two unique variants in directed graphs:

* A digraph is said to be **weakly connected** if there is either a path from A to B or a path from B to A for every two vertices A and B.
* If there are pathways leading both ways, we say it is **strongly connected**.

If two vertices A and B are joined by an edge e, we call them **neighbors**, and the edge linking them is called **incident** to A and B. Two edges that share a vertex (for example, one linking A and B and one connecting B and C) are referred to be **adjacent**.

## Representation of Graphs

There are multiple ways to represent graphs in computer memory. Two common methods are the adjacency matrix and the adjacency list.

### Adjacency Matrix

An **adjacency matrix** is a representation of a graph $G$ as a $V × V$ matrix $A$, where rows and columns are indexed by vertices. An element $A_{ij}$ equals 1 if vertex $i$ is adjacent to vertex $j$, and 0 otherwise. For weighted graphs, values in the array can represent the respective edge weights.

Example:

|   | A | B | C | D |
|---|---|---|---|---|
| A | 0 | 1 | 0 | 1 |
| B | 1 | 0 | 1 | 0 |
| C | 0 | 1 | 0 | 1 |
| D | 1 | 0 | 1 | 0 |

In this example, the adjacency matrix represents a simple undirected graph with vertices A, B, C, and D. The table shows the presence or absence of an edge between each pair of vertices. For example, vertex A is connected to vertices B and D, so the corresponding elements in the matrix are set to 1.

This method is suitable when the graph's vertices and edges are explicitly defined and the graph is dense (meaning there are many edges compared to the number of vertices).

### Adjacency List

An **adjacency list** is a representation of a graph $G$ using an array or a collection of $|V(G)|$ linked lists, where each list contains the neighbors of each vertex.

Example:

```
A -> [B, D]
B -> [A, C]
C -> [B, D]
D -> [A, C]
```

In this example, the adjacency list represents the same simple undirected graph as the adjacency matrix example. Each vertex has a corresponding list of its neighbors. Vertex A is connected to vertices B and D, so its list contains $[B, D]$.

The adjacency list representation is more space-efficient for sparse graphs (graphs with relatively few edges compared to the number of vertices) and allows for faster traversal of a vertex's neighbors.

## Planarity

A planar graph is one that can be drawn on a plane, such as a piece of paper, without any of its edges crossing each other. Planar graphs are essential in applications like printed circuit design, where overlapping connections are not allowed.

### Planar embedding

A planar embedding of a graph is a way to draw the graph on a plane such that no edges intersect. The fact that a graph can be drawn with crossing edges does not make it non-planar. The important aspect is whether it can be transformed into a form where no edges cross. A graph with a planar embedding is considered planar.

### Examples

Let's take a look at some examples of planar and non-planar graphs.

1. A simple cycle graph, such as a triangle, square, or pentagon, is planar because it can be drawn on a plane without any of its edges crossing each other.

2. A complete graph with four vertices (K4), which is a graph where every vertex is connected to every other vertex, is also planar. It can be drawn as a tetrahedron, with no crossing edges.

3. However, a complete graph with five vertices (K5) is non-planar. No matter how you try to draw it, there will always be at least one pair of crossing edges.

### Techniques for determining planarity

Checking if a given graph is planar can be challenging, especially for larger graphs. For small graphs, it is relatively straightforward to systematically check for possible vertex repositionings or edge deformations that would result in a planar embedding. However, for larger graphs, this process quickly becomes complex and computationally intensive.

There are some well-known theorems and algorithms that can be used to determine if a graph is planar. Two of the most famous theorems are Kuratowski's and Wagner's theorems, which are based on graph minors and subgraphs. These theorems state that a graph is planar if and only if it does not contain a subgraph that is homeomorphic to K5 (complete graph with five vertices) or K3,3 (complete bipartite graph with two sets of three vertices).

Algorithms like the Hopcroft-Tarjan planarity testing algorithm and the Boyer-Myrvold planarity testing algorithm are efficient methods for determining graph planarity. These algorithms have a linear time complexity in terms of the number of vertices and edges in the graph.

## Traversals

Traversing a graph involves visiting all of its vertices in a systematic way. We need an approach that guarantees we don't miss any edges or vertices. Unlike trees, graphs don't have a root vertex, so there's no obvious starting point for a traversal. We assume that we're given, or we randomly select, a starting vertex _i_.

Note: The order in which vertices are visited in both breadth-first search (BFS) and depth-first search (DFS) depends on the implementation. If our starting vertex A has three neighbors (C, F, and G), there's no strict rule for processing one before the others. Therefore, it's better to talk about _a_ result of these algorithms rather than _the_ result.

### Breadth-First Search (BFS)

For BFS, we need two additional containers:

* A queue called `unexplored`.
* A hash table called `visited`.

We start with the given vertex _i_. We visit its neighbors one by one, adding them to the `unexplored` queue. We then remove the initial vertex from the queue. Next, we visit the following vertex in the queue and add its neighbors to the end of the queue. We repeat this process until the queue is empty.

However, without any modifications, this method might never terminate. If there's a cycle in the graph, we could revisit a previously visited vertex, causing an infinite loop. To prevent this, we use the hash table `visited`. Initially, `visited[v] = false` for all vertices `v ∈ V(G)`. After visiting each vertex, we set its corresponding entry in `visited` to `true`.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs)

### Depth-First Search (DFS)

For DFS, we also need two additional containers:

* A stack called `unexplored`.
* A hash table called `visited`.

We start with the given vertex _i_. We add it to a stack instead of a queue. Then we remove it from the stack, mark it as visited, and examine its neighbors one by one. We add the neighbors to the stack if they haven't been visited yet. We continue this process by removing the next vertex from the stack, marking it as visited, and adding its unvisited neighbors to the stack.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dfs)

## Shortest paths

A common task when dealing with weighted graphs is to find the shortest route between two vertices, such as from vertex A to vertex B. Note that there might not be a unique shortest path, since several paths could have the same length.

### Dijkstra's Algorithm

Dijkstra's algorithm is used to compute the shortest path between a given vertex A and all other vertices. It is more convenient to compute the shortest routes from A to all vertices and then choose the relevant distance.

* **Input**: A weighted graph (a graph with values assigned to each edge) and a starting vertex A.
* **Output**: An array of distances.

We need three additional containers:

* An array called `distances` indexed by the vertices.
* A hash table called `finished`.
* Optional: a priority queue.

#### Overestimation of Shortest Paths

Distances are initialized using `distances[v] = ∞` for all vertices `v ∈ V(G)`. Then, starting with vertex A, set `distances[A] = 0`. The algorithm reduces the overestimations continually until they can no longer be reduced any further. When this occurs, the algorithm is terminated.

#### Improving Estimates

The fundamental goal is to search for shortcuts in a methodical manner. Assume that for two given vertices C and D, `distances[C] + weights[C][D] < distances[D]`. Then there is a path from A to D and then to z that has a shorter total length than the current overestimate `distances[D]`, and we can replace `distances[D]` with this better estimate.

1. Repeat the following steps as many times as there are vertices in the graph:
2. Find a vertex `v` with `finished[v]` equal to false and set it to true.
3. Iterate over each vertex `u` adjacent to `v`.
4. Update the distances array `distances[u] = distances[v] + weights[v][u]` if `distances[v] + weights[v][u] < distances[u]`.

#### Improving Time Complexity

The time complexity of the above Dijkstra's algorithm implementation is `O(n^2)`.

It can be optimized by using a priority queue to track which vertices can be marked as finished next. When choosing the next vertex `v` for evaluation, we can choose the vertex with the lowest priority from the queue. In the inner loop, while iterating over the vertex `v`'s neighbors called `u`, we modify the priority of vertex `u` in the queue to `distances[u]`.

Thus, the time complexity for Dijkstra's algorithm can be improved to `O(nlogn)` for sparse graphs.

#### Applications

* Internet packet routing
* Train-ticket reservation systems
* Driving route finders

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dijkstra)

## Bellman-Ford Algorithm

Bellman-Ford algorithm is an alternative to Dijkstra's algorithm for computing the shortest path between a given vertex A and all other vertices. It can handle negative edge weights, which makes it more robust than Dijkstra's algorithm.

* **Input**: A weighted graph and a starting vertex A.
* **Output**: An array of distances.

#### Key Differences from Dijkstra's Algorithm

* Running time is $O(V*E)$ (slower than Dijkstra's algorithm).
* In V-1 iterations, Bellman-Ford relaxes all edges simultaneously, whereas Dijkstra's algorithm chooses the edge with the lowest cost in a greedy manner.
* Does V-1 iterations + 1 to detect cycles: if the cost decreases in the V-th iteration, there is a negative loop, since all paths have been explored up to the V-1 iteration.

#### Algorithm Steps

1. Initialize the distances array by setting `distances[v] = ∞` for all vertices $v \in V(G)$ except for the starting vertex A, where `distances[A] = 0`.
2. Repeat the following steps for V-1 iterations:
  3. For each edge `(u, v)` in the graph, check if `distances[u] + weights[u][v] < distances[v]`.
  4. If true, update the distances array: `distances[v] = distances[u] + weights[u][v]`.
5. Perform the V-th iteration to detect negative cycles. If `distances[v]` decreases for any vertex v, a negative cycle exists.

#### Applications

* RIP "Routing Information Protocol"
* Currency arbitrage detection

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford)
  
## A*

A* is an informed search algorithm used for finding the shortest path between a starting vertex A and a target vertex B in a weighted graph. It combines the advantages of Dijkstra's algorithm and heuristic-based search, which allows it to be more efficient in practice.

* **Input**: A weighted graph, a starting vertex A, a target vertex B, and a heuristic function `h(v)`.
* **Output**: The shortest path from A to B.

#### Algorithm Steps

1. Initialize the distances array by setting `distances[v] = ∞` for all vertices $v \in V(G)$ except for the starting vertex A, where `distances[A] = 0`.
2. Initialize a priority queue Q and add the starting vertex A with priority `h(A`).
3. While Q is not empty:
  4. Dequeue the vertex v with the lowest priority (i.e., the smallest sum of distances[v] and the heuristic function h(v)).
  5. If v is the target vertex B, return the shortest path.
  6. For each neighbor u of vertex v:
    7. Calculate the tentative distance `tentative_distance = distances[v] + weights[v][u]`.
    8. If `tentative_distance < distances[u]`, update the distances array: `distances[u] = tentative_distance`, and update the parent of u to be v.
    9. Add vertex u to the priority queue Q with priority `distances[u] + h(u)` (if not already present, or update its priority otherwise).
10. If the target vertex B has not been reached, return that no path exists.

#### Heuristic Function

The heuristic function h(v) estimates the cost of the cheapest path from vertex v to the target vertex B. It should be chosen so that it never overestimates the cost to reach the goal. One commonly used heuristic function is the straight-line distance (Euclidean distance) between the vertex v and the target vertex B.

#### Applications

* Pathfinding in games
* Robotics and navigation

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/a_star)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/a_star)

## Minimal Spanning Trees

Suppose we have a graph that represents a network of houses. Weights represent the distances between vertices, which each represent a single house. All houses must have water, electricity, and internet, but we want the cost of installation to be as low as possible. We need to identify a subgraph of our graph with the following properties:

* There are no cycles in the graph.
* All vertices are connected.
* The total sum of weights is minimum.

Such a subgraph is called a minimal spanning tree.

### Prim's Algorithm

Prim's algorithm is a greedy vertex-based approach. A greedy algorithm is defined as one that makes a locally optimum choice at each stage, doing whatever appears to be the best at the time without considering the overall strategy.

#### Algorithm Steps

1. Initialize a tree T containing a single vertex.
2. Grow the tree T by adding a new vertex with the lowest-cost edge that connects it to the current tree.
3. Repeat step 2 until all vertices are included in the tree T.

By constantly adding the smallest edge that touches a vertex in the current tree, we produce a minimum spanning tree.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim)

### Kruskal's Algorithm

Kruskal's algorithm is a greedy edge-based approach. Our greedy choice is to take the next available edge with the smallest weight.

#### Algorithm Steps

1. Sort all edges in the graph by their weights.
2. Initialize a spanning subgraph S.
3. Add the smallest edge to S if it doesn't create a cycle.
4. Repeat step 3 until (n - 1) edges are added, where n is the number of vertices in the graph.

Two or more edges may have the same weight at times. In this scenario, the order in which the edges are picked is irrelevant. Different minimal spanning trees may be produced, but they will always have the same overall cost, which will always be the minimum.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/kruskal)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/kruskal)

### Kruskal vs Prim

Take note of the differences in the algorithms: Kruskal's approach always keeps a spanning subgraph, which only becomes a tree at the end. Prim's method, on the other hand, always maintains a tree that only becomes spanning in the end.
