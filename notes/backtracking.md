# Backtracking

Backtracking is a systematic method for solving problems that incrementally build candidates to the solutions and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution. This approach is often used for constraint satisfaction problems, combinatorial optimization, and puzzles like the N-Queens problem or Sudoku.

## Recursive Functions

Recursive functions are functions that call themselves directly or indirectly to solve a problem by breaking it down into smaller, more manageable subproblems. This concept is fundamental in computer science and mathematics, as it allows for elegant solutions to complex problems through repeated application of a simple process.

### Key Concepts:

1. **Base Case (Termination Condition)** is the condition under which the recursion stops. It prevents infinite recursion by providing an explicit solution for the simplest instance of the problem.
2. **Recursive Case** is the part of the function where it calls itself with a modified parameter, moving towards the base case.

### Mathematical Foundation:

Recursion closely relates to mathematical induction, where a problem is solved by assuming that the solution to a smaller instance of the problem is known and building upon it.

A recursive function can often be expressed using a recurrence relation:

$$ f(n) = 
   \begin{cases} 
      g(n) & \text{if } n = \text{base case} \\
      h(f(n - 1), n) & \text{otherwise}
   \end{cases}
$$

where:

- $g(n)$ is the base case value,
- $h$ is a function that defines how to build the solution from the smaller instance.

### Example: Calculating Factorial

The factorial of a non-negative integer $n$ is the product of all positive integers less than or equal to $n$. Mathematically, it is defined as:

$$ n! = 
   \begin{cases}
      1 & \text{if } n = 0 \\
      n \times (n - 1)! & \text{if } n > 0
   \end{cases}
$$

#### Python Implementation:

```python
def factorial(n):
    if n == 0:
        return 1  # Base case: 0! = 1
    else:
        return n * factorial(n - 1)  # Recursive case
```

#### Detailed Computation for $n = 5$:

Let's trace the recursive calls for `factorial(5)`:

1. **Call**: `factorial(5)`
   - Since $5 \neq 0$, compute $5 \times factorial(4)$.
2. **Call**: `factorial(4)`
   - Compute $4 \times factorial(3)$.
3. **Call**: `factorial(3)`
   - Compute $3 \times factorial(2)$.
4. **Call**: `factorial(2)`
   - Compute $2 \times factorial(1)$.
5. **Call**: `factorial(1)`
   - Compute $1 \times factorial(0)$.
6. **Call**: `factorial(0)`
   - Base case reached: return $1$.

Now, we backtrack and compute the results:

1. `factorial(1)` returns $1 \times 1 = 1$.
2. `factorial(2)` returns $2 \times 1 = 2$.
3. `factorial(3)` returns $3 \times 2 = 6$.
4. `factorial(4)` returns $4 \times 6 = 24$.
5. `factorial(5)` returns $5 \times 24 = 120$.

Thus, $5! = 120$.

### Visualization with Recursion Tree:

Each recursive call can be visualized as a node in a tree:

```
factorial(5)
|
+-- factorial(4)
    |
    +-- factorial(3)
        |
        +-- factorial(2)
            |
            +-- factorial(1)
                |
                +-- factorial(0)
```

The leaves represent the base case, and the tree unwinds as each recursive call returns.

### Important Considerations:

- **Termination:** Ensure that all recursive paths eventually reach a base case.
- **Stack Depth:** Each recursive call adds a new frame to the call stack. Deep recursion can lead to stack overflow.
- **Efficiency:** Recursive solutions can be elegant but may not always be the most efficient in terms of time and space.

---

## Depth-First Search (DFS)

Depth-First Search is an algorithm for traversing or searching tree or graph data structures. It starts at a selected node and explores as far as possible along each branch before backtracking.

### Key Concepts:

- **Traversal Strategy:** DFS explores a branch to its deepest point before moving to another branch.
- **Implementation:** Can be implemented using recursion or an explicit stack data structure.
- **Applications:** Used in topological sorting, finding connected components, solving puzzles, and more.

### Algorithm Steps:

1. **Start at the Root Node:**
   - Mark the node as visited.
2. **Explore Each Branch:**
   - For each unvisited neighbor, recursively perform DFS.
3. **Backtrack:**
   - When all neighbors are visited, return to the previous node.

### Pseudocode:

```pseudo
DFS(node):
    mark node as visited
    for each neighbor in node.neighbors:
        if neighbor is not visited:
            DFS(neighbor)
```

