# Graphs

<h1> Bellman-Ford </h1>

- Invented in 1958
- Slower than Dijkstra'’s but more robust: it can handle negative edge weights too
- Dijkstra algorithm choose the edge greedely, with the lowest cost: Bellman-Ford relaxes all edges at the same time for V-1 iteration
- Running time is O(V*E)
- Does V-1 iteration + 1 to detect cycles: if cost decreases in the V-th iteration, than there is a negative cycle, because all the paths are traversen up to the V-1 iteration.
