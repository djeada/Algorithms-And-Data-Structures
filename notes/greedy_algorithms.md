## Greedy algorithms

Greedy algorithms are the “make progress now” strategy: build a solution one step at a time, and at each step take the option that looks best *right now* according to a simple rule (highest value, earliest finish, smallest weight, smallest distance label, etc.). You keep the choice only if it doesn’t break the problem’s rules.

The story you should keep in your head is: **greedy is fast because it refuses to look ahead**, but that means it earns its correctness only when you can prove that local choices are *safe*. The fun part is that the *proof patterns* repeat across problems, so once you learn the toolkit, new greedy problems stop feeling like magic tricks and start feeling like “apply the template.”

**The general pattern:**

1. Sort by your rule (the “key”).
2. Scan items in that order.
3. If adding this item keeps the partial answer valid, keep it.
4. Otherwise skip it.

Picking the best “now” doesn’t obviously give the best “overall.” **Greedy isn’t magic; you must prove the choice is safe.** The real work is showing that these local choices still lead to a globally best answer.

A good do/don’t to internalize right away:

* **Do** write down the constraint you must never violate (your *feasibility invariant*).
* **Don’t** trust a greedy rule until you can justify it with a reusable proof pattern.

### The Greedy Proof Toolkit

This section is your reusable toolbox. The goal is to stop re-inventing proofs from scratch: the same 2–3 ideas show up again and again, just wearing different costumes.

#### The Universal Greedy Checklist

For every greedy algorithm, answer these five questions:

1. **Greedy choice**: What local choice do we make at each step?
2. **Feasibility**: What constraint must always remain true? (the invariant)
3. **Why safe**: Why does this choice never hurt optimality?
4. **Implementation**: What data structure makes the choice fast?
5. **Complexity**: What dominates runtime?

Why you should care: if you can’t fill in #3, you don’t have an algorithm yet, you have a hopeful heuristic. The checklist is your “am I actually done?” filter.

#### Exchange Argument Template

The exchange argument is the workhorse of greedy correctness proofs. It’s the “I can transform any optimal solution into greedy without paying more” trick.

Generic template:

1. Take any optimal solution **OPT** that disagrees with greedy **G** at the first position.
2. Show you can swap in the greedy choice at that position without making the solution worse or breaking feasibility.
3. The modified solution is still optimal and now agrees with greedy for one more position.
4. Repeat until **OPT** becomes **G** → greedy is optimal.

*Picture it like this:*

```
position →   0    1    2    3    4
greedy:     [✓]  [✗]  [✓]  [✓]  [✗]
some optimal:
             ✓    ✓    ✗    ?    ?
First mismatch at position 2 → swap in greedy's pick without harm.
Repeat until both rows match → greedy is optimal.
```

Do/don’t: **do** look for the *first* disagreement (it keeps the swap localized), and **don’t** try to “compare whole solutions at once”, you usually only need one clean swap.

#### Loop Invariant Template

Sometimes it’s easier to prove that your partial solution is “the best possible so far,” iteration by iteration.

Template:

1. **State the invariant**: a sentence true after every iteration.
2. **Initialization**: show it holds before the loop starts.
3. **Maintenance**: show one iteration preserves it.
4. **Termination**: show the invariant implies optimality when the loop ends.

This is especially nice when greedy isn’t “choose and lock forever,” but “maintain a best frontier/label” (reachability scans, shortest paths, etc.).

#### Cut and Cycle Rules (Graph Specializations)

For graph problems, exchange arguments often become two famous “rules”:

* **Cut rule (safe to add)**: For any partition $(S, V\setminus S)$, the cheapest edge crossing that cut can safely be included in an MST.
* **Cycle rule (safe to skip)**: In any cycle, the most expensive edge is never in an MST.

These are exchange arguments with graph language. The cut rule says “swapping in the cheapest crossing edge can’t hurt,” and the cycle rule says “dropping the heaviest edge in a cycle can’t hurt.”

### Examples Grouped by Pattern

Each example follows the same structure: **Problem → Greedy rule → Algorithm → Proof sketch → Complexity → Edge cases**.

That structure is not cosmetic. It’s the point: if you can tell the story cleanly, you understand the algorithm, and you can re-derive it under pressure.

#### Reachability on a line

**Pattern**: Frontier/Reachability Greedy

This pattern is the “don’t overthink it” cousin of graph reachability. Instead of tracking *every* reachable square, you track a *frontier*: the furthest place your current knowledge guarantees you can get to. The *do* is: compress lots of reachability facts into one summary number. The *don’t* is: simulate every jump or mark every square repeatedly when you only need to know how far the wave has pushed.

```
Mental model: a growing flashlight beam

0 1 2 3 4 5 6 7 ...
^ start
[=======]  <- everything up to F is "lit" (reachable)
```

**Problem**

* You stand at square $0$ on squares $0,1,\ldots,n-1$.
* Each square $i$ has jump power $a[i]$. From $i$ you may land on any of $i+1,i+2,\dots,i+a[i]$.
* Goal: decide if you can reach $n-1$; if not, report the furthest reachable square.

Why this matters: it’s the simplest form of “can I keep progressing?” problems (game levels, packet routing along hops, scheduling with ranges). The *do* is: treat each `a[i]` as “potential energy” you can spend once you actually reach `i`. The *don’t* is: assume a large jump power somewhere helps unless you can *get there*.

```
Key gotcha:

Big power at 10 is useless if you get stuck at 6.

0 ... 6 7 8 9 10
      X gap      (a[10] = 100 doesn't matter)
```

**Example**

Input: $a=[3,1,0,0,4,1]$, so $n=6$.

This example is perfect because it contains both “early progress” and a “dead zone.” It forces the algorithm to prove it can detect getting stuck without backtracking. The *do* is: watch for the first index that lies beyond your frontier. That’s the exact moment the game ends.

```
indices:  0   1   2   3   4   5
a[i]   :  3   1   0   0   4   1
reach  :  ^ start at 0
```

From any $i$, the allowed landings are a range:

```
i=0 (a[0]=3): 1..3
i=1 (a[1]=1): 2
i=2 (a[2]=0): , 
i=3 (a[3]=0): , 
i=4 (a[4]=4): 5..8 (board ends at 5)
```

