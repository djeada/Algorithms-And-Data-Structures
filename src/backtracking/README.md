# Backtracking
A general algorithm for locating all solutions to certain computational problems, especially constraint satisfaction problems.

Builds candidates to solutions incrementally, abandoning each partial candidate A ("backtracks") until it decides that A cannot be completed to a valid solution.

Since it can reject a large number of candidates with a single test, backtracking is also much quicker than brute force complete enumeration of all candidates.

Backtracking is a useful technique for solving constraint satisfaction problems like combinatorial optimization.

<h1>The method </h1>

The nodes of a tree structure, the possible search tree, are used to represent the partial candidates. Each partial candidate is the parent of candidates that differ by a single extension step from it. The tree's leaves represent partial candidates who can't be expanded any further.

The backtracking algorithm traverses this search tree in depth-first order, recursively, from the root down.

Backtracking is often referred to as "depth-first search!

- The algorithm examines each node to see if it a correct solution can be found.
- If not, the node is skipped.
- If yes, recursively enumerates all subtrees of the node.

<h1>8 Queens problem </h1>

The problem of arranging N chess queens on a NxN chessboard in such a way that none of them threaten each other.

The problem was originally intended for eight queens. This was a topic that Gauss studied.

This problem was used by Dijkstra to demonstrate the influence of formal programming.
