## Backtracking

Backtracking is a method used to solve problems by building potential solutions step by step. If it becomes clear that a partial solution cannot lead to a valid final solution, the process "backtracks" by undoing the last step and trying a different path. This approach is commonly applied to **constraint satisfaction problems**, **combinatorial optimization**, and puzzles like **N-Queens** or **Sudoku**, where all possibilities need to be explored systematically while avoiding unnecessary computations.

Think of backtracking as “explore with a rewind button.” You move forward making choices, but you’re never afraid to erase and try again. The reason this matters is simple: brute force tries *everything* blindly, but backtracking tries to be smart about quitting early. The moment a choice breaks the rules (a constraint), you stop investing time in that branch. That “stop early” habit is the real superpower, it keeps problems that *could* explode into millions of possibilities from wasting your time on guaranteed failures.

A good mental model is: **choose → test → continue or undo**. The “test” part is what turns random exploration into an algorithm with structure.

### Recursive Functions

Recursive functions are functions that call themselves directly or indirectly to solve a problem by breaking it down into smaller, more manageable subproblems. This concept is fundamental in computer science and mathematics, as it allows for elegant solutions to complex problems through repeated application of a simple process.

Recursion shows up here because backtracking naturally creates “nested decisions.” Every time you make a choice, you enter a smaller version of the same problem: “Okay, given what I’ve chosen so far, what choices can I make next?” Recursion fits that pattern perfectly. The big win is that recursion keeps the code focused on the **current step**, while the call stack quietly remembers how you got there, so when you backtrack, you return to the exact point where the last decision was made.

That said, recursion is not “magic.” It’s a disciplined way of saying: *solve the small version, then build up*. If you don’t have a clear stop condition, recursion doesn’t politely fail, it loops until you run out of stack.

Main idea:

1. **Base Case (Termination Condition)** is the condition under which the recursion stops. It prevents infinite recursion by providing an explicit solution for the simplest instance of the problem.
2. **Recursive Case** is the part of the function where it calls itself with a modified parameter, moving towards the base case.

A useful way to keep recursion readable is to ask two questions while writing it:

* **When do I stop?** (base case)
* **How do I make the problem smaller?** (recursive case)

If you can answer those cleanly, you usually get clean code.

#### Mathematical Foundation

Recursion closely relates to mathematical induction, where a problem is solved by assuming that the solution to a smaller instance of the problem is known and building upon it.

A recursive function can often be expressed using a recurrence relation:

$$ f(n) =
\begin{cases}
g(n) & \text{if } n = \text{base case} \
h(f(n - 1), n) & \text{otherwise}
\end{cases}
$$

where:

* $g(n)$ is the base case value,
* $h$ is a function that defines how to build the solution from the smaller instance.

This is where recursion becomes more than a programming trick, it becomes a way to *prove* correctness. Induction and recursion share the same shape: handle the simplest case, then show how everything else reduces to it. If you ever want confidence that a recursive solution is correct, that structure is what you lean on.

#### Example: Calculating Factorial

The factorial of a non-negative integer $n$ is the product of all positive integers less than or equal to $n$. Mathematically, it is defined as:

$$ n! =
\begin{cases}
1 & \text{if } n = 0 \
n \times (n - 1)! & \text{if } n > 0
\end{cases}
$$

Python Implementation:

```python
def factorial(n):
    if n == 0:
        return 1  # Base case: 0! = 1
    else:
        return n * factorial(n - 1)  # Recursive case
```

Factorial is the “hello world” of recursion because it’s easy to see the shrinking problem: `factorial(n)` becomes `factorial(n-1)`. And it also shows the two phases you always get with recursion: **going down** (making calls) and **coming back up** (combining results). That “coming back up” part is basically backtracking in miniature: you return from deep calls and rebuild the final answer step by step.

##### Detailed Computation for $n = 5$

Let's trace the recursive calls for `factorial(5)`:

* Call `factorial(5)` and compute $5 \times factorial(4)$ because $5 \neq 0$.
* Call `factorial(4)` and compute $4 \times factorial(3)$.
* Call `factorial(3)` and compute $3 \times factorial(2)$.
* Call `factorial(2)` and compute $2 \times factorial(1)$.
* Call `factorial(1)` and compute $1 \times factorial(0)$.
* Call `factorial(0)` and return $1$ as the base case is reached.

Now, we backtrack and compute the results:

1. `factorial(1)` returns $1 \times 1 = 1$.
2. `factorial(2)` returns $2 \times 1 = 2$.
3. `factorial(3)` returns $3 \times 2 = 6$.
4. `factorial(4)` returns $4 \times 6 = 24$.
5. `factorial(5)` returns $5 \times 24 = 120$.

Thus, $5! = 120$.

Notice how the “real math” happens on the way back. On the way down, you’re basically stacking up IOUs: “I’ll finish factorial(5) once I know factorial(4).” Backtracking is the same vibe: explore deep, then unwind and try something else if needed.

#### Visualization with Recursion Tree

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

**Important Considerations:**

* When using recursion, ensure **termination** by designing the recursive function such that all possible paths eventually reach a base case. This prevents infinite recursion.
* Be mindful of **stack depth**, as each recursive call adds a new frame to the call stack. Too many recursive calls, especially in deep recursion, can result in a stack overflow error.
* Consider **efficiency** when choosing a recursive approach. While recursive solutions can be elegant and clean, they may not always be optimal in terms of time and space, particularly when dealing with large input sizes or deep recursive calls.

These points matter even more once you move from “mathy recursion” (like factorial) to “search recursion” (like backtracking). Search trees can get deep *and* wide. That’s why good backtracking code doesn’t just recurse, it also **prunes** aggressively and keeps state management clean, so you aren’t blowing up time or memory.

### Depth-First Search (DFS)

Depth-First Search is an algorithm for traversing or searching tree or graph data structures. It starts at a selected node and explores as far as possible along each branch before backtracking.

DFS is the bridge between “recursion as a technique” and “backtracking as a strategy.” DFS says: go deep first, then rewind. That rewind is literally the same behavior: when you hit a dead end, you return to the last decision point and try a different neighbor. If you’ve ever solved a maze by walking forward until you can’t, then returning to the last intersection, that’s DFS in human form.

Main idea:

* The **traversal strategy** of Depth-First Search (DFS) involves exploring each branch of a graph or tree to its deepest point before backtracking to explore other branches.
* **Implementation** of DFS can be achieved either through recursion, which implicitly uses the call stack, or by using an explicit stack data structure to manage the nodes.
* **Applications** of DFS include tasks such as topological sorting, identifying connected components in a graph, solving puzzles like mazes, and finding paths in trees or graphs.

A quick “do and don’t” that makes DFS feel less abstract:

* **Do** mark visited nodes when the graph can loop, or you’ll walk in circles forever.
* **Don’t** assume DFS finds the shortest path, it finds *a* path and explores deeply, not optimally.

#### Algorithm Steps

* **Start at the root node** by marking it as visited to prevent revisiting it during the traversal.
* **Explore each branch** by recursively performing DFS on each unvisited neighbor, diving deeper into the graph or tree structure.
* **Backtrack** once all neighbors of a node are visited, returning to the previous node to continue exploring other branches.

Pseudocode:

```pseudo
DFS(node):
    mark node as visited
    for each neighbor in node.neighbors:
        if neighbor is not visited:
            DFS(neighbor)
```

#### Example: Tree Traversal

Consider the following tree:

```
Tree:
       A
      / \
     B   C
        / \
       D   E
```

Traversal using DFS starting from node 'A':

* **Visit 'A'** to begin the traversal, marking it as visited.
* **Move to 'B'**, but since 'B' has no unvisited neighbors, **backtrack to 'A'** to explore other branches.
* **Move to 'C'**, continuing the traversal to the next unvisited node.
* **Move to 'D'**, but as 'D' has no unvisited neighbors, **backtrack to 'C'**.
* **Move to 'E'**, but since 'E' also has no unvisited neighbors, **backtrack to 'C'**, and then further **backtrack to 'A'** to complete the exploration.

Traversal order: $A → B → C → D → E$

Implementation in Python:

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

Analysis:

* The **time complexity** of Depth-First Search (DFS) is $O(V + E)$, where $V$ represents the number of vertices and $E$ represents the number of edges in the graph.
* The **space complexity** is $O(V)$, primarily due to the space used by the recursion stack or an explicit stack, as well as the memory required for tracking visited nodes.

If you care about performance, the key takeaway is: DFS is often cheap enough to be a default traversal tool, but it can still get expensive in huge graphs. Also, that `visited` flag is doing a lot of work, without it, graphs with cycles can turn DFS into an accidental infinite adventure.

#### Applications

