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

Graphs, with their versatile applications in numerous domains, necessitate efficient storage and manipulation mechanisms in computer memory. The choice of representation often depends on the graph's characteristics (e.g., dense vs. sparse, directed vs. undirected, weighted vs. unweighted) and the specific operations to be performed. Among the various methods available, the adjacency matrix and the adjacency list are the most prevalent.

#### Adjacency Matrix

An adjacency matrix represents a graph $G$ with $V$ vertices as a two-dimensional matrix $A$ of size $V \times V$. The rows and columns correspond to vertices, and each cell $A_{ij}$ holds:

* `1` if there is an edge between vertex $i$ and vertex $j$ (or specifically $i \to j$ in a directed graph)
* `0` if no such edge exists
* For weighted graphs, $A_{ij}$ contains the **weight** of the edge; often `0` or `∞` (or `None`) indicates “no edge”

**Same graph used throughout (undirected 4-cycle A–B–C–D–A):**

```
        (A)------(B)
         |        |
         |        |
        (D)------(C)
```

**Matrix (table form):**

|   | A | B | C | D |
| - | - | - | - | - |
| A | 0 | 1 | 0 | 1 |
| B | 1 | 0 | 1 | 0 |
| C | 0 | 1 | 0 | 1 |
| D | 1 | 0 | 1 | 0 |

Here, the matrix indicates a graph with vertices A to D. For instance, vertex A connects with vertices B and D, hence the respective 1s in the matrix.

**Matrix:**

```
4x4
            Columns →
          A   B   C   D
        +---+---+---+---+
Row   A | 0 | 1 | 0 | 1 |
↓     B | 1 | 0 | 1 | 0 |
      C | 0 | 1 | 0 | 1 |
      D | 1 | 0 | 1 | 0 |
        +---+---+---+---+
```

**Notes & Variants**

* When an *undirected graph* is represented, the adjacency matrix is symmetric because the connection from node $i$ to node $j$ also implies a connection from node $j$ to node $i$; if this property is omitted, the matrix will misrepresent mutual relationships, such as a road existing in both directions between two cities.
* In the case of a *directed graph*, the adjacency matrix does not need to be symmetric since an edge from node $i$ to node $j$ does not guarantee a reverse edge; without this rule, one might incorrectly assume bidirectional links, such as mistakenly treating a one-way street as two-way.
* A *self-loop* appears as a nonzero entry on the diagonal of the adjacency matrix, indicating that a node is connected to itself; if ignored, the representation will overlook scenarios like a website containing a hyperlink to its own homepage.

**Benefits**

* An *edge existence check* in an adjacency matrix takes constant time $O(1)$ because the presence of an edge is determined by directly inspecting a single cell; if this property is absent, the lookup could require scanning a list, as in adjacency list representations where finding whether two cities are directly connected may take longer.
* With *simple, compact indexing*, the adjacency matrix aligns well with array-based structures, which makes it helpful for GPU optimizations or bitset operations; without this feature, algorithms relying on linear algebra techniques, such as computing paths with matrix multiplication, become less efficient.

**Drawbacks**

* The *space* requirement of an adjacency matrix is always $O(V^2)$, meaning memory usage grows with the square of the number of vertices even if only a few edges exist; if this property is overlooked, sparse networks such as social graphs with millions of users but relatively few connections will be stored inefficiently.
* For *neighbor iteration*, each vertex requires $O(V)$ time because the entire row of the matrix must be scanned to identify adjacent nodes; without recognizing this cost, tasks like finding all friends of a single user in a large social network could become unnecessarily slow.

**Common Operations (Adjacency Matrix)**

| Operation                          | Time     |
| ---------------------------------- | -------- |
| Check if edge $u\leftrightarrow v$ | $O(1)$   |
| Add/remove edge                    | $O(1)$   |
| Iterate neighbors of $u$           | $O(V)$   |
| Compute degree of $u$ (undirected) | $O(V)$   |
| Traverse all edges                 | $O(V^2)$ |

**Space Tips**

* Using a *boolean or bitset matrix* allows each adjacency entry to be stored in just one bit, which reduces memory consumption by a factor of eight compared to storing each entry as a byte; if this method is not applied, representing even moderately sized graphs, such as a network of 10,000 nodes, can require far more storage than necessary.
* The approach is most useful when the graph is *dense*, the number of vertices is relatively small, or constant-time edge queries are the primary operation; without these conditions, such as in a sparse graph with millions of vertices, the $V^2$ bit requirement remains wasteful and alternative representations like adjacency lists become more beneficial.

#### Adjacency List

An adjacency list stores, for each vertex, the list of its neighbors. It’s usually implemented as an array/vector of lists (or vectors), hash sets, or linked structures. For weighted graphs, each neighbor entry also stores the weight.

**Same graph (A–B–C–D–A) as lists:**

```
A -> [B, D]
B -> [A, C]
C -> [B, D]
D -> [A, C]
```

**“In-memory” view (array of heads + per-vertex chains):**

```
Vertices (index) →   0     1     2     3
Names              [ A ] [ B ] [ C ] [ D ]
                     |     |     |     |
                     v     v     v     v
A-list:  head -> [B] -> [D] -> NULL
B-list:  head -> [A] -> [C] -> NULL
C-list:  head -> [B] -> [D] -> NULL
D-list:  head -> [A] -> [C] -> NULL
```

**Variants & Notes**

* In an *undirected graph* stored as adjacency lists, each edge is represented twice—once in the list of each endpoint—so that both directions can be traversed easily; if this duplication is omitted, traversing from one node to its neighbor may be possible in one direction but not in the other, as with a friendship relation that should be mutual but is stored only once.
* For a *directed graph*, only out-neighbors are recorded in each vertex’s list, meaning that edges can be followed in their given direction; without a separate structure for in-neighbors, tasks like finding all users who link to a webpage require inefficient scanning of every adjacency list.
* In a *weighted graph*, each adjacency list entry stores both the neighbor and the associated weight, such as $(\text{destination}, \text{distance})$; if weights are not included, algorithms like Dijkstra’s shortest path cannot be applied correctly.
* The *order of neighbors* in adjacency lists may be arbitrary, though keeping them sorted allows faster checks for membership; if left unsorted, testing whether two people are directly connected in a social network could require scanning the entire list rather than performing a quicker search.

