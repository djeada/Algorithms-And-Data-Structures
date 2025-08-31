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

What does it mean to traverse a graph?

Graph traversal **can** be done in a way that visits *all* vertices and edges (like a full DFS/BFS), but it doesn’t *have to*.

* If you start DFS or BFS from a single source vertex, you’ll only reach the **connected component** containing that vertex. Any vertices in other components won’t be visited.
* Some algorithms (like shortest path searches, A\*, or even partial DFS) intentionally stop early, meaning not all vertices or edges are visited.
* In weighted or directed graphs, you may also skip certain edges depending on the traversal rules.

So the precise way to answer that question is:

> **Graph traversal is a systematic way of exploring vertices and edges, often ensuring complete coverage of the reachable part of the graph — but whether all vertices/edges are visited depends on the algorithm and stopping conditions.**

- Graphs, unlike **trees**, don’t have a single starting point like a root. This means we either need to be given a starting vertex or pick one randomly.
- Let’s say we start from a specific vertex, like **$i$**. From there, the traversal explores all connected vertices according to the rules of the chosen method.
- In both **breadth-first search (BFS)** and **depth-first search (DFS)**, the order of visiting vertices depends on how the algorithm is implemented.
- For example, if the starting vertex **A** has three neighbors, like $C, F,$ and $G$, the algorithm doesn’t have a fixed rule for which neighbor to visit first. It could choose any of them based on the way it’s programmed.
- Because of this flexibility, we talk about **a result** of BFS or DFS, rather than **the result**, since different implementations might visit vertices in different orders.

#### Breadth-First Search (BFS)

Breadth-First Search (BFS) is a fundamental graph traversal algorithm that explores a graph **level by level** from a specified start vertex. It first visits all vertices at distance 1 from the start, then all vertices at distance 2, and so on. This makes BFS the natural choice whenever “closest in number of edges” matters.

To efficiently keep track of the traversal, BFS employs two primary data structures:

* A **queue** (often named `queue` or `unexplored`) that stores vertices pending exploration in **first-in, first-out (FIFO)** order.
* A **`visited` set** (or boolean array) that records which vertices have already been discovered to prevent revisiting.

*Useful additions in practice:*

* An optional **`parent` map** to reconstruct shortest paths (store `parent[child] = current` when you first discover `child`).
* An optional **`dist` map** to record the edge-distance from the start (`dist[start] = 0`, and when discovering `v` from `u`, set `dist[v] = dist[u] + 1`).

**Algorithm Steps**

1. Begin from a starting vertex, \$i\$.
2. Initialize `visited = {i}`, set `parent[i] = None`, optionally `dist[i] = 0`, and **enqueue** \$i\$ into `queue`.
3. While `queue` is not empty:
1. **Dequeue** the front vertex `u`.
2. For **each neighbor** `v` of `u`:
* If `v` is **not** in `visited`, add `v` to `visited`, set `parent[v] = u` (and `dist[v] = dist[u] + 1` if tracking distances), and **enqueue** `v`.
4. Continue until the queue becomes empty.

Marking nodes as **visited at the moment they are enqueued** (not when dequeued) is crucial: it prevents the same node from being enqueued multiple times in graphs with cycles or multiple incoming edges.

*Reference pseudocode (adjacency-list graph):*

```
BFS(G, i):
    visited = {i}
    parent  = {i: None}
    dist    = {i: 0}            # optional
    queue   = [i]

    order = []                  # optional: visitation order

    while queue:
        u = queue.pop(0)        # dequeue
        order.append(u)

        for v in G[u]:          # iterate neighbors
            if v not in visited:
                visited.add(v)
                parent[v] = u
                dist[v] = dist[u] + 1   # if tracking
                queue.append(v)

    return order, parent, dist
```

*Sanity notes:*

* **Time:** $O(V + E)$ for a graph with $V$ vertices and $E$ edges (each vertex enqueued once; each edge considered once).
* **Space:** $O(V)$ for the queue + visited (+ parent/dist if used).
* BFS order can differ depending on **neighbor iteration order**.

**Example**

Graph (undirected) with start at **A**:

```
           ┌─────┐
           │  A  │
           └──┬──┘
          ┌───┘ └───┐
        ┌─▼─┐     ┌─▼─┐
        │ B │     │ C │
        └─┬─┘     └─┬─┘
        ┌─▼─┐     ┌─▼─┐
        │ D │     │ E │
        └───┘     └───┘

Edges: A–B, A–C, B–D, C–E
```

*Queue/Visited evolution (front → back):*

```
Step | Dequeued | Action                                   | Queue            | Visited
-----+----------+-------------------------------------------+------------------+----------------
0    | —        | enqueue A                                 | [A]              | {A}
1    | A        | discover B, C; enqueue both               | [B, C]           | {A, B, C}
2    | B        | discover D; enqueue                       | [C, D]           | {A, B, C, D}
3    | C        | discover E; enqueue                       | [D, E]           | {A, B, C, D, E}
4    | D        | no new neighbors                          | [E]              | {A, B, C, D, E}
5    | E        | no new neighbors                          | []               | {A, B, C, D, E}
```

*BFS tree and distances from A:*

```
dist[A]=0
A → B (1), A → C (1)
B → D (2), C → E (2)

Parents: parent[B]=A, parent[C]=A, parent[D]=B, parent[E]=C
Shortest path A→E: backtrack E→C→A  ⇒  A - C - E
```

**Applications**

1. **Shortest paths in unweighted graphs.**
   BFS computes the minimum number of edges from the source to every reachable node. Use the `parent` map to reconstruct actual paths.

2. **Connected components (undirected graphs).**
   Repeatedly run BFS from every unvisited vertex; each run discovers exactly one component.

3. **Broadcast/propagation modeling.**
   BFS mirrors “wavefront” spread (e.g., message fan-out, infection spread, multi-hop neighborhood queries).

4. **Cycle detection (undirected graphs).**
   During BFS, if you encounter a neighbor that is already **visited** and is **not** the parent of the current vertex, a cycle exists.
   *Note:* For **directed graphs**, detecting cycles typically uses other techniques (e.g., DFS with recursion stack or Kahn’s algorithm on indegrees).

5. **Bipartite testing.**
   While BFS’ing, assign alternating “colors” by level; if you ever see an edge connecting the **same** color, the graph isn’t bipartite.

6. **Multi-source searches.**
   Initialize the queue with **several** starting nodes at once (all with `dist=0`). This solves “nearest facility” style problems efficiently.

7. **Topological sorting via Kahn’s algorithm (DAGs).**
   A BFS-like process over vertices of indegree 0 (using a queue) produces a valid topological order for directed acyclic graphs.

**Implementation**

*Implementation tip:* For dense graphs or when memory locality matters, an adjacency **matrix** can be used, but the usual adjacency **list** representation is more space- and time-efficient for sparse graphs.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs)

#### Depth-First Search (DFS)

