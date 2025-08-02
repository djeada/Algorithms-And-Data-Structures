TODO:
- topological sort

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

Viewing these systems as graphs lets us dig deeper into how they work, optimize them better, and even predict their behavior more accurately. In fields like computer science and math, graphs are a powerful tool that helps us model and understand these systems effectively.

### Graph Terminology

Graph theory has its own language, full of terms that make it easier to talk about and define different types of graphs and their features. Here's an explanation of some important terms:

- A *graph* $G$ is a mathematical structure composed of vertices (also known as nodes or points), forming the set $V(G)$, and edges (also called links or lines), forming the set $E(G)$. Each edge connects two distinct vertices, denoted by pairs $\{x, y\} \in E(G)$.
- When two vertices, say $x$ and $y$, share an edge, they are termed *adjacent*. The count of adjacent vertices to any vertex $v$ defines its *degree*. Notably, summing the degrees of all vertices in a graph always yields an even number.
- A *path* of length $n$ is a sequence of vertices $v_1 \sim v_2 \sim dots \sim v_{n+1}$, each consecutively connected by edges, with no vertex repeated.
- A *cycle* is a special path where the first and last vertices are identical, forming a closed loop, and no other vertex is repeated within the cycle.
- *Distance* in a graph refers to the shortest path length between two vertices. Essentially, it measures how closely two vertices are connected through the minimal number of edges.
- A *simple graph* is characterized by the absence of self-loops—edges that connect vertices to themselves—and contains no more than one edge between any two distinct vertices.
- A *directed graph* (or digraph) includes edges with specific directions, known as arcs, represented as ordered pairs of vertices. Conversely, an undirected graph treats connections symmetrically, meaning the connection between vertices $A$ and $B$ is identical to the one from $B$ to $A$.
- A *weighted graph* assigns numerical values (weights) to edges, typically non-negative integers. Binary weights (0 or 1) indicate connection presence or absence; numeric weights quantify costs or strengths; and normalized weights scale outgoing connections from a vertex to sum to one, commonly used in probability models.
- Regarding *connectivity*, an undirected graph is *connected* if there's a path linking any pair of vertices. For directed graphs, *weak connectivity* means at least one directional path exists between vertex pairs, while *strong connectivity* demands a path in both directions between every vertex pair.
- Two vertices connected by an edge are called *neighbors*, and the edge itself is said to be *incident* to these vertices. Edges sharing a common vertex are described as *adjacent* edges.
- An *isolated vertex* refers to a vertex with no connecting edges, hence having a degree of zero and no neighbors.
- *Subgraphs* are smaller structures derived from selecting subsets of vertices and edges from a larger graph. Formally, a subgraph $H$ of a graph $G$ has vertex and edge sets entirely contained within those of $G$.
- A *spanning tree* of a graph $G$ is a subgraph that connects all vertices using the minimal number of edges required, specifically $|V| - 1$ edges, and contains no cycles.
- *Bipartite graphs* partition vertices into two distinct groups such that no edges connect vertices within the same group. Formally, a graph is bipartite if it can be split into sets $V_1$ and $V_2$ where each edge links vertices across the two sets only.
- A *complete graph*, denoted by $K_n$, is a simple graph with an edge between every possible pair of vertices. Thus, a complete graph with $n$ vertices contains exactly $\frac{n(n-1)}{2}$ edges.
- *Planar graphs* are graphs that can be drawn on a flat plane without edge intersections except at vertices. Such graphs can be embedded clearly onto a two-dimensional surface without visual confusion.
- An *Eulerian path* travels through each edge exactly once. If this path forms a loop, starting and ending at the same vertex, it becomes an *Eulerian circuit*. For a graph to have an Eulerian circuit, all vertices must have even degrees and the graph must be connected; an Eulerian path exists if exactly zero or two vertices have odd degrees.
- A *Hamiltonian path* traverses every vertex exactly once. If such a path returns to its starting vertex, it becomes a *Hamiltonian circuit*. The decision about the existence of Hamiltonian paths or circuits is notably difficult and classified as an NP-complete problem.
- *Graph isomorphism* describes two graphs, $G$ and $H$, that are structurally identical despite potentially different vertex or edge labels. Formally, an isomorphism is a one-to-one correspondence preserving adjacency between their vertex sets.
- The *degree sequence* of a graph lists all vertex degrees, typically ordered from highest to lowest. This sequence serves as a graph invariant, meaning it is consistent across isomorphic graphs.
- *Graph coloring* involves assigning different labels or "colors" to adjacent vertices. The minimum number of colors required to color a graph without adjacent vertices sharing the same color is called the chromatic number.
- A *tree* is a connected graph with no cycles. It possesses a unique path between every pair of vertices, and adding any extra edge will inevitably create a cycle. Trees are important in many computational applications, especially algorithms and data structures.
- A *forest* consists of multiple disconnected trees. It's essentially an acyclic graph that isn't necessarily connected, serving as a generalization of trees.
- Regarding *connectivity*, a vertex whose removal increases the number of disconnected parts is an *articulation vertex* (or cut vertex). Similarly, an edge whose removal disconnects the graph is called a *bridge* or cut edge.
- A *matching* in a graph is a set of edges with no shared vertices. A *maximum matching* is the largest possible such set.
- An *independent set* is a vertex set with no edges connecting any two vertices. The largest size of such a set is known as the independence number.
- A *clique* is a subset of vertices in which each vertex connects directly to all others. The largest clique size is called the clique number.
- A *vertex cover* is a collection of vertices such that every graph edge touches at least one vertex from the collection.
- A *clique* is the opposite concept—vertices in a clique are all mutually adjacent. The largest possible clique size defines the clique number.
- *Planarity testing* checks if a graph can be drawn without intersecting edges. Kuratowski’s theorem states that non-planarity occurs precisely when a graph contains subgraphs similar to $K_5$ (complete graph of five vertices) or $K_{3,3}$ (complete bipartite graph).
- Common algorithms on graphs include methods for finding shortest paths (Bellman-Ford, Dijkstra's algorithm), discovering minimum spanning trees (Kruskal’s, Prim’s algorithm), and graph traversal (DFS, BFS). These algorithms help solve important graph-related problems in computing and operations research.

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

- Fixed-time ( $O(1)$ ) edge existence checks.
- Particularly suitable for dense graphs, where the edge-to-vertex ratio is high.

**Drawbacks**:

- Consumes more space for sparse graphs.
- Traversing neighbors can be slower due to the need to check all vertices.

#### Adjacency List

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

The choice between these (and other) representations often depends on the graph's characteristics and the specific tasks or operations envisioned.

### Planarity

Planarity examines whether a graph can be drawn on a flat surface (a plane) without any of its edges crossing. This idea holds significant importance in areas such as circuit design, urban planning, and geography.

#### What is a Planar Graph?

A graph is considered **planar** if there exists a representation (also called a drawing) of it on a two-dimensional plane where its edges intersect only at their vertices and nowhere else. Even if a graph is initially drawn with overlaps or crossings, it may still be planar if it is possible to **redraw** (or **rearrange**) it so that no edges intersect in the interior of the drawing.

An important theoretical result related to planarity is **Kuratowski’s Theorem**, which states that a graph is planar if and only if it does not contain a subgraph that is a subdivision of either $K_5$ (the complete graph on five vertices) or $K_{3,3}$ (the complete bipartite graph on six vertices, partitioned into sets of three).  

#### Planar Embedding

A **planar embedding** refers to a specific way of drawing a graph on a plane so that none of its edges cross each other in the interior. If such a crossing-free drawing exists, the graph is planar. A related fact is **Euler’s Formula** for planar graphs:

$$|V| - |E| + |F| = 2$$

where:

- $|V|$ is the number of vertices,
- $|E|$ is the number of edges,
- $|F|$ is the number of faces (including the "outer" infinite face).

#### Examples

I. **Cycle Graphs**  

Simple cycle graphs (triangles, squares, pentagons, hexagons, etc.) are planar because you can easily draw them without any edges crossing. In the square cycle graph $C_4$ example below, there are no intersecting edges:

```
A-----B
|     |
C-----D
```

II. **Complete Graph with Four Vertices ($K_4$)**

This graph has every vertex connected to every other vertex. Despite having 6 edges, $K_4$ is planar. Its planar drawing can resemble a tetrahedron (triangular pyramid) flattened onto a plane:

```
   A
  / \
 B---C
  \ /
   D
```

III. **Complete Graph with Five Vertices ($K_5$)**

$K_5$ has every one of its five vertices connected to the other four, making a total of 10 edges. This graph is **non-planar**: no matter how you try to arrange the vertices and edges, there will always be at least one pair of edges that must cross. A rough sketch illustrating its inherent crossing is shown below:

```
   A
  /|\
 / | \
B--+--C
 \ | /
  \|/
   D
   |
   E
```

Attempting to avoid one crossing in $K_5$ inevitably forces another crossing elsewhere, confirming its non-planarity.

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

- **Dijkstra's algorithm** is a method to find the shortest paths from a starting vertex to all other vertices in a weighted graph.
- A **weighted graph** is one where each edge has a numerical value (cost, distance, or time).
- The algorithm starts at a **starting vertex**, often labeled **A**, and computes the shortest path to every other vertex.
- It keeps a **tentative distance** for each vertex, representing the current known shortest distance from the start.
- It repeatedly **selects the vertex** with the smallest tentative distance that hasn't been finalized (or "finished") yet.
- Once a vertex is selected, the algorithm **relaxes all its edges**: it checks if going through this vertex offers a shorter path to its neighbors.
- This continues until all vertices are processed, yielding the shortest paths from the starting vertex to every other vertex.
- **Important**: Dijkstra’s algorithm requires **non-negative edge weights**, or else results can be incorrect.

##### Algorithm Steps

**Input**

- A weighted graph where each edge has a cost or distance
- A starting vertex `A`

**Output**

- An array `distances` where `distances[v]` is the shortest distance from `A` to vertex `v`

**Containers and Data Structures**

- An array `distances`, initialized to `∞` for all vertices except `A`, which is set to `0`
- A hash table `finished` to mark vertices with confirmed shortest paths
- A priority queue to efficiently select the vertex with the smallest current distance

**Steps**

I. Initialize `distances[A]` to `0`

II. Initialize `distances[v]` to `∞` for every other vertex `v`

III. While not all vertices are marked as finished

- Select vertex `u` with the smallest `distances[u]` among unfinished vertices
- Mark `finished[u]` as `true`
- For each neighbor `w` of `u`, if `distances[u] + weights[u][w]` is less than `distances[w]`, update `distances[w]` to `distances[u] + weights[u][w]`

##### Step by Step Example

Consider a graph with vertices A, B, C, D, and E, and edges:

```
A-B: 4
A-C: 2
C-B: 1
B-D: 5
C-D: 8
C-E: 10
D-E: 2
```

The adjacency matrix looks like this (∞ means no direct edge):

|   |  A |  B |  C |  D |  E |
|---|----|----|----|----|----|
| **A** |  0 |  4 |  2 |  ∞ |  ∞ |
| **B** |  4 |  0 |  1 |  5 |  ∞ |
| **C** |  2 |  1 |  0 |  8 | 10 |
| **D** |  ∞ |  5 |  8 |  0 |  2 |
| **E** |  ∞ |  ∞ | 10 |  2 |  0 |

**Starting from A**, here’s how Dijkstra’s algorithm proceeds:

I. Initialize all distances with ∞ except A=0:

```
A: 0
B: ∞
C: ∞
D: ∞
E: ∞
```

II. From A (distance 0), update neighbors:

```
A: 0
B: 4  (via A)
C: 2  (via A)
D: ∞
E: ∞
```

III. Pick the smallest unvisited vertex (C with distance 2). Update its neighbors:

- B can be updated to 3 if 2 + 1 < 4  
- D can be updated to 10 if 2 + 8 < ∞  
- E can be updated to 12 if 2 + 10 < ∞

```
A: 0
B: 3  (via C)
C: 2
D: 10 (via C)
E: 12 (via C)
```

IV. Pick the next smallest unvisited vertex (B with distance 3). Update its neighbors:

- D becomes 8 if 3 + 5 < 10  
- E remains 12 (no direct edge from B to E)

```
A: 0
B: 3
C: 2
D: 8  (via B)
E: 12
```

V. Pick the next smallest unvisited vertex (D with distance 8). Update its neighbors:

- E becomes 10 if 8 + 2 < 12

```
A: 0
B: 3
C: 2
D: 8
E: 10 (via D)
```

VI. The only remaining vertex is E (distance 10). No further updates are possible.

**Final shortest paths from A**:

```
A: 0
B: 3
C: 2
D: 8
E: 10
```

##### Optimizing Time Complexity

- A basic (array-based) implementation of Dijkstra's algorithm runs in **O(n^2)** time.
- Using a priority queue (min-heap) to select the vertex with the smallest distance reduces the complexity to **O((V+E) log V)**, where **V** is the number of vertices and **E** is the number of edges.

##### Applications

- **Internet routing** protocols use it to determine efficient paths for data packets.
- **Mapping software** (e.g., Google Maps, Waze) employ variations of Dijkstra to compute driving routes.
- **Telecommunication networks** use it to determine paths with minimal cost.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dijkstra)

