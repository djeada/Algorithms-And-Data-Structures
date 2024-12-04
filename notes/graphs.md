## Graphs

In many areas of life, we come across systems where elements are deeply interconnected—whether through physical routes, digital networks, or abstract relationships. Graphs offer a flexible way to represent and make sense of these connections.

Some real-world examples include:

- Underground tunnel networks (subways and transportation systems below the city surface)
- Railway maps (train routes connecting different towns and cities)
- Cities linked by flights (air travel routes between global destinations)
- Networks of pipes (piping systems transporting water, gas, or oil)
- Electrical grids (networks distributing electricity across regions)
- Carbon atoms in a molecule (chemical compounds and the bonds between their constituent atoms)
- Internet (webpages interlinked through hyperlinks or networks of computers)
- Task scheduling (dependencies among tasks that determine their sequence or priority)
- Spread of a disease (understanding how diseases propagate through populations)
- Social networks (people connected through friendships, family ties, or professional relationships)
- Countries and their political alliances (diplomatic ties, trade partnerships, or defense pacts between nations)

Viewing these systems as graphs allows for deeper analysis, better optimization, and more accurate predictions of their behavior. In computer science and mathematics, graphs serve as a powerful data structure that provides the tools needed for this kind of modeling.

### Graph Terminology

Graph theory has its own language, full of terms that make it easier to talk about and define different types of graphs and their features. Here's an explanation of some important terms:

- A **graph** $G$ is a mathematical structure consisting of a set $V(G)$ of vertices (also known as points or nodes) and a set $E(G)$ of pairs of these vertices. These pairs, denoted as $\{x, y\} \in E(G)$, are called edges (or links or lines).
- If $\{x, y\} \in E(G)$, then $x$ and $y$ are said to be **adjacent**. The number of vertices adjacent to a vertex $v$ defines its degree. Interestingly, the total degrees of all vertices in a graph is always even.
- A **path** of length $n$ is a series of vertices $v_1 \sim v_2 \sim \dots \sim v_{n+1}$ such that $(v_i, v_{i+1}) \in E(G)$ with all vertices in the sequence being distinct.
- A **cycle** is a special type of path where $v_1 = v_{n+1}$, and all other vertices from $v_1$ to $v_n$ are unique.
- Distance represents the length of the shortest path between two vertices. When assessing the distance between vertices $x$ and $y$, you are looking for the most direct route connecting them.
- A **simple graph** is a graph with no self-loops (edges connected at both ends to the same vertex) and at most one edge between any two vertices.
- In a **directed graph** (digraph), edges have direction. They are an ordered pair of vertices, often called arcs. In contrast, undirected graphs lack directionality, meaning an edge from vertex $A$ to vertex $B$ is the same as one from $B$ to $A$.
- A **weighted graph** assigns a weight to each edge, typically a non-negative integer. A binary weight represents the presence (1) or absence (0) of a connection between nodes. A numeric weight indicates the strength or cost of a connection. A normalized weight ensures that all outgoing edges from a node sum to one, often used in probabilistic contexts.
- In terms of **connectivity**, an undirected graph is termed connected if every vertex pair is linked by some path. In a directed graph, weakly connected means a path exists from vertex $A$ to $B$ or $B$ to $A$ for any vertices $A$ and $B$. Strongly connected means paths exist in both directions between every pair of vertices.
- **Vertices** $A$ and $B$, if connected by an edge $e$, are neighbors. This edge $e$ is incident to both $A$ and $B$. When two edges share a vertex (like edges from $A$ to $B$ and $B$ to $C$), they are adjacent.
- The concept of an **isolated vertex** refers to a vertex with no edges connected to it. This means the vertex has a degree of zero since it is not adjacent to any other vertex.
- **Subgraphs** are smaller graphs formed from a subset of the vertices and edges of a larger graph. If $G$ is a graph, a subgraph $H$ is a graph such that the vertex set of $H$ is a subset of the vertex set of $G$ and the edge set of $H$ is a subset of the edge set of $G$.
- A **spanning tree** of a graph $G$ is a subgraph that includes all the vertices of $G$ and is a single connected tree. A spanning tree has exactly $|V| - 1$ edges where $|V|$ is the number of vertices in the graph.
- **Bipartite graphs** are graphs whose vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. Formally, a graph $G$ is bipartite if there exists a partition $V(G) = V_1 \cup V_2$ where $V_1$ and $V_2$ are disjoint and every edge connects a vertex in $V_1$ to a vertex in $V_2$.
- A **complete graph** is a simple graph in which there is an edge between every pair of vertices. If a complete graph has $n$ vertices, it is denoted by $K_n$ and has $\frac{n(n-1)}{2}$ edges.
- **Planar graphs** can be drawn on a plane without any edges crossing. A graph is planar if it can be embedded in the plane, meaning it can be drawn on a flat surface such that its edges intersect only at their endpoints.
- The **Eulerian path** is a path in a graph that visits every edge exactly once. If such a path exists and starts and ends at different vertices, it is an Eulerian path. If it starts and ends at the same vertex, it is an Eulerian circuit. A graph has an Eulerian circuit if and only if all vertices have an even degree, and it is connected. A graph has an Eulerian path if it has exactly zero or two vertices of odd degree, and it is connected.
- The **Hamiltonian path** is a path in a graph that visits every vertex exactly once. If such a path exists and starts and ends at different vertices, it is a Hamiltonian path. If it starts and ends at the same vertex, it is a Hamiltonian circuit. Determining whether a Hamiltonian path or circuit exists in a graph is a well-known NP-complete problem.
- **Graph isomorphism** refers to a condition where two graphs $G$ and $H$ are considered isomorphic if there is a one-to-one correspondence between their vertex sets and their edge sets that preserves adjacency. In other words, $G$ and $H$ are structurally identical but may have different vertex and edge labels.
- **Degree sequence** is a list of the degrees of the vertices in a graph, usually written in non-increasing order. The degree sequence is a graph invariant, meaning it is the same for any isomorphic graphs.
- **Graph coloring** is the assignment of labels (colors) to vertices of a graph such that no two adjacent vertices share the same color. The minimum number of colors needed to color a graph $G$ is known as its chromatic number.
- **Tree** is a connected, acyclic graph. In a tree, any two vertices are connected by exactly one path, and adding any edge to a tree will create a cycle. Trees have several important properties and applications in computer science, particularly in data structures and algorithms.
- **Forest** is a disjoint set of trees. It is an acyclic graph that may consist of multiple disconnected components, each being a tree.
- **Cut vertices and cut edges** refer to vertices and edges whose removal increases the number of connected components of the graph. A cut vertex (or articulation point) is a vertex that, if removed, would split the graph into two or more disconnected subgraphs. A cut edge (or bridge) is an edge that, if removed, would increase the number of connected components.
- **Matching** in a graph is a set of edges without common vertices. A maximum matching is a matching that contains the largest possible number of edges. If every vertex of the graph is incident to exactly one edge of the matching, it is called a perfect matching.
- **Independent set** is a set of vertices in a graph, no two of which are adjacent. The size of the largest independent set is called the independence number of the graph.
- **Clique** is a subset of vertices such that every two distinct vertices are adjacent. The size of the largest clique in a graph is called the clique number.
- **Vertex cover** is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. The size of the smallest vertex cover is called the vertex cover number.
- **Dominating set** is a set of vertices such that each vertex in the graph is either in the dominating set or adjacent to a vertex in the dominating set. The size of the smallest dominating set is called the domination number.
- **Planarity testing** determines whether a graph can be drawn in a plane without edge crossings. Kuratowski's theorem provides a criterion for planarity based on the presence of subgraphs homeomorphic to $K_5$ (complete graph on five vertices) or $K_{3,3}$ (complete bipartite graph on six vertices, three in each set).
- **Graph algorithms** encompass a variety of procedures and techniques used to solve problems related to graphs. Examples include depth-first search (DFS), breadth-first search (BFS), Dijkstra's algorithm for shortest paths, Kruskal's and Prim's algorithms for minimum spanning trees, and the Bellman-Ford algorithm for shortest paths in graphs with negative weights.

### Representation of Graphs in Computer Memory

Graphs, with their versatile applications in numerous domains, necessitate efficient storage and manipulation mechanisms in computer memory. The choice of representation often depends on the graph's characteristics, such as sparsity, and the specific operations to be performed. Among the various methods available, the adjacency matrix and the adjacency list are the most prevalent.

#### Adjacency Matrix

An adjacency matrix represents a graph $G$ as a two-dimensional matrix. Given $V$ vertices, it utilizes a $V \times V$ matrix $A$. The rows and columns correspond to the graph's vertices, and each cell $A_{ij}$ holds:

- `1` if there is an edge between vertex $i$ and vertex $j$
- `0` if no such edge exists

For graphs with edge weights, $A_{ij}$ contains the weight of the edge between vertices $i$ and $j$.

Example:

|   | A | B | C | D |
|---|---|---|---|---|
| A | 0 | 1 | 0 | 1 |
| B | 1 | 0 | 1 | 0 |
| C | 0 | 1 | 0 | 1 |
| D | 1 | 0 | 1 | 0 |

Here, the matrix indicates a graph with vertices A to D. For instance, vertex A connects with vertices B and D, hence the respective 1s in the matrix.

**Benefits**:

- Fixed-time ($O(1)$) edge existence checks.
- Particularly suitable for dense graphs, where the edge-to-vertex ratio is high.

**Drawbacks**:

- Consumes more space for sparse graphs.
- Traversing neighbors can be slower due to the need to check all vertices.

### Adjacency List

An adjacency list uses a collection (often an array or a linked list) to catalog the neighbors of each vertex. Each vertex points to its own list, enumerating its direct neighbors.

Example:

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

- Edge existence checks can take up to $O(V)$ time in the worst case.
- Potentially consumes more space for dense graphs.

In practice, the choice between these (and other) representations often hinges on the graph's characteristics and the specific tasks or operations envisioned.

### Planarity

Planarity is a fundamental concept in graph theory that examines whether a graph can be drawn on a flat surface without any of its edges overlapping. This idea holds significant importance in areas such as circuit design, urban planning, and geography.

#### What is a Planar Graph?

A graph is considered "planar" if there exists a representation of it on a two-dimensional plane where its edges intersect only at their vertices and nowhere in between. Being able to redraw a graph without any edges crossing, even if it starts out messy with overlaps, is what shows if it’s planar or not.

#### Planar Embedding

A "planar embedding" refers to a way of drawing a graph on a plane so that none of its edges cross each other. If a graph is first drawn with overlapping edges, it’s considered planar if you can rearrange it so no edges cross.

#### Examples

To understand planarity better, let's explore some examples:

1. **Cycle Graphs**: Graphs like triangles, squares, or hexagons, which are simple loops or cycles, are intrinsically planar. These shapes can always be illustrated without intersecting edges.

```
A-----B
|     |
C-----D
```

2. **Complete Graph with Four Vertices ($K_4$)**: This graph has every vertex connected to all other vertices. Despite its complexity, $K_4$ remains planar and resembles a tetrahedron.

```
#
   A--------
  / \      |
 B---C     |
  \ /      |
   D--------
```

3. **Complete Graph with Five Vertices ($K_5$)**: Unlike $K_4$, $K_5$ cannot be sketched without crossing edges, thus classifying it as non-planar.

```
#
      -  A  -
    /  /   \  \
  /   |     |   \
 B----+-----+---C
  \   |     |  /
    \ D-----E /
```

In the $K_5$ graph, edges like AD and AE overlap with BC.

#### Strategies for Assessing Planarity

- The **planarity** of a graph refers to whether it can be drawn on a flat surface without any edges crossing each other.
- **Small graphs** can be tested for planarity by manually rearranging their vertices and edges to check if a crossing-free drawing is possible.
- **Kuratowski's theorem** states that a graph is planar if it does not contain a subgraph that can be transformed into $K_5$ (a graph with five vertices all connected to each other) or $K_{3,3}$ (a graph with two groups of three vertices, where every vertex in one group connects to every vertex in the other).
- **$K_5$** is a complete graph with five vertices where every pair of vertices has a direct edge connecting them.
- **$K_{3,3}$** is a bipartite graph where two sets of three vertices are connected such that each vertex in the first set is connected to all vertices in the second set, with no edges within the same set.
- **Wagner’s theorem** provides an alternative way to determine planarity, stating that a graph is planar if it does not have $K_5$ or $K_{3,3}$ as a "minor." A minor is a smaller graph formed by deleting edges, deleting vertices, or merging connected vertices.
- For **larger graphs**, manual testing becomes impractical, and planarity algorithms are often used instead.
- The **Hopcroft-Tarjan algorithm** is a linear-time method for testing planarity. It uses depth-first search to efficiently decide if a graph can be drawn without crossing edges.
- The **Boyer-Myrvold algorithm** is another linear-time approach that tests planarity and can also provide an embedding of the graph (a specific way to draw it without crossings) if it is planar.
- Both **algorithms** are widely used in computer science for applications that involve networks, circuit design, and data visualization, where planarity helps simplify complex structures.

### Traversals

- When we **traverse** a graph, we visit its vertices in an organized way to make sure we don’t miss any vertices or edges.
- Graphs, unlike **trees**, don’t have a single starting point like a root. This means we either need to be given a starting vertex or pick one randomly.
- Let’s say we start from a specific vertex, like **$i$**. From there, the traversal explores all connected vertices according to the rules of the chosen method.
- In both **breadth-first search (BFS)** and **depth-first search (DFS)**, the order of visiting vertices depends on how the algorithm is implemented.
- For example, if the starting vertex **A** has three neighbors, like $C, F,$ and $G$, the algorithm doesn’t have a fixed rule for which neighbor to visit first. It could choose any of them based on the way it’s programmed.
- Because of this flexibility, we talk about **a result** of BFS or DFS, rather than **the result**, since different implementations might visit vertices in different orders.

#### Breadth-First Search (BFS)