Notice the drama: square 4 has huge power, but squares 2 and 3 are “dead” (power 0). If you can’t reach 4, that big number is just decoration. That’s exactly why the greedy “frontier” viewpoint is the right abstraction.

```
Visualizing the trap:

0 can reach -> 1,2,3
1 can reach -> 2
2 can reach -> nowhere
3 can reach -> nowhere

So if frontier never reaches 4, you're done.
```

**Baseline idea**

“Paint everything reachable, one wave at a time.”

1. Start with ${0}$ reachable.
2. For each already-reachable $i$, add all $i+1 \ldots i+a[i]$.
3. Stop when nothing new appears.

Correct, but it can reprocess many squares.

This is a classic “why greedy exists” moment: the baseline is correct but wasteful because it keeps rediscovering the same reachability facts. Greedy will compress “everything I’ve learned so far” into one number.

The baseline is basically a slow-motion flood fill. It’s conceptually comforting because it mirrors how you’d explain reachability to a human: “from here I can go there, and from there I can go…” But it’s also the classic performance mistake: you keep scanning regions you already know are reachable. The *do* is: steal the baseline’s correctness idea, then compress it. The *don’t* is: keep “painting” when the only question is “how far can the paint possibly spread?”

```
Baseline flood (inefficient):

Round 1: reach {0}
Round 2: add {1,2,3}
Round 3: from 1 add {2} (already known)
Round 4: from 2 add {} ...
... lots of re-checking for no new info
```

**Greedy rule**

Carry one number while scanning left→right: the furthest frontier $F$ seen so far.

Why one number is enough: on a line, if you know you can reach everything up to `F`, then you’ve implicitly learned *all* the starting points that matter for future jumps. Every index ≤ F is a possible launchpad. So instead of tracking them individually, you treat them as a single “reachable prefix.” The *do* is: think “reachable prefix length.” The *don’t* is: store per-square reachability unless you’re asked for paths or counts.

Rules:

* If you are at $i$ with $i>F$, you hit a gap → stuck forever.
* Otherwise extend $F\leftarrow \max(F,i+a[i])$ and continue.

This “gap” rule is the entire punchline. If you arrive at an index you can’t even stand on, then nothing to the right can be reached either, because all jumps move forward, and you’ve already accounted for all possible forward reach from all reachable places. The *do* is: stop immediately on the first gap. The *don’t* is: keep scanning hoping a later jump fixes it (it can’t).

```
Gap logic (why stopping is correct):

reachable prefix = [0..F]

If i = F+1, then i is outside the prefix.
No reachable square can land on i, otherwise i would be ≤ F.
So nothing beyond i can be reached either.
```

At the end:

* Can reach last iff $F\ge n-1$.
* Furthest reachable square is $F$ (capped by $n-1$).

This gives you both answers “for free”: a yes/no (did we cover the last index?) and a diagnostic (how far did we get before the road ended?). The *do* is: return both in interviews / debugging, “no, and here’s where it fails.” The *don’t* is: just return false and throw away the useful boundary.

**Algorithm**

```
F = 0
for i in 0..n-1:
    if i > F: break
    F = max(F, i + a[i])

can_reach_last = (F >= n-1)
furthest = min(F, n-1)
```

What makes this feel “human” is that it matches how you’d actually play: you keep walking forward as long as you’re within what you already know you can reach, and every time you land somewhere with jump power, you update your best possible future. The *do* is: read it like “keep upgrading my maximum reach.” The *don’t* is: interpret it as “I must jump at every square”, you’re not choosing a specific jump sequence; you’re summarizing all possible sequences.

```
Frontier evolution on the example a=[3,1,0,0,4,1]

Start: F=0

i=0 <=F: F=max(0,0+3)=3
i=1 <=F: F=max(3,1+1)=3
i=2 <=F: F=max(3,2+0)=3
i=3 <=F: F=max(3,3+0)=3
i=4 > F  -> GAP -> stop

Result: furthest reachable = 3 (can't reach 5)
```

**Proof sketch**

Loop invariant: “After processing index $i$, $F$ equals the furthest position reachable using jumps that start at some truly reachable square $\le i$.”

This invariant is doing a lot of work, and it’s worth appreciating why it’s phrased that way: you’re only allowed to use jump power from squares you can actually reach, and you’re only considering launch points up to the current scan index. That matches the algorithm’s left-to-right processing. The *do* is: tie the invariant to what the loop has “seen.” The *don’t* is: claim $F$ is “furthest reachable overall” mid-loop; it’s “furthest reachable given processed launchpads.”

* Initialization: $F=0$ is correct at the start.
* Maintenance: if $i\le F$, then $i$ is reachable, so $i+a[i]$ is a valid new reach and updating $F$ is safe.
* If $i>F$, no earlier reachable square can jump to $i$ (all such reach was already summarized in $F$), so stopping is correct.
* Termination: the final $F$ is exactly the furthest reachable position.

A nice way to visualize the proof is to imagine the scan as “unlocking” jump powers. You can only use `a[i]` after you confirm `i` is inside the unlocked zone (`i ≤ F`). Every time you unlock a square, you possibly expand the unlocked zone. If you ever encounter a locked square (`i > F`), the unlocking process cannot continue.

```
Invariant picture:

Processed launchpads: 0..i
Reachable prefix:     0..F

We only expand F using launchpads that lie inside 0..F.
If i steps beyond F, we found the first unreachable launchpad.
Forward-only jumps => no future square can fix that.
```

**Complexity**: time $O(n)$, space $O(1)$.

This is the reward for choosing the right summary statistic. Instead of simulating many possibilities, you scan once and keep one frontier value. The *do* is: recognize this as “linear scan with a running max.” The *don’t* is: accidentally reintroduce extra work (nested loops) when implementing.

**Edge cases**

* If $n=1$, you’re already at the goal.
* If many $a[i]=0$, the scan correctly stops at the first gap.

These edge cases are basically the algorithm’s personality check. For `n=1`, the frontier starts at the goal. For many zeros, you quickly find where progress ends, and you stop without wasted work. The *do* is: handle `n=1` cleanly. The *don’t* is: try to “jump from nowhere” past a gap, forward-only movement makes gaps final.

```
Zeros create cliffs:

a = [2,0,0,0,...]
i=0 => F=2
i=1 ok
i=2 ok
i=3 => i>F => stop at 2

Cliff detected exactly where it should be.
```

#### Minimum spanning trees

