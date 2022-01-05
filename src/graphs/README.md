# Graphs
A graph G consists of a set V(G) called vertices together with a collection E(G) of pairs of vertices. 
Each pair {x, y} ∈ E(G) is called an edge of G.

If {x, y} ∈ E(G), we say that x and y are <b>adjacent</b> to each other. The number of vertices adjacent to v is called the degree of v. The sum of the degrees of the vertices of a graph is even.

<b>A path</b> of length n in a graph is a sequence of vertices v1 ∼ v2 ∼ ··· ∼ vn+1 such that (vi, vi+1) ∈ E(G) and vertices {v1, v2,...,vn+1} are distinct.

<b>A cycle</b> of length n is a sequence of vertices v1 ∼ v2 ∼ ··· vn ∼ vn+1 such that v1 = vn+1, (vi, vi+1) ∈ E(G) and therefore only vertices {v1, v2,...,vn} are distinct.

<b>The distance</b>  between two vertices x and y in a graph is the length of the shortest path between them.

In a <b>directed graph</b>, an edge is an ordered pair of vertices, and hence has a direction. In directed graphs, edges are often called arcs.

Directed Tree Each vertex has at most one directed edge leading into it, and there is one vertex (the root) which has a path to every other vertex.

In a weighted graph, each of the edges is assigned a weight (usually a non-negative integer).

<h2>Representation of graphs</h2>
<b>Adjacency lists</b> The graph G is represented by an array of |V (G)| linked lists, with each list containing the neighbours of a vertex.

<b>The adjacency matrix</b> of a graph G is a V × V matrix A where the rows and columns are indexed by the vertices and such that Aij = 1 if and only if vertex i is adjacent to vertex j.

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