#### Bellman-Ford Algorithm

- **Bellman-Ford algorithm** is a method for finding the shortest paths from a single starting vertex to all other vertices in a weighted graph.
- Unlike **Dijkstra’s algorithm**, Bellman-Ford can handle **negative edge weights**, making it more flexible for certain types of graphs.
- The algorithm works by **repeatedly relaxing all edges** in the graph. Relaxing an edge means updating the current shortest distance to a vertex if a shorter path is found via another vertex.
- The algorithm performs this **relaxation process** exactly **$V - 1$ times**, where $V$ is the number of vertices. This ensures that every possible shortest path is discovered.
- After completing $V - 1$ relaxations, the algorithm does one more pass to detect **negative weight cycles**. If any edge can still be relaxed, a negative cycle exists and no finite shortest path is defined.
- Bellman-Ford’s time complexity is **$O(V \times E)$**, which is generally slower than Dijkstra’s algorithm for large graphs.

##### Algorithm Steps

**Input**

- A weighted graph with possible negative edge weights
- A starting vertex `A`

**Output**

- An array `distances` where `distances[v]` represents the shortest path from `A` to vertex `v`

**Containers and Data Structures**

- An array `distances`, set to `∞` for all vertices except the start vertex (set to `0`)
- A `predecessor` array to help reconstruct the actual shortest path

