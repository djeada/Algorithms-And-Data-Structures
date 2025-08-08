## What are greedy algorithms?

Greedy methods construct a solution piece by piece, always choosing the currently best-looking option according to a simple rule. The subtlety is not the rule itself but the proof that local optimality extends to global optimality. Two proof tools do most of the work: exchange arguments (you can swap an optimal solution’s first “deviation” back to the greedy choice without harm) and loop invariants (you maintain a statement that pins down exactly what your partial solution guarantees at each step).

Formally, consider a finite ground set $E$, a family of feasible subsets $\mathcal{F}\subseteq 2^E$, and a weight function $w:E\to \mathbb{R}$. A generic greedy scheme orders elements of $E$ by a key $\kappa(e)$ and scans them, adding $e$ to the building solution $S$ if $S\cup\{e\}\in\mathcal{F}$. Correctness means

$$
\text{Greedy}(E,\mathcal{F},w,\kappa)\in\arg\max\{\,w(S):S\in\mathcal{F}\,\}.
$$

The nice, crisp setting where this always works is the theory of matroids. Outside that, correctness must be argued problem-by-problem.

```
scan order:  e1  e2  e3  e4  e5  ...
feasible?     Y   N   Y   Y   N
solution S:  {e1,    e3, e4}
```

## The greedy-choice principle and exchange arguments

A problem exhibits the greedy-choice principle if there exists an optimal solution that begins with a greedy step. Once you show that, you can peel off that step and repeat on the residual subproblem. Exchange arguments are a tight way to prove it.

Let $G$ be the greedy solution and $O$ an optimal solution. Suppose the first element where they differ is $g\in G$ and $o\in O$. If replacing $o$ by $g$ in $O$ keeps feasibility and does not reduce the objective, then there exists an optimal solution that agrees with greedy at that position. Repeating this swap inductively transforms $O$ into $G$ with no loss, hence greedy is optimal.

Visually, you keep “pushing” the optimal solution toward the greedy one:

```
O:   o  ?  ?  ?       → swap o→g at first difference
G:   g  g  g  g
```

## Matroids

Matroids capture exactly when a simple weight-ordered greedy works for all weights.

A matroid is a pair $(E,\mathcal{I})$ where $\mathcal{I}\subseteq 2^E$ satisfies three axioms: non-emptiness $\varnothing\in\mathcal{I}$, heredity $A\in\mathcal{I}$ and $B\subseteq A\Rightarrow B\in\mathcal{I}$, and augmentation if $A,B\in\mathcal{I}$ with $|A|<|B|$ then there exists $x\in B\setminus A$ such that $A\cup\{x\}\in\mathcal{I}$.

Given nonnegative weights $w:E\to\mathbb{R}_{\ge 0}$, the greedy algorithm that scans in order of decreasing $w$ and keeps an element whenever independence is preserved returns a maximum-weight independent set. The proof is a one-line exchange: if greedy kept $g$ and an optimal $O$ did not, augmentation in the matroid allows swapping in $g$ for some element of $O$ without losing feasibility or weight.

Two takeaways rise above the formalism. When your feasibility system has an augmentation flavor, greedy tends to shine. When augmentation fails, greedy can fail spectacularly and you should be suspicious.

## Loop invariants

Some greedy scans are best understood with invariants that certify what your partial state already guarantees.

A linear reachability scan on positions $0,1,\dots,n-1$ with “hop budgets” $a_i\ge 0$ uses the invariant

$$
F_i=\max\{\, j+a_j : 0\le j\le i,\ j\le F_{j}\ \text{when processed}\,\},
$$

where $F_i$ is the furthest index known reachable after processing index $i$. If at some step $i>F_{i-1}$, progress is impossible, because every candidate that could have extended the frontier was already considered.

```
indices: 0   1   2   3   4   5
a[i]:    3   1   0   2   4   1
frontier after i=0: F=3
after i=1: F=max(3,1+1)=3
after i=2: F=max(3,2+0)=3
stuck at i=4 because 4>F
```

