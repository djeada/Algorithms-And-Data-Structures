# Graphs

Many real life situations involve objects that are connected in some way to other objects, such as:

* underground tunnel network;
* network of pipes;
* railway map;
* cities linked by flights;
* countries and their political alliances.

To model such examples, we will use a data structure known as a graph.

<h2>Graph terminology</h2>

There is a lot of vocabulary that allows us to exactly define graphs.

A graph <i>G</i> consists of a set <code>V(G)</code> called vertices (or points or nodes) together with a set <code>E(G)</code> of pairs of vertices. 
Each pair <code>{x, y} ∈ E(G)</code> is called an edge (or link or line) of <i>G</i>.

If <code>{x, y} ∈ E(G)</code>, we say that <i>x</i> and <i>y</i> are <b>adjacent</b> to each other. The number of vertices adjacent to <i>v</i> is called the degree of <i>v</i>. The sum of the degrees of the vertices of a graph is even.

<b>A path</b> of length <i>n</i> in a graph is a sequence of vertices <code>v_1 ∼ v_2 ∼ ··· ∼ v_(n+1)</code> such that <code>(v_i, v_(i+1)) ∈ E(G)</code> and vertices <code>{v_1, v_2,...,v_(n+1)}</code> are distinct.

<b>A cycle</b> of length n is a sequence of vertices <code>v_1 ∼ v_2 ∼ ··· v+n ∼ v_(n+1)</code> such that <code>v_1 = v_(n+1), (v_i, v_(i+1)) ∈ E(G)</code> and therefore only vertices <code>{v_1, v_2,...,v_n}</code> are distinct.

<b>The distance</b> between two vertices <i>x</i> and <i>y</i> in a graph is the length of the shortest path between them.

In a <b>simple graph</b>  has no <i>self-loops</i> (i.e., edges connected at both ends to the same vertex) and no more than one edge connecting any pair of vertices.

In a <b>directed graph</b>, an edge is an ordered pair of vertices, and hence has a direction. In directed graphs, edges are often called arcs. In <b>undirected graphs</b>, we assume that every edge can be considered as going both ways, that is, an edge between A and B can be viewed as a way from A to B and from B to A.

In a <b>weighted graph</b>, each of the edges is assigned a weight (usually a non-negative integer).

An undirected graph is <b>connected</b> if every pair of vertices is connected by a path. The concept of connection has two unique variants in directed graphs: 

* A digraph is said to be <b>weakly connected</b> if there is either a path from A to B or a path from B to A for every two vertices A and B. 
* If there are pathways leading both ways, we say it is <b>strongly connected</b>.

If two vertices A and B are joined by an edge e, we call them <b>neighbours</b>, and the edge linking them is called <b>incident</b> to A and B. Two edges that share a vertex (for example, one linking A and B and one connecting B and C) are referred to be <b>adjacent</b>.

<h1>Representation of graphs</h1>

<h2>Array-based implementation.</h2>

<b>The adjacency matrix</b> of a graph <i>G</i> is a <code>V × V</code> matrix <i>A</i> where the rows and columns are indexed by the vertices and such that <code>A_(ij) = 1 </code> if and only if vertex <i>i</i> is adjacent to vertex <i>j</i> and is equal to 0 otherwise. For weighted graphs other values representing the respective weights might be stored in the array.


|   |   |   |   |   |
|---|---|---|---|---|
|-|__A__|__B__|__C__|__D__|
|__A__| 1 | 0 | 1 | 1 |
|__B__| 1 | 1 | 1 | 0 |
|__C__| 1 | 0 | 0 | 1 |
|__D__| 0 | 0 | 1 | 1 |

This only works if the graph is explicitly defined, that is, if we know how many vertices there will be and which pairs will have edges between them.

<h2>Pointer-based implementation</h2>

The graph <i>G</i> is represented by an array of <code>|V(G)|</code> linked lists, with each list containing the neighbours of the vertex.

```
| A | -> | B | D |
| B | -> | A | C | D |
| C | -> | B | D |
| D | -> | A |
```

<h1>Planarity</h1>
A planar graph is one that may be fitted onto a plane. In other words, it may be drawn on a piece of paper so that no edges cross each other. This is crucial in applications such as printed circuit design.
It is obvious that planar graphs may be drawn in such a manner that their edges cross, but the important issue is that they can be transformed into a form with no edges crossing.
General techniques for assessing if a given graph is planar are really fairly difficult to develop. It is straightforward to confirm systematically for small graphs that there are no feasible vertex repositionings or edge deformations that would put the graph into explicitly planar shape, but it gets complicated quite fast for bigger graphs.

<h1>Minimal spanning trees</h1>

<h1>Traversals</h1>
Traversing a graph entails visiting all of its vertices in a methodical manner. We definitely want a mechanism for examining graphs that ensures we do not overlook any edges or vertices. Because graphs, unlike trees, do not have a root vertex, there is no obvious vertex to begin a traversal, thus we suppose we are provided, or randomly choose, a beginning vertex <i>i</i>.

<h2> BFS </h2>

We need two additional containers:

* a queue called unexplored.
* a hash table called visited.

We begin with the vertex <i>i</i> that has been handed to us. Then, one by one, we visit its neighbors, adding them to the <i>unexplored</i> queue. The initial vertex is then removed from the queue. We then go to the next vertex in the queue and place its neighbors at the end of the queue once more. This is repeated until the queue is empty.

However, there is no reason why this simple method should ever terimnate. If there is a circle in the graph, we will return to a vertex we have previously visited, resulting in an infinite loop. We utilize the hash table <i>visited</i> to prevent this. Initially, all <code>visted[v] = false</code>. Then, after each visited vertex, we set it to <i>true</i>.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h2> DFS </h2>

We need two additional containers:

* a stack called unexplored.
* a hash table called visited.

We start with the vertex <i>i</i> that was handed to us. We move it to a stack rather than a queue. Then we remove it from the stack, mark it as visited, look up its neighbors one by one, and place them back on the stack. We then continuously remove the next vertex from the stack, mark it as visited, and place its neighbors on the stack, assuming they have not already been marked as visited.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1> Dijkstra </h1>

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1> A* </h1>

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1> Bellman-Ford </h1>

- Invented in 1958
- Running time is O(V*E)
- It is slower than Dijkstra's algorithm, but it is more robust: it can also handle negative edge weights.
- The Dijkstra algorithm chooses the edge with the lowest cost in a greedy manner: For V-1 iteration, Bellman-Ford relaxes all edges at the same time.
- Does V-1 iteration + 1 to detect cycles: if cost decreases in the V-th iteration, there is a negative loop, since all paths have been explored up to the V-1 iteration.

<h2>Applications</h2>
- RIP ,,Routing Information Protocol”

<h2>Algorithm</h2>
* Each node calculates and stores the distances between itself and all other nodes in a table.
* Each node sends its table to all adjacent nodes
* When a node receives distance tables from its neighbors, it determines the shortest routes to all other nodes and updates its own table accordingly.

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1> Kruskal </h1>

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1> Prim </h1>

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>