**Pattern**: Cut-Based Greedy on Graphs

Before we even touch the algorithms, it helps to picture the “job” an MST is doing: you want *all* the vertices connected, you want to spend as little total weight as possible, and you’re not allowed to waste edges making loops. This shows up everywhere, laying fiber between cities, wiring circuits on a board, connecting servers in a data center, clustering points in ML, any time “connect everything cheaply” matters. The *do* here is: think “infrastructure budget.” The *don’t* is: treat it like a random graph puzzle; it’s really about spending weight efficiently.

```
Goal (MST): connect all nodes, no cycles, minimum total cost

   A---(3)---B
   | \       |
 (2) (6)   (4)
   |     \   |
   C---(5)---D

Bad: has a cycle (extra spend)
Good: just enough edges to connect all nodes (|V|-1 edges)
```

**Problem**

Given a connected, undirected, weighted graph, connect all vertices with minimum total edge weight without cycles: an MST.

A useful way to “feel” this constraint is: a tree with `|V|` vertices always has exactly `|V|-1` edges. So if you ever add an edge that creates a cycle, you’ve basically bought an unnecessary cable. The *do* is: keep asking “does this edge actually help me reach a new vertex/component?” The *don’t* is: add edges just because they look cheap, cheap and *useful* is what matters.

```
Why cycles are waste (intuition)

Cycle: A--B
       |  |
       D--C

You can remove the heaviest edge on the cycle
and still keep everything connected.
So that heaviest edge was never necessary.
```

**Baseline**

Enumerate all spanning trees and pick the lightest, correct but combinatorially impossible for real graphs. This baseline is important conceptually: it reminds you what “optimal” even means, and it highlights why a greedy shortcut is valuable.

This is the “brute-force North Star.” It’s the version you’d run if graphs were tiny and time was infinite. The *do* is: keep it in your head as the definition of correctness (“we’re trying to match what brute force would choose”). The *don’t* is: ever implement it outside of toy examples, its only real job is to motivate why we need smarter structure.

```
Brute-force vs. greedy (scale intuition)

# of spanning trees can explode fast.

Tiny graph: feasible
Real graph: "nope"

Greedy works because we can prove certain choices are "safe".
```

**Two facts that power the greedy proofs**

* Cut rule (safe to add)
* Cycle rule (safe to skip)

These are the “why safe” pieces that let greedy commit early without regret.

These two rules are the emotional support system for greedy algorithms. Greedy is scary because it “locks in” choices without seeing the future, but MST is one of the lucky problems where we can prove some choices can’t hurt. The *do* is: when you read a proof, hunt for “cut” or “cycle” language. The *don’t* is: memorize steps without internalizing what makes them safe; the rules are the whole reason the algorithms work.

```
Cut rule (picture a cut)

   [  Left side  ]  |cut|  [  Right side  ]

A ----(lightest crossing edge)---- B

If an edge is the lightest crossing SOME cut,
it is safe to include in an MST.
```

```
Cycle rule (picture a cycle)

A --(2)-- B
|         |
(5)     (3)
|         |
D --(4)-- C

Heaviest edge on the cycle is safe to skip.
(Here: weight 5)
```

#### Kruskal’s method

Kruskal feels like “shopping with a strict budget.” You walk through edges from cheapest to priciest, and you only buy an edge if it doesn’t create a loop. The algorithm is simple; the magic is that the *rules above* guarantee you’re not painting yourself into a corner. The *do* is: think “merge components.” The *don’t* is: think “build one expanding blob” (that’s Prim).

**Greedy rule**

Sort edges by weight. Scan from lightest to heaviest and keep an edge if it connects two different components (i.e., doesn’t form a cycle). Stop when you have $|V|-1$ edges.

The “two different components” test is the entire game. Early on, every vertex is its own component; every accepted edge fuses two components into a bigger one. The *do* is: visualize components as islands and edges as bridges. The *don’t* is: accept a bridge that starts and ends on the same island, congrats, you just paid for a scenic loop.

```
Kruskal = "connect islands cheaply"

Start: {A} {B} {C} {D}

Pick smallest edges that connect DIFFERENT sets:

{A}-{C}   => {AC} {B} {D}
{B}-{D}   => {AC} {BD}
{C}-{D}   => {ACBD}   (done)
```

**Implementation idea**

Use a disjoint-set union-find structure to test whether two vertices are already connected.

Union-find is basically your “island tracker.” It answers: “Are u and v already in the same component?” quickly, and if not, it merges them. The *do* is: rely on union-find for speed. The *don’t* is: do connectivity checks with full graph searches per edge, you’ll turn a fast algorithm into a slow one.

```
Union-Find (DSU) mental model

find(x) -> returns component representative
union(a,b) -> merges components

If find(u) == find(v): adding (u,v) makes a cycle -> skip
Else: safe to add -> union(u,v)
```

**Proof sketch**

* If an edge would create a cycle, the cycle rule says it’s safe to skip.
* If an edge is the lightest that connects two components, it is the lightest crossing edge of some cut, and the cut rule says it’s safe to include.
* Exchange argument: transform any optimal MST to include Kruskal’s chosen edge without increasing weight.

Here’s the flow that makes this proof feel human: every time Kruskal picks an edge, it’s either (a) obviously wasteful (it would create a cycle) so you skip it, or (b) it’s the cheapest way to connect two currently-separated groups, meaning it’s the cheapest edge crossing the cut between those groups. The exchange argument is the “no hard feelings” clause: even if the optimal MST you imagined didn’t include your chosen edge, you can swap edges and not increase cost. The *do* is: connect each bullet to either “cut” or “cycle.” The *don’t* is: treat “exchange argument” like a spell, see it as a controlled swap that keeps the tree valid and not heavier.

```
Exchange argument (tiny sketch)

Your MST:      Kruskal wants:

... X ---- Y   add edge e = (U,V)

If e not in MST, adding e creates a cycle.
Remove the heaviest edge on that cycle (call it f).
Result is still a spanning tree and no heavier.
So you can "exchange" f for e safely.
```

**Complexity**

* Sorting: $O(E\log E)$ (often written $O(E\log V)$).
* Union-find operations: near-constant amortized ($\alpha(V)$).
* Space: $O(V)$.