**Steps**

I. Initialize `distances[A]` to `0` and `distances[v]` to `∞` for all other vertices `v`

II. Repeat `V - 1` times

- For every edge `(u, v)` with weight `w`, if `distances[u] + w < distances[v]`, update `distances[v]` to `distances[u] + w` and `predecessor[v]` to `u`

III. Check for negative cycles by iterating over all edges `(u, v)` again

- If `distances[u] + w < distances[v]` for any edge, a negative weight cycle exists

##### Step by Step Example

We have vertices A, B, C, D, and E. The edges and weights (including a self-loop on E):

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

Adjacency matrix (∞ means no direct edge):

|   |  A |  B |  C |  D |  E |
|---|----|----|----|----|----|
| **A** |  0 |  6 |  7 |  ∞ |  ∞ |
| **B** |  ∞ |  0 |  8 | -4 |  5 |
| **C** |  ∞ |  ∞ |  0 |  ∞ | -3 |
| **D** |  2 |  ∞ |  7 |  0 |  ∞ |
| **E** |  ∞ |  ∞ |  ∞ |  ∞ |  9 |

**Initialization**:

```
dist[A] = 0
dist[B] = ∞
dist[C] = ∞
dist[D] = ∞
dist[E] = ∞
```

**Iteration 1** (relax edges from A):

