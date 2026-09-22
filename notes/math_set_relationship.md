# Math Set Relationships

Starting from a finite set, we can construct pairs, sequences, subsets, and orderings. For each construction, these notes explain what counts as a distinct result, how many results exist, and the time and storage required to generate them.

Before counting, decide what makes two objects distinct: whether order matters and whether elements may be reused. Keep those rules fixed throughout the problem.

## Sets and Notation

Let a finite set be:

```
A = {a, b, c}
|A| = n = 3
```

Unless stated otherwise, $n$ and $k$ are non-negative integers, the elements of $A$ are distinct, and sampling without repetition requires $0 \le k \le n$. There is one empty subset and one empty sequence, so $0! = 1$ and choosing zero elements gives one result. Choosing more than $n$ elements without repetition gives no results.

Almost everything below is about creating new sets of objects from `A`, then counting how many objects there are, then generating them efficiently.

This is the same move you do in programming all the time, turning a small input into a space of candidates. If the candidate space is small, brute force can work. If it’s huge (hello, $2^n$ and $n!$), you need smarter strategies. The math tells you when “try everything” is doomed.

## Cartesian Products

When you see “choose one thing from here and one thing from there,” you’re in Cartesian-product land. It’s the formal version of nested loops: for each $x$ in $A$, loop over each $y$ in $B$.

The Cartesian product $A \times B$ is the set of all ordered pairs:

```
A × B = {(x, y) : x ∈ A, y ∈ B}
```

Example diagram

Let:

```
A = {a, b, c}
B = {0, 1}
```

Then:

```
A × B =
(a,0) (a,1)
(b,0) (b,1)
(c,0) (c,1)
```

“grid view”:

```
        B
      0     1
A  +-----+-----+
a  | a,0 | a,1 |
   +-----+-----+
b  | b,0 | b,1 |
   +-----+-----+
c  | c,0 | c,1 |
   +-----+-----+
```

Do remember these are ordered pairs, $(a,0)\neq(0,a)$, and don’t treat it like “a set of two things.” Order is the entire point.

### Counting

If $|A| = n$ and $|B| = m$ then:

```
|A × B| = n·m
```

### Why it matters

This is the foundation of:

- counting multi-step choices (“choose x then choose y”)
- building tuples (records, coordinates)
- generating combinations/permutations via sequences (see below)

This shows up constantly in real code: if you ever wrote two nested loops, joined two tables, or enumerated coordinate pairs on a grid, you were living in $A\times B$. The math just makes the “how many iterations is this?” question instantly answerable.

### Algorithm + time

To enumerate all pairs you must output $n\cdot m$ things:

- Time: $\Theta(n\cdot m)$
- Space: $\Theta(1)$ extra (if streaming) or $\Theta(n\cdot m)$ if storing

A practical do/don’t: do stream results when possible (generate and consume immediately), and don’t store the full product unless you truly need random access, memory can become your bottleneck before time does.

## Power Sets

If Cartesian products feel like “two-loop land,” the power set is “every possible on/off choice.” This is where problems become exponential because you’re not picking one item, you’re deciding for each item whether it’s included.

The power set $\mathcal{P}(A)$ is the set of all subsets of $A$.

For `A={a,b,c}`:

```
𝒫(A) = {
  ∅,
  {a}, {b}, {c},
  {a,b}, {a,c}, {b,c},
  {a,b,c}
}
```

Subset lattice (Boolean lattice):

```
        {a,b,c}
       /   |   \
   {a,b} {a,c} {b,c}
     |  \ /   \ /  |
     |  / \   / \  |
    {a}    {b}    {c}
       \    |     /
            ∅
```

The power set is the search space behind “try all subsets” algorithms, feature selection, subset sum, knapsack-style brute force, and lots of graph subset problems. The lattice diagram is the map of that search space.

### Counting

If $|A| = n$ then:

```
|𝒫(A)| = 2^n
```

Why? Each element has two states: “in” or “out”.

Bitmask picture (n=3):

```
a b c   subset
0 0 0   ∅
1 0 0   {a}
0 1 0   {b}
0 0 1   {c}
1 1 0   {a,b}
1 0 1   {a,c}
0 1 1   {b,c}
1 1 1   {a,b,c}
```

A do/don’t that saves headaches: do think “bitmask = subset” whenever you need to generate subsets efficiently, and don’t try to be “clever” by skipping the output cost, if the problem truly needs all subsets, $2^n$ is unavoidable.

### Algorithms + time

To enumerate all subsets, you must output $2^n$ subsets:

- Time: $\Theta(n\cdot 2^n)$ if you build each subset explicitly (each subset may cost up to $n$ to construct)
- Space: $\Theta(n)$ recursion/bitmask state (streaming) or $\Theta(n\cdot 2^n)$ if storing all

The big idea: output size dominates. If you’re generating all subsets, you’re not “being slow”, you’re paying the bill for the number of results you asked to print.

