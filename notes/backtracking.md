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

## Backtracking

Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, removing solutions that fail to satisfy the constraints at any point.

Main Idea:

- Building solutions one piece at a time and evaluating them against the constraints.
- Early detection of invalid solutions to prune the search space.
- When a partial solution cannot be extended to a complete solution, the algorithm backtracks to try different options.

### General Algorithm Framework

1. Understand the possible configurations of the solution.
2. Start with an empty solution.
3. At each step, try to add a new component to the solution.
4. After adding a component, check if the partial solution is valid.
5. If not valid, backtrack.
6. If the partial solution is complete and valid, record or output it.
7. If all options are exhausted at a level, remove the last component and backtrack to the previous level.

### N-Queens Problem

The N-Queens problem is a classic puzzle in which the goal is to place $N$ queens on an $N \times N$ chessboard such that no two queens threaten each other. In chess, a queen can move any number of squares along a row, column, or diagonal. Therefore, no two queens can share the same row, column, or diagonal.

Objective:

- Place $N$ queens on the board.
- Ensure that no two queens attack each other.
- Find all possible arrangements that satisfy the above conditions.

#### Visual Representation:

To better understand the problem, let's visualize it using ASCII graphics.

**Empty $4 \times 4$ Chessboard:**

```
  0   1   2   3  (Columns)
+---+---+---+---+
0|   |   |   |   |
+---+---+---+---+
1|   |   |   |   |
+---+---+---+---+
2|   |   |   |   |
+---+---+---+---+
3|   |   |   |   |
+---+---+---+---+
(Rows)
```

Each cell can be identified by its row and column indices \((row, column)\).

**Example Solution for $N = 4$:**

One of the possible solutions for placing 4 queens on a $4 \times 4$ chessboard is:

```
  0   1   2   3  (Columns)
+---+---+---+---+
0| Q |   |   |   |  (Queen at position (0, 0))
+---+---+---+---+
1|   |   | Q |   |  (Queen at position (1, 2))
+---+---+---+---+
2|   |   |   | Q |  (Queen at position (2, 3))
+---+---+---+---+
3|   | Q |   |   |  (Queen at position (3, 1))
+---+---+---+---+
(Rows)
```

- `Q` represents a queen.
- Blank spaces represent empty cells.

#### Constraints:

- Only one queen per row.
- Only one queen per column.
- No two queens share the same diagonal.

#### Approach Using Backtracking:

Backtracking is an ideal algorithmic approach for solving the N-Queens problem due to its constraint satisfaction nature. The algorithm incrementally builds the solution and backtracks when a partial solution violates the constraints.

High-Level Steps:

1. Initialize an empty chessboard of size $N \times N$.
2. Try placing a queen in each column of the first row and check for conflicts.
3. Move to the next row.
4. For each column, attempt to place a queen.
5. Check if the placement is safe (no conflicts with existing queens).
6. If no safe position is found in the current row, backtrack to the previous row.
7. Try the next available position in the previous row.
8. When $N$ queens have been successfully placed without conflicts, record the solution.
9. Continue the process to find all possible solutions.

#### Python Implementation:

Below is a Python implementation of the N-Queens problem using backtracking.

```python
def solve_n_queens(N):
    solutions = []
    board = [-1] * N  # board[row] = column position of queen in that row

    def is_safe(row, col):
        for prev_row in range(row):
            # Check column conflict
            if board[prev_row] == col:
                return False
            # Check diagonal conflicts
            if abs(board[prev_row] - col) == abs(prev_row - row):
                return False
        return True

    def place_queen(row):
        if row == N:
            # All queens are placed successfully
            solutions.append(board.copy())
            return
        for col in range(N):
            if is_safe(row, col):
                board[row] = col  # Place queen
                place_queen(row + 1)  # Move to next row
                board[row] = -1  # Backtrack

    place_queen(0)
    return solutions

# Example usage:
N = 4
solutions = solve_n_queens(N)
print(f"Number of solutions for N={N}: {len(solutions)}")
for index, sol in enumerate(solutions):
    print(f"\nSolution {index + 1}:")
    for row in range(N):
        line = ['.'] * N
        if sol[row] != -1:
            line[sol[row]] = 'Q'
        print(' '.join(line))
```