Breadth-First Search (BFS) is a fundamental graph traversal algorithm that explores the vertices of a graph in layers, starting from a specified source vertex. It progresses by visiting all immediate neighbors of the starting point, then the neighbors of those neighbors, and so on.

To efficiently keep track of the traversal, BFS employs two primary data structures:

* A queue, typically named `unexplored` or `queue`, to store nodes that are pending exploration.
* A hash table or a set called `visited` to ensure that we do not revisit nodes.

##### Algorithm Steps

1. Begin from a starting vertex, $i$.
2. Mark the vertex $i$ as visited.
3. Explore each of its neighbors. If the neighbor hasn't been visited yet, mark it as visited and enqueue it in `unexplored`.
4. Dequeue the front vertex from `unexplored` and repeat step 3.
5. Continue this process until the `unexplored` queue becomes empty.

To ensure the algorithm doesn't fall into an infinite loop due to cycles in the graph, it could be useful to mark nodes as visited as soon as they are enqueued. This prevents them from being added to the queue multiple times.

##### Example

```
Queue: Empty          Visited: A, B, C, D, E

   A
  / \
 B   C
 |   |
 D   E
```

In this example, BFS started at the top of the graph and worked its way down, visiting nodes in order of their distance from the starting node. The ASCII representation provides a step-by-step visualization of BFS using a queue and a list of visited nodes.

##### Applications

BFS is not only used for simple graph traversal. Its applications span multiple domains:

1. BFS can determine the **shortest path** in an unweighted graph from a source to all other nodes.
2. To find all **connected components** in an undirected graph, you can run BFS on every unvisited node.
3. BFS mirrors the propagation in broadcasting networks, where a message is forwarded to neighboring nodes, and they subsequently forward it to their neighbors.
4. If during BFS traversal, an already visited node is encountered (and it's not the parent of the current node in traversal), then there exists a cycle in the graph.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs)

#### Depth-First Search (DFS)

Depth-First Search (DFS) is another fundamental graph traversal algorithm, but unlike BFS which traverses level by level, DFS dives deep into the graph, exploring as far as possible along each branch before backtracking.

To implement DFS, we use two main data structures:

* A stack, either implicitly using the call stack through recursion or explicitly using a data structure. This stack is responsible for tracking vertices that are to be explored.
* A hash table or set called `visited` to ensure nodes aren't revisited.

##### Algorithm Steps

1. Begin from a starting vertex, $i$.
2. Mark vertex $i$ as visited.
3. Visit an unvisited neighbor of $i$, mark it as visited, and move to that vertex.
4. Repeat the above step until the current vertex has no unvisited neighbors.
5. Backtrack to the previous vertex and explore other unvisited neighbors.
6. Continue this process until you've visited all vertices connected to the initial start vertex.

Marking nodes as visited as soon as you encounter them is important to avoid infinite loops, particularly in graphs with cycles.

##### Example

```
Stack: Empty          Visited: A, B, D, C, E

   A
  / \
 B   C
 |   |
 D   E
```

In this example, DFS explored as deep as possible along the left side (branch with B and D) of the graph before backtracking and moving to the right side (branch with C and E). The ASCII representation provides a step-by-step visualization of DFS using a stack and a list of visited nodes.

##### Applications

DFS, with its inherent nature of diving deep, has several intriguing applications:

1. Topological Sorting is used in scheduling tasks, where one task should be completed before another starts.
2. To find all strongly connected components in a directed graph.
3. DFS can be employed to find a path between two nodes, though it might not guarantee the shortest path.
4. If during DFS traversal, an already visited node is encountered (and it's not the direct parent of the current node in traversal), then there's a cycle in the graph.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dfs)

### Shortest paths

A common task when dealing with weighted graphs is to find the shortest route between two vertices, such as from vertex $A$ to vertex $B$. Note that there might not be a unique shortest path, since several paths could have the same length.

#### Dijkstra's Algorithm

- **Dijkstra's algorithm** is a method used to find the shortest paths from a starting vertex to all other vertices in a weighted graph.
- A **weighted graph** is a graph where each edge has a number, called a weight, which typically represents cost, distance, or time.
- The algorithm begins at a specific **starting vertex**, often labeled as $A$, and calculates the shortest path to every other vertex.
- Dijkstra's algorithm maintains a **tentative distance** for each vertex, which represents the current shortest distance from the start to that vertex.
- The process involves **selecting the vertex** with the smallest tentative distance that hasn’t been fully processed yet.
- After selecting a vertex, the algorithm **relaxes all its edges**. Relaxing an edge means checking if the current shortest path to the neighboring vertex can be improved by going through the selected vertex.
- This process continues until all vertices have been processed, resulting in the shortest paths from the starting vertex to all others in the graph.
- Dijkstra’s algorithm works only for graphs with **non-negative weights**, as negative weights can lead to incorrect results.

##### Input & Output

* **Input**: A weighted graph (where each edge has a value associated with it, representing the cost or distance) and a starting vertex `A`.
* **Output**: An array `distances` where `distances[v]` represents the shortest path from `A` to vertex `v`.

##### Containers and Data Structures

* An array `distances`, initialized to `∞` for all vertices except the starting vertex which is initialized to `0`.
* A hash table `finished` to keep track of vertices for which the shortest path has been determined.
* A priority queue to efficiently select the vertex with the smallest tentative distance.

##### Algorithm Steps

I. Initialize `distances[A] = 0` and `distances[v] = ∞` for all other vertices `v`.

II. For each vertex `v` in the graph:

- Select the vertex `u` with the minimum `distances[u]` and `finished[u]` being false.
- Set `finished[u]` to true.
- For each neighbor `w` of `u`:
  - If `distances[u] + weights[u][w] < distances[w]`, then update `distances[w] = distances[u] + weights[u][w]`.

##### Step by Step Example

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

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 4 | 2 | ∞ | ∞ |
| **B** | 4 | 0 | 1 | 5 | ∞ |
| **C** | 2 | 1 | 0 | 8 | 10 |
| **D** | ∞ | 5 | 8 | 0 | 2 |
| **E** | ∞ | ∞ | 10 | 2 | 0 |

Dijkstra's algorithm starting from A would proceed as follows:

I. Initialize the shortest paths from A to all other nodes as infinite (∞) and A to A as 0.

```
A: 0
B: ∞
C: ∞
D: ∞
E: ∞
```

II. Start with A. Update all its neighbors:

```
A: 0
B: 4
C: 2
D: ∞
E: ∞
```

III. Pick the smallest unvisited vertex, which is C. Update its neighbors:

```
A: 0
B: 3 (via C)
C: 2
D: ∞
E: 10
```

IV. Next smallest unvisited vertex is B. Update its neighbors:

```
A: 0
B: 3
C: 2
D: 8 (via B)
E: 10
```

V. Next smallest unvisited vertex is D. Update its neighbors:

```
A: 0
B: 3
C: 2
D: 8
E: 10
```

VI. E remains, but no update is possible.

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

##### Optimizing Time Complexity

While the basic implementation of Dijkstra's algorithm runs in `O(n^2)` time, its time complexity can be significantly reduced using a priority queue. By leveraging the queue to extract the vertex with the minimum distance, the complexity becomes `O((V+E) log V)` for a graph with `V` vertices and `E` edges.

##### Applications

* It's used in internet routing to find the most efficient path for data packets.
* Mapping software like Google Maps or Waze use variations of Dijkstra to compute driving directions.
* In telecommunication networks, it helps in determining paths with minimum cost.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dijkstra)

