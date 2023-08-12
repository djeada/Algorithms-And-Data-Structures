## Graphs

In various spheres of life, we encounter systems comprising elements intricately connected to each other. These connections manifest in diverse forms, be it physical pathways, digital networks, or abstract relationships. Graphs provide a versatile framework to represent and analyze such interconnected entities. 

Some prevalent real-world examples include:

- **Transportation Systems**:
  * **Underground Tunnel Networks**: Subways and transportation systems below the city surface.
  * **Railway Map**: Train routes connecting different towns and cities.
  * **Cities Linked by Flights**: Air travel routes between global destinations.

- **Utility Systems**:
  * **Network of Pipes**: Piping systems transporting water, gas, or oil.
  * **Electrical Grids**: Networks distributing electricity across regions.

- **Molecular Structures**:
  * **Carbon Atoms in a Molecule**: Chemical compounds and the bonds between their constituent atoms.

- **Information and Technology**:
  * **Internet**: Webpages interlinked through hyperlinks or networks of computers.
  * **Task Scheduling**: Dependencies among tasks that determine their sequence or priority.

- **Social and Epidemiological Studies**:
  * **Spread of a Disease**: Understanding how diseases propagate through populations.
  * **Social Networks**: People connected through friendships, family ties, or professional relationships.

- **Geopolitics**:
  * **Countries and their Political Alliances**: Diplomatic ties, trade partnerships, or defense pacts between nations.

Understanding these systems through the lens of graphs enables more effective analysis, optimization, and prediction of system behavior. The data structure termed "graph" in computer science and mathematics provides the tools and constructs necessary for such modeling.

## Graph Terminology

Graph theory has its own rich vocabulary that allows us to precisely discuss and define various graph structures and concepts. Here's a primer:

- **Graph**: A graph $(G)$ is a mathematical structure containing a set $(V(G))$ of **vertices** (also known as points or nodes) along with a set $(E(G))$ of pairs of these vertices. These pairs, denoted as $({x, y} \in E(G))$, are termed **edges** (or links or lines).

- **Adjacent**: If $({x, y} \in E(G))$, then $(x)$ and $(y)$ are said to be adjacent. The number of vertices adjacent to a vertex $(v)$ defines its **degree**. Interestingly, the total degrees of all vertices in a graph is always even.

- **Path**: A path of length $(n)$ is a series of vertices $(v_1 \sim v_2 \sim \dots \sim v_{n+1})$ such that $((v_i, v_{i+1}) \in E(G))$ with all vertices in the sequence being distinct.

- **Cycle**: This is a special type of path where $(v_1 = v_{n+1})$, and all other vertices from $(v_1)$ to $(v_n)$ are unique.

- **Distance**: Represents the length of the shortest path between two vertices. If you're assessing the distance between vertices $(x)$ and $(y)$, you're looking for the most direct route connecting them.

- **Simple Graph**: A graph with no self-loops (edges connected at both ends to the same vertex) and at most one edge between any two vertices.

- **Directed Graph (Digraph)**: Here, edges have direction. They are an ordered pair of vertices, often called **arcs**. In contrast, **undirected graphs** lack directionality—meaning an edge from vertex A to vertex B is the same as one from B to A.

- **Weighted Graph**: Assigns a weight to each edge, typically a non-negative integer. 
  * **Binary weight**: Represents presence (1) or absence (0) of a connection between nodes.
  * **Numeric weight**: Indicates the strength or cost of a connection.
  * **Normalized weight**: Ensures that all outgoing edges from a node sum to one, often used in probabilistic contexts.

- **Connectivity**:
  * **Undirected Graph**: A graph is termed **connected** if every vertex pair is linked by some path.
  * **Directed Graph**: Differently defined:
    - **Weakly Connected**: A path exists from vertex A to B or B to A for any vertices A and B.
    - **Strongly Connected**: Paths exist in both directions between every pair of vertices.

