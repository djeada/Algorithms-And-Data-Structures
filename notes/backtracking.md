# Backtracking

Backtracking is a method used to solve problems by building potential solutions step by step. If it becomes clear that a partial solution cannot lead to a valid final solution, the process "backtracks" by undoing the last step and trying a different path. This approach is commonly applied to constraint satisfaction problems, combinatorial optimization, and puzzles like N-Queens or Sudoku, where all possibilities need to be explored systematically while avoiding unnecessary computations.

Backtracking explores choices depth first and rejects a branch as soon as its partial solution violates a constraint. Undoing the last choice restores the state for the next candidate. Early rejection reduces wasted exploration, though the worst-case search can still be exponential.

A good mental model is: choose → test → continue or undo. The “test” part is what turns random exploration into an algorithm with structure.

## Recursive Functions

Recursive functions are functions that call themselves directly or indirectly to solve a problem by breaking it down into smaller, more manageable subproblems. This concept is fundamental in computer science and mathematics, as it allows for elegant solutions to complex problems through repeated application of a simple process.

Recursion shows up here because backtracking naturally creates “nested decisions.” Every time you make a choice, you enter a smaller version of the same problem: “Okay, given what I’ve chosen so far, what choices can I make next?” Recursion fits that pattern perfectly. The big win is that recursion keeps the code focused on the current step, while the call stack quietly remembers how you got there, so when you backtrack, you return to the exact point where the last decision was made.

Each recursive call needs a base case or a demonstrable move toward one. Without that progress, calls continue until a resource limit is reached.

Main idea:

1. Base Case (Termination Condition) is the condition under which the recursion stops. It prevents infinite recursion by providing an explicit solution for the simplest instance of the problem.
2. Recursive Case is the part of the function where it calls itself with a modified parameter, moving towards the base case.

A useful way to keep recursion readable is to ask two questions while writing it:

- When do I stop? (base case)
- How do I make the problem smaller? (recursive case)

If you can answer those cleanly, you usually get clean code.

### Mathematical Foundation

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

This is where recursion becomes more than a programming trick, it becomes a way to *prove* correctness. Induction and recursion share the same shape: handle the simplest case, then show how everything else reduces to it. If you ever want confidence that a recursive solution is correct, that structure is what you lean on.

### Example: Calculating Factorial

The factorial of a non-negative integer $n$ is the product of all positive integers less than or equal to $n$. Mathematically, it is defined as:

$$ n! =
\begin{cases}
1 & \text{if } n = 0 \\
n \times (n - 1)! & \text{if } n > 0
\end{cases}
$$

Python Implementation:

```python
def factorial(n):
    if n < 0:
        raise ValueError("n must be non-negative")
    if n == 0:
        return 1  # Base case: 0! = 1
    else:
        return n * factorial(n - 1)  # Recursive case
```

Factorial is the “hello world” of recursion because it’s easy to see the shrinking problem: `factorial(n)` becomes `factorial(n-1)`. And it also shows the two phases you always get with recursion: going down (making calls) and coming back up (combining results). Returning through the call stack is called unwinding. It is useful preparation for backtracking, but factorial is not a backtracking search: it does not choose among alternatives or undo tentative decisions.

#### Detailed Computation for $n = 5$

Let's trace the recursive calls for `factorial(5)`:

- Call `factorial(5)` and compute $5 \times factorial(4)$ because $5 \neq 0$.
- Call `factorial(4)` and compute $4 \times factorial(3)$.
- Call `factorial(3)` and compute $3 \times factorial(2)$.
- Call `factorial(2)` and compute $2 \times factorial(1)$.
- Call `factorial(1)` and compute $1 \times factorial(0)$.
- Call `factorial(0)` and return $1$ as the base case is reached.

Now the calls unwind and compute the results:

1. `factorial(1)` returns $1 \times 1 = 1$.
2. `factorial(2)` returns $2 \times 1 = 2$.
3. `factorial(3)` returns $3 \times 2 = 6$.
4. `factorial(4)` returns $4 \times 6 = 24$.
5. `factorial(5)` returns $5 \times 24 = 120$.

Thus, $5! = 120$.

The downward phase creates pending multiplications; the return phase completes them. Backtracking uses the same call-stack behavior, with the additional work of undoing a choice and trying another candidate.

### Visualization with Recursion Tree

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

Important Considerations:

- When using recursion, ensure termination by designing the recursive function such that all possible paths eventually reach a base case. This prevents infinite recursion.
- Be mindful of stack depth, as each recursive call adds a new frame to the call stack. Too many recursive calls, especially in deep recursion, can result in a stack overflow error.
- Consider efficiency when choosing a recursive approach. While recursive solutions can be elegant and clean, they may not always be optimal in terms of time and space, particularly when dealing with large input sizes or deep recursive calls.

These points matter even more once you move from “mathy recursion” (like factorial) to “search recursion” (like backtracking). Search trees can get deep and wide. That’s why good backtracking code doesn’t just recurse, it also prunes aggressively and keeps state management clean, so you aren’t blowing up time or memory.

## Depth-First Search (DFS)

Depth-First Search is an algorithm for traversing or searching tree or graph data structures. It starts at a selected node and explores as far as possible along each branch before backtracking.

DFS is the bridge between “recursion as a technique” and “backtracking as a strategy.” DFS says: go deep first, then rewind. That rewind is literally the same behavior: when you hit a dead end, you return to the last decision point and try a different neighbor. If you’ve ever solved a maze by walking forward until you can’t, then returning to the last intersection, that’s DFS in human form.

Main idea:

- The traversal strategy of Depth-First Search (DFS) involves exploring each branch of a graph or tree to its deepest point before backtracking to explore other branches.
- Implementation of DFS can be achieved either through recursion, which implicitly uses the call stack, or by using an explicit stack data structure to manage the nodes.
- Applications of DFS include tasks such as topological sorting, identifying connected components in a graph, solving puzzles like mazes, and finding paths in trees or graphs.

A quick “do and don’t” that makes DFS feel less abstract:

- Do mark visited nodes when the graph can loop, or you’ll walk in circles forever.
- Don’t assume DFS finds the shortest path, it finds a path and explores deeply, not optimally.

### Algorithm Steps

- Start at the root node by marking it as visited to prevent revisiting it during the traversal.
- Explore each branch by recursively performing DFS on each unvisited neighbor, diving deeper into the graph or tree structure.
- Backtrack once all neighbors of a node are visited, returning to the previous node to continue exploring other branches.

Pseudocode:

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
Tree:
       A
      / \
     B   C
        / \
       D   E
```

Traversal using DFS starting from node 'A':

- Visit 'A' to begin the traversal, marking it as visited.
- Move to 'B', but since 'B' has no unvisited neighbors, backtrack to 'A' to explore other branches.
- Move to 'C', continuing the traversal to the next unvisited node.
- Move to 'D', but as 'D' has no unvisited neighbors, backtrack to 'C'.
- Move to 'E', but since 'E' also has no unvisited neighbors, backtrack to 'C', and then further backtrack to 'A' to complete the exploration.

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

- The time complexity of Depth-First Search (DFS) is $O(V + E)$, where $V$ represents the number of vertices and $E$ represents the number of edges in the graph.
- The space complexity is $O(V)$, primarily due to the space used by the recursion stack or an explicit stack, as well as the memory required for tracking visited nodes.

If you care about performance, the key takeaway is: DFS is often cheap enough to be a default traversal tool, but it can still get expensive in huge graphs. Also, that `visited` flag is doing a lot of work, without it, graphs with cycles can turn DFS into an accidental infinite adventure.

### Applications

- Cycle detection in directed and undirected graphs.
- Topological sorting in directed acyclic graphs (DAGs).
- Solving mazes and puzzles by exploring all possible paths.
- Identifying connected components in a network or graph.

## Backtracking

Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, removing solutions that fail to satisfy the constraints at any point.

At this point, you can think of backtracking as DFS with standards. DFS explores; backtracking explores while enforcing rules and cutting off bad paths early. That’s why people use it for puzzles and constraint problems: you don’t just want to wander, you want to wander with a checklist, so you can confidently say “this can’t possibly work” and move on fast.

Main Idea:

- Building solutions one piece at a time and evaluating them against the constraints.
- Early detection of invalid solutions to prune the search space.
- When a partial solution cannot be extended to a complete solution, the algorithm backtracks to try different options.

The “prune the search space” is the reason backtracking is usable. Without pruning, N-Queens becomes “try everything,” and “everything” grows ridiculously fast. With pruning, you still explore possibilities, but you stop feeding time into branches that are already doomed.

### General Algorithm Framework

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
        return

    for candidate in generate_candidates(partial):
        if is_valid(candidate, partial):
            place(candidate, partial)          // extend partial with candidate
            backtrack(partial)
            unplace(candidate, partial)        // undo extension (backtrack)
```

Pieces you supply per problem:

- `is_complete`: does `partial` represent a full solution?
- `handle_solution`: record/output the solution.
- `generate_candidates`: possible next choices given current partial.
- `is_valid`: pruning test to reject infeasible choices early.
- `place` / `unplace`: apply and revert the choice.

The beauty of this template is that it teaches you what backtracking really is: not one specific algorithm, but a reusable shape. Most backtracking problems differ only in those helper functions. If you can clearly define “what counts as valid so far,” you can solve a lot of classic puzzles with the same skeleton.

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

You can wrap those callbacks into a class or closures for stateful problems. Returning from a complete solution still allows the caller to try the next candidate, so this template enumerates all solutions. To stop at the first solution, return a success flag through every call. If `handle_solution` stores a mutable list, store a copy; otherwise later undo operations alter the recorded result.

One practical “do/don’t” with this style:

- Do make `place/unplace` symmetrical (every change you make must be undone).
- Don’t mutate shared state without undoing it, or you’ll get “ghost effects” where one branch pollutes another.

### Choose, Explore, Unchoose

> **First step:** Before writing code, name the one decision made at each level of the recursion, what the partial solution holds, and the test that says it is complete. Everything else in the function follows from those three answers.

The generic framework above has five callbacks, but in interview problems you rarely write them as separate functions. The shape collapses into three lines inside a loop. You choose a candidate by changing shared state, explore by recursing, and unchoose by reverting exactly the change you made. The shared state is usually a `path` list plus whatever bookkeeping makes validity checks cheap, such as a set of used columns or a running sum.

The recorded answer must be a copy. `path` is a single list that every branch mutates, so `result.append(path)` stores a reference that later pops will empty, and the result ends up full of identical empty lists. Write `result.append(path[:])` or `path.copy()`. When the partial answer is a string built with `s + ch`, a new string is created at every step, so no copy is needed, at the price of $O(L)$ work per step.

The Python-ish framework above already has this shape, with `partial.append` as the choose and `partial.pop` as the unchoose. Total time is roughly the number of nodes in the recursion tree times the work done per node, plus the cost of copying each answer. The most common mistake is an unchoose that does not mirror the choose, for example adding to a set before the recursive call and forgetting to remove it on one of the return paths.

### Estimating Cost From the Output Size

When a problem asks you to return every solution, the size of the answer is a lower bound on the running time. If there are $S$ answers of length $L$, copying them alone costs $O(S \cdot L)$, and no pruning can beat that. So the first estimate is to count the answers. The three counts that appear constantly are

$$
\text{subsets: } 2^n \qquad \text{permutations: } n! \qquad \text{k-combinations: } \binom{n}{k} = \frac{n!}{k!(n-k)!}
$$

This gives the familiar bounds. Subsets (LeetCode 78) is $O(n \cdot 2^n)$, Permutations (LeetCode 46) is $O(n \cdot n!)$, and Combinations (LeetCode 77) is $O(k \cdot \binom{n}{k})$. It also explains the input limits. Since $2^{20}$ is about a million and $10!$ is about 3.6 million, subset problems allow $n$ up to about 20 while permutation problems stop around 8 to 11.