Depth-First Search (DFS) is a fundamental graph traversal algorithm that explores **as far as possible** along each branch before backtracking. Starting from a source vertex, it dives down one neighbor, then that neighbor’s neighbor, and so on—only backing up when it runs out of new vertices to visit.

To track the traversal efficiently, DFS typically uses:

* A **call stack** via **recursion** *or* an explicit **stack** data structure (LIFO).
* A **`visited` set** (or boolean array) to avoid revisiting vertices.

*Useful additions in practice:*

* A **`parent` map** to reconstruct paths and build the DFS tree (`parent[child] = current` on discovery).
* Optional **timestamps** (`tin[u]` on entry, `tout[u]` on exit) to reason about edge types, topological order, and low-link computations.
* Optional **`order` lists**: pre-order (on entry) and post-order (on exit).

**Algorithm Steps**

1. Begin at starting vertex $i$.
2. Mark $i$ as **visited**, optionally set `parent[i] = None`, record `tin[i]`.
3. For each neighbor $v$ of the current vertex $u$:

   * If $v$ is **unvisited**, set `parent[v] = u` and **recurse** (or push onto a stack) into $v$.
4. After all neighbors of $u$ are explored, record `tout[u]` and **backtrack** (return or pop).
5. Repeat for any remaining unvisited vertices (to cover disconnected graphs).

Mark vertices **when first discovered** (on entry/push) to prevent infinite loops in cyclic graphs.

*Pseudocode (recursive, adjacency list):*

```
time = 0

DFS(G, i):
    visited = set()
    parent  = {i: None}
    tin     = {}
    tout    = {}
    pre     = []       # optional: order on entry
    post    = []       # optional: order on exit

    def explore(u):
        nonlocal time
        visited.add(u)
        time += 1
        tin[u] = time
        pre.append(u)               # preorder

        for v in G[u]:
            if v not in visited:
                parent[v] = u
                explore(v)

        time += 1
        tout[u] = time
        post.append(u)              # postorder

    explore(i)
    return pre, post, parent, tin, tout
```

*Pseudocode (iterative, traversal order only):*

```
DFS_iter(G, i):
    visited = set()
    parent  = {i: None}
    order   = []
    stack   = [i]

    while stack:
        u = stack.pop()             # take the top
        if u in visited: 
            continue
        visited.add(u)
        order.append(u)

        # Push neighbors in reverse of desired visiting order
        for v in reversed(G[u]):
            if v not in visited:
                parent[v] = u
                stack.append(v)

    return order, parent
```

*Sanity notes:*

* **Time:** $O(V + E)$ — each vertex/edge handled a constant number of times.
* **Space:** $O(V)$ — visited + recursion/stack. Worst-case recursion depth can reach $V$; use the iterative form on very deep graphs.

**Example**

Same graph as the BFS section, start at **A**; assume neighbor order: `B` before `C`, and for `B` the neighbor `D`; for `C` the neighbor `E`.

```
                 ┌─────────┐
                 │    A    │
                 └───┬─┬───┘
                     │ │
           ┌─────────┘ └─────────┐
           ▼                     ▼
      ┌─────────┐           ┌─────────┐
      │    B    │           │    C    │
      └───┬─────┘           └───┬─────┘
          │                     │
          ▼                     ▼
     ┌─────────┐           ┌─────────┐
     │    D    │           │    E    │
     └─────────┘           └─────────┘

Edges: A–B, A–C, B–D, C–E  (undirected)
```

*Recursive DFS trace (pre-order):*

```
call DFS(A)
  visit A
    -> DFS(B)
         visit B
           -> DFS(D)
                visit D
                return D
         return B
    -> DFS(C)
         visit C
           -> DFS(E)
                visit E
                return E
         return C
  return A
```

*Discovery/finish times (one valid outcome):*

```
Vertex | tin | tout | parent
-------+-----+------+---------
A      |  1  | 10   | None
B      |  2  |  5   | A
D      |  3  |  4   | B
C      |  6  |  9   | A
E      |  7  |  8   | C
```

*Stack/Visited evolution (iterative DFS, top = right):*

```
Step | Action                       | Stack                 | Visited
-----+------------------------------+-----------------------+-----------------
0    | push A                       | [A]                   | {}
1    | pop A; visit                 | []                    | {A}
     | push C, B                    | [C, B]                | {A}
2    | pop B; visit                 | [C]                   | {A, B}
     | push D                       | [C, D]                | {A, B}
3    | pop D; visit                 | [C]                   | {A, B, D}
4    | pop C; visit                 | []                    | {A, B, D, C}
     | push E                       | [E]                   | {A, B, D, C}
5    | pop E; visit                 | []                    | {A, B, D, C, E}
```

*DFS tree (tree edges shown), with preorder: A, B, D, C, E*

```
A
├── B
│   └── D
└── C
    └── E
```

**Applications**

1. **Path existence & reconstruction.**
   Use `parent` to backtrack from a target to the start after a DFS that finds it.

2. **Topological sorting (DAGs).**
   Run DFS on a directed acyclic graph; the **reverse postorder** (vertices sorted by decreasing `tout`) is a valid topological order.

3. **Cycle detection.**
   *Undirected:* seeing a visited neighbor that isn’t the parent ⇒ cycle.
   *Directed:* maintain states (`unvisited`, `in_stack`, `done`); encountering an edge to a vertex **in\_stack** (a back edge) ⇒ cycle.

4. **Connected components (undirected).**
   Run DFS from every unvisited node; each run discovers exactly one component.

5. **Bridges & articulation points (cut vertices).**
   Using DFS **low-link** values (`low[u] = min(tin[u], tin[v] over back edges, low of children)`), you can find edges whose removal disconnects the graph (bridges) and vertices whose removal increases components (articulation points).

6. **Strongly Connected Components (SCCs, directed graphs).**
   Tarjan’s (single-pass with a stack and low-link) or Kosaraju’s (two DFS passes) algorithms are built on DFS.

7. **Backtracking & search in state spaces.**
   Classic for maze solving, puzzles (N-Queens, Sudoku), and constraint satisfaction: DFS systematically explores choices and backtracks on dead ends.

8. **Detecting and classifying edges (directed).**
   With timestamps, classify edges as **tree**, **back**, **forward**, or **cross**—useful for reasoning about structure and correctness.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dfs)

*Implementation tips:*

* For **very deep** or skewed graphs, prefer the **iterative** form to avoid recursion limits.
* If neighbor order matters (e.g., lexicographic traversal), control push order (push in reverse for stacks) or sort adjacency lists.
* For sparse graphs, adjacency **lists** are preferred over adjacency matrices for time/space efficiency.

### Shortest paths

A common task when dealing with weighted graphs is to find the shortest route between two vertices, such as from vertex $A$ to vertex $B$. Note that there might not be a unique shortest path, since several paths could have the same length.

#### Dijkstra’s Algorithm