- **Neighbors and Incident**: Vertices A and B, if connected by an edge $(e)$, are neighbors. This edge $(e)$ is incident to both A and B. When two edges have a shared vertex (like edges from A to B and B to C), they are **adjacent**.

## Representation of Graphs in Computer Memory

Graphs, with their versatile applications in numerous domains, necessitate efficient storage and manipulation mechanisms in computer memory. Commonly, the representation choice depends on the graph's characteristics (e.g., sparsity) and the specific operations to be performed. Among the many methods available, the **adjacency matrix** and the **adjacency list** stand out as the most prevalent.

### Adjacency Matrix

An adjacency matrix offers a two-dimensional matrix approach to represent a graph \(G\). Given \(V\) vertices, we have a \(V \times V\) matrix \(A\). The matrix's rows and columns correspond to the graph's vertices, and each cell \(A_{ij}\) holds:

- `1` if there's an edge between vertex \(i\) and vertex \(j\), or
- `0` if no such edge exists.

For graphs with edge weights, \(A_{ij}\) contains the weight of the edge between vertices \(i\) and \(j\).

**Example**:

|   | A | B | C | D |
|---|---|---|---|---|
| A | 0 | 1 | 0 | 1 |
| B | 1 | 0 | 1 | 0 |
| C | 0 | 1 | 0 | 1 |
| D | 1 | 0 | 1 | 0 |

Here, the matrix indicates a graph with vertices A to D. For instance, vertex A connects with vertices B and D, hence the respective 1s in the matrix.

**Benefits**:
- Fixed-time (O(1)) edge existence checks.
- Particularly suitable for dense graphs, where the edge-to-vertex ratio is high.

**Drawbacks**:
- Consumes more space for sparse graphs.
- Traversing neighbors can be slower due to the need to check all vertices.

### Adjacency List

In contrast, the adjacency list employs a collection (often an array or a linked list) to catalog the neighbors of each vertex. Each vertex points to its own list, enumerating its direct neighbors.

**Example**:

```
A -> [B, D]
B -> [A, C]
C -> [B, D]
D -> [A, C]
```

This list reflects the same graph as our matrix example. Vertex A's neighbors, for instance, are B and D.

**Benefits**:
- Space-efficient for sparse graphs, where edges are relatively fewer.
- Facilitates faster traversal of a vertex's neighbors since the direct neighbors are listed without extraneous checks.

**Drawbacks**:
- Edge existence checks can take up to O(V) time in the worst case.
- Potentially consumes more space for dense graphs.

In practice, the choice between these (and other) representations often hinges on the graph's characteristics and the specific tasks or operations envisioned.

## Planarity

Planarity is a fundamental concept in graph theory that examines whether a graph can be sketched on a flat surface without any of its edges overlapping. This idea holds significant importance in areas such as circuit design, urban planning, and geography.

### What is a Planar Graph?

A graph is termed "planar" if there exists a representation of it on a two-dimensional plane, where its edges intersect only at their vertices and nowhere in between. The capacity to redraw a graph without overlapping edges, even if initially sketched with intersections, is crucial to its planarity.

### Planar Embedding: A Closer Look

A "planar embedding" pertains to a specific drawing or representation of a graph on a plane that doesn't feature any crossing edges. While a graph might initially be depicted with overlapping edges, it's the ability to reconfigure it into a non-overlapping form that classifies it as planar.

### Diving into Examples

To comprehend planarity more tangibly, let's explore some examples:

1. **Cycle Graphs**: Graphs like triangles, squares, or hexagons, which are simple loops or cycles, are intrinsically planar. These shapes can always be illustrated without intersecting edges.

```
A-----B
|     |
C-----D
```

3. **Complete Graph with Four Vertices (K4)**: This graph sees every vertex connected to all other vertices. Despite its complexity, K4 remains planar, bearing resemblance to a tetrahedron.

```
   A
  /|\
 B-+-C
  \|/
   D
```

3. **Complete Graph with Five Vertices (K5)**: Contrarily, K5 cannot be sketched without crossing edges, thus classifying it as non-planar.

