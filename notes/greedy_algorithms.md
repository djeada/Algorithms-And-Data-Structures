## Greedy algorithms

**Table of Contents**
1. [What Is Greedy?](#what-is-greedy)
2. [The Greedy Proof Toolkit](#the-greedy-proof-toolkit)
3. [Examples Grouped by Pattern](#examples-grouped-by-pattern)
   - [Frontier/Reachability Greedy: Jump Game](#reachability-on-a-line)
   - [Cut-Based Greedy on Graphs: MST and Dijkstra](#minimum-spanning-trees)
   - [Scheduling Greedy: Interval Scheduling and EDD Lateness](#scheduling-themes)
   - [Merge-the-Two-Smallest Greedy: Huffman Coding](#huffman-coding)
   - [Discard-Negative-Prefix Greedy: Maximum Subarray](#maximum-contiguous-sum)
4. [When Greedy Is Guaranteed: Matroids](#when-greedy-is-guaranteed-matroids)
5. [Common Failure Modes](#common-failure-modes)

---

### What Is Greedy?

Greedy algorithms build a solution one step at a time. At each step, grab the option that looks best *right now* by some simple rule (highest value, earliest finish, shortest length, etc.). Keep it if it doesn't break the rules of the problem.

**The general pattern:**

1. Sort by your rule (the "key").
2. Scan items in that order.
3. If adding this item keeps the partial answer valid, keep it.
4. Otherwise skip it.

Picking the best "now" doesn't obviously give the best "overall." **Greedy isn't magic; you must prove the choice is safe.** The real work is showing that these local choices still lead to a globally best answer.

---

### The Greedy Proof Toolkit

This section provides reusable proof templates you'll apply to every greedy algorithm. Master these patterns once, and you can tackle any greedy problem.

#### The Universal Greedy Checklist

For every greedy algorithm, answer these five questions:

1. **Greedy choice**: What local choice do we make at each step?
2. **Feasibility**: What constraint must always remain true? (the invariant)
3. **Why safe**: Why does this choice never hurt optimality?
4. **Implementation**: What data structure makes the choice fast?
5. **Complexity**: What dominates runtime?

#### Exchange Argument Template

The exchange argument is the workhorse of greedy correctness proofs. Here's the four-line generic template:

1. Take any optimal solution **OPT** that disagrees with greedy **G** at the first position.
2. Show you can "swap in" the greedy choice at that position without making the solution worse or breaking feasibility.
3. The modified solution is still optimal and now agrees with greedy for one more position.
4. Repeat this process: eventually **OPT** transforms into **G**, proving greedy is optimal.

*Picture it like this:*

```
position →   0    1    2    3    4
greedy:     [✓]  [✗]  [✓]  [✓]  [✗]
some optimal:
             ✓    ✓    ✗    ?    ?
First mismatch at position 2 → swap in greedy's pick without harm.
Repeat until both rows match → greedy is optimal.
```

#### Loop Invariant Template

An alternative proof strategy uses loop invariants. The template has four parts:

1. **State the invariant**: A sentence that's true after every iteration (e.g., "the current set is feasible and at least as good as any other feasible set built from the items processed so far").
2. **Initialization**: Prove the invariant holds before the first iteration.
3. **Maintenance**: Prove that if the invariant holds before an iteration, it remains true afterward.
4. **Termination**: Show that when the loop ends, the invariant implies the solution is optimal.

#### Cut and Cycle Rules (Graph Specializations)

For graph problems, exchange arguments often take specialized forms:

* **Cut rule (safe to add)**: For any partition of vertices into two sets, the cheapest edge crossing that partition can safely be included in an optimal solution. This underlies MST algorithms and Dijkstra's shortest paths.
* **Cycle rule (safe to skip)**: In any cycle, the most expensive edge is never in a minimum spanning tree. You can always remove it and remain connected with lower cost.

These rules are just exchange arguments dressed in graph-theoretic language. The cut rule says "swapping in the cheapest crossing edge cannot hurt," and the cycle rule says "removing the heaviest edge in a cycle cannot hurt."

---

### Examples Grouped by Pattern

The following examples demonstrate different greedy patterns. Each section follows a standard structure: **Problem → Greedy rule → Algorithm → Proof sketch → Complexity → Edge cases**.


### Reachability on a line

**Pattern**: Frontier/Reachability Greedy

**Problem**

- You stand at square 0 on squares $0, 1, \ldots, n-1$.
- Each square $i$ has a jump power $a[i]$. From $i$ you may land on any of $i+1, i+2, \dots, i+a[i]$.
- Goal: decide if you can reach $n-1$; if not, report the furthest reachable square.

**Example**

Input: $a = [3, 1, 0, 0, 4, 1]$, so $n = 6$ (squares $0$ through $5$).

```
indices:  0   1   2   3   4   5
a[i]   :  3   1   0   0   4   1
reach  :  ^ start at 0
```

From any $i$, the allowed landings are a range:

```
i=0 (a[0]=3): 1..3
i=1 (a[1]=1): 2
i=2 (a[2]=0): —
i=3 (a[3]=0): —
i=4 (a[4]=4): 5..8 (board ends at 5)
```

**Baseline idea**

"Paint everything reachable, one wave at a time."

1. Start with $\{0\}$ reachable.
2. For each already-reachable $i$, add all $i+1 \ldots i+a[i]$.
3. Stop when nothing new appears.

*Walkthrough:*

```
start:   reachable = {0}
from 0:  add {1,2,3}     → reachable = {0,1,2,3}
from 1:  add {2}         → no change
from 2:  add {}          → a[2]=0
from 3:  add {}          → a[3]=0
stop:    no new squares  → furthest = 3; last (5) unreachable
```

Correct, but can reprocess many squares.

**Greedy rule**

Carry one number while scanning left→right: the furthest frontier $F$ seen so far.

Rules:

* If you are at $i$ with $i > F$, you hit a gap → stuck forever.
* Otherwise, extend $F \leftarrow \max(F, i + a[i])$ and continue.

At the end:

* Can reach last iff $F \ge n - 1$.
* Furthest reachable square is $F$ (capped by $n - 1$).

**Algorithm**

*Pseudocode*

```
F = 0
for i in 0..n-1:
    if i > F: break
    F = max(F, i + a[i])

can_reach_last = (F >= n-1)
furthest = min(F, n-1)
```

**Proof sketch** 

The loop invariant is: "$F$ always equals the best jump end discovered from any truly-reachable square $\le i$." This is maintained because:

* Initially $F = 0$ (we start at position 0).
* If $i \le F$, then position $i$ is reachable, so we can update $F$ with $i + a[i]$.
* If $i > F$, no earlier jump can help because all such jumps were already folded into $F$.

Since $F$ never decreases and captures all reachable positions up to $i$, when the loop ends we have the correct furthest reachable position.

**Greedy checklist application:**

1. **Greedy choice**: At each position $i$, extend the frontier as far as possible using $a[i]$.
2. **Feasibility**: The invariant "$F$ = furthest reachable so far" is always true.
3. **Why safe**: Any position beyond $F$ is unreachable, so stopping at $i > F$ is correct. Extending $F$ greedily captures all possibilities from reachable positions.
4. **Implementation**: Single pass with $O(1)$ state.
5. **Complexity**: $O(n)$ time, $O(1)$ space.

**Walkthrough:**

We draw the frontier as a bracket reaching to $F$.

Step $i = 0$ (inside frontier since $0 \le F$); update $F = \max(0, 0 + 3) = 3$.

```
indices:  0   1   2   3   4   5
          [===============F]
          0   1   2   3
F=3
```

Step $i = 1$: still $i \le F$. Update $F = \max(3, 1 + 1) = 3$ (no change).
Step $i = 2$: $F = \max(3, 2 + 0) = 3$ (no change).
Step $i = 3$: $F = \max(3, 3 + 0) = 3$ (no change).

Now $i = 4$ but $4 > F(= 3)$ → gap → stuck.

```
indices:  0   1   2   3   4   5
          [===============F]   x  (i=4 is outside)
F=3
```

Final: $F = 3$. Since $F < n - 1 = 5$, last is unreachable; furthest reachable square is $3$.

**Complexity**

* Time: $O(n)$
* Space: $O(1)$

**Edge cases**

* If all $a[i] = 0$ except $a[0]$, you can only reach as far as $a[0]$.
* If $n = 1$, you're already at the goal.


### Minimum spanning trees

**Pattern**: Cut-Based Greedy on Graphs

**Problem**

You've got a **connected, undirected, weighted** graph and you want the cheapest way to connect **all** its vertices without any cycles—that's a minimum spanning tree (MST). Think "one network of cables that touches every building, with the total cost as small as possible."

**Example inputs and outputs**

```
V = {A,B,C,D,E}

Edges (u-v:w):
A-B:1  A-C:5  A-E:9
B-C:4  B-D:2  B-E:7
C-D:6  C-E:3
D-E:8
```

A correct MST for this graph is:

$$
\{A \!-\! B(1), B \!-\! D(2), C \!-\! E(3), B \!-\! C(4)\}
$$

Total weight $= 1 + 2 + 3 + 4 = 10$.

You can't do better: any cheaper set of 4 edges would either miss a vertex or create a cycle.

**Baseline**

Enumerate every spanning tree and pick the one with the smallest total weight. That's conceptually simple—"try all combinations of $n - 1$ edges that connect everything and have no cycles"—but it explodes combinatorially. Even medium graphs have an astronomical number of spanning trees, so this approach is only good as a thought experiment.

**How it works**

Both fast methods rely on two facts:

* **Cut rule (safe to add)** - for any cut $(S, V \setminus S)$, the cheapest edge that crosses the cut appears in some MST. Intuition: if your current partial connection is on one side, the cheapest bridge to the other side is never a bad idea.
* **Cycle rule (safe to skip)** - in any cycle, the most expensive edge is never in an MST. Intuition: if you already have a loop, drop the priciest link and you'll still be connected but strictly cheaper.

#### Kruskal's method

**Example inputs and outputs**

Use the same graph as above. A valid MST is

$$
\{A\!-\!B(1), B\!-\!D(2), C\!-\!E(3), B\!-\!C(4)\} \quad\Rightarrow\quad \text{total} = 10
$$

**Greedy rule**

Sort edges from lightest to heaviest; walk down that list and keep an edge if it connects two **different** components. Stop when you have $n - 1$ edges.

**Algorithm**

Sorted edges by weight:

```
1: A-B
2: B-D
3: C-E
4: B-C
5: A-C
6: C-D
7: B-E
8: D-E
9: A-E
```

We'll keep a running view of the components; initially each vertex is alone.

```
start:   {A} {B} {C} {D} {E}

take 1:  A-B(1)   → {AB} {C} {D} {E}
take 2:  B-D(2)   → {ABD} {C} {E}
take 3:  C-E(3)   → {ABD} {CE}
take 4:  B-C(4)   → {ABCDE}   ← all connected (|V|-1 edges) → stop

kept: A-B(1), B-D(2), C-E(3), B-C(4)  → total = 10
```

- Edges kept: $A\!-\!B(1), B\!-\!D(2), C\!-\!E(3), B\!-\!C(4)$.
- Total $= 10$. Every later edge would create a cycle and is skipped by the cycle rule.

**Kruskal pseudocode**

```python
MST = ∅
make_set(v) for v in V
for (w,u,v) in edges sorted by w:
    if find(u) != find(v):
        MST.add((u,v,w))
        union(u,v)
        if |MST| == |V|-1: break
```

**Proof sketch**

The greedy choice is always the lightest edge that doesn't create a cycle. By the cycle rule, any edge that would create a cycle is safe to skip. By the cut rule, the lightest edge connecting two components is always safe to include. An exchange argument shows that any optimal MST can be transformed to match Kruskal's choices without increasing cost.

**Greedy checklist application:**

1. **Greedy choice**: Always pick the lightest available edge that doesn't create a cycle.
2. **Feasibility**: No cycles; remains a forest throughout.
3. **Why safe**: Cycle rule (skip heavy edges in cycles) + cut rule (include light crossing edges).
4. **Implementation**: Disjoint-set (union-find) data structure for cycle detection.
5. **Complexity**: $O(E \log E)$ dominated by sorting.

**Complexity**

* Time: $O(E \log E)$ to sort edges + near-constant $\alpha(V)$ for DSU unions; often written $O(E \log V)$ since $E \le V^2$.
* Space: $O(V)$ for disjoint-set structure.

**Edge cases**

* If the graph is disconnected, Kruskal produces a minimum spanning forest (one tree per component).
* Ties in edge weights can be broken arbitrarily; all produce an MST of the same total weight.

#### Prim's method

**Example inputs and outputs**

Same graph and target: produce any MST of total weight $10$.

**Greedy rule**

Start from any vertex; repeatedly add the lightest edge that leaves the current tree to bring in a new vertex. Stop when all vertices are in.

**Algorithm**

Let's start from $A$. The "tree" grows one cheapest boundary edge at a time.

```
step 0:
Tree = {A}
Boundary = { A-B(1), A-C(5), A-E(9) }

take A-B(1)
Tree = {A,B}
Boundary = { B-D(2), B-C(4), B-E(7), A-C(5), A-E(9) }

take B-D(2)
Tree = {A,B,D}
Boundary = { B-C(4), A-C(5), D-C(6), B-E(7), D-E(8), A-E(9) }

take B-C(4)
Tree = {A,B,C,D}
Boundary = { C-E(3), A-E(9), B-E(7), D-E(8) }

take C-E(3)
Tree = {A,B,C,D,E}  → done

kept: A-B(1), B-D(2), B-C(4), C-E(3) → total = 10
```

Edges chosen: exactly the same four as Kruskal, total $= 10$.

Why did step 4 grab a weight-3 edge after we already took a 4? Because earlier that 3 wasn't **available**—it didn't cross from the tree to the outside until $C$ joined the tree. Prim never regrets earlier picks because of the cut rule: at each moment it adds the cheapest bridge from "inside" to "outside," and that's always safe.

**Prim pseudocode (binary heap)**

```python
pick any root r
Tree = {r}
push all edges (r→v,w) into heap
while |Tree| < |V|:
    pop (w,u→v) with minimum w where v ∉ Tree
    add v to Tree; record edge (u,v,w) in MST
    push all edges (v→x,wvx) with x ∉ Tree
```

**Proof sketch**

At each step, Prim's algorithm chooses the lightest edge crossing the cut between the current tree and the rest of the graph. By the cut rule, this edge must be in some MST. An exchange argument shows that any optimal MST can be transformed to use Prim's choices.

**Greedy checklist application:**

1. **Greedy choice**: Always add the lightest edge leaving the current tree.
2. **Feasibility**: Tree property maintained (no cycles, connected).
3. **Why safe**: Cut rule—lightest crossing edge is always in some MST.
4. **Implementation**: Min-heap (priority queue) for boundary edges; track visited vertices.
5. **Complexity**: $O(E \log V)$ with binary heap.

**Complexity**

* Time: $O(E \log V)$ with a binary heap and adjacency lists; $O(E + V \log V)$ with a Fibonacci heap.
* Space: $O(V)$ for keys/parents and visited set.

**Edge cases**

* Choice of starting vertex doesn't matter; all produce an MST of the same weight.
* The heap may contain stale entries (edges to already-visited vertices); skip them when popped.


### Shortest paths with non-negative weights (Dijkstra)

**Pattern**: Cut-Based Greedy on Graphs

**Problem**

Goal: from start $s$, compute cheapest costs $d(\cdot)$ to every node (and routes if you keep parents).

**Non-negative edges only**; that's what makes the greedy step safe. The graph can be either **directed or undirected**.

**Example**

```
Nodes: A B C D E   (start s=A)

Edges (undirected, non-negative weights):
A-B:2  A-C:5
B-C:1  B-D:2  B-E:7
C-D:3  C-E:1
D-E:2
```

Correct answers from A: $d(A) = 0, d(B) = 2, d(C) = 3, d(D) = 4, d(E) = 4$.

**Baseline** 

Repeat relaxations $|V| - 1$ rounds (Bellman–Ford-style).

Work $\approx |V| \cdot |E|$. Handles negatives; we don't need that here.

**Greedy rule: "settle the smallest label"**

At each step, among all unsettled nodes, pick the one with the smallest tentative distance and **settle** it (mark its distance as final). This is safe because with non-negative weights, any path through unsettled nodes to reach this node would be at least as long.

**Algorithm**

1. Initialize distance labels: set $d(s) = 0$, and $d(x) = \infty$ for all other nodes.
2. Initialize parent pointers $\pi(\cdot)$.
3. Initialize the settled set $S = \emptyset$.
4. Initialize the unsettled set as $V \setminus S$.
5. Select the unsettled node $u$ with the smallest distance label $d(u)$.
6. Move node $u$ from the unsettled set into the settled set.
7. Update each neighbor $v$ of $u$ by assigning $d(v) \leftarrow \min\bigl(d(v), d(u) + w(u, v)\bigr)$.
8. If the update in step 7 improves $d(v)$, then set $\pi(v) \leftarrow u$.
9. Repeat from step 5 until all nodes are settled or no reachable unsettled nodes remain.

**Proof sketch (Justification of correctness)**

With non-negative edge weights, any path reaching an unsettled node must have length at least $d(u)$ plus a non-negative exit edge. Therefore, the chosen $d(u)$ is final and cannot later be decreased. This is the core greedy property: settling the node with the smallest label is always safe.

The loop invariant is: "All settled nodes have their correct shortest-path distances." This holds because:

* **Initialization**: $d(s) = 0$ is correct.
* **Maintenance**: When we settle $u$, $d(u)$ is minimal among unsettled nodes. Any alternative path to $u$ would go through another unsettled node with distance $\ge d(u)$, plus non-negative edges, so it cannot be shorter.
* **Termination**: When all reachable nodes are settled, all have correct distances.

**Greedy checklist application:**

1. **Greedy choice**: Always settle the unsettled node with smallest tentative distance.
2. **Feasibility**: All settled nodes have correct final distances (invariant).
3. **Why safe**: Non-negative weights ensure no future discovery can improve a settled node's distance.
4. **Implementation**: Min-heap (priority queue) for unsettled nodes with their distances.
5. **Complexity**: $O((V + E) \log V)$ with binary heap.

**Pseudocode (binary heap)**

```
for v in V: d[v]=∞; π[v]=nil
d[s]=0
push (0,s) into min-heap H
S = ∅
while H not empty:
    (du,u) = pop-min(H)
    if u in S: continue         # ignore stale heap entries
    S.add(u)
    for (u,v,w) in adj[u]:
        if d[v] > d[u] + w:
            d[v] = d[u] + w
            π[v] = u
            push (d[v], v) into H
```

Time $O((|V| + |E|) \log |V|)$; space $O(|V|)$.

**Walkthrough**

Legend: "S" = settled, "$\pi[x]$" = parent of $x$. Ties break arbitrarily.

Round 0 (init)

```
S = ∅
d:  A:0  B:∞  C:∞  D:∞  E:∞
π:  A:-  B:-  C:-  D:-  E:-
```

Round 1 — pick min unsettled → A(0); relax neighbors

```
S = {A}
relax A-B (2):  d[B]=2  π[B]=A
relax A-C (5):  d[C]=5  π[C]=A
d:  A:0S  B:2  C:5  D:∞  E:∞
π:  A:-   B:A  C:A  D:-  E:-
```

Round 2 — pick B(2); relax

```
S = {A,B}
B→C (1): 2+1=3 <5 → d[C]=3  π[C]=B
B→D (2): 2+2=4     → d[D]=4  π[D]=B
B→E (7): 2+7=9     → d[E]=9  π[E]=B
d:  A:0S  B:2S  C:3  D:4  E:9
π:  A:-   B:A   C:B  D:B  E:B
```

Round 3 — pick C(3); relax

```
S = {A,B,C}
C→D (3): 3+3=6  (no improv; keep 4)
C→E (1): 3+1=4 <9 → d[E]=4  π[E]=C
d:  A:0S  B:2S  C:3S  D:4  E:4
π:  A:-   B:A   C:B   D:B  E:C
```

Round 4 — pick D(4); relax

```
S = {A,B,C,D}
D→E (2): 4+2=6 (no improv; keep 4)
d:  A:0S  B:2S  C:3S  D:4S  E:4
```

Round 5 — pick E(4); done

```
S = {A,B,C,D,E}  (all settled)
Final d: A:0  B:2  C:3  D:4  E:4
Parents π: B←A, C←B, D←B, E←C
```

Reconstruct routes by following parents backward:

* $B$: $A \to B$
* $C$: $A \to B \to C$
* $D$: $A \to B \to D$
* $E$: $A \to B \to C \to E$

**Complexity**

* Time: $O((V + E) \log V)$ with a binary heap (often written $O(E \log V)$ when $E \ge V$).
* Space: $O(V)$ for distances, parent pointers, and heap entries.

**Edge cases**

* If a node is unreachable from $s$, its distance remains $\infty$.
* The heap may contain stale entries (outdated distance labels); we skip them by checking if the node is already settled.
* Works on both directed and undirected graphs, as long as all edge weights are non-negative.


### Scheduling themes

**Pattern**: Scheduling Greedy

Two classics:

- Pick as many non-overlapping intervals as possible (one room, max meetings).
- Keep maximum lateness small when jobs have deadlines.

They're both greedy—and both easy to run by hand.

#### Interval scheduling (maximum cardinality)

**Problem**

Imagine you have time intervals on a single line, and you can keep an interval only if it doesn't overlap anything you already kept. The aim is to keep as many as possible.

**Example inputs and outputs**

Intervals (start, finish):

```
(1,3) (2,5) (4,7) (6,9) (8,10) (9,11)
```

A best answer keeps **three** intervals, for instance $(1,3), (4,7), (8,10)$.

Note: With the given input set, the maximum number of non-overlapping intervals is 3, not 4. If we had an additional interval like $(10,11)$ in the input, we could keep four intervals: $(1,3), (4,7), (8,10), (10,11)$.

**Baseline (slow)**

Try all subsets and keep the largest that has no overlaps. That's conceptually simple and always correct, but it's exponential in the number of intervals, which is a non-starter for anything but tiny inputs.

**Greedy rule**

Sort by finish time and take what fits.

- Scan from earliest finisher to latest.
- Keep $(s, e)$ iff $s \ge \text{last end}$; then set $\text{last end} \leftarrow e$.

**Algorithm**

Sorted by finish:

$$
(1,3), (2,5), (4,7), (6,9), (8,10), (9,11)
$$

Run the scan and track the end of the last kept interval.

```
last_end = -∞
(1,3):  1 ≥ -∞ → keep → last_end = 3
(2,5):  2 < 3  → skip
(4,7):  4 ≥ 3  → keep → last_end = 7
(6,9):  6 < 7  → skip
(8,10): 8 ≥ 7  → keep → last_end = 10
(9,11): 9 < 10 → skip
```

Kept intervals: $(1,3), (4,7), (8,10)$. That's 3 intervals, which is optimal for this input.

A tiny picture helps the "finish early" idea feel natural:

```
time →
kept:  [1────3) [4─────7)  [8────10)
skip:      [2────5)  [6──────9)[9─────11)
ending earlier leaves more open space to the right
```

**Proof sketch**

At the first place an optimal schedule would choose a later-finishing interval, swapping in the earlier finisher cannot reduce what still fits afterward (the earlier finisher ends sooner or at the same time, leaving at least as much room for future intervals). An exchange argument shows you can push any optimal schedule to match greedy without losing size.

**Greedy checklist application:**

1. **Greedy choice**: Always pick the interval with the earliest finish time among those that don't overlap kept intervals.
2. **Feasibility**: No two kept intervals overlap.
3. **Why safe**: Exchange argument—replacing a later-finishing interval with an earlier-finishing one never reduces future opportunities.
4. **Implementation**: Sort intervals by finish time; single scan with $O(1)$ state.
5. **Complexity**: $O(n \log n)$ sorting + $O(n)$ scan.

**Handy pseudocode**

```python
# Interval scheduling (max cardinality)
sort intervals by end time
last_end = -∞
keep = []
for (s,e) in intervals:
    if s >= last_end:
        keep.append((s,e))
        last_end = e
```

**Complexity**

* Time: $O(n \log n)$ to sort by finishing time; $O(n)$ scan.
* Space: $O(1)$ (beyond input storage).

**Edge cases**

* If all intervals overlap at a single point, only one can be kept.
* Intervals with the same finish time can be processed in any order among themselves.

#### Minimize the maximum lateness

**Problem**

Now think of $n$ jobs, all taking the same amount of time (say one unit). Each job $i$ has a deadline $d_i$. When you run them in some order, the completion time of the $k$-th job is $C_k = k$ (since each takes one unit), and its lateness is

$$
L_i = C_i - d_i.
$$

Negative values mean you finished early; the quantity to control is the worst lateness $L_{\max} = \max_i L_i$. The goal is to order the jobs so $L_{\max}$ is as small as possible.

**Example inputs and outputs**

Jobs and deadlines:

* $J_1: d_1 = 3$
* $J_2: d_2 = 1$
* $J_3: d_3 = 4$
* $J_4: d_4 = 2$

An optimal schedule is $J_2, J_4, J_1, J_3$. The maximum lateness there is $0$.

**Baseline (slow)**

Try all $n!$ orders, compute every job's completion time and lateness, and take the order with the smallest $L_{\max}$. This explodes even for modest $n$.

**Greedy rule**

Order jobs by nondecreasing deadlines (earliest due date first, often called EDD). Fixing any "inversion" where a later deadline comes before an earlier one can only help the maximum lateness, so sorting by deadlines is safe.

**Algorithm**

Deadlines in increasing order:

$$
J_2(d = 1), J_4(d = 2), J_1(d = 3), J_3(d = 4)
$$

Run them one by one and compute completion times and lateness.

```
slot 1: J2 finishes at C=1 → L2 = 1 - d2(=1) = 0
slot 2: J4 finishes at C=2 → L4 = 2 - d4(=2) = 0
slot 3: J1 finishes at C=3 → L1 = 3 - d1(=3) = 0
slot 4: J3 finishes at C=4 → L3 = 4 - d3(=4) = 0
L_max = 0
```

If you scramble the order, the worst lateness jumps. For example, $J_1, J_2, J_3, J_4$ gives

```
slot 1: J1 → L1 = 1 - 3 = -2
slot 2: J2 → L2 = 2 - 1 = 1
slot 3: J3 → L3 = 3 - 4 = -1
slot 4: J4 → L4 = 4 - 2 = 2
L_max = 2   (worse)
```

A quick timeline sketch shows how EDD keeps you out of trouble:

```
time → 1   2   3   4
EDD:   [J2][J4][J1][J3]   deadlines: 1   2   3   4
late?    0    0    0    0  → max lateness 0
```

**Proof sketch**

If two adjacent jobs are out of deadline order (later deadline comes first), swapping them never increases any completion time relative to its own deadline. In fact, it strictly improves the lateness of the earlier-deadline job. An exchange argument shows that repeatedly fixing these inversions leads to the sorted-by-deadline order with no worse maximum lateness. Therefore, EDD is optimal.

**Greedy checklist application:**

1. **Greedy choice**: Process jobs in order of increasing deadline.
2. **Feasibility**: All jobs are completed; order determines completion times.
3. **Why safe**: Exchange argument—swapping adjacent out-of-order jobs never increases $L_{\max}$.
4. **Implementation**: Sort jobs by deadline; scan and compute lateness.
5. **Complexity**: $O(n \log n)$ sorting + $O(n)$ evaluation.

**Pseudocode**

```
# Minimize L_max (EDD)
sort jobs by increasing deadline d_j
t = 0; Lmax = -∞
for job j in order:
    t += p_j           # completion time C_j
    L = t - d_j
    Lmax = max(Lmax, L)
return order, Lmax
```

**Complexity**

* Time: $O(n \log n)$ to sort by deadlines; $O(n)$ evaluation.
* Space: $O(1)$.

**Edge cases**

* If all jobs have the same deadline, any order gives the same $L_{\max}$.
* If jobs have different processing times $p_j$, the problem becomes more complex (weighted EDD or other scheduling algorithms may be needed).


### Huffman coding

**Pattern**: Merge-the-Two-Smallest Greedy

**Problem**

You have symbols that occur with known frequencies $f_i > 0$ and $\sum_i f_i = 1$ (if you start with counts, first normalize by their total). The goal is to assign each symbol a binary codeword so that no codeword is a prefix of another (a **prefix code**, i.e., uniquely decodable without separators), and the average length

$$
\mathbb{E}[L] = \sum_i f_i L_i
$$

is as small as possible. Prefix codes correspond exactly to **full binary trees** (every internal node has two children) whose leaves are the symbols and whose leaf depths equal the codeword lengths $L_i$. The **Kraft inequality** $\sum_i 2^{-L_i} \le 1$ characterizes feasibility; equality holds for full trees (so an optimal prefix code "fills" the inequality).

**Example inputs and outputs**

Frequencies:

$$
A:0.40, \quad B:0.20, \quad C:0.20, \quad D:0.10, \quad E:0.10.
$$

A valid optimal answer will be a prefix code with expected length as small as possible. We will compute the exact minimum and one optimal set of lengths $L_A, \ldots, L_E$, plus a concrete codebook.

**Baseline**

One conceptual baseline is to enumerate all full binary trees with five labeled leaves and pick the one minimizing $\sum_i f_i L_i$. That is correct but explodes combinatorially as the number of symbols grows. A simpler but usually suboptimal baseline is to give every symbol the same length $\lceil \log_2 5 \rceil = 3$. That fixed-length code has $\mathbb{E}[L] = 3$.

**Greedy rule**

Huffman's rule repeats one tiny step: always merge the two least frequent items. When you merge two "symbols" with weights $p$ and $q$, you create a parent of weight $p + q$. 

**Why does this change the objective by exactly $p + q$?** Every leaf in those two subtrees increases its depth (and thus its code length) by $1$, so the total increase in $\sum_i f_i L_i$ is $\sum_{\ell \in \text{subtrees}} f_\ell \cdot 1 = (p + q)$ by definition of $p$ and $q$. Summing over all merges yields the final cost:

$$
\mathbb{E}[L] = \sum_{\text{merges}} (p + q) = \sum_{\text{internal nodes}} \text{weight}.
$$

**Algorithm**

**Why is the greedy choice optimal?** In an optimal tree the two deepest leaves must be siblings; if not, pairing them to be siblings never increases any other depth and strictly reduces cost whenever a heavier symbol is deeper than a lighter one (an **exchange argument**: swapping depths changes the cost by $f_{\text{heavy}} - f_{\text{light}} > 0$ in our favor when we move the lighter symbol deeper). Collapsing those siblings into a single pseudo-symbol reduces the problem size without changing optimality, so induction finishes the proof. (Ties can be broken arbitrarily; all tie-breaks achieve the same minimum $\mathbb{E}[L]$.)

Start with the multiset $\{0.40, 0.20, 0.20, 0.10, 0.10\}$. At each line, merge the two smallest weights and add their sum to the running cost.

```
1) merge 0.10 + 0.10 → 0.20        cost += 0.20   (total 0.20)
   multiset becomes {0.20, 0.20, 0.20, 0.40}

2) merge 0.20 + 0.20 → 0.40        cost += 0.40   (total 0.60)
   multiset becomes {0.20, 0.40, 0.40}

3) merge 0.20 + 0.40 → 0.60        cost += 0.60   (total 1.20)
   multiset becomes {0.40, 0.60}

4) merge 0.40 + 0.60 → 1.00        cost += 1.00   (total 2.20)
   multiset becomes {1.00}  (done)
```

So the optimal expected length is $\boxed{\mathbb{E}[L] = 2.20}$ bits per symbol. This already beats the naive fixed-length baseline $3$. It also matches the information-theoretic bound $H(f) \le \mathbb{E}[L] < H(f) + 1$ (where $H(f)$ is the Shannon entropy), since the entropy here is $H \approx 2.1219$.

Now assign actual lengths. Record who merged with whom:

* Step 1 merges $D(0.10)$ and $E(0.10)$ → those two become siblings.
* Step 2 merges $B(0.20)$ and $C(0.20)$ → those two become siblings.
* Step 3 merges the pair $D\!E(0.20)$ with $A(0.40)$ — wait, that's not quite right. Let me redo this carefully.

Actually, in step 3, we merge one of the 0.20 nodes (say the pair $D\!E$) with the standalone 0.20 node. Let's be more careful:

* Step 1: merge $D(0.10)$ and $E(0.10)$ → create node $DE(0.20)$.
* Step 2: merge $B(0.20)$ and $C(0.20)$ → create node $BC(0.40)$.
* Step 3: merge $DE(0.20)$ and $A(0.40)$ → create node $DEA(0.60)$.
* Step 4: merge $DEA(0.60)$ and $BC(0.40)$ → create root $(1.00)$.

Depths follow directly (each merge adds one level to its members):

$$
L_A = 2, \quad L_B = L_C = 2, \quad L_D = L_E = 3.
$$

Check the Kraft sum $3 \cdot 2^{-2} + 2 \cdot 2^{-3} = 3/4 + 1/4 = 1$ and the cost $0.4 \cdot 2 + 0.2 \cdot 2 + 0.2 \cdot 2 + 0.1 \cdot 3 + 0.1 \cdot 3 = 2.2$.

A tidy tree (weights shown for clarity):

```
[1.00]
+--0--> [0.60]
|       +--0--> A(0.40)
|       `--1--> [0.20]
|                +--0--> D(0.10)
|                `--1--> E(0.10)
`--1--> [0.40]
        +--0--> B(0.20)
        `--1--> C(0.20)
```

One concrete codebook arises by reading left edges as 0 and right edges as 1 (the left/right choice is arbitrary; flipping all bits in a subtree yields an equivalent optimal code):

* $A \mapsto 00$
* $B \mapsto 10$
* $C \mapsto 11$
* $D \mapsto 010$
* $E \mapsto 011$

You can verify the prefix property immediately and recompute $\mathbb{E}[L]$ from these lengths to get $2.20$ again. (From these lengths you can also construct the **canonical Huffman code**, which orders codewords lexicographically—useful for compactly storing the codebook.)

**Proof sketch**

The greedy choice is to always merge the two least frequent symbols/subtrees. An exchange argument shows that in any optimal tree, the two least frequent symbols must be siblings at the deepest level (otherwise we could improve the tree by swapping a deeper heavy symbol with a shallower light symbol). Inductively, collapsing these siblings and repeating maintains optimality.

**Greedy checklist application:**

1. **Greedy choice**: Always merge the two items with smallest frequency.
2. **Feasibility**: Construct a valid full binary tree (prefix code).
3. **Why safe**: Exchange argument—lighter symbols should be deeper; pairing the two lightest is always optimal.
4. **Implementation**: Min-heap for frequencies; $k-1$ merge operations for $k$ symbols.
5. **Complexity**: $O(k \log k)$ time.

**Complexity**

* Time: $O(k \log k)$ using a min-heap over $k$ symbol frequencies (each of the $k - 1$ merges performs two extractions and one insertion).
* Space: $O(k)$ for the heap and $O(k)$ for the resulting tree (plus $O(k)$ for an optional map from symbols to codewords).

**Edge cases**

* There can be multiple optimal codebooks when there are ties in frequencies. The expected length $\mathbb{E}[L]$ is always the same, but specific codeword assignments (especially among equal-frequency symbols) may differ. So we say: "Expected length is the same; codeword/leaf assignments may differ (especially among equal-frequency symbols)."
* For two symbols, optimal code lengths are both 1 (one bit each).


### Maximum contiguous sum

**Pattern**: Discard-Negative-Prefix Greedy

**Problem**

You're given a list of numbers laid out in a line (indexed from 0). You may pick one **contiguous** block, and you want that block's sum to be as large as possible.

**This is greedy in the sense that any negative-running prefix is never worth keeping, so we discard it immediately.** This is commonly taught as Kadane's algorithm or as a DP problem, but it has a clear greedy interpretation.

**Example inputs and outputs**

```
x = [ 2, -3, 4, -1, 2, -5, 3 ]
indices: 0   1  2   3  4   5  6
best block = [ 4, -1, 2 ]  → sum = 5
```

So the correct output is "maximum sum $= 5$" and one optimal segment is positions $2$ through $4$ (0-based indexing).

**Baseline**

Try every possible block and keep the best total. To sum any block $i \ldots j$ quickly, precompute **prefix sums** $S_0 = 0$ and $S_j = \sum_{k=0}^{j-1} x[k]$ (0-based). Then

$$
\sum_{k=i}^{j} x[k] = S_{j+1} - S_i
$$

Loop over all $j$ and all $i \le j$, compute the sum, and take the maximum. This is easy to reason about and always correct, but it does $O(n^2)$ block checks.

**Greedy rule**

Walk left to right once and carry two simple numbers.

* $S$: the running prefix sum up to the current position.
* $M$: the **smallest** prefix seen so far (to the left of the current position).

At each step $j$, the best block **ending at** $j$ is "current prefix minus the smallest older prefix":

$$
\text{best ending at j} = S_j - \min_{0 \le t < j} S_t
$$

So during the scan:

1. Update $S \leftarrow S + x[j]$.
2. Update the answer with $S - M$.
3. Update $M \leftarrow \min(M, S)$.

This is the whole algorithm. In words: keep the lowest floor you've ever seen and measure how high you are above it now. If you dip to a new floor, remember it; if you rise, maybe you've set a new record.

**Why is this greedy?** At each position, we make the local decision to either continue the current subarray or start fresh from the current position. Specifically, if the running sum ever becomes negative, we "drop" that prefix because it would only hurt future subarrays. This is the greedy choice: never carry a negative prefix forward.

A widely used equivalent form keeps a "best sum ending here" value $E$: set $E \leftarrow \max(x[j], E + x[j])$ and track a global maximum. It's the same idea written incrementally: if the running sum ever hurts you (becomes negative), you "reset" and start fresh at the current element.

**Algorithm**

*Walkthrough*

Sequence $x = [2, -3, 4, -1, 2, -5, 3]$ (0-based indices).

Initialize $S = 0$, $M = 0$, and $\text{best} = -\infty$. Keep the index $t$ where the current $M$ occurred so we can reconstruct the block.

```
 j   x[j]   S_j = S+x[j]   M (min prefix so far)   S_j - M   best   chosen block
------------------------------------------------------------------------------------
 0    2         2                0                    2        2     (0..0)
       update: M = min(0,2) = 0

 1   -3        -1                0                   -1        2     (still 0..0)
       update: M = min(0,-1) = -1   [new floor at t=1]

 2    4         3               -1                    4        4     (2..2)
       update: M = min(-1,3) = -1

 3   -1         2               -1                    3        4     (still 2..2)
       update: M = min(-1,2) = -1

 4    2         4               -1                    5        5     (2..4)  ✓
       update: M = min(-1,4) = -1

 5   -5        -1               -1                    0        5     (still 2..4)
       update: M = min(-1,-1) = -1

 6    3         2               -1                    3        5     (still 2..4)
       update: M = min(-1,2) = -1
```

Final answer: maximum sum $= 5$, achieved by indices $2 \ldots 4$ (that's $[4, -1, 2]$).

You can picture $S_j$ as a hilly skyline and $M$ as the lowest ground you've touched. The best block is the tallest vertical gap between the skyline and any earlier ground level.

```
prefix S: 0 → 2 → -1 → 3 → 2 → 4 → -1 → 2
ground M: 0   0   -1   -1  -1  -1   -1  -1
gap S-M:  0   2    0    4   3   5    0   3
                                ^ peak gap = 5 here
```

**Pseudocode (prefix-floor form):**

```
best = -∞          # or x[0] if you require non-empty
S = 0
M = 0              # 0 makes empty prefix available
t = 0              # index where M happened (0 means before first element)
best_i = best_j = None

for j in 0..n-1:
    S = S + x[j]
    if S - M > best:
        best = S - M
        best_i = t + 1
        best_j = j
    if S < M:
        M = S
        t = j

return best, (best_i, best_j)
```

**Pseudocode (incremental form, Kadane's algorithm):**

```
best = -∞          # or x[0] if you require non-empty
E = 0              # best sum ending here

for j in 0..n-1:
    E = max(x[j], E + x[j])
    best = max(best, E)

return best
```

**Proof sketch**

The greedy choice is: if the running sum becomes negative, discard it and start fresh. This is safe because a negative prefix can never help a future subarray—it would only reduce the sum. 

The loop invariant is: "At position $j$, we know the best subarray ending at or before $j$." This is maintained because at each step we consider extending the current subarray or starting a new one at $j$, and we always choose the option that maximizes the sum.

**Greedy checklist application:**

1. **Greedy choice**: Discard any negative-running prefix; never carry a negative sum forward.
2. **Feasibility**: Always track the best contiguous subarray seen so far.
3. **Why safe**: A negative prefix can never improve a future subarray sum.
4. **Implementation**: Single pass with $O(1)$ state.
5. **Complexity**: $O(n)$ time, $O(1)$ space.

**Edge cases**

When all numbers are negative, the best block is the **least negative single element**. The scan handles this automatically because $M$ keeps dropping with every step, so the maximum of $S_j - M$ happens when you take just the largest (least negative) entry.

Empty-block conventions matter. If you define the answer to be strictly nonempty, initialize $\text{best}$ with $x[0]$ and $E = x[0]$ in the incremental form; if you allow empty blocks with sum $0$, initialize $\text{best} = 0$ and $M = 0$. Either way, the one-pass logic doesn't change.

**Complexity**

* Time: $O(n)$
* Space: $O(1)$


---

### When Greedy Is Guaranteed: Matroids

**Optional: Advanced Topic**

There's a tidy setting where greedy is *always* right (for nonnegative weights): when your "what's allowed" rules form a **matroid**. You don't need the symbols—just the vibe:

1. **You can start from empty.**
2. **Throwing things out never hurts.** If a set is allowed, any subset is allowed.
3. **Smooth growth (augmentation).** If one allowed set is smaller than another, you can always add *something* from the bigger one to the smaller and stay allowed.

That third rule prevents dead ends and is exactly what exchange arguments rely on. In matroids, the simple "sort by weight and take what fits" greedy is guaranteed optimal. Outside matroids, greedy can still work—but you must justify it for the specific problem using exchange/invariants.

**Why is this relevant to our examples?**

* **MST** is a classic matroid example (the graphic matroid). The "allowed sets" are forests (acyclic edge sets), which satisfy all three matroid properties. This is why Kruskal's algorithm (sort edges by weight, add if no cycle) always works.
* **Interval scheduling** has a matroid-like structure where "allowed sets" are non-overlapping intervals. This is sometimes called an "interval scheduling matroid" or viewed as a special case of matroid intersection.

The matroid framework explains why greedy works "automatically" in these settings—exchange arguments are baked into the structure. For problems like Dijkstra's algorithm or Huffman coding, the correctness proofs rely on problem-specific properties rather than general matroid theory, but the exchange argument pattern is similar.

**Bridge to exchange arguments:**

Matroids formalize the conditions under which exchange arguments succeed. The augmentation property (property 3 above) guarantees that if one solution is smaller, we can grow it by borrowing from a larger solution without breaking feasibility—this is exactly the swap operation used in exchange arguments.

If you're curious about matroids, they're worth studying for competitive programming and algorithm design, but they're not required to understand or apply greedy algorithms. Think of matroids as the "formal certificate" that greedy works, while exchange arguments are the "proof technique" you use in practice.

---

### Common Failure Modes

Greedy doesn't always work. Here are examples where the local-best choice fails:

#### Coin change with non-canonical coin systems

**Problem**: Make change for amount $n$ using the fewest coins from denominations $\{d_1, d_2, \ldots, d_k\}$.

**Greedy approach**: Always pick the largest coin that fits.

**Example where greedy fails**:

Denominations: $\{1, 3, 4\}$, target amount $= 6$.

* Greedy: picks $4$, then $1$, then $1$ → total 3 coins.
* Optimal: picks $3$, then $3$ → total 2 coins.

The greedy algorithm fails because larger coins don't always lead to fewer total coins in non-canonical systems. (For canonical systems like US coins $\{1, 5, 10, 25\}$, greedy does work.)

**Fix**: Use dynamic programming instead.

#### Interval scheduling by earliest start time

**Problem**: Same as interval scheduling (maximize non-overlapping intervals).

**Wrong greedy approach**: Sort by start time and take what fits.

**Example where this fails**:

Intervals: $(1, 10), (2, 3), (4, 5)$.

* Greedy by start time: picks $(1, 10)$ first, then can't fit $(2, 3)$ or $(4, 5)$ → total 1 interval.
* Optimal (by finish time): picks $(2, 3)$ and $(4, 5)$ → total 2 intervals.

Picking the earliest start doesn't leave room for other intervals that might fit. The correct greedy choice is earliest **finish** time.

**Fix**: Sort by finish time instead of start time.

#### Fractional vs 0/1 knapsack

**Problem**: Pack items with weights and values into a knapsack of capacity $W$.

**Greedy works for fractional knapsack**: Sort by value/weight ratio and take as much as possible of each item (allowing fractions).

**Greedy fails for 0/1 knapsack**: You must take whole items or nothing.

**Example where greedy fails (0/1)**:

Items: $(w_1 = 10, v_1 = 60), (w_2 = 20, v_2 = 100), (w_3 = 30, v_3 = 120)$, capacity $W = 50$.

Ratios: $v_1/w_1 = 6, v_2/w_2 = 5, v_3/w_3 = 4$.

* Greedy by ratio: picks item 1 ($w = 10, v = 60$), then item 2 ($w = 20, v = 100$), then can't fit item 3 → total value $= 160$.
* Optimal: picks item 2 and item 3 ($w = 50, v = 220$) → total value $= 220$.

**Fix**: Use dynamic programming for 0/1 knapsack.

---

**Lesson**: Always verify the greedy choice is safe for your specific problem using an exchange argument or loop invariant. If you can't prove it, greedy might not work, and you may need dynamic programming, backtracking, or another approach.

