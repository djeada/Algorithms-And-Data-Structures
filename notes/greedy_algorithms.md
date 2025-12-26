## Greedy algorithms

Greedy algorithms build a solution one step at a time. At each step, grab the option that looks best *right now* by some simple rule (highest value, earliest finish, shortest length, etc.). Keep it if it doesn’t break the rules of the problem.

1. Sort by your rule (the “key”).
2. Scan items in that order.
3. If adding this item keeps the partial answer valid, keep it.
4. Otherwise skip it.

Picking the best “now” doesn’t obviously give the best “overall.” The real work is showing that these local choices still lead to a globally best answer.

**Two proof tricks you’ll see a lot:**

* *Exchange argument.* Take any optimal solution that disagrees with greedy at the first point. Show you can “swap in” the greedy choice there without making the solution worse or breaking feasibility. Do this repeatedly and you morph some optimal solution into the greedy one—so greedy must be optimal.
* *Loop invariant.* Write down a sentence that’s true after every step of the scan (e.g., “the current set is feasible and as good as any other set built from the items we’ve seen”). Prove it stays true as you process the next item; at the end, that sentence implies optimality.

*Picture it like this:*

```
position →   1    2    3    4    5
greedy:     [✓]  [✗]  [✓]  [✓]  [✗]
some optimal:
             ✓    ✓    ✗    ?    ?
First mismatch at 3 → swap in greedy’s pick without harm.
Repeat until both rows match → greedy is optimal.
```

**Where greedy shines automatically: matroids (nice constraint systems).**
There’s a tidy setting where greedy is *always* right (for nonnegative weights): when your “what’s allowed” rules form a **matroid**. You don’t need the symbols—just the vibe:

1. **You can start from empty.**
2. **Throwing things out never hurts.** If a set is allowed, any subset is allowed.
3. **Smooth growth (augmentation).** If one allowed set is smaller than another, you can always add *something* from the bigger one to the smaller and stay allowed.

That third rule prevents dead ends and is exactly what exchange arguments rely on. In matroids, the simple “sort by weight and take what fits” greedy is guaranteed optimal. Outside matroids, greedy can still work—but you must justify it for the specific problem using exchange/invariants.

### Reachability on a line

- You stand at square $0$ on squares $0,1,\ldots,n-1$.
- Each square $i$ has a jump power $a[i]$. From $i$ you may land on any of $i+1, i+2, \dots, i+a[i]$.
- Goal: decide if you can reach $n-1$; if not, report the furthest reachable square.

**Example**

Input: $a=[3,1,0,0,4,1]$, so $n=6$ (squares $0..5$).

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

“Paint everything reachable, one wave at a time.”

1. Start with ${0}$ reachable.
2. For each already-reachable $i$, add all $i+1..i+a[i]$.
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

**One-pass trick**

Carry one number while scanning left→right: the furthest frontier $F$ seen so far.

Rules:

* If you are at $i$ with $i>F$, you hit a gap → stuck forever.
* Otherwise, extend $F \leftarrow \max(F, i+a[i])$ and continue.

At the end:

* Can reach last iff $F \ge n-1$.
* Furthest reachable square is $F$ (capped by $n-1$).

*Pseudocode*

```
F = 0
for i in 0..n-1:
    if i > F: break
    F = max(F, i + a[i])

can_reach_last = (F >= n-1)
furthest = min(F, n-1)
```

Why this is safe (one line): $F$ always equals “best jump end discovered from any truly-reachable square $\le i$,” and never decreases; if $i>F$, no earlier jump can help because its effect was already folded into $F$.

*Walkthrough:*

We draw the frontier as a bracket reaching to $F$.

Step $i=0$ (inside frontier since $0\le F$); update $F=\max(0,0+3)=3$.

```
indices:  0   1   2   3   4   5
          [===============F]
          0   1   2   3
F=3
```

Step $i=1$: still $i\le F$. Update $F=\max(3,1+1)=3$ (no change).
Step $i=2$: $F=\max(3,2+0)=3$ (no change).
Step $i=3$: $F=\max(3,3+0)=3$ (no change).