Dijkstra’s algorithm computes **shortest paths** from a specified start vertex in a graph with **non-negative edge weights**. It grows a “settled” region outward from the start, always choosing the unsettled vertex with the **smallest known distance** and relaxing its outgoing edges to improve neighbors’ distances.

To efficiently keep track of the traversal, Dijkstra’s algorithm employs two primary data structures:

* A **min-priority queue** (often named `pq`, `open`, or `unexplored`) keyed by each vertex’s current best known distance from the start.
* A **`dist` map** storing the best known distance to each vertex (∞ initially, except the start), a **`visited`/`finalized` set** to mark vertices whose shortest distance is proven, and a **`parent` map** to reconstruct paths.

*Useful additions in practice:*

* A **target-aware early stop**: if you only need the distance to a specific target, you can stop when that target is popped from the priority queue.
* **Decrease-key or lazy insertion**: if the PQ doesn’t support decrease-key, push an updated entry and ignore popped stale ones by checking against `dist`.
* Optional **`pred` lists** for counting shortest paths or reconstructing multiple optimal routes.

**Algorithm Steps**

1. Begin from a starting vertex, \$i\$.

2. Initialize `dist[i] = 0`, `parent[i] = None`; for all other vertices `v`, set `dist[v] = ∞`. Push \$i\$ into the min-priority queue keyed by `dist[i]`.

3. While the priority queue is not empty:

   1. **Extract** the vertex `u` with the **smallest** `dist[u]`.
   2. If `u` is already finalized, continue; otherwise **finalize** `u` (add to `visited`/`finalized`).
   3. For **each neighbor** `v` of `u` with edge weight `w(u,v) ≥ 0`:

      * If `dist[u] + w(u,v) < dist[v]`, then **relax** the edge: set
        `dist[v] = dist[u] + w(u,v)` and `parent[v] = u`, and **push** `v` into the PQ keyed by the new `dist[v]`.

4. Continue until the queue becomes empty (all reachable vertices finalized) or until your **target** has been finalized (early stop).

5. Reconstruct any shortest path by following `parent[·]` **backwards** from the target to the start.

Vertices are **finalized when they are dequeued** (popped) from the priority queue. With **non-negative** weights, once a vertex is popped the recorded `dist` is **provably optimal**.

*Reference pseudocode (adjacency-list graph):*

```
Dijkstra(G, i, target=None):
    INF = +infinity
    dist   = defaultdict(lambda: INF)
    parent = {i: None}
    dist[i] = 0

    pq = MinPriorityQueue()
    pq.push(i, 0)

    finalized = set()

    while pq:
        u, du = pq.pop_min()                 # smallest current distance
        if u in finalized:                   # ignore stale entries
            continue

        finalized.add(u)

        if target is not None and u == target:
            break                            # early exit: target finalized

        for (v, w_uv) in G[u]:               # w_uv >= 0
            alt = du + w_uv
            if alt < dist[v]:
                dist[v]   = alt
                parent[v] = u
                pq.push(v, alt)              # decrease-key or lazy insert

    return dist, parent

# Reconstruct path i -> t (if t reachable):
reconstruct(parent, t):
    path = []
    while t is not None:
        path.append(t)
        t = parent.get(t)
    return list(reversed(path))
```

*Sanity notes:*

* **Time:** with a binary heap, \$O((V + E)\log V)\$; with a Fibonacci heap, \$O(E + V\log V)\$; with a plain array (no heap), \$O(V^2)\$.
* **Space:** \$O(V)\$ for `dist`, `parent`, PQ bookkeeping.
* **Preconditions:** All edge weights must be **\$\ge 0\$**. Negative edges invalidate correctness.
* **Ordering:** Different neighbor iteration orders don’t affect correctness, only tie behavior/performance.

**Example**

Weighted, undirected graph; start at **A**. Edge weights are on the links.

```
                          ┌────────┐
                          │   A    │
                          └─┬──┬───┘
                         4/   │1
                       ┌──    │    ──┐
                 ┌─────▼──┐  │     ┌▼──────┐
                 │   B    │──┘2    │   C   │
                 └───┬────┘        └──┬────┘
                   1 │               4 │
                     │                 │
                 ┌───▼────┐      3  ┌──▼───┐
                 │   E    │────────│   D   │
                 └────────┘         └──────┘

Edges: A–B(4), A–C(1), C–B(2), B–E(1), C–D(4), D–E(3)
```

*Priority queue / Finalized evolution (front = smallest key):*

```
Step | Pop (u,dist) | Relaxations (v: new dist, parent)         | PQ after push                   | Finalized
-----+--------------+--------------------------------------------+----------------------------------+----------------
0    | —            | init A: dist[A]=0                          | [(A,0)]                          | {}
1    | (A,0)        | B:4←A  , C:1←A                             | [(C,1), (B,4)]                   | {A}
2    | (C,1)        | B:3←C  , D:5←C                             | [(B,3), (B,4), (D,5)]            | {A,C}
3    | (B,3)        | E:4←B                                      | [(E,4), (B,4), (D,5)]            | {A,C,B}
4    | (E,4)        | D:7 via E  (no improve; current 5)         | [(B,4), (D,5)]                   | {A,C,B,E}
5    | (B,4) stale  | (ignore; B already finalized)              | [(D,5)]                          | {A,C,B,E}
6    | (D,5)        | —                                          | []                               | {A,C,B,E,D}
```

*Distances and parents (final):*

```
dist[A]=0 (—)
dist[C]=1 (A)
dist[B]=3 (C)
dist[E]=4 (B)
dist[D]=5 (C)

Shortest path A→E: A → C → B → E  (total cost 4)
```

*Big-picture view of the expanding frontier:*

```
   Settled set grows outward from A by increasing distance.
   After Step 1: {A}
   After Step 2: {A, C}
   After Step 3: {A, C, B}
   After Step 4: {A, C, B, E}
   After Step 6: {A, C, B, E, D}  (all reachable nodes done)
```

**Applications**

1. **Single-source shortest paths** on graphs with **non-negative** weights (roads, networks, transit).
2. **Navigation/routing** with early stop: stop when the goal is popped to avoid extra work.
3. **Network planning & QoS:** minimum latency/cost routing, bandwidth-weighted paths (when additive and non-negative).
4. **As a building block:** A\* with $h \equiv 0$; **Johnson’s algorithm** (all-pairs on sparse graphs); **k-shortest paths** variants.
5. **Multi-source Dijkstra:** seed the PQ with multiple starts at distance 0 (e.g., nearest facility / multi-sink problems).
6. **Label-setting baseline** for comparing heuristics (A\*, ALT landmarks, contraction hierarchies).
7. **Grid pathfinding with terrain costs** (non-negative cell costs) when no admissible heuristic is available.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dijkstra)