Interpretation: most of the time is spent sorting edges; union-find is the lightweight bouncer at the club door. The *do* is: remember “sort dominates.” The *don’t* is: overthink $\alpha(V)$, it’s effectively constant for any practical input size.

**Edge cases**

* Disconnected graph → minimum spanning forest.
* Ties are fine: multiple MSTs may exist with the same total weight.

Practical takeaway: in real data, disconnection is common (clusters, communities, separated regions). Kruskal doesn’t panic; it just builds one MST per connected component. And if weights tie, the graph is basically saying “you have multiple equally good designs.” The *do* is: accept that MST may not be unique. The *don’t* is: expect identical edge sets across runs if tie-breaking differs.

```
Disconnected -> forest

Component 1: A--B--C     MST1
Component 2: D--E        MST2

Output = {MST1, MST2}
```

#### Prim’s method

Prim feels like “growing a single organism.” You start from one vertex and keep attaching the cheapest edge that reaches something new. If Kruskal is “merge islands everywhere,” Prim is “expand one territory.” The *do* is: think “frontier/boundary.” The *don’t* is: think “global cheapest edge anywhere” (that’s Kruskal’s vibe).

**Greedy rule**

Grow one tree: repeatedly add the lightest edge leaving the current tree to bring in a new vertex.

This “leaving the current tree” phrase is the key limiter that makes Prim different: you’re only allowed to choose edges that cross from inside to outside. The *do* is: picture a boundary fence around your current tree. The *don’t* is: pick an edge fully outside the tree (even if it’s super cheap), because it doesn’t help your current structure grow.

```
Prim boundary picture

Tree (inside) vs Outside:

   inside nodes:  {A, C}
   outside nodes: {B, D, E}

Only consider edges that cross the boundary:
  A--B, C--D, A--E, ...

Pick the cheapest crossing edge, add that outside vertex.
```

**Implementation idea**

Use a min-heap (priority queue) keyed by the cheapest “boundary edge” to each outside vertex.

The heap is your “best next deal” list: for every outside vertex, keep track of the cheapest known edge that would bring it into the tree. The *do* is: update keys when you find a cheaper connection. The *don’t* is: try to keep the heap perfectly clean at all times, real implementations often allow duplicates and ignore stale entries later.

```
Min-heap idea (keys = best known connection cost)

Outside vertex : best edge weight so far
B : 3
D : 4
E : 2   <-- pop this next

When you add E, you may discover:
D can be reached with weight 1 instead of 4 -> decrease-key (or push new entry)
```

**Proof sketch**

At every step, Prim picks the lightest edge crossing the cut (tree vs. outside). By the cut rule, that edge belongs to some MST, so committing to it is safe.

This proof is basically one clean sentence: Prim always picks the lightest edge crossing the specific cut “current tree vs. everything else,” and the cut rule says that’s safe. The *do* is: explicitly name the cut each step. The *don’t* is: get lost in implementation details (heap, adjacency lists) when you’re trying to understand correctness.

```
Prim correctness in one diagram

Current tree T        Outside V\T

   [   T   ]  --e*--   [ outside ]

e* = lightest edge crossing this cut
Cut rule => e* is safe => you can keep growing.
```

**Complexity**

* Binary heap + adjacency lists: $O(E\log V)$.
* Space: $O(V)$ plus adjacency representation.

Meaning: every edge might cause a heap update-ish operation, and the heap costs log V per meaningful push/pop. The *do* is: use adjacency lists (especially for sparse graphs). The *don’t* is: use an adjacency matrix for huge sparse graphs unless you really mean it.

**Edge cases**

* Start vertex doesn’t affect total MST weight (though the chosen edges may differ).
* Heaps may contain stale entries; skip when popped.

If you start at a different node, you may build a different-looking MST but with the same optimal total weight (assuming ties/structure allow multiple). And if your heap has outdated offers, just ignore them when you notice they no longer match the best-known state. The *do* is: code defensively with a visited set / current best key checks. The *don’t* is: assume the heap always reflects the current truth without verification.

#### Shortest paths with non-negative weights (Dijkstra)

**Pattern**: Cut-Based Greedy on Graphs

Dijkstra is the “no regrets” version of shortest paths: you keep a boundary between what you *know for sure* and what you’re still *guessing*, and you repeatedly promote the safest-looking guess into certainty. The whole reason this works is non-negativity, roads don’t give you refunds. The *do* is: treat the algorithm as expanding a region of confirmed shortest distances. The *don’t* is: use it when edges can be negative; a negative edge is exactly the kind of “refund detour” that breaks the safety logic.

```
Two-zone view:

Settled (final)      Unsettled (tentative)
[  correct dist  ] | [  maybe smaller later  ]

Dijkstra repeatedly moves the boundary rightward:
it "locks in" one node at a time.
```

**Problem**

From a start node $s$, compute shortest distances $d(\cdot)$ to all nodes (and routes via parents). Edge weights must be non-negative.

Why you should care: shortest paths is the backbone of routing, navigation, dependency planning, game AI, and “minimum cost to reach X” problems. The output isn’t just numbers, it’s also *parents* (how you actually get there). The *do* is: maintain both distance and predecessor for reconstruction. The *don’t* is: only compute distances and then wonder how to produce the path later.

```
Distances + parents => path reconstruction

parent[v] = u means: best-known path to v ends with edge u->v

To reconstruct s -> t:
t <- parent[t] <- parent[parent[t]] <- ... <- s
(reverse it)
```

**Baseline**

Bellman–Ford-style repeated relaxation: about $O(|V||E|)$. It handles negatives; Dijkstra doesn’t need that generality, so greedy buys speed.

The baseline is “keep trying to improve everyone until nothing changes.” It’s powerful because it works even with negative edges, but it spends time rechecking improvements that can’t possibly matter when all edges are non-negative. Greedy says: “instead of endlessly revisiting, let’s *finalize* nodes when we’re sure.” The *do* is: see Dijkstra as a faster specialization of relaxation. The *don’t* is: forget that Bellman–Ford exists when negatives appear.

```
Relaxation idea (shared by both):

If d[u] + w(u,v) < d[v], then update d[v].

Difference:
- Bellman-Ford repeats relaxations many rounds.
- Dijkstra chooses an order that makes some nodes final early.
```

**Greedy rule: “settle the smallest label”**

Repeatedly pick the unsettled node $u$ with smallest tentative distance $d(u)$ and **settle** it (declare its distance final).