* **Cycle detection** in directed and undirected graphs.
* **Topological sorting** in directed acyclic graphs (DAGs).
* **Solving mazes and puzzles** by exploring all possible paths.
* Identifying **connected components** in a network or graph.

### Backtracking

Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, removing solutions that fail to satisfy the constraints at any point.

At this point, you can think of backtracking as DFS with standards. DFS explores; backtracking explores *while enforcing rules* and cutting off bad paths early. That’s why people use it for puzzles and constraint problems: you don’t just want to wander, you want to wander with a checklist, so you can confidently say “this can’t possibly work” and move on fast.

Main Idea:

* Building solutions one piece at a time and evaluating them against the constraints.
* Early detection of invalid solutions to prune the search space.
* When a partial solution cannot be extended to a complete solution, the algorithm backtracks to try different options.

The “prune the search space” is the reason backtracking is usable. Without pruning, N-Queens becomes “try everything,” and “everything” grows ridiculously fast. With pruning, you still explore possibilities, but you stop feeding time into branches that are already doomed.

#### General Algorithm Framework

1. Understand the possible configurations of the solution.
2. Start with an empty solution.
3. At each step, try to add a new component to the solution.
4. After adding a component, check if the partial solution is valid.
5. If not valid, backtrack.
6. If the partial solution is complete and valid, record or output it.
7. If all options are exhausted at a level, remove the last component and backtrack to the previous level.

General Template (pseudocode)

```
function backtrack(partial):
    if is_complete(partial):
        handle_solution(partial)
        return    // or continue if looking for all solutions

    for candidate in generate_candidates(partial):
        if is_valid(candidate, partial):
            place(candidate, partial)          // extend partial with candidate
            backtrack(partial)
            unplace(candidate, partial)        // undo extension (backtrack)
```

Pieces you supply per problem:

* `is_complete`: does `partial` represent a full solution?
* `handle_solution`: record/output the solution.
* `generate_candidates`: possible next choices given current partial.
* `is_valid`: pruning test to reject infeasible choices early.
* `place` / `unplace`: apply and revert the choice.

The beauty of this template is that it teaches you what backtracking really is: not one specific algorithm, but a reusable *shape*. Most backtracking problems differ only in those helper functions. If you can clearly define “what counts as valid so far,” you can solve a lot of classic puzzles with the same skeleton.

Python-ish Generic Framework

```python
def backtrack(partial, is_complete, generate_candidates, is_valid, handle_solution):
    if is_complete(partial):
        handle_solution(partial)
        return

    for candidate in generate_candidates(partial):
        if not is_valid(candidate, partial):
            continue
        # make move
        partial.append(candidate)
        backtrack(partial, is_complete, generate_candidates, is_valid, handle_solution)
        # undo move
        partial.pop()
```

You can wrap those callbacks into a class or closures for stateful problems.

One practical “do/don’t” with this style:

* **Do** make `place/unplace` symmetrical (every change you make must be undone).
* **Don’t** mutate shared state without undoing it, or you’ll get “ghost effects” where one branch pollutes another.

#### N-Queens Problem

The N-Queens problem is a classic puzzle in which the goal is to place $N$ queens on an $N \times N$ chessboard such that no two queens threaten each other. In chess, a queen can move any number of squares along a row, column, or diagonal. Therefore, no two queens can share the same row, column, or diagonal.

Objective:

* Place $N$ queens on the board.
* Ensure that no two queens attack each other.
* Find all possible arrangements that satisfy the above conditions.

N-Queens is the poster child for backtracking because it’s easy to describe, hard to brute force, and perfect for pruning. The moment you place a queen, you instantly rule out a bunch of squares. That means you don’t need to “wait until the end” to discover failure, you can detect it *as soon as it happens*, which is exactly what backtracking wants.

##### Visual Representation

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

Each cell can be identified by its row and column indices ((row, column)).

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

* `Q` represents a queen.
* Blank spaces represent empty cells.

##### Constraints

* Only one queen per row.
* Only one queen per column.
* No two queens share the same diagonal.

##### Approach Using Backtracking

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

This flow is exactly “choose → test → recurse → undo.” The fun part is that the board doesn’t need to be fully drawn most of the time. You can represent a queen placement compactly (like “row -> column”), and then your safety check becomes pure logic. That’s a nice lesson: backtracking is often more about managing **state** than about fancy data structures.

##### Python Implementation

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

# Example usage
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

##### Execution Flow