#### Execution Flow

1. Try placing a queen in columns `0` to `N - 1`.
2. For each valid placement, proceed to row `1`.
3. At each row, attempt to place a queen in a safe column.
4. If no safe column is found, backtrack to the previous row.
5. When a valid placement is found for all $N$ rows, record the solution.

#### All Solutions for $N = 4$:

There are two distinct solutions for $N = 4$:

**Solution 1:**

```
Board Representation: [1, 3, 0, 2]

  0   1   2   3
+---+---+---+---+
0|   | Q |   |   |
+---+---+---+---+
1|   |   |   | Q |
+---+---+---+---+
2| Q |   |   |   |
+---+---+---+---+
3|   |   | Q |   |
+---+---+---+---+
```

**Solution 2:**

```
Board Representation: [2, 0, 3, 1]

  0   1   2   3
+---+---+---+---+
0|   |   | Q |   |
+---+---+---+---+
1| Q |   |   |   |
+---+---+---+---+
2|   |   |   | Q |
+---+---+---+---+
3|   | Q |   |   |
+---+---+---+---+
```

#### Output of the Program:

```
Number of solutions for N=4: 2

Solution 1:
. Q . .
. . . Q
Q . . .
. . Q .

Solution 2:
. . Q .
Q . . .
. . . Q
. Q . .
```

#### Visualization of the Backtracking Tree:

The algorithm explores the solution space as a tree, where each node represents a partial solution (queens placed up to a certain row). The branches represent the possible positions for the next queen.

- **Nodes:** Partial solutions with queens placed in certain rows.
- **Branches:** Possible positions for the next queen in the next row.
- **Leaves:** Complete solutions when $N$ queens are placed.

The backtracking occurs when a node has no valid branches (no safe positions in the next row), prompting the algorithm to return to the previous node and try other options.

#### Analysis:

**Time Complexity:** $O(N!)$

- The algorithm explores permutations of queen placements.

**Space Complexity:** $O(N)$

- The `board` array stores $N$ positions.
- The recursion stack can go up to $N$ levels deep.

#### Applications:

- **Constraint Satisfaction Problems:** The N-Queens problem is a classic example used to study algorithms in this domain.
- **Algorithm Design:** Understanding backtracking and recursive problem-solving techniques.
- **Artificial Intelligence:** Search algorithms and optimization.

#### Potential Improvements:

- Implementing more efficient conflict detection methods.
- Using heuristics to choose the order of columns to try first.
- Converting the recursive solution to an iterative one using explicit stacks to handle larger values of $N$ without stack overflow.

### Example: Maze Solver

Given a maze represented as a 2D grid, find a path from the starting point to the goal using backtracking. The maze consists of open paths and walls, and movement is allowed in four directions: up, down, left, and right (no diagonal moves). The goal is to determine a sequence of moves that leads from the start to the goal without crossing any walls.

#### Maze Representation:

**Grid Cells:**

- `.` (dot) represents an **open path**.
- `#` (hash) represents a **wall** or **obstacle**.

**Allowed Moves:**

- Up, down, left, right.
- No diagonal movement.

#### ASCII Representation

Let's visualize the maze using ASCII graphics to better understand the problem.

```
Maze Layout:

Start (S) at position (0, 0)
Goal (G) at position (5, 5)

  0 1 2 3 4 5 (Columns)
0 S . # . . .
1 . # . . . .
2 . . . . # .
3 . # # # . .
4 . . . # . .
5 # # # # . G

Legend:
S - Start
G - Goal
. - Open path
# - Wall
```

Here's the maze grid with indices:

```
    0   1   2   3   4   5
  +---+---+---+---+---+---+
0 | S | . | # | . | . | . |
  +---+---+---+---+---+---+
1 | . | # | . | . | . | . |
  +---+---+---+---+---+---+
2 | . | . | . | . | # | . |
  +---+---+---+---+---+---+
3 | . | # | # | # | . | . |
  +---+---+---+---+---+---+
4 | . | . | . | # | . | . |
  +---+---+---+---+---+---+
5 | # | # | # | # | . | G |
  +---+---+---+---+---+---+
```