**Benefits**

* The representation is *space-efficient for sparse graphs* because it requires $O(V+E)$ storage, growing only with the number of vertices and edges; without this property, a graph with millions of vertices but relatively few edges, such as a road network, would consume far more memory if stored as a dense matrix.
* For *neighbor iteration*, the time cost is $O(\deg(u))$, since only the actual neighbors of vertex $u$ are examined; if this benefit is absent, each query would need to scan through all possible vertices, as happens in adjacency matrices when identifying a node’s connections.
* In *edge traversals and searches*, adjacency lists support breadth-first search and depth-first search efficiently on sparse graphs because only existing edges are processed; without this design, traversals would involve wasted checks on non-edges, making exploration of large but sparsely connected networks, like airline routes, much slower.

**Drawbacks**

* An *edge existence check* in adjacency lists requires $O(\deg(u))$ time in the worst case because the entire neighbor list may need to be scanned; if a hash set is used for each vertex, the expected time improves to $O(1)$, though at the cost of extra memory and overhead, as seen in fast membership tests within large social networks.
* With respect to *cache locality*, adjacency lists often rely on pointers or scattered memory, which reduces their efficiency on modern hardware; without this drawback, as in dense matrix storage, sequential memory access patterns make repeated operations such as matrix multiplication more beneficial.

**Common Operations (Adjacency List)**

| Operation                          | Time (typical)                              |
| ---------------------------------- | ------------------------------------------- |
| Check if edge $u\leftrightarrow v$ | $O(\deg(u))$ (or expected $O(1)$ with hash) |
| Add edge                           | Amortized $O(1)$ (append to list(s))        |
| Remove edge                        | $O(\deg(u))$ (find & delete)                |
| Iterate neighbors of $u$           | $O(\deg(u))$                                |
| Traverse all edges                 | $O(V + E)$                                  |

The choice between these (and other) representations often depends on the graph's characteristics and the specific tasks or operations envisioned.

* Choosing an *adjacency matrix* is helpful when the graph is dense, the number of vertices is moderate, and constant-time edge queries or linear-algebra formulations are beneficial; if this choice is ignored, operations such as repeatedly checking flight connections in a fully connected air network may become slower or harder to express mathematically.
* Opting for an *adjacency list* is useful when the graph is sparse or when neighbor traversal dominates, as in breadth-first search or shortest-path algorithms; without this structure, exploring a large but lightly connected road network would waste time scanning nonexistent edges.

**Hybrids/Alternatives:**

* With *CSR/CSC (Compressed Sparse Row/Column)* formats, all neighbors of a vertex are stored contiguously in memory, which improves cache locality and enables fast traversals; without this layout, as in basic pointer-based adjacency lists, high-performance analytics on graphs like web link networks would suffer from slower memory access.
* An *edge list* stores edges simply as $(u,v)$ pairs, making it convenient for graph input, output, and algorithms like Kruskal’s minimum spanning tree; if used for queries such as checking whether two nodes are adjacent, the lack of structure forces scanning the entire list, which becomes inefficient in large graphs.
* In *hash-based adjacency* structures, each vertex’s neighbor set is managed as a hash table, enabling expected $O(1)$ membership tests; without this tradeoff, checking connections in dense social networks requires linear scans, while the hash-based design accelerates lookups at the cost of extra memory.

### Planarity

**Planarity** asks: can a graph be drawn on a flat plane so that edges only meet at their endpoints (no crossings)?

Why it matters: layouts of circuits, road networks, maps, and data visualizations often rely on planar drawings.

#### What is a planar graph?

A graph is **planar** if it has **some** drawing in the plane with **no edge crossings**. A messy drawing with crossings doesn’t disqualify it—if you can **redraw** it without crossings, it’s planar.

* A crossing-free drawing of a planar graph is called a **planar embedding** (or **plane graph** once embedded).
* In a planar embedding, the plane is divided into **faces** (regions), including the unbounded **outer face**.

**Euler’s Formula (connected planar graphs):**

$$
|V| - |E| + |F| = 2 \quad
\text{(for \(c\) connected components: } |V|-|E|+|F|=1+c)
$$

#### Kuratowski’s & Wagner’s characterizations

* According to *Kuratowski’s Theorem*, a graph is planar if and only if it does not contain a subgraph that is a subdivision of $K_5$ or $K_{3,3}$; if this condition is not respected, as in a network with five nodes all mutually connected, the graph cannot be drawn on a plane without edge crossings.
* By *Wagner’s Theorem*, a graph is planar if and only if it has no $K_5$ or $K_{3,3}$ minor, meaning such structures cannot be formed through edge deletions, vertex deletions, or edge contractions; without ruling out these minors, a graph like the complete bipartite structure of three stations each linked to three others cannot be embedded in the plane without overlaps.

These are equivalent “forbidden pattern” views.

#### Handy planar edge bounds (quick tests)

For a **simple** planar graph with $|V|\ge 3$:

* $|E| \le 3|V| - 6$.
* If the graph is **bipartite**, then $|E| \le 2|V| - 4$.

These give fast non-planarity proofs:

* $K_5$: $|V|=5, |E|=10 > 3\cdot5-6=9$ ⇒ **non-planar**.
* $K_{3,3}$: $|V|=6, |E|=9 > 2\cdot6-4=8$ ⇒ **non-planar**.

#### Examples

**I. Cycle graphs $C_n$ (always planar)**

A 4-cycle $C_4$:

```
A───B
│   │
D───C
```

No crossings; faces: 2 (inside + outside).

**II. Complete graph on four vertices $K_4$ (planar)**

A planar embedding places one vertex inside a triangle:

```
    A
   / \
  B───C
   \ /
    D
```

All edges meet only at vertices; no crossings.

**III. Complete graph on five vertices $K_5$ (non-planar)**

No drawing avoids crossings. Even a “best effort” forces at least one:

```
A───B
│╲ ╱│
│ ╳ │   (some crossing is unavoidable)
│╱ ╲│
D───C
  \ /
   E
```

The edge bound $10>9$ (above) certifies non-planarity.

**IV. Complete bipartite $K_{3,3}$ (non-planar)**

