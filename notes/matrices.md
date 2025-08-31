## Matrices and 2D Grids

Matrices represent images, game boards, and maps. Many classic problems reduce to transforming matrices, traversing them, or treating grids as graphs for search.

### Conventions

**Rows indexed $0..R-1$, columns $0..C-1$; cell $(r,c)$.**

Rows increase **down**, columns increase **right**. Think “top-left is $(0,0)$”, not a Cartesian origin.

Visual index map (example $R=6$, $C=8$; each cell labeled $rc$):

```
  c →    0    1    2    3    4    5    6    7
r ↓   +----+----+----+----+----+----+----+----+
0     | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 |
	  +----+----+----+----+----+----+----+----+
1     | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |
	  +----+----+----+----+----+----+----+----+
2     | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 |
	  +----+----+----+----+----+----+----+----+
3     | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 |
	  +----+----+----+----+----+----+----+----+
4     | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
	  +----+----+----+----+----+----+----+----+
5     | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 |
	  +----+----+----+----+----+----+----+----+
```

Handy conversions (for linearization / array-of-arrays):

* Linear index: $\text{id}=r\cdot C+c$.
* From id: $r=\lfloor \text{id}/C \rfloor$, $c=\text{id}\bmod C$.
* Row-major scan order (common in problems): for $r$ in $0..R-1$, for $c$ in $0..C-1$.

**Row-major vs column-major arrows (same $3\times 6$ grid):**

```
Row-major (r, then c):                  Column-major (c, then r):
→ → → → → →                              ↓ ↓ ↓
↓             ↓                          ↓ ↓ ↓
← ← ← ← ← ←                              ↓ ↓ ↓
↓             ↓                          ↓ ↓ ↓
→ → → → → →                              ↓ ↓ ↓
```

**Neighborhoods: $\mathbf{4}$-dir $\Delta={(-1,0),(1,0),(0,-1),(0,1)}$; $\mathbf{8}$-dir adds diagonals.**

The offsets $(\Delta r,\Delta c)$ are applied as $(r+\Delta r,\ c+\Delta c)$.

**4-neighborhood (“+”):**

```
		   (r-1,c)
			 ↑
  (r,c-1) ← (r,c) → (r,c+1)
			 ↓
		   (r+1,c)
```

**8-neighborhood (“×” adds diagonals):**

```
   (r-1,c-1)   (r-1,c)   (r-1,c+1)
		  \       ↑       /
		   \      │      /
  (r,c-1) ←———  (r,c)  ———→ (r,c+1)
		   /      │      \
		  /       ↓       \
   (r+1,c-1)   (r+1,c)   (r+1,c+1)
```

Typical direction arrays (keep them consistent to avoid bugs):

```
// 4-dir
dr = [-1, 1,  0, 0]
dc = [ 0, 0, -1, 1]

// 8-dir
dr8 = [-1,-1,-1, 0, 0, 1, 1, 1]
dc8 = [-1, 0, 1,-1, 1,-1, 0, 1]
```

**Boundary checks** (always guard neighbors):

```
0 ≤ nr < R  and  0 ≤ nc < C
```

**Edge/inside intuition:**

```
	   out of bounds
	┌─────────────────┐
	│ · · · · · · · · │
	│ · +---+---+---+ │
	│ · | a | b | c | │   ← valid cells
	│ · +---+---+---+ │
	│ · | d | e | f | │
	│ · +---+---+---+ │
	│ · · · · · · · · │
	└─────────────────┘
```

### Basic Operations (Building Blocks)

#### Transpose

Swap across the main diagonal: $A_{r,c} \leftrightarrow A_{c,r}$ (square). For non-square, result shape is $C\times R$.

**Example inputs and outputs**

*Example 1 (square)*

$$
A = \begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\quad\Rightarrow\quad
A^{\mathsf{T}} =
\begin{bmatrix}
1 & 4 & 7 \\
2 & 5 & 8 \\
3 & 6 & 9
\end{bmatrix}
$$

*Example 2 (rectangular)*

$$
\text{Input: } \quad 
A = \begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6
\end{bmatrix}
\ (2 \times 3)
$$

