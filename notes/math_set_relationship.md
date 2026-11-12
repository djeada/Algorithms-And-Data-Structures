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

> **First step:** Decide whether you must list every subset or only count or optimize over them. Listing costs $\Theta(n \cdot 2^n)$ and is realistic up to about $n = 20$. If you only need a count or a best value, look for a formula or a dynamic program instead.

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

### Subsets as Bitmasks

Number the elements $0$ to $n-1$. Every integer `mask` from $0$ to $2^n - 1$ then names exactly one subset: element $i$ is in the subset when bit $i$ of `mask` is set, which you test with `(mask >> i) & 1`. Looping over all masks is the iterative answer to LeetCode 78 Subsets and needs no recursion at all.

A second iterative style starts with `[[]]` and, for each new element, appends a copy of every existing subset with that element added. Both produce all $2^n$ subsets. The recursive take/skip version lives in the backtracking note.

```python
def subsets(nums):
    n = len(nums)
    result = []
    for mask in range(1 << n):
        result.append([nums[i] for i in range(n) if (mask >> i) & 1])
    return result
```

The same loop solves LeetCode 784 Letter Case Permutation (a mask over the letter positions picks which letters are uppercase, giving $2^{\text{letters}}$ strings) and LeetCode 1863 Sum of All Subset XOR Totals. For 1863 there is also a shortcut: any bit that appears in at least one element is set in the XOR of exactly half of the subsets, so the answer is (OR of all elements) $\cdot\, 2^{n-1}$.

Time is $\Theta(n \cdot 2^n)$. The most common mistake is writing `2^n` in Python or C, where `^` is XOR; write `1 << n`.

### Enumerating Submasks

Sometimes you already have a set `mask` and need every subset of it, for example in DP over subsets where a state is split into two parts. The trick `sub = (sub - 1) & mask` jumps straight to the next smaller submask and skips every integer that has a bit outside `mask`.

```python
sub = mask
while True:
    process(sub)
    if sub == 0:
        break
    sub = (sub - 1) & mask
```

A mask with $b$ set bits has $2^b$ submasks. Running this for every mask of $n$ bits costs $3^n$ in total, because each element is either outside the mask, in the mask but not the submask, or in both. The common mistake is the loop condition: `while sub > 0` silently skips the empty submask, and forgetting the break loops forever because `(0 - 1) & mask` is `mask` again.

### Gray Code Order

LeetCode 89 Gray Code asks for all $2^n$ masks ordered so that neighbours differ in exactly one bit. The binary-reflected Gray code has a closed form: the $i$-th code is `i ^ (i >> 1)`.

The reflect construction explains why it works. Take the list for $n-1$ bits, append its mirror image with the top bit set, and both the seam in the middle and the wraparound at the end change only that top bit.

```python
def gray_code(n):
    return [i ^ (i >> 1) for i in range(1 << n)]
```

Time is $\Theta(2^n)$. The usual mistake is shifting the wrong way, `i ^ (i << 1)`, which produces values outside the $n$-bit range.

## Combinations

Combinations are how you take the power set and say: “Okay, cool, but I only want subsets of a specific size.” This is a common “make the search space manageable” move: instead of every subset, you focus on one level of the lattice.

> **First step:** Confirm that order really does not matter and that each element can be picked at most once. Then decide whether you need the actual groups or only how many there are, and check how large $\binom{n}{k}$ can get before choosing an integer type or a modulus.

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

### Generating Combinations in Order

LeetCode 77 Combinations is usually solved by backtracking with a start index: after choosing position `i`, the next choice starts at `i + 1`, so no element is reused and no group appears in two orders. Prune by stopping the loop once too few elements remain to fill the group. The general backtracking template is in the backtracking note.

The iterative alternative works on a sorted list of $k$ indices and produces the next combination in lexicographic order. Find the rightmost index that can still move up, increase it by one, and reset everything to its right to consecutive values. This is exactly what LeetCode 1286 Iterator for Combination needs, with the indices mapped to characters.