```
      -  A  -
    /  /   \  \
  /   |     |   \
 B----+-----+---C
  \   |     |  /
    \ D-----E /
```

In the K5 graph, edges like AD and AE are overlapping with BC.

### Strategies for Assessing Planarity

While small graphs allow for manual examination for planarity, larger ones necessitate more sophisticated methods:

1. **Visual Inspection**: For simpler graphs, manual rearrangement of vertices and edges might reveal a planar embedding.

2. **Theoretical Foundations**:
    * **Kuratowski’s Theorem**: A graph is planar if and only if it lacks a subgraph that can be transformed into K5 (a complete graph with five vertices) or K3,3 (a bipartite graph with dual trios of vertices).
    * **Wagner's Theorem**: Another foundational principle focusing on graph minors and subgraphs, akin to Kuratowski's approach.

3. **Algorithms**:
    * **Hopcroft-Tarjan Algorithm**: A renowned linear-time procedure for discerning planarity.
    * **Boyer-Myrvold Planarity Testing**: Another efficient linear-time method for the same purpose.

## Traversals

Traversing a graph involves visiting all of its vertices in a systematic way. We need an approach that guarantees we don't miss any edges or vertices. Unlike trees, graphs don't have a root vertex, so there's no obvious starting point for a traversal. We assume that we're given, or we randomly select, a starting vertex _i_.

Note: The order in which vertices are visited in both breadth-first search (BFS) and depth-first search (DFS) depends on the implementation. If our starting vertex A has three neighbors (C, F, and G), there's no strict rule for processing one before the others. Therefore, it's better to talk about _a_ result of these algorithms rather than _the_ result.

### Breadth-First Search (BFS)

Breadth-First Search (BFS) is a fundamental graph traversal algorithm that explores the vertices of a graph in layers, starting from a specified source vertex. It progresses by visiting all immediate neighbors of the starting point, then the neighbors of those neighbors, and so on.

To efficiently keep track of the traversal, BFS employs two primary data structures:

* A queue, typically named `unexplored` or `queue`, to store nodes that are pending exploration.
* A hash table or a set called `visited` to ensure that we do not revisit nodes.

#### Algorithm Steps:

1. Begin from a starting vertex, _i_.
2. Mark the vertex _i_ as visited.
3. Explore each of its neighbors. If the neighbor hasn't been visited yet, mark it as visited and enqueue it in `unexplored`.
4. Dequeue the front vertex from `unexplored` and repeat step 3.
5. Continue this process until the `unexplored` queue becomes empty.

To ensure the algorithm doesn't fall into an infinite loop due to cycles in the graph, it's vital to mark nodes as visited as soon as they are enqueued. This prevents them from being added to the queue multiple times.

#### Example

```
Queue: Empty          Visited: A, B, C, D, E

   A
  / \
 B   C
 |   |
 D   E
```

In this example, BFS started at the top of the graph and worked its way down, visiting nodes in order of their distance from the starting node. The ASCII representation provides a step-by-step visualization of BFS using a queue and a list of visited nodes.

#### Applications of BFS

BFS is not only used for simple graph traversal. Its applications span multiple domains:

1. **Shortest Path**: BFS can determine the shortest path in an unweighted graph from a source to all other nodes.
2. **Connected Components**: To find all connected components in an undirected graph, you can run BFS on every unvisited node.
3. **Network Broadcasting**: BFS mirrors the propagation in broadcasting networks, where a message is forwarded to neighboring nodes, and they subsequently forward it to their neighbors.
4. **Cycle Detection**: If during BFS traversal, an already visited node is encountered (and it's not the parent of the current node in traversal), then there exists a cycle in the graph.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs)

### Depth-First Search (DFS)

Depth-First Search (DFS) is another fundamental graph traversal algorithm, but unlike BFS which traverses level by level, DFS dives deep into the graph, exploring as far as possible along each branch before backtracking.

To implement DFS, we use two main data structures:

* A stack, either implicitly using the call stack through recursion or explicitly using a data structure. This stack is responsible for tracking vertices that are to be explored.
* A hash table or set called `visited` to ensure nodes aren't revisited.

#### Algorithm Steps:

1. Begin from a starting vertex, _i_.
2. Mark vertex _i_ as visited.
3. Visit an unvisited neighbor of _i_, mark it as visited, and move to that vertex.
4. Repeat the above step until the current vertex has no unvisited neighbors.
5. Backtrack to the previous vertex and explore other unvisited neighbors.
6. Continue this process until you've visited all vertices connected to the initial start vertex.

It's crucial to mark nodes as visited as soon as they're encountered to prevent infinite loops, especially in graphs containing cycles.

#### Example

```
Stack: Empty          Visited: A, B, D, C, E

   A
  / \
 B   C
 |   |
 D   E
```

In this example, DFS explored as deep as possible along the left side (branch with B and D) of the graph before backtracking and moving to the right side (branch with C and E). The ASCII representation provides a step-by-step visualization of DFS using a stack and a list of visited nodes.

#### Applications of DFS

DFS, with its inherent nature of diving deep, has several intriguing applications:

1. **Topological Sorting**: Used in scheduling tasks, where one task should be completed before another starts.
2. **Connected Components**: To find all strongly connected components in a directed graph.
3. **Pathfinding**: DFS can be employed to find a path between two nodes, though it might not guarantee the shortest path.
4. **Cycle Detection**: If during DFS traversal, an already visited node is encountered (and it's not the direct parent of the current node in traversal), then there's a cycle in the graph.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dfs)

## Shortest paths

A common task when dealing with weighted graphs is to find the shortest route between two vertices, such as from vertex A to vertex B. Note that there might not be a unique shortest path, since several paths could have the same length.

### Dijkstra's Algorithm

Dijkstra's algorithm is a cornerstone in graph theory, designed to compute the shortest path from a designated starting vertex `A` to all other vertices in a weighted graph. The algorithm works by iteratively selecting the vertex with the shortest tentative distance from the start, and relaxing all its edges.

#### Input & Output

* **Input**: A weighted graph (where each edge has a value associated with it, representing the cost or distance) and a starting vertex `A`.
* **Output**: An array `distances` where `distances[v]` represents the shortest path from `A` to vertex `v`.

#### Containers and Data Structures:

* An array `distances`, initialized to `∞` for all vertices except the starting vertex which is initialized to `0`.
* A hash table `finished` to keep track of vertices for which the shortest path has been determined.
* A priority queue to efficiently select the vertex with the smallest tentative distance.

#### Algorithm Steps:

1. Initialize `distances[A] = 0` and `distances[v] = ∞` for all other vertices `v`.
2. For each vertex `v` in the graph:
   * Select the vertex `u` with the minimum `distances[u]` and `finished[u]` being false.
   * Set `finished[u]` to true.
   * For each neighbor `w` of `u`:
     * If `distances[u] + weights[u][w] < distances[w]`, then update `distances[w] = distances[u] + weights[u][w]`.

## Step by Step Example

Imagine we have the same graph with vertices A, B, C, D, and E. The edges and weights are:

```
A-B: 4
A-C: 2
C-B: 1
B-D: 5
C-D: 8
C-E: 10
D-E: 2
```

The adjacency matrix for the graph is:

```
   A  B  C  D  E
A [0, 4, 2, ∞, ∞]
B [4, 0, 1, 5, ∞]
C [2, 1, 0, 8, 10]
D [∞, 5, 8, 0, 2]
E [∞, ∞, 10, 2, 0]
```

Dijkstra's algorithm starting from A would proceed as follows:

Step 1: Initialize the shortest paths from A to all other nodes as infinite (∞) and A to A as 0.

```
A: 0
B: ∞
C: ∞
D: ∞
E: ∞
```

Step 2: Start with A. Update all its neighbors:

```
A: 0
B: 4
C: 2
D: ∞
E: ∞
```

Step 3: Pick the smallest unvisited vertex, which is C. Update its neighbors:

```
A: 0
B: 3 (via C)
C: 2
D: ∞
E: 10
```

Step 4: Next smallest unvisited vertex is B. Update its neighbors:

```
A: 0
B: 3
C: 2
D: 8 (via B)
E: 10
```

Step 5: Next smallest unvisited vertex is D. Update its neighbors:

```
A: 0
B: 3
C: 2
D: 8
E: 10
```

Step 6: E remains, but no update is possible.

Final shortest paths from A:

```
A: 0
B: 3
C: 2
D: 8
E: 10
```

In the adjacency matrix, the shortest path distances from A can be represented as:

```
A [0]
B [3]
C [2]
D [8]
E [10]
```

#### Optimizing Time Complexity:

While the basic implementation of Dijkstra's algorithm runs in `O(n^2)` time, its time complexity can be significantly reduced using a priority queue. By leveraging the queue to extract the vertex with the minimum distance, the complexity becomes `O((V+E) log V)` for a graph with `V` vertices and `E` edges.

#### Notable Applications:

* **Internet Routing**: It's used to find the most efficient path for data packets.
* **Navigation Systems**: Mapping software like Google Maps or Waze use variations of Dijkstra to compute driving directions.
* **Network Design**: In telecommunication networks, it helps in determining paths with minimum cost.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dijkstra)

