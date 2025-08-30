## Greedy algorithms

Greedy algorithms build a solution one step at a time. At each step, grab the option that looks best *right now* by some simple rule (highest value, earliest finish, shortest length, etc.). Keep it if it doesn’t break the rules of the problem.

```
1) Sort by your rule (the “key”).
2) Scan items in that order.
3) If adding this item keeps the partial answer valid, keep it.
4) Otherwise skip it.
```

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

- You stand at square \$0\$ on squares \$0,1,\dots,n-1\$.
- Each square \$i\$ has a jump power \$a\[i]\$. From \$i\$ you may land on any of \$i+1, i+2, \dots, i+a\[i]\$.
- Goal: decide if you can reach \$n-1\$; if not, report the furthest reachable square.

Example

* Input: \$a=\[3,1,0,0,4,1]\$, so \$n=6\$ (squares \$0..5\$).

```
indices:  0   1   2   3   4   5
a[i]   :  3   1   0   0   4   1
reach   :  ^ start at 0
```

From any \$i\$, the allowed landings are a range:

```
i=0 (a[0]=3): 1..3
i=1 (a[1]=1): 2
i=2 (a[2]=0): —
i=3 (a[3]=0): —
i=4 (a[4]=4): 5..8 (board ends at 5)
```

---

Baseline idea (waves)

“Paint everything reachable, one wave at a time.”

1. Start with \${0}\$ reachable.
2. For each already-reachable \$i\$, add all \$i+1..i+a\[i]\$.
3. Stop when nothing new appears.

Walk on the example:

```
start:   reachable = {0}
from 0:  add {1,2,3}     → reachable = {0,1,2,3}
from 1:  add {2}         → no change
from 2:  add {}          → a[2]=0
from 3:  add {}          → a[3]=0
stop:    no new squares  → furthest = 3; last (5) unreachable
```

Correct, but can reprocess many squares.

---

One-pass trick (frontier)

Carry one number while scanning left→right: the furthest frontier \$F\$ seen so far.

Rules:

* If you are at \$i\$ with \$i>F\$, you hit a gap → stuck forever.
* Otherwise, extend \$F \leftarrow \max(F,\ i+a\[i])\$ and continue.

At the end:

* Can reach last iff \$F \ge n-1\$.
* Furthest reachable square is \$F\$ (capped by \$n-1\$).

Pseudocode

```
F = 0
for i in 0..n-1:
    if i > F: break
    F = max(F, i + a[i])

can_reach_last = (F >= n-1)
furthest = min(F, n-1)
```

Why this is safe (one line): \$F\$ always equals “best jump end discovered from any truly-reachable square \$\le i\$,” and never decreases; if \$i>F\$, no earlier jump can help because its effect was already folded into \$F\$.

 walkthrough on the example

We draw the frontier as a bracket reaching to \$F\$.

Step \$i=0\$ (inside frontier since \$0\le F\$); update \$F=\max(0,0+3)=3\$.

```
indices:  0   1   2   3   4   5
          [===============F]
          0   1   2   3
F=3
```

Step \$i=1\$: still \$i\le F\$. Update \$F=\max(3,1+1)=3\$ (no change).
Step \$i=2\$: \$F=\max(3,2+0)=3\$ (no change).
Step \$i=3\$: \$F=\max(3,3+0)=3\$ (no change).

Now \$i=4\$ but \$4>F(=3)\$ → gap → stuck.

```
indices:  0   1   2   3   4   5
          [===============F]   x  (i=4 is outside)
F=3
```

Final: \$F=3\$. Since \$F\<n-1=5\$, last is unreachable; furthest reachable square is \$3\$.

Complexity: time \$O(n)\$, space \$O(1)\$.


### Minimum spanning trees

You’ve got a connected weighted graph and you want the cheapest way to connect **all** its vertices without any cycles—that’s a minimum spanning tree (MST). Think “one network of cables that touches every building, with the total cost as small as possible.”

**Example inputs and outputs**

Vertices: $V=\{A,B,C,D,E\}$

Edges with weights:

* $A\!-\!B:1,\ A\!-\!C:5,\ A\!-\!E:9$
* $B\!-\!C:4,\ B\!-\!D:2,\ B\!-\!E:7$
* $C\!-\!D:6,\ C\!-\!E:3$
* $D\!-\!E:8$