*Implementation tip:* If your PQ has no decrease-key, **push duplicates** on improvement and, when popping a vertex, **skip it** if it’s already finalized or if the popped key doesn’t match `dist[u]`. This “lazy” approach is simple and fast in practice.

#### Bellman-Ford Algorithm

#### Bellman–Ford Algorithm

Bellman–Ford computes **shortest paths** from a start vertex in graphs that may have **negative edge weights** (but no negative cycles reachable from the start). It works by repeatedly **relaxing** every edge; each full pass can reduce some distances until they stabilize. A final check detects **negative cycles**: if an edge can still be relaxed after $(V-1)$ passes, a reachable negative cycle exists.

To efficiently keep track of the computation, Bellman–Ford employs two primary data structures:

* A **`dist` map** (or array) with the best-known distance to each vertex (initialized to ∞ except the start).
* A **`parent` map** to reconstruct shortest paths (store `parent[v] = u` when relaxing edge $u\!\to\!v$).

*Useful additions in practice:*

* **Edge list**: iterate edges directly (fast and simple) even if your graph is stored as adjacency lists.
* **Early exit**: stop as soon as a full pass makes **no updates**.
* **Negative-cycle extraction**: if an update occurs on pass $V$, backtrack through `parent` to find a cycle.
* **Reachability guard**: you can skip edges whose source has `dist[u] = ∞` (still unreached).

**Algorithm Steps**

1. Begin from a starting vertex, $i$.

2. Initialize `dist[i] = 0`, `parent[i] = None`; for all other vertices $v$, set `dist[v] = ∞`.

3. Repeat **$V-1$ passes** (where $V$ is the number of vertices):

   1. Set `changed = False`.
   2. For **each directed edge** $(u,v,w)$ (weight $w$):

      * If `dist[u] + w < dist[v]`, then **relax** the edge:
        `dist[v] = dist[u] + w`, `parent[v] = u`, and set `changed = True`.
   3. If `changed` is **False**, break early (all distances stabilized).

4. **Negative-cycle detection** (optional but common):
   For each edge $(u,v,w)$, if `dist[u] + w < dist[v]`, then a **negative cycle is reachable**.
   *To extract a cycle:* follow `parent` from `v` **V times** to land inside the cycle; then keep following until you revisit a vertex, collecting the cycle.

5. To get a shortest path to a target $t$ (if no negative cycle affects it), follow `parent[t]` backward to $i$.

*Reference pseudocode (edge list):*

```
BellmanFord(V, E, i):                 # V: set/list of vertices
    INF = +infinity                   # E: list of (u, v, w) edges
    dist   = {v: INF for v in V}
    parent = {v: None for v in V}
    dist[i] = 0

    # (V-1) relaxation passes
    for _ in range(len(V) - 1):
        changed = False
        for (u, v, w) in E:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                changed = True
        if not changed:
            break

    # Negative-cycle check
    cycle_vertex = None
    for (u, v, w) in E:
        if dist[u] != INF and dist[u] + w < dist[v]:
            cycle_vertex = v
            break

    return dist, parent, cycle_vertex     # cycle_vertex=None if no neg cycle

# Reconstruct shortest path i -> t (if safe):
reconstruct(parent, t):
    path = []
    while t is not None:
        path.append(t)
        t = parent[t]
    return list(reversed(path))
```

*Sanity notes:*

* **Time:** $O(VE)$ (each pass scans all edges; up to $V-1$ passes).
* **Space:** $O(V)$ for `dist` and `parent`.
* **Handles negative weights**; **detects** reachable negative cycles.
* If a reachable **negative cycle** exists, true shortest paths to vertices it can reach are **undefined** (effectively $-\infty$).

**Example**

Directed, weighted graph; start at **A**. (Negative edges allowed; **no** negative cycles here.)

```
                               ┌─────────┐
                               │    A    │
                               └──┬───┬──┘
                              4  │   │  2
                                 │   │
                      ┌──────────▼───┐   -1    ┌─────────┐
                      │      B       │ ───────►│    C    │
                      └──────┬───────┘          └──┬─────┘
                           2 │                     5│
                             │                      │
                      ┌──────▼──────┐    -3    ┌───▼─────┐
                      │      D       │ ◄────── │    E    │
                      └──────────────┘          └─────────┘

Also:
A → C (2)
C → B (1)
C → E (3)
(Edges shown with weights on arrows)
```

*Edges list:*
`A→B(4), A→C(2), B→C(-1), B→D(2), C→B(1), C→D(5), C→E(3), D→E(-3)`

*Relaxation trace (dist after each full pass; start A):*

```
Init (pass 0):
  dist[A]=0, dist[B]=∞, dist[C]=∞, dist[D]=∞, dist[E]=∞

After pass 1:
  A=0, B=3, C=2, D=6, E=3
    (A→B=4, A→C=2; C→B improved B to 3; B→D=5? (via B gives 6); D→E=-3 gives E=3)

After pass 2:
  A=0, B=3, C=2, D=5, E=2
    (B→D improved D to 5; D→E improved E to 2)

After pass 3:
  A=0, B=3, C=2, D=5, E=2   (no changes → early stop)
```

*Parents / shortest paths (one valid set):*

```
parent[A]=None
parent[C]=A
parent[B]=C
parent[D]=B
parent[E]=D

Example shortest path A→E:
A → C → B → D → E   with total cost 2 + 1 + 2 + (-3) = 2
```

*Negative-cycle detection (illustration):*
If we **add** an extra edge `E→C(-4)`, the cycle `C → D → E → C` has total weight `5 + (-3) + (-4) = -2` (negative).
Bellman–Ford would perform a $V$-th pass and still find an improvement (e.g., relaxing `E→C(-4)`), so it reports a **reachable negative cycle**.

**Applications**

1. **Shortest paths with negative edges** (when Dijkstra/A\* don’t apply).
2. **Arbitrage detection** in currency/markets by summing $\log$ weights along cycles.
3. **Feasibility checks** in difference constraints (systems like $x_v - x_u \le w$).
4. **Robust baseline** for verifying or initializing faster methods (e.g., Johnson’s algorithm for all-pairs).
5. **Graphs with penalties/credits** where some transitions reduce accumulated cost.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford)

*Implementation tip:* For **all-pairs** on sparse graphs with possible negative edges, use **Johnson’s algorithm**: run Bellman–Ford once from a super-source to reweight edges (no negatives), then run **Dijkstra** from each vertex.

#### A* (A-Star) Algorithm

A\* is a best-first search that finds a **least-cost path** from a start to a goal by minimizing

$$
f(n) = g(n) + h(n),
$$

where:

* $g(n)$ = cost from start to $n$ (so far),
* $h(n)$ = heuristic estimate of the remaining cost from $n$ to the goal.

If $h$ is **admissible** (never overestimates) and **consistent** (triangle inequality), A\* is **optimal** and never needs to “reopen” closed nodes.

**Core data structures**