```
dist[B] = 6
dist[C] = 7
```

**Iteration 2** (relax edges from B, then C):

```
dist[D] = 2        (6 + (-4))
dist[E] = 11       (6 + 5)
dist[E] = 4        (7 + (-3))  // C → E is better
```

**Iteration 3** (relax edges from D):

```
dist[A] = 4        (2 + 2)
(No update for C since dist[C]=7 is already < 9)
```

**Iteration 4**:

```
No changes in this round
```

**Final distances from A**:

```
dist[A] = 0
dist[B] = 6
dist[C] = 7
dist[D] = 2
dist[E] = 4
```

##### Special Characteristics

- It can manage **negative edge weights** but cannot produce valid results when **negative cycles** are present.
- It is often used when edges can be negative, though it is slower than Dijkstra’s algorithm.

##### Applications

- **Financial arbitrage** detection in currency exchange markets.
- **Routing** in networks where edges might have negative costs.
- **Game development** scenarios with penalties or negative terrain effects.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford)
  
#### A* (A-Star) Algorithm

- **A\*** is an informed search algorithm used for **pathfinding** and **graph traversal**.
- It is a **best-first search** because it prioritizes the most promising paths first, combining known and estimated costs.
- The algorithm relies on:
- **g(n)**: The actual cost from the start node to the current node **n**.
- **h(n)**: A **heuristic** estimating the cost from **n** to the goal.
- The total cost function is **f(n) = g(n) + h(n)**, guiding the search toward a potentially optimal path.
- At each step, A* expands the node with the **lowest f(n)** in the priority queue.
- The heuristic **h(n)** must be **admissible** (never overestimates the real cost) to guarantee an optimal result.
- A* terminates when it either reaches the **goal** or exhausts all possibilities if no solution exists.
- It is efficient for many applications because it balances **exploration** with being **goal-directed**, but its performance depends on the heuristic quality.
- A* is broadly used in **games**, **robotics**, and **navigation** due to its effectiveness in real-world pathfinding.