“Settle” is the key word: once settled, a node never changes again. That’s the greedy commitment. The *do* is: interpret “smallest label” as “closest frontier point.” The *don’t* is: settle nodes in arbitrary order; the safety proof depends on always picking the minimum tentative distance next.

```
Label-setting picture:

d[ ] = current best-known distances

Unsettled nodes have labels like:
A: 7   B: 3   C: 11   D: 5

Pick the smallest (B:3), settle it, relax its outgoing edges.
```

**Why safe**

With non-negative weights, any path to $u$ that detours through other unsettled nodes can only add non-negative cost, so it cannot beat the current smallest label.

This is the intuition that makes the algorithm feel “obviously right”: if `u` is currently the cheapest unsettled node, then going from `s` to some other unsettled node `x` (which is already ≥ `d(u)`) and then traveling more edges to reach `u` can’t magically become cheaper, because those extra edges can’t subtract cost. The *do* is: remember “detours only add.” The *don’t* is: forget that a single negative edge is enough to make a detour beneficial.

```
Why non-negative matters:

If all edges >= 0, then detour cost >= 0.

So if u is the cheapest tentative node,
any route that reaches u via another unsettled node
must be >= that other node's tentative distance >= d[u].

No detour can undercut d[u].
```

**Proof sketch**

Loop invariant: “All settled nodes have correct shortest-path distances.”

The invariant is your safety harness: we’re gradually building a set `S` of nodes whose distances are finalized and correct. Each step must preserve that truth. The *do* is: keep the invariant in mind while reading the algorithm. The *don’t* is: think Dijkstra is “just BFS with weights”, the correctness comes from this settle-min step plus non-negativity.

* Initialization: $d(s)=0$ is correct.
* Maintenance: settling the minimum-label node is safe by non-negativity.
* Termination: when all reachable nodes are settled, distances are correct.

A cut-based way to picture the maintenance step:

* Let `S` be settled nodes, `V \ S` unsettled.
* Dijkstra chooses `u` in `V \ S` with minimum `d(u)`.
* Any path to an unsettled node must cross the cut at some edge out of `S`.
* `d(u)` is already the best possible among those, so it’s final.

```
Cut view:

S (settled)             V\S (unsettled)
[ s, ..., ]  |cut|  [ u, v, w, ... ]

All known best routes to outside go through this boundary.
Pick the smallest boundary-reachable node u, lock it in.
```

**Complexity**

* With binary heap: $O((V+E)\log V)$.
* Space: $O(V)$.

Heap intuition: you need a fast way to repeatedly extract the smallest tentative label and to push improved distances. The *do* is: use a priority queue keyed by `d`. The *don’t* is: linearly scan for the minimum each time unless `V` is tiny.

```
What the heap is doing:

push (0, s)
repeat:
  pop smallest (dist, u)
  if u already settled: continue
  settle u
  for each edge (u,v,w):
      if dist + w < d[v]:
          d[v] = dist + w
          parent[v] = u
          push (d[v], v)
```

**Edge cases**

* Unreachable nodes remain at $\infty$.
* Stale heap entries occur; skip if already settled.

Unreachable nodes are not a failure, they’re a real output: “there is no path from s.” Stale heap entries happen because many implementations push a new `(betterDist, v)` instead of decreasing-key in place; later, the old worse entry resurfaces and must be ignored. The *do* is: keep a settled/visited check. The *don’t* is: assume every pop is “the one true current distance.”

```
Stale entry example:

Heap contains:
(10, v)   <- old
(6,  v)   <- newer, better

Pop (6, v): settle v
Later pop (10, v): v already settled -> skip
```

#### Scheduling themes

**Pattern**: Scheduling Greedy

Scheduling is greedy-friendly because “what you do early” shapes what’s possible later, and the proofs often boil down to a clean exchange: “finishing earlier leaves more room.”

That “leaves more room” line is the whole vibe of scheduling proofs. Time is a one-way resource: once you waste a slot early, you can’t buy it back later. So greedy strategies that **protect future flexibility** often win. The *do* is: look for a simple local choice that maximizes options later (earliest finish, earliest due date). The *don’t* is: get distracted by “what feels urgent” unless the objective matches that urgency.

```
Scheduling = packing into time

Time ---------------------------------------------------->

Every choice consumes a chunk.
Good greedy choices keep the remaining timeline usable.
```

#### Interval scheduling (maximum number of non-overlapping intervals)

This is the “fit as many meetings as possible” problem. The trick is realizing the objective is **count**, not total duration, not value, not “use time efficiently.” If you’re maximizing *how many*, then short/early-finishing intervals are gold because they leave space for more. The *do* is: optimize for free time after each pick. The *don’t* is: pick the earliest-starting interval (that’s a classic wrong greedy).

**Baseline**

Try all subsets → exponential.

The baseline is “check every combination of meetings and see which one works.” It’s correct but useless at scale, and it hides the structure: feasibility depends on *ordering* in time, not arbitrary set selection. The *do* is: use it to define correctness (“maximum number”). The *don’t* is: keep thinking in subsets once you see time order exists.

```
Why subsets explode:

Intervals: n
Subsets:   2^n

Even n=50 is astronomical.
```

**Greedy rule**

Sort by finish time, take the next interval that starts after the last chosen ends.

This is the “always finish as early as possible” strategy. It’s not about being fast for its own sake, it’s about keeping the remaining timeline as wide as possible for future intervals. The *do* is: treat the finish time as the critical decision point. The *don’t* is: prioritize long intervals or early starts; those can block many later choices.

```
Wrong greedy (earliest start) can fail:

A: [1---------10]
B: [2-3]
C:   [3-4]
D:     [4-5]
E:       [5-6]
F:         [6-7]
G:           [7-8]
H:             [8-9]

Earliest start picks A -> total 1
Earliest finish picks B,C,D,E,F,G,H -> total 7
```

**Proof sketch**

Exchange argument: if an optimal schedule picks an interval that finishes later than the earliest-finishing compatible interval, swap it out. You don’t reduce how many intervals fit afterward because you only *free up* time.

Here’s the “human” version of the exchange: suppose you and I both have a schedule, and at some step you picked a meeting that ends at 5pm, but there was another compatible meeting that ends at 3pm. If we swap yours for the 3pm one, everything after 5pm is still available, and now *more* time is available between 3pm and 5pm too. So swapping cannot make your future worse; it can only keep it the same or improve it. The *do* is: focus on the first decision where two schedules differ. The *don’t* is: try to prove it by complex induction before you see the simple “end earlier can’t hurt” fact.