Now $i=4$ but $4>F(=3)$ → gap → stuck.

```
indices:  0   1   2   3   4   5
          [===============F]   x  (i=4 is outside)
F=3
```

Final: $F=3$. Since $F <n-1=5$, last is unreachable; furthest reachable square is $3$.

Complexity: time $O(n)$, space $O(1)$.

### Minimum spanning trees

You’ve got a connected weighted graph and you want the cheapest way to connect **all** its vertices without any cycles—that’s a minimum spanning tree (MST). Think “one network of cables that touches every building, with the total cost as small as possible.”

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
{A ⁣− ⁣B(1), B ⁣− ⁣D(2), C ⁣− ⁣E(3), B ⁣− ⁣C(4)}
$$

Total weight $=1+2+3+4=10$.

You can’t do better: any cheaper set of 4 edges would either miss a vertex or create a cycle.

*Baseline*

Enumerate every spanning tree and pick the one with the smallest total weight. That’s conceptually simple—“try all combinations of $n-1$ edges that connect everything and have no cycles”—but it explodes combinatorially. Even medium graphs have an astronomical number of spanning trees, so this approach is only good as a thought experiment.

*How it works*

Both fast methods rely on two facts:

* **Cut rule (safe to add)** - for any cut $(S, V\setminus S)$, the cheapest edge that crosses the cut appears in some MST. Intuition: if your current partial connection is on one side, the cheapest bridge to the other side is never a bad idea.
* **Cycle rule (safe to skip)** - in any cycle, the most expensive edge is never in an MST. Intuition: if you already have a loop, drop the priciest link and you’ll still be connected but strictly cheaper.

#### Kruskal’s method

**Example inputs and outputs**

Use the same graph as above. A valid MST is

$$
\{A\!-\!B(1), B\!-\!D(2), C\!-\!E(3), B\!-\!C(4)\}\quad\Rightarrow\quad \text{total} = 10
$$

**How it works**

Sort edges from lightest to heaviest; walk down that list and keep an edge if it connects two **different** components. Stop when you have $n-1$ edges.

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

We’ll keep a running view of the components; initially each vertex is alone.

```
start:   {A} {B} {C} {D} {E}

take 1:  A-B(1)   → {AB} {C} {D} {E}
take 2:  B-D(2)   → {ABD} {C} {E}
take 3:  C-E(3)   → {ABD} {CE}
take 4:  B-C(4)   → {ABCDE}   ← all connected (|V|-1 edges) → stop

kept: A-B(1), B-D(2), C-E(3), B-C(4)  → total = 10
```

- Edges kept: $A\!-\!B(1), B\!-\!D(2), C\!-\!E(3), B\!-\!C(4)$.
- Total $=10$. Every later edge would create a cycle and is skipped by the cycle rule.

Kruskal pseudocode

```python
MST = ∅
make_set(v) for v in V
for (w,u,v) in edges sorted by w:
    if find(u) != find(v):
        MST.add((u,v,w))
        union(u,v)
        if |MST| == |V|-1: break
```

Complexity

* Time: $O(E \log E)$ to sort edges + near-constant $\alpha(V)$ for DSU unions; often written $O(E \log V)$ since $E\le V^2$.
* Space: $O(V)$ for disjoint-set structure.

#### Prim's method

**Example inputs and outputs**

Same graph and target: produce any MST of total weight $10$.

**How it works**

Start from any vertex; repeatedly add the lightest edge that leaves the current tree to bring in a new vertex. Stop when all vertices are in.

Let’s start from $A$. The “tree” grows one cheapest boundary edge at a time.

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

Edges chosen: exactly the same four as Kruskal, total $=10$.

Why did step 4 grab a weight-3 edge after we already took a 4? Because earlier that 3 wasn’t **available**—it didn’t cross from the tree to the outside until $C$ joined the tree. Prim never regrets earlier picks because of the cut rule: at each moment it adds the cheapest bridge from “inside” to “outside,” and that’s always safe.