* **Open set**: min-priority queue keyed by $f$ (often called `open` or `frontier`).
* **Closed set**: a set (or map) of nodes already expanded (finalized).
* **`g` map**: best known cost-so-far to each node.
* **`parent` map**: to reconstruct the path on success.
* (Optional) **`h` cache** and a **tie-breaker** (e.g., prefer larger $g$ or smaller $h$ when $f$ ties).

**Algorithm Steps**

1. Initialize `open = {start}` with `g[start]=0`, `f[start]=h(start)`; `parent[start]=None`.
2. While `open` is not empty:
   a. Pop `u` with **smallest** `f(u)` from `open`.
   b. If `u` is the **goal**, reconstruct the path via `parent` and return.
   c. Add `u` to **closed**.
   d. For each neighbor `v` of `u` with edge cost `w(u,v) ≥ 0`:

   * `tentative = g[u] + w(u,v)`
   * If `v` not in `g` or `tentative < g[v]`: update `parent[v]=u`, `g[v]=tentative`, `f[v]=g[v]+h(v)` and push `v` into `open` (even if it was there before with a worse key).
3. If `open` empties without reaching the goal, no path exists.

*Mark neighbors **when you enqueue them** (by storing their best `g`) to avoid duplicate work; with **consistent** $h$, any node popped from `open` is final and will not improve later.*

**Reference pseudocode**

```
A_star(G, start, goal, h):
    open = MinPQ()                        # keyed by f = g + h
    open.push(start, h(start))
    g = {start: 0}
    parent = {start: None}
    closed = set()

    while open:
        u = open.pop_min()                # node with smallest f
        if u == goal:
            return reconstruct_path(parent, goal), g[goal]

        closed.add(u)

        for (v, w_uv) in G.neighbors(u):  # w_uv >= 0
            tentative = g[u] + w_uv
            if v in closed and tentative >= g.get(v, +inf):
                continue

            if tentative < g.get(v, +inf):
                parent[v] = u
                g[v] = tentative
                f_v = tentative + h(v)
                open.push(v, f_v)         # decrease-key OR push new entry

    return None, +inf

reconstruct_path(parent, t):
    path = []
    while t is not None:
        path.append(t)
        t = parent[t]
    return list(reversed(path))
```

*Sanity notes:*

* **Time:** Worst-case exponential; practically much faster with informative $h$.
* **Space:** $O(V)$ for maps + PQ (A\* is memory-hungry).
* **Special cases:** If $h \equiv 0$, A\* ≡ **Dijkstra**. If all edges cost 1 and $h \equiv 0$, it behaves like **BFS**.

**Visual walkthrough (grid with 4-neighborhood, Manhattan $h$)**

Legend: `S` start, `G` goal, `#` wall, `.` free, `◉` expanded (closed), `•` frontier (open), `×` final path

```
Row/Col →   1 2 3 4 5 6 7 8 9
           ┌───────────────────┐
1   S  .  .  .  .  #  .  .  .  │
2   .  #  #  .  .  #  .  #  .  │
3   .  .  .  .  .  .  .  #  .  │
4   #  .  #  #  .  #  .  .  .  │
5   .  .  .  #  .  .  .  #  G  │
           └───────────────────┘
Movement cost = 1 per step; 4-dir moves; h = Manhattan distance
```

**Early expansion snapshot (conceptual):**

```
Step 0:
Open: [(S, g=0, h=|S-G|, f=g+h)]         Closed: {}
Grid: S is • (on frontier)

Step 1: pop S → expand neighbors
Open: [((1,2), g=1, h=?, f=?), ((2,1), g=1, h=?, f=?)]
Closed: {S}
Marks: S→ ◉, its valid neighbors → •

Step 2..k:
A* keeps popping the lowest f, steering toward G.
Nodes near the straight line to G are preferred over detours around '#'.
```

**When goal is reached, reconstruct the path:**

```
Final path (example rendering):
           ┌───────────────────┐
1   ×  ×  ×  ×  .  #  .  .  .  │
2   ×  #  #  ×  ×  #  .  #  .  │
3   ×  ×  ×  ×  ×  ×  ×  #  .  │
4   #  .  #  #  ×  #  ×  ×  ×  │
5   .  .  .  #  ×  ×  ×  #  G  │
           └───────────────────┘
Path length (g at G) equals number of × steps (optimal with admissible/consistent h).
```

**Priority queue evolution (toy example)**

```
Step | Popped u | Inserted neighbors (v: g,h,f)                  | Note
-----+----------+-------------------------------------------------+---------------------------
0    | —        | push S: g=0, h=14, f=14                        | S at (1,1), G at (5,9)
1    | S        | (1,2): g=1,h=13,f=14 ; (2,1): g=1,h=12,f=13    | pick (2,1) next
2    | (2,1)    | (3,1): g=2,h=11,f=13 ; (2,2) blocked           | ...
3    | (3,1)    | (4,1) wall; (3,2): g=3,h=10,f=13               | still f=13 band
…    | …        | frontier slides along the corridor toward G    | A* hugs the beeline
```

(Exact numbers depend on the specific grid and walls; shown for intuition.)

---

### Heuristic design

For **grids**:

* **4-dir moves:** $h(n)=|x_n-x_g|+|y_n-y_g|$ (Manhattan).
* **8-dir (diag cost √2):** **Octile**: $h=\Delta_{\max} + (\sqrt{2}-1)\Delta_{\min}$.
* **Euclidean** when motion is continuous and diagonal is allowed.

For **sliding puzzles (e.g., 8/15-puzzle)**:

* **Misplaced tiles** (admissible, weak).
* **Manhattan sum** (stronger).
* **Linear conflict / pattern databases** (even stronger).

**Admissible vs. consistent**

* **Admissible:** $h(n) \leq h^\*(n)$ (true remaining cost). Guarantees optimality.
* **Consistent (monotone):** $h(u) \le w(u,v) + h(v)$ for every edge.
  Ensures $f$-values are nondecreasing along paths; once a node is popped, its `g` is final (no reopen).

**Applications**

1. **Pathfinding** in maps, games, robotics (shortest or least-risk routes).
2. **Route planning** with road metrics (time, distance, tolls) and constraints.
3. **Planning & scheduling** in AI as a general shortest-path in state spaces.
4. **Puzzle solving** (8-puzzle, Sokoban variants) with domain-specific $h$.
5. **Network optimization** where edge costs are nonnegative and heuristics exist.

**Variants & practical tweaks**

* **Dijkstra** = A\* with $h \equiv 0$.
* **Weighted A\***: use $f = g + \varepsilon h$ ($\varepsilon>1$) for faster, **bounded-suboptimal** search.
* **A\*ε / Anytime A\***: start with $\varepsilon>1$, reduce over time to approach optimal.
* **IDA\***: iterative deepening on $f$-bound; **much lower memory**, sometimes slower.
* **RBFS / Fringe Search**: memory-bounded alternatives.
* **Tie-breaking**: on equal $f$, prefer **larger $g$** (deeper) or **smaller $h$** to reduce node re-expansions.
* **Closed-set policy**: if $h$ is **inconsistent**, allow **reopening** when a better `g` is found.