```
Exchange picture:

Your chosen interval:     [---X---] ends late
Greedy candidate:         [--G--]   ends earlier

Timeline:  ----|----|----|----|---->
                     G end   X end

Anything that starts after X end also starts after G end.
So replacing X with G keeps all later options.
```

**Complexity**: $O(n\log n)$ sort + $O(n)$ scan.

Most work is sorting once. The scan is just “take it if it fits.” The *do* is: implement as sort-by-end then one pass. The *don’t* is: repeatedly search for the next interval in an inner loop.

**Edge cases**

* If everything overlaps, you keep 1.
* Equal finish times can be broken arbitrarily.

Equal finish times don’t change the “free up time” logic, finishing at the same time leaves the same future. The *do* is: treat ties as harmless. The *don’t* is: overfit tie-breaking rules unless you need reproducibility.

#### Minimize the maximum lateness (unit-time jobs)

Define lateness for job $i$ as $L_i=C_i-d_i$ and objective $L_{\max}=\max_i L_i$.

This problem is subtle because it’s not “meet all deadlines” (sometimes you can’t). It’s “if someone is late, make the worst lateness as small as possible.” So fairness matters: you’re trying to prevent one job from being *catastrophically* late. The *do* is: think “minimize the worst-case pain.” The *don’t* is: optimize average lateness; that’s a different objective.

```
Unit-time jobs = each job takes 1 slot:

Slots: 1 2 3 4 5 ...
Pick an order, jobs fill slots in that order.

Completion time C_i = slot index when job finishes.
Lateness L_i = C_i - d_i
Goal: minimize max lateness across all jobs.
```

**Baseline**

Try all $n!$ orders → impossible.

The baseline here is “try every permutation.” It screams that what matters is the order, and that we need a rule to choose an order without exploring all of them. The *do* is: acknowledge scheduling is about permutations. The *don’t* is: brute-force except for tiny `n`.

**Greedy rule (EDD)**

Sort jobs by nondecreasing deadlines (Earliest Due Date first).

EDD is the “protect the earliest deadline from getting pushed back” strategy. If a job is due sooner, delaying it tends to create large lateness spikes. Putting it earlier is like paying the urgent bills first so your “overdue penalty” doesn’t explode. The *do* is: sort by `d_i`. The *don’t* is: sort by shortest job first here, processing times are all equal, so that idea is irrelevant.

```
EDD visual:

Deadlines:  d=2  d=5  d=5  d=9  d=10
Order:      earliest deadline jobs first
```

**Proof sketch**

Exchange argument on inversions: if two adjacent jobs are out of deadline order, swapping them cannot increase $L_{\max}$, and it improves (or preserves) the lateness of the earlier-deadline job. Repeatedly remove inversions → sorted order is optimal.

The “why” is very local: consider two adjacent jobs `A` then `B` where `d_A > d_B` (they’re inverted). Since both take one unit time, the pair occupies the same two slots either way, swapping only changes *which job gets the earlier slot*. Giving the earlier slot to the earlier deadline is never worse for the maximum lateness. So you bubble-sort away inversions without harming the objective, ending at EDD. The *do* is: zoom in on a two-job swap. The *don’t* is: attempt a global argument without this local swap lens.

```
Inversion swap diagram (unit time)

Current order:  A then B   with d_A > d_B
Slots:          t     t+1

Case 1: A then B
C_A = t
C_B = t+1
L_A = t - d_A
L_B = (t+1) - d_B

Case 2: B then A
C_B = t
C_A = t+1
L_B' = t - d_B        (improves, since earlier completion for earlier deadline)
L_A' = (t+1) - d_A    (may worsen by 1)

Key: the job with the tighter deadline stops being punished.
Max lateness cannot increase by doing the swap.
```

**Complexity**: $O(n\log n)$.

Again: sort once, then schedule in that order. The *do* is: implement as sort-by-deadline then compute completion times. The *don’t* is: simulate with complicated data structures when unit-time makes it simple.

**Edge cases**

* Same deadlines → any order ties.
* Different processing times $p_j$ requires a different model/algorithm.

EDD is optimal for **unit-time** jobs (or more generally, for minimizing maximum lateness on a single machine even with varying processing times under classic results, but the proof and model shift). Your note is a good guardrail: if job lengths differ, you must be precise about which theorem/problem variant you’re in. The *do* is: check assumptions (unit time? single machine? no release times?). The *don’t* is: apply EDD blindly when the model changes.

```
Model checklist:

- single machine?
- all jobs available at time 0?
- unit processing times?
- objective is L_max (max lateness), not #on-time?

If any change: re-evaluate the greedy rule.
```

#### Huffman coding

**Pattern**: Merge-the-Two-Smallest Greedy

Huffman coding is what happens when you take “be efficient” seriously: frequent symbols should be quick to write, rare symbols can be longer, and **prefix-free** means decoding is unambiguous (you never get stuck wondering where one codeword ends). The *do* is: think “short for common, long for rare.” The *don’t* is: chase clever-looking bitstrings by hand, this is a tree problem wearing a binary hat.

```
Prefix-free means: no codeword is the prefix of another

Good:
A: 0
B: 10
C: 110
D: 111

Bad (ambiguous):
A: 0
B: 01   <- "0" is a prefix of "01"
```

**Problem**

Given symbol frequencies $f_i>0$ with $\sum_i f_i=1$, find a prefix code minimizing average length:

$$
\mathbb{E}[L]=\sum_i f_i L_i.
$$

The “why care” is baked into the formula: every extra bit on a high-frequency symbol costs you a lot, while extra bits on a rare symbol barely move the needle. Huffman is the clean, provably optimal way to trade length against frequency under the prefix constraint. The *do* is: keep seeing the objective as “weighted depth in a tree.” The *don’t* is: treat it like arithmetic on bitstrings; the tree is the real object.

```
Code tree view:

Each symbol = a leaf
Codeword length L_i = depth of that leaf

Average length = sum(f_i * depth_i)
So we want heavy leaves shallow, light leaves deep.
```

**Baseline**