### Bellman-Ford Algorithm

The Bellman-Ford algorithm is a graph search algorithm that finds the shortest path from a single source vertex to all vertices in a weighted graph. Unlike Dijkstra's algorithm, which works only for graphs with non-negative weights, Bellman-Ford is versatile enough to handle graphs in which some of the edge weights are negative.

#### Input & Output:

* **Input**: A weighted graph (where each edge has an associated cost or distance) and a starting vertex `A`.
* **Output**: An array `distances` where `distances[v]` represents the shortest path from `A` to vertex `v`.

#### Containers and Data Structures:

* An array `distances`, initialized to `∞` for all vertices except the starting vertex which is initialized to `0`.
* A predecessor array, often used to reconstruct the shortest path.

#### Algorithm Steps:

1. Initialize `distances[A] = 0` for the starting vertex and `distances[v] = ∞` for all other vertices.
2. Repeat `V-1` times (where `V` is the number of vertices):
   * For each edge `(u, v)` with weight `w`:
     * If `distances[u] + w < distances[v]`, then update `distances[v] = distances[u] + w` and update the predecessor of `v` to `u`.
3. For each edge `(u, v)` with weight `w`:
   * If `distances[u] + w < distances[v]`, there is a negative weight cycle, and the shortest path is not well-defined.

## Step by Step Example

Consider a graph with vertices A, B, C, D, and E. The edges and weights are:

```
A-B: 6
A-C: 7
B-C: 8
B-D: -4
B-E: 5
C-E: -3
D-A: 2
D-C: 7
E-E: 9
```

The adjacency matrix for the graph would be:

```
   A  B  C  D  E
A [0, 6, 7, ∞, ∞]
B [∞, 0, 8, -4, 5]
C [∞, ∞, 0, ∞, -3]
D [2, ∞, 7, 0, ∞]
E [∞, ∞, ∞, ∞, 9]
```

Now, let's run Bellman-Ford algorithm starting from vertex A:

Initialization:

```
dist[A] = 0
dist[B] = dist[C] = dist[D] = dist[E] = ∞
```

For each vertex, update the distance to every other vertex.

Iteration 1:

Based on A's neighbors:

```
dist[B] = 6
dist[C] = 7
```

Iteration 2:

Based on B's neighbors:

```
dist[C] = 7 (No change)
dist[D] = 6 - 4 = 2
dist[E] = 11
```

Based on C's neighbors:

```
dist[E] = 7 - 3 = 4
```

Iteration 3:

Based on D's neighbors:

```
dist[A] = 2 + 2 = 4
dist[C] = 2 + 7 = 9 (But C's distance is already 7, so no change)
```

Iteration 4:

No changes this round.

