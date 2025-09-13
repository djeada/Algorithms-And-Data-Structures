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
          ↓                              ↓ ↓ ↓
← ← ← ← ← ←                              ↓ ↓ ↓
↓                                        ↓ ↓ ↓
→ → → → → →                              ↓ ↓ ↓
```

**Neighborhoods: $\mathbf{4}$-dir $\Delta={(-1,0),(1,0),(0,-1),(0,1)}$; $\mathbf{8}$-dir adds diagonals.**

The offsets $(\Delta r,\Delta c)$ are applied as $(r+\Delta r,\ c+\Delta c)$.

**4-neighborhood (“+”):**

```
#
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

**Mathematical formula (3×3)**

$$
(A^{\mathsf T})_{r,c}=A_{c,r},\quad 0\le r,c<3.
$$

**Pseudocode (square, in-place)**

```
n = 3  # for this example; generalize to n = size
for r in 0..n-1:
  for c in r+1..n-1:
    swap A[r][c], A[c][r]
```

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

**Mathematical formula (2×3 → 3×2)**

$$
(A^{\mathsf T})_{r,c}=A_{c,r},\quad 0\le r<3,\ 0\le c<2.
$$

**Pseudocode (rectangular, new matrix)**

```
R, C = 2, 3
B = zeros(C, R)
for r in 0..R-1:
  for c in 0..C-1:
    B[c][r] = A[r][c]
```

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

**Mathematical formula (2×3)**

$$
B_{r,c}=A_{r,\ C-1-c},\quad 0\le r<2,\ 0\le c<3.
$$

**Pseudocode (in-place)**

```
R, C = 2, 3
for r in 0..R-1:
  for c in 0..(C//2 - 1):
    swap A[r][c], A[r][C-1-c]
```

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

**Mathematical formula (3×3)**

$$
B_{r,c}=A_{R-1-r,\ c},\quad 0\le r,c<3.
$$

**Pseudocode (in-place)**

```
R, C = 3, 3
for r in 0..(R//2 - 1):
  for c in 0..C-1:
    swap A[r][c], A[R-1-r][c]
```

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

**Mathematical formula (n×n)**

$$
B_{r,c}=A_{n-1-c,\ r},\quad 0\le r,c<n.
$$

**Pseudocode (square, in-place via basics)**

```
n = 3
# transpose
for r in 0..n-1:
  for c in r+1..n-1:
    swap A[r][c], A[c][r]
# reverse each row
for r in 0..n-1:
  for c in 0..(n//2 - 1):
    swap A[r][c], A[r][n-1-c]
```

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

**Mathematical formula (R×C → C×R)**

$$
B_{r,c}=A_{R-1-c,\ r},\quad 0\le r<C,\ 0\le c<R\ \ (R{=}2,\ C{=}3).
$$

**Pseudocode (rectangular, direct mapping)**

```
R, C = 2, 3
B = zeros(C, R)
for r in 0..C-1:      # rows of B
  for c in 0..R-1:    # cols of B
    B[r][c] = A[R-1-c][r]
```

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

**Mathematical formula (n×n)**

$$
B_{r,c}=A_{c,\ n-1-r},\quad 0\le r,c<n.
$$

**Pseudocode (square, via basics)**

```
n = 3
# transpose
for r in 0..n-1:
  for c in r+1..n-1:
    swap A[r][c], A[c][r]
# reverse each column (vertical flip)
for r in 0..(n//2 - 1):
  for c in 0..n-1:
    swap A[r][c], A[n-1-r][c]
```

**Pseudocode (general, direct mapping)**

```
# A is R x C, B is C x R
B = zeros(C, R)
for r in 0..C-1:
  for c in 0..R-1:
    B[r][c] = A[c][C-1-r]
```

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

**Mathematical formula (R×C → R×C)**

$$
B_{r,c}=A_{R-1-r,\ C-1-c},\quad 0\le r<R,\ 0\le c<C.
$$

**Pseudocode (in-place via two flips)**

```
R, C = 3, 3  # generalize as needed
# reverse rows
for r in 0..R-1:
  for c in 0..(C//2 - 1):
    swap A[r][c], A[r][C-1-c]
# reverse columns
for r in 0..(R//2 - 1):
  for c in 0..C-1:
    swap A[r][c], A[R-1-r][c]
```

**Pseudocode (direct mapping to new matrix)**

```
B = zeros(R, C)
for r in 0..R-1:
  for c in 0..C-1:
    B[r][c] = A[R-1-r][C-1-c]
```

**How it works**

Horizontal + vertical flips relocate each element to $(R-1-r,\ C-1-c)$.

* Time: $O(R\cdot C)$
* Space: $O(1)$ (square) or $O(R\cdot C)$

#### 270° Rotation

270° CW = 90° CCW; 270° CCW = 90° CW. Reuse the 90° procedures.

**Mathematical formulas (general)**

270° CW (i.e., 90° CCW):

