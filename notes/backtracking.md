## Recursive Functions

Recursive functions are a unique type of function that has the ability to call itself in order to tackle complex problems by breaking them down into smaller and more manageable subproblems. The concept of recursion revolves around the principle of self-reference where the solution to the larger problem depends on solutions to smaller instances of the same problem.

Key Concept:

1. **Base Case:** The condition(s) under which the recursive function stops calling itself. This prevents the function from running indefinitely.
2. **Recursive Case:** The part of the function where the function calls itself, working towards reaching the base case.

### Example: Calculating Factorial

Below is a Python code snippet showcasing the usage of a recursive function to calculate the factorial of a number:

```python
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)
```

Let's consider the factorial of 5:

1. `n` is not 1, so the function proceeds to the recursive case. It calls `factorial(4)`.
2. `n` is not 1, so the function proceeds to the recursive case. It calls `factorial(3)`.
3. `n` is not 1, so the function proceeds to the recursive case. It calls `factorial(2)`.
4. `n` is not 1, so the function proceeds to the recursive case. It calls `factorial(1)`.
5. `n` is 1, so the function returns 1.

Now, the function starts returning from the recursive calls:

1. Returns `2 * factorial(1)` which is `2 * 1 = 2`. 
2. Returns `3 * factorial(2)` which is `3 * 2 = 6`.
3. Returns `4 * factorial(3)` which is `4 * 6 = 24`.
4. Returns `5 * factorial(4)` which is `5 * 24 = 120`.

Thus, `factorial(5)` results in 120.

## Depth-First Search (DFS)

Depth-First Search (DFS) is a powerful algorithm often used for traversing or searching through graphs or trees. 

Key Concepts:

- *DFS operates under the principle of going as deep as possible from a starting point until it hits a dead end. Then, it backtracks and explores the next available path, ensuring no node is left unvisited.
- When multiple paths are available, such as in a tree with multiple children for a node, DFS typically explores the leftmost path first. This is a convention chosen for simplicity and consistency across different data structures.
- The algorithm uses a stack to remember nodes that are yet to be visited. A stack follows the "last in, first out" rule, which aligns perfectly with DFS's backtracking approach, allowing it to return to the most recent unexplored node.
- DFS and backtracking techniques can be used together, creating a powerful toolkit for solving problems like mazes, network routing, or searching through web pages for specific information.

### Example Tree

```
   A
  / \
 B   C
    / \
   D   E
```

In a depth-first search starting from 'A', the algorithm follows these steps:

1. Start at the root node 'A'.
2. Dive deeper into the leftmost unvisited branch, visiting 'B'.
3. After reaching 'B' (a dead end), backtrack to 'A'.
4. Explore the next available path, moving to 'C'.
5. Continue the journey to 'D', the left child of 'C'.
6. Finally, visit 'E', the right child of 'C'.

So, the sequence of node visitation for this example would be: **A, B, C, D, E**.

### DFS Implementation in Python

Here's a simple Python implementation of DFS for a tree structure:

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def dfs(node):
    if node is not None:
        print(node.value)  # Visit the node
        dfs(node.left)     # Recursively visit the left subtree
        dfs(node.right)    # Recursively visit the right subtree

# Create the tree
root = Node('A')
root.left = Node('B')
root.right = Node('C')
root.right.left = Node('D')
root.right.right = Node('E')

