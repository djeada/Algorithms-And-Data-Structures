## Searching

Searching is the task of finding whether a particular value exists in a collection and, if it does, where it lives (its index, pointer, node, or associated value). It shows up everywhere: checking if a username is taken, locating a record in a database, finding a file in an index, routing packets, or matching a word inside a document. The “shape” of your data—unsorted list, sorted array, hash table, tree, or text stream—determines what kinds of search strategies are possible and how fast they can be.

Good search choices are really about trade-offs. A linear scan is universal and simple but grows slower as data grows; binary search is dramatically faster but requires sorted data; hash-based lookup is usually constant-time but depends on hashing quality and memory overhead; probabilistic filters trade perfect accuracy for huge space savings. Understanding these options helps you design systems that scale cleanly and keeps your code practical: fast where it needs to be, predictable under load, and correct for the guarantees your application requires.

### Which Search Should I Use?

Choosing the right search algorithm depends on your data structure, constraints, and use case. Use this decision guide to quickly identify the best approach:

The fastest way to pick correctly is to start from your constraints, not from the algorithm names. Ask: **Is the data sorted?** **Do I need exact matches or “probably in set”?** **Am I searching text or keys?** If you answer those, most options eliminate themselves.

#### For Arrays and Lists

**Unsorted data + need exact match?**

* **Linear Search** ,  Simple scan left-to-right; $O(n)$ time, works on any list
* **Sentinel Linear Search** ,  Slight optimization removing bounds checks; still $O(n)$

**Sorted array + random access?**

* **Binary Search** (default choice) ,  Repeatedly halve the search space; $O(\log n)$ time

  * *When target likely near start or unknown bounds?* → **Exponential Search** ,  Double index until range found, then binary search
  * *Values uniformly distributed numeric?* → **Interpolation Search** ,  Estimate position based on value; expected $O(\log \log n)$ but can degrade to $O(n)$
  * *Want blocky scanning behavior?* → **Jump Search** ,  Jump by $\sqrt{n}$ blocks, then linear scan; $O(\sqrt{n})$ time; better cache locality than binary in some cases

**Sorted array + finding first/last occurrence?**

* **Binary Search variant** ,  Adjust binary search to continue after finding match

A practical note: if you will search the same array many times, sorting up front can be worth it even if sorting costs $O(n\log n)$. If you only search once, sorting may be wasted work.

#### For Key-Based Lookup and Membership

**Key → value lookup or set membership?**

* **Hash Tables** ,  Expected $O(1)$ lookup with good hash function and load factor

  * *Collision resolution:* Choose based on your needs:

    * **Separate Chaining** ,  Lists/arrays per bucket; easiest deletions; steady performance at α ≈ 1
    * **Linear Probing** ,  Simple and cache-friendly; watch for primary clustering; keep α < 0.7
    * **Quadratic Probing** ,  Reduces primary clustering; use prime table sizes
    * **Double Hashing** ,  Best probe distribution; minimizes clustering; slightly more complex
    * **Cuckoo Hashing** ,  Guarantees $O(1)$ worst-case lookup (checks 2 positions); insertions may trigger rehashing

Hash tables are the default when you want speed and don’t care about order. The “gotcha” is that hash tables only stay fast if you keep them from getting too full and you use a good hash function.

#### For Approximate Membership (Space-Efficient)

**Need to test "is element in set?" with space priority?**

* **Bloom Filter** ,  Probabilistic membership; answers "maybe present" or "definitely not"; no false negatives; no deletions
* **Counting Bloom Filter** ,  Like Bloom but supports deletions via counters; uses more space
* **Cuckoo Filter** ,  Space-efficient with deletions; high load factors (90%+); better performance than Bloom in many cases

Approximate membership structures are built for one move: quickly rejecting items that are *definitely not* present. They save time and memory by allowing **false positives** (“maybe present”), but never **false negatives** (“definitely not” is always correct).

#### For Substring/Pattern Search

**Need to find pattern in text?**

* **Naive String Search** ,  Simple sliding window; $O(n \cdot m)$ worst case; fine for short patterns
* **Knuth–Morris–Pratt (KMP)** ,  Guaranteed $O(n + m)$; uses failure function to avoid rechecks; best all-rounder
* **Boyer–Moore (BM)** ,  Often fastest in practice; scans right-to-left with smart skips; excellent for long patterns and large alphabets
* **Rabin–Karp (RK)** ,  Rolling hash comparison; $O(n + m)$ expected; great for multiple patterns or streaming data

Text search is its own world because matching strings has structure you can exploit: repeated prefixes, character distributions, and the fact that mismatches can let you skip big chunks of work.

#### Quick Comparison Table

| Use Case                     | Data Type    | Algorithm                      | Time Complexity      | Notes                           |
| ---------------------------- | ------------ | ------------------------------ | -------------------- | ------------------------------- |
| Unsorted lookup              | Array        | Linear Search                  | $O(n)$               | Simple, works anywhere          |
| Sorted lookup                | Array        | Binary Search                  | $O(\log n)$          | Default for sorted arrays       |
| Target near start            | Sorted Array | Exponential Search             | $O(\log p)$          | p = position found              |
| Uniform distribution         | Sorted Array | Interpolation Search           | $O(\log \log n)$ avg | Can degrade to $O(n)$           |
| Block-based scan             | Sorted Array | Jump Search                    | $O(\sqrt{n})$        | Better cache locality           |
| Key-value pairs              | Hash Table   | Hash + Chaining/Probing        | $O(1)$ expected      | Depends on load factor          |
| Guaranteed O(1) lookup       | Cuckoo Hash  | Cuckoo Hashing                 | $O(1)$ worst         | 2 hash positions                |
| Set membership (space-first) | Bit Array    | Bloom Filter                   | $O(k)$               | k = hash functions; FPR tunable |
| Set with deletions           | Counters     | Counting Bloom / Cuckoo Filter | $O(k)$               | Supports removal                |
| Substring search             | String       | KMP                            | $O(n + m)$           | Guaranteed linear time          |
| Substring (fast average)     | String       | Boyer–Moore                    | $O(n/m)$ avg         | Best for long patterns          |
| Multiple patterns            | String       | Rabin–Karp                     | $O(n + m)$           | Rolling hash enables batching   |

### Linear & Sequential Search

Linear search is the baseline: it requires no assumptions and no preprocessing, which is exactly why it still matters. If your data is tiny, frequently changing, or you only search once, linear search is often “good enough” and the simplest correct solution.

#### Linear Search

Scan the list from left to right, comparing the target with each element until you either find a match (return its index) or finish the list (report “not found”).

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } [7, 3, 5, 2, 9], \quad \text{target} = 5
$$

$$
\text{Output: } \text{index} = 2
$$

*Example 2*

$$
\text{Input: } [4, 4, 4], \quad \text{target} = 4
$$

$$
\text{Output: } \text{index} = 0  (\text{first match})
$$

*Example 3*

$$
\text{Input: } [10, 20, 30], \quad \text{target} = 25
$$