$$
\text{Output: } \quad 
A^{\mathsf{T}} = \begin{bmatrix}
1 & 4 \\
2 & 5 \\
3 & 6
\end{bmatrix}
\ (3 \times 2)
$$

**How it works**

Iterate pairs once and swap. For square matrices, can be in-place by visiting only $c>r$.

* Time: $O(R\cdot C)$
* Space: $O(1)$ in-place (square), else $O(R\cdot C)$ to allocate

#### Reverse Rows (Horizontal Flip)

Reverse each row left $\leftrightarrow$ right.

**Example inputs and outputs**

*Example*

$$
\text{Input: }
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: }
\begin{bmatrix}
3 & 2 & 1 \\
6 & 5 & 4
\end{bmatrix}
$$

* Time: $O(R\cdot C)$
* Space: $O(1)$

#### Reverse Columns (Vertical Flip)

Reverse each column top $\leftrightarrow$ bottom.

**Example inputs and outputs**

*Example*

$$
\text{Input: }
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: }
\begin{bmatrix}
7 & 8 & 9 \\
4 & 5 & 6 \\
1 & 2 & 3
\end{bmatrix}
$$

* Time: $O(R\cdot C)$
* Space: $O(1)$

### Rotations (Composed from Basics)

Use transpose + reversals for square in-place rotations; rectangular rotations produce new shape $(R\times C)\to(C\times R)$.

#### 90° Clockwise (CW)

Transpose, then reverse each row.

**Example inputs and outputs**

*Example 1 (3×3)*

$$
\text{Input: } 
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: } 
\begin{bmatrix}
7 & 4 & 1 \\
8 & 5 & 2 \\
9 & 6 & 3
\end{bmatrix}
$$

*Example 2 (2×3 → 3×2)*

$$
\text{Input: }
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: }
\begin{bmatrix}
4 & 1 \\
5 & 2 \\
6 & 3
\end{bmatrix}
$$

**How it works**

Transpose swaps axes; reversing each row aligns columns to rows of the rotated image.

* Time: $O(R\cdot C)$
* Space: $O(1)$ in-place for square, else $O(R\cdot C)$ new

#### 90° Counterclockwise (CCW)

Transpose, then reverse each column (or reverse rows, then transpose).

**Example inputs and outputs**

*Example*

$$
\text{Input: }
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: }
\begin{bmatrix}
3 & 6 & 9 \\
2 & 5 & 8 \\
1 & 4 & 7
\end{bmatrix}
$$

**How it works**

Transpose, then flip vertically to complete the counterclockwise rotation.

* Time: $O(R\cdot C)$
* Space: $O(1)$ (square) or $O(R\cdot C)$

#### 180° Rotation

Equivalent to reversing rows, then reversing columns (or two 90° rotations).

**Example inputs and outputs**

*Example*

$$
\text{Input: }
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: }
\begin{bmatrix}
9 & 8 & 7 \\
6 & 5 & 4 \\
3 & 2 & 1
\end{bmatrix}
$$

**How it works**

Horizontal + vertical flips relocate each element to $(R-1-r,\ C-1-c)$.

* Time: $O(R\cdot C)$
* Space: $O(1)$ (square) or $O(R\cdot C)$

#### 270° Rotation

270° CW = 90° CCW; 270° CCW = 90° CW. Reuse the 90° procedures.

#### Layer-by-Layer (Square) 90° CW

Rotate each ring by cycling 4 positions.

**How it works**

For layer $\ell$ with bounds $[\ell..n-1-\ell]$, for each offset move:

```
top ← left, left ← bottom, bottom ← right, right ← top
```

* Time: $O(n^{2})$
* Space: $O(1)$

### Traversal Patterns

#### Spiral Order

Read outer layer, then shrink bounds.

**Example inputs and outputs**

*Example*

$$
\text{Input: }
\begin{bmatrix}
1 & 2 & 3 & 4 \\
5 & 6 & 7 & 8 \\
9 & 10 & 11 & 12
\end{bmatrix}
$$

$$
\text{Output sequence: } 1,2,3,4,8,12,11,10,9,5,6,7
$$

**How it works**

Maintain top, bottom, left, right. Walk edges in order; after each edge, move the corresponding bound inward.