```python
def next_combination(c, n):
    k = len(c)
    i = k - 1
    while i >= 0 and c[i] == n - k + i:   # c[i] is already at its maximum
        i -= 1
    if i < 0:
        return False                      # c was the last combination
    c[i] += 1
    for j in range(i + 1, k):
        c[j] = c[j - 1] + 1
    return True
```

Each step costs $O(k)$. The common mistake in the recursive version is passing `i` instead of `i + 1` to the next call, which allows reuse and turns combinations into multisets.

### Computing Binomial Coefficients Safely

Computing $n!$ and then dividing overflows fixed-width integers long before $\binom{n}{k}$ itself does. There are three safer routes, and which one fits depends on the size of $n$ and whether a modulus is involved.

Pascal's rule $\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}$ builds the triangle row by row using only additions. LeetCode 118 Pascal's Triangle asks for the rows, and LeetCode 119 Pascal's Triangle II asks for a single row in $O(k)$ memory, which you get by updating one array from right to left.

```python
def pascal_row(n):
    row = [1] * (n + 1)
    for i in range(1, n + 1):
        for j in range(i - 1, 0, -1):     # right to left keeps old values
            row[j] += row[j - 1]
    return row
```

The multiplicative formula computes a single value in $O(k)$ time: start from `r = 1` and for $i = 1, \ldots, k$ set `r = r * (n - k + i) // i`. After step $i$ the value is $\binom{n-k+i}{i}$, so every division is exact. Use $k = \min(k, n-k)$ to keep the loop short. LeetCode 62 Unique Paths is this formula in disguise: a robot in an $m \times n$ grid makes $m+n-2$ moves, of which $m-1$ go down, so the answer is $\binom{m+n-2}{m-1}$.

When the problem says "return the answer modulo $10^9+7$", you cannot divide after reducing. Because the modulus $p$ is prime, Fermat's little theorem gives the inverse $a^{-1} \equiv a^{p-2} \pmod p$ for any $a$ not divisible by $p$. Precompute factorials and inverse factorials once, and every query becomes three multiplications.

```python
MOD = 10**9 + 7

def build(n):
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    inv = [1] * (n + 1)
    inv[n] = pow(fact[n], MOD - 2, MOD)   # Fermat inverse
    for i in range(n, 0, -1):
        inv[i - 1] = inv[i] * i % MOD
    return fact, inv

def ncr(n, r, fact, inv):
    if r < 0 or r > n:
        return 0
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD
```

Pascal's triangle costs $O(nk)$, the multiplicative formula $O(k)$, and the factorial tables $O(n)$ to build plus $O(1)$ per query. The most common mistake is writing `fact[n] // (fact[r] * fact[n - r]) % MOD` after the factorials were already reduced, which gives a wrong answer because integer division does not survive reduction modulo $p$. Fermat inverses also require a prime modulus and $n < p$.

## Permutations

Permutations are what happens when you stop treating a chosen set as a bag of items and start treating it like a sequence. In algorithm terms, you’ve moved from “which items?” to “in what order?”

> **First step:** Decide whether you need every ordering, only the next one, or only the $k$-th one, and whether the input has repeated values. Listing all $n!$ orderings is only realistic for $n$ up to about 8 to 10, so "next" and "$k$-th" questions should be answered by construction.

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

### Permutations with Duplicates

LeetCode 46 Permutations uses the standard backtracking with a `used` array, described in the backtracking note. LeetCode 47 Permutations II adds repeated values, and the number of distinct results drops to $N!/(m_1! \cdots m_r!)$, where $m_i$ is how many times value $i$ appears.

To generate each distinct ordering once, sort the input and, at each depth, skip a value that equals its left neighbour when that neighbour is not currently used. This forces equal values to be placed in their original left-to-right order, so swapping two equal copies never creates a second copy of the same result. LeetCode 996 Number of Squareful Arrays uses the same skip rule.