Final distances from A:

```
dist[A] = 0
dist[B] = 6
dist[C] = 7
dist[D] = 2
dist[E] = 4
```

#### Special Characteristics:

* **Handling Negative Weights**: One of the major advantages of the Bellman-Ford algorithm is its ability to handle negative weights, though it cannot handle negative weight cycles (cycles in the graph where the overall sum of the edge weights is negative).

* **Time Complexity**: The basic implementation of the Bellman-Ford algorithm has a time complexity of `O(V*E)`, where `V` is the number of vertices and `E` is the number of edges. This makes it less efficient than Dijkstra's algorithm for some scenarios, but its ability to handle negative weights is a distinct advantage.

#### Applications:

* **Arbitrage Opportunities**: Used in financial markets to detect arbitrage opportunities in currency exchange.
* **Computer Networking**: To determine the best path to forward data packets.
* **Game Development**: In games that involve terrain and movement costs.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford)
  
### A* (A-Star) Algorithm

A* is an informed search algorithm, or a best-first search, widely used in pathfinding and graph traversal. The idea is to navigate the graph by choosing the path that promises the shortest distance to the goal at each step, using heuristic knowledge.

#### Input & Output:

* **Input**: A graph, a start vertex `A`, a goal vertex `B`, and a heuristic function `h(v)`, which estimates the cost from vertex `v` to goal vertex `B`.
* **Output**: The shortest path from `A` to `B`, if one exists.

#### Containers and Data Structures:

* `g(n)`: The cost of the cheapest path from the start vertex to vertex `n` currently known.
* `h(n)`: Heuristic estimate of the cost from vertex `n` to the goal.
* `f(n) = g(n) + h(n)`: Estimated total cost from start to goal through vertex `n`.
* An `openSet`, initialized with the starting vertex, represents the set of nodes to be evaluated.
* A `closedSet` representing the nodes already evaluated.
* A `cameFrom` data structure, which keeps track of the best path as the algorithm progresses.

#### Algorithm Steps:

1. Add the starting node to the `openSet`.
2. While the `openSet` is not empty:
   * Get the node `current` in `openSet` having the lowest `f(n)`.
   * If `current` is the goal node, reconstruct the path and return it.
   * Remove `current` from `openSet` and add to `closedSet`.
   * For each neighbor `n` of `current`:
     * If `n` is in `closedSet`, skip it.
     * If `n` is not in `openSet`, add it and compute its `g(n)`, `h(n)`, and `f(n)`.
     * If a better path to `n` is found, update `cameFrom` for `n`.
3. If the algorithm terminates without finding the goal, no path exists.

#### Step by Step Example

Suppose we have a graph with vertices A, B, C, D, and E. The edges and weights are:

```
A-B: 1
A-C: 2
B-D: 3
C-D: 2
D-E: 1
```

Additionally, let's assume we have the following heuristic values estimating the distance from each node to the target node E:

```
h(A) = 3
h(B) = 2
h(C) = 2
h(D) = 1
h(E) = 0
```

The adjacency matrix for the graph would look like:

```
   A  B  C  D  E
A [0, 1, 2, ∞, ∞]
B [∞, 0, ∞, 3, ∞]
C [∞, ∞, 0, 2, ∞]
D [∞, ∞, ∞, 0, 1]
E [∞, ∞, ∞, ∞, 0]
```

Now, let's run the A* algorithm starting from vertex A with the goal of reaching vertex E:

Initialization:

```
g(A) = 0
f(A) = g(A) + h(A) = 0 + 3 = 3

OpenList = [A]
ClosedList = []

While OpenList is not empty:

    Choose the node n in the OpenList with the lowest f(n).
    If n is the goal node, we're done.
    Otherwise, move n from the OpenList to the ClosedList.
```

Expand Node A:

```
A -> B : f(B) = g(A) + cost(A, B) + h(B) = 0 + 1 + 2 = 3
A -> C : f(C) = g(A) + cost(A, C) + h(C) = 0 + 2 + 2 = 4
The node with the lowest f value is B. So, expand B next.
```

