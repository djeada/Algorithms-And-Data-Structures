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

<b>The adjacency matrix</b> of a graph G is a V × V matrix A where the rows and columns are indexed by the vertices and such that Aij = 1 if and only if vertex i is adjacent to vertex j.

<b>Adjacency lists</b> The graph G is represented by an array of |V (G)| linked lists, with each list containing the neighbours of a vertex.

<h1>Traversals</h1>
systematically visiting all vertices

<h1> BFS </h1>

<h2>Implementation</h2>

* <a href=””>C++</a>
* <a href=””>Python</a>

<h1> DFS </h1>

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