```python
def permute_unique(nums):
    nums.sort()
    used, path, out = [False] * len(nums), [], []
    def go():
        if len(path) == len(nums):
            out.append(path[:])
            return
        for i in range(len(nums)):
            if used[i] or (i > 0 and nums[i] == nums[i - 1] and not used[i - 1]):
                continue
            used[i] = True
            path.append(nums[i])
            go()
            path.pop()
            used[i] = False
    go()
    return out
```

Time is $O(n)$ per result plus pruned branches. The usual mistake is forgetting to sort, which leaves equal values apart so the neighbour check never fires.

### Next Permutation

LeetCode 31 Next Permutation asks for the next arrangement in lexicographic order, in place. Scanning from the right, the longest non-increasing suffix is already the largest possible ordering of its items, so nothing inside it can grow. The change must happen just before it.

The algorithm has three steps. First, find the pivot: the largest index $i$ with $a[i] < a[i+1]$. If there is none, the array is the last permutation and you reverse it all to get the first. Second, find the rightmost $j > i$ with $a[j] > a[i]$ and swap $a[i]$ and $a[j]$. Third, reverse the suffix after $i$, which turns it from largest to smallest.

For `1 3 5 4 2`, the pivot is `3`, the rightmost larger value in the suffix is `4`, swapping gives `1 4 5 3 2`, and reversing the suffix gives `1 4 2 3 5`.

```python
def next_permutation(a):
    i = len(a) - 2
    while i >= 0 and a[i] >= a[i + 1]:
        i -= 1
    if i >= 0:
        j = len(a) - 1
        while a[j] <= a[i]:
            j -= 1
        a[i], a[j] = a[j], a[i]
    a[i + 1:] = reversed(a[i + 1:])
```

It runs in $O(n)$ time and $O(1)$ extra space, and the same routine solves LeetCode 556 Next Greater Element III. The most common mistake is using strict comparisons (`>` and `<`) in the two scans, which picks the wrong pivot or swap target when values repeat.

### The k-th Permutation

LeetCode 60 Permutation Sequence asks for the $k$-th permutation of $1, \ldots, n$. Generating $k$ permutations would be far too slow, but the answer can be read off directly. Among the $n!$ orderings, the first $(n-1)!$ start with the smallest element, the next $(n-1)!$ with the second smallest, and so on.

So with a 0-based rank $k$, the first element is the one at index $\lfloor k/(n-1)! \rfloor$ among the remaining elements, then $k$ becomes $k \bmod (n-1)!$ and you repeat with $(n-2)!$. The sequence of indices is the representation of $k$ in the factorial number system (also called the Lehmer code). For $n = 4$ and 1-based $k = 9$, the 0-based rank is 8: $8 = 1 \cdot 3! + 1 \cdot 2! + 0 \cdot 1! + 0 \cdot 0!$, which picks `2`, then `3`, then `1`, then `4`, giving `2314`.

```python
from math import factorial

def kth_permutation(n, k):
    items = list(range(1, n + 1))
    k -= 1                                # switch to a 0-based rank
    out = []
    for size in range(n, 0, -1):
        idx, k = divmod(k, factorial(size - 1))
        out.append(items.pop(idx))
    return "".join(map(str, out))
```

This is $O(n^2)$ because of the list removals, which is nothing for $n \le 9$. Running the same idea backwards gives the rank of a given permutation. The most common mistake is forgetting to convert $k$ from 1-based to 0-based, which shifts the answer by one permutation.

## Selection with Repetition

Subsets and permutations without repetition use each element at most once. Cartesian products and powers allow the same value in different positions. If reuse is allowed, the counting flips in a really clean way: “no repetition” tends to create factorials and falling factorials; “repetition allowed” tends to create powers and stars-and-bars.

> **First step:** Ask whether the things being placed are identical or distinguishable, and whether the slots or bins are ordered. Distinct choices in ordered positions with reuse give a plain power, while identical items dropped into distinct bins give stars and bars.

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