The invariant is monotone and essentially proves itself: no future step can invent a larger $j+a_j$ from a $j$ you skipped as unreachable.

## Minimum spanning trees

Two greedy algorithms produce minimum spanning trees in a connected weighted graph $G=(V,E,w)$.

Kruskal’s rule sorts edges by nondecreasing weight and adds an edge if it connects two different components of the partial forest. Prim’s rule grows a single tree, always adding the lightest edge that leaves the current tree. Both succeed due to the cut and cycle properties.

For any partition $(S,V\setminus S)$, the lightest edge crossing the cut belongs to some minimum spanning tree. For any cycle $C$, the heaviest edge on $C$ does not belong to any minimum spanning tree. The first property justifies “always add the cheapest safe edge,” while the second justifies “never add an edge that would create a cycle unless it is not the heaviest on that cycle.”

A crisp exchange proves the cut property. If a minimum tree $T$ does not use the cut’s lightest edge $e$, add $e$ to $T$ to form a cycle. That cycle must cross the cut at least twice; remove a heavier cross-edge from the cycle to get a strictly cheaper spanning tree, a contradiction.

```
cut S | V\S
   \  |  /
    \ | /   ← add the cheapest cross-edge
-----\|/-----
```

Union–find makes Kruskal’s rule nearly linear; a binary heap makes Prim’s rule nearly linear as well.

## Shortest paths with nonnegative weights

Dijkstra’s method picks an unsettled vertex with minimum tentative distance and settles it forever. The loop invariant is the heart: when a vertex $u$ is settled, its label $d(u)$ equals the true shortest-path distance $\delta(s,u)$. The proof uses nonnegativity. If there were a shorter route leaving the settled set, it would have to traverse an edge of nonnegative weight to an as-yet unsettled vertex v, which cannot reduce the label below the minimum label currently available to settle. Formally, an exchange of the “last edge that leaves the settled set” gives the contradiction.

It helps to picture the labels as a wavefront expanding through the graph:

```
settled:  ####
frontier:  .....
unseen:       ooooo
labels grow outward like ripples in a pond
```

Negative edge weights break the monotonicity that makes “settle and forget” safe.

## Prefix sums and the maximum contiguous sum

Consider a finite sequence $x_1,\dots,x_n$. Define prefix sums $S_0=0$ and $S_j=\sum_{k=1}^j x_k$. Any contiguous sum equals $S_j-S_i$ for some $0\le i<j$. The optimum is

$$
\max_{1\le j\le n}\bigl(S_j-\min_{0\le t<j} S_t\bigr).
$$

One pass that tracks the current prefix and the smallest prefix seen so far achieves the maximum. The greedy flavor is the “reset if the running sum drops too low” heuristic, which is simply the above formula written incrementally.

```
S:   0   2   1   4   3  -1   2
min: 0   0   0   0   0  -1  -1
gap: 0   2   1   4   3   0   3   → optimum 4
```

When every $x_i<0$, the best segment is the largest (least negative) single element, which appears automatically since the minimum prefix keeps descending.

## Scheduling themes

Two fundamental one-line rules show up over and over.

Choosing as many compatible time intervals as possible is achieved by sorting by finishing time and repeatedly keeping the earliest finisher that does not conflict with what you already kept. An exchange argument makes it airtight: whenever an optimal schedule picks a later finisher as its next meeting, swapping it for the earlier finisher cannot reduce the pool of future compatible meetings because ending earlier never hurts.

Minimizing maximum lateness for jobs with equal processing times is achieved by ordering by nondecreasing deadlines. If two adjacent jobs $i$ and $j$ disobey this order with $d_i>d_j$, swapping them does not increase any lateness and strictly helps one of them; repeatedly fixing inversions yields the sorted order with no worse objective.

```
time →
kept:   [---)   [--)    [----)     [---)
others:    [-----)    [------)  [--------)
ending earlier opens more future room
```