##### Algorithm Steps

**Input**

- A graph
- A start vertex `A`
- A goal vertex `B`
- A heuristic function `h(v)` that estimates the cost from `v` to `B`

**Output**

- The shortest path from `A` to `B` if one exists

**Used Data Structures**

I. **g(n)**: The best-known cost from the start vertex to vertex `n`

II. **h(n)**: The heuristic estimate from vertex `n` to the goal

III. **f(n) = g(n) + h(n)**: The estimated total cost from start to goal via `n`

IV. **openSet**: Starting with the initial node, contains nodes to be evaluated

V. **closedSet**: Contains nodes already fully evaluated

VI. **cameFrom**: Structure to record the path taken

**Steps**

I. Add the starting node to the **openSet**

II. While the **openSet** is not empty

- Get the node `current` in **openSet** with the lowest **f(n)**
- If `current` is the goal node, reconstruct the path and return it
- Remove `current` from **openSet** and add it to **closedSet**
- For each neighbor `n` of `current`, skip it if it is in **closedSet**
- If `n` is not in **openSet**, add it and compute **g(n)**, **h(n)**, and **f(n)**
- If a better path to `n` is found, update **cameFrom** for `n`

III. If the algorithm terminates without finding the goal, no path exists

##### Step by Step Example

We have a graph with vertices A, B, C, D, and E:

```
A-B: 1
A-C: 2
B-D: 3
C-D: 2
D-E: 1
```

Heuristic estimates to reach E:

```
h(A) = 3
h(B) = 2
h(C) = 2
h(D) = 1
h(E) = 0
```

Adjacency matrix (∞ = no direct path):

|   | A | B | C | D |  E |
|---|---|---|---|---|----|
| **A** | 0 | 1 | 2 | ∞ |  ∞ |
| **B** | ∞ | 0 | ∞ | 3 |  ∞ |
| **C** | ∞ | ∞ | 0 | 2 |  ∞ |
| **D** | ∞ | ∞ | ∞ | 0 |  1 |
| **E** | ∞ | ∞ | ∞ | ∞ |  0 |

**Initialization**:

```
g(A) = 0
f(A) = g(A) + h(A) = 0 + 3 = 3
openSet = [A]
closedSet = []
```

Expand **A**:

```
f(B) = 0 + 1 + 2 = 3
f(C) = 0 + 2 + 2 = 4
```

Expand **B** next (lowest f=3):

```
f(D) = g(B) + cost(B,D) + h(D) = 1 + 3 + 1 = 5
```

Next lowest is **C** (f=4):

```
f(D) = g(C) + cost(C,D) + h(D) = 2 + 2 + 1 = 5 (no improvement)
```

