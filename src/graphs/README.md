# Graphs

Many real life situations involve objects that are connected in some way to other objects, such as:

* underground tunnel network;
* network of pipes;
* carbon atoms in a molecule.
* railway map;
* cities linked by flights;
* countries and their political alliances.

To model such examples, we will use a data structure known as a graph.

## Graph terminology

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

#Representation of graphs

## Array-based implementation.

<b>The adjacency matrix</b> of a graph <i>G</i> is a <code>V × V</code> matrix <i>A</i> where the rows and columns are indexed by the vertices and such that <code>A_(ij) = 1 </code> if and only if vertex <i>i</i> is adjacent to vertex <i>j</i> and is equal to 0 otherwise. For weighted graphs other values representing the respective weights might be stored in the array.


|   |   |   |   |   |
|---|---|---|---|---|
|-|__A__|__B__|__C__|__D__|
|__A__| 1 | 0 | 1 | 1 |
|__B__| 1 | 1 | 1 | 0 |
|__C__| 1 | 0 | 0 | 1 |
|__D__| 0 | 0 | 1 | 1 |

This only works if the graph is explicitly defined, that is, if we know how many vertices there will be and which pairs will have edges between them.

## Pointer-based implementation

The graph <i>G</i> is represented by an array of <code>|V(G)|</code> linked lists, with each list containing the neighbours of the vertex.

```
A -> [B, D]
B -> [A, C, D]
C -> [B, D]
D -> [A]
```

## Planarity
A planar graph is one that may be fitted onto a plane. In other words, it may be drawn on a piece of paper so that no edges cross each other. This is crucial in applications such as printed circuit design.

It is obvious that planar graphs may be drawn in such a manner that their edges cross, but the important issue is that they can be transformed into a form with no edges crossing.

General techniques for assessing if a given graph is planar are really fairly difficult to develop. It is straightforward to confirm systematically for small graphs that there are no feasible vertex repositionings or edge deformations that would put the graph into explicitly planar shape, but it gets complicated quite fast for bigger graphs.

# Traversals
Traversing a graph entails visiting all of its vertices in a methodical manner. We definitely want a mechanism for examining graphs that ensures we do not overlook any edges or vertices. Because graphs, unlike trees, do not have a root vertex, there is no obvious vertex to begin a traversal, thus we suppose we are provided, or randomly choose, a beginning vertex <i>i</i>.

Important: The order of the vertices in both breadth first search and depth first search depends on the implementation. If our starting vertex A has three neighbors, C, F, and G, there is no reason for one to be processed before the others. As a consequence, instead of speaking about the result, it is preferable to speak about a result of such algorithms.

## BFS

We need two additional containers:

* a queue called unexplored.
* a hash table called visited.

We begin with the vertex <i>i</i> that has been handed to us. Then, one by one, we visit its neighbors, adding them to the <i>unexplored</i> queue. The initial vertex is then removed from the queue. We then go to the next vertex in the queue and place its neighbors at the end of the queue once more. This is repeated until the queue is empty.

However, there is no reason why this simple method should ever terimnate. If there is a circle in the graph, we will return to a vertex we have previously visited, resulting in an infinite loop. We utilize the hash table <i>visited</i> to prevent this. Initially, <code>visted[v] = false</code> for all vertices <code>v ∈ V(G)</code>. Then, after each visited vertex, we set it to <i>true</i>.

## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>

## DFS

We need two additional containers:

* a stack called unexplored.
* a hash table called visited.

We start with the vertex <i>i</i> that was handed to us. We move it to a stack rather than a queue. Then we remove it from the stack, mark it as visited, look up its neighbors one by one, and place them back on the stack. We then continuously remove the next vertex from the stack, mark it as visited, and place its neighbors on the stack, assuming they have not already been marked as visited.

## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>

# Shortest paths

Common task when dealing with weighted graphs is to find the shortest route from vertex A to vertex B. Note that there need not be a unique shortest path, since several paths might have the same length.

## Dijkstra

It turns out that if we wish to compute the shortest path from a given vertex A to a given vertex B, it is actually more convenient to compute the shortest routes from A to all other vertices and then choose the interesting distance. The Dijsktra algorithm works in this manner.

* <b>Input</b>: A weighted graph and a start vertex A.
* <b>Output</b>: An array of distances.

We need three additional containers:

* an array called distances indexed by the vertices.
* a hash table called finished.
* optional: a priority queue.

## Overestimation of shortest paths.