Two sets $\{u_1,u_2,u_3\}$ and $\{v_1,v_2,v_3\}$, all cross-set pairs connected:

```
u1   u2   u3
│ \  │ \  │ \
│  \ │  \ │  \
v1───v2───v3  (many edges must cross in the plane)
```

The bipartite bound $9>8$ proves non-planarity.

#### How to check planarity in practice

**For small graphs**

1. Rearrange vertices and try to remove crossings.
2. Look for $K_5$ / $K_{3,3}$ (or their subdivisions/minors).
3. Apply the edge bounds above for quick eliminations.

**For large graphs (efficient algorithms)**

* The *Hopcroft–Tarjan* algorithm uses a depth-first search approach to decide planarity in linear time; without such an efficient method, testing whether a circuit layout can be drawn without wire crossings would take longer on large graphs.
* The *Boyer–Myrvold* algorithm also runs in linear time but, in addition to deciding planarity, it produces a planar embedding when one exists; if this feature is absent, as in Hopcroft–Tarjan, a separate procedure would be required to actually construct a drawing of a planar transportation network.

Both are widely used in graph drawing, EDA (circuit layout), GIS, and network visualization.

### Traversals

What does it mean to traverse a graph?

Graph traversal **can** be done in a way that visits *all* vertices and edges (like a full DFS/BFS), but it doesn’t *have to*.

* If you start DFS or BFS from a single source vertex, you’ll only reach the **connected component** containing that vertex. Any vertices in other components won’t be visited.
* Some algorithms (like shortest path searches, A*, or even partial DFS) intentionally stop early, meaning not all vertices or edges are visited.
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

1. Pick a start vertex $i$.
2. Set `visited = {i}`, `parent[i] = None`, optionally `dist[i] = 0`, and enqueue $i$ into `queue`.
3. While `queue` is nonempty, repeat steps 4–5.
4. Dequeue the front vertex `u`.
5. For each neighbor `v` of `u`, if `v` is not in `visited`, add it to `visited`, set `parent[v] = u` (and `dist[v] = dist[u] + 1` if tracking), and enqueue `v`.
6. Stop when the queue is empty.

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

* The *time* complexity of breadth-first search is $O(V+E)$ because each vertex is enqueued once and each edge is examined once; if this property is overlooked, one might incorrectly assume that exploring a large social graph requires quadratic time rather than scaling efficiently with its size.
* The *space* requirement is $O(V)$ since the algorithm maintains a queue and a visited array, with optional parent or distance arrays if needed; without accounting for this, applying BFS to a network of millions of nodes could be underestimated in memory cost.
* The order in which BFS visits vertices depends on the *neighbor iteration order*, meaning that traversal results can vary between implementations; if this variation is not recognized, two runs on the same graph—such as exploring a road map—may appear inconsistent even though both are correct BFS traversals.

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

* In *shortest path computation on unweighted graphs*, BFS finds the minimum number of edges from a source to all reachable nodes and allows path reconstruction via a parent map; without this approach, one might incorrectly use Dijkstra’s algorithm, which is slower for unweighted networks such as social connections.
* For identifying *connected components in undirected graphs*, BFS is run repeatedly from unvisited vertices, with each traversal discovering one full component; without this method, components in a road map or friendship network may remain undetected.
* When modeling *broadcast or propagation*, BFS naturally mirrors wavefront-like spreading, such as message distribution or infection spread; ignoring this property makes it harder to simulate multi-hop communication in networks.
* During BFS-based *cycle detection in undirected graphs*, encountering a visited neighbor that is not the current vertex’s parent signals a cycle; without this check, cycles in structures like utility grids may be overlooked.
* For *bipartite testing*, BFS alternates colors by level, and the appearance of an edge connecting same-colored nodes disproves bipartiteness; without this strategy, verifying whether a task-assignment graph can be split into two groups becomes more complicated.
* In *multi-source searches*, initializing the queue with several start nodes at distance zero allows efficient nearest-facility queries, such as finding the closest hospital from multiple candidate sites; without this, repeated single-source BFS runs would be less efficient.
* In *topological sorting of DAGs*, a BFS-like procedure processes vertices of indegree zero using a queue, producing a valid ordering; without this method, scheduling tasks with dependency constraints may require less efficient recursive DFS approaches.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bfs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bfs)

*Implementation tip:* For dense graphs or when memory locality matters, an adjacency **matrix** can be used, but the usual adjacency **list** representation is more space- and time-efficient for sparse graphs.

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

1. Pick a start vertex $i$.
2. Initialize `visited[v]=False` for all $v$; optionally set `parent[v]=None`; set a global timer `t=0`.
3. Start a DFS from $i$ (recursive or with an explicit stack).
4. On entry to a vertex $u$: set `visited[u]=True`, record `tin[u]=t++` (and keep `parent[u]=None` if $u=i$).
5. Scan neighbors $v$ of $u$; whenever `visited[v]=False`, set `parent[v]=u` and visit $v$ (recurse/push), then resume scanning $u$’s neighbors.
6. After all neighbors of $u$ are processed, record `tout[u]=t++` and backtrack (return or pop).
7. When the DFS from $i$ finishes, if any vertex remains unvisited, choose one and repeat steps 4–6 to cover disconnected components.
8. Stop when no unvisited vertices remain.

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

* The *time* complexity of DFS is $O(V+E)$ because every vertex and edge is processed a constant number of times; if this property is ignored, one might incorrectly assume exponential growth when analyzing networks like citation graphs.
* The *space* complexity is $O(V)$, coming from the visited array and the recursion stack (or an explicit stack in iterative form); without recognizing this, applying DFS to very deep structures such as long linked lists could risk stack overflow unless the iterative approach is used.

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