### Example: Tree Traversal

Consider the following tree:

```
       A
      / \
     B   C
        / \
       D   E
```

Traversal using DFS starting from node 'A':

1. Visit 'A'.
2. Move to 'B'.
   - 'B' has no unvisited neighbors; backtrack to 'A'.
3. Move to 'C'.
4. Move to 'D'.
   - 'D' has no unvisited neighbors; backtrack to 'C'.
5. Move to 'E'.
   - 'E' has no unvisited neighbors; backtrack to 'C', then 'A'.

Traversal order: A → B → C → D → E

### Implementation in Python:

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.children = []
        self.visited = False

def dfs(node):
    node.visited = True
    print(node.value)
    for child in node.children:
        if not child.visited:
            dfs(child)

# Create nodes
node_a = Node('A')
node_b = Node('B')
node_c = Node('C')
node_d = Node('D')
node_e = Node('E')

# Build the tree
node_a.children = [node_b, node_c]
node_c.children = [node_d, node_e]

# Perform DFS
dfs(node_a)
```

### Analysis:

- **Time Complexity:** $O(V + E)$, where $V$ is the number of vertices and $E$ is the number of edges.
- **Space Complexity:** $O(V)$, due to the recursion stack and the visited flag.

### Applications:

- **Cycle Detection in Graphs**
- **Topological Sorting**
- **Solving Mazes and Puzzles**
- **Connected Components in Networks**

---

## Backtracking

Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, removing solutions that fail to satisfy the constraints at any point.

### Key Concepts:

- **Partial Solutions:** Building solutions one piece at a time and evaluating them against the constraints.
- **Constraints Checking:** Early detection of invalid solutions to prune the search space.
- **Backtracking:** When a partial solution cannot be extended to a complete solution, the algorithm backtracks to try different options.

### General Algorithm Framework:

1. **Define the Solution Space:** Understand the possible configurations of the solution.

2. **Recursive Function:**
   - Start with an empty solution.
   - At each step, try to add a new component to the solution.

3. **Constraints Checking:**
   - After adding a component, check if the partial solution is valid.
   - If not valid, backtrack.

4. **Base Case:**
   - If the partial solution is complete and valid, record or output it.

5. **Backtracking:**
   - If all options are exhausted at a level, remove the last component and backtrack to the previous level.

### Example: N-Queens Problem

#### Problem Statement:

Place $N$ queens on an $N \times N$ chessboard such that no two queens threaten each other.

#### Constraints:

- No two queens share the same row, column, or diagonal.

#### Solution Representation:

- Use a list or array where the index represents the row and the value represents the column position of the queen.

#### Python Implementation:

```python
def solve_n_queens(N):
    solutions = []
    board = [-1] * N  # board[row] = column position of queen in that row

    def is_safe(row, col):
        for i in range(row):
            if (board[i] == col or
                board[i] - i == col - row or
                board[i] + i == col + row):
                return False
        return True

    def place_queen(row):
        if row == N:
            solutions.append(board.copy())
            return
        for col in range(N):
            if is_safe(row, col):
                board[row] = col
                place_queen(row + 1)
                board[row] = -1  # Backtrack

    place_queen(0)
    return solutions

# Example usage:
solutions = solve_n_queens(4)
print(f"Number of solutions: {len(solutions)}")
for sol in solutions:
    print(sol)
```

#### Explanation:

- **Recursive Function `place_queen`:** Tries to place a queen in a row.
- **Safety Check `is_safe`:** Ensures the queen does not conflict with previously placed queens.
- **Backtracking:** If placing a queen leads to no solution, remove it and try the next position.

### Visualization of Backtracking Tree:

At each node, the algorithm tries a new position for a queen. If it reaches a dead end, it backtracks to the previous node and tries the next position.

### Applications:

1. **Sudoku Solving:** Filling a grid while adhering to the constraints.
2. **Permutation and Combination Generation:** Generating all possible arrangements.
3. **Graph Coloring:** Coloring a graph with minimal colors without adjacent same colors.
4. **Puzzle Solving:** Solving puzzles like crosswords or cryptograms.

### Advantages:

- **Completeness:** Finds all possible solutions.
- **Flexibility:** Can be adapted to a wide range of problems.
- **Simplicity:** Conceptually straightforward.

### Disadvantages:

- **Time Complexity:** Often exponential; can be slow for large problem sizes.
- **Memory Usage:** Recursive calls can consume a lot of memory.

### Optimization Techniques:

- **Pruning:** Eliminate paths early that cannot lead to a solution.
- **Heuristics:** Use problem-specific knowledge to improve efficiency.
- **Constraint Propagation:** Deduce variable domains to reduce the search space.

---

### Maze Solving Example

#### Problem Statement:

Find a path from the starting point to the goal in a maze represented by a 2D grid.

#### Maze Representation:

- **Grid Cells:**
  - `.` (dot) represents an open path.
  - `#` (hash) represents a wall or obstacle.