1. Try placing a queen in columns `0` to `N - 1`.
2. For each valid placement, proceed to row `1`.
3. At each row, attempt to place a queen in a safe column.
4. If no safe column is found, backtrack to the previous row.
5. When a valid placement is found for all $N$ rows, record the solution.

##### All Solutions for $N = 4$

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

##### Output of the Program

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

##### Visualization of the Backtracking Tree

The algorithm explores the solution space as a tree, where each node represents a partial solution (queens placed up to a certain row). The branches represent the possible positions for the next queen.

* **Nodes** represent partial solutions where a certain number of queens have already been placed in specific rows.
* **Branches** correspond to the possible positions for placing the next queen in the following row, exploring each valid option.
* **Leaves** are the complete solutions when all $N$ queens have been successfully placed on the board without conflicts.

The backtracking occurs when a node has no valid branches (no safe positions in the next row), prompting the algorithm to return to the previous node and try other options.

##### Analysis

I. The **time complexity** of the N-Queens problem is $O(N!)$ as the algorithm explores permutations of queen placements across rows.

II. The **space complexity** is $O(N)$, where:

* The `board` array stores the positions of the $N$ queens.
* The recursion stack can go as deep as $N$ levels during the backtracking process.

This is a good moment to connect the “why should I care?” dot: many real problems look like N-Queens under the hood, scheduling, assignment, routing with constraints, configuration systems, even some parts of compiler design. You’re practicing a general way to search through choices without drowning in them.

##### Applications

* **Constraint satisfaction problems** often use the N-Queens problem as a classic example to study and develop solutions for placing constraints on variable assignments.
* In **algorithm design**, the N-Queens problem helps illustrate the principles of backtracking and recursive problem-solving.
* In **artificial intelligence**, it serves as a foundational example for search algorithms and optimization techniques.

##### Potential Improvements

* Implementing more efficient conflict detection methods.
* Using heuristics to choose the order of columns to try first.
* Converting the recursive solution to an iterative one using explicit stacks to handle larger values of $N$ without stack overflow.

#### Example: Maze Solver

Given a maze represented as a 2D grid, find a path from the starting point to the goal using backtracking. The maze consists of open paths and walls, and movement is allowed in four directions: up, down, left, and right (no diagonal moves). The goal is to determine a sequence of moves that leads from the start to the goal without crossing any walls.

Maze solving makes backtracking feel instantly real. You’re making choices (directions), you hit walls or loops (constraints), and you undo moves when you get stuck. Even if you never care about mazes, you *do* care about the pattern: this is the same structure as exploring possible decisions in a game AI, navigating states in a program, or searching combinations until you find one that works.

##### Maze Representation

**Grid Cells:**

* `.` (dot) represents an **open path**.
* `#` (hash) represents a **wall** or **obstacle**.

**Allowed Moves:**

* Up, down, left, right.
* No diagonal movement.

##### ASCII Representation

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

##### Python Implementation

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

One small but important detail: this code’s `is_valid` only allows stepping onto `'.'`, so `S` and `G` are treated as labels in the diagram, not actual characters in the grid. In practice, you either keep the grid as dots and track `start`/`goal` separately (like this code does), or you expand `is_valid` to allow stepping onto `'G'` as well. The version here is consistent because the grid itself is all `'.'` and `'#'`, and the goal is a coordinate.

##### Recursive Function `explore(x, y)`

I. **Base Cases:**

* If `(x, y)` is not valid (out of bounds, wall, or visited), return `False`.
* If `(x, y)` equals the goal position, append it to `path` and return `True`.

II. **Recursive Exploration:**

* Mark the current cell `(x, y)` as visited by setting `maze[x][y] = 'V'`.
* Append `(x, y)` to the `path`.
* Recursively attempt to explore neighboring cells in the following order:
* Move **Down**: `explore(x + 1, y)`
* Move **Up**: `explore(x - 1, y)`
* Move **Right**: `explore(x, y + 1)`
* Move **Left**: `explore(x, y - 1)`
* If any recursive call returns `True`, propagate the `True` value upwards.

III. **Backtracking:**

* If none of the neighboring cells lead to a solution, backtrack:
* Remove `(x, y)` from `path` using `path.pop()`.
* Unmark the cell by setting `maze[x][y] = '.'`.
* Return `False` to indicate that this path does not lead to the goal.

This is the heart of backtracking in one function: **mark, explore, undo**. The “undo” is what keeps the search honest. Without undoing the visited mark and the path append, you’d either get stuck or accidentally block valid routes later.