Enumerate full binary trees → combinatorial explosion. Fixed-length codes (like all length $\lceil\log_2 k\rceil$) are easy but usually suboptimal. Greedy is the route to “optimal but still fast.”

This baseline is important for two reasons:

1. It clarifies what “optimal” really means (best tree among all prefix trees).
2. It shows why we need structure: there are too many trees to brute-force.

Fixed-length coding is the “easy but wasteful” plan: it ignores the fact that some symbols happen way more than others. Huffman’s whole point is exploiting skew. The *do* is: compare “equal lengths” vs “frequency-aware lengths.” The *don’t* is: assume fixed-length is close to optimal unless frequencies are nearly uniform.

```
Fixed-length code (k=8):
everyone gets length 3 bits

But if one symbol is 50% of the data,
making it length 1 can massively reduce average length.
```

**Greedy rule**

Repeatedly merge the two smallest weights $p$ and $q$ into $p+q$.

This is the heart of Huffman: if two symbols are the least frequent, you can “bury them deep” together with minimal pain. Merging is like saying: “in the final tree, these two will share a parent.” You then treat that parent as a combined pseudo-symbol with frequency `p+q` and repeat. The *do* is: see merging as “commit a deepest sibling pair.” The *don’t* is: merge something just because it looks convenient; it must be the **two smallest** for optimality.

```
Greedy visualization (weights only):

(0.05) (0.07) (0.12) (0.15) (0.25) (0.36)

Merge two smallest:
0.05 + 0.07 -> 0.12

Now weights:
(0.12) (0.12) (0.15) (0.25) (0.36)
Repeat...
```

**Why the cost increases by exactly $p+q$**

When you merge two subtrees, every leaf under them increases depth by $1$, so the objective increases by the total frequency mass under them:

$$
\Delta \mathbb{E}[L] = p+q.
$$

This is the “why this greedy is even measurable” moment: every merge has an exactly quantifiable cost. If you decide two subtrees will become siblings one level deeper, you’re charging every leaf underneath them one extra bit. The *do* is: remember “each merge adds its combined weight once.” The *don’t* is: think you need to build the entire codebook to compute the total cost, you can sum merge weights.

```
Depth bump diagram:

Before merge:            After merge:
   T_p                     (parent)
  /...\                   /       \
 leaves                 T_p       T_q
(depth d)             (depth d+1) (depth d+1)

All leaves under T_p and T_q get +1 depth.
Total added cost = (mass under T_p) + (mass under T_q) = p + q
```

So the final cost is the sum of merge weights.

That’s a beautiful side effect: Huffman is not just “construct a tree,” it’s “pay a known fee at each merge.” The algorithm is like repeatedly choosing the cheapest “depth increase” to apply.

```
Total cost = Σ (merge_weight at each step)

Because each merge corresponds to "add 1 bit"
to all leaves under the merged node.
```

**Why safe**

Exchange argument: in an optimal prefix tree, the two least frequent symbols can be assumed to be deepest siblings. If a heavier symbol were deeper than a lighter one, swapping them would reduce cost. Collapsing the deepest sibling pair reduces the problem size and preserves optimality → induction.

Here’s the flow that makes this feel human rather than mystical:

1. In any prefix tree, the deepest leaves pay the most bits.
2. So if *someone* must be deepest, it should be the least frequent symbols (cheapest to “punish” with extra length).
3. Moreover, in a full binary prefix tree, the deepest leaves come in sibling pairs (they share a parent).
4. Therefore, you can assume the two smallest frequencies are deepest siblings in an optimal tree.
5. If you glue them into one pseudo-symbol of weight `p+q`, you’ve shrunk the problem while preserving optimal structure, then repeat.

The *do* is: connect “least frequent” → “deepest” → “siblings” → “merge.” The *don’t* is: accept “exchange argument” as a black box; it’s just “put heavier stuff shallower.”

```
Exchange intuition (swap reduces cost)

Suppose:
light symbol has freq p
heavy symbol has freq r, where r > p

If heavy is deeper by 1:
cost includes r*(d+1) + p*d

Swap them:
cost becomes r*d + p*(d+1)

Difference (old - new) = r - p > 0
So swapping improves cost.
Therefore optimal trees push small freqs deeper.
```

```
Induction step picture:

Deepest siblings in optimal tree:
   parent
   /   \
  p     q   (two smallest)

Collapse them into one node of weight p+q:

   (p+q)

Now solve smaller problem optimally.
Expand back => optimal for original.
```

**Implementation**: min-heap.

The heap is how you make “always pick two smallest” fast. Each pop gives you the smallest remaining weight; push back the merged weight; repeat until one weight remains. The *do* is: treat it like repeatedly combining the cheapest two tasks. The *don’t* is: sort once and then do linear merges incorrectly, after every merge, the new `p+q` must re-enter the “smallest candidates” pool.

```
Min-heap loop:

push all f_i
while heap size > 1:
    p = pop_min()
    q = pop_min()
    push(p+q)
    cost += p+q
```

**Complexity**: $O(k\log k)$ for $k$ symbols.

Interpretation: you do `k-1` merges; each merge does two pops and one push, each `log k`. The *do* is: remember it scales well even for large alphabets. The *don’t* is: assume it’s linear; the heap work matters (but it’s still very fast in practice).

**Edge cases**

* Ties → multiple optimal codebooks, same $\mathbb{E}[L]$.
* Two symbols → both length $1$.

Ties are normal in real data (e.g., equal counts), and Huffman doesn’t care which tied pair you merge first, different trees, same optimal average length. With two symbols, there’s exactly one sensible prefix code: one gets `0`, the other gets `1`. The *do* is: expect non-uniqueness. The *don’t* is: treat different Huffman outputs as “wrong” if the cost matches.

```
Two symbols:

A: 0
B: 1

Average length = 1 exactly.
```

#### Maximum contiguous sum (Kadane)

**Pattern**: Discard-Negative-Prefix Greedy

This pattern is about emotional baggage: if the stuff you’ve accumulated so far is dragging you down, stop carrying it. Kadane’s algorithm works because *contiguous* means you’re forced to take whatever came immediately before, so the only real choice at each position is: **extend** the current block, or **start fresh** here. The *do* is: treat every index as a “restart checkpoint.” The *don’t* is: keep a running sum just because you started it earlier; sunk cost has no power here.