A useful variant of stars and bars requires every bin to get at least one item. Put one item in each of the $n$ bins first, then distribute the remaining $k - n$ freely, which gives $\binom{k-1}{n-1}$ ways for $k \ge n \ge 1$.

## Catalan Numbers

> **First step:** If a problem counts nested or recursive structures (balanced brackets, tree shapes, ways to split a sequence around a root), compute the first few answers by hand. If you see 1, 1, 2, 5, 14, 42, you are looking at Catalan numbers.

The Catalan numbers count structures that split into a left part and a right part around one chosen piece. They start at $C_0 = 1$ and follow the recurrence

$$C_{n+1} = \sum_{i=0}^{n} C_i \, C_{n-i}$$

with the closed form

$$C_n = \frac{1}{n+1}\binom{2n}{n} = \binom{2n}{n} - \binom{2n}{n+1}$$

LeetCode 96 Unique Binary Search Trees is the recurrence directly: pick root $r$ among $n$ keys, the left subtree holds $r-1$ keys and the right subtree $n-r$, and the shapes multiply. LeetCode 22 Generate Parentheses lists the $C_n$ balanced strings with $n$ pairs, and LeetCode 95 Unique Binary Search Trees II lists the trees. The same numbers count polygon triangulations and grid paths that never cross the diagonal.

```python
def num_trees(n):
    dp = [1] + [0] * n
    for nodes in range(1, n + 1):
        for root in range(1, nodes + 1):
            dp[nodes] += dp[root - 1] * dp[nodes - root]
    return dp[n]
```

The recurrence costs $O(n^2)$ and the closed form $O(n)$, while listing all structures costs about $n \cdot C_n$, and $C_n$ grows roughly like $4^n / n^{3/2}$. For 22, the most common mistake is allowing a closing bracket whenever fewer than $n$ have been used; the correct rule is to add `)` only while the number of closes is below the number of opens.

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

## Inclusion-Exclusion

> **First step:** Look for the words "at least one", "or", or "divisible by any of". Decide whether it is easier to count the union directly with inclusion-exclusion or to count the complement ("none of them") and subtract from the total.

Adding the sizes of overlapping sets counts the overlaps more than once. Inclusion-exclusion corrects this by alternately subtracting and adding the intersections:

$$|A \cup B| = |A| + |B| - |A \cap B|$$

$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

A small example: among $1, \ldots, 30$, there are 15 multiples of 2, 10 multiples of 3, and 5 multiples of 6, so $15 + 10 - 5 = 20$ numbers are divisible by 2 or 3. For divisibility, the intersection of "multiples of $a$" and "multiples of $b$" is the multiples of $\operatorname{lcm}(a, b)$, not of $a \cdot b$.

LeetCode 1201 Ugly Number III combines this with binary search. Count the numbers up to $x$ divisible by $a$, $b$ or $c$, then search for the smallest $x$ whose count reaches $n$.

```python
from math import lcm

def nth_ugly_number(n, a, b, c):
    ab, ac, bc, abc = lcm(a, b), lcm(a, c), lcm(b, c), lcm(a, b, c)
    def count(x):
        return (x // a + x // b + x // c
                - x // ab - x // ac - x // bc + x // abc)
    lo, hi = 1, 2 * 10**9
    while lo < hi:
        mid = (lo + hi) // 2
        if count(mid) >= n:
            hi = mid
        else:
            lo = mid + 1
    return lo
```

With $m$ sets, loop over every nonempty mask of the $m$ sets and add the intersection size when the mask has an odd number of bits, subtracting it when even. That is $2^m$ terms, fine for $m$ up to about 20. The most common mistake is using the product $a \cdot b$ instead of $\operatorname{lcm}(a, b)$ when the numbers share a factor.

## Sets as Bits: XOR and Bit Tricks

> **First step:** Check whether the universe is small (at most 32 or 64 distinct items) or whether the problem is about values that "appear twice" or "appear once". Small universes fit in an integer used as a set, and pairing problems usually collapse under XOR.