For problems that return a single answer, a yes or no, or a count (Sudoku, N-Queens II, Partition to K Equal Sum Subsets), the output is tiny and the cost is the size of the pruned tree, which is hard to state exactly. There you quote a loose bound such as $O(k^n)$ for assigning $n$ items to $k$ buckets and rely on pruning in practice. The counting rules themselves are derived in [Math Set Relationships](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/math_set_relationship.md).

The common mistake is treating a counting question as an enumeration question. If only the number of answers is required, dynamic programming or a formula is often exponentially faster than listing them.

### Start Index: Subsets and Combinations

> **First step:** Each level picks the next element to add, and it may only pick from positions after the last one used. The partial solution is the chosen list, and for subsets every node of the tree is already an answer.

Order does not matter in a subset or a combination, so {1, 2} and {2, 1} are the same answer. The standard way to generate each set exactly once is to always pick elements in increasing index order. The recursion carries a `start` index and the loop only considers positions from `start` onward. After picking index `i`, the child call receives `i + 1`, so nothing at or before `i` can be picked again.

For Subsets (LeetCode 78) you record the path at every node, including the empty path at the root. For Combinations (LeetCode 77) and Combination Sum III (LeetCode 216) you record only when the path reaches length $k$ (and, for 216, when the sum equals the target). Combinations also has a cheap prune: if fewer elements remain than slots still to fill, the loop can stop early.

```python
def combine(n, k):
    result, path = [], []
    def backtrack(start):
        if len(path) == k:
            result.append(path[:])
            return
        need = k - len(path)
        for i in range(start, n - need + 2):   # leave room for the remaining picks
            path.append(i)
            backtrack(i + 1)
            path.pop()
    backtrack(1)
    return result
```

Letter Combinations of a Phone Number (LeetCode 17) and Letter Case Permutation (LeetCode 784) are the same shape with a different decision per level. The level is a digit or a character position, and the choices are its letters or its two cases. There is no start index because each position is decided exactly once, in order. Binary Watch (LeetCode 401) can be solved by choosing which LEDs are on with a start index, but a direct scan of all 720 times that counts set bits is simpler.

Subsets runs in $O(n \cdot 2^n)$ and Combinations in $O(k \cdot \binom{n}{k})$. The most common mistake is passing `start + 1` instead of `i + 1` to the child, which lets later picks reach back to earlier elements and produces duplicates.

### Used Array: Permutations

> **First step:** Each level fills the next position of the arrangement, and the choice is any element not already placed. The path is complete when its length equals $n$.

In a permutation order matters, so after choosing `nums[2]` the next position may still take `nums[0]`. A start index cannot express that. Instead keep a boolean array `used` (or a bitmask) and loop over every index, skipping those already in the path.

```python
def permute(nums):
    result, path = [], []
    used = [False] * len(nums)
    def backtrack():
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            backtrack()
            path.pop()
            used[i] = False
    backtrack()
    return result
```

Beautiful Arrangement (LeetCode 526) is this template with one extra validity check: value $v$ may go at position $p$ only if $v$ divides $p$ or $p$ divides $v$. Because the check runs before recursing, most branches die after a few levels, and since only the count is required, no path list is needed at all.

Permutations run in $O(n \cdot n!)$ time with $O(n)$ extra space besides the output. The most common mistake is testing `nums[i] in path` instead of keeping a used array, which costs $O(n)$ per test and breaks as soon as the input contains equal values.

### Reuse Allowed: Combination Sum

> **First step:** Each level picks the next candidate to add, from the current index onward. The path is complete when the remaining target is exactly zero and invalid once it would go negative.

Combination Sum (LeetCode 39) allows each number to be used any number of times, but [2, 2, 3] and [2, 3, 2] still count as the same answer. Keep the start index so the order is fixed, and pass `i` instead of `i + 1` to the child so the same element can be picked again. Passing `i + 1` gives each element at most once, as in Combination Sum II (LeetCode 40). Looping from 0 at every level would count ordered sequences instead, which is what Combination Sum IV (LeetCode 377) asks for, and since it only wants a count it is solved with dynamic programming.

Sorting the candidates enables an early exit. Once `candidates[i]` exceeds the remaining target, every later candidate does too, so the loop can `break` rather than `continue`.

```python
def combination_sum(candidates, target):
    candidates.sort()
    result, path = [], []
    def backtrack(start, remaining):
        if remaining == 0:
            result.append(path[:])
            return
        for i in range(start, len(candidates)):
            if candidates[i] > remaining:
                break                                 # sorted, nothing later fits
            path.append(candidates[i])
            backtrack(i, remaining - candidates[i])   # i, not i + 1: reuse allowed
            path.pop()
    backtrack(0, target)
    return result
```

The depth is at most the target divided by the smallest candidate, so the tree is exponential in that depth and the output size usually dominates. The most common mistake is keeping the `break` on unsorted input, where it silently drops valid answers.

### Skipping Duplicates After Sorting

> **First step:** Sort the input so equal values sit next to each other. At any one level of the tree each distinct value may be tried only once, while deeper levels may still use the next copy of it.

Subsets II (LeetCode 90), Combination Sum II (LeetCode 40), and Permutations II (LeetCode 47) take input that may contain duplicates and ask for unique answers. Generating everything and deduplicating with a set of tuples works, but it wastes time exploring identical subtrees. The better fix is never to start two identical subtrees from the same parent.

For the start-index family the rule is `if i > start and nums[i] == nums[i - 1]: continue`. The condition is `i > start` and not `i > 0` because the first candidate at a level is always allowed. If it equals the element just before it, that earlier element was the parent's choice, and taking another copy one level deeper is legitimate, since [1, 2, 2] must be produced. What is forbidden is two siblings with the same value, because they would grow identical subtrees.

```python
def subsets_with_dup(nums):
    nums.sort()
    result, path = [], []
    def backtrack(start):
        result.append(path[:])
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i - 1]:
                continue                  # this value was already tried at this level
            path.append(nums[i])
            backtrack(i + 1)
            path.pop()
    backtrack(0)
    return result
```