##### Execution Flow

I. **Start at `(0, 0)`**:

* The algorithm begins at the starting position.
* Marks `(0, 0)` as visited and adds it to the path.

II. **Explore Neighbors**:

* Tries moving **Down** to `(1, 0)`.

III. **Recursive Exploration**:

* From `(1, 0)`, continues moving **Down** to `(2, 0)`.
* From `(2, 0)`, attempts **Right** to `(2, 1)`.

IV. **Dead Ends and Backtracking**:

* If a path leads to a wall or visited cell, the algorithm backtracks to the previous cell and tries a different direction.
* This process continues, exploring all possible paths recursively.

V. **Reaching the Goal**:

* Eventually, the algorithm reaches the goal `(5, 5)` if a path exists.
* The function returns `True`, and the full path is constructed via the recursive calls.

##### Output

* If a path is found, it prints "Path to goal:" followed by the list of coordinates in the path.
* If no path exists, it prints "No path found."

##### Final Path Found

The path from start to goal:

```
[(0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (2, 3),
 (1, 3), (1, 4), (1, 5), (2, 5), (3, 5), (4, 5),
 (5, 5)]
```

##### Visual Representation of the Path

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

##### Advantages of Using Backtracking for Maze Solving

* Ensures that all possible paths are explored until the goal is found.
* Only the current path and visited cells are stored, reducing memory usage compared to storing all possible paths.
* Recursive implementation leads to clean and understandable code.

##### Potential Improvements

* This algorithm finds a path but not necessarily the shortest path.
* To find the shortest path, algorithms like Breadth-First Search (BFS) are more suitable.
* Modify the code to collect all possible paths by removing early returns when the goal is found.
* Allowing diagonal movements would require adjusting the `explore` function to include additional directions.

This is where you can choose your “vibe” depending on the problem:

* If you just need **any** solution fast and the maze is small, backtracking is perfect.
* If you need the **best** solution (shortest path), you switch strategies (like BFS).
* If the search space is massive, you start adding smarter pruning, heuristics, or even entirely different approaches.

Backtracking isn’t the final boss :) it’s just a foundation. Once you understand it, you start recognizing when a problem is a “choices + constraints” machine, and you’ll know exactly how to build a solver that’s not only correct, but actually fun to reason about.

### List of Problems

#### Permutations

Develop an algorithm to generate all possible permutations of a given list of elements. This problem requires creating different arrangements of the elements where the order matters.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_permutations)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_permutations)

#### Combinations

Design an algorithm to generate all possible combinations of 'k' elements selected from a given list of elements. This involves selecting elements where the order does not matter, but the selection size does.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_combinations)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_combinations)

#### String Pattern

Create a solution to determine whether a given string adheres to a specified pattern, where the pattern may include letters and wildcard characters that represent any character. This problem often involves checking for matches and handling special pattern symbols.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/string_pattern)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/string_pattern)

#### Generating Words

Generate all possible words that can be formed from a given list of characters and match a specified pattern. The pattern can contain letters and wildcard characters, requiring the algorithm to account for flexible matching.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/generating_words)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/generating_words)

#### Hamiltonian Path

Create an algorithm that identifies whether a simple path exists within a provided undirected or directed graph. This path should visit every vertex exactly once. Known as the "traveling salesman problem," it can be addressed using depth-first search to explore possible paths.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/hamiltonian_paths)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/hamiltonian_paths)

#### K-Colorable Configurations

Develop an algorithm to find all possible ways to color a given graph with 'k' colors such that no two adjacent vertices share the same color. This graph coloring problem requires ensuring valid color assignments for all vertices.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/k_colorable_configurations)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/k_colorable_configurations)

#### Knight Tour

Create an algorithm to find all potential paths a knight can take on an 'n' x 'n' chessboard to visit every square exactly once. This classic chess problem involves ensuring the knight moves in an L-shape and covers all board positions.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/knight_tour)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/knight_tour)

#### Topological Orderings

Determine a topological ordering of the vertices in a given directed graph, if one exists. This involves sorting the vertices such that for every directed edge UV from vertex U to vertex V, U comes before V in the ordering.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/topological_sort)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/topological_sort)

#### Tic-Tac-Toe (Minimax)

Develop an algorithm to determine the optimal move for a player in a game of tic-tac-toe using the minimax algorithm. This requires evaluating possible moves to find the best strategy for winning or drawing the game.

* [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/minimax)
* [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/minimax)