**Pitfalls & tips**

* **No negative edges.** A\* assumes $w(u,v) \ge 0$.
* **Overestimating $h$** breaks optimality.
* **Precision issues:** with floats, compare $f$ using small epsilons.
* **State hashing:** ensure equal states hash equal (avoid exploding duplicates).
* **Neighbor order:** doesn’t affect optimality, but affects performance/trace aesthetics.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/a_star)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/a_star)

*Implementation tip:* If your PQ lacks decrease-key, **push duplicates** with improved keys and ignore stale entries when popped (check if popped `g` matches current `g[u]`). This is simple and fast in practice.

### Minimal Spanning Trees

Suppose we have a graph that represents a network of houses. Weights represent the distances between vertices, which each represent a single house. All houses must have water, electricity, and internet, but we want the cost of installation to be as low as possible. We need to identify a subgraph of our graph with the following properties:

* There are no cycles in the graph.
* All vertices are connected.
* The total sum of weights is minimum.

Such a subgraph is called a minimal spanning tree.

#### Prim's Algorithm

#### Prim’s Algorithm

Prim’s algorithm builds a **minimum spanning tree (MST)** of a **weighted, undirected** graph by growing a tree from a start vertex. At each step it adds the **cheapest edge** that connects a vertex **inside** the tree to a vertex **outside** the tree.

To efficiently keep track of the construction, Prim’s algorithm employs two primary data structures:

* A **min-priority queue** (often named `pq`, `open`, or `unexplored`) keyed by a vertex’s **best known connection cost** to the current tree.
* A **`in_mst`/`visited` set** to mark vertices already added to the tree, plus a **`parent` map** to record the chosen incoming edge for each vertex.

*Useful additions in practice:*

* A **`key` map** where `key[v]` stores the lightest edge weight found so far that connects `v` to the current tree (∞ initially, except the start which is 0).
* **Lazy updates** if your PQ has no decrease-key: push improved `(v, key[v])` again and skip stale pops.
* **Component handling**: if the graph can be **disconnected**, either run Prim once per component (restarting at an unvisited vertex) or seed the PQ with **multiple starts** (`key=0`) to produce a **spanning forest**.

**Algorithm Steps**

1. Begin from a starting vertex, \$i\$.

2. Initialize `key[i] = 0`, `parent[i] = None`; for all other vertices `v`, set `key[v] = ∞`. Push \$i\$ into the min-priority queue keyed by `key`.

3. While the priority queue is not empty:

   1. **Extract** the vertex `u` with the **smallest** `key[u]`.
   2. If `u` is already in the MST, continue; otherwise **add `u` to the MST** (insert into `in_mst`).
      If `parent[u]` is not `None`, record the tree edge `(parent[u], u)`.
   3. For **each neighbor** `v` of `u` with edge weight `w(u,v)`:

      * If `v` is **not** in the MST **and** `w(u,v) < key[v]`, then **improve** the connection to `v`:
        set `key[v] = w(u,v)`, `parent[v] = u`, and **push** `v` into the PQ keyed by the new `key[v]`.

4. Continue until the queue is empty (or until all vertices are in the MST for a connected graph).

5. The set of edges `{ (parent[v], v) : v ≠ i }` forms an MST; the MST **total weight** is `∑ key[v]` when each `v` is added.

Vertices are **finalized when they are dequeued**: at that moment, `key[u]` is the **minimum** cost to connect `u` to the growing tree (by the **cut property**).

*Reference pseudocode (adjacency-list graph):*

```
Prim(G, i):
    INF = +infinity
    key    = defaultdict(lambda: INF)
    parent = {i: None}
    key[i] = 0

    pq = MinPriorityQueue()              # holds (key[v], v)
    pq.push((0, i))

    in_mst = set()
    mst_edges = []

    while pq:
        ku, u = pq.pop_min()             # smallest key
        if u in in_mst:
            continue
        in_mst.add(u)

        if parent[u] is not None:
            mst_edges.append((parent[u], u, ku))

        for (v, w_uv) in G[u]:           # undirected: each edge seen twice
            if v not in in_mst and w_uv < key[v]:
                key[v] = w_uv
                parent[v] = u
                pq.push((key[v], v))     # decrease-key or lazy insert

    return mst_edges, parent, sum(w for (_,_,w) in mst_edges)
```

*Sanity notes:*

* **Time:** with a binary heap, $O(E \log V)$; with a Fibonacci heap, $O(E + V \log V)$.
  Dense graph (adjacency matrix + no PQ) variant runs in $O(V^2)$.
* **Space:** $O(V)$ for `key`, `parent`, and MST bookkeeping.
* **Graph type:** **weighted, undirected**; weights may be negative or positive (no restriction like Dijkstra).
  If the graph is **disconnected**, Prim yields a **minimum spanning forest** (one tree per component).
* **Uniqueness:** If all edge weights are **distinct**, the MST is **unique**.

**Example**

Undirected, weighted graph; start at **A**. Edge weights shown on links.

```
                          ┌────────┐
                          │   A    │
                          └─┬──┬───┘
                         4/   │1
                       ┌──    │    ──┐
                 ┌─────▼──┐  │     ┌▼──────┐
                 │   B    │──┘2    │   C   │
                 └───┬────┘        └──┬────┘
                   1 │               4 │
                     │                 │
                 ┌───▼────┐      3  ┌──▼───┐
                 │   E    │────────│   D   │
                 └────────┘         └──────┘

Edges: A–B(4), A–C(1), C–B(2), B–E(1), C–D(4), D–E(3)
```

*Frontier (keys) / In-tree evolution (min at front):*

```
Legend: key[v] = cheapest known connection to tree; parent[v] = chosen neighbor

Step | Action                          | PQ (key:vertex) after push         | In MST | Updated keys / parents
-----+---------------------------------+------------------------------------+--------+-------------------------------
0    | init at A                       | [0:A]                               | {}     | key[A]=0, others=∞
1    | pop A → add                     | [1:C, 4:B]                          | {A}    | key[C]=1 (A), key[B]=4 (A)
2    | pop C → add                     | [2:B, 4:D, 4:B]                     | {A,C}  | key[B]=min(4,2)=2 (C), key[D]=4 (C)
3    | pop B(2) → add                  | [1:E, 4:D, 4:B]                     | {A,C,B}| key[E]=1 (B)
4    | pop E(1) → add                  | [3:D, 4:D, 4:B]                     | {A,C,B,E}| key[D]=min(4,3)=3 (E)
5    | pop D(3) → add                  | [4:D, 4:B]                          | {A,C,B,E,D}| done
```

*MST edges chosen (with weights):*