* Time: $O(R\cdot C)$; Space: $O(1)$ beyond output.

#### Diagonal Order (r+c layers)

Visit cells grouped by $s=r+c$; alternate direction per diagonal to keep locality if desired.

**Example inputs and outputs**

*Example*

$$
\text{Input: }
\begin{bmatrix}
a & b & c \\
d & e & f
\end{bmatrix}
\quad\Rightarrow\quad
\text{One order: } a, b, d, e, c, f
$$

* Time: $O(R\cdot C)$; Space: $O(1)$.

### Grids as Graphs

Each cell is a node; edges connect neighboring walkable cells.

**Grid-as-graph view (4-dir edges).** Each cell is a node; edges connect neighbors that are “passable”. Great for BFS shortest paths on unweighted grids.

**Example map (walls `#`, free `.`, start `S`, target `T`).**
Left: the map. Right: BFS distances (4-dir) from `S` until `T` is reached.

```
Original Map:
#####################
#S..#....#....#.....#
#.#.#.##.#.##.#.##..#
#.#...#..#.......#.T#
#...###.....###.....#
#####################

BFS layers (distance mod 10):
#####################
#012#8901#9012#45678#
#1#3#7##2#8##1#3##89#
#2#456#43#7890123#7X#
#345###54567###34567#
#####################

Legend: walls (#), goal reached (X)
```

BFS explores in **expanding “rings”**; with 4-dir edges, each step increases Manhattan distance by 1 (unless blocked). Time $O(RC)$, space $O(RC)$ with a visited matrix/queue.

**Obstacles / costs / diagonals.**

* Obstacles: skip neighbors that are `#` (or where cost is $\infty$).
* Weighted grids: Dijkstra / 0-1 BFS on the same neighbor structure.
* 8-dir with Euclidean costs: use $1$ for orthogonal moves and $\sqrt{2}$ for diagonals (A\* often pairs well here with an admissible heuristic).

**Common symbols:**

```
. = free cell      # = wall/obstacle
S = start          T = target/goal
V = visited        * = on current path / frontier
```

#### BFS Shortest Path (Unweighted)

Find the minimum steps from S to T.

**Example inputs and outputs**

*Example*

$$
\text{Grid (0 = open, 1 = wall), } S = (0,0), T = (2,3)
$$

$$
\begin{bmatrix}
S & 0 & 1 & 0 \\
0 & 0 & 0 & 0 \\
1 & 1 & 0 & T
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: distance } = 5
$$

**How it works**

Push S to a queue, expand in 4-dir layers, track distance/visited; stop when T is dequeued.

* Time: $O(R\cdot C)$; Space: $O(R\cdot C)$.

#### Connected Components (Islands)

Count regions of ‘1’s via DFS/BFS.

**Example inputs and outputs**

$$
\text{Input: }
\begin{bmatrix}
1 & 1 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}
\quad\Rightarrow\quad
\text{Output: } 2 \ \text{islands}
$$

**How it works**

Scan cells; when an unvisited ‘1’ is found, flood it (DFS/BFS) to mark the whole island.

* Time: $O(R\cdot C)$
* Space: $O(R\cdot C)$ worst-case

### Backtracking on Grids

#### Word Search (Single Word)

Find a word by moving to adjacent cells (4-dir), using each cell once per path.

**Example inputs and outputs**

$$
\text{Board: }
\begin{bmatrix}
A & B & C & E \\
S & F & C & S \\
A & D & E & E
\end{bmatrix},
\quad
\text{Word: } "ABCCED"
\quad\Rightarrow\quad
\text{Output: true}
$$

**How it works**

From each starting match, DFS to next char; mark visited (temporarily), backtrack on failure.

* Time: up to $O(R\cdot C\cdot b^{L})$ (branching $b\in[3,4]$, word length $L$)
* Space: $O(L)$

Pruning: early letter mismatch; frequency precheck; prefix trie when searching many words.

#### Crossword-style Fill (Multiple Words)

Place words to slots with crossings; verify consistency at intersections.

**How it works**

Backtrack over slot assignments; use a trie for prefix feasibility; order by most constrained slot first.

* Time: exponential in slots; strong pruning and good heuristics are crucial.