#### Bellman-Ford Algorithm

- **Bellman-Ford algorithm** is a method for finding the shortest paths from a single starting vertex to all other vertices in a weighted graph.
- Unlike **Dijkstra’s algorithm**, Bellman-Ford can handle **negative edge weights**, making it more flexible for certain types of graphs.
- The algorithm works by **repeatedly relaxing all edges** in the graph. Relaxing an edge means updating the shortest known distance to a vertex if a shorter path is found through another vertex.
- The algorithm performs this **relaxation process $V-1$ times**, where $V$ is the number of vertices in the graph. This ensures that all possible shortest paths are accounted for.
- After $V-1$ relaxations, the algorithm performs an additional pass to check for **negative weight cycles**. If any edge can still be relaxed, it means the graph contains a cycle with a negative total weight.
- Bellman-Ford is slower than Dijkstra’s algorithm, with a time complexity of **$O(V \times E)$**, where $E$ is the number of edges, making it less efficient for large graphs with many edges.

##### Input & Output

* **Input**: A weighted graph (where each edge has an associated cost or distance) and a starting vertex `A`.
* **Output**: An array `distances` where `distances[v]` represents the shortest path from `A` to vertex `v`.

##### Containers and Data Structures

* An array `distances`, initialized to `∞` for all vertices except the starting vertex which is initialized to `0`.
* A predecessor array, often used to reconstruct the shortest path.

##### Algorithm Steps

I. Initialize `distances[A] = 0` for the starting vertex and `distances[v] = ∞` for all other vertices.

II. Repeat `V-1` times (where `V` is the number of vertices):

  - For each edge `(u, v)` with weight `w`:
    - If `distances[u] + w < distances[v]`, then update `distances[v] = distances[u] + w` and update the predecessor of `v` to `u`.

III. For each edge `(u, v)` with weight `w`:

  - If `distances[u] + w < distances[v]`, there is a negative weight cycle, and the shortest path is not well-defined.