Objective:

Find a sequence of moves from `S` to `G`, navigating only through open paths (`.`) and avoiding walls (`#`). The path should be returned as a list of grid coordinates representing the steps from the start to the goal.

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
        # Try all possible directions: down, up, right, left
        if (explore(x + 1, y) or
            explore(x - 1, y) or
            explore(x, y + 1) or
            explore(x, y - 1)):
            return True
        path.pop()          # Backtrack
        maze[x][y] = '.'    # Unmark visited
        return False

    if explore(*start):
        return path
    else:
        return None

# Sample maze (as a list of lists)
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

#### Recursive Function `explore(x, y)`:

I. **Base Cases:**

- If `(x, y)` is not valid (out of bounds, wall, or visited), return `False`.
- If `(x, y)` equals the goal position, append it to `path` and return `True`.

II. **Recursive Exploration:**

- Mark the current cell `(x, y)` as visited by setting `maze[x][y] = 'V'`.
- Append `(x, y)` to the `path`.
- Recursively attempt to explore neighboring cells in the following order:
- Move **Down**: `explore(x + 1, y)`
- Move **Up**: `explore(x - 1, y)`
- Move **Right**: `explore(x, y + 1)`
- Move **Left**: `explore(x, y - 1)`
- If any recursive call returns `True`, propagate the `True` value upwards.

III. **Backtracking:**

- If none of the neighboring cells lead to a solution, backtrack:
- Remove `(x, y)` from `path` using `path.pop()`.
- Unmark the cell by setting `maze[x][y] = '.'`.
- Return `False` to indicate that this path does not lead to the goal.

#### Execution Flow:

I. **Start at `(0, 0)`**:

- The algorithm begins at the starting position.
- Marks `(0, 0)` as visited and adds it to the path.

II. **Explore Neighbors**:

- Tries moving **Down** to `(1, 0)`.

III. **Recursive Exploration**:

- From `(1, 0)`, continues moving **Down** to `(2, 0)`.
- From `(2, 0)`, attempts **Right** to `(2, 1)`.

IV. **Dead Ends and Backtracking**:

- If a path leads to a wall or visited cell, the algorithm backtracks to the previous cell and tries a different direction.
- This process continues, exploring all possible paths recursively.

V. **Reaching the Goal**:

- Eventually, the algorithm reaches the goal `(5, 5)` if a path exists.
- The function returns `True`, and the full path is constructed via the recursive calls.

#### Output

- If a path is found, it prints "Path to goal:" followed by the list of coordinates in the path.
- If no path exists, it prints "No path found."

#### Final Path Found:

The path from start to goal:

```
[(0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (2, 3),
 (1, 3), (1, 4), (1, 5), (2, 5), (3, 5), (4, 5),
 (5, 5)]
```

#### Visual Representation of the Path:

Let's overlay the path onto the maze for better visualization. We'll use `*` to indicate the path.

```
Maze with Path:

    0   1   2   3   4   5
  +---+---+---+---+---+---+
0 | * | * | # | . | . | . |
  +---+---+---+---+---+---+
1 | * | # | . | * | * | * |
  +---+---+---+---+---+---+
2 | * | * | * | * | # | * |
  +---+---+---+---+---+---+
3 | . | # | # | # | . | * |
  +---+---+---+---+---+---+
4 | . | . | . | # | . | * |
  +---+---+---+---+---+---+
5 | # | # | # | # | . | * |
  +---+---+---+---+---+---+

Legend:
* - Path taken
# - Wall
. - Open path
```

#### Advantages of Using Backtracking for Maze Solving:

- Ensures that all possible paths are explored until the goal is found.
- Only the current path and visited cells are stored, reducing memory usage compared to storing all possible paths.
- Recursive implementation leads to clean and understandable code.

#### Potential Improvements:

- This algorithm finds a path but not necessarily the shortest path.
- To find the shortest path, algorithms like Breadth-First Search (BFS) are more suitable.
- Modify the code to collect all possible paths by removing early returns when the goal is found.
- Allowing diagonal movements would require adjusting the `explore` function to include additional directions.

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