* In *path existence and reconstruction*, DFS records parent links so that after reaching a target node, the path can be backtracked to the source; without this, finding an explicit route through a maze-like graph would require re-running the search.
* For *topological sorting of DAGs*, running DFS and outputting vertices in reverse postorder yields a valid order; if this step is omitted, dependencies in workflows such as build systems cannot be properly sequenced.
* During *cycle detection*, DFS in undirected graphs reports a cycle when a visited neighbor is not the parent, while in directed graphs the discovery of a back edge to an in-stack node reveals a cycle; without these checks, feedback loops in control systems or task dependencies may go unnoticed.
* To identify *connected components in undirected graphs*, DFS is launched from every unvisited vertex, with each traversal discovering one component; without this method, clusters in social or biological networks remain hidden.
* Using *low-link values* in DFS enables detection of bridges (edges whose removal disconnects the graph) and articulation points (vertices whose removal increases components); if these are not identified, critical links in communication or power networks may be overlooked.
* In *strongly connected components* of directed graphs, algorithms like Tarjan’s and Kosaraju’s use DFS to group vertices where every node is reachable from every other; ignoring this method prevents reliable partitioning of web link graphs or citation networks.
* For *backtracking and state-space search*, DFS systematically explores decision trees and reverses when hitting dead ends, as in solving puzzles like Sudoku or N-Queens; without DFS, these problems would be approached less efficiently with blind trial-and-error.
* With *edge classification in directed graphs*, DFS timestamps allow edges to be labeled as tree, back, forward, or cross, which helps analyze structure and correctness; without this classification, reasoning about graph algorithms such as detecting cycles or proving properties becomes more difficult.

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

* A *target-aware early stop* allows Dijkstra’s algorithm to halt once the target vertex is extracted from the priority queue, saving work compared to continuing until all distances are finalized; without this optimization, computing the shortest route between two cities would require processing the entire network unnecessarily.
* With *decrease-key or lazy insertion* strategies, priority queues that lack a decrease-key operation can still work by inserting updated entries and discarding outdated ones when popped; without this adjustment, distance updates in large road networks would be inefficient or require a more complex data structure.
* Adding optional *predecessor lists* enables reconstruction of multiple optimal paths or counting the number of shortest routes; if these lists are not maintained, applications like enumerating all equally fast routes between transit stations cannot be supported.

**Algorithm Steps**

1. Pick a start vertex $i$.
2. Set `dist[i] = 0` and `parent[i] = None`; for all other vertices $v \ne i$, set `dist[v] = ∞`.
3. Push $i$ into a min-priority queue keyed by `dist[·]`.
4. While the priority queue is nonempty, repeat steps 5–8.
5. Extract the vertex $u$ with the smallest `dist[u]`.
6. If $u$ is already finalized, continue to step 4; otherwise mark $u$ as finalized.
7. For each neighbor $v$ of $u$ with edge weight $w(u,v) \ge 0$, test whether `dist[u] + w(u,v) < dist[v]`.
8. If true, set `dist[v] = dist[u] + w(u,v)`, set `parent[v] = u`, and push $v$ into the priority queue keyed by the new `dist[v]`.
9. Stop when the queue is empty (all reachable vertices finalized) or, if you have a target, when that target is finalized.
10. Reconstruct any shortest path by following `parent[·]` backward from the target to $i$.

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

* The *time* complexity of Dijkstra’s algorithm depends on the priority queue: $O((V+E)\log V)$ with a binary heap, $O(E+V\log V)$ with a Fibonacci heap, and $O(V^2)$ with a plain array; without this distinction, one might wrongly assume that all implementations scale equally on dense versus sparse road networks.
* The *space* complexity is $O(V)$, needed to store distance values, parent pointers, and priority queue bookkeeping; if underestimated, running Dijkstra on very large graphs such as nationwide transit systems may exceed available memory.
* The *precondition* is that all edge weights must be nonnegative, since the algorithm assumes distances only improve as edges are relaxed; if negative weights exist, as in certain financial models with losses, the computed paths can be incorrect and Bellman–Ford must be used instead.
* In terms of *ordering*, the sequence in which neighbors are processed does not affect correctness, only the handling of ties and slight performance differences; without recognizing this, variations in output order between implementations might be mistakenly interpreted as errors.

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

* In *single-source shortest paths* with non-negative edge weights, Dijkstra’s algorithm efficiently finds minimum-cost routes in settings like roads, communication networks, or transit systems; without it, travel times or costs could not be computed reliably when distances vary.
* For *navigation and routing*, stopping the search as soon as the destination is extracted from the priority queue avoids unnecessary work; without this early stop, route planning in a road map continues exploring irrelevant regions of the network.
* In *network planning and quality of service (QoS)*, Dijkstra selects minimum-latency or minimum-cost routes when weights are additive and non-negative; without this, designing efficient data or logistics paths becomes more error-prone.
* As a *building block*, Dijkstra underlies algorithms like A* (with zero heuristic), Johnson’s algorithm for all-pairs shortest paths in sparse graphs, and $k$-shortest path variants; without it, these higher-level methods would lack a reliable core procedure.
* In *multi-source Dijkstra*, initializing the priority queue with several starting nodes at distance zero solves nearest-facility queries, such as finding the closest hospital; without this extension, repeated single-source runs would waste time.
* As a *label-setting baseline*, Dijkstra provides the reference solution against which heuristics like A*, ALT landmarks, or contraction hierarchies are compared; without this baseline, heuristic correctness and performance cannot be properly evaluated.
* For *grid pathfinding with terrain costs*, Dijkstra handles non-negative cell costs when no admissible heuristic is available; without it, finding a least-effort path across weighted terrain would require less efficient exhaustive search.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/dijkstra)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/dijkstra)

*Implementation tip:* If your PQ has no decrease-key, **push duplicates** on improvement and, when popping a vertex, **skip it** if it’s already finalized or if the popped key doesn’t match `dist[u]`. This “lazy” approach is simple and fast in practice.

#### Bellman–Ford Algorithm

Bellman–Ford computes **shortest paths** from a start vertex in graphs that may have **negative edge weights** (but no negative cycles reachable from the start). It works by repeatedly **relaxing** every edge; each full pass can reduce some distances until they stabilize. A final check detects **negative cycles**: if an edge can still be relaxed after $(V-1)$ passes, a reachable negative cycle exists.

To efficiently keep track of the computation, Bellman–Ford employs two primary data structures:

* A **`dist` map** (or array) with the best-known distance to each vertex (initialized to ∞ except the start).
* A **`parent` map** to reconstruct shortest paths (store `parent[v] = u` when relaxing edge $u\!\to\!v$).

*Useful additions in practice:*