Weighted versions of these problems typically need dynamic programming rather than greedy rules.

## Huffman coding

Given symbol frequencies $f_i>0$ with $\sum_i f_i=1$, a prefix code assigns codeword lengths $L_i$ satisfying the Kraft inequality $\sum_i 2^{-L_i}\le 1$. The expected codeword length is

$$
\mathbb{E}[L]=\sum_i f_i L_i.
$$

Huffman’s algorithm repeatedly merges the two least frequent symbols. The exchange idea is simple. In an optimal tree, the two deepest leaves must be siblings and must be the two least frequent symbols; otherwise, swapping their positions with the two least frequent decreases expected length by at least $f_{\text{heavy}}-f_{\text{light}}>0$. Merging these two leaves into a single pseudo-symbol of frequency $f_a+f_b$ reduces the problem size while preserving optimality, leading to optimality by induction.

The code tree literally grows from the bottom:

```
      *
     / \
    *   c
   / \
  a   b         merge a,b first if f_a ≤ f_b ≤ f_c ≤ ...
```

The cost identity $\mathbb{E}[L]=\sum_{\text{internal nodes}} \text{weight}$ turns the greedy step into a visible decrement of objective value at every merge.

## When greedy fails (and how to quantify “not too bad”)

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

## Sweep lines and event counts: a greedy counting lens

Many timeline problems reduce to counting the maximum load. Turn each interval $[s,e)$ into an arrival at $s$ and a departure at $e$. Sort all events and scan from left to right, increasing a counter on arrivals and decreasing it on departures. The answer is the peak value of the counter:

$$
\max_t C(t).
$$

Ties are processed with departures before arrivals, which matches the half-open convention and prevents phantom conflicts when one interval ends exactly where the next begins.

```
time → 1 2 3 4 5 6 7
A:     [-----)
B:        [---)
C:           [-----)
load:  1 2 3 2 2 1 0
peak:  3
```

While this is not “optimization by selection,” it is greedy in spirit: you never need to look back, and the loop invariant (counter equals number of currently active intervals) makes the peak exact.

## Anatomy of a greedy proof

It pays to recognize the tiny handful of templates that keep recurring.

* Exchange template for selection: assume the first divergence between a greedy solution and an optimal solution. Show the greedy choice weakly dominates the optimal one with respect to the future, swap, and iterate.
* Cut template for graphs: argue that the cheapest edge crossing a cut is always safe to add, or that the heaviest edge on any cycle is always safe to discard.
* Potential or invariant template for scans: identify a monotone quantity that only moves one way; once it passes a threshold, later steps cannot undo it.

These are the same ideas with different clothes.

## Pitfalls, boundary choices, and complexity

Monotonicity assumptions are not decoration. Dijkstra needs nonnegative edges; the proof breaks the moment a negative edge lets a later step undercut a settled label. Interval boundaries love the half-open convention $[s,e)$ to make “end at $t$, start at $t$” compatible and to simplify event-ordering in sweeps.

Complexity usually splits into a sort plus a scan. Sorting $n$ items costs $O(n\log n)$. A scan with constant-time updates costs $O(n)$. Minimum spanning trees achieve $O(m\alpha(n))$ with union–find for Kruskal and $O(m\log n)$ for Prim with a heap, where $\alpha$ is the inverse Ackermann function.

## A compact design checklist you can actually use

* Identify a key order that seems to make future choices easier. Finishing times, smallest weights, or largest marginal gains are usual suspects.
* Propose a local rule that never looks back, then write down the loop invariant that must be true if the rule is right.
* Decide whether an exchange argument, a cut/cycle argument, or a potential function is the appropriate proof lens.
* Stress-test the rule on a crafted counterexample. If one appears, consider whether the structure is missing a matroid-like augmentation or a monotonicity prerequisite.
* If exact optimality is out of reach, look for submodularity or harmonic charging to get a clean approximation guarantee.