$$
B_{r,c}=A_{c,\ C-1-r},\quad B\in\mathbb{R}^{C\times R}.
$$

270° CCW (i.e., 90° CW):

$$
B_{r,c}=A_{R-1-c,\ r},\quad B\in\mathbb{R}^{C\times R}.
$$

**Pseudocode (via composition, square in-place)**

```
# 270° CW == 90° CCW
transpose(A)
reverse_columns_in_place(A)

# 270° CCW == 90° CW
transpose(A)
reverse_rows_in_place(A)
```

#### Layer-by-Layer (Square) 90° CW

Rotate each ring by cycling 4 positions.

**How it works**

For layer $\ell$ with bounds $ [\ell..n-1-\ell]$, for each offset move:

```
top ← left, left ← bottom, bottom ← right, right ← top
```

**Mathematical mapping (per moved element)**

For an $n\times n$ matrix and a position $(r,c)$ on layer $\ell$, a 90° CW rotation sends

$$
(r,c)\ \mapsto\ (c,\ n-1-r)\ \mapsto\ (n-1-r,\ n-1-c)\ \mapsto\ (n-1-c,\ r).
$$

**Pseudocode (explicit loops, in-place)**

```
n = size(A)
for layer in 0..(n//2 - 1):
  first = layer
  last  = n - 1 - layer
  for i in first..last-1:
    offset = i - first

    # save top
    tmp = A[first][i]

    # left -> top
    A[first][i] = A[last - offset][first]

    # bottom -> left
    A[last - offset][first] = A[last][last - offset]

    # right -> bottom
    A[last][last - offset] = A[i][last]

    # top (saved) -> right
    A[i][last] = tmp
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

**Mathematical formulation (general $R\times C$)**

Let the matrix indices be $(r,c)$ with $0\le r<R,\ 0\le c<C$. For layer $\ell=0,1,\dots,L-1$ where $L=\left\lceil \tfrac{\min(R,C)}{2}\right\rceil$, set

$$
t=\ell,\quad b=R-1-\ell,\quad left=\ell,\quad rgt=C-1-\ell .
$$

Visit, in order:

* Top edge: $(t,c)$ for $c=left,\ldots,rgt$.
* Right edge: $(r,rgt)$ for $r=t+1,\ldots,b$.
* Bottom edge (if $b>t$): $(b,c)$ for $c=rgt-1,\ldots,left$ (decreasing).
* Left edge (if $rgt>left$): $(r,left)$ for $r=b-1,\ldots,t+1$ (decreasing).

Concatenate these per layer until all elements are visited.

**Pseudocode (loops)**

```
R, C = dims(A)
top, bottom = 0, R - 1
left, right = 0, C - 1
out = []

while top <= bottom and left <= right:
  # top row
  for c in left..right:
    out.append(A[top][c])
  top += 1

  # right column
  for r in top..bottom:
    out.append(A[r][right])
  right -= 1

  # bottom row (if any)
  if top <= bottom:
    for c in right..left step -1:
      out.append(A[bottom][c])
    bottom -= 1

  # left column (if any)
  if left <= right:
    for r in bottom..top step -1:
      out.append(A[r][left])
    left += 1
```

**How it works**

Maintain top, bottom, left, right. Walk edges in order; after each edge, move the corresponding bound inward.

* Time: $O(R\cdot C)$
* Space: $O(1)$ beyond output.

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

**Mathematical formulation (general $R\times C$)**

Let $s=r+c$. For $s=0,1,\dots,R+C-2$, define

$$
r_{\min}(s)=\max\!\big(0,\ s-(C-1)\big),\qquad
r_{\max}(s)=\min\!\big(R-1,\ s\big).
$$

The diagonal set is $\{(r,s-r)\mid r_{\min}(s)\le r\le r_{\max}(s)\}$.
Traverse with alternating direction:

$$
\begin{cases}
\text{if } s \text{ even: } r=r_{\max}(s), r_{\max}(s)-1,\dots,r_{\min}(s);\ [2pt]
\text{if } s \text{ odd: } r=r_{\min}(s), r_{\min}(s)+1,\dots,r_{\max}(s).
\end{cases}
$$

(This parity choice reproduces the example order $a,b,d,e,c,f$ for $R=2,C=3$.)

**Pseudocode (loops, alternating direction)**

```
R, C = dims(A)
out = []

for s in 0..(R + C - 2):
  r_lo = max(0, s - (C - 1))
  r_hi = min(R - 1, s)

  if s % 2 == 0:
    # even s: go downward-left (decreasing r)
    for r in r_hi..r_lo step -1:
      c = s - r
      out.append(A[r][c])
  else:
    # odd s: go upward-right (increasing r)
    for r in r_lo..r_hi:
      c = s - r
      out.append(A[r][c])