## Combinations

Combinations are how you take the power set and say: “Okay, cool, but I only want subsets of a specific size.” This is a common “make the search space manageable” move: instead of every subset, you focus on one level of the lattice.

A $k$-combination is a subset of size $k$.

The set of all $k$-subsets of $A$ is:

```
{ S ⊆ A : |S| = k }
```

Counting (binomial coefficient)

If $|A| = n$:

```
C(n,k) = "n choose k" = n! / (k!(n-k)!)
```

In standard notation, this is

$$C(n,k)=\binom{n}{k}=\dfrac{n!}{k!(n-k)!}$$

Do use $\binom{n}{k}$ when you write math (it’s clearer), and don’t forget the “order doesn’t matter” rule, if you start ordering the chosen elements, you’ve switched problems.

Combinations form a level in the power-set lattice.

For `A={a,b,c}`, `k=2`:

```
level k=2: {a,b} {a,c} {b,c}
```

Power set is all combinations across all k:

```
2^n = |𝒫(A)| = Σ_{k=0..n} C(n,k)
```

Proper math:

$$2^n = |\mathcal{P}(A)| = \sum_{k=0}^{n} \binom{n}{k}$$

### Algorithms + time

To enumerate all $k$-combinations you output $\binom{n}{k}$ objects:

- Time: $\Theta(k \cdot C(n,k))$ (each output has $k$ items)
- Space: $O(k)$ working storage for a generator that recurses over chosen positions. A literal take/skip recursion over all $n$ input positions can instead need $O(n)$ stack space.

Common methods:

- recursive backtracking (“take / skip”)
- iterative lexicographic combination generation
- bitmask “next k-bit” tricks

One practical tip: do pick your generation method based on what you need downstream (lexicographic order? Streaming? Constant extra memory?), and don’t assume “combinations are always small”, $\binom{n}{k}$ can still be huge around $k\approx n/2$.

## Permutations

Permutations are what happens when you stop treating a chosen set as a bag of items and start treating it like a sequence. In algorithm terms, you’ve moved from “which items?” to “in what order?”

There are two closely related ideas:

### (A) Permutations of all n elements

All orderings of the entire set `A` (size $n$).

Count:

```
n!
```

Example `A={a,b,c}`:

```
abc acb bac bca cab cba
```

### (B) k-permutations (arrangements of length k without repetition)

Ordered sequences of length $k$ drawn from $n$ distinct elements.

Count:

```
P(n,k) = n·(n-1)·...·(n-k+1) = n!/(n-k)!
```

Proper math:

$$P(n,k)=n(n-1)\cdots(n-k+1)=\dfrac{n!}{(n-k)!}$$

A do/don’t that prevents classic mistakes: do decide early whether repetition is allowed; don’t mix “without repetition” formulas (like $P(n,k)$) with “with repetition” reasoning (like $n^k$).

### permutations as “paths” of choices (multiplication rule)

For $n=3, k=2$:

```
start
 ├─ pick a ─┬─ then b  => (a,b)
 │          └─ then c  => (a,c)
 ├─ pick b ─┬─ then a  => (b,a)
 │          └─ then c  => (b,c)
 └─ pick c ─┬─ then a  => (c,a)
            └─ then b  => (c,b)
```

This tree is the “nested loops in your head” picture: each level is a choice, and the number of leaves is the total count.

### Relationship to combinations

A $k$-combination becomes many $k$-permutations once you order it:

```
P(n,k) = C(n,k) · k!
```

Proper math:

$$P(n,k)=\binom{n}{k} k!$$

Because:

- choose the $k$ elements (order-free): $\binom{n}{k}$
- order them: $k!$

### Algorithms + time

To enumerate all permutations of $n$ items:

- Time: $\Theta(n \cdot n!)$ ($n$ work per permutation)
- Space: $\Theta(n)$ recursion or in-place swaps

Classic algorithms:

- Heap’s algorithm (efficient swaps)
- next_permutation (lexicographic)
- backtracking swap recursion

In-place swapping limits working memory, but explicitly producing every permutation still takes factorially many outputs. Estimate the output size before choosing enumeration, and use streaming when results can be processed one at a time.

## Selection with Repetition

Subsets and permutations without repetition use each element at most once. Cartesian products and powers allow the same value in different positions. If reuse is allowed, the counting flips in a really clean way: “no repetition” tends to create factorials and falling factorials; “repetition allowed” tends to create powers and stars-and-bars.

### Cartesian product becomes “strings of length k”

If you choose $k$ positions and each position can be any of $n$ symbols, you get:

```
A^k = A × A × ... × A   (k times)
|A^k| = n^k
```

Proper Math:

$$A^k = \underbrace{A\times A\times\cdots\times A}_{k\text{ times}}$$

$$|A^k|=n^k$$

This is exactly “all $k$-length sequences over $A$” (like passwords).

### Combinations with repetition (multisets)

Number of size-$k$ multisets from $n$ types:

```
C(n+k-1, k)
```

For $n \ge 1$, that is $\binom{n+k-1}{k}$ (a “stars and bars” result). Place $k$ stars and $n-1$ separators in a row: the numbers of stars between separators specify the multiplicities of the $n$ types. If $n=0$, only the empty multiset ($k=0$) exists. Do picture $k$ identical picks distributed among $n$ bins; don’t treat this like normal combinations, repetition changes the geometry.

### Permutations with repetition

If you have $n$ symbols and length $k$, order matters and repetition allowed:

```
n^k
```

This use of “permutations with repetition” means unrestricted sequences. Arranging a fixed multiset is a different problem: if $N$ items have multiplicities $m_1,\ldots,m_r$ with sum $N$, the number of distinct orderings is $N!/(m_1!\cdots m_r!)$. For example, `aab` has three orderings: `aab`, `aba`, and `baa`.

## Viewing the Constructions as Functions

This section is the “snap everything into place” moment. If you ever feel lost, switching to the function viewpoint usually makes the counting obvious: how many ways can I assign labels to inputs?

### Subset = function to {0,1}

A subset $S \subseteq A$ is equivalent to an indicator function:

```
f: A → {0,1}
f(x)=1 if x∈S else 0
```

Number of such functions is $2^n$ → power set size.

### k-length sequence = function from positions to A

A length-$k$ sequence is:

```
g: {1..k} → A
```

Number is $n^k$ → Cartesian power.

### Permutation as a bijection from positions to elements

A permutation is a bijection:

```
p: {1..n} → A
```

Number is $n!$.

So:

- power set = all $\{0,1\}$-labelings of $A$
- Cartesian powers = all $k$-position labelings by $A$
- permutations = all one-to-one labelings of positions by $A$

A do/don’t here: do use “functions” when you’re stuck; don’t overcomplicate it with new symbols, this is meant to be the simplest mental model.

### Complexity reality check: output size dominates

If you generate these objects, the minimum time is at least the number of outputs. The bounds below assume nonempty outputs are copied explicitly and each element takes constant time to copy. For $n=0$ or $k=0$, emitting the single empty result costs constant time. Streaming saves storage for the accumulated results, but it does not remove the output time.

So:

| Structure                  |          Count |      Typical enumeration time |
| -------------------------- | -------------: | ----------------------------: |
| $A \times B$               |     $n\cdot m$ |            $\Theta(n\cdot m)$ |
| $\mathcal{P}(A)$           |          $2^n$ |          $\Theta(n\cdot 2^n)$ |
| $k$-combinations           | $\binom{n}{k}$ | $\Theta(k\cdot \binom{n}{k})$ |
| permutations               |           $n!$ |           $\Theta(n\cdot n!)$ |
| $k$-permutations           |       $P(n,k)$ |       $\Theta(k\cdot P(n,k))$ |
| $k$-length strings ($A^k$) |          $n^k$ |          $\Theta(k\cdot n^k)$ |

This is why many problems that ask you to “try all subsets” are exponential: the search space literally has $2^n$ candidates.

One last do/don’t that matters in real projects: do treat these counts like early warning signs (a design review for your algorithm), and don’t wait until you’ve implemented everything to realize you built an $n!$ machine.

## Choosing a Counting Formula

Ask two questions:

### Q1: Does order matter?

- No → combinations / subsets / multisets
- Yes → permutations / sequences / tuples

### Q2: Can you reuse elements?

- No repetition → factorial / falling factorial
- Repetition allowed → powers / stars-and-bars

Decision table:

```
                     No repetition        Repetition allowed
Order matters         P(n,k)=n!/(n-k)!    n^k
Order doesn't matter  C(n,k)=n!/(k!(n-k)!) C(n+k-1,k)
```

Use the table by deciding first whether order matters and then whether elements can be reused. Those two assumptions distinguish the four counting problems.

## Why these appear in algorithms

- Power set / combinations show up in: subset-sum, knapsack variants, feature selection, graph vertex subsets, brute-force optimization.
- Permutations show up in: traveling salesman, scheduling, ordering constraints, anagrams, backtracking search.
- Cartesian products show up in: nested loops, join operations in databases, grid/coordinate enumeration, state spaces.

A yes/no branch for each of $n$ elements suggests $2^n$ candidate subsets. Trying all orders of $n$ distinct elements suggests $n!$ candidates. Constraints may prune the search, but these counts explain its initial size.

A tiny “big picture” diagram: how they build on each other

```
Sets (A)
  |
  +--> Cartesian product (A×B)  ---> tuples / coordinates
  |         |
  |         +--> Cartesian power (A^k) ---> sequences, strings (n^k)
  |
  +--> Power set P(A) ---> all subsets (2^n)
            |
            +--> k-subsets ---> combinations C(n,k)
                         |
                         +--> order them ---> k-permutations = C(n,k)·k! = P(n,k)
```
