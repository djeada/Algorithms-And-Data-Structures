## Recursive Functions

A recursive function is a function that calls itself, either directly or indirectly, in its definition. It solves a problem by breaking it down into smaller subproblems, and then solves those subproblems by calling itself recursively.

For example, consider the problem of computing the factorial of a number n ($n! = n * (n-1) * (n-2) * ... * 1$). One way to solve this problem is to use a recursive function:

```
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)
```

In this example, the function calls itself with a smaller value of n until it reaches the base case (n == 1). At that point, it returns the result (1) and the recursive calls start to unwind, returning the final result.

## Depth-First Search (DFS)

Depth-first search (DFS) is an algorithm for traversing a graph or a tree. It starts at the root (or some arbitrary node) and explores as far as possible along each branch before backtracking.

For example, consider the following tree:

```
   A
  / \
 B   C
    / \
   D   E
```

A depth-first search starting at A would first visit A, then B, and then backtrack to A and visit C, D, and E.

DFS can be implemented using a stack data structure, where the nodes to be visited are pushed onto the stack and popped off in the reverse order that they were added. When a node is popped off the stack, its children are examined and pushed onto the stack if they have not been visited yet.

DFS is often used in combination with backtracking, as it allows us to explore all possible paths in a tree or graph and backtrack when we reach a dead end.

## When to use backtracking

Backtracking is an efficient method to solve problems that have multiple solutions. It can also be used to find all possible solutions for a problem.

### Examples

* Finding all possible combinations of words formed by a set of characters.
* Generating all possible permutations of a given set of numbers.
* Solving the 8 queens puzzle.
* Finding all possible paths from top-left to bottom-right of a matrix, given that you can only move right or down.

### Advantages

* Efficient for certain types of problems.
* Can find all possible solutions for a problem.

### Disadvantages

* Can be slow for large problems.
* May require a large amount of memory to store the search tree.

### Conclusion

Backtracking is a useful technique for solving constraint satisfaction problems and combinatorial optimization. It is efficient for certain types of problems and can find all possible solutions, but it may be slow for large problems and require a large amount of memory.

## How to build a backtracking algorithm?

To build a backtracking algorithm, follow these steps:

1. Identify the base case(s) for the problem. These are the conditions under which the algorithm should stop searching for solutions and return a result.
1. Set up a recursive function that takes in the current state of the candidate solution and any relevant parameters.
1. Within the function, check if the current state is a valid solution or if it has reached one of the base cases. If either of these conditions is met, return a result.
1. If the current state is not a valid solution and the base case has not been reached, generate a list of potential next steps or "choices" that can be taken from the current state.
1. Iterate through the list of choices and, for each choice, make the change to the current state and recursively call the function with the updated state.
1. If the function returns a result for any of the choices, return that result. If the function returns without finding a result for any of the choices, return "no result" or backtrack to the previous state.
1. Repeat this process until a valid solution is found or all possibilities have been exhausted.

It is important to note that backtracking algorithms can be computationally expensive, as they may need to explore a large number of possibilities before finding a solution. However, they can be very effective for problems with a small search space or for problems where it is easy to quickly check if a candidate solution is valid.

## List of problems

### Permutations

Generate all possible permutations of a given list of elements.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_permutations">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_permutations">Python</a>

### Combinations

Generate all possible combinations of k elements from a given list of elements.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_combinations">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_combinations">Python</a>

### String Pattern

Determine if a given string follows a given pattern, where the pattern can contain letters and wildcards representing any character.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/string_pattern">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/string_pattern">Python</a>

### Generating Words

Generate all possible words that can be formed by a given list of characters and match a given pattern, where the pattern can contain letters and wildcards representing any character.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/generating_words">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/generating_words">Python</a>

### Hamiltonian Path

Determine if a simple path exists in a given undirected or directed graph that visits every vertex exactly once. This problem, also known as the "traveling salesman problem," can be solved using a depth-first search algorithm that starts at a vertex and checks if all the vertices in the graph have been visited. If not, the algorithm backtracks and tries a different path.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/hamiltonian_paths">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/hamiltonian_paths">Python</a>

### K-Colorable Configurations

Find all the ways to color a given graph with K colors such that no two adjacent vertices have the same color. This problem can be solved using a depth-first search algorithm that starts at a vertex and tries different colors for it. The algorithm then recursively explores the rest of the graph, making sure that no two adjacent vertices have the same color. If the algorithm is able to color all the vertices, it adds the current configuration to the list of solutions. If the algorithm is unable to color a vertex, it backtracks and tries a different color.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/k_colorable_configurations">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/k_colorable_configurations">Python</a>

### Knight Tour

Given a chessboard of size n x n, use a depth-first search algorithm to find all possible paths a knight can take to visit every square on the board exactly once. The algorithm starts at a square and tries all possible moves, adding each visited square to a tour. If the algorithm is able to visit all the squares, it adds the current tour to the list of solutions. If the algorithm is unable to visit a square, it backtracks and tries a different move. The algorithm can be optimized by using a heuristic that prioritizes moves that lead to squares that have not been visited yet.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/knight_tour">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/knight_tour">Python</a>

### Topological Orderings

Find a topological ordering of the vertices in a given directed graph, if one exists. A topological ordering is an ordering of the vertices such that for every edge (u, v), u comes before v in the ordering.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/topological_sort">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/topological_sort">Python</a>

### Tic-Tac-Toe (Minimax)

Determine the best move for a player to make in a tic-tac-toe board using the minimax algorithm. The minimax algorithm is a decision-making strategy that aims to maximize the player's score while minimizing the opponent's score.

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/minimax">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/minimax">Python</a>