$$
\text{Output: } \text{not found}
$$

**How Linear Search Works**

We start at index `0`, compare the value with the target, and keep moving right until we either **find it** or reach the **end**.

Target **5** in `[7, 3, 5, 2, 9]`

```
Indexes:   0    1    2    3    4
List:     [7]  [3]  [5]  [2]  [9]
Target: 5
```

*Step 1:* pointer at index 0

```
|
v
7   3   5   2   9

→ compare 7 vs 5  → no
```

*Step 2:* pointer moves to index 1

```
    |
    v
7   3   5   2   9

→ compare 3 vs 5  → no
```

*Step 3:* pointer moves to index 2

```
        |
        v
7   3   5   2   9

→ compare 5 vs 5  → YES ✅ → return index 2
```

**Worst Case (Not Found)**

Target **9** in `[1, 2, 3]`

```
Indexes:   0    1    2
List:     [1]  [2]  [3]
Target: 9
```

Checks:

```
→  1 ≠ 9
→  2 ≠ 9
→  3 ≠ 9
→  end
→ not found ❌
```

* Works on any list; no sorting or structure required.
* Returns the first index containing the target; if absent, reports “not found.”
* Time: $O(n)$ comparisons on average and in the worst case; best case $O(1)$ if the first element matches.
* Space: $O(1)$ extra memory.
* Naturally finds the earliest occurrence when duplicates exist.
* Simple and dependable for short or unsorted data.
* Assumes 0-based indexing in these notes.

#### Sentinel Linear Search

Place one copy of the target at the very end as a “sentinel” so the scan can run without checking bounds each step; afterward, decide whether the match was inside the original list or only at the sentinel position.

Sentinel search is the same algorithm with a small engineering twist: remove a bounds check from the loop. That doesn’t change big-O, but in performance-sensitive code it can matter, especially in low-level languages where bounds checks are not free.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } [12, 8, 6, 15], \quad \text{target} = 6
$$

$$
\text{Output: } \text{index} = 2
$$

*Example 2*

$$
\text{Input: } [2, 4, 6, 8], \quad \text{target} = 5
$$

$$
\text{Output: } \text{not found }  (\text{only the sentinel matched})
$$

**How it works**

Put the target at one extra slot at the end so the loop is guaranteed to stop on a match; afterward, check whether the match was inside the original range.

Target **11** not in the list

```
Original list (n=5):
[ 4 ][ 9 ][ 1 ][ 7 ][ 6 ]
Target: 11
```

Add sentinel (extra slot):

```
[ 4 ][ 9 ][ 1 ][ 7 ][ 6 ][ 11 ]
  0    1    2    3    4     5  ← sentinel
```

Scan step by step:

```
4 ≠ 11   → pointer at 0
9 ≠ 11   → pointer at 1
1 ≠ 11   → pointer at 2
7 ≠ 11   → pointer at 3
6 ≠ 11   → pointer at 4
11 = 11  → pointer at 5 (sentinel)
```

Therefore, **not found** in original list.

Target **6** inside the list

```
Original list (n=4):
[ 12 ][ 8 ][ 6 ][ 15 ]
Target: 6
```

Add sentinel:

```
[ 12 ][ 8 ][ 6 ][ 15 ][ 6 ]
  0     1    2    3     4
```

Scan:

```
12 ≠ 6   → index 0
 8 ≠ 6   → index 1
 6 = 6   → index 2 ✅
```

* Removes the per-iteration “have we reached the end?” check; the sentinel guarantees termination.
* Same $O(n)$ time in big-O terms, but slightly fewer comparisons in tight loops.
* Space: needs one extra slot; if you cannot append, you can temporarily overwrite the last element (store it, write the target, then restore it).
* After scanning, decide by index: if the first match index < original length, it’s a real match; otherwise, it’s only the sentinel.
* Use when micro-optimizing linear scans over arrays where bounds checks are costly.
* Behavior with duplicates: still returns the first occurrence within the original range.
* Be careful to restore any overwritten last element if you used the in-place variant.

### Divide & Conquer Search

Divide-and-conquer search algorithms assume structure, almost always sorted order, and then exploit it to throw away most of the search space quickly. The “why you should care” is simple: when $n$ gets big, cutting the problem in half repeatedly is the difference between instant and unbearable.

#### Binary Search

On a sorted array, repeatedly halve the search interval by comparing the target to the middle element until found or the interval is empty.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } A = [2, 5, 8, 12, 16, 23, 38], \quad \text{target} = 16
$$

$$
\text{Output: } \text{index} = 4
$$

*Example 2*

$$
\text{Input: } A = [1, 3, 3, 3, 9], \quad \text{target} = 3
$$

$$
\text{Output: } \text{index} = 2 \quad (\text{any valid match; first/last needs a variant})
$$

*Example 3*

$$
\text{Input: } A = [10, 20, 30, 40], \quad \text{target} = 35
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

We repeatedly check the **middle** element, and then discard half the list based on comparison.

Find **16** in:

```
A = [  2 ][  5 ][  8 ][ 12 ][ 16 ][ 23 ][ 38 ]
i =    0     1     2     3     4     5     6
```

*Step 1*

```
low = 0, high = 6
mid = (0+6)//2 = 3
A[3] = 12 < 16  →  target is to the RIGHT  →  new low = mid + 1 = 4

A = [  2 ][  5 ][  8 ][ 12 ][ 16 ][ 23 ][ 38 ]
i =    0     1     2     3     4     5     6
        ↑L                ↑M                ↑H
        0                 3                 6
Active range: indices 0..6
```

*Step 2*

```
low = 4, high = 6
mid = (4+6)//2 = 5
A[5] = 23 > 16  →  target is to the LEFT   →  new high = mid - 1 = 4

A = [  2 ][  5 ][  8 ][ 12 ][ 16 ][ 23 ][ 38 ]
i =    0     1     2     3     4     5     6
                              ↑L      ↑M      ↑H
                              4       5       6
Active range: indices 4..6
```

*Step 3*

```
low = 4, high = 4
mid = 4
A[4] = 16 == target ✅

A = [  2 ][  5 ][  8 ][ 12 ][ 16 ][ 23 ][ 38 ]
i =    0     1     2     3     4     5     6
                              ↑LMH
                              4
Active range: indices 4..4
```

FOUND at index 4

* Requires a sorted array (assume ascending here).
* Time: $O(log n)$; Space: $O(1)$ iterative.
* Returns any one matching index by default; “first/last occurrence” is a small, common refinement.
* Robust, cache-friendly, and a building block for many higher-level searches.
* Beware of off-by-one errors when shrinking bounds.

A common refinement in real work is “find the first/last occurrence.” The trick is not to stop when you see the target, keep going left (or right) while preserving correctness. Same structure, slightly different termination condition.

#### Ternary Search

Like binary, but splits the current interval into three parts using two midpoints; used mainly for unimodal functions or very specific array cases.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } A = [1, 4, 7, 9, 12, 15], \quad \text{target} = 9
$$