Permutations II has no start index, so the rule becomes `if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]: continue`. It forces equal values to be placed in their original left-to-right order, so each distinct arrangement appears once. Non-decreasing Subsequences (LeetCode 491) cannot be sorted, because sorting changes which subsequences exist. There the rule is a fresh `seen` set inside each call, skipping any value already tried at that level, and the same trick works whenever sorting is not allowed.

The worst case is unchanged, but the work now tracks the number of distinct answers instead of every duplicate copy. The most common mistake is writing `i > 0` instead of `i > start`, which removes valid answers such as [1, 2, 2].

### N-Queens Problem

> **First step:** One decision per level is the column of the queen in the current row, so rows never conflict by construction. The partial solution is the list of columns chosen so far, complete when every row has a queen, and a column is invalid if it shares a column or diagonal with an earlier queen.

The N-Queens problem is a classic puzzle in which the goal is to place $N$ queens on an $N \times N$ chessboard such that no two queens threaten each other. In chess, a queen can move any number of squares along a row, column, or diagonal. Therefore, no two queens can share the same row, column, or diagonal.

Objective:

- Place $N$ queens on the board.
- Ensure that no two queens attack each other.
- Find all possible arrangements that satisfy the above conditions.

N-Queens is the poster child for backtracking because it’s easy to describe, hard to brute force, and perfect for pruning. The moment you place a queen, you instantly rule out a bunch of squares. That means you don’t need to “wait until the end” to discover failure, you can detect it as soon as it happens, which is exactly what backtracking wants.

#### Visual Representation

To better understand the problem, let's visualize it using ASCII graphics.

Empty $4 \times 4$ Chessboard:

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

Example Solution for $N = 4$:

One of the possible solutions for placing 4 queens on a $4 \times 4$ chessboard is:

```
  0   1   2   3  (Columns)
+---+---+---+---+
0|   | Q |   |   |  (Queen at position (0, 1))
+---+---+---+---+
1|   |   |   | Q |  (Queen at position (1, 3))
+---+---+---+---+
2| Q |   |   |   |  (Queen at position (2, 0))
+---+---+---+---+
3|   |   | Q |   |  (Queen at position (3, 2))
+---+---+---+---+
(Rows)
```

- `Q` represents a queen.
- Blank spaces represent empty cells.

#### Constraints

- Only one queen per row.
- Only one queen per column.
- No two queens share the same diagonal.

#### Approach Using Backtracking

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

This flow is exactly “choose → test → recurse → undo.” The fun part is that the board doesn’t need to be fully drawn most of the time. You can represent a queen placement compactly (like “row -> column”), and then your safety check becomes pure logic. That’s a nice lesson: backtracking is often more about managing state than about fancy data structures.

#### Python Implementation

Below is a Python implementation of the N-Queens problem using backtracking.

```python
def solve_n_queens(N):
    if N < 0:
        raise ValueError("N must be non-negative")
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

#### Execution Flow

1. Try placing a queen in columns `0` to `N - 1`.
2. For each valid placement, proceed to row `1`.
3. At each row, attempt to place a queen in a safe column.
4. If no safe column is found, backtrack to the previous row.
5. When a valid placement is found for all $N$ rows, record the solution.

#### All Solutions for $N = 4$

There are two distinct solutions for $N = 4$:

Solution 1:

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

Solution 2:

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

#### Output of the Program

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

#### Visualization of the Backtracking Tree

The algorithm explores the solution space as a tree, where each node represents a partial solution (queens placed up to a certain row). The branches represent the possible positions for the next queen.

- Nodes represent partial solutions where a certain number of queens have already been placed in specific rows.
- Branches correspond to the possible positions for placing the next queen in the following row, exploring each valid option.
- Leaves are either complete solutions or dead ends with no valid next placement.

The backtracking occurs when a node has no valid branches (no safe positions in the next row), prompting the algorithm to return to the previous node and try other options.

#### Analysis

I. The search has factorial growth because valid partial placements use distinct columns. The displayed implementation also tests every column and scans earlier rows in `is_safe`. A conservative bound is $O(N^2 N!)$, plus $O(SN)$ to copy $S$ solutions. Quoting $O(N!)$ alone omits this implementation's candidate-checking cost. Column and diagonal sets can make each conflict test constant time.

II. Auxiliary space is $O(N)$, excluding the $O(SN)$ stored output, where:

- The `board` array stores the positions of the $N$ queens.
- The recursion stack can go as deep as $N$ levels during the backtracking process.

This is a good moment to connect the “why should I care?” dot: many real problems look like N-Queens under the hood, scheduling, assignment, routing with constraints, configuration systems, even some parts of compiler design. You’re practicing a general way to search through choices without drowning in them.

#### Applications

- Constraint satisfaction problems often use the N-Queens problem as a classic example to study and develop solutions for placing constraints on variable assignments.
- In algorithm design, the N-Queens problem helps illustrate the principles of backtracking and recursive problem-solving.
- In artificial intelligence, it serves as a foundational example for search algorithms and optimization techniques.

#### Potential Improvements

- Implementing more efficient conflict detection methods.
- Using heuristics to choose the order of columns to try first.
- Converting the recursive solution to an iterative one using explicit stacks to handle larger values of $N$ without stack overflow.

#### Constant-Time Conflict Checks

The implementation above rescans all earlier rows for every candidate. The usual solution for N-Queens (LeetCode 51) and N-Queens II (LeetCode 52) keeps three sets instead. Every square on the same descending diagonal has the same value of $r - c$, and every square on the same ascending diagonal has the same value of $r + c$. A placement is safe when its column, its $r - c$, and its $r + c$ are all unused. Arrays of size $2n - 1$ work too if $r - c$ is shifted by $n - 1$.

```python
def total_n_queens(n):
    cols, diag, anti = set(), set(), set()
    def place(r):
        if r == n:
            return 1
        count = 0
        for c in range(n):
            if c in cols or (r - c) in diag or (r + c) in anti:
                continue
            cols.add(c); diag.add(r - c); anti.add(r + c)
            count += place(r + 1)
            cols.remove(c); diag.remove(r - c); anti.remove(r + c)
        return count
    return place(0)