```
Contiguous block = one solid segment

x:  [  ...  | start --------- end | ... ]
            ^ you can't "skip" inside

So at each j:
Either extend the segment ending at j-1
or start a new segment at j.
```

**Problem**

Given an array, pick one contiguous block maximizing its sum.

Why you should care: this shows up as “best streak,” “max profit over a period,” “strongest signal window,” “most energetic segment,” and a million other “find the hottest run” tasks. The *do* is: recognize it as “best window” not “best set.” The *don’t* is: mix it up with picking any subset (that’s a different problem).

```
Subset vs contiguous (important!)

contiguous:  [x2, x3, x4]  (must be adjacent)
subset:      [x2, x7, x9]  (can skip)

Kadane is for contiguous.
```

**Baseline**

Try all $O(n^2)$ blocks (using prefix sums to evaluate quickly).

The baseline is the “I will brute-force my way to truth” approach: choose every possible start and end, compute sums, keep the best. It’s correct, and it teaches what “optimal” means, but it wastes time by recomputing overlapping windows. The *do* is: remember this baseline when you want to justify correctness. The *don’t* is: actually use it for large `n` unless you enjoy waiting.

```
All blocks = all (L,R) pairs

L=0: (0,0) (0,1) (0,2) ...
L=1:       (1,1) (1,2) ...
...

O(n^2) windows, tons of overlap.
```

**Greedy rule**

Never carry a negative-running prefix forward. If your running sum becomes negative, drop it, because adding a negative prefix to any future suffix only makes it worse.

This is the “why” that makes the algorithm feel inevitable: if your current partial sum is negative, then for any future value `t`,
`(negative sum) + t < t`.
So keeping that negative prefix can never help you build a best block that continues into the future. The *do* is: reset when the running sum goes below zero. The *don’t* is: reset when it merely “gets smaller”, smaller can still be useful if it stays non-negative.

```
Why negative prefixes are poison:

Suppose prefix sum P < 0.
Any future suffix S:

P + S  <  0 + S  = S

So the best subarray that ends in the future
will never want to include P.
```

Equivalent incremental form:

$$
E_j = \max(x[j], E_{j-1}+x[j])
$$

and track the best seen.

Here `E_j` is the best sum of a subarray that **must end at j**. That’s the key: “ending here” makes the choice local and greedy-friendly. Either you (1) start at `j` (take only `x[j]`), or (2) extend the best ending at `j-1`. There’s no third option if contiguity is mandatory. The *do* is: read the recurrence as “restart vs extend.” The *don’t* is: treat it like magic DP, this one is literally just the two possible ways to end at `j`.

```
Two options at j:

Option A: start new at j
   [ x[j] ]

Option B: extend previous best ending at j-1
   [ ... best ending at j-1 ..., x[j] ]

Take max of the two.
```

A quick “flow” visualization for intuition:

```
x:    [  4,  -6,  3,  2,  -1,  5 ]
E:     4   -2   3   5    4   9
best:  4    4   4   5    5   9

At -6, the running sum becomes negative -> baggage dropped.
Then the streak restarts at 3.
```

**Proof sketch**

A negative prefix cannot improve any future subarray sum, so discarding it is always safe. The loop maintains “best sum ending here” and “best overall.”

The proof is basically a tight little logic loop:

1. To get the best subarray ending at `j`, you either start at `j` or extend something ending at `j-1` (contiguity forces this).
2. If the best ending at `j-1` is negative, extending it only hurts, so starting fresh is optimal.
3. Therefore the recurrence computes the correct “best ending here,” and taking the maximum over all `j` gives the best overall.

The *do* is: anchor your reasoning on “must end at j.” The *don’t* is: try to prove it by enumerating all subarrays again, you’ll just reinvent the baseline.

```
Invariant view:

E_j = best sum of any subarray that ends exactly at j
BEST = max over all E_j seen so far

Update keeps both truths correct each step.
```

**Complexity**: $O(n)$ time, $O(1)$ space.

You scan once, keep two numbers (`E` and `BEST`). That’s the whole win: maximal information compression with minimal bookkeeping. The *do* is: implement it as a single pass. The *don’t* is: store all `E_j` unless you specifically need reconstruction.

**Edge cases**

* All negatives → answer is the least negative element (for non-empty requirement).
* If empty block allowed → initialize best at $0$.

These matter because Kadane’s “reset when negative” can otherwise trick you into returning 0 even when you’re required to pick *something*. The *do* is: decide up front whether “empty subarray” is allowed. The *don’t* is: mix conventions mid-solution.

```
All-negative example: [-5, -2, -8]

Non-empty required:
  answer = -2 (pick the single best element)

Empty allowed:
  answer = 0  (pick empty block)
```

### When Greedy Is Guaranteed: Matroids

There’s a clean world where greedy is always right for nonnegative weights: matroids.

Informal rules:

1. Start from empty.
2. Subsets of allowed sets are allowed.
3. Augmentation: if one allowed set is smaller than another, you can add something from the larger to the smaller and stay allowed.

Why you should care: matroids are a formal “certificate” that exchange arguments will succeed. They explain why “sort by weight and take what fits” works for MSTs (graphic matroid).

Greedy can still work outside matroids (Dijkstra, Huffman), but then correctness depends on problem-specific structure rather than the general matroid guarantee.

### Common Failure Modes

Greedy doesn’t always work. The failures are valuable because they teach you what a missing proof looks like.

#### Coin change with non-canonical coins

Denominations ${1,3,4}$, target $6$.

* Greedy: $4+1+1$ → 3 coins.
* Optimal: $3+3$ → 2 coins.

Lesson: “largest coin first” is not universally safe; it depends on special coin systems.

### Interval scheduling by earliest start time (wrong rule)

Intervals $(1,10),(2,3),(4,5)$.

* Earliest start picks $(1,10)$ → blocks everything → 1 interval.
* Earliest finish picks $(2,3),(4,5)$ → 2 intervals.

Lesson: the key must match the exchange argument (“finishes earlier leaves more room”).

#### Fractional vs 0/1 knapsack

Greedy by value/weight ratio is optimal for fractional knapsack, but fails for 0/1.

Example capacity $50$ with items $(10,60),(20,100),(30,120)$:

* Greedy ratio picks items 1 and 2 → value $160$.
* Optimal picks items 2 and 3 → value $220$.

Lesson: allowing fractions changes feasibility structure, and greedy safety can disappear.