$$
\text{Output: } \text{index} = 3
$$

*Example 2*

$$
\text{Input: } A = [2, 6, 10, 14], \quad \text{target} = 5
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

We divide the array into **three parts** using two midpoints `m1` and `m2`.

* If `target < A[m1]` → search $[low .. m1-1]$
* Else if `target > A[m2]` → search $[m2+1 .. high]$
* Else → search $[m1+1 .. m2-1]$

```
A = [  1 ][  4 ][  7 ][  9 ][ 12 ][ 15 ]
i =    0     1     2     3     4     5
Target: 9
```

*Step 1*

```
low = 0, high = 5

m1 = low + (high - low)//3  = 0 + (5)//3 = 1
m2 = high - (high - low)//3 = 5 - (5)//3 = 3

A[m1] = 4
A[m2] = 9

A = [  1 ][  4 ][  7 ][  9 ][ 12 ][ 15 ]
i =    0     1     2     3     4     5
        ↑L    ↑m1        ↑m2           ↑H
        0     1          3             5
```

FOUND at index 3

* Also assumes a sorted array.
* For discrete sorted arrays, it does **not** beat binary search asymptotically; it performs more comparisons per step.
* Most valuable for searching the extremum of a **unimodal function** on a continuous domain; for arrays, prefer binary search.
* Complexity: $O(log n)$ steps but with larger constant factors than binary search.

#### Jump Search

On a sorted array, jump ahead in fixed block sizes to find the block that may contain the target, then do a linear scan inside that block.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } A = [1, 4, 9, 16, 25, 36, 49], \quad \text{target} = 25, \quad \text{jump} = \lfloor \sqrt{7} \rfloor = 2
$$

$$
\text{Output: } \text{index} = 4
$$

*Example 2*

$$
\text{Input: } A = [3, 8, 15, 20, 22, 27], \quad \text{target} = 21, \quad \text{jump} = 2
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

Here’s a clear trace of **jump search** in action:

We’re applying **jump search** to find $25$ in

$$
A = [1, 4, 9, 16, 25, 36, 49]
$$

with $n=7$, block size $\approx \sqrt{7} \approx 2$, so **jump=2**.

We probe every 2nd index:

* probe = 0 → $A[0] = 1 < 25$ → jump to 2
* probe = 2 → $A[2] = 9 < 25$ → jump to 4
* probe = 4 → $A[4] = 25 \geq 25$ → stop

So target is in block $(2..4]$

```
[ 1 ][ 4 ] | [ 9 ][16 ] | [25 ][36 ] | [49 ]
    ^            ^            ^            ^
   probe=0      probe=2      probe=4      probe=6
```

Linear Scan in block (indexes 3..4)

* i = 3 → $A[3] = 16 < 25$
* i = 4 → $A[4] = 25 = 25$ ✅ FOUND

```
Block [16 ][25 ]
       ^    ^
      i=3  i=4 (found!)
```

The element $25$ is found at **index 4**.

* Works on sorted arrays; pick jump ≈ √n for good balance.
* Time: $O(√n)$ comparisons on average; Space: $O(1)$.
* Useful when binary search isn’t desirable: binary search has poor locality (random jumps); jump search scans a block sequentially, which is more cache-friendly and has better branch prediction.
* Degrades gracefully to “scan block then stop.”

#### Exponential Search

On a sorted array, grow the right boundary exponentially (1, 2, 4, 8, …) to find a containing range, then finish with binary search in that range.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } A = [2, 3, 5, 7, 11, 13, 17, 19, 23], \quad \text{target} = 19
$$

$$
\text{Output: } \text{index} = 7
$$

*Example 2*

$$
\text{Input: } A = [10, 20, 30, 40, 50], \quad \text{target} = 12
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

```
A = [  2 ][  3 ][  5 ][  7 ][ 11 ][ 13 ][ 17 ][ 19 ][ 23 ]
i =    0     1     2     3    4     5     6     7     8
Target = 19
```

Find range by exponential jumps

*Start* at `i=1`, double each step until `A[i] ≥ target` (or end).

*Jump 1:* `i=1`

```
A[i]=3 ≤ 19  → continue
...
```

*Jump 2:* `i=2`

```
A[i]=5 ≤ 19  → continue
...
```

*Jump 3:* `i=4`

```
A[i]=11 ≤ 19 → continue
...
```

*Jump 4:* `i=8`

```
A[i]=23 > 19  → stop
Range is (previous power of two .. i] = (4 .. 8] → search indices 5..8
...
```

*Range for binary search:* `low=5, high=8`.

Binary search on $A[5..8]$

```
Subarray: [ 13 ][ 17 ][ 19 ][ 23 ]
Indices :    5     6     7     8
```

*Step 1*

```
low=5, high=8 → mid=(5+8)//2=6
A[6]=17 < 19 → move right → low=7
...
```

*Step 2*

```
low=7, high=8 → mid=(7+8)//2=7
A[7]=19 == target ✅ → FOUND
...
```

Found at **index 7**.