* With an *edge list*, iterating directly over edges simplifies implementation and keeps updates fast, even if the graph is stored in adjacency lists; without this practice, repeatedly scanning adjacency structures adds unnecessary overhead in each relaxation pass.
* Using an *early exit* allows termination once a full iteration over edges yields no updates, improving efficiency; without this check, the algorithm continues all $V-1$ passes even on graphs like road networks where distances stabilize early.
* For *negative-cycle extraction*, if an update still occurs on the $V$-th pass, backtracking through parent links reveals a cycle; without this step, applications such as financial arbitrage detection cannot identify opportunities caused by negative cycles.
* Adding a *reachability guard* skips edges from vertices with infinite distance, avoiding wasted work on unreached nodes; without this filter, the algorithm needlessly inspects irrelevant edges in disconnected parts of the graph.

**Algorithm Steps**

1. Pick a start vertex $i$.
2. Set `dist[i] = 0` and `parent[i] = None`; for all other vertices $v \ne i$, set `dist[v] = ∞`.
3. Do up to $V-1$ passes: in each pass, scan every directed edge $(u,v,w)$; if `dist[u] + w < dist[v]`, set `dist[v] = dist[u] + w` and `parent[v] = u`. If a full pass makes no changes, stop early.
4. (Optional) Detect negative cycles: if any edge $(u,v,w)$ still satisfies `dist[u] + w < dist[v]`, a reachable negative cycle exists. To extract one, follow `parent` from $v$ for $V$ steps to enter the cycle, then continue until a vertex repeats, collecting the cycle.
5. To get a shortest path to a target $t$ (when no relevant negative cycle exists), follow `parent[t]` backward to $i$.

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

* The *time* complexity of Bellman–Ford is $O(VE)$ because each of the $V-1$ relaxation passes scans all edges; without this understanding, one might underestimate the cost of running it on dense graphs with many edges.
* The *space* complexity is $O(V)$, needed for storing distance estimates and parent pointers; if this is not accounted for, memory use may be underestimated in large-scale applications such as road networks.
* The algorithm *handles negative weights* correctly and can also *detect negative cycles* that are reachable from the source; without this feature, Dijkstra’s algorithm would produce incorrect results on graphs with negative edge costs.
* When a reachable *negative cycle* exists, shortest paths to nodes that can be reached from it are undefined, effectively taking value $-\infty$; without recognizing this, results such as infinitely decreasing profit in arbitrage graphs would be misinterpreted as valid finite paths.

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

* In *shortest path problems with negative edges*, Bellman–Ford is applicable where Dijkstra or A* fail, such as road networks with toll credits; without this method, these graphs cannot be handled correctly.
* For *arbitrage detection* in currency or financial markets, converting exchange rates into $\log$ weights makes profit loops appear as negative cycles; without Bellman–Ford, such opportunities cannot be systematically identified.
* In solving *difference constraints* of the form $x_v - x_u \leq w$, the algorithm checks feasibility by detecting whether any negative cycles exist; without this check, inconsistent scheduling or timing systems may go unnoticed.
* As a *robust baseline*, Bellman–Ford verifies results of faster algorithms or initializes methods like Johnson’s for all-pairs shortest paths; without it, correctness guarantees in sparse-graph all-pairs problems would be weaker.
* For *graphs with penalties or credits*, where some transitions decrease accumulated cost, Bellman–Ford models these adjustments accurately; without it, such systems—like transport discounts or energy recovery paths—cannot be represented properly.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/bellman_ford)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/bellman_ford)

*Implementation tip:* For **all-pairs** on sparse graphs with possible negative edges, use **Johnson’s algorithm**: run Bellman–Ford once from a super-source to reweight edges (no negatives), then run **Dijkstra** from each vertex.

#### A* (A-Star) Algorithm

A* is a best-first search that finds a **least-cost path** from a start to a goal by minimizing

$$
f(n) = g(n) + h(n),
$$

where:

* $g(n)$ = cost from start to $n$ (so far),
* $h(n)$ = heuristic estimate of the remaining cost from $n$ to the goal.

If $h$ is **admissible** (never overestimates) and **consistent** (triangle inequality), A* is **optimal** and never needs to “reopen” closed nodes.

**Core data structures**

* The *open set* is a min-priority queue keyed by the evaluation function $f=g+h$, storing nodes pending expansion; without it, selecting the next most promising state in pathfinding would require inefficient linear scans.
* The *closed set* contains nodes already expanded and finalized, preventing reprocessing; if omitted, the algorithm may revisit the same grid cells or graph states repeatedly, wasting time.
* The *$g$ map* tracks the best known cost-so-far to each node, ensuring paths are only updated when improvements are found; without it, the algorithm cannot correctly accumulate and compare path costs.
* The *parent map* stores predecessors so that a complete path can be reconstructed once the target is reached; if absent, the algorithm would output only a final distance without the actual route.
* An optional *heuristic cache* and *tie-breaker* (such as preferring larger $g$ or smaller $h$ when $f$ ties) can improve efficiency and consistency; without these, the search may expand more nodes than necessary or return different paths under equivalent conditions.

**Algorithm Steps**

1. Put `start` in `open` (a min-priority queue by `f`); set `g[start]=0`, `f[start]=h(start)`, `parent[start]=None`; initialize `closed = ∅`.
2. While `open` is nonempty, repeat steps 3–7.
3. Pop the node `u` with the smallest `f(u)` from `open`.
4. If `u` is the goal, reconstruct the path by following `parent` back to `start` and return it.
5. Add `u` to `closed`.
6. For each neighbor `v` of `u` with edge cost $w(u,v) \ge 0$, set `tentative = g[u] + w(u,v)`.
7. If `v` not in `g` or `tentative < g[v]`, set `parent[v]=u`, `g[v]=tentative`, `f[v]=g[v]+h(v)`, and push `v` into `open` (even if it was already there with a worse key).
8. If the loop ends because `open` is empty, no path exists.

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