##### Step by Step Example

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

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 6 | 7 | ∞ | ∞ |
| **B** | ∞ | 0 | 8 | -4 | 5 |
| **C** | ∞ | ∞ | 0 | ∞ | -3 |
| **D** | 2 | ∞ | 7 | 0 | ∞ |
| **E** | ∞ | ∞ | ∞ | ∞ | 9 |

Now, let's run Bellman-Ford algorithm starting from vertex A:

Initialization:

```
dist[A] = 0
dist[B] = dist[C] = dist[D] = dist[E] = ∞
```

For each vertex, update the distance to every other vertex.

I. Iteration 1:

Based on A's neighbors:

```
dist[B] = 6
dist[C] = 7
```

II. Iteration 2:

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

III. Iteration 3:

Based on D's neighbors:

```
dist[A] = 2 + 2 = 4
dist[C] = 2 + 7 = 9 (But C's distance is already 7, so no change)
```

IV. Iteration 4:

No changes this round.

Final distances from A:

```
dist[A] = 0
dist[B] = 6
dist[C] = 7
dist[D] = 2
dist[E] = 4
```

##### Special Characteristics

* One of the major advantages of the Bellman-Ford algorithm is its ability to handle negative weights, though it cannot handle negative weight cycles (cycles in the graph where the overall sum of the edge weights is negative).
* The basic implementation of the Bellman-Ford algorithm has a time complexity of `O(V*E)`, where `V` is the number of vertices and `E` is the number of edges. This makes it less efficient than Dijkstra's algorithm for some scenarios, but its ability to handle negative weights is a distinct advantage.

##### Applications

* Used in financial markets to detect arbitrage opportunities in currency exchange.
* To determine the best path to forward data packets.
* In games that involve terrain and movement costs.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford)
  
#### A* (A-Star) Algorithm

- **A*** is an informed search algorithm commonly used for **pathfinding** and **graph traversal** tasks.
- It is considered a **best-first search algorithm** because it prioritizes exploring the most promising paths first, based on a combination of actual and estimated costs.
- The algorithm uses two main components for decision-making at each step:
- **$g(n)$**: The actual cost from the start node to the current node $n$.
- **$h(n)$**: A **heuristic** function that estimates the cost from $n$ to the goal node.
- The **total cost** function, $f(n) = g(n) + h(n)$, guides the algorithm. It evaluates both the known path cost and the estimated remaining cost to reach the goal.
- At each step, A* selects the node with the **lowest $f(n)$** value from the priority queue for exploration.
- The **heuristic $h(n)$** must be **admissible**, meaning it never overestimates the actual cost to the goal, ensuring the algorithm finds an optimal path.
- A* stops when it either reaches the **goal node** or exhausts all possible paths (if no solution exists).
- It is efficient for many applications because it **balances exploration and goal-direction**, but its performance heavily depends on the quality of the heuristic function.
- A* is widely used in areas like game development, robotics, and navigation systems due to its flexibility and effectiveness in solving real-world pathfinding problems.

##### Input & Output

* **Input**: A graph, a start vertex `A`, a goal vertex `B`, and a heuristic function `h(v)`, which estimates the cost from vertex `v` to goal vertex `B`.
* **Output**: The shortest path from `A` to `B`, if one exists.

##### Algorithm Steps

I. Add the starting node to the `openSet`.

II. While the `openSet` is not empty:

- Get the node `current` in `openSet` having the lowest `f(n)`.
- If `current` is the goal node, reconstruct the path and return it.
- Remove `current` from `openSet` and add to `closedSet`.
- For each neighbor `n` of `current`:
  - If `n` is in `closedSet`, skip it.
  - If `n` is not in `openSet`, add it and compute its `g(n)`, `h(n)`, and `f(n)`.
  - If a better path to `n` is found, update `cameFrom` for `n`.

III. If the algorithm terminates without finding the goal, no path exists.

##### Used Data Structures

* `g(n)`: The cost of the cheapest path from the start vertex to vertex `n` currently known.
* `h(n)`: Heuristic estimate of the cost from vertex `n` to the goal.
* `f(n) = g(n) + h(n)`: Estimated total cost from start to goal through vertex `n`.
* An `openSet`, initialized with the starting vertex, represents the set of nodes to be evaluated.
* A `closedSet` representing the nodes already evaluated.
* A `cameFrom` data structure, which keeps track of the best path as the algorithm progresses.

##### Step by Step Example

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

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 1 | 2 | ∞ | ∞ |
| **B** | ∞ | 0 | ∞ | 3 | ∞ |
| **C** | ∞ | ∞ | 0 | 2 | ∞ |
| **D** | ∞ | ∞ | ∞ | 0 | 1 |
| **E** | ∞ | ∞ | ∞ | ∞ | 0 |

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