- **Allowed Moves:** Up, down, left, right (no diagonal movement).

#### Python Implementation:

```python
def solve_maze(maze, start, goal):
    rows, cols = len(maze), len(maze[0])
    path = []

    def is_valid(x, y):
        return (0 <= x < rows and 0 <= y < cols and maze[x][y] == '.')

    def explore(x, y):
        if not is_valid(x, y):
            return False
        if (x, y) == goal:
            path.append((x, y))
            return True
        maze[x][y] = 'V'  # Mark as visited
        path.append((x, y))
        # Try all possible directions
        if (explore(x + 1, y) or
            explore(x - 1, y) or
            explore(x, y + 1) or
            explore(x, y - 1)):
            return True
        path.pop()
        maze[x][y] = '.'  # Unmark visited
        return False

    if explore(*start):
        return path
    else:
        return None

# Sample maze
maze = [
    ['.', '.', '#', '.', '.', '.'],
    ['.', '#', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '#', '.'],
    ['.', '#', '#', '#', '.', '.'],
    ['.', '.', '.', '#', '.', '.'],
    ['#', '#', '#', '#', '.', '.']
]
start = (0, 0)
goal = (5, 5)
solution = solve_maze(maze, start, goal)
if solution:
    print("Path to goal:")
    for step in solution:
        print(step)
else:
    print("No path found.")
```

Explanation:

- The `explore` function recursively searches for a path to the goal.
- Cells are marked to prevent revisiting.
- If a path doesn't lead to the goal, the function backtracks and tries other directions.

## List of Problems

### Permutations

Develop an algorithm to generate all possible permutations of a given list of elements. This problem requires creating different arrangements of the elements where the order matters.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_permutations)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_permutations)

### Combinations

Design an algorithm to generate all possible combinations of 'k' elements selected from a given list of elements. This involves selecting elements where the order does not matter, but the selection size does.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_combinations)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_combinations)

### String Pattern

Create a solution to determine whether a given string adheres to a specified pattern, where the pattern may include letters and wildcard characters that represent any character. This problem often involves checking for matches and handling special pattern symbols.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/string_pattern)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/string_pattern)

### Generating Words

Generate all possible words that can be formed from a given list of characters and match a specified pattern. The pattern can contain letters and wildcard characters, requiring the algorithm to account for flexible matching.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/generating_words)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/generating_words)

### Hamiltonian Path

Create an algorithm that identifies whether a simple path exists within a provided undirected or directed graph. This path should visit every vertex exactly once. Known as the "traveling salesman problem," it can be addressed using depth-first search to explore possible paths.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/hamiltonian_paths)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/hamiltonian_paths)

### K-Colorable Configurations

Develop an algorithm to find all possible ways to color a given graph with 'k' colors such that no two adjacent vertices share the same color. This graph coloring problem requires ensuring valid color assignments for all vertices.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/k_colorable_configurations)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/k_colorable_configurations)

### Knight Tour

Create an algorithm to find all potential paths a knight can take on an 'n' x 'n' chessboard to visit every square exactly once. This classic chess problem involves ensuring the knight moves in an L-shape and covers all board positions.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/knight_tour)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/knight_tour)

### Topological Orderings

Determine a topological ordering of the vertices in a given directed graph, if one exists. This involves sorting the vertices such that for every directed edge UV from vertex U to vertex V, U comes before V in the ordering.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/topological_sort)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/topological_sort)

### Tic-Tac-Toe (Minimax)

Develop an algorithm to determine the optimal move for a player in a game of tic-tac-toe using the minimax algorithm. This requires evaluating possible moves to find the best strategy for winning or drawing the game.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/minimax)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/minimax)