```
A—C(1), C—B(2), B—E(1), E—D(3)
Total weight = 1 + 2 + 1 + 3 = 7
```

*Resulting MST (tree edges only):*

```
A
└── C (1)
    └── B (2)
        └── E (1)
            └── D (3)
```

**Applications**

1. **Network design** (least-cost wiring/piping/fiber) connecting all sites with minimal total cost.
2. **Approximation for TSP** (metric TSP 2-approx via MST preorder walk).
3. **Clustering (single-linkage)**: remove the **k−1** heaviest edges of the MST to form **k** clusters.
4. **Image processing / segmentation**: MST over pixels/superpixels to find low-contrast boundaries.
5. **Map generalization / simplification**: keep a connectivity backbone with minimal redundancy.
6. **Circuit design / VLSI**: minimal interconnect length under simple models.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim)

*Implementation tip:*
For **dense graphs** ($E \approx V^2$), skip heaps: store `key` in an array and, at each step, scan all non-MST vertices to pick the minimum `key` in $O(V)$. Overall $O(V^2)$ but often **faster in practice** on dense inputs due to low overhead.


#### Kruskal's Algorithm
#### Kruskal’s Algorithm

Kruskal’s algorithm builds a **minimum spanning tree (MST)** for a **weighted, undirected** graph by sorting all edges by weight (lightest first) and repeatedly adding the next lightest edge that **does not create a cycle**. It grows the MST as a forest of trees that gradually merges until all vertices are connected.

To efficiently keep track of the construction, Kruskal’s algorithm employs two primary data structures:

* A **sorted edge list** (ascending by weight) that drives which edge to consider next.
* A **Disjoint Set Union (DSU)**, also called **Union–Find**, to detect whether an edge’s endpoints are already in the same tree (cycle) or in different trees (safe to unite).

*Useful additions in practice:*

* **Union–Find with path compression** + **union by rank/size** for near-constant-time merges and finds.
* **Early stop**: in a connected graph with $V$ vertices, once you’ve added **$V-1$** edges, the MST is complete.
* **Deterministic tie-breaking**: when equal weights occur, break ties consistently for reproducible MSTs.
* **Disconnected graphs**: Kruskal naturally yields a **minimum spanning forest** (one MST per component).

**Algorithm Steps**

1. Gather all edges $E=\{(u,v,w)\}$ and **sort** them by weight $w$ (ascending).

2. Initialize **DSU** with each vertex in its **own set**; `parent[v]=v`, `rank[v]=0`.

3. Traverse the sorted edges one by one:

   1. For edge $(u,v,w)$, compute `ru = find(u)`, `rv = find(v)` in DSU.
   2. If `ru ≠ rv` (endpoints in **different** sets), **add** $(u,v,w)$ to the MST and **union** the sets.
   3. Otherwise, **skip** the edge (it would create a cycle).

4. Stop when either **$V-1$** edges are chosen (connected case) or edges are exhausted (forest case).

5. The chosen edges form the **MST**; the **total weight** is the sum of their weights.

By the **cycle** and **cut** properties of MSTs, selecting the minimum-weight edge that crosses any cut between components is always safe; rejecting edges that close a cycle preserves optimality.

*Reference pseudocode (edge list + DSU):*

```
Kruskal(V, E):
    # V: iterable of vertices
    # E: list of edges (u, v, w) for undirected graph

    sort E by weight ascending

    make_set(v) for v in V        # DSU init: parent[v]=v, rank[v]=0

    mst_edges = []
    total = 0

    for (u, v, w) in E:
        if find(u) != find(v):
            union(u, v)
            mst_edges.append((u, v, w))
            total += w
            if len(mst_edges) == len(V) - 1:   # early stop if connected
                break

    return mst_edges, total

# Union-Find helpers (path compression + union by rank):
find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

union(x, y):
    rx, ry = find(x), find(y)
    if rx == ry: return
    if rank[rx] < rank[ry]:
        parent[rx] = ry
    elif rank[rx] > rank[ry]:
        parent[ry] = rx
    else:
        parent[ry] = rx
        rank[rx] += 1
```

*Sanity notes:*

* **Time:** Sorting dominates: $O(E \log E)$ = $O(E \log V)$. DSU operations are almost $O(1)$ amortized (inverse Ackermann).
* **Space:** $O(V)$ for DSU; $O(E)$ to store edges.
* **Weights:** May be **negative or positive** (unlike Dijkstra); graph must be **undirected**.
* **Uniqueness:** If all edge weights are **distinct**, the MST is **unique**.

**Example**

Undirected, weighted graph (we’ll draw the key edges clearly and list the rest).
Start with all vertices as separate sets: `{A} {B} {C} {D} {E} {F}`.

```
Top row:                 A────────4────────B────────2────────C
                         │                     │
                         │                     │
                         7                     3
                         │                     │
Bottom row:              F────────1────────E───┴──────────────D
                               (E–F)
Other edges (not all drawn to keep the picture clean):
A–C(4), B–D(5), C–D(5), C–E(5), D–E(6), D–F(2)
```

*Sorted edge list (ascending):*
`E–F(1), B–C(2), D–F(2), B–E(3), A–B(4), A–C(4), B–D(5), C–D(5), C–E(5), D–E(6), A–F(7)`

*Union–Find / MST evolution (take the edge if it connects different sets):*

```
Step | Edge (w)  | Find(u), Find(v) | Action     | Components after union            | MST so far                 | Total
-----+-----------+-------------------+------------+-----------------------------------+----------------------------+------
 1   | E–F (1)   | {E}, {F}          | TAKE       | {E,F} {A} {B} {C} {D}            | [E–F(1)]                   | 1
 2   | B–C (2)   | {B}, {C}          | TAKE       | {E,F} {B,C} {A} {D}              | [E–F(1), B–C(2)]           | 3
 3   | D–F (2)   | {D}, {E,F}        | TAKE       | {B,C} {D,E,F} {A}                | [E–F(1), B–C(2), D–F(2)]   | 5
 4   | B–E (3)   | {B,C}, {D,E,F}    | TAKE       | {A} {B,C,D,E,F}                  | [..., B–E(3)]              | 8
 5   | A–B (4)   | {A}, {B,C,D,E,F}  | TAKE       | {A,B,C,D,E,F} (all connected)    | [..., A–B(4)]              | 12
     | (stop: we have V−1 = 5 edges for 6 vertices)
```

*Resulting MST edges and weight:*

```
E–F(1), B–C(2), D–F(2), B–E(3), A–B(4)    ⇒  Total = 1 + 2 + 2 + 3 + 4 = 12
```

*Clean MST view (tree edges only):*

```
A
└── B (4)
    ├── C (2)
    └── E (3)
        └── F (1)
            └── D (2)
```

**Applications**