Expand Node B:

```
B -> D : f(D) = g(B) + cost(B, D) + h(D) = 1 + 3 + 1 = 5
Now, C has the lowest f value. So, expand C next.
```

Expand Node C:

```
C -> D : f(D) = g(C) + cost(C, D) + h(D) = 2 + 2 + 1 = 5 (No improvement on the path to D)
```

Expand Node D:

```
D -> E : f(E) = g(D) + cost(D, E) + h(E) = 5 + 1 + 0 = 6
E is the goal node. The algorithm stops here.
```

The path found by A* is: `A -> B -> D -> E` with a total cost of 5.

#### Special Characteristics:

* **Optimality**: When using an admissible heuristic (one that never overestimates the true cost), A* is guaranteed to return the shortest possible path.
* **Efficiency**: The efficiency of A* depends on the heuristic. A good heuristic will explore fewer nodes than a poor one.

#### Applications:

* **Video Games**: Widely used in games to determine the path a character should take to reach a destination.
* **Robotics**: For navigation and movement planning.
* **Geographical Maps**: To determine the shortest path between two locations.

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

Prim's Algorithm is a greedy algorithm used to find a minimum spanning tree (MST) for a weighted undirected graph. The goal of the algorithm is to include every vertex in the graph into a tree while minimizing the total edge weights.

#### Input & Output:

* **Input**: A connected, undirected graph with weighted edges.
* **Output**: A minimum spanning tree, which is a subset of the edges that connects all the vertices together without any cycles and with the minimum possible total edge weight.

#### Containers and Data Structures:

* An array `key[]` to store weights. Initially, `key[v] = ∞` for all `v` except the first vertex.
* A boolean array `mstSet[]` to keep track of vertices included in MST. Initially, all values are `false`.
* An array `parent[]` to store the MST.

#### Algorithm Steps:

1. Start with an arbitrary node as the initial MST node.
2. While there are nodes not yet included in the MST:
   * Pick a vertex `v` not in the MST with the smallest key value.
   * Include `v` in `mstSet[]`.
   * For each neighboring vertex `u` of `v` not in the MST:
     * If the weight of edge `(u, v)` is less than `key[u]`, update `key[u]` and set `parent[u]` to `v`.
3. The MST is formed using the `parent[]` array.

#### Step by Step Example

Consider a simple graph with vertices A, B, C, D, and E. The edges with weights are:

```
A-B: 2
A-C: 3
B-D: 1
B-E: 3
C-D: 4
C-E: 5
D-E: 2
```

The adjacency matrix for the graph would look like:

```
   A  B  C  D  E
A [0, 2, 3, ∞, ∞]
B [2, 0, ∞, 1, 3]
C [3, ∞, 0, 4, 5]
D [∞, 1, 4, 0, 2]
E [∞, 3, 5, 2, 0]
```

Now, let's run Prim's algorithm starting from vertex A:

Initialization:

```
Chosen vertex: A
Vertices not included: B, C, D, E
```

Step-by-Step Execution:

Starting from vertex A, the closest vertex is B with a weight of 2.

```
Chosen vertices: A, B
Vertices not included: C, D, E
```

From the chosen vertices A and B, the closest vertex is D (from B) with a weight of 1.

```
Chosen vertices: A, B, D
Vertices not included: C, E
```

Continuing from the chosen vertices, the closest vertex is E (from D) with a weight of 2.

```
Chosen vertices: A, B, D, E
Vertices not included: C
```

From the chosen vertices, the closest remaining vertex is C (from A) with a weight of 3.

```
Chosen vertices: A, B, D, E, C
And with that, all vertices have been included in the Minimum Spanning Tree (MST) using Prim's algorithm.
```

The edges selected by Prim's algorithm in this case are: A-B, B-D, D-E, and A-C, with a total weight of 8.

#### Special Characteristics:

* **Greedy Nature**: At every step, it considers the smallest weight edge to add to the MST.
* **Complexity**: With a priority queue, its time complexity can be reduced to `O(E log V)`, where `E` is the number of edges and `V` is the number of vertices.

#### Applications:

* **Network Design**: Used in scenarios like designing a telecommunication network to ensure all cities are connected while reducing the total length of cable.
* **Transportation Networks**: Building roads, tunnels, or bridges while minimizing costs.
* **Utility Networks**: Designing water, electrical, or internet infrastructure to connect all houses or buildings at a minimum cost.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim)

### Kruskal's Algorithm
Kruskal's Algorithm is another method to find the minimum spanning tree (MST) of a connected, undirected graph with weighted edges. It works by sorting all the edges from the lowest to highest weight, and then picking edges one by one, ensuring that the inclusion of each edge doesn't form a cycle.

#### Input & Output:

* **Input**: A connected, undirected graph with weighted edges.
* **Output**: A minimum spanning tree composed of a subset of the edges.

#### Containers and Data Structures:

* A list or priority queue to sort all the edges based on their weights.
* A disjoint-set (or union-find) structure to help in cycle detection and prevention.

#### Algorithm Steps:

1. Sort all the edges in increasing order based on their weights.
2. Initialize an empty forest (a set of trees).
3. Iterate through the sorted edges. For each edge `(u, v)`:
   * If `u` and `v` are in different trees (or disjoint sets), add the edge to the forest and union `u` and `v` to be in the same set.
   * If they are in the same set, skip the edge as it would form a cycle.
4. The forest formed after processing all edges is the MST.

#### Step by Step Example

Consider a simple graph with vertices A, B, C, D, and E. The edges with weights are:

```
A-B: 2
A-C: 3
B-D: 1
B-E: 3
C-D: 4
C-E: 5
D-E: 2
```

Here is the adjacency matrix for the graph:

```
   A  B  C  D  E
A [0, 2, 3, ∞, ∞]
B [2, 0, ∞, 1, 3]
C [3, ∞, 0, 4, 5]
D [∞, 1, 4, 0, 2]
E [∞, 3, 5, 2, 0]
```

Kruskal's algorithm sorts all the edges in ascending order and starts picking them from the smallest, ensuring that a cycle isn't formed.

Step-by-Step Execution:

```
Sort all edges:
    B-D: 1
    A-B: 2
    D-E: 2
    A-C: 3
    B-E: 3
    C-D: 4
    C-E: 5
```

Pick the smallest edge, B-D with a weight of 1.

```
Included edges: B-D
Total weight: 1
```

The next edge, A-B with a weight of 2, does not form a cycle. Include it.

```
Included edges: B-D, A-B
Total weight: 3
```

The edge D-E with a weight of 2 is chosen next and does not form a cycle.

```
Included edges: B-D, A-B, D-E
Total weight: 5
```

The edge A-C with a weight of 3 does not form a cycle. Include it.

```
Included edges: B-D, A-B, D-E, A-C
Total weight: 8
```

The next edge, B-E would form a cycle with the previously chosen edges, so it's skipped.

Continuing, C-D would also form a cycle, so it's skipped.

The edge C-E would also form a cycle. At this point, all the vertices are connected, so the algorithm terminates.

The final Minimum Spanning Tree formed by Kruskal's algorithm includes the edges: B-D, A-B, D-E, and A-C with a total weight of 8.

#### Special Characteristics:

* **Greedy Nature**: The algorithm always picks the smallest edge that doesn't cause a cycle.
* **Complexity**: With a good disjoint-set implementation, the time complexity is close to `O(E log E)` (or `O(E log V)`), where `E` is the number of edges and `V` is the number of vertices.

#### Applications:

* **Network Design**: Useful for designing telecommunication or computer networks to ensure all nodes are connected while minimizing total wire length or latency.
* **Spatial Networks**: Such as connecting homes to utility sources in a way that minimizes the total infrastructure cost.
* **Transportation Networks**: Like road systems to connect all locations with the shortest possible roads.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/kruskal)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/kruskal)