A correct MST for this graph is:

$$
\{A\!-\!B(1),\ B\!-\!D(2),\ C\!-\!E(3),\ B\!-\!C(4)\}
$$

Total weight $=1+2+3+4=10$.

You can’t do better: any cheaper set of 4 edges would either miss a vertex or create a cycle.

Baseline (slow)

Enumerate every spanning tree and pick the one with the smallest total weight. That’s conceptually simple—“try all combinations of $n-1$ edges that connect everything and have no cycles”—but it explodes combinatorially. Even medium graphs have an astronomical number of spanning trees, so this approach is only good as a thought experiment.

**How it works**

Both fast methods rely on two facts:

* **Cut rule (safe to add):** for any cut $(S, V\setminus S)$, the cheapest edge that crosses the cut appears in some MST. Intuition: if your current partial connection is on one side, the cheapest bridge to the other side is never a bad idea.
* **Cycle rule (safe to skip):** in any cycle, the most expensive edge is never in an MST. Intuition: if you already have a loop, drop the priciest link and you’ll still be connected but strictly cheaper.

#### Kruskal’s method

**Example inputs and outputs**

Use the same graph as above. A valid MST is

$$
\{A\!-\!B(1),\ B\!-\!D(2),\ C\!-\!E(3),\ B\!-\!C(4)\}\quad\Rightarrow\quad \text{total} = 10.
$$

**How it works**

Sort edges from lightest to heaviest; walk down that list and keep an edge if it connects two **different** components. Stop when you have $n-1$ edges.

Sorted edges by weight:

$$
1: A\!-\!B,\quad
2: B\!-\!D,\quad
3: C\!-\!E,\quad
4: B\!-\!C,\quad
5: A\!-\!C,\quad
6: C\!-\!D,\quad
7: B\!-\!E,\quad
8: D\!-\!E,\quad
9: A\!-\!E
$$

We’ll keep a running view of the components; initially each vertex is alone.

1. $A\!-\!B(1)$ connects $\{A\}$ and $\{B\}$ → **keep**
   Components: $\{A,B\},\{C\},\{D\},\{E\}$

2. $B\!-\!D(2)$ connects $\{A,B\}$ and $\{D\}$ → **keep**
   Components: $\{A,B,D\},\{C\},\{E\}$

3. $C\!-\!E(3)$ connects $\{C\}$ and $\{E\}$ → **keep**
   Components: $\{A,B,D\},\{C,E\}$

4. $B\!-\!C(4)$ connects $\{A,B,D\}$ and $\{C,E\}$ → **keep**
   Components: $\{A,B,C,D,E\}$  ← all connected; we have 4 edges → stop.

Edges kept: $A\!-\!B(1), B\!-\!D(2), C\!-\!E(3), B\!-\!C(4)$.
Total $=10$. Every later edge would create a cycle and is skipped by the cycle rule.

Complexity

* Time: $O(E \log E)$ to sort edges + near-constant $\alpha(V)$ for DSU unions; often written $O(E \log V)$ since $E\le V^2$.
* Space: $O(V)$ for disjoint-set structure.

### Prim's method

**Example inputs and outputs**

Same graph and target: produce any MST of total weight $10$.

**How it works**

Start from any vertex; repeatedly add the lightest edge that leaves the current tree to bring in a new vertex. Stop when all vertices are in.

Let’s start from $A$. The “tree” grows one cheapest boundary edge at a time.

Start: tree = $\{A\}$. Boundary edges from $A$: $A\!-\!B(1), A\!-\!C(5), A\!-\!E(9)$.

1. Take $A\!-\!B(1)$ (lightest leaving the tree).
   Tree vertices: $\{A,B\}$. New boundary includes $B\!-\!D(2), B\!-\!C(4), B\!-\!E(7)$ as well.

2. Take $B\!-\!D(2)$ (now the lightest boundary edge).
   Tree: $\{A,B,D\}$. Boundary now has $B\!-\!C(4), A\!-\!C(5), D\!-\!C(6), B\!-\!E(7), D\!-\!E(8), A\!-\!E(9)$.

3. Take $B\!-\!C(4)$.
   Tree: $\{A,B,C,D\}$. Boundary updates to include $C\!-\!E(3)$.