```

* Time: $O(R\cdot C)$
* Space: $O(1)$

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

**Mathematical formulation (general)**

Let the word be $W=W_0W_1\cdots W_{L-1}$ and the grid be $G\in\Sigma^{R\times C}$.
We seek a path $P=\big((r_0,c_0),\ldots,(r_{L-1},c_{L-1})\big)$ such that

$$
\begin{aligned}
&\text{(match)} && G_{r_i,c_i}=W_i,\quad i=0,\ldots,L-1;\\
&\text{(adjacent)} && |r_{i+1}-r_i|+|c_{i+1}-c_i|=1,\quad i=0,\ldots,L-2;\\
&\text{(no reuse)} && (r_i,c_i)\neq(r_j,c_j)\ \text{for all }i\ne j.
\end{aligned}
$$

**Instantiation for the example (one valid path)**

$$
P=\big((0,0),(0,1),(0,2),(1,2),(2,2),(2,1)\big)
$$

gives $A\to B\to C\to C\to E\to D = \text{"ABCCED"}$.

**Pseudocode (DFS with loops over starts and 4-neighbors)**

```
R, C = dims(board)
L = len(word)
visited = array(R, C, fill=false)
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

def dfs(r, c, i):
  if r < 0 or r >= R or c < 0 or c >= C: 
    return false
  if visited[r][c] or board[r][c] != word[i]:
    return false
  if i == L - 1:
    return true

  visited[r][c] = true
  for k in 0..3:
    nr = r + dr[k]
    nc = c + dc[k]
    if dfs(nr, nc, i + 1):
      return true
  visited[r][c] = false
  return false

# try every starting cell
for r in 0..R-1:
  for c in 0..C-1:
    if dfs(r, c, 0):
      return true
return false
```

**How it works**

From each starting match, DFS to next char; mark visited (temporarily), backtrack on failure.

* Time: up to $O(R\cdot C\cdot b^{L})$ (branching $b\in [3,4]$, word length $L$)
* Space: $O(L)$

Pruning: early letter mismatch; frequency precheck; prefix trie when searching many words.

#### Crossword-style Fill (Multiple Words)

Place words to slots with crossings; verify consistency at intersections.

**Mathematical formulation**

Let $S$ be the set of slots (across/down). Each slot $s\in S$ has a length $\ell(s)$ and ordered cell coordinates
$\mathrm{cells}(s) = \big((r_0,c_0),\ldots,(r_{\ell(s)-1},c_{\ell(s)-1})\big)$.
Let $D$ be the dictionary; define $D_\ell=\{w\in D:|w|=\ell\}$.
Known letters from the grid induce a pattern constraint $P_s\in(\Sigma\cup\{_\})^{\ell(s)}$.

Find an assignment $f:S\to D$ such that, for all $s\in S$,

$$
f(s)\in D_{\ell(s)}\quad\text{and}\quad
\forall i\ (P_s[i]\neq _ \Rightarrow f(s)[i]=P_s[i]),
$$

and for every intersection between slots $s$ at index $i$ and $t$ at index $j$,

$$
f(s)[i]=f(t)[j].
$$

(Optionally enforce all-different: $s\neq t \Rightarrow f(s)\neq f(t)$.)

**Pseudocode (backtracking with loops, MRV + trie filtering)**

```
# Preprocess
slots = extract_slots(grid)                  # with cells(s) and pattern P_s
trie = build_trie(dictionary)                # for prefix/length checks

# Build initial domains from patterns and lengths
domains = dict()
for s in slots:
  domains[s] = { w in dictionary | len(w) == len(s) and matches_pattern(w, P_s) }

# Order slots: Most-Restricted-Variable (smallest domain first)
slots.sort_by(|domains[s]| ascending, tiebreak by number_of_intersections)

used = set()          # if words must be unique
assignment = dict()

def consistent(s, w):
  # check crossings vs assigned neighbors
  for each intersection (s,i) with (t,j):
    if t in assignment and assignment[t][j] != w[i]:
      return false
  return true

def forward_check_update_domains(s, w, removed):
  # reduce neighbor domains by letter constraints from placing w at s
  for each intersection (s,i) with (t,j):
    for each v in copy(domains[t]):
      if v[j] != w[i]:
        domains[t].remove(v); removed.append((t, v))

def undo_forward_check(removed):
  for (t, v) in removed:
    domains[t].add(v)

def backtrack(idx):
  if idx == len(slots):
    return true

  s = slots[idx]

  # iterate candidates; optionally skip ones already used
  for w in iterate(domains[s]):
    if w in used: 
      continue
    if not consistent(s, w):
      continue

    assignment[s] = w
    used.add(w)
    removed = []
    forward_check_update_domains(s, w, removed)

    if backtrack(idx + 1):
      return true

    undo_forward_check(removed)
    used.remove(w)
    del assignment[s]

  return false

# Start search
if backtrack(0):
  return assignment  # filled crossword
else:
  return failure
```

**How it works**

Backtrack over slot assignments; use a trie for prefix feasibility; order by most constrained slot first.

* Time: exponential in slots; strong pruning and good heuristics important.