```

Each node now does $O(n)$ work instead of $O(n^2)$, and the number of nodes is still bounded by roughly $n!$. The most common mistake is using `abs(r - c)` as the diagonal key, which merges two different diagonals and rejects valid boards.

### Sudoku Solver

> **First step:** One decision is the digit for the next empty cell. The partial solution is the grid itself, complete when no empty cell remains, and a digit is invalid if its row, column, or 3 by 3 box already contains it.

Sudoku Solver (LeetCode 37) needs one valid fill, not all of them. Collect the empty cells once, and keep a set of used digits for each row, each column, and each box, where the box index is `(r // 3) * 3 + c // 3`. The recursion walks the list of empty cells and returns `True` the moment it reaches the end. That `True` must travel all the way up without undoing anything, otherwise the solved grid is erased on the way out.

```python
def solve_sudoku(board):
    rows, cols, boxes = [set() for _ in range(9)], [set() for _ in range(9)], [set() for _ in range(9)]
    empty = []
    for r in range(9):
        for c in range(9):
            d = board[r][c]
            if d == '.':
                empty.append((r, c))
            else:
                rows[r].add(d); cols[c].add(d); boxes[r // 3 * 3 + c // 3].add(d)
    def fill(k):
        if k == len(empty):
            return True
        r, c = empty[k]
        b = r // 3 * 3 + c // 3
        for d in "123456789":
            if d in rows[r] or d in cols[c] or d in boxes[b]:
                continue
            board[r][c] = d; rows[r].add(d); cols[c].add(d); boxes[b].add(d)
            if fill(k + 1):
                return True
            board[r][c] = '.'; rows[r].remove(d); cols[c].remove(d); boxes[b].remove(d)
        return False
    fill(0)
```

A large speedup comes from filling the empty cell with the fewest legal digits first instead of going in reading order. The worst case is $O(9^m)$ for $m$ empty cells, though real puzzles prune far below that. The most common mistake is continuing the loop after a solution was found, so later undo steps wipe the answer from the board.

### Example: Maze Solver

> **First step:** One decision is the direction of the next move. The partial solution is the path of cells from the start, complete when it reaches the goal, and a move is invalid if it leaves the grid, hits a wall, or steps on a cell already on the path.

Given a maze represented as a 2D grid, find a path from the starting point to the goal using backtracking. The maze consists of open paths and walls, and movement is allowed in four directions: up, down, left, and right (no diagonal moves). The goal is to determine a sequence of moves that leads from the start to the goal without crossing any walls.

Maze solving makes backtracking feel instantly real. You’re making choices (directions), you hit walls or loops (constraints), and you undo moves when you get stuck. Even if you never care about mazes, you do care about the pattern: this is the same structure as exploring possible decisions in a game AI, navigating states in a program, or searching combinations until you find one that works.

#### Maze Representation

Grid Cells:

- `.` (dot) represents an open path.
- `#` (hash) represents a wall or obstacle.

Allowed Moves:

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

#### Python Implementation

```python
def solve_maze(maze, start, goal):
    if not maze or not maze[0]:
        return None
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
            maze[x][y] = '.'
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

One small but important detail: this code’s `is_valid` only allows stepping onto `'.'`, so `S` and `G` are treated as labels in the diagram, not actual characters in the grid. In practice, you either keep the grid as dots and track `start`/`goal` separately (like this code does), or you expand `is_valid` to allow both `'S'` and `'G'` and restore each cell's original character after exploring it. The version here is consistent because the grid itself is all `'.'` and `'#'`, and the goal is a coordinate.

#### Recursive Function `explore(x, y)`

I. Base Cases:

- If `(x, y)` is not valid (out of bounds, wall, or visited), return `False`.
- If `(x, y)` equals the goal position, append it to `path` and return `True`.

II. Recursive Exploration:

- Mark the current cell `(x, y)` as visited by setting `maze[x][y] = 'V'`.
- Append `(x, y)` to the `path`.
- Recursively attempt to explore neighboring cells in the following order:
- Move Down: `explore(x + 1, y)`
- Move Up: `explore(x - 1, y)`
- Move Right: `explore(x, y + 1)`
- Move Left: `explore(x, y - 1)`
- If a recursive call succeeds, restore the current cell to `'.'` and propagate `True`, retaining the successful path. The input grid is restored on both successful and failed searches.

III. Backtracking:

- If none of the neighboring cells lead to a solution, backtrack:
- Remove `(x, y)` from `path` using `path.pop()`.
- Unmark the cell by setting `maze[x][y] = '.'`.
- Return `False` to indicate that this path does not lead to the goal.

This is the heart of backtracking in one function: mark, explore, undo. The “undo” is what keeps the search honest. Here visited marks belong to the current path and are undone so alternative simple paths can reuse cells. For finding any route in a static maze, a permanent visited set is also correct and avoids repeated exploration. Path-dependent puzzles, such as word search, need more careful state tracking.

#### Execution Flow

I. Start at `(0, 0)`:

- The algorithm begins at the starting position.
- Marks `(0, 0)` as visited and adds it to the path.

II. Explore Neighbors:

- Tries moving Down to `(1, 0)`.

III. Recursive Exploration:

- From `(1, 0)`, continues moving Down to `(2, 0)`.
- From `(2, 0)`, first explores downward through `(3, 0)` into the dead end along row 4. After undoing those moves, it tries right to `(2, 1)`.

IV. Dead Ends and Backtracking:

- If a path leads to a wall or visited cell, the algorithm backtracks to the previous cell and tries a different direction.
- This process continues, exploring all possible paths recursively.

V. Reaching the Goal:

- Eventually, the algorithm reaches the goal `(5, 5)` if a path exists.
- The function returns `True`, and the full path is constructed via the recursive calls.

#### Output

- If a path is found, it prints "Path to goal:" followed by the list of coordinates in the path.
- If no path exists, it prints "No path found."

#### Final Path Found

The path from start to goal:

```
[(0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (1, 2),
 (1, 3), (0, 3), (0, 4), (1, 4), (1, 5), (2, 5),
 (3, 5), (4, 5), (5, 5)]
```

#### Visual Representation of the Path

Let's overlay the path onto the maze for better visualization. We'll use `*` to indicate the path.

```
Maze with Path:

    0   1   2   3   4   5
  +---+---+---+---+---+---+
0 | * | . | # | * | * | . |
  +---+---+---+---+---+---+
1 | * | # | * | * | * | * |
  +---+---+---+---+---+---+
2 | * | * | * | . | # | * |
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

For a rectangular grid with $R$ rows and $C$ columns, this path-based search uses $O(RC)$ auxiliary space but can explore exponentially many simple paths. A DFS with permanent visited marks finds any reachable goal in $O(RC)$ time; BFS has the same time bound and finds a shortest path when every move has equal cost.

#### Advantages of Using Backtracking for Maze Solving

- Ensures that all possible paths are explored until the goal is found.
- Only the current path and visited cells are stored, reducing memory usage compared to storing all possible paths.
- Recursive implementation leads to clean and understandable code.

#### Potential Improvements

- This algorithm finds a path but not necessarily the shortest path.
- To find the shortest path, algorithms like Breadth-First Search (BFS) are more suitable.
- Modify the code to collect all possible paths by removing early returns when the goal is found.
- Allowing diagonal movements would require adjusting the `explore` function to include additional directions.

Choose the search method according to the required result:

- If you just need any solution fast and the maze is small, backtracking is perfect.
- If you need the best solution (shortest path), you switch strategies (like BFS).
- If the search space is massive, you start adding smarter pruning, heuristics, or even entirely different approaches.

The reusable pattern is to represent partial choices, check constraints, explore a candidate, and restore state. Understanding these responsibilities makes it easier to adapt the method to other constraint problems.

### Grid Search With In-Place Marking

> **First step:** One decision is the neighbour to step to next. The partial solution is the current path, marked directly in the grid, and a step is invalid if it leaves the grid, hits a blocked cell, revisits a cell on the current path, or does not match what the problem expects next.

Word Search (LeetCode 79) asks whether a word can be traced through horizontally or vertically adjacent cells without reusing a cell. Start a search from every cell. The recursive call carries the index of the letter being matched, temporarily overwrites the current cell with a marker such as `'#'`, tries the four neighbours, and writes the letter back before returning.

The restore is essential here, unlike in the any-path maze. Whether a cell can continue a match depends on which letter you are on when you reach it, so a cell that failed as the fourth letter may succeed as the sixth letter along another route. A permanent visited set would wrongly rule it out.

```python
def exist(board, word):
    R, C = len(board), len(board[0])
    def dfs(r, c, k):
        if k == len(word):
            return True
        if not (0 <= r < R and 0 <= c < C) or board[r][c] != word[k]:
            return False
        board[r][c] = '#'                       # mark as on the current path
        found = (dfs(r + 1, c, k + 1) or dfs(r - 1, c, k + 1) or
                 dfs(r, c + 1, k + 1) or dfs(r, c - 1, k + 1))
        board[r][c] = word[k]                   # restore before returning
        return found
    return any(dfs(r, c, 0) for r in range(R) for c in range(C))
```

Unique Paths III (LeetCode 980) uses the same mark and restore, but it counts paths from the start square to the end square that walk over every non-obstacle square exactly once. Count the walkable squares first. A path is complete only when it stands on the end square and the number of squares visited equals that count. Reaching the end early is a dead end, not an answer. The grid has at most 20 cells, which is the hint that exponential search is expected.

Word Search costs $O(R \cdot C \cdot 3^{L})$ for a word of length $L$, since after the first step at most three directions are unvisited. The most common mistake is checking `k == len(word)` after the bounds check, which reports failure when the word ends on a border cell and the next call steps off the grid.

### Word Search II With a Trie

Word Search II (LeetCode 212) gives one board and many words. Running the single-word search for each word repeats the same board walks again and again. Instead put all words in a trie and walk the board and the trie together. A branch dies the moment the current prefix is not a child in the trie, which is far stronger pruning than any per-word check.

Two details keep it fast. Store the complete word at its final trie node and remove it once found, so it is reported once. After returning from a child, delete trie nodes that have become empty, so later starting cells do not walk into exhausted branches.

```python
def find_words(board, words):
    root = {}
    for w in words:
        node = root
        for ch in w:
            node = node.setdefault(ch, {})
        node['$'] = w
    R, C, found = len(board), len(board[0]), []
    def dfs(r, c, parent):
        ch = board[r][c]
        node = parent.get(ch)
        if node is None:
            return                                # no word continues this prefix
        if '$' in node:
            found.append(node.pop('$'))           # report each word once
        board[r][c] = '#'
        for nr, nc in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
            if 0 <= nr < R and 0 <= nc < C:
                dfs(nr, nc, node)
        board[r][c] = ch
        if not node:
            del parent[ch]                        # prune an exhausted branch
    for r in range(R):
        for c in range(C):
            dfs(r, c, root)
    return found
```

The worst case is $O(R \cdot C \cdot 3^{L})$ for the longest word length $L$, plus the size of the trie, but the trie pruning makes typical runs much faster. The most common mistake is leaving found words in the trie, which reports the same word several times.

### Partitioning a String

> **First step:** One decision is where the next piece ends. The partial solution is the list of pieces so far, complete when the cut position reaches the end of the string, and a cut is invalid if the new piece breaks the rule (not a palindrome, not a valid IP octet, not one less than the previous number).

Palindrome Partitioning (LeetCode 131) asks for every way to cut a string into palindromes. The recursion carries the start of the next piece and tries every end position. Checking each piece with slicing costs $O(n)$, so it pays to precompute a table `pal[i][j]` that says whether `s[i..j]` is a palindrome. The table fills from short substrings to long ones in $O(n^2)$.

```python
def partition(s):
    n = len(s)
    pal = [[False] * n for _ in range(n)]
    for i in range(n - 1, -1, -1):
        for j in range(i, n):
            pal[i][j] = s[i] == s[j] and (j - i < 2 or pal[i + 1][j - 1])
    result, path = [], []
    def backtrack(start):
        if start == n:
            result.append(path[:])
            return
        for end in range(start, n):
            if pal[start][end]:
                path.append(s[start:end + 1])
                backtrack(end + 1)
                path.pop()
    backtrack(0)
    return result
```

Restore IP Addresses (LeetCode 93) is the same cut-position recursion with exactly four pieces. Each piece has one to three digits, a value of at most 255, and no leading zero unless the piece is exactly "0". It also prunes on length: the characters left must be at least the number of pieces left and at most three times that number. Splitting a String Into Descending Consecutive Values (LeetCode 1849) tries every first piece except the whole string, after which each next piece must equal the previous value minus one. Since the next value is forced, the tree is very narrow. Compare values as integers, because pieces may have leading zeros.

A string of length $n$ has $2^{n-1}$ ways to cut it, so Palindrome Partitioning is $O(n \cdot 2^n)$ in the worst case, for example a string of identical letters. The most common mistake in Restore IP Addresses is forgetting the leading-zero rule, which accepts pieces like "01".

### Generating Balanced Parentheses

> **First step:** Each level appends either an opening or a closing bracket. The partial solution is the string so far with its open and close counts, complete at length $2n$, and a bracket is invalid if it would make open exceed $n$ or close exceed open.

Generate Parentheses (LeetCode 22) shows how much a validity check during the search saves. Generating all $2^{2n}$ strings and filtering at the end is wasteful. Allowing `(` only while fewer than $n$ have been used, and `)` only while it closes something, means every leaf is already a valid answer.

```python
def generate_parenthesis(n):
    result = []
    def backtrack(s, open_, close):
        if len(s) == 2 * n:
            result.append(s)
            return
        if open_ < n:
            backtrack(s + "(", open_ + 1, close)
        if close < open_:
            backtrack(s + ")", open_, close + 1)
    backtrack("", 0, 0)
    return result
```

Remove Invalid Parentheses (LeetCode 301) runs the logic in reverse. First scan once to find how many `(` and how many `)` must be removed at minimum. Then backtrack over positions, deciding to keep or delete each bracket while those two budgets last, and accept a string when both budgets are zero and it is balanced. To avoid duplicate results, when several identical brackets sit in a row, only try deleting the first of the run at each level. A breadth-first search that deletes one character per level is a common alternative.

The number of answers to Generate Parentheses is the Catalan number $\frac{1}{n+1}\binom{2n}{n}$, which grows roughly like $4^n / n^{3/2}$. The most common mistake is checking balance only at the end, which explores every one of the $2^{2n}$ strings.

### Building Expressions With Operators

> **First step:** One decision is the next operand (a run of digits) and the operator placed before it. The partial state is the expression text, its value so far, and the last term added, complete when all digits are used, and an operand is invalid if it has a leading zero.

Expression Add Operators (LeetCode 282) inserts `+`, `-`, or `*` between digits to hit a target. Addition and subtraction are easy to evaluate on the fly. Multiplication binds tighter, so when you append `* cur` the last term has already been added to the running value and must be taken back out. If the value is `value` and the last term is `last`, the new value is `value - last + last * cur` and the new last term is `last * cur`. For subtraction the last term is stored as `-cur`, so a following multiplication is handled the same way.

```python
def add_operators(num, target):
    result = []
    def backtrack(i, expr, value, last):
        if i == len(num):
            if value == target:
                result.append(expr)
            return
        for j in range(i, len(num)):
            if j > i and num[i] == '0':
                break                             # no leading zeros in an operand
            s = num[i:j + 1]
            cur = int(s)
            if i == 0:
                backtrack(j + 1, s, cur, cur)
            else:
                backtrack(j + 1, expr + "+" + s, value + cur, cur)
                backtrack(j + 1, expr + "-" + s, value - cur, -cur)
                backtrack(j + 1, expr + "*" + s, value - last + last * cur, last * cur)
    backtrack(0, "", 0, 0)
    return result
```

Between each pair of adjacent digits there are four options (join, plus, minus, times), so the search is $O(n \cdot 4^n)$ including the string building. The most common mistake is evaluating strictly left to right, which turns `2+3*2` into 10 instead of 8.

### Filling K Buckets

> **First step:** One decision is which bucket receives the next item, with items taken largest first. The partial solution is the list of bucket sums, complete when every item is placed, and a placement is invalid if it pushes a bucket over the target.

Partition to K Equal Sum Subsets (LeetCode 698) asks whether an array can be split into $k$ groups with equal sums. The target per bucket is the total divided by $k$, and if the total is not divisible or some item exceeds the target the answer is immediately false. Sorting the items in decreasing order makes failures happen near the root, where they cut the most.

The decisive prune is symmetry. Buckets are interchangeable, so placing the current item into two buckets that hold the same sum leads to identical subtrees. Skip a bucket whose sum was already tried for this item. This covers the important special case where an item fails in an empty bucket, after which every other empty bucket would fail too.

```python
def can_partition_k(nums, k):
    total = sum(nums)
    if total % k:
        return False
    target = total // k
    nums.sort(reverse=True)
    if nums[0] > target:
        return False
    buckets = [0] * k
    def place(i):
        if i == len(nums):
            return True                       # no bucket exceeds target, so all equal it
        tried = set()
        for b in range(k):
            if buckets[b] + nums[i] > target or buckets[b] in tried:
                continue
            tried.add(buckets[b])             # equal sums give identical subtrees
            buckets[b] += nums[i]
            if place(i + 1):
                return True
            buckets[b] -= nums[i]
        return False
    return place(0)
```

Matchsticks to Square (LeetCode 473) is this function with $k = 4$. Find Minimum Time to Finish All Jobs (LeetCode 1723) and Fair Distribution of Cookies (LeetCode 2305) use the same item-to-bucket recursion but minimize the largest bucket, so they keep a global best and abandon any branch whose largest bucket already reaches it. Campus Bikes II (LeetCode 1066) assigns each worker a distinct bike, which is a used-array search that works for its tiny limits, though dynamic programming over a bitmask of used bikes is the safer answer.

The worst case is $O(k^n)$, and a bitmask dynamic programming alternative runs in $O(n \cdot 2^n)$. The most common mistake is omitting the symmetry prune, which explores each partition up to $k!$ times and times out.

### Other Common Variations

Maximum Length of a Concatenated String with Unique Characters (LeetCode 1239) is an include-or-exclude search over the strings. Drop any string that repeats a letter internally, turn each remaining string into a 26-bit mask, and include a string only when its mask shares no bit with the current mask. With at most 16 strings, the $2^n$ subsets are cheap.

Path Sum II (LeetCode 113) is backtracking on a tree. Append the node to the path, subtract its value from the remaining sum, recurse into both children, and pop on the way out. Record a copy of the path only at a leaf where the remaining sum is zero. Values may be negative, so a running sum that overshoots the target is not a reason to stop early.

Gray Code (LeetCode 89) can be built by backtracking that flips one bit at a time and skips codes already used. The direct formula `i ^ (i >> 1)` produces a valid sequence in $O(2^n)$ with no search, so it is usually the better answer.

## List of Problems

### Permutations

Develop an algorithm to generate all possible permutations of a given list of elements. This problem requires creating different arrangements of the elements where the order matters.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_permutations)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_permutations)