4. Take $C\!-\!E(3)$ (cheapest boundary edge now).
   Tree: $\{A,B,C,D,E\}$ → all vertices included → stop.

Edges chosen: exactly the same four as Kruskal, total $=10$.

Why did step 4 grab a weight-3 edge after we already took a 4? Because earlier that 3 wasn’t **available**—it didn’t cross from the tree to the outside until $C$ joined the tree. Prim never regrets earlier picks because of the cut rule: at each moment it adds the cheapest bridge from “inside” to “outside,” and that’s always safe.

Complexity

* Time: $O(E \log V)$ with a binary heap and adjacency lists; $O(E + V\log V)$ with a Fibonacci heap.
* Space: $O(V)$ for keys/parents and visited set.

### Shortest paths with non-negative weights

You’ve got a weighted graph and a starting node $s$. Every edge has a cost $\ge 0$. The task is to find the cheapest cost to reach every node from $s$, and a cheapest route for each if you want it.

**Example inputs and outputs**

Nodes: $A,B,C,D,E$

Edges (undirected, weights in parentheses):

* $A\!-\!B(2)$, $A\!-\!C(5)$
* $B\!-\!C(1)$, $B\!-\!D(2)$, $B\!-\!E(7)$
* $C\!-\!D(3)$, $C\!-\!E(1)$
* $D\!-\!E(2)$

Start at $A$.

Correct shortest-path costs from $A$:

* $d(A)=0$
* $d(B)=2$ via $A\!\to\!B$
* $d(C)=3$ via $A\!\to\!B\!\to\!C$
* $d(D)=4$ via $A\!\to\!B\!\to\!D$
* $d(E)=4$ via $A\!\to\!B\!\to\!C\!\to\!E$

Baseline (slow)

One safe—but slower—approach is to relax all edges repeatedly until nothing improves. Think of it as “try to shorten paths by one edge at a time, do that $|V|-1$ rounds.” This eventually converges to the true shortest costs, but it touches every edge many times, so its work is about $|V|\cdot|E|$. It also handles negative edges, which is why it has to be cautious and keep looping.

**How it works**

Carry two sets and a distance label for each node.

* “Settled” nodes are done forever; their labels are final.
* “Unsettled” nodes still might improve.

Initialize all labels to $\infty$ except $d(s)=0$. Over and over:

1. Pick the **unsettled** node with the **smallest** label. Call it $u$. Move $u$ to settled.
2. For each neighbor $v$ of $u$, try to improve $d(v)$ using the route through $u$:

   $$
   d(v)\ \leftarrow\ \min\bigl(d(v),\ d(u)+w(u,v)\bigr).
   $$

Greedy “settle and forget” is safe **because all edges are non-negative**. At the moment you pick the smallest-label unsettled node $u$, every route to any other unsettled node must cost at least $d(u)$ plus some non-negative edge to leave the settled set, so nobody can beat $d(u)$ later.

#### Plugging the numbers

We’ll keep a tiny table each round. “S” means settled. Ties can be broken arbitrarily.

Start:

* Labels: $d(A)=0$; $d(B)=d(C)=d(D)=d(E)=\infty$
* Settled: $\varnothing$

Round 1
Pick min unsettled → $A$ (0). Settle $A$. Relax its neighbors.

* Update via $A$: $d(B)=2$, $d(C)=5$
* Labels now: $A:0\text{ (S)},\ B:2,\ C:5,\ D:\infty,\ E:\infty$

Round 2
Pick min unsettled → $B$ (2). Settle $B$. Relax neighbors of $B$.

* $C$ via $B$: $2+1=3 < 5$ → $d(C)=3$
* $D$ via $B$: $2+2=4$ → $d(D)=4$
* $E$ via $B$: $2+7=9$ → $d(E)=9$
* Labels: $A:0\text{ (S)},\ B:2\text{ (S)},\ C:3,\ D:4,\ E:9$

Round 3
Pick min unsettled → $C$ (3). Settle $C$. Relax neighbors of $C$.

* $D$ via $C$: $3+3=6$ (worse than 4) → no change
* $E$ via $C$: $3+1=4 < 9$ → $d(E)=4$
* Labels: $A:0\text{ (S)},\ B:2\text{ (S)},\ C:3\text{ (S)},\ D:4,\ E:4$