1. **Network design:** least-cost backbone (roads, fiber, pipes) connecting all sites with minimal total length/cost.
2. **Clustering (single-linkage):** build MST, then cut the **k−1** heaviest edges to form **k** clusters.
3. **Image segmentation:** graph-based grouping by intensity/feature differences via MST.
4. **Approximation for metric TSP:** preorder walk of MST gives a 2-approx tour (with shortcutting).
5. **Circuit/VLSI layout:** minimal interconnect under simple models.
6. **Maze generation:** randomized Kruskal picks edges in random order subject to acyclicity.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/kruskal)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/kruskal)

*Implementation tip:*
On huge graphs that **stream from disk**, you can **external-sort** edges by weight, then perform a single pass with DSU. For reproducibility across platforms, **stabilize** sorting by `(weight, min(u,v), max(u,v))`.

### Topological Sort

Topological sort orders the vertices of a **directed acyclic graph (DAG)** so that **every directed edge** $u \rightarrow v$ goes **from left to right** in the order (i.e., $u$ appears before $v$). It’s the canonical tool for scheduling tasks with dependencies.

To efficiently keep track of the process (Kahn’s algorithm), we use:

* A **queue** (or min-heap if you want lexicographically smallest order) holding all vertices with **indegree = 0** (no unmet prerequisites).
* An **`indegree` map/array** that counts for each vertex how many prerequisites remain.
* An **`order` list** to append vertices as they are “emitted.”

*Useful additions in practice:*

* A **`visited_count`** (or length of `order`) to detect cycles: if, after processing, fewer than $V$ vertices were output, the graph has a cycle.
* A **min-heap** instead of a FIFO queue to get the **lexicographically smallest** valid topological order.
* A **DFS-based alternative**: run DFS and take vertices in **reverse postorder** (also $O(V+E)$); with DFS you detect cycles via a 3-color/stack state.

**Algorithm Steps (Kahn’s algorithm)**

1. Compute `indegree[v]` for every vertex $v$.

2. Initialize a queue `Q` with **all** vertices of indegree 0.

3. While `Q` is not empty:

   1. **Dequeue** a vertex `u` and append it to `order`.
   2. For each outgoing edge `u → v`:

      * Decrement `indegree[v]` by 1.
      * If `indegree[v]` becomes 0, **enqueue** `v`.

4. If `len(order) < V`, a **cycle exists** (topological order does not exist). Otherwise, `order` is a valid topological ordering.

*Reference pseudocode (adjacency-list graph):*

```
TopoSort_Kahn(G):
    # G[u] = iterable of neighbors v with edge u -> v
    V = all_vertices(G)
    indeg = {v: 0 for v in V}
    for u in V:
        for v in G[u]:
            indeg[v] += 1

    Q = Queue()
    for v in V:
        if indeg[v] == 0:
            Q.enqueue(v)

    order = []

    while not Q.empty():
        u = Q.dequeue()
        order.append(u)
        for v in G[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                Q.enqueue(v)

    if len(order) != len(V):
        return None    # cycle detected
    return order
```

*Sanity notes:*

* **Time:** $O(V + E)$ — each vertex enqueued once; each edge decreases an indegree once.
* **Space:** $O(V)$ — for indegrees, queue, and output.
* **Input:** Must be a **DAG**; if a cycle exists, **no** topological order exists.

**Example**

DAG; we’ll start with all indegree-0 vertices. (Edges shown as arrows.)

```
                           ┌───────┐
                           │   A   │
                           └───┬───┘
                               │
                               │
        ┌───────┐          ┌───▼───┐          ┌───────┐
        │   B   │──────────│   C   │──────────│   D   │
        └───┬───┘          └───┬───┘          └───┬───┘
            │                  │                  │
            │                  │                  │
            │              ┌───▼───┐              │
            │              │   E   │──────────────┘
            │              └───┬───┘
            │                  │
            │                  │
        ┌───▼───┐          ┌───▼───┐
        │   G   │          │   F   │
        └───────┘          └───────┘

Edges:
A→C, B→C, C→D, C→E, E→D, B→G
```

*Initial indegrees:*

```
indeg[A]=0, indeg[B]=0, indeg[C]=2, indeg[D]=2, indeg[E]=1, indeg[F]=0, indeg[G]=1
```

*Queue/Indegree evolution (front → back; assume we keep the queue **lexicographically** by using a min-heap):*

```
Step | Pop u | Emit order         | Decrease indeg[...]         | Newly 0 → Enqueue | Q after
-----+-------+--------------------+------------------------------+-------------------+-----------------
0    | —     | []                 | —                            | A, B, F           | [A, B, F]
1    | A     | [A]                | C:2→1                        | —                 | [B, F]
2    | B     | [A, B]             | C:1→0, G:1→0                | C, G              | [C, F, G]
3    | C     | [A, B, C]          | D:2→1, E:1→0                | E                 | [E, F, G]
4    | E     | [A, B, C, E]       | D:1→0                       | D                 | [D, F, G]
5    | D     | [A, B, C, E, D]    | —                            | —                 | [F, G]
6    | F     | [A, B, C, E, D, F] | —                            | —                 | [G]
7    | G     | [A, B, C, E, D, F, G] | —                         | —                 | []
```

*A valid topological order:*
`A, B, C, E, D, F, G` (others like `B, A, C, E, D, F, G` are also valid.)

*Clean left-to-right view (one possible ordering):*

```
A   B   F   C   E   D   G
│   │       │   │   │
└──►└──►    └──►└──►└──►   (all arrows go left→right)
```

**Cycle detection (why it fails on cycles)**

If there’s a cycle, some vertices **never** reach indegree 0. Example:

```
   ┌─────┐      ┌─────┐
   │  X  │ ───► │  Y  │
   └──┬──┘      └──┬──┘
      └───────────►┘
        (Y ───► X creates a cycle)
```

Here `indeg[X]=indeg[Y]=1` initially; `Q` starts empty ⇒ `order=[]` and `len(order) < V` ⇒ **cycle reported**.

**Applications**

1. **Build systems / compilation** (compile a file only after its prerequisites).
2. **Course scheduling** (take courses in an order respecting prerequisites).
3. **Data pipelines / DAG workflows** (Airflow, Spark DAGs): execute stages when inputs are ready.
4. **Dependency resolution** (package managers, container layers).
5. **Dynamic programming on DAGs** (longest/shortest path, path counting) by processing vertices in topological order.
6. **Circuit evaluation / spreadsheets** (evaluate cells/nets after their dependencies).

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/topological_sort)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/topological_sort/kruskal)

*Implementation tips:*

* Use a **deque** for FIFO behavior; use a **min-heap** to get the **lexicographically smallest** topological order.
* When the graph is large and sparse, store adjacency as **lists** and compute indegrees in one pass for $O(V+E)$.
* **DFS variant** (brief): color states `0=unseen,1=visiting,2=done`; on exploring `u`, mark `1`; DFS to neighbors; if you see `1` again, there’s a cycle; on finish, push `u` to a stack. Reverse the stack for the order.