An integer whose bit $i$ means "item $i$ is present" is a set, and the bitwise operators are the set operations. `a | b` is the union, `a & b` the intersection, `a & ~b` the difference, and `a ^ b` the symmetric difference. Add item $i$ with `a | (1 << i)`, remove it with `a & ~(1 << i)`, and complement within $n$ bits with `a ^ ((1 << n) - 1)`.

Two expressions show up constantly. `x & (x - 1)` removes the lowest set bit, and `x & -x` isolates it. LeetCode 231 Power of Two is `n > 0 and n & (n - 1) == 0`. LeetCode 191 Number of 1 Bits repeats `n &= n - 1` and counts the steps, so it runs once per set bit. LeetCode 338 Counting Bits fills a table with `bits[i] = bits[i >> 1] + (i & 1)`, because shifting right drops only the last bit.

XOR acts like toggling membership: $x \oplus x = 0$, $x \oplus 0 = x$, and the order does not matter. XOR all values in LeetCode 136 Single Number and every pair cancels, leaving the single value. LeetCode 268 Missing Number XORs the indices $0, \ldots, n$ with the values, so every present number cancels and only the missing one remains. LeetCode 137 Single Number II, where the others appear three times, counts each bit position modulo 3 instead (in Python, reinterpret bit 31 as the sign at the end).

LeetCode 260 Single Number III has two unique values $a$ and $b$. XOR of everything is $a \oplus b$, which is nonzero, so pick any set bit of it; $a$ and $b$ differ there. Split all numbers by that bit and XOR each group separately.

```python
def single_number_iii(nums):
    x = 0
    for v in nums:
        x ^= v
    low = x & -x            # a bit where the two answers differ
    a = 0
    for v in nums:
        if v & low:
            a ^= v
    return [a, x ^ a]
```

All of these run in $O(n)$ time and $O(1)$ extra space, or $O(1)$ per bit operation. The most common mistake is precedence in C and C++, where `n & n - 1 == 0` parses as `n & ((n - 1) == 0)` (Java rejects it outright), so always write `(n & (n - 1)) == 0`.

## Set Operations with Hash Sets

> **First step:** Decide whether duplicates matter. A plain set answers "is it present", while a counter (multiset) answers "how many times", and problems like intersection come in both flavours.

When the universe is large, a hash set gives $O(1)$ average membership tests and turns many sorting solutions into linear ones. LeetCode 217 Contains Duplicate is `len(set(nums)) < len(nums)`. LeetCode 349 Intersection of Two Arrays is a set intersection, while LeetCode 350 Intersection of Two Arrays II keeps multiplicities, which in Python is `(Counter(a) & Counter(b)).elements()` and takes the minimum count of each value.

LeetCode 128 Longest Consecutive Sequence needs $O(n)$ time. Put all values in a set and only start counting from values $x$ where $x - 1$ is missing, since those are the starts of runs. Each value is then visited at most twice.

```python
def longest_consecutive(nums):
    s = set(nums)
    best = 0
    for x in s:
        if x - 1 not in s:          # x starts a run
            y = x
            while y + 1 in s:
                y += 1
            best = max(best, y - x + 1)
    return best
```

LeetCode 41 First Missing Positive asks for the same idea in $O(1)$ extra space. The answer is always in $1, \ldots, n+1$, so the array itself can serve as the set: swap each value $v$ in that range into index $v - 1$, repeating at each position until it holds the right value or a duplicate, then the first index $i$ with $a[i] \ne i + 1$ gives the answer $i + 1$. Compute the target index before swapping, because `a[i], a[a[i] - 1] = a[a[i] - 1], a[i]` in Python assigns `a[i]` first and then reads the wrong slot.

Set relationships also drive counting problems such as LeetCode 2306 Naming a Company. Group the suffixes by first letter; for two letters with suffix sets $S$ and $T$, the valid pairs number $(|S| - |S \cap T|)(|T| - |S \cap T|)$, doubled for the two orders. Iterating over the 26 by 26 letter pairs keeps it fast.

