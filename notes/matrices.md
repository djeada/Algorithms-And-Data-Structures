## Matrices and 2D Grids

Matrices represent images, game boards, and maps. Many classic problems reduce to transforming matrices, traversing them, or treating grids as graphs for search. This note mirrors the structure used in the Searching notes: each topic includes Example inputs and outputs, How it works, and a compact summary with $O(\cdot)$.

### Conventions

* Rows indexed 0..R−1, columns 0..C−1; cell (r, c).
* Neighborhoods: 4-dir Δ = {(-1,0),(1,0),(0,-1),(0,1)}, or 8-dir adds diagonals.

---

### Basic Operations (Building Blocks)

#### Transpose

Swap across the main diagonal: $A[r][c] \leftrightarrow A[c][r]$ (square). For non-square, result shape is $C\times R$.

**Example inputs and outputs**

*Example 1 (square)*

$$
	ext{Input: } A = \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\\7 & 8 & 9\end{bmatrix}
$$

$$
	ext{Output: } A^{T} = \begin{bmatrix}1 & 4 & 7\\2 & 5 & 8\\3 & 6 & 9\end{bmatrix}
$$

*Example 2 (rectangular)*

$$
	ext{Input: } A = \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\end{bmatrix}\ (2\times3)
$$

$$
	ext{Output: } A^{T} = \begin{bmatrix}1 & 4\\2 & 5\\3 & 6\end{bmatrix}\ (3\times2)
$$

**How it works**

Iterate pairs once and swap. For square matrices, can be in-place by visiting only $c>r$.

* Time: $O(R\cdot C)$; Space: $O(1)$ in-place (square), else $O(R\cdot C)$ to allocate.

#### Reverse Rows (Horizontal Flip)

Reverse each row left↔right.

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } \begin{bmatrix}3 & 2 & 1\\6 & 5 & 4\end{bmatrix}
$$

* Time: $O(R\cdot C)$; Space: $O(1)$.

#### Reverse Columns (Vertical Flip)

Reverse each column top↔bottom.

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\\7 & 8 & 9\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } \begin{bmatrix}7 & 8 & 9\\4 & 5 & 6\\1 & 2 & 3\end{bmatrix}
$$

* Time: $O(R\cdot C)$; Space: $O(1)$.

---

### Rotations (Composed from Basics)

Use transpose + reversals for square in-place rotations; rectangular rotations produce new shape $(R\times C)\to(C\times R)$.

#### 90° Clockwise (CW)

Transpose, then reverse each row.

**Example inputs and outputs**

*Example 1 (3×3)*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\\7 & 8 & 9\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } \begin{bmatrix}7 & 4 & 1\\8 & 5 & 2\\9 & 6 & 3\end{bmatrix}
$$

*Example 2 (2×3 → 3×2)*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } \begin{bmatrix}4 & 1\\5 & 2\\6 & 3\end{bmatrix}
$$

**How it works**

Transpose swaps axes; reversing each row aligns columns to rows of the rotated image.

* Time: $O(R\cdot C)$; Space: $O(1)$ in-place for square, else $O(R\cdot C)$ new.

#### 90° Counterclockwise (CCW)

Transpose, then reverse each column (or reverse rows, then transpose).

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\\7 & 8 & 9\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } \begin{bmatrix}3 & 6 & 9\\2 & 5 & 8\\1 & 4 & 7\end{bmatrix}
$$

**How it works**

Transpose, then flip vertically to complete the counterclockwise rotation.

* Time: $O(R\cdot C)$; Space: $O(1)$ (square) or $O(R\cdot C)$.

#### 180° Rotation

Equivalent to reversing rows, then reversing columns (or two 90° rotations).

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6\\7 & 8 & 9\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } \begin{bmatrix}9 & 8 & 7\\6 & 5 & 4\\3 & 2 & 1\end{bmatrix}
$$

**How it works**

Horizontal + vertical flips relocate each element to $(R-1-r,\ C-1-c)$.

* Time: $O(R\cdot C)$; Space: $O(1)$ (square) or $O(R\cdot C)$.

#### 270° Rotation