### Combinations

Design an algorithm to generate all possible combinations of 'k' elements selected from a given list of elements. This involves selecting elements where the order does not matter, but the selection size does.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/all_combinations)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/all_combinations)

### String Pattern

Determine whether pattern symbols can be mapped to nonempty substrings so that concatenating their mappings reproduces the entire input string. Repeated occurrences of a symbol must use the same substring. For example, `abab` can match `redblueredblue` with `a → red` and `b → blue`. State separately whether distinct symbols must have distinct mappings; that is an additional constraint, not ordinary wildcard matching.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/string_pattern)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/string_pattern)

### Generating Words

Given a board of letters and a dictionary, find dictionary words formed by paths through neighboring cells. This exercise allows horizontal, vertical, and diagonal moves. Track cells used in the current path, define whether reuse is allowed, and reject prefixes that cannot lead to dictionary words.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/generating_words)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/generating_words)

### Hamiltonian Path

Create an algorithm that identifies whether a simple path exists within a provided undirected or directed graph. This path should visit every vertex exactly once. A Hamiltonian path visits every vertex once; a Hamiltonian cycle also returns to its start. The traveling salesperson problem is a related optimization problem that asks for a minimum-weight tour. Backtracking can enumerate candidate paths and reject repeated vertices.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/hamiltonian_paths)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/hamiltonian_paths)