Round 4
Pick min unsettled → tie $D$ or $E$ at 4. Take $D$. Settle $D$. Relax neighbors.

* $E$ via $D$: $4+2=6$ (worse than 4) → no change
* Labels: $A:0\text{ (S)},\ B:2\text{ (S)},\ C:3\text{ (S)},\ D:4\text{ (S)},\ E:4$

Round 5
Pick $E$ (4). Settle $E$. No better updates. Done: all settled.

Final labels:

* $d(A)=0$
* $d(B)=2$
* $d(C)=3$
* $d(D)=4$
* $d(E)=4$

Recovering paths by remembering “who improved whom” gives:

* $B$ from $A$
* $C$ from $B$
* $D$ from $B$
* $E$ from $C$

Complexity

* Time: $O((V+E)\log V)$ with a binary heap (often written $O(E \log V)$ when $E\ge V$).
* Space: $O(V)$ for distances, parent pointers, and heap entries.

### Maximum contiguous sum

You’re given a list of numbers laid out in a line. You may pick one **contiguous** block, and you want that block’s sum to be as large as possible.

**Example inputs and outputs**

Take $x = [\,2,\,-3,\,4,\,-1,\,2,\,-5,\,3\,]$.

A best block is $[\,4,\,-1,\,2\,]$. Its sum is $5$.
So the correct output is “maximum sum $=5$” and one optimal segment is positions $3$ through $5$ (1-based).

Baseline (slow)

Try every possible block and keep the best total. To sum any block $i..j$ quickly, precompute **prefix sums** $S_0=0$ and $S_j=\sum_{k=1}^j x_k$. Then

$$
\sum_{k=i}^j x_k \;=\; S_j - S_{i-1}.
$$

Loop over all $j$ and all $i\le j$, compute $S_j-S_{i-1}$, and take the maximum. This is easy to reason about and always correct, but it does $O(n^2)$ block checks.

**How it works**

Walk left to right once and carry two simple numbers.

* $S$: the running prefix sum up to the current position.
* $M$: the **smallest** prefix seen so far (to the left of the current position).

At each step $j$, the best block **ending at** $j$ is “current prefix minus the smallest older prefix”:

$$
\text{best\_ending\_at\ }j \;=\; S_j - \min_{0\le t<j} S_t.
$$

So during the scan:

1. Update $S \leftarrow S + x_j$.
2. Update the answer with $S - M$.
3. Update $M \leftarrow \min(M, S)$.

This is the whole algorithm. In words: keep the lowest floor you’ve ever seen and measure how high you are above it now. If you dip to a new floor, remember it; if you rise, maybe you’ve set a new record.

A widely used equivalent form keeps a “best sum ending here” value $E$: set $E \leftarrow \max(x_j,\; E+x_j)$ and track a global maximum. It’s the same idea written incrementally: if the running sum ever hurts you, you “reset” and start fresh at the current element.

#### Work the example by hand

Sequence $x = [\,2,\,-3,\,4,\,-1,\,2,\,-5,\,3\,]$.
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
ground M: 0    0    -1   -1  -1  -1   -1  -1
gap S-M: 0    2     0    4   3   5    0   3
                             ^ peak gap = 5 here