# Perform DFS
dfs(root)
```

## Backtracking

Backtracking is a tried-and-true method for solving constraint satisfaction problems and problems involving combinatorial optimization. Although efficient for certain types of problems, it might slow down when dealing with large problems and could require significant memory.

### Advantages

* For some problem types, backtracking can be a highly efficient method.
* It can generate all feasible solutions to a given problem.

### Disadvantages

* For large-scale problems, backtracking can be slower.
* Maintaining the search tree in memory might require substantial space.

#### Real-world Examples

1. Figuring out all viable combinations of words that can be formed from a given set of characters.
2. Generating all possible permutations of a designated set of numbers.
3. The famous 8 queens puzzle: placing 8 queens on a chessboard in such a way that none can attack another.
4. Finding all possible routes from the top-left corner to the bottom-right corner of a grid, given you can only move downwards or to the right.

### Crafting a Backtracking Algorithm

Here's a step-by-step guide to building a backtracking algorithm:

1. Identify the problem's base case(s) where the algorithm should halt its search for solutions and return a result.
2. Design a recursive function that takes in the current state of the candidate solution and any related parameters.
3. If the current state is a valid solution or a base case has been reached within the function, it should return a result.
4. If the current state isn't a solution and the base case hasn't been reached, generate a list of potential next steps or "choices" that could be made from the present state.
5. Loop through the list of choices. For each choice, modify the current state and recursively call the function with this updated state.
6. If the function finds a result for any of the choices, return that result. If none of the choices produce a result, return "no result" or revert to the previous state (this is the "backtracking").
7. Repeat this process until a valid solution is identified or all possibilities have been considered.

While backtracking algorithms can be demanding in terms of computational resources (since they might explore many possibilities before finding a solution), they can be incredibly effective for problems with a limited search space or problems where a candidate solution's validity can be swiftly checked.

### Visualization

Consider a maze with the start at the top left and the goal at the bottom right. You can only move right or down. The "#" indicates a wall, and "." indicates an open space:

```
. . # . . .
. # . . . .
. . . . # .
. # # # . .
. . . # . .
# # # # . .
```

1. The algorithm starts at the top-left corner of the maze at position `(0, 0)`. From here, it explores the neighboring cells.

2. It first moves downwards, visiting `(1, 0)` and `(2, 0)`. This is because our algorithm prioritizes moving down and right.

3. From `(2, 0)`, it can't move down because there's either a wall (`#`) or the boundary of the maze. So, it moves to the right, visiting cells `(2, 1)`, `(2, 2)`, and `(2, 3)`.

4. At `(2, 3)`, it encounters a wall on the right, so it can't continue in this direction. It then tries to move downwards but finds another wall there. So, it backtracks to move upwards to cell `(1, 3)`.

5. From `(1, 3)`, it again tries moving rightwards as it's the preferred direction, visiting `(1, 4)` and `(1, 5)`.

6. From `(1, 5)`, it cannot go right or up as there are either walls or visited cells, and it can't go left because that would be backtracking. So, it moves down to `(2, 5)`.

7. It continues moving downwards, visiting `(3, 5)`, `(4, 5)`, and finally reaching the goal at `(5, 5)`.

The backtracking happens at step 4 when the algorithm realizes it has reached a dead end at `(2, 3)` and must backtrack to `(1, 3)` to explore unvisited cells. This step signifies the essence of the backtracking algorithm: trying out different possibilities and stepping back when encountering a block.

Here is the code snippet in Python:

```python
# Function to find the path from start (0, 0) to goal
def solve_maze(maze):
    path = []
    if explore_maze(maze, 0, 0, path):
        return path
    else:
        return "No solution found!"


# Recursive function to explore the maze
def explore_maze(maze, x, y, path):
    # If point is outside the maze, return False
    if x < 0 or y < 0 or x >= len(maze) or y >= len(maze[0]):
        return False

    # If point is a wall or has been visited before, return False
    if maze[x][y] == "#" or maze[x][y] == "V":
        return False

    # Mark point as visited
    maze[x][y] = "V"
    path.append((x, y))

    # If point is the goal, return True
    if x == len(maze) - 1 and y == len(maze[0]) - 1:
        return True

    # If any neighboring point is the goal, return True
    if (
        explore_maze(maze, x + 1, y, path)
        or explore_maze(maze, x, y + 1, path)
        or explore_maze(maze, x - 1, y, path)
        or explore_maze(maze, x, y - 1, path)
    ):
        return True

    # If no neighboring point is the goal, remove point from path and return False
    path.pop()
    return False


for row in maze:
    print(f'{"".join(row)}')

print(solve_maze(maze))
```

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