### K-Colorable Configurations

Develop an algorithm to find all possible ways to color a given graph with 'k' colors such that no two adjacent vertices share the same color. This graph coloring problem requires ensuring valid color assignments for all vertices.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/k_colorable_configurations)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/k_colorable_configurations)

### Knight Tour

Create an algorithm to find all potential paths a knight can take on an 'n' x 'n' chessboard to visit every square exactly once. This classic chess problem involves ensuring the knight moves in an L-shape and covers all board positions.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/knight_tour)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/knight_tour)

### Topological Orderings

Enumerate topological orderings of a directed acyclic graph by repeatedly choosing an available zero-indegree vertex, updating indegrees, and undoing the choice. If only one ordering is needed, a standard topological sort is more efficient. This involves sorting the vertices such that for every directed edge UV from vertex U to vertex V, U comes before V in the ordering.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/topological_sort)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/topological_sort)

### Tic-Tac-Toe (Minimax)

Develop an algorithm to determine the optimal move for a player in a game of tic-tac-toe using the minimax algorithm. This requires evaluating possible moves to find the best strategy for winning or drawing the game.

- [C++ Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/cpp/minimax)
- [Python Solution](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/backtracking/python/minimax)

## Reading the Problem Statement

The wording and the constraints of a backtracking problem usually tell you which template to use before you design anything. This table maps common phrases to the decision they imply.