Distances are initialized using <code>distances[v] = ∞</code> for all vertices <code>v ∈ V(G)</code>. Then, starting with vertex A, set <code>distances[A] = 0</code>.The algorithm then reduces the overestimations continually until they can no longer be reduced any further. When this occurs, the algorithm is terminated.

## Improving estimates.
The fundamental goal is to search for shortcuts in a methodical manner. Assume that for two given vertices C and D, <code>distances[C] + weights[C][D] < distances[D]</code>. Then there is a path from A to D and then to z that has a shorter total length than the current overestimate <code>distances[D]</code>, and we can replace <code>distances[D]</code> with this better estimate.

1. Repeat the following steps as many times as there are vertices in the graph:
2. Find a vertex <i>v</i> with <code>finished[v]</code> equal to false and set it to true.
3. Iterate over each vertex <i>u</i> adjacent to <i>v</i>.
4. Update the distances array <code>distances[u] = distances[v] + weights[v][u]</code> if <code>distances[v] + weights[v][u] < distances[u]</code>.

## Improving the time complexity
                                  
The time complexity of the above Dijkstra’s algorithm implementation is <code>O(n^2)</code>.
  
It may be optimized by using a priority queue to track which vertices can be marked as finished next. When choosing the next vertex <i>v</i> for evaluation, we can choose the vertex with the lowest priority from the queue. And in the most inner loop, while iterating over the vertex <i>v</i>'s neighbors called <i>u</i>, we modify the priority of vertex <i>u</i> in the queue to <code>distances[u]</code>.

Thus, the time complexity for Dijkstra algorithm can be improved to <code>O(nlogn)</code> for sparse graphs.
                               
## Applications
                               
* internet packet routing (since a message sent from your computer to someone else must pass through several routers before arriving at its final destination);
* train-ticket reservation systems (it must be able to provide the user with the cheapest and fastest connections);
* driving route finders.

## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>

## Bellman-Ford

- Invented in 1958
- Running time is O(V*E)
- It is slower than Dijkstra's algorithm, but it is more robust: it can also handle negative edge weights.
- The Dijkstra algorithm chooses the edge with the lowest cost in a greedy manner: For V-1 iteration, Bellman-Ford relaxes all edges at the same time.
- Does V-1 iteration + 1 to detect cycles: if cost decreases in the V-th iteration, there is a negative loop, since all paths have been explored up to the V-1 iteration.

## Applications
- RIP "Routing Information Protocol"

## Algorithm
* Each node calculates and stores the distances between itself and all other nodes in a table.
* Each node sends its table to all adjacent nodes
* When a node receives distance tables from its neighbors, it determines the shortest routes to all other nodes and updates its own table accordingly.

## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>
  
## A*

## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>

# Minimal spanning trees

Suppose we have a graph that represents a web of houses. Weights represent the distances between vertices, which each represent a single house. All houses must have water, electricity, and internet, but we want the cost of installation to be as low as possible. We need to identify a subgraph of our graph with the following properties:

* there are no cycles in the graph.
* all vertices are connected.
* the total sum of weights is minimum.

Such a subgraph is called a minimal spanning tree.
  
## Prim

A greedy vertex-based approach. A greedy algorithm is defined as one that makes a locally optimum choice at each stage. A greedy algorithm is one in which no overall strategy is followed, but instead you simply do whatever appears to be the best at the time.
  
Any vertex not in the tree but connected to it by an edge can be added to the tree. To find a minimal spanning tree, we must be picky - we must always add a new vertex with the lowest cost of the new edge. By constantly adding the smallest edge that touches a vertex in the current tree, we produce a minimum spanning tree.

## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>
    
## Kruskal

A greedy edge-based approach. Our greedy choice is to take the next available edge with the smallest weight.

In a graph with <code>n</code> vertices, we keep adding the edge with the smallest weight while avoiding the formation of cycles until <code>n - 1</code> edges are added. Two or more edges may have the same weight at times. In this scenario, the order in which the edges are picked is irrelevant. Different minimal spanning trees may be produced, but they will always have the same overall cost, which will always be the minimum.
  
## Kruskal vs Prim
  
  Take note of the differences in the algorithms: Kruskal's approach always keeps a spanning subgraph, which only becomes a tree at the end.
Prim's method, on the other hand, always maintains a tree that only becomes spanning in the end.
  
## Implementation

* <a href=””>C++</a>
* <a href=””>Python</a>