Expand **D** (f=5):

```
f(E) = g(D) + cost(D,E) + h(E) = 5 + 1 + 0 = 6
E is the goal; algorithm stops.
```

Resulting path: **A -> B -> D -> E** with total cost **5**.

##### Special Characteristics

- **A\*** finds an optimal path if the heuristic is **admissible**.
- Edges must have **non-negative weights** for A* to work correctly.
- A good heuristic drastically improves its efficiency.

##### Applications

- Used in **video games** for enemy AI or player navigation.
- Employed in **robotics** for motion planning.
- Integral to **mapping** and **GPS** systems for shortest route calculations.

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
- It works on a **weighted undirected graph**, meaning the edges have weights, and the direction of edges doesn’t matter.  
- It starts with an **arbitrary vertex** and grows the MST by adding one edge at a time.  
- At each step, it chooses the **smallest weight edge** that connects a vertex in the MST to a vertex not yet in the MST (a **greedy** approach).  
- This process continues until **all vertices** are included.  
- The resulting MST is **connected**, ensuring a path between any two vertices, and the total edge weight is minimized.  
- Using a **priority queue** (min-heap), it can achieve a time complexity of **O(E log V)** with adjacency lists, where E is the number of edges and V is the number of vertices.  
- With an adjacency matrix, the algorithm can be implemented in **O(V^2)** time.

##### Algorithm Steps

**Input**

- A connected, undirected graph with weighted edges
- A start vertex `A`

**Output**

- A minimum spanning tree, which is a subset of the edges that connects all vertices together without any cycles and with the minimum total edge weight

**Containers and Data Structures**

- An array `key[]` to store the minimum reachable edge weight for each vertex. Initially, `key[v] = ∞` for all `v` except the first chosen vertex (set to `0`)
- A boolean array `mstSet[]` to keep track of whether a vertex is included in the MST. Initially, all values are `false`
- An array `parent[]` to store the MST. Each `parent[v]` indicates the vertex connected to `v` in the MST

**Steps**

I. Start with an arbitrary node as the initial MST node

II. While there are vertices not yet included in the MST

- Pick a vertex `v` with the smallest `key[v]`
- Include `v` in `mstSet[]`
- For each neighboring vertex `u` of `v` not in the MST
- If the weight of edge `(u, v)` is less than `key[u]`, update `key[u]` and set `parent[u]` to `v`

III. The MST is formed using the `parent[]` array once all vertices are included

##### Step by Step Example

Consider a simple graph with vertices **A**, **B**, **C**, **D**, and **E**. The edges with weights are:

```
A-B: 2
A-C: 3
B-D: 1
B-E: 3
C-D: 4
C-E: 5
D-E: 2
```

The adjacency matrix for the graph (using ∞ where no direct edge exists) is:

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 2 | 3 | ∞ | ∞ |
| **B** | 2 | 0 | ∞ | 1 | 3 |
| **C** | 3 | ∞ | 0 | 4 | 5 |
| **D** | ∞ | 1 | 4 | 0 | 2 |
| **E** | ∞ | 3 | 5 | 2 | 0 |

Run Prim's algorithm starting from vertex **A**:

I. **Initialization**  

```
Chosen vertex: A  
Not in MST: B, C, D, E  
```

II. **Pick the smallest edge from A**  

```
Closest vertex is B with a weight of 2.  
MST now has: A, B  
Not in MST: C, D, E  
```

III. **From A and B, pick the smallest edge**  

```
Closest vertex is D (from B) with a weight of 1.  
MST now has: A, B, D  
Not in MST: C, E  
```

IV. **Next smallest edge from A, B, or D**  

```
Closest vertex is E (from D) with a weight of 2.  
MST now has: A, B, D, E  
Not in MST: C  
```

V. **Pick the final vertex**  

```
The closest remaining vertex is C (from A) with a weight of 3.  
MST now has: A, B, D, E, C  
```

The MST includes the edges: **A-B (2), B-D (1), D-E (2),** and **A-C (3)**, with a total weight of **8**.

##### Special Characteristics