Prim pseudocode (binary heap)

```python
pick any root r
Tree = {r}
push all edges (r→v,w) into heap
while |Tree| < |V|:
    pop (w,u→v) with minimum w where v ∉ Tree
    add v to Tree; record edge (u,v,w) in MST
    push all edges (v→x,wvx) with x ∉ Tree
```

Complexity

* Time: $O(E \log V)$ with a binary heap and adjacency lists; $O(E + V\log V)$ with a Fibonacci heap.
* Space: $O(V)$ for keys/parents and visited set.

### Shortest paths with non-negative weights (Dijkstra)

Goal: from start $s$, compute cheapest costs $d(\cdot)$ to every node (and routes if you keep parents).

Non-negative edges only; that’s what makes the greedy step safe.

Example

```
Nodes: A B C D E   (start s=A)

Edges (undirected):
A-B:2  A-C:5
B-C:1  B-D:2  B-E:7
C-D:3  C-E:1
D-E:2
```

Correct answers from A: $d(A)=0, d(B)=2, d(C)=3, d(D)=4, d(E)=4$.

*Baseline* 

Repeat relaxations $|V|-1$ rounds (Bellman–Ford-style).

Work $\approx |V|\cdot|E|$. Handles negatives; we don’t need that here.

Fast method (Dijkstra): “settle the smallest label”

1. Initialize distance labels: set $d(s)=0$, and $d(x)=\infty$ for all other nodes.
2. Initialize parent pointers $\pi(\cdot)$.
3. Initialize the settled set $S=\emptyset$.
4. Initialize the unsettled set as $V\setminus S$.
5. Select the unsettled node $u$ with the smallest distance label $d(u)$.
6. Move node $u$ from the unsettled set into the settled set.
7. Update each neighbor $v$ of $u$ by assigning $d(v) \leftarrow \min\bigl(d(v), d(u) + w(u,v)\bigr)$.
8. If the update in step 7 improves $d(v)$, then set $\pi(v) \leftarrow u$.
9. Repeat from step 5 until all nodes are settled or no reachable unsettled nodes remain.
10. Justification of correctness: with non-negative edge weights, any path reaching an unsettled node must have length at least $d(u)$ plus a non-negative exit edge, so the chosen $d(u)$ is final and cannot later be decreased.

Pseudocode (binary heap)

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

Time $O((|V|+|E|)\log|V|)$; space $O(|V|)$.

*Walkthrough*

Legend: “S” = settled, “π[x]” = parent of $x$. Ties break arbitrarily.

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

* $B$: $A\to B$
* $C$: $A\to B\to C$
* $D$: $A\to B\to D$
* $E$: $A\to B\to C\to E$

Complexity

* Time: $O((V+E)\log V)$ with a binary heap (often written $O(E \log V)$ when $E\ge V$).
* Space: $O(V)$ for distances, parent pointers, and heap entries.

### Maximum contiguous sum

You’re given a list of numbers laid out in a line. You may pick one **contiguous** block, and you want that block’s sum to be as large as possible.

**Example inputs and outputs**

```
x = [ 2, -3, 4, -1, 2, -5, 3 ]
best block = [ 4, -1, 2 ]  → sum = 5
```

So the correct output is “maximum sum $=5$” and one optimal segment is positions $3$ through $5$ (1-based).

*Baseline*

(Note: This section uses 1-based indexing for mathematical convenience with prefix sums, following standard textbook conventions.)

Try every possible block and keep the best total. To sum any block $i..j$ quickly, precompute **prefix sums** $S_0=0$ and $S_j=\sum_{k=1}^j x_k$. Then

$$
\sum_{k=i}^j x_k = S_j - S_{i-1}
$$

Loop over all $j$ and all $i\le j$, compute $S_j-S_{i-1}$, and take the maximum. This is easy to reason about and always correct, but it does $O(n^2)$ block checks.

**How it works**