| If the problem says | What it means for your code |
|---|---|
| "Return all" subsets, combinations, or arrangements | Backtracking that records a copy at each answer, with the output size setting the running time. |
| "Return the number of" ways | Look for dynamic programming or a formula first, and backtrack only when n is tiny. |
| "Return any valid solution" or "return true if possible" | Return True up the stack as soon as one complete solution is found and skip the undo on that path. |
| "May contain duplicates" and "unique" answers | Sort, then skip `nums[i] == nums[i - 1]` when `i > start`, or when the earlier copy is unused for permutations. |
| "Each number may only be used once" | Pass `i + 1` to the child call. |
| "The same number may be chosen an unlimited number of times" | Pass `i` to the child call. |
| "Order does not matter" or "combinations" | Use a start index so each set is built in one fixed order. |
| "All possible orderings" or "permutations" | Loop over every index with a used array or bitmask. |
| n up to about 8 to 11 | An $n!$ search over arrangements fits. |
| n up to about 15 to 20 | A $2^n$ search over subsets, or dynamic programming over a bitmask, fits. |
| n around 30 to 40 with a subset question | Plain subset search is too slow, so think of meet in the middle or dynamic programming. |
| "All candidates are positive" | After sorting, `break` once a candidate exceeds the remaining target. |
| "Subsequence" or the input order must be kept | Do not sort, and deduplicate with a set per recursion level. |
| A grid path that "walks over every non-obstacle square exactly once" | Mark cells in place, count visited cells, restore on return, and accept only at the end square with all cells used. |
| "The same cell may not be used more than once" in a word on a grid | Use path-local marks restored on return, never a permanent visited set. |
| A list of many words to find on one board | Build a trie and walk it during the search. |
| "Partition into k subsets with equal sums" | Check divisibility, sort descending, fill buckets, and skip buckets with equal sums. |
| "Split the string" or "insert dots" or "insert operators" | Recurse on the cut position and validate each piece, including leading zeros. |
| "Minimize the maximum" load over an assignment | Keep a global best and prune branches that reach it, or binary search the answer with a feasibility check. |
| "Well-formed" or "valid" parentheses | Track open and close counts and never let close exceed open. |