```

#### Edge cases

When all numbers are negative, the best block is the **least negative single element**. The scan handles this automatically because $M$ keeps dropping with every step, so the maximum of $S_j-M$ happens when you take just the largest entry.

Empty-block conventions matter. If you define the answer to be strictly nonempty, initialize $\text{best}$ with $x_1$ and $E=x_1$ in the incremental form; if you allow empty blocks with sum $0$, initialize $\text{best}=0$ and $M=0$. Either way, the one-pass logic doesn’t change.

Summary

* Time: $O(n)$
* Space: $O(1)$

### Scheduling themes

Two everyday scheduling goals keep popping up. One tries to pack as many non-overlapping intervals as possible, like booking the most meetings in a single room. The other tries to keep lateness under control when jobs have deadlines, like finishing homework so the worst overrun is as small as possible. Both have crisp greedy rules, and both are easy to run by hand once you see them.

Imagine you have time intervals on a single line, and you can keep an interval only if it doesn’t overlap anything you already kept. The aim is to keep as many as possible.

**Example inputs and outputs**

Intervals (start, finish):

* $(1,3)$, $(2,5)$, $(4,7)$, $(6,9)$, $(8,10)$, $(9,11)$

A best answer keeps four intervals, for instance $(1,3),(4,7),(8,10),(10,11)$. I wrote $(10,11)$ for clarity even though the original end was $11$; think half-open $[s,e)$ if you want “touching” to be allowed.

Baseline (slow)

Try all subsets and keep the largest that has no overlaps. That’s conceptually simple and always correct, but it’s exponential in the number of intervals, which is a non-starter for anything but tiny inputs.

**How it works**

Sort by finishing time, then walk once from earliest finisher to latest. Keep an interval if its start is at least the end time of the last one you kept. Ending earlier leaves more room for the future, and that is the whole intuition.

Sorted by finish:

$$
(1,3),\ (2,5),\ (4,7),\ (6,9),\ (8,10),\ (9,11)
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

Kept intervals: $(1,3),(4,7),(8,10)$. If we allow a meeting that starts exactly at $10$, we can also keep $(10,11)$ if it exists. Four kept, which matches the claim.

A tiny picture helps the “finish early” idea feel natural:

```
time →
kept:   [1──3)      [4───7)        [8─10)
skip:      [2────5)    [6────9)        [9───11)
ending earlier leaves more open space to the right
```

Why this works in one sentence: at the first place an optimal schedule would choose a later-finishing interval, swapping in the earlier finisher cannot reduce what still fits afterward, so you can push the optimal schedule to match greedy without losing size.

Complexity

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

Baseline (slow)

Try all $n!$ orders, compute every job’s completion time and lateness, and take the order with the smallest $L_{\max}$. This explodes even for modest $n$.

**How it works**

Order jobs by nondecreasing deadlines (earliest due date first, often called EDD). Fixing any “inversion” where a later deadline comes before an earlier one can only help the maximum lateness, so sorting by deadlines is safe.

Deadlines in increasing order:

$$
J_2(d=1),\ J_4(d=2),\ J_1(d=3),\ J_3(d=4)
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

Why this works in one sentence: if two adjacent jobs are out of deadline order, swapping them never increases any completion time relative to its own deadline, and strictly improves at least one, so repeatedly fixing these inversions leads to the sorted-by-deadline order with no worse maximum lateness.

Complexity

* Time: $O(n \log n)$ to sort by deadlines; $O(n)$ evaluation.
* Space: $O(1)$.

### Huffman coding

You have symbols that occur with known frequencies $f_i>0$ and $\sum_i f_i=1$. The goal is to assign each symbol a binary codeword so that no codeword is a prefix of another (a prefix code), and the average length

$$
\mathbb{E}[L]=\sum_i f_i\,L_i
$$

is as small as possible. Prefix codes exactly correspond to full binary trees whose leaves are the symbols and whose leaf depths are the codeword lengths $L_i$. The Kraft inequality $\sum_i 2^{-L_i}\le 1$ is the feasibility condition; equality holds for full trees.

**Example inputs and outputs**

Frequencies:

$$
A:0.40,\quad B:0.20,\quad C:0.20,\quad D:0.10,\quad E:0.10.
$$

A valid optimal answer will be a prefix code with expected length as small as possible. We will compute the exact minimum and one optimal set of lengths $L_A,\dots,L_E$, plus a concrete codebook.

Baseline (slow)

One conceptual baseline is to enumerate all full binary trees with five labeled leaves and pick the one minimizing $\sum f_i\,L_i$. That is correct but explodes combinatorially as the number of symbols grows. A simpler but usually suboptimal baseline is to give every symbol the same length $\lceil \log_2 5\rceil=3$. That fixed-length code has $\mathbb{E}[L]=3$.

**How it works**

Huffman’s rule repeats one tiny step: always merge the two least frequent items. When you merge two “symbols” with weights $p$ and $q$, you create a parent of weight $p+q$. The act of merging adds exactly $p+q$ to the objective $\mathbb{E}[L]$ because every leaf inside those two subtrees becomes one level deeper. Summing over all merges yields the final cost:

$$
\mathbb{E}[L]=\sum_{\text{merges}} (p+q)=\sum_{\text{internal nodes}} \text{weight}.
$$

The greedy choice is safe because in an optimal tree the two deepest leaves must be siblings and must be the two least frequent symbols; otherwise swapping depths strictly reduces the cost by at least $f_{\text{heavy}}-f_{\text{light}}>0$. Collapsing those siblings into one pseudo-symbol reduces the problem size without changing optimality, so induction finishes the proof.

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

So the optimal expected length is $\boxed{\mathbb{E}[L]=2.20}$ bits per symbol. This already beats the naive fixed-length baseline $3$. It also matches the information-theoretic bound $H(f)\le \mathbb{E}[L]<H(f)+1$, since the entropy here is $H\approx 2.122$.

Now assign actual lengths. Record who merged with whom:

* Step 1 merges $D(0.10)$ and $E(0.10)$ → those two become siblings.
* Step 2 merges $B(0.20)$ and $C(0.20)$ → those two become siblings.
* Step 3 merges the pair $D\!E(0.20)$ with $A(0.40)$.
* Step 4 merges the pair from step 3 with the pair $B\!C(0.40)$.

Depths follow directly:

$$
L_A=2,\quad L_B=L_C=2,\quad L_D=L_E=3.
$$

Check the Kraft sum $3\cdot 2^{-2}+2\cdot 2^{-3}=3/4+1/4=1$ and the cost $0.4\cdot2+0.2\cdot2+0.2\cdot2+0.1\cdot3+0.1\cdot3=2.2$.

A tidy ASCII tree (weights shown for clarity):

```
                [1.00]
               /      \
           [0.60]     [0.40]=BC
           /    \        /   \
       [0.40]=A [0.20]=DE    B     C
                    /   \
                   D     E