This is greedy in the sense that any negative prefix is never worth keeping—we discard it immediately. The local decision is: "Does adding the current element to my running sum help, or should I start fresh here?" That greedy choice turns out to be safe.

Walk left to right once and carry two simple numbers.

* $S$: the running prefix sum up to the current position.
* $M$: the **smallest** prefix seen so far (to the left of the current position).

At each step $j$, the best block **ending at** $j$ is “current prefix minus the smallest older prefix”:

$$
\text{best ending at j} = S_j - \min_{0\le t \le j} S_t
$$

So during the scan:

1. Update $S \leftarrow S + x_j$.
2. Update the answer with $S - M$.
3. Update $M \leftarrow \min(M, S)$.

This is the whole algorithm. In words: keep the lowest floor you’ve ever seen and measure how high you are above it now. If you dip to a new floor, remember it; if you rise, maybe you’ve set a new record.

A widely used equivalent form keeps a “best sum ending here” value $E$: set $E \leftarrow \max(x_j, E+x_j)$ and track a global maximum. It’s the same idea written incrementally: if the running sum ever hurts you, you “reset” and start fresh at the current element.

*Walkthrough*

Sequence $x = [2,-3,4,-1,2,-5,3]$.

Initialize $S=0$, $M=0$, and $\text{best}=-\infty$. Keep the index $t$ where the current $M$ occurred so we can reconstruct the block as $(t+1)..j$.

```
 j   x_j   S_j = S+x_j   M (min prefix so far)   S_j - M   best   chosen block
--------------------------------------------------------------------------------
 1    2         2                0                  2        2     (1..1)
       update: M = min(0,2) = 0

 2   -3        -1                0                 -1        2     (still 1..1)
       update: M = min(0,-1) = -1   [new floor at t=2]

 3    4         3               -1                  4        4     (3..3)
       update: M = min(-1,3) = -1

 4   -1         2               -1                  3        4     (still 3..3)
       update: M = min(-1,2) = -1

 5    2         4               -1                  5        5     (3..5)  ✓
       update: M = min(-1,4) = -1

 6   -5        -1               -1                  0        5     (still 3..5)
       update: M = min(-1,-1) = -1

 7    3         2               -1                  3        5     (still 3..5)
       update: M = min(-1,2) = -1
```

Final answer: maximum sum $=5$, achieved by indices $3..5$ (that’s $[4,-1,2]$).

You can picture $S_j$ as a hilly skyline and $M$ as the lowest ground you’ve touched. The best block is the tallest vertical gap between the skyline and any earlier ground level.

```
prefix S: 0 → 2 → -1 → 3 → 2 → 4 → -1 → 2
ground M: 0   0   -1   -1  -1  -1   -1  -1
gap S-M:  0   2    0    4   3   5    0   3
                                ^ peak gap = 5 here
```

Pseudocode (prefix-floor form):