* The *time* complexity of A* is worst-case exponential, though in practice it runs much faster when the heuristic $h$ provides useful guidance; without an informative heuristic, the search can expand nearly the entire graph, as in navigating a large grid without directional hints.
* The *space* complexity is $O(V)$, covering the priority queue and bookkeeping maps, which makes A* memory-intensive; without recognizing this, applications such as robotics pathfinding may exceed available memory on large maps.
* In *special cases*, A* reduces to Dijkstra’s algorithm when $h \equiv 0$, and further reduces to BFS when all edges have cost 1 and $h \equiv 0$; without this perspective, one might overlook how A* generalizes these familiar shortest-path algorithms.

**Visual walkthrough (grid with 4-neighborhood, Manhattan $h$)**

Legend: `S` start, `G` goal, `#` wall, `.` free, `◉` expanded (closed), `•` frontier (open), `×` final path

```
Row/Col →    1  2  3  4  5  6  7  8  9
           ┌────────────────────────────┐
         1 │ S  .  .  .  .  #  .  .  .  │
         2 │ .  #  #  .  .  #  .  #  .  │
         3 │ .  .  .  .  .  .  .  #  .  │
         4 │ #  .  #  #  .  #  .  .  .  │
         5 │ .  .  .  #  .  .  .  #  G  │
           └────────────────────────────┘
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
Row/Col →     1  2  3  4  5  6  7  8  9
           ┌─────────────────────────────┐
         1 │  ×  ×  ×  ×  .  #  .  .  .  │
         2 │  ×  #  #  ×  ×  #  .  #  .  │
         3 │  ×  ×  ×  ×  ×  ×  ×  #  .  │
         4 │  #  .  #  #  ×  #  ×  ×  ×  │
         5 │  .  .  .  #  ×  ×  ×  #  G  │
           └─────────────────────────────┘
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

**Heuristic design**

For **grids**:

* *4-dir moves:* $h(n)=|x_n-x_g|+|y_n-y_g|$ (Manhattan).
* *8-dir (diag cost √2):* **Octile**: $h=\Delta_{\max} + (\sqrt{2}-1)\Delta_{\min}$.
* *Euclidean* when motion is continuous and diagonal is allowed.

For **sliding puzzles (e.g., 8/15-puzzle)**:

**Misplaced tiles* (admissible, weak).
* *Manhattan sum* (stronger).
* *Linear conflict / pattern databases* (even stronger).

**Admissible vs. consistent**

* An *admissible* heuristic satisfies $h(n) \leq h^*(n)$, meaning it never overestimates the true remaining cost, which guarantees that A* finds an optimal path; without admissibility, the algorithm may return a suboptimal route, such as a longer-than-necessary driving path.
* A *consistent (monotone)* heuristic obeys $h(u) \leq w(u,v) + h(v)$ for every edge, ensuring that $f$-values do not decrease along paths and that once a node is removed from the open set, its $g$-value is final; without consistency, nodes may need to be reopened, increasing complexity in searches like grid navigation.

**Applications**

* In *pathfinding* for maps, games, and robotics, A* computes shortest or least-risk routes by combining actual travel cost with heuristic guidance; without it, movement planning in virtual or physical environments becomes slower or less efficient.
* For *route planning* with road metrics such as travel time, distance, or tolls, A* incorporates these costs and constraints into its evaluation; without heuristic search, navigation systems must fall back to slower methods like plain Dijkstra.
* In *planning and scheduling* tasks, A* serves as a general shortest-path algorithm in abstract state spaces, supporting AI decision-making; without it, solving resource allocation or task sequencing problems may require less efficient exhaustive search.
* In *puzzle solving* domains such as the 8-puzzle or Sokoban, A* uses problem-specific heuristics to guide the search efficiently; without heuristics, the state space may grow exponentially and become impractical to explore.
* For *network optimization* problems with nonnegative edge costs, A* applies whenever a useful heuristic is available to speed convergence; without heuristics, computations on communication or logistics networks may take longer than necessary.

**Variants & practical tweaks**

* Viewing *Dijkstra* as A* with $h \equiv 0$ shows that A* generalizes the classic shortest-path algorithm; without this equivalence, the connection between uninformed and heuristic search may be overlooked.
* In *Weighted A**, the evaluation function becomes $f = g + \varepsilon h$ with $\varepsilon > 1$, trading exact optimality for faster performance with bounded suboptimality; without this variant, applications needing quick approximate routing, like logistics planning, would run slower.
* The *A*ε / Anytime A** approach begins with $\varepsilon > 1$ for speed and gradually reduces it to converge toward optimal paths; without this strategy, incremental refinement in real-time systems like navigation aids is harder to achieve.
* With *IDA** (Iterative Deepening A*), the search is conducted by gradually increasing an $f$-cost threshold, greatly reducing memory usage but sometimes increasing runtime; without it, problems like puzzle solving could exceed memory limits.
* *RBFS and Fringe Search* are memory-bounded alternatives that manage recursion depth or fringe sets more carefully; without these, large state spaces in AI planning can overwhelm storage.
* In *tie-breaking*, preferring larger $g$ or smaller $h$ when $f$ ties reduces unnecessary re-expansions; without careful tie-breaking, searches on uniform-cost grids may explore more nodes than needed.
* For the *closed-set policy*, when heuristics are inconsistent, nodes must be reopened if a better $g$ value is found; without allowing this, the algorithm may miss shorter paths, as in road networks with varying travel times.

**Pitfalls & tips**

* The algorithm requires *non-negative edge weights* because A* assumes $w(u,v) \ge 0$; without this, negative costs can cause nodes to be expanded too early, breaking correctness in applications like navigation.
* If the heuristic *overestimates* actual costs, A* loses its guarantee of optimality; without enforcing admissibility, a routing system may return a path that is faster to compute but longer in distance.
* With *floating-point precision issues*, comparisons of $f$-values should include small epsilons to avoid instability; without this safeguard, two nearly equal paths may lead to inconsistent queue ordering in large-scale searches.
* In *state hashing*, equivalent states must hash identically so duplicates are merged properly; without this, search in puzzles or planning domains may blow up due to treating the same state as multiple distinct ones.
* While *neighbor order* does not affect correctness, it influences performance and the aesthetics of the returned path trace; without considering this, two identical problems might yield very different expansion sequences or outputs.

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

#### Prim’s Algorithm

Prim’s algorithm builds a **minimum spanning tree (MST)** of a **weighted, undirected** graph by growing a tree from a start vertex. At each step it adds the **cheapest edge** that connects a vertex **inside** the tree to a vertex **outside** the tree.

To efficiently keep track of the construction, Prim’s algorithm employs two primary data structures:

* A **min-priority queue** (often named `pq`, `open`, or `unexplored`) keyed by a vertex’s **best known connection cost** to the current tree.
* A **`in_mst`/`visited` set** to mark vertices already added to the tree, plus a **`parent` map** to record the chosen incoming edge for each vertex.

*Useful additions in practice:*

* A *key map* stores, for each vertex, the lightest edge weight connecting it to the current spanning tree, initialized to infinity except for the starting vertex at zero; without this, Prim’s algorithm cannot efficiently track which edges should be added next to grow the tree.
* With *lazy updates*, when the priority queue lacks a decrease-key operation, improved entries are simply pushed again and outdated ones are skipped upon popping; without this adjustment, priority queues become harder to manage, slowing down minimum spanning tree construction.
* For *component handling*, if the graph is disconnected, Prim’s algorithm must either restart from each unvisited vertex or seed multiple starts with key values of zero to produce a spanning forest; without this, the algorithm would stop after one component, leaving parts of the graph unspanned.

**Algorithm Steps**

1. Pick a start vertex $i$.
2. Set `key[i] = 0`, `parent[i] = None`; for all other vertices $v \ne i$, set `key[v] = ∞`; push $i$ into a min-priority queue keyed by `key`.
3. While the priority queue is nonempty, repeat steps 4–6.
4. Extract the vertex $u$ with the smallest `key[u]`.
5. If $u$ is already in the MST, continue; otherwise add $u$ to the MST and, if `parent[u] ≠ None`, record the tree edge `(parent[u], u)`.
6. For each neighbor $v$ of $u$ with weight $w(u,v)$, if $v$ is not in the MST and $w(u,v) < key[v]$, set `key[v] = w(u,v)`, set `parent[v] = u`, and push $v$ into the priority queue keyed by the new `key[v]`.
7. Stop when the queue is empty or when all vertices are in the MST (for a connected graph).
8. The edges $\{(parent[v], v) : v \ne i\}$ form an MST; the MST total weight equals $\sum key[v]$ at the moments when each $v$ is added.

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

* The *time* complexity of Prim’s algorithm is $O(E \log V)$ with a binary heap, $O(E + V \log V)$ with a Fibonacci heap, and $O(V^2)$ for the dense-graph adjacency-matrix variant; without knowing this, one might apply the wrong implementation and get poor performance on sparse or dense networks.
* The *space* complexity is $O(V)$, required for storing the key values, parent pointers, and bookkeeping to build the minimum spanning tree; without this allocation, the algorithm cannot track which edges belong to the MST.
* The *graph type* handled is a weighted, undirected graph with no restrictions on edge weights being positive; without this flexibility, graphs with negative costs, such as energy-saving transitions, could not be processed.
* In terms of *uniqueness*, if all edge weights are distinct, the minimum spanning tree is unique; without distinct weights, multiple MSTs may exist, such as in networks where two equally light connections are available.

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

* In *network design*, Prim’s or Kruskal’s MST construction connects all sites such as offices, cities, or data centers with the least total cost of wiring, piping, or fiber; without using MSTs, infrastructure plans risk including redundant and more expensive links.
* As an *approximation for the traveling salesman problem (TSP)*, building an MST and performing a preorder walk of it yields a tour within twice the optimal length for metric TSP; without this approach, even approximate solutions for large instances may be much harder to obtain.
* In *clustering with single linkage*, removing the $k-1$ heaviest edges of the MST partitions the graph into $k$ clusters; without this technique, hierarchical clustering may require recomputing pairwise distances repeatedly.
* For *image processing and segmentation*, constructing an MST over pixels or superpixels highlights low-contrast boundaries as cut edges; without MST-based grouping, segmentations may fail to respect natural intensity or color edges.
* In *map generalization and simplification*, the MST preserves a connectivity backbone with minimal redundancy, reducing complexity while maintaining essential routes; without this, simplified maps may show excessive or unnecessary detail.
* In *circuit design and VLSI*, MSTs minimize interconnect length under simple wiring models, supporting efficient layouts; without this method, chip designs may consume more area and power due to avoidable wiring overhead.

##### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/prim)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/python/prim)

*Implementation tip:*
For **dense graphs** ($E \approx V^2$), skip heaps: store `key` in an array and, at each step, scan all non-MST vertices to pick the minimum `key` in $O(V)$. Overall $O(V^2)$ but often **faster in practice** on dense inputs due to low overhead.

#### Kruskal’s Algorithm

Kruskal’s algorithm builds a **minimum spanning tree (MST)** for a **weighted, undirected** graph by sorting all edges by weight (lightest first) and repeatedly adding the next lightest edge that **does not create a cycle**. It grows the MST as a forest of trees that gradually merges until all vertices are connected.

To efficiently keep track of the construction, Kruskal’s algorithm employs two primary data structures:

* A *sorted edge list* arranged in ascending order of weights ensures that Kruskal’s algorithm always considers the lightest available edge next; without this ordering, the method cannot guarantee that the resulting spanning tree has minimum total weight.
* A *Disjoint Set Union (DSU)*, or Union–Find structure, tracks which vertices belong to the same tree and prevents cycles by only uniting edges from different sets; without this mechanism, the algorithm could inadvertently form cycles instead of building a spanning tree.

*Useful additions in practice:*

* Using *Union–Find with path compression and union by rank/size* enables near-constant-time merge and find operations, making Kruskal’s algorithm efficient; without these optimizations, edge processing in large graphs such as communication networks would slow down significantly.
* Applying an *early stop* allows the algorithm to terminate once $V-1$ edges have been added in a connected graph, since the MST is then complete; without this, unnecessary edges are still considered, adding avoidable work.
* Enforcing *deterministic tie-breaking* ensures that when multiple edges share equal weights, the same MST is consistently produced; without this, repeated runs on the same weighted graph might yield different but equally valid spanning trees, complicating reproducibility.
* On *disconnected graphs*, Kruskal’s algorithm naturally outputs a minimum spanning forest with one tree per component; without this property, handling graphs such as multiple separate road systems would require additional adjustments.

**Algorithm Steps**

1. Gather all edges $E=\{(u,v,w)\}$ and sort them by weight $w$ in ascending order.
2. Initialize a DSU with each vertex in its own set: `parent[v]=v`, `rank[v]=0`.
3. Traverse the edges in the sorted order.
4. For the current edge $(u,v,w)$, compute `ru = find(u)` and `rv = find(v)` in the DSU.
5. If `ru ≠ rv`, add $(u,v,w)$ to the MST and `union(ru, rv)`.
6. If `ru = rv`, skip the edge (it would create a cycle).
7. Continue until $V-1$ edges have been chosen (connected graph) or until all edges are processed (forest).
8. The chosen edges form the MST; the total weight is the sum of their weights.

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

* The *time* complexity of Kruskal’s algorithm is dominated by sorting edges, which takes $O(E \log E)$, or equivalently $O(E \log V)$, while DSU operations run in near-constant amortized time; without recognizing this, one might wrongly attribute the main cost to the union–find structure rather than sorting.
* The *space* complexity is $O(V)$ for the DSU arrays and $O(E)$ to store the edges; without this allocation, the algorithm cannot track connectivity or efficiently access candidate edges.
* With respect to *weights*, Kruskal’s algorithm works on undirected graphs with either negative or positive weights; without this flexibility, cases like networks where some connections represent cost reductions could not be handled.
* Regarding *uniqueness*, if all edge weights are distinct, the MST is guaranteed to be unique; without distinct weights, multiple equally valid minimum spanning trees may exist, such as in graphs where two different links have identical costs.

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

* In *network design*, Kruskal’s algorithm builds the least-cost backbone, such as roads, fiber, or pipelines, that connects all sites with minimal total expense; without MST construction, the resulting infrastructure may include redundant and costlier links.
* For *clustering with single linkage*, constructing the MST and then removing the $k-1$ heaviest edges partitions the graph into $k$ clusters; without this method, grouping data points into clusters may require repeated and slower distance recalculations.
* In *image segmentation*, applying Kruskal’s algorithm to pixel or superpixel graphs groups regions by intensity or feature similarity through MST formation; without MST-based grouping, boundaries between regions may be less well aligned with natural contrasts.
* As an *approximation for the metric traveling salesman problem*, building an MST and performing a preorder walk (with shortcutting) yields a tour at most twice the optimal length; without this approach, near-optimal solutions would be harder to compute efficiently.
* In *circuit and VLSI layout*, Kruskal’s algorithm finds minimal interconnect length under simplified wiring models; without this, designs may require more area and energy due to unnecessarily long connections.
* For *maze generation*, a randomized Kruskal process selects edges in random order while maintaining acyclicity, producing mazes that remain connected without loops; without this structure, generated mazes could contain cycles or disconnected regions.

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

* Maintaining a *visited count* or tracking the length of the output order lets you detect cycles, since producing fewer than $V$ vertices indicates that some could not be placed due to a cycle; without this check, algorithms like Kahn’s may silently return incomplete results on cyclic task graphs.
* Using a *min-heap* instead of a simple FIFO queue ensures that, among available candidates, the smallest-indexed vertex is always chosen, yielding the lexicographically smallest valid topological order; without this modification, the output order depends on arbitrary queueing, which may vary between runs.
* A *DFS-based alternative* computes a valid topological order by recording vertices in reverse postorder, also in $O(V+E)$ time, while detecting cycles via a three-color marking or recursion stack; without DFS, cycle detection must be handled separately in Kahn’s algorithm.

**Algorithm Steps (Kahn’s algorithm)**

1. Compute `indegree[v]` for every vertex $v$; set `order = []`.
2. Initialize a queue `Q` with all vertices of indegree 0.
3. While `Q` is nonempty, repeat steps 4–6.
4. Dequeue a vertex `u` from `Q` and append it to `order`.
5. For each outgoing edge `u → v`, decrement `indegree[v]` by 1.
6. If `indegree[v]` becomes 0, enqueue `v` into `Q`.
7. If `len(order) < V` at the end, a cycle exists and no topological order; otherwise `order` is a valid topological ordering.

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

* The *time* complexity of topological sorting is $O(V+E)$ because each vertex is enqueued exactly once and every edge is processed once when its indegree decreases; without this efficiency, ordering tasks in large dependency graphs would be slower.
* The *space* complexity is $O(V)$, required for storing indegree counts, the processing queue, and the final output order; without allocating this space, the algorithm cannot track which vertices are ready to be placed.
* The required *input* is a directed acyclic graph (DAG), since if a cycle exists, no valid topological order is possible; without this restriction, attempts to schedule cyclic dependencies, such as tasks that mutually depend on each other, will fail.

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

* In *build systems and compilation*, topological sorting ensures that each file is compiled only after its prerequisites are compiled; without it, a build may fail by trying to compile a module before its dependencies are available.
* For *course scheduling*, topological order provides a valid sequence in which to take courses respecting prerequisite constraints; without it, students may be assigned courses they are not yet eligible to take.
* In *data pipelines and DAG workflows* such as Airflow or Spark, tasks are executed when their inputs are ready by following a topological order; without this, pipeline stages might run prematurely and fail due to missing inputs.
* For *dependency resolution* in package managers or container systems, topological sorting installs components in an order that respects their dependencies; without it, software may be installed in the wrong sequence and break.
* In *dynamic programming on DAGs*, problems like longest path, shortest path, or path counting are solved efficiently by processing vertices in topological order; without this ordering, subproblems may be computed before their dependencies are solved.
* For *circuit evaluation or spreadsheets*, topological order ensures that each cell or net is evaluated only after its referenced inputs; without it, computations could use undefined or incomplete values.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/cpp/topological_sort)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/graphs/topological_sort/kruskal)

*Implementation tips:*

* Use a **deque** for FIFO behavior; use a **min-heap** to get the **lexicographically smallest** topological order.
* When the graph is large and sparse, store adjacency as **lists** and compute indegrees in one pass for $O(V+E)$.
* **DFS variant** (brief): color states `0=unseen,1=visiting,2=done`; on exploring `u`, mark `1`; DFS to neighbors; if you see `1` again, there’s a cycle; on finish, push `u` to a stack. Reverse the stack for the order.