```

One concrete codebook arises by reading left edges as 0 and right edges as 1:

* $A \mapsto 00$
* $B \mapsto 10$
* $C \mapsto 11$
* $D \mapsto 010$
* $E \mapsto 011$

You can verify the prefix property immediately and recompute $\mathbb{E}[L]$ from these lengths to get $2.20$ again.

Complexity

* Time: $O(k \log k)$ using a min-heap over $k$ symbol frequencies.
* Space: $O(k)$ for the heap and $O(k)$ for the resulting tree.

### When greedy fails (and how to quantify “not too bad”)

The $0\text{–}1$ knapsack with arbitrary weights defeats the obvious density-based rule. A small, dense item can block space needed for a medium-density item that pairs perfectly with a third, leading to a globally superior pack. Weighted interval scheduling similarly breaks the “earliest finish” rule; taking a long, heavy meeting can beat two short light ones that finish earlier.

Approximation guarantees rescue several hard problems with principled greedy performance. For set cover on a universe $U$ with $|U|=n$, the greedy rule that repeatedly picks the set covering the largest number of uncovered elements achieves an $H_n$ approximation:

$$
\text{cost}_{\text{greedy}} \le H_n\cdot \text{OPT},\qquad H_n=\sum_{k=1}^n \frac{1}{k}\le \ln n+1.
$$

A tight charging argument proves it: each time you cover new elements, charge them equally; no element is charged more than the harmonic sum relative to the optimum’s coverage.

Maximizing a nondecreasing submodular set function $f:2^E\to\mathbb{R}_{\ge 0}$ under a cardinality constraint $|S|\le k$ is a crown jewel. Submodularity means diminishing returns:

$$
A\subseteq B,\ x\notin B \ \Rightarrow\ f(A\cup\{x\})-f(A)\ \ge\ f(B\cup\{x\})-f(B).
$$

The greedy algorithm that adds the element with largest marginal gain at each step satisfies the celebrated bound

$$
f(S_k)\ \ge\ \Bigl(1-\frac{1}{e}\Bigr)\,f(S^\star),
$$

where $S^\star$ is an optimal size-$k$ set. The proof tracks the residual gap $g_i=f(S^\star)-f(S_i)$ and shows

$$
g_{i+1}\ \le\ \Bigl(1-\frac{1}{k}\Bigr)g_i,
$$

hence $g_k\le e^{-k/k}g_0=e^{-1}g_0$. Diminishing returns is exactly what makes the greedy increments add up to a constant-factor slice of the unreachable optimum.