```
best = -∞          # or x[0] if you require non-empty
S = 0
M = 0              # 0 makes empty prefix available
t = 0              # index where M happened (0 means before first element)
best_i = best_j = None

for j in 1..n:
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

*Edge cases*

When all numbers are negative, the best block is the **least negative single element**. The scan handles this automatically because $M$ keeps dropping with every step, so the maximum of $S_j-M$ happens when you take just the largest entry.

Empty-block conventions matter. If you define the answer to be strictly nonempty, initialize $\text{best}$ with $x_1$ and $E=x_1$ in the incremental form; if you allow empty blocks with sum $0$, initialize $\text{best}=0$ and $M=0$. Either way, the one-pass logic doesn’t change.

*Complexity*

* Time: $O(n)$
* Space: $O(1)$

### Scheduling themes

Two classics:

- Pick as many non-overlapping intervals as possible (one room, max meetings).
- Keep maximum lateness small when jobs have deadlines.

They’re both greedy—and both easy to run by hand.

Imagine you have time intervals on a single line, and you can keep an interval only if it doesn’t overlap anything you already kept. The aim is to keep as many as possible.

**Example inputs and outputs**

Intervals (start, finish):

```
(1,3) (2,5) (4,7) (6,9) (8,10) (9,11)
```

A best answer keeps three intervals, for instance $(1,3),(4,7),(8,10)$.

**Baseline (slow)**

Try all subsets and keep the largest that has no overlaps. That’s conceptually simple and always correct, but it’s exponential in the number of intervals, which is a non-starter for anything but tiny inputs.

**Greedy rule:** 

Sort by finish time and take what fits.

- Scan from earliest finisher to latest.
- Keep $(s,e)$ iff $s \ge \text{last end}$; then set $\text{last end}\leftarrow e$.

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

Kept intervals: $(1,3),(4,7),(8,10)$. Three kept, which matches the claim.

A tiny picture helps the “finish early” idea feel natural:

```
time →
kept:  [1────3) [4─────7)  [8────10)
skip:      [2────5)  [6──────9)[9─────11)
ending earlier leaves more open space to the right
```

Why this works: at the first place an optimal schedule would choose a later-finishing interval, swapping in the earlier finisher cannot reduce what still fits afterward, so you can push the optimal schedule to match greedy without losing size.

Handy pseudocode

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

*Complexity*

* Time: $O(n \log n)$ to sort by finishing time; $O(n)$ scan.
* Space: $O(1)$ (beyond input storage).

### Minimize the maximum lateness

Now think of $n$ jobs, all taking the same amount of time (say one unit). Each job $i$ has a deadline $d_i$. When you run them in some order, the completion time of the $k$-th job is $C_k=k$ (since each takes one unit), and its lateness is

$$
L_i = C_i - d_i.
$$

Negative values mean you finished early; the quantity to control is the worst lateness $L_{\max}=\max_i L_i$. The goal is to order the jobs so $L_{\max}$ is as small as possible.

**Example inputs and outputs**

Jobs and deadlines:

* $J_1: d_1=3$
* $J_2: d_2=1$
* $J_3: d_3=4$
* $J_4: d_4=2$

An optimal schedule is $J_2,J_4, J_1, J_3$. The maximum lateness there is $0$.

**Baseline (slow)**

Try all $n!$ orders, compute every job’s completion time and lateness, and take the order with the smallest $L_{\max}$. This explodes even for modest $n$.

**Greedy rule**

Order jobs by nondecreasing deadlines (earliest due date first, often called EDD). Fixing any “inversion” where a later deadline comes before an earlier one can only help the maximum lateness, so sorting by deadlines is safe.

Deadlines in increasing order:

$$
J_2(d=1), J_4(d=2), J_1(d=3), J_3(d=4)
$$

Run them one by one and compute completion times and lateness.

```
slot 1: J2 finishes at C=1 → L2 = 1 - d2(=1) = 0
slot 2: J4 finishes at C=2 → L4 = 2 - d4(=2) = 0
slot 3: J1 finishes at C=3 → L1 = 3 - d1(=3) = 0
slot 4: J3 finishes at C=4 → L3 = 4 - d3(=4) = 0
L_max = 0
```

If you scramble the order, the worst lateness jumps. For example, $J_1,J_2,J_3,J_4$ gives

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

Why this works: if two adjacent jobs are out of deadline order, swapping them never increases any completion time relative to its own deadline, and strictly improves at least one, so repeatedly fixing these inversions leads to the sorted-by-deadline order with no worse maximum lateness.

Pseudocode

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

*Complexity*

* Time: $O(n \log n)$ to sort by deadlines; $O(n)$ evaluation.
* Space: $O(1)$.

### Huffman coding

You have symbols that occur with known frequencies $f_i>0$ and $\sum_i f_i=1$ (if you start with counts, first normalize by their total). The goal is to assign each symbol a binary codeword so that no codeword is a prefix of another (a **prefix code**, i.e., uniquely decodable without separators), and the average length

$$
\mathbb{E}[L]=\sum_i f_i\,L_i
$$

is as small as possible. Prefix codes correspond exactly to **full binary trees** (every internal node has two children) whose leaves are the symbols and whose leaf depths equal the codeword lengths $L_i$. The **Kraft inequality** $\sum_i 2^{-L_i}\le 1$ characterizes feasibility; equality holds for full trees (so an optimal prefix code “fills” the inequality).

**Example inputs and outputs**

Frequencies:

$$
A:0.40,\quad B:0.20,\quad C:0.20,\quad D:0.10,\quad E:0.10.
$$

A valid optimal answer will be a prefix code with expected length as small as possible. We will compute the exact minimum and one optimal set of lengths $L\_A,\dots,L\_E$, plus a concrete codebook. (There can be multiple optimal codebooks when there are ties in frequencies; expected length is the same; codeword/leaf assignments may differ (especially among equal-frequency symbols).)

**Baseline**

One conceptual baseline is to enumerate all full binary trees with five labeled leaves and pick the one minimizing $\sum_i f_i L_i$. That is correct but explodes combinatorially as the number of symbols grows. A simpler but usually suboptimal baseline is to give every symbol the same length $\lceil \log\_2 5\rceil=3$. That fixed-length code has $\mathbb{E}[L]=3$.

**Greedy Approach**

Huffman’s rule repeats one tiny step: always merge the two least frequent items. When you merge two “symbols” with weights $p$ and $q$, you create a parent of weight $p+q$. **Why does this change the objective by exactly $p+q$?** Every leaf in those two subtrees increases its depth (and thus its code length) by $1$, so the total increase in $\sum f\_i L\_i$ is $\sum\_{\ell\in\text{subtrees}} f\_\ell\cdot 1=(p+q)$ by definition of $p$ and $q$. Summing over all merges yields the final cost:

$$
\mathbb{E}[L]=\sum_{\text{merges}} (p+q)=\sum_{\text{internal nodes}} \text{weight}.
$$

**Why is the greedy choice optimal?** In an optimal tree the two deepest leaves must be siblings; if not, pairing them to be siblings never increases any other depth and strictly reduces cost whenever a heavier symbol is deeper than a lighter one (an **exchange argument**: swapping depths changes the cost by $f\_{\text{heavy}}-f\_{\text{light}}>0$ in our favor). Collapsing those siblings into a single pseudo-symbol reduces the problem size without changing optimality, so induction finishes the proof. (Ties can be broken arbitrarily; all tie-breaks achieve the same minimum $\mathbb{E}[L]$.)

Start with the multiset ${0.40, 0.20, 0.20, 0.10, 0.10}$. At each line, merge the two smallest weights and add their sum to the running cost.

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

So the optimal expected length is $\boxed{\mathbb{E}[L]=2.20}$ bits per symbol. This already beats the naive fixed-length baseline $3$. It also matches the information-theoretic bound $H(f)\le \mathbb{E}[L] <H(f)+1$, since the entropy here is $H\approx 2.1219$.

Now assign actual lengths. Record who merged with whom:

* Step 1 merges $D(0.10)$ and $E(0.10)$ → those two become siblings.
* Step 2 merges $B(0.20)$ and $C(0.20)$ → those two become siblings.
* Step 3 merges the pair $D!E(0.20)$ with $A(0.40)$.
* Step 4 merges the pair from step 3 with the pair $B!C(0.40)$.

Depths follow directly (each merge adds one level to its members):

$$
L_A=2,\quad L_B=L_C=2,\quad L_D=L_E=3.
$$

Check the Kraft sum $3\cdot 2^{-2}+2\cdot 2^{-3}=3/4+1/4=1$ and the cost $0.4\cdot2+0.2\cdot2+0.2\cdot2+0.1\cdot3+0.1\cdot3=2.2$.

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

*Complexity*

* Time: $O(k \log k)$ using a min-heap over $k$ symbol frequencies (each of the $k-1$ merges performs two extractions and one insertion).
* Space: $O(k)$ for the heap and $O(k)$ for the resulting tree (plus $O(k)$ for an optional map from symbols to codewords).