I. Expand Node A:

```
A -> B : f(B) = g(A) + cost(A, B) + h(B) = 0 + 1 + 2 = 3
A -> C : f(C) = g(A) + cost(A, C) + h(C) = 0 + 2 + 2 = 4
The node with the lowest f value is B. So, expand B next.
```

II. Expand Node B:

```
B -> D : f(D) = g(B) + cost(B, D) + h(D) = 1 + 3 + 1 = 5
Now, C has the lowest f value. So, expand C next.
```

III. Expand Node C:

```
C -> D : f(D) = g(C) + cost(C, D) + h(D) = 2 + 2 + 1 = 5 (No improvement on the path to D)
```

IV. Expand Node D:

```
D -> E : f(E) = g(D) + cost(D, E) + h(E) = 5 + 1 + 0 = 6
E is the goal node. The algorithm stops here.
```

The path found by A* is: `A -> B -> D -> E` with a total cost of 5.

##### Special Characteristics

* When using an admissible heuristic (one that never overestimates the true cost), A* is guaranteed to return the shortest possible path.
* The efficiency of A* depends on the heuristic. A good heuristic will explore fewer nodes than a poor one.

##### Applications

* Widely used in games to determine the path a character should take to reach a destination.
* For navigation and movement planning.
* To determine the shortest path between two locations.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/a_star)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/a_star)

### Minimal Spanning Trees

Suppose we have a graph that represents a network of houses. Weights represent the distances between vertices, which each represent a single house. All houses must have water, electricity, and internet, but we want the cost of installation to be as low as possible. We need to identify a subgraph of our graph with the following properties:

* There are no cycles in the graph.
* All vertices are connected.
* The total sum of weights is minimum.

Such a subgraph is called a minimal spanning tree.

#### Prim's Algorithm

- **Prim's Algorithm** is used to find a **minimum spanning tree (MST)**, which is a subset of a graph that connects all its vertices with the smallest total edge weight.
- The algorithm works on a **weighted undirected graph**, meaning the edges have weights, and the direction of edges doesn’t matter.
- It starts with an **arbitrary vertex** and grows the tree by adding one edge at a time.
- At each step, the algorithm chooses the **smallest weight edge** that connects a vertex already in the tree to a vertex outside the tree. This is why it’s considered a **greedy algorithm**.
- The process continues until **all vertices** are included in the tree.
- Prim’s algorithm ensures the resulting tree is **connected**, meaning there’s a path between any two vertices, and the total weight is minimized.
- The algorithm can be efficiently implemented using a **priority queue** (like a min-heap) to keep track of the smallest edge weights, resulting in a time complexity of **$O(E \log V)$**, where $E$ is the number of edges and $V$ is the number of vertices.

##### Input & Output

* **Input**: A connected, undirected graph with weighted edges.
* **Output**: A minimum spanning tree, which is a subset of the edges that connects all the vertices together without any cycles and with the minimum possible total edge weight.

##### Containers and Data Structures

* An array `key[]` to store weights. Initially, `key[v] = ∞` for all `v` except the first vertex.
* A boolean array `mstSet[]` to keep track of vertices included in MST. Initially, all values are `false`.
* An array `parent[]` to store the MST.

##### Algorithm Steps

I. Start with an arbitrary node as the initial MST node.

II. While there are nodes not yet included in the MST:

- Pick a vertex `v` not in the MST with the smallest key value.
- Include `v` in `mstSet[]`.
- For each neighboring vertex `u` of `v` not in the MST:
  - If the weight of edge `(u, v)` is less than `key[u]`, update `key[u]` and set `parent[u]` to `v`.

III.. The MST is formed using the `parent[]` array.

##### Step by Step Example

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

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 2 | 3 | ∞ | ∞ |
| **B** | 2 | 0 | ∞ | 1 | 3 |
| **C** | 3 | ∞ | 0 | 4 | 5 |
| **D** | ∞ | 1 | 4 | 0 | 2 |
| **E** | ∞ | 3 | 5 | 2 | 0 |

Now, let's run Prim's algorithm starting from vertex A:

Initialization:

```
Chosen vertex: A
Vertices not included: B, C, D, E
```

Step-by-Step Execution:

I. Starting from vertex A, the closest vertex is B with a weight of 2.

```
Chosen vertices: A, B
Vertices not included: C, D, E
```

II. From the chosen vertices A and B, the closest vertex is D (from B) with a weight of 1.

```
Chosen vertices: A, B, D
Vertices not included: C, E
```

III. Continuing from the chosen vertices, the closest vertex is E (from D) with a weight of 2.

```
Chosen vertices: A, B, D, E
Vertices not included: C
```

