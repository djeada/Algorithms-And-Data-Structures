# Graphs

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