- It always selects the smallest edge that can connect a new vertex to the existing MST.  
- Different choices of starting vertex can still result in the same total MST weight (though the exact edges might differ if multiple edges have the same weight).  
- With adjacency lists and a priority queue, the time complexity is **O(E log V)**; with an adjacency matrix, it is **O(V^2)**.

##### Applications

- **Network design**: Building telecommunication networks with minimal cable length.  
- **Road infrastructure**: Constructing roads, tunnels, or bridges at minimal total cost.  
- **Utility services**: Designing water, electrical, or internet infrastructure to connect all locations at minimum cost.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim)

#### Kruskal's Algorithm

- **Kruskal's Algorithm** is used to find a **minimum spanning tree (MST)** in a connected, undirected graph with weighted edges.  
- It **sorts all edges** from smallest to largest by weight.  
- It **adds edges** one by one to the MST if they do not form a cycle.  
- **Cycle detection** is managed by a **disjoint-set** (union-find) data structure, which helps quickly determine if two vertices belong to the same connected component.  
- If adding an edge connects two different components, it is safe to include; if both vertices are already in the same component, including that edge would create a cycle and is skipped.  
- The process continues until the MST has **V-1** edges, where **V** is the number of vertices.  
- Its time complexity is **O(E \log E)**, dominated by sorting the edges, while union-find operations typically take near-constant time (**O(α(V))**, where α is the inverse Ackermann function).

##### Algorithm Steps

**Input**

- A connected, undirected graph with weighted edges

**Output**

- A subset of edges forming a MST, ensuring all vertices are connected with no cycles and minimal total weight

**Containers and Data Structures**

- A list or priority queue to sort the edges by weight
- A `disjoint-set (union-find)` structure to manage and merge connected components

**Steps**

I. Sort all edges in increasing order of their weights

II. Initialize a forest where each vertex is its own tree

III. Iterate through the sorted edges

- If the edge `(u, v)` connects two different components, include it in the MST and perform a `union` of the sets
- If it connects vertices in the same component, skip it

IV. Once `V-1` edges have been added, the MST is complete

##### Step by Step Example

Consider a graph with vertices **A**, **B**, **C**, **D**, and **E**. The weighted edges are:

```
A-B: 2
A-C: 3
B-D: 1
B-E: 3
C-D: 4
C-E: 5
D-E: 2
```

The adjacency matrix (∞ indicates no direct edge):

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **A** | 0 | 2 | 3 | ∞ | ∞ |
| **B** | 2 | 0 | ∞ | 1 | 3 |
| **C** | 3 | ∞ | 0 | 4 | 5 |
| **D** | ∞ | 1 | 4 | 0 | 2 |
| **E** | ∞ | 3 | 5 | 2 | 0 |

**Sort edges** by weight:

```
B-D: 1
A-B: 2
D-E: 2
A-C: 3
B-E: 3
C-D: 4
C-E: 5
```

1. **Pick B-D (1)**: Include it. MST has {B-D}, weight = 1.  
2. **Pick A-B (2)**: Include it. MST has {B-D, A-B}, weight = 3.  
3. **Pick D-E (2)**: Include it. MST has {B-D, A-B, D-E}, weight = 5.  
4. **Pick A-C (3)**: Include it. MST has {B-D, A-B, D-E, A-C}, weight = 8.  
5. **Pick B-E (3)**: Would form a cycle (B, D, E already connected), skip.  
6. **Pick C-D (4)**: Would form a cycle (C, D already connected), skip.  
7. **Pick C-E (5)**: Would form a cycle as well, skip.  

The MST edges are **B-D, A-B, D-E, and A-C**, total weight = **8**.

##### Special Characteristics

- It always picks the **smallest available edge** that won't create a cycle.  
- In case of a **tie**, any equally weighted edge can be chosen.  
- The approach is particularly efficient for **sparse graphs**.  
- Sorting edges takes **O(E \log E)** time, and disjoint-set operations can be considered almost **O(1)** on average.

##### Applications

- **Network design**: Connecting servers or cities using minimal cable length.  
- **Infrastructure**: Building road systems, water lines, or power grids with the smallest total cost.  
- **Any MST requirement**: Ensuring connectivity among all nodes at minimum cost.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/kruskal)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/kruskal)