IV. From the chosen vertices, the closest remaining vertex is C (from A) with a weight of 3.

```
Chosen vertices: A, B, D, E, C
And with that, all vertices have been included in the Minimum Spanning Tree (MST) using Prim's algorithm.
```

The edges selected by Prim's algorithm in this case are: A-B, B-D, D-E, and A-C, with a total weight of 8.

##### Special Characteristics

* At every step, it considers the smallest weight edge to add to the MST.
* With a priority queue, its time complexity can be reduced to `O(E log V)`, where `E` is the number of edges and `V` is the number of vertices.

##### Applications

* Used in scenarios like designing a telecommunication network to ensure all cities are connected while reducing the total length of cable.
* Building roads, tunnels, or bridges while minimizing costs.
* Designing water, electrical, or internet infrastructure to connect all houses or buildings at a minimum cost.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim)

#### Kruskal's Algorithm

- **Kruskal's Algorithm** is a method for finding a **minimum spanning tree (MST)** in a connected, undirected graph with weighted edges.
- The algorithm starts by **sorting all edges** in the graph by weight, from smallest to largest.
- It then processes the edges in order, **adding each edge to the MST** if it does not create a cycle.
- To check for **cycles**, the algorithm uses a **disjoint-set data structure** (also known as Union-Find). This structure keeps track of which vertices are in the same connected component.
- If two vertices connected by an edge are in the same component, adding that edge would form a cycle, so the edge is skipped.
- The process continues until the MST contains **$V-1$ edges**, where $V$ is the number of vertices in the graph.
- Kruskal’s algorithm is particularly efficient for **sparse graphs** (graphs with relatively few edges) and has a time complexity of **$O(E \log E)$**, where $E$ is the number of edges. This complexity arises from sorting the edges and performing Union-Find operations.

##### Input & Output

* **Input**: A connected, undirected graph with weighted edges.
* **Output**: A minimum spanning tree composed of a subset of the edges.

##### Containers and Data Structures

* A list or priority queue to sort all the edges based on their weights.
* A disjoint-set (or union-find) structure to help in cycle detection and prevention.

##### Algorithm Steps

I. Sort all the edges in increasing order based on their weights.

II. Initialize an empty forest (a set of trees).

III. Iterate through the sorted edges. For each edge `(u, v)`:

  - If `u` and `v` are in different trees (or disjoint sets), add the edge to the forest and union `u` and `v` to be in the same set.
  - If they are in the same set, skip the edge as it would form a cycle.

IV. The forest formed after processing all edges is the MST.

##### Step by Step Example

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

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 2 | 3 | ∞ | ∞ |
| **B** | 2 | 0 | ∞ | 1 | 3 |
| **C** | 3 | ∞ | 0 | 4 | 5 |
| **D** | ∞ | 1 | 4 | 0 | 2 |
| **E** | ∞ | 3 | 5 | 2 | 0 |

Kruskal's algorithm sorts all the edges in ascending order and starts picking them from the smallest, ensuring that a cycle isn't formed.

Step-by-Step Execution:

I. Sort all edges:

``` 
B-D: 1
A-B: 2
D-E: 2
A-C: 3
B-E: 3
C-D: 4
C-E: 5
```

II. Pick the smallest edge, B-D with a weight of 1.

```
Included edges: B-D
Total weight: 1
```

III. The next edge, A-B with a weight of 2, does not form a cycle. Include it.

```
Included edges: B-D, A-B
Total weight: 3
```

IV. The edge D-E with a weight of 2 is chosen next and does not form a cycle.

```
Included edges: B-D, A-B, D-E
Total weight: 5
```

V. The edge A-C with a weight of 3 does not form a cycle. Include it.

```
Included edges: B-D, A-B, D-E, A-C
Total weight: 8
```

VI. The next edge, B-E would form a cycle with the previously chosen edges, so it's skipped.

VII. Continuing, C-D would also form a cycle, so it's skipped.

VIII. The edge C-E would also form a cycle. At this point, all the vertices are connected, so the algorithm terminates.

The final Minimum Spanning Tree formed by Kruskal's algorithm includes the edges: B-D, A-B, D-E, and A-C with a total weight of 8.

##### Special Characteristics

* The algorithm always picks the smallest edge that doesn't cause a cycle.
* With a good disjoint-set implementation, the time complexity is close to `O(E log E)` (or `O(E log V)`), where `E` is the number of edges and `V` is the number of vertices.

##### Applications

* Useful for designing telecommunication or computer networks to ensure all nodes are connected while minimizing total wire length or latency.
* Such as connecting homes to utility sources in a way that minimizes the total infrastructure cost.
* Like road systems to connect all locations with the shortest possible roads.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/kruskal)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/kruskal)