* Great when the target is likely to be near the beginning or when the array is **unbounded**/**stream-like** but sorted (you can probe indices safely).
* Time: $O(log p)$ to find the range where p is the final bound, plus $O(log p)$ for binary search → overall $O(log p)$.
* Space: $O(1)$.
* Often paired with data sources where you can test “is index i valid?” while doubling i.

#### Interpolation Search

On a sorted (roughly uniformly distributed) array, estimate the likely position using the values themselves and probe there; repeat on the narrowed side.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } A = [10, 20, 30, 40, 50, 60, 70], \quad \text{target} = 55
$$

$$
\text{Output: } \text{not found }  (\text{probes near indices } 4\text{–}5)
$$

*Example 2*

$$
\text{Input: } A = [5, 15, 25, 35, 45, 55, 65], \quad \text{target} = 45
$$

$$
\text{Output: } \text{index} = 4
$$

*Example 3*

$$
\text{Input: } A = [1, 1000, 1001, 1002], \quad \text{target} = 2
$$

$$
\text{Output: } \text{not found }  (\text{bad distribution for interpolation})
$$

**How it works**

* Guard against division by zero: if `A[high] == A[low]`, stop (or binary-search fallback).
* Clamp the computed `pos` to `[low, high]` before probing.
* Works best when values are **uniformly distributed**; otherwise it can degrade toward linear time.
* Assumes `A` is sorted and values are uniform.

Probe formula:

```
pos ≈ low + (high - low) * (target - A[low]) / (A[high] - A[low])
```

Let's say we have the following array and target:

```
A = [ 10 ][ 20 ][ 30 ][ 40 ][ 50 ][ 60 ][ 70 ]
i =    0     1     2     3     4     5     6
target = 45
```

*Step 1 ,  initial probe*

```
low=0 (A[0]=10), high=6 (A[6]=70)

pos ≈ 0 + (6-0) * (45-10)/(70-10)
    ≈ 6 * 35/60
    ≈ 3.5  → probe near 3.5
...
```

Probe **index 3**: `A[3]=40 < 45` → set `low = 3 + 1 = 4`

*Step 2 ,  after moving low*

```
A = [ 10 ][ 20 ][ 30 ][ 40 ][ 50 ][ 60 ][ 70 ]
...
```

At this point, an **early-stop check** already tells us `target (45) < A[low] (50)` → cannot exist in `A[4..6]` → **not found**.

* Best on **uniformly distributed** sorted data; expected time $O(log log n)$.
* Worst case can degrade to $O(n)$, especially on skewed or clustered values.
* Space: $O(1)$.
* Very fast when value-to-index mapping is close to linear (e.g., near-uniform numeric keys).
* Requires careful handling when A[high] = A[low] (avoid division by zero); also sensitive to integer rounding in discrete arrays.

### Hash-based Search

Hash-based search is for when you want direct access by key. Instead of narrowing down ranges, you compute a location in (roughly) constant time. The cost is setup complexity: you need a hash function, a collision strategy, and resizing rules to keep performance stable.

* **Separate chaining:** Easiest deletions, steady $O(1)$ with α≈1; good when memory fragmentation isn’t a concern.
* **Open addressing (double hashing):** Best probe quality among OA variants; great cache locality; keep α < 0.8.
* **Open addressing (linear/quadratic):** Simple and fast at low α; watch clustering and tombstones.
* **Cuckoo hashing:** Tiny and predictable lookup cost; inserts costlier and may rehash; great for read-heavy workloads.
* In all cases: pick strong hash functions and resize early to keep α healthy.

#### Hash Table Search

Map a key to an array index with a hash function; look at that bucket to find the key, giving expected $O(1)$ lookups under a good hash and healthy load factor.

**Example inputs and outputs**

*Example 1*

$$
\text{Table size: } m = 7,
\quad \text{Keys stored: } {10, 24, 31},
\quad \text{Target: } 24
$$

$$
\text{Output: } \text{found (bucket 3)}
$$

*Example 2*

$$
\text{Table size: } m = 7,
\quad \text{Keys stored: } {10, 24, 31},
\quad \text{Target: } 18
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

```
+-----+      hash       +-----------------+      search/compare      +--------+
| key | --------------> | index in array  | ----------------------> | match? |
+-----+                  +-----------------+                         +--------+
```

* With chaining, the “collision path” is the **list inside one bucket**.
* With linear probing, the “collision path” is the **probe sequence** across buckets (3 → 4 → 5 → …).
* Both keep your original flow: hash → inspect bucket (and collision path) → match?

```
Array (buckets/indexes 0..6):

Idx:   0     1     2     3     4     5     6
      +---+-----+-----+-----+-----+-----+-----+
      |   |     |     |     |     |     |     |
      +---+-----+-----+-----+-----+-----+-----+
```

**Example mapping with** `h(k) = k mod 7`, **stored keys** `{10, 24, 31}` all hash to index `3`.

*Strategy A ,  Separate Chaining (linked list per bucket)*

Insertions

```
10 -> 3
24 -> 3   (collides with 10; append to bucket[3] list)
31 -> 3   (collides again; append to bucket[3] list)

Idx:   0     1     2     3     4     5     6
      +---+-----+-----+-----+-----+-----+-----+
      |   |     |     | •   |     |     |     |
      +---+-----+-----+-----+-----+-----+-----+

bucket[3] chain:  [10] → [24] → [31] → ∅
```

*Search(24)*

```
1) Compute index = h(24) = 3
2) Inspect bucket 3's chain:
      [10]  →  [24]  →  [31]
               ↑ found here
3) Return FOUND (bucket 3)
```

*Strategy B ,  Open Addressing (Linear Probing)*

Insertions

```
10 -> 3                    place at 3
24 -> 3  (occupied)  →  probe 4  → place at 4
31 -> 3  (occ) → 4 (occ) → probe 5 → place at 5

Idx:   0     1     2     3     4     5     6
      +---+-----+-----+-----+-----+-----+-----+
      |   |     |     | 10  | 24  | 31  |     |
      +---+-----+-----+-----+-----+-----+-----+
```

*Search(24)*

```
1) Compute index = h(24) = 3
2) Probe sequence:
      3: 10 ≠ 24  → continue
      4: 24 = target  → FOUND at index 4
   (If not found, continue probing until an empty slot or wrap limit.)
```

* Quality hash + low load factor (α = n/m) ⇒ expected $O(1)$ search/insert/delete.
* Collisions are inevitable; the collision strategy (open addressing vs. chaining vs. cuckoo) dictates actual steps.
* Rehashing (growing and re-inserting) is used to keep α under control.
* Uniform hashing assumption underpins the $O(1)$ expectation; adversarial keys or poor hashes can degrade performance.

#### Open Addressing ,  Linear Probing

Keep everything in one array; on collision, probe alternative positions in a deterministic sequence until an empty slot or the key is found.

**Example inputs and outputs**

*Example 1*

$$
m = 10,
\quad \text{Stored keys: } {12, 22, 32},
\quad \text{Target: } 22
$$

$$
\text{Output: } \text{found (index 3)}
$$

*Example 2*

$$
m = 10,
\quad \text{Stored keys: } {12, 22, 32},
\quad \text{Target: } 42
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

*Hash function:*

```
h(k) = k mod 10
Probe sequence: i, i+1, i+2, ... (wrap around)
```

*Insertions*

* Insert 12 → `h(12)=2` → place at index 2
* Insert 22 → `h(22)=2` occupied → probe 3 → place at 3
* Insert 32 → `h(32)=2` occupied → probe 3 (occupied) → probe 4 → place at 4

Resulting table (indexes 0..9):

```
Index:   0   1   2    3    4   5   6   7   8   9
        +---+---+----+----+----+---+---+---+---+---+
Value:  |   |   | 12 | 22 | 32 |   |   |   |   |   |
        +---+---+----+----+----+---+---+---+---+---+
```

*Search(22)*

* Start at `h(22)=2`
* index 2 → 12 ≠ 22 → probe →
* index 3 → 22 ✅ FOUND

Path followed:

```
2 → 3
```

*Search(42)*

* Start at `h(42)=2`
* index 2 → 12 ≠ 42 → probe →
* index 3 → 22 ≠ 42 → probe →
* index 4 → 32 ≠ 42 → probe →
* index 5 → empty slot → stop → ❌ NOT FOUND

Path followed:

```
2 → 3 → 4 → 5 (∅)
```

* Simple and cache-friendly; clusters form (“primary clustering”) which can slow probes.
* Deletion uses **tombstones** to keep probe chains intact.
* Performance depends sharply on load factor; keep α well below 1 (e.g., α ≤ 0.7).
* Expected search~ $O(1)$ at low α; degrades as clusters grow.

#### Open Addressing ,  Quadratic Probing

**Example inputs and outputs**

*Example 1*

$$
m = 11  (\text{prime}),
\quad \text{Stored keys: } {22, 33, 44},
\quad \text{Target: } 33
$$

$$
h(k) = k \bmod m, \quad h(33) = 33 \bmod 11 = 0
$$

$$
\text{Output: found (index 1)}
$$

*Example 2*

$$
m = 11  (\text{prime}),
\quad \text{Stored keys: } {22, 33, 44},
\quad \text{Target: } 55
$$

$$
h(55) = 55 \bmod 11 = 0
$$

$$
\text{Output: not found}
$$

**How it works**

*Hash function:*

```
h(k) = k mod 11
```

*Probe sequence (relative offsets):*

```
+1², +2², +3², +4², +5², ... mod 11
= +1, +4, +9, +5, +3, +3, +5, +9, +4, +1, ... (wrapping around table size)
```

So from `h(k)`, we try slots in this order:

```
h, h+1, h+4, h+9, h+5, h+3, ...   (all mod 11)
```

*Insertions*

* Insert **22** → `h(22)=0` → place at index 0
* Insert **33** → `h(33)=0` occupied → try `0+1²=1` → index 1 free → place at 1
* Insert **44** → `h(44)=0` occupied → probe 1 (occupied) → probe `0+4=4` → place at 4

Resulting table:

```
Idx:    0    1    2   3   4    5   6   7   8   9  10
      +----+----+---+---+----+---+---+---+---+---+---+
Val:  | 22 | 33 |   |   | 44 |   |   |   |   |   |   |
      +----+----+---+---+----+---+---+---+---+---+---+
```

*Search(33)*

* Start `h(33)=0` → slot 0 = 22 ≠ 33
* Probe `0+1²=1` → slot 1 = 33 ✅ FOUND

Path:

```
0 → 1
```

*Search(55)*

* Start `h(55)=0` → slot 0 = 22 ≠ 55
* Probe `0+1²=1` → slot 1 = 33 ≠ 55
* Probe `0+2²=4` → slot 4 = 44 ≠ 55
* Probe `0+3²=9` → slot 9 = empty → stop → ❌ NOT FOUND

Path:

```
0 → 1 → 4 → 9 (∅)
```

* Reduces primary clustering but can exhibit **secondary clustering** (keys with same h(k) follow same probe squares).
* Table size choice matters (often prime); ensure the probe sequence can reach many slots.
* Keep α modest; deletion still needs tombstones.
* Expected $O(1)$ at healthy α; simpler than double hashing.

#### Open Addressing ,  Double Hashing

**Example inputs and outputs**

*Hash functions*

$$
h_{1}(k) = k \bmod 11,
\quad h_{2}(k) = 1 + (k \bmod 10)
$$

Probing sequence:

$$
h(k,i) = \big(h_{1}(k) + i \cdot h_{2}(k)\big) \bmod 11
$$

*Example 1*

$$
m = 11,
\quad \text{Stored keys: } {22, 33, 44},
\quad \text{Target: } 33
$$

For $k = 33$:

$$
h_{1}(33) = 33 \bmod 11 = 0,
\quad h_{2}(33) = 1 + (33 \bmod 10) = 1 + 3 = 4
$$

So probe sequence is

$$
h(33,0) = 0,
h(33,1) = (0 + 1\cdot 4) \bmod 11 = 4,
h(33,2) = (0 + 2\cdot 4) \bmod 11 = 8, \dots
$$

Since the stored layout places $33$ at index $4$, the search succeeds.

$$
\text{Output: found (index 4)}
$$

*Example 2*

$$
m = 11,
\quad \text{Stored keys: } {22, 33, 44},
\quad \text{Target: } 55
$$

For $k = 55$:

$$
h_{1}(55) = 55 \bmod 11 = 0,
\quad h_{2}(55) = 1 + (55 \bmod 10) = 1 + 5 = 6
$$

Probing sequence:

$$
0,  (0+6)\bmod 11 = 6, (0+2\cdot 6)\bmod 11 = 1, (0+3\cdot 6)\bmod 11 = 7, \dots
$$

No slot matches $55$.

$$
\text{Output: not found}
$$

**How it works**

We use **two hash functions**:

```
h₁(k) = k mod m
h₂(k) = 1 + (k mod 10)
```

*Probe sequence:*

```
i, i + h₂, i + 2·h₂, i + 3·h₂, ...  (all mod m)
```

This ensures fewer clustering issues compared to linear or quadratic probing.

*Insertions (m = 11)*

Insert **22**

* `h₁(22)=0` → place at index 0

Insert **33**

* `h₁(33)=0` (occupied)
* `h₂(33)=1+(33 mod 10)=4`
* Probe sequence: 0, 4 → place at index 4

Insert **44**

* `h₁(44)=0` (occupied)
* `h₂(44)=1+(44 mod 10)=5`
* Probe sequence: 0, 5 → place at index 5

*Table State*

```
Idx:   0   1  2  3   4   5  6  7  8  9  10
      +---+---+---+---+---+---+---+---+---+---+
Val:  |22 |   |   |   |33 |44 |   |   |   |   |   |
      +---+---+---+---+---+---+---+---+---+---+---+
```

*Search(33)*

* Start at `h₁(33)=0` → slot 0 = 22 ≠ 33
* Next: `0+1·h₂(33)=0+4=4` → slot 4 = 33 ✅ FOUND

Path:

```
0 → 4
```

*Search(55)*

* `h₁(55)=0`, `h₂(55)=1+(55 mod 10)=6`
* slot 0 = 22 ≠ 55
* slot 6 = empty → stop → ❌ NOT FOUND

Path:

```
0 → 6 (∅)
```

* Minimizes clustering; probe steps depend on the key.
* Choose h₂ so it’s **non-zero** and relatively prime to m, ensuring a full cycle.
* Excellent performance at higher α than linear/quadratic, but still sensitive if α → 1.
* Deletion needs tombstones; implementation slightly more complex.

#### Separate Chaining

Each array cell holds a small container (e.g., a linked list); colliding keys live together in that bucket.

**Example inputs and outputs**

*Setup*

$$
m = 5, \quad h(k) = k \bmod 5, \quad \text{buckets hold linked lists}
$$

Keys stored:

$$
{12, 22, 7, 3, 14}
$$

Bucket contents after hashing:

$$
h(12) = 12 \bmod 5 = 2 \;\Rightarrow\; \text{bucket 2: } [12]
$$

$$
h(22) = 22 \bmod 5 = 2 \;\Rightarrow\; \text{bucket 2: } [12, 22]
$$

$$
h(7) = 7 \bmod 5 = 2 \;\Rightarrow\; \text{bucket 2: } [12, 22, 7]
$$

$$
h(3) = 3 \bmod 5 = 3 \;\Rightarrow\; \text{bucket 3: } [3]
$$

$$
h(14) = 14 \bmod 5 = 4 \;\Rightarrow\; \text{bucket 4: } [14]
$$

*Example 1*

$$
\text{Target: } 22
$$

$$
h(22) = 2 \Rightarrow \text{bucket 2} = [12, 22, 7]
$$

Found at **position 2** in the list.

$$
\text{Output: found (bucket 2, position 2)}
$$

*Example 2*

$$
\text{Target: } 9
$$

$$
h(9) = 9 \bmod 5 = 4 \Rightarrow \text{bucket 4} = [14]
$$

No match.

$$
\text{Output: not found}
$$

**How it works**

```
h(k) = k mod 5
Buckets store small lists (linked lists or dynamic arrays)

Idx:   0             1           2                    3            4
     [  ]         [  ]       [ 12 → 22 → 7 ]       [ 3 ]       [ 14 ]

Search(22):
- Compute bucket b = h(22) = 2
- Linearly scan bucket 2 → find 22

Search(9):
- b = h(9) = 4
- Bucket 4: [14] → 9 not present → NOT FOUND
```

* Simple deletes (remove from a bucket) and no tombstones.
* Expected $O(1 + α)$ time; with good hashing and α kept near/below 1, bucket lengths stay tiny.
* Memory overhead for bucket nodes; cache locality worse than open addressing.
* Buckets can use **ordered lists** or **small vectors** to accelerate scans.
* Rehashing still needed as n grows; α = n/m controls performance.

#### Cuckoo Hashing

Keep two (or more) hash positions per key; insert by “kicking out” occupants to their alternate home so lookups check only a couple of places.

**Example inputs and outputs**

*Setup*
Two hash tables $T_{1}$ and $T_{2}$, each of size

$$
m = 5
$$

Two independent hash functions:

$$
h_{1}(k), \quad h_{2}(k)
$$

Cuckoo hashing invariant:

* Each key is stored either in $T_{1}[h_{1}(k)]$ or $T_{2}[h_{2}(k)]$.
* On insertion, if a spot is occupied, the existing key is **kicked out** and reinserted into the other table.
* If relocations form a cycle, the table is **rebuilt (rehash)** with new hash functions.

*Example 1*

$$
\text{Target: } 15
$$

Lookup procedure:

1. Check $T_{1}[h_{1}(15)]$.
2. If not found, check $T_{2}[h_{2}(15)]$.

Result:

$$
\text{found in } T_{2} \text{ at index } 4
$$

$$
\text{Output: found (T₂, index 4)}
$$

*Example 2*

If insertion causes repeated displacements and eventually loops:

$$
\text{Cycle detected } \Rightarrow \text{rehash with new } h_{1}, h_{2}
$$

$$
\text{Output: rebuild / rehash required}
$$

**How it works**

We keep **two hash tables (T₁, T₂)**, each with its own hash function. Every key can live in **exactly one of two possible slots**:

Hash functions:

$$
h_1(k) = k \bmod 5, \quad h_2(k) = 1 + (k \bmod 4)
$$

Every key can live in **exactly one of two slots**: $T_1[h_1(k)]$ or $T_2[h_2(k)]$.
If a slot is occupied, we **evict** the old occupant and reinsert it at its alternate location.

*Start empty:*

```
T₁: [   ][   ][   ][   ][   ]
T₂: [   ][   ][   ][   ][   ]
```

*Insert 10* → goes to $T_1[h_1(10)=0]$:

```
T₁: [10 ][   ][   ][   ][   ]
T₂: [   ][   ][   ][   ][   ]
```

*Insert 15*

* $T_1[0]$ already has 10 → evict 10
* Place 15 at $T_1[0]$
* Reinsert evicted 10 at $T_2[h_2(10)=3]$:

```
T₁: [15 ][   ][   ][   ][   ]
T₂: [   ][   ][   ][10 ][   ]
```

*Insert 20*

* $T_1[0]$ has 15 → evict 15
* Place 20 at $T_1[0]$
* Reinsert 15 at $T_2[h_2(15)=4]$:

```
T₁: [20 ][   ][   ][   ][   ]
T₂: [   ][   ][   ][10 ][15 ]
```

*Insert 25*

* $T_1[0]$ has 20 → evict 20
* Place 25 at $T_1[0]$
* Reinsert 20 at $T_2[h_2(20)=1]$:

```
T₁: [25 ][   ][   ][   ][   ]
T₂: [   ][20 ][   ][10 ][15 ]
```

🔎 *Search(15)*

* $T_1[h_1(15)=0] \to 25 \neq 15$
* $T_2[h_2(15)=4] \to 15$ ✅ FOUND

**FOUND in T₂ at index 4**

* Lookups probe at **most two places** (with two hashes) → excellent constant factors.
* Inserts may trigger a chain of evictions; detect cycles and **rehash** with new functions.
* High load factors achievable (e.g.,~0.5–0.9 depending on variant and number of hashes/tables).
* Deletions are easy (remove key); no tombstones, but ensure invariants remain.
* Sensitive to hash quality; poor hashes increase cycle risk.

### Probabilistic Membership Filters

Probabilistic membership filters answer a very specific question: **“Is this item in the set?”** but with a twist, they allow uncertainty in one direction. They can say **“definitely not”** with full confidence, or **“maybe”** when the filter thinks the item could be present. This trade lets them be extremely space-efficient and extremely fast.

The main rule to remember is:

* **No false negatives**: if the filter says “definitely not,” the item is not in the set.
* **Possible false positives**: the filter might say “maybe present” even when the item isn’t actually there.

That’s often exactly what you want when a “maybe” result can be followed by a real lookup in a slower structure (like a hash table or database).

#### Bloom Filter

A Bloom filter uses a bit array of length `m` and `k` independent hash functions. To insert an element, hash it `k` times and set those `k` bit positions to `1`. To query an element, hash it again and check the same `k` positions: if any bit is `0`, the element is definitely not present; if all are `1`, it might be present.

**How it works (tiny example)**

Bit array of length 10 (all zeros initially):

```
index:  0 1 2 3 4 5 6 7 8 9
bits : [0 0 0 0 0 0 0 0 0 0]
```

Insert `"cat"` with k=3 hash positions: 2, 5, 8

```
bits : [0 0 1 0 0 1 0 0 1 0]
```

Insert `"dog"` hashes to 1, 5, 9

```
bits : [0 1 1 0 0 1 0 0 1 1]
```

Query `"cat"` → check 2,5,8 → all 1 → **maybe present** ✅
Query `"cow"` → hashes to 3,5,7 → bit 3 is 0 → **definitely not** ❌

* Insert: $O(k)$ bit sets
* Query: $O(k)$ bit checks
* Space: $O(m)$ bits total
* No deletions (basic Bloom): clearing bits could break other entries.
* False positive rate depends on `m`, `k`, and number of inserted items `n`.

#### Counting Bloom Filter

A Counting Bloom filter replaces the bit array with small counters (e.g., 4-bit or 8-bit). Insertion increments counters; deletion decrements counters. Query checks whether all counters are non-zero.

This is the “Bloom filter that supports removals,” but you pay for it in memory: counters cost more than bits, and counter overflow must be handled carefully.

* Insert/query/delete: $O(k)$
* More space than Bloom filter
* Supports deletions safely (within counter limits)

#### Cuckoo Filter

A Cuckoo filter stores small fingerprints (short hashes) in a table and uses cuckoo-style relocation (similar spirit to cuckoo hashing). Queries check a small number of candidate buckets.

Compared to Bloom filters, cuckoo filters often:

* support deletions naturally,
* achieve high load factors,
* and can be faster at query time for similar false positive rates.

- Insert/query/delete: expected $O(1)$, with occasional relocations
- No false negatives (for stored fingerprints, assuming correct implementation)
- False positives possible (fingerprints can collide)

### String Matching (Substring/Pattern Search)

Searching in strings is about finding a pattern of length `m` inside a text of length `n`. The naive method works by checking every alignment, but smarter algorithms exploit structure, especially the fact that mismatches can tell you how far you can skip ahead.

#### Naive String Search

Slide the pattern across the text one position at a time; at each position, compare characters until mismatch or full match.

* Worst case: $O(n \cdot m)$
* Great when patterns are short, texts are small, or you just want the simplest correct solution.

#### Knuth–Morris–Pratt (KMP)

KMP avoids re-checking characters by precomputing a failure function (often called the LPS array: longest proper prefix which is also a suffix). When a mismatch occurs, KMP uses the failure function to shift the pattern without moving backward in the text.

* Preprocessing: $O(m)$
* Search: $O(n)$
* Total: $O(n+m)$ guaranteed

Why it matters: KMP gives you a **hard guarantee**. No “bad day” inputs that suddenly become quadratic.

#### Boyer–Moore (BM)

Boyer–Moore compares from right to left and uses skip heuristics (bad-character and good-suffix rules) to jump the pattern forward by more than one step when mismatches happen.

* Often fastest in practice for long patterns and large alphabets.
* Worst-case can be higher than linear depending on variant, but real-world performance is excellent.

Why it matters: BM is what you use when you care about speed on typical text, not just asymptotic guarantees.

#### Rabin–Karp (RK)

Rabin–Karp uses a rolling hash. Hash the pattern and each length-`m` window of the text; if hashes match, verify by direct comparison to avoid hash collision errors.

* Expected: $O(n + m)$
* Great for multiple patterns (hash them all) or streaming windows.

Why it matters: the rolling hash lets you update the window hash in constant time, which is powerful when you’re scanning huge text or many patterns.

### Probabilistic & Approximate Search

Probabilistic search structures are built for one very specific job: **fast membership tests** when you don’t want (or can’t afford) exact storage. Instead of storing full keys, they store compact “evidence” that a key might be present. That trade buys you speed and memory savings, at the cost of occasionally saying *“maybe”* when the real answer is *“no.”*

The core promise is usually this:

* **“Definitely not present” is trustworthy.**
* **“Maybe present” means “check the real structure if you need certainty.”**

In practice, these filters sit in front of slower systems (databases, disk caches, network calls). If the filter says “definitely not,” you skip the expensive work. If it says “maybe,” you pay the cost, but only for a smaller set of candidates.

#### Bloom Filter

Space-efficient structure for fast membership tests; answers **“maybe present”** or **“definitely not present”** with a tunable false-positive rate and no false negatives (if built correctly, without deletions).

A Bloom filter is basically a **bit array + a few hash functions**. Insertion flips a handful of bits to 1. Lookup checks the same handful of bits. The reason this works is monotonicity: bits only ever go from 0 → 1, so a missing 1-bit is a solid proof the item was never inserted. The flip side is that different items can collide onto the same bits, causing false positives.

**Example inputs and outputs**

*Setup*

$$
m = 16  \text{bits},
\quad k = 3  \text{hash functions } (h_{1}, h_{2}, h_{3})
$$

Inserted set:

$$
{"cat", "dog"}
$$

*Example 1*

$$
\text{Query: contains("cat")}
$$

All $h_{i}(\text{"cat"})$ bits are set → actual member.

$$
\text{Output: maybe present (true positive)}
$$

*Example 2*

$$
\text{Query: contains("cow")}
$$

One probed bit = 0 → cannot be present.

$$
\text{Output: definitely not present}
$$

*Example 3*

$$
\text{Query: contains("eel")}
$$

All $h_{i}(\text{"eel"})$ bits happen to be set, even though "eel" was never inserted.

$$
\text{Output: maybe present (false positive)}
$$

**How it works**

*Initial state* (all zeros):

```
Idx:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
A  =  [0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0]
```

Insert `"cat"`

```
h1(cat) = 3,  h2(cat) = 7,  h3(cat) = 12
→ Set bits at 3, 7, 12

Idx:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
A  =  [0  0  0  1  0  0  0  1  0  0  0  0  1  0  0  0]
                ^              ^              ^
                3              7              12
```

Insert `"dog"`

```
h1(dog) = 1,  h2(dog) = 7,  h3(dog) = 9
→ Set bits at 1, 7, 9  (7 already set)

Idx:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
A  =  [0  1  0  1  0  0  0  1  0  1  0  0  1  0  0  0]
          ^              ^     ^
          1              7     9
```

Query `"cow"`

```
h1(cow) = 1 → bit[1] = 1
h2(cow) = 3 → bit[3] = 1
h3(cow) = 6 → bit[6] = 0  ❌

Idx:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
A  =  [0  1  0  1  0  0  0  1  0  1  0  0  1  0  0  0]
          ✓              ✓     ✗
```

At least one zero → **DEFINITELY NOT PRESENT**

Query `"eel"`

```
h1(eel) = 7 → bit[7] = 1
h2(eel) = 9 → bit[9] = 1
h3(eel) = 12 → bit[12] = 1

Idx:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
A  =  [0  1  0  1  0  0  0  1  0  1  0  0  1  0  0  0]
                            ✓     ✓        ✓
```

All ones → **MAYBE PRESENT** (could be a **false positive**)

* Answers: **maybe present** / **definitely not present**; never false negatives (without deletions).
* False-positive rate is tunable via bit-array size **m**, number of hashes **k**, and items **n**; more space & good **k** → lower FPR.
* Time: $O(k)$ per insert/lookup; Space:~m bits.
* No deletions in the basic form; duplicates are harmless (idempotent sets).
* Union = bitwise OR; intersection = bitwise AND (for same m,k,hashes).
* Choose independent, well-mixed hash functions to avoid correlated bits.

A helpful intuition: a Bloom filter is like a nightclub bouncer with a stamp list. If you don’t have the stamp pattern, you’re definitely not in. If you do, you might still be an imposter who happens to match the pattern, but it’s usually rare enough to be worth the speed.

#### Counting Bloom Filter

Bloom filter variant that keeps a small counter per bit so you can **delete** by decrementing; still probabilistic and may have false positives.

Counting Bloom filters exist because normal Bloom filters only ever turn bits on. That’s great for proving “definitely not,” but it makes deletions unsafe: turning a bit off might accidentally remove evidence needed for other elements. Counters fix that by tracking **how many inserts contributed** to each position.

**Example inputs and outputs**

*Setup*

$$
m = 12  \text{counters (each 2–4 bits)},
\quad k = 3  \text{hash functions}
$$

Inserted set:

$$
{\text{"alpha"},  \text{"beta"}}
$$

Then delete `"alpha"`.

*Example 1*

$$
\text{Query: contains("alpha")}
$$

Counters for `"alpha"` decremented; at least one probed counter is now $0$.

$$
\text{Output: definitely not present}
$$

*Example 2*

$$
\text{Query: contains("beta")}
$$

All three counters for `"beta"` remain $>0$.

$$
\text{Output: maybe present}
$$

*Example 3*

$$
\text{Query: contains("gamma")}
$$

At least one probed counter is $0$.

$$
\text{Output: definitely not present}
$$

**How it works**

Each cell is a **small counter** (e.g. 4-bits, range 0..15).
This allows **deletions**: increment on insert, decrement on delete.

Initial state

```
Idx:   0  1  2  3  4  5  6  7  8  9 10 11
A  =  [0  0  0  0  0  0  0  0  0  0  0  0]
```

Insert `"alpha"`

```
Hashes: {2, 5, 9}
→ Increment those counters

Idx:   0  1  2  3  4  5  6  7  8  9 10 11
A  =  [0  0  1  0  0  1  0  0  0  1  0  0]
             ↑        ↑              ↑
             2        5              9
```

Insert `"beta"`

```
Hashes: {3, 5, 11}
→ Increment those counters

Idx:   0  1  2  3  4  5  6  7  8  9 10 11
A  =  [0  0  1  1  0  2  0  0  0  1  0  1]
                ↑        ↑              ↑
                3        5              11
```

Lookup `"beta"`

```
Hashes: {3, 5, 11}
Counters = {1, 2, 1} → all > 0
→ Result: MAYBE PRESENT

Idx:   0  1  2  3  4  5  6  7  8  9 10 11
A  =  [0  0  1  1  0  2  0  0  0  1  0  1]
                ✓        ✓              ✓
```

Delete `"alpha"`

```
Hashes: {2, 5, 9}
→ Decrement those counters

Idx:   0  1  2  3  4  5  6  7  8  9 10 11
A  =  [0  0  0  1  0  1  0  0  0  0  0  1]
             ↓        ↓              ↓
             2        5              9
```

Lookup `"alpha"`

```
Hashes: {2, 5, 9}
Counters = {0, 1, 0}
→ At least one zero
→ Result: DEFINITELY NOT PRESENT

Idx:   0  1  2  3  4  5  6  7  8  9 10 11
A  =  [0  0  0  1  0  1  0  0  0  0  0  1]
             ✗        ✓              ✗
```

* Supports **deletion** by decrementing counters; insertion increments.
* Still probabilistic: may return false positives; avoids false negatives **if counters never underflow** and hashes are consistent.
* Space: more than Bloom (a few bits per counter instead of 1).
* Watch for counter **saturation** (caps at max value) and **underflow** (don’t decrement below 0).
* Good for dynamic sets with frequent inserts and deletes.

If Bloom filters are stamps, counting Bloom filters are a sign-in sheet: you can erase a name only when you’re sure nobody else relied on that same mark. The counters track that “how many” safely.

#### Cuckoo Filter

Hash-table–style filter that stores short **fingerprints** in two possible buckets; supports **insert, lookup, delete** with low false-positive rates and high load factors.

A cuckoo filter feels more like a compact hash table than a Bloom filter. Instead of setting bits, it stores small fingerprints in buckets. The reason you should care is practical: cuckoo filters support deletions naturally (you remove a fingerprint), and they often achieve excellent performance at high occupancy.

**Example inputs and outputs**

*Setup*

$$
b = 8  \text{buckets},
\quad \text{bucket size} = 2,
\quad \text{fingerprint size} = 8  \text{bits}
$$

Inserted set:

$$
{\text{"cat"},  \text{"dog"},  \text{"eel"}}
$$

Each element is stored as a short fingerprint in one of two candidate buckets.

*Example 1*

$$
\text{Query: contains("cat")}
$$

Fingerprint for `"cat"` is present in one of its candidate buckets.

$$
\text{Output: maybe present (true positive)}
$$

*Example 2*

$$
\text{Query: contains("fox")}
$$

Fingerprint for `"fox"` is absent from both candidate buckets.

$$
\text{Output: definitely not present}
$$

*Example 3 (Deletion)*

$$
\text{Operation: remove("dog")}
$$

Fingerprint for `"dog"` is removed from its bucket.

$$
\text{Result: deletion supported directly by removing the fingerprint}
$$

**How it works**

Each key `x` → short **fingerprint** `f = FP(x)`
Two candidate buckets:

* `i1 = H(x) mod b`
* `i2 = (i1 XOR H(f)) mod b`
  (`f` can be stored in either bucket; moving between buckets preserves the invariant.)

Start (empty)

```
[0]: [ -- , -- ]   [1]: [ -- , -- ]   [2]: [ -- , -- ]   [3]: [ -- , -- ]
[4]: [ -- , -- ]   [5]: [ -- , -- ]   [6]: [ -- , -- ]   [7]: [ -- , -- ]
```

Insert `"cat"`

```
f = 0xA7
i1 = 1
i2 = 1 XOR H(0xA7) = 5

Bucket 1 has free slot → place 0xA7 in [1]

[1]: [ A7 , -- ]
```

Insert `"dog"`

```
f = 0x3C
i1 = 5
i2 = 5 XOR H(0x3C) = 2

Bucket 5 has free slot → place 0x3C in [5]

[1]: [ A7 , -- ]        [5]: [ 3C , -- ]
```

Insert `"eel"`

```
f = 0xD2
i1 = 1
i2 = 1 XOR H(0xD2) = 4

Bucket 1 has one free slot → place 0xD2 in [1]

[1]: [ A7 , D2 ]        [5]: [ 3C , -- ]
```

Lookup `"cat"`

```
f = 0xA7
Buckets: i1 = 1, i2 = 5
Check: bucket[1] has A7 → found
```

Result: MAYBE PRESENT

Lookup `"fox"`

```
f = 0x9B
i1 = 0
i2 = 0 XOR H(0x9B) = 7

Check buckets 0 and 7 → fingerprint not found
```

Result: DEFINITELY NOT PRESENT

* Stores **fingerprints**, not full keys; answers **maybe present** / **definitely not present**.
* Supports **deletion** by removing a matching fingerprint from either bucket.
* Very high load factors (often 90%+ with small buckets) and excellent cache locality.
* False-positive rate controlled by fingerprint length (more bits → lower FPR).
* Insertions can trigger **eviction chains**; worst case requires a **rehash/resize**.
* Two buckets per item (or more in variants); lookups check a tiny, fixed set of places.

A good mental model: cuckoo filters are like a coat check where every coat has exactly two allowed hooks. If both hooks are full, you temporarily move coats around (“cuckooing”) until everyone has a legal spot, or you expand the room.