270° CW = 90° CCW; 270° CCW = 90° CW. Reuse the 90° procedures.

#### Layer-by-Layer (Square) 90° CW

Rotate each ring by cycling 4 positions.

**How it works**

For layer $\ell$ with bounds $[\ell..n-1-\ell]$, for each offset move:

```
top ← left, left ← bottom, bottom ← right, right ← top
```

* Time: $O(n^{2})$; Space: $O(1)$.

---

### Traversal Patterns

#### Spiral Order

Read outer layer, then shrink bounds.

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}1 & 2 & 3 & 4\\5 & 6 & 7 & 8\\9 & 10 & 11 & 12\end{bmatrix}
$$

$$
	ext{Output sequence: } 1,2,3,4,8,12,11,10,9,5,6,7
$$

**How it works**

Maintain top, bottom, left, right. Walk edges in order; after each edge, move the corresponding bound inward.

* Time: $O(R\cdot C)$; Space: $O(1)$ beyond output.

#### Diagonal Order (r+c layers)

Visit cells grouped by $s=r+c$; alternate direction per diagonal to keep locality if desired.

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}a & b & c\\d & e & f\end{bmatrix}
\quad\Rightarrow\quad
	ext{One order: } a, b,d, e,c, f
$$

* Time: $O(R\cdot C)$; Space: $O(1)$.

---

### Grids as Graphs

Each cell is a node; edges connect neighboring walkable cells.

#### BFS Shortest Path (Unweighted)

Find the minimum steps from S to T.

**Example inputs and outputs**

*Example*

$$
	ext{Grid (0=open, 1=wall), S=(0,0), T=(2,3)}\\
\begin{bmatrix}S & 0 & 1 & 0\\0 & 0 & 0 & 0\\1 & 1 & 0 & T\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: distance } = 5
$$

**How it works**

Push S to a queue, expand in 4-dir layers, track distance/visited; stop when T is dequeued.

* Time: $O(R\cdot C)$; Space: $O(R\cdot C)$.

#### Connected Components (Islands)

Count regions of ‘1’s via DFS/BFS.

**Example inputs and outputs**

*Example*

$$
	ext{Input: } \begin{bmatrix}1 & 1 & 0\\0 & 1 & 0\\0 & 0 & 1\end{bmatrix}
\quad\Rightarrow\quad
	ext{Output: } 2\ \text{islands}
$$

**How it works**

Scan cells; when an unvisited ‘1’ is found, flood it (DFS/BFS) to mark the whole island.

* Time: $O(R\cdot C)$; Space: $O(R\cdot C)$ worst-case.

---

### Backtracking on Grids

#### Word Search (Single Word)

Find a word by moving to adjacent cells (4-dir), using each cell once per path.

**Example inputs and outputs**

*Example*

$$
	ext{Board: } \begin{bmatrix}A & B & C & E\\S & F & C & S\\A & D & E & E\end{bmatrix},\ \text{Word: } "ABCCED"
\quad\Rightarrow\quad
	ext{Output: } \text{true}
$$

**How it works**

From each starting match, DFS to next char; mark visited (temporarily), backtrack on failure.

* Time: up to $O(R\cdot C\cdot b^{L})$ (branching $b\in[3,4]$, word length $L$); Space: $O(L)$.

Pruning: early letter mismatch; frequency precheck; prefix trie when searching many words.

#### Crossword-style Fill (Multiple Words)

Place words to slots with crossings; verify consistency at intersections.

**How it works**

Backtrack over slot assignments; use a trie for prefix feasibility; order by most constrained slot first.

* Time: exponential in slots; strong pruning and good heuristics are crucial.

---

### Summary of Complexities

* Full traversal: $O(R\cdot C)$ time; $O(1)$ space (no visited) or $O(R\cdot C)$ with visited.
* Rotations/transpose: $O(R\cdot C)$ time; $O(1)$ in-place (square) or $O(R\cdot C)$ extra.
* BFS/DFS on grids: $O(R\cdot C)$ time; $O(R\cdot C)$ space.
* Word search backtracking: up to $O(R\cdot C\cdot b^{L})$ time; $O(L)$ space.