Hash-set operations run in $O(n)$ average time and space. The most common mistake in 128 is looping over `nums` instead of the set, which repeats the inner walk for duplicated run starts and can degrade toward quadratic time.

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

### More Counting Formulas

Many interview counting problems reduce to one of a short list of formulas. Identify the structure first, then look up the count.

| Situation | Count | Example problem |
| --- | --- | --- |
| Sequences of length $k$ from $n$ symbols, reuse allowed | $n^k$ | PIN codes of length $k$ |
| All subsets of $n$ items | $2^n$ | 78 Subsets |
| Orderings of $n$ distinct items | $n!$ | 46 Permutations |
| Ordered picks of $k$ from $n$, no reuse | $n!/(n-k)!$ | arranging $k$ of $n$ people in a row |
| Unordered picks of $k$ from $n$ | $\binom{n}{k}$ | 77 Combinations |
| Multisets of size $k$ from $n$ types | $\binom{n+k-1}{k}$ | $k$ scoops from $n$ ice cream flavours |
| $k$ identical items into $n$ bins, none empty | $\binom{k-1}{n-1}$ | splitting $k$ into $n$ positive parts |
| Orderings of a multiset with counts $m_1, \ldots, m_r$ summing to $N$ | $N!/(m_1! \cdots m_r!)$ | 47 Permutations II |
| Right and down paths in an $m \times n$ grid | $\binom{m+n-2}{m-1}$ | 62 Unique Paths |
| Balanced strings of $n$ bracket pairs, BST shapes on $n$ keys | $\frac{1}{n+1}\binom{2n}{n}$ | 22 Generate Parentheses, 96 Unique BSTs |
| (mask, submask) pairs over $n$ bits | $3^n$ | DP over subsets |
| Nonempty subsets of $m$ sets in inclusion-exclusion | $2^m - 1$ | 1201 Ugly Number III |

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

## Reading the Problem Statement

Most problems in this area announce their structure in a few stock phrases. Matching those phrases to a technique before writing any code saves you from building the wrong search.

| If the problem says | What it means for your code |
| --- | --- |
| "order does not matter", "choose", "groups", "teams" | Combinations: generate with a start index, count with $\binom{n}{k}$ |
| "arrangements", "orderings", "order matters" | Permutations: track used items, count with $n!$ or $n!/(n-k)!$ |
| "all possible subsets" or "the power set" | Loop masks from $0$ to $2^n - 1$ or recurse take/skip |
| "each element may be used unlimited times" | Recurse with the same index, not the next one; counts become powers or stars and bars |
| "may contain duplicates" and "no duplicate answers" | Sort and skip equal neighbours at the same depth; counts divide by repeated factorials |
| "return the answer modulo $10^9+7$" | Reduce after every addition and multiplication, and replace division with a modular inverse |
| $n$ up to 20 | $2^n$ is about a million, so bitmask enumeration or bitmask DP is fine |
| $n$ up to 15 or so with "split into groups" | Submask enumeration at $3^n$ total is affordable |
| $n$ up to 8 to 10 | Listing all permutations is feasible |
| $n$ up to $10^5$ or more and "number of ways" | Use a formula with precomputed factorials, never enumeration |
| "the $k$-th permutation" or "the $k$-th in lexicographic order" | Build it directly with the factorial number system |
| "the next greater arrangement" or "next lexicographic order" | Next permutation: find pivot, swap with rightmost larger, reverse suffix |
| "every element appears twice except one" | XOR everything so the pairs cancel |
| "every element appears three times except one" | Count each bit position modulo 3 |
| "adjacent values differ by exactly one bit" | Gray code, `i ^ (i >> 1)` |
| "divisible by a, b or c" or "at least one of" | Inclusion-exclusion with lcm, or count the complement |
| "valid parentheses" or "structurally unique BSTs" | Catalan numbers, by recurrence or closed form |
| "O(n) time" on unsorted values, or "O(1) extra space" with values in 1 to n | Hash set, or use the array itself as the set by index |
