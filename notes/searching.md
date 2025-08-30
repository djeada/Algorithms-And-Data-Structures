## Searching

Searching refers to the process of finding the location of a specific element within a collection of data, such as an array, list, tree, or graph. It underpins many applications, from databases and information retrieval to routing and artificial intelligence. Depending on the organization of the data, different search techniques are used—such as linear search for unsorted data, binary search for sorted data, and more advanced approaches like hash-based lookup or tree traversals for hierarchical structures. Efficient searching is important because it directly impacts the performance and scalability of software systems.

### Linear & Sequential Search

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
\text{Output: } \text{index} = 0 \; (\text{first match})
$$

*Example 3*

$$
\text{Input: } [10, 20, 30], \quad \text{target} = 25
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

Start at index 0, compare, move right; stop on first equal or after the last element.

```
Indexes:     0    1    2    3    4
List:      [ 7 ][ 3 ][ 5 ][ 2 ][ 9 ]
Target: 5

Pass 1: pointer at 0 → compare 7 vs 5  → no
          v
Indexes:   0    1    2    3    4
           |    
List:      7    3    5    2    9

Pass 2: pointer at 1 → compare 3 vs 5  → no
               v
Indexes:   0    1    2    3    4
                |   
List:      7    3    5    2    9

Pass 3: pointer at 2 → compare 5 vs 5  → YES → return 2
                    v
Indexes:   0    1    2    3    4
                     |  
List:      7    3    5    2    9
```

**Worst case (not found):** you compare every element and then stop.

```
Indexes:     0    1    2
List:      [ 1 ][ 2 ][ 3 ]
Target: 9

Checks: (1≠9) → (2≠9) → (3≠9) → end → not found
```

* Works on any list; no sorting or structure required.
* Returns the first index containing the target; if absent, reports “not found.”
* Time: O(n) comparisons on average and in the worst case; best case O(1) if the first element matches.
* Space: O(1) extra memory.
* Naturally finds the earliest occurrence when duplicates exist.
* Simple and dependable for short or unsorted data.
* Assumes 0-based indexing in these notes.

#### Sentinel Linear Search

Place one copy of the target at the very end as a “sentinel” so the scan can run without checking bounds each step; afterward, decide whether the match was inside the original list or only at the sentinel position.

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
\text{Output: } \text{not found } \; (\text{only the sentinel matched})
$$

**How it works**

Put the target at one extra slot at the end so the loop is guaranteed to stop on a match; afterward, check whether the match was inside the original range.

```
Original length n = 5
Before:   [ 4 ][ 9 ][ 1 ][ 7 ][ 6 ]
Target: 11

Add sentinel (extra slot):
          [ 4 ][ 9 ][ 1 ][ 7 ][ 6 ][ 11 ]
Indexes:    0    1    2    3    4     5  ← sentinel position

Scan left→right until you see 11:

Step 1: 4 ≠ 11
          ^
Step 2: 9 ≠ 11
               ^
Step 3: 1 ≠ 11
                    ^
Step 4: 7 ≠ 11
                         ^
Step 5: 6 ≠ 11
                              ^
Step 6: 11 (match at index 5, which is the sentinel)

Because the first match is at index 5 (the sentinel position), the target was not in the original indexes 0..4 → report “not found”.
```

**When the target exists inside the list:**

```
List:      [ 12 ][ 8 ][ 6 ][ 15 ]   n = 4
Target: 6
With sentinel: [ 12 ][ 8 ][ 6 ][ 15 ][ 6 ]

Scan: 12≠6 → 8≠6 → 6=6 (index 2 < n) → real match at 2
```

* Removes the per-iteration “have we reached the end?” check; the sentinel guarantees termination.
* Same O(n) time in big-O terms, but slightly fewer comparisons in tight loops.
* Space: needs one extra slot; if you cannot append, you can temporarily overwrite the last element (store it, write the target, then restore it).
* After scanning, decide by index: if the first match index < original length, it’s a real match; otherwise, it’s only the sentinel.
* Use when micro-optimizing linear scans over arrays where bounds checks are costly.
* Behavior with duplicates: still returns the first occurrence within the original range.
* Be careful to restore any overwritten last element if you used the in-place variant.

### Divide & Conquer Search

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

```
Sorted A:  [ 2 ][ 5 ][ 8 ][12 ][16 ][23 ][38 ]
Indexes:     0    1    2   3    4    5    6
Target: 16

1) low=0, high=6  → mid=(0+6)//2=3
   A[3]=12 < 16 → discard left half up to mid, keep [mid+1..high]
         [ 2 ][ 5 ][ 8 ]  |[12 ]| [16 ][23 ][38 ]
                          low=4               high=6

2) low=4, high=6 → mid=(4+6)//2=5
   A[5]=23 > 16 → discard right half after mid, keep [low..mid-1]
         [16 ][23 ]|[38 ]
        low=4  high=4

3) low=4, high=4 → mid=4
   A[4]=16 = target → FOUND at index 4
```

* Requires a sorted array (assume ascending here).
* Time: O(log n); Space: O(1) iterative.
* Returns any one matching index by default; “first/last occurrence” is a small, common refinement.
* Robust, cache-friendly, and a building block for many higher-level searches.
* Beware of off-by-one errors when shrinking bounds.

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

```
Sorted A: [ 1 ][ 4 ][ 7 ][ 9 ][12 ][15 ]
Indexes:    0    1    2    3    4    5
Target: 9

1) low=0, high=5
   m1 = low + (high-low)//3      = 0 + 5//3 = 1
   m2 = high - (high-low)//3     = 5 - 5//3 = 3

   Compare A[m1]=4, A[m2]=9 with target=9:

   A[m2]=9 = target → FOUND at index 3

(If no immediate match:)
- If target < A[m1], keep [low..m1-1]
- Else if target > A[m2], keep [m2+1..high]
- Else keep [m1+1..m2-1] and repeat
```

* Also assumes a sorted array.
* For discrete sorted arrays, it does **not** beat binary search asymptotically; it performs more comparisons per step.
* Most valuable for searching the extremum of a **unimodal function** on a continuous domain; for arrays, prefer binary search.
* Complexity: O(log n) steps but with larger constant factors than binary search.

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

```
Sorted A: [ 1 ][ 4 ][ 9 ][16 ][25 ][36 ][49 ]
Indexes:    0    1    2    3    4    5    6
Target: 25
Choose block size ≈ √n → here n=7 → jump=2

Jumps (probe at 0,2,4,6 until A[probe] ≥ target):
- probe=0 → A[0]=1   (<25) → next probe=2
- probe=2 → A[2]=9   (<25) → next probe=4
- probe=4 → A[4]=25 (≥25) → target must be in block (2..4]

Linear scan inside last block (indexes 3..4):
- i=3 → A[3]=16 (<25)
- i=4 → A[4]=25 (=) FOUND at index 4
```

* Works on sorted arrays; pick jump ≈ √n for good balance.
* Time: O(√n) comparisons on average; Space: O(1).
* Useful when random access is cheap but full binary search isn’t desirable (e.g., limited CPU branch prediction, or when scanning in blocks is cache-friendly).
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
Sorted A: [ 2 ][ 3 ][ 5 ][ 7 ][11 ][13 ][17 ][19 ][23 ]
Indexes:    0    1    2    3    4    5    6    7    8
Target: 19

1) Find range by exponential jumps (check A[1], A[2], A[4], A[8], ...):
   - A[1]=3  ≤ 19
   - A[2]=5  ≤ 19
   - A[4]=11 ≤ 19
   - A[8]=23 > 19 → stop; range is (prev_power_of_two..8] → (4..8]

2) Do binary search on A[5..8]:
   Subarray: [13 ][17 ][19 ][23 ]
   Indices:    5    6    7    8
   Binary search finds A[7]=19 → FOUND at index 7
```

* Great when the target is likely to be near the beginning or when the array is **unbounded**/**stream-like** but sorted (you can probe indices safely).
* Time: O(log p) to find the range where p is the final bound, plus O(log p) for binary search → overall O(log p).
* Space: O(1).
* Often paired with data sources where you can test “is index i valid?” while doubling i.

#### Interpolation Search

On a sorted (roughly uniformly distributed) array, estimate the likely position using the values themselves and probe there; repeat on the narrowed side.

**Example inputs and outputs**

*Example 1*

$$
\text{Input: } A = [10, 20, 30, 40, 50, 60, 70], \quad \text{target} = 55
$$

$$
\text{Output: } \text{not found } \; (\text{probes near indices } 4\text{–}5)
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
\text{Output: } \text{not found } \; (\text{bad distribution for interpolation})
$$

**How it works**

```
Assumes A is sorted and values are roughly uniform.

Idea: "Guess" the likely index by linearly interpolating the target’s value
between A[low] and A[high]:

Estimated position:
pos ≈ low + (high - low) * (target - A[low]) / (A[high] - A[low])

Example:
A = [10, 20, 30, 40, 50, 60, 70], target = 45
low=0 (A[0]=10), high=6 (A[6]=70)

pos ≈ 0 + (6-0) * (45-10)/(70-10) = 6 * 35/60 ≈ 3.5 → probe index 3 or 4

Probe at 3: A[3]=40  (<45) → new low=4
Probe at 4: A[4]=50  (>45) → new high=3
Now low>high → not found
```

* Best on **uniformly distributed** sorted data; expected time O(log log n).
* Worst case can degrade to O(n), especially on skewed or clustered values.
* Space: O(1).
* Very fast when value-to-index mapping is close to linear (e.g., near-uniform numeric keys).
* Requires careful handling when A\[high] = A\[low] (avoid division by zero); also sensitive to integer rounding in discrete arrays.

### Hash-based Search
* **Separate chaining:** Easiest deletions, steady O(1) with α≈1; good when memory fragmentation isn’t a concern.
* **Open addressing (double hashing):** Best probe quality among OA variants; great cache locality; keep α < 0.8.
* **Open addressing (linear/quadratic):** Simple and fast at low α; watch clustering and tombstones.
* **Cuckoo hashing:** Tiny and predictable lookup cost; inserts costlier and may rehash; great for read-heavy workloads.
* In all cases: pick strong hash functions and resize early to keep α healthy.

#### Hash Table Search
Map a key to an array index with a hash function; look at that bucket to find the key, giving expected O(1) lookups under a good hash and healthy load factor.

**Example inputs and outputs**

*Example 1*

$$
\text{Table size: } m = 7, 
\quad \text{Keys stored: } \{10, 24, 31\}, 
\quad \text{Target: } 24
$$

$$
\text{Output: } \text{found (bucket 3)}
$$

*Example 2*

$$
\text{Table size: } m = 7, 
\quad \text{Keys stored: } \{10, 24, 31\}, 
\quad \text{Target: } 18
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

```
Concept:
key  --hash-->  index in array  --search/compare-->  match?

Array (buckets/indexes 0..6):
Idx:    0     1     2     3     4     5     6
      [   ][   ][   ][   ][   ][   ][   ]

Example mapping with h(k)=k mod 7, stored keys {10, 24, 31}:
10 -> 3
24 -> 3   (collides with 10; resolved by the chosen strategy)
31 -> 3   (collides again)

Search(24):
1) Compute index = h(24) = 3
2) Inspect bucket 3 (and possibly its collision path)
3) If 24 is found along that path → found; otherwise → not found
```

* Quality hash + low load factor (α = n/m) ⇒ expected O(1) search/insert/delete.
* Collisions are inevitable; the collision strategy (open addressing vs. chaining vs. cuckoo) dictates actual steps.
* Rehashing (growing and re-inserting) is used to keep α under control.
* Uniform hashing assumption underpins the O(1) expectation; adversarial keys or poor hashes can degrade performance.

#### Open Addressing — Linear Probing

Keep everything in one array; on collision, probe alternative positions in a deterministic sequence until an empty slot or the key is found.

**Example inputs and outputs**

*Example 1*

$$
m = 10, 
\quad \text{Stored keys: } \{12, 22, 32\}, 
\quad \text{Target: } 22
$$

$$
\text{Output: } \text{found (index 3)}
$$

*Example 2*

$$
m = 10, 
\quad \text{Stored keys: } \{12, 22, 32\}, 
\quad \text{Target: } 42
$$

$$
\text{Output: } \text{not found}
$$

**How it works**

```
h(k) = k mod 10, probe sequence: i, i+1, i+2, ... (wrap around)

Insertions already done:
12 -> h=2 → put at 2
22 -> h=2 (occupied) → try 3 → put at 3
32 -> h=2 (occupied), 3 (occupied) → try 4 → put at 4

Array:
Idx:  0  1  2   3   4  5  6  7  8  9
     [ ][ ][12][22][32][ ][ ][ ][ ][ ]

Search(22):
- Start at h(22)=2 → 12 ≠ 22
- Next 3 → 22 = 22 → FOUND at index 3

Search(42):
- Start at 2 → 12 ≠ 42
- 3 → 22 ≠ 42
- 4 → 32 ≠ 42
- 5 → empty → stop → NOT FOUND
```

* Simple and cache-friendly; clusters form (“primary clustering”) which can slow probes.
* Deletion uses **tombstones** to keep probe chains intact.
* Performance depends sharply on load factor; keep α well below 1 (e.g., α ≤ 0.7).
* Expected search \~ O(1) at low α; degrades as clusters grow.

#### Open Addressing — Quadratic Probing

**Example inputs and outputs**

*Example 1*

$$
m = 11 \; (\text{prime}), 
\quad \text{Stored keys: } \{22, 33, 44\}, 
\quad \text{Target: } 33
$$

$$
h(k) = k \bmod m, \quad h(33) = 33 \bmod 11 = 0
$$

$$
\text{Output: found (index 4)}
$$

*Example 2*

$$
m = 11 \; (\text{prime}), 
\quad \text{Stored keys: } \{22, 33, 44\}, 
\quad \text{Target: } 55
$$

$$
h(55) = 55 \bmod 11 = 0
$$

$$
\text{Output: not found}
$$

**How it works**

```
h(k) = k mod 11
Probe offsets: +1^2, +2^2, +3^2, ... (i.e., +1, +4, +9, +16≡+5, +25≡+3, ... mod 11)

Insert:
22 -> h=0 → put at 0
33 -> h=0 (occupied) → 0+1^2=1 → put at 1? (showing a typical sequence)
(For clarity we'll place 33 at the first free among 0,1,4,9,... Suppose 1 is free.)
44 -> h=0 (occupied) → try 1 (occupied) → try 4 → put at 4

Array (one possible state):
Idx:  0   1   2  3  4  5  6  7  8  9  10
     [22][33][ ][ ][44][ ][ ][ ][ ][ ][  ]

Search(33):
- h=0 → 22 ≠ 33
- 0+1^2=1 → 33 = 33 → FOUND at index 1

Search(55):
- h=0 → 22 ≠ 55
- +1^2=1 → 33 ≠ 55
- +2^2=4 → 44 ≠ 55
- +3^2=9 → empty → NOT FOUND
```

* Reduces primary clustering but can exhibit **secondary clustering** (keys with same h(k) follow same probe squares).
* Table size choice matters (often prime); ensure the probe sequence can reach many slots.
* Keep α modest; deletion still needs tombstones.
* Expected O(1) at healthy α; simpler than double hashing.

#### Open Addressing — Double Hashing

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
\quad \text{Stored keys: } \{22, 33, 44\}, 
\quad \text{Target: } 33
$$

* For $k = 33$:

$$
h_{1}(33) = 33 \bmod 11 = 0,
\quad h_{2}(33) = 1 + (33 \bmod 10) = 1 + 3 = 4
$$

So probe sequence is

$$
h(33,0) = 0,\;
h(33,1) = (0 + 1\cdot 4) \bmod 11 = 4,\;
h(33,2) = (0 + 2\cdot 4) \bmod 11 = 8,\; \dots
$$

Since the stored layout places $33$ at index $4$, the search succeeds.

$$
\text{Output: found (index 4)}
$$

*Example 2*

$$
m = 11, 
\quad \text{Stored keys: } \{22, 33, 44\}, 
\quad \text{Target: } 55
$$

* For $k = 55$:

$$
h_{1}(55) = 55 \bmod 11 = 0,
\quad h_{2}(55) = 1 + (55 \bmod 10) = 1 + 5 = 6
$$

Probing sequence:

$$
0, \; (0+6)\bmod 11 = 6,\; (0+2\cdot 6)\bmod 11 = 1,\; (0+3\cdot 6)\bmod 11 = 7,\; \dots
$$

No slot matches $55$.

$$
\text{Output: not found}
$$

**How it works**

```
Probe sequence: i, i+h₂, i+2·h₂, i+3·h₂, ... (all mod m)

Insert:
22: h₁=0 → put at 0
33: h₁=0 (occupied), h₂=1+(33 mod 10)=4
    Probes: 0, 4 → put at 4
44: h₁=0 (occupied), h₂=1+(44 mod 10)=5
    Probes: 0, 5 → put at 5

Array:
Idx:  0   1  2  3  4   5  6  7  8  9  10
     [22][ ][ ][ ][33][44][ ][ ][ ][ ][ ]

Search(33):
- Start 0 → 22 ≠ 33
- Next 0+4=4 → 33 → FOUND

Search(55):
- h₁=0, h₂=1+(55 mod 10)=6
- Probes: 0 (22), 6 (empty) → NOT FOUND
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
\{12, 22, 7, 3, 14\}
$$

Bucket contents after hashing:

$$
\begin{aligned}
h(12) &= 12 \bmod 5 = 2 &\;\;\Rightarrow& \;\; \text{bucket 2: } [12] \\[6pt]
h(22) &= 22 \bmod 5 = 2 &\;\;\Rightarrow& \;\; \text{bucket 2: } [12, 22] \\[6pt]
h(7)  &= 7  \bmod 5 = 2 &\;\;\Rightarrow& \;\; \text{bucket 2: } [12, 22, 7] \\[6pt]
h(3)  &= 3  \bmod 5 = 3 &\;\;\Rightarrow& \;\; \text{bucket 3: } [3] \\[6pt]
h(14) &= 14 \bmod 5 = 4 &\;\;\Rightarrow& \;\; \text{bucket 4: } [14]
\end{aligned}
$$

*Example 1*

$$
\text{Target: } 22
$$

$$
h(22) = 2 \;\;\Rightarrow\;\; \text{bucket 2} = [12, 22, 7]
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
h(9) = 9 \bmod 5 = 4 \;\;\Rightarrow\;\; \text{bucket 4} = [14]
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
* Expected O(1 + α) time; with good hashing and α kept near/below 1, bucket lengths stay tiny.
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
\text{Cycle detected } \;\;\Rightarrow\;\; \text{rehash with new } h_{1}, h_{2}
$$

$$
\text{Output: rebuild / rehash required}
$$

**How it works**

```
Example hashes:
h₁(k) = k mod 5
h₂(k) = 1 + (k mod 4)

Start empty T₁ and T₂ (indexes 0..4):

T₁: [   ][   ][   ][   ][   ]
T₂: [   ][   ][   ][   ][   ]

Insert 10:
- Place at T₁[h₁(10)=0] = 0

T₁: [10 ][   ][   ][   ][   ]
T₂: [   ][   ][   ][   ][   ]

Insert 15:
- T₁[h₁(15)=0] occupied by 10 → cuckoo step:
  Evict 10; put 15 at T₁[0]
  Reinsert evicted 10 at its alternate home T₂[h₂(10)=1+(10 mod 4)=3]

T₁: [15 ][   ][   ][   ][   ]
T₂: [   ][   ][   ][10 ][   ]

Insert 20:
- T₁[h₁(20)=0] occupied by 15 → evict 15; place 20 at T₁[0]
  Reinsert 15 at T₂[h₂(15)=1+(15 mod 4)=4]

T₁: [20 ][   ][   ][   ][   ]
T₂: [   ][   ][   ][10 ][15 ]

Insert 25:
- T₁[h₁(25)=0] occupied by 20 → evict 20; place 25 at T₁[0]
  Reinsert 20 at T₂[h₂(20)=1+(20 mod 4)=1]

T₁: [25 ][   ][   ][   ][   ]
T₂: [   ][20 ][   ][10 ][15 ]

Search(15):
- Check T₁[h₁(15)=0] → 25 ≠ 15
- Check T₂[h₂(15)=4] → 15 → FOUND
```

* Lookups probe at **most two places** (with two hashes) → excellent constant factors.
* Inserts may trigger a chain of evictions; detect cycles and **rehash** with new functions.
* High load factors achievable (e.g., \~0.5–0.9 depending on variant and number of hashes/tables).
* Deletions are easy (remove key); no tombstones, but ensure invariants remain.
* Sensitive to hash quality; poor hashes increase cycle risk.

### Probabilistic & Approximate Search

#### Bloom Filter
Space-efficient structure for fast membership tests; answers **“maybe present”** or **“definitely not present”** with a tunable false-positive rate and no false negatives (if built correctly, without deletions).

**Example inputs and outputs**

*Setup*

$$
m = 16 \; \text{bits}, 
\quad k = 3 \; \text{hash functions } (h_{1}, h_{2}, h_{3})
$$

Inserted set:

$$
\{"cat", "dog"\}
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

```
Bit array (m = 16), initially all zeros:

Idx:  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
     [0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0]

INSERT "cat":
h1(cat)=3, h2(cat)=7, h3(cat)=12  → set those bits to 1

     [0 0 0 1 0 0 0 1 0 0  0  0  1  0  0  0]
                 ^   ^           ^
                3    7          12

INSERT "dog":
h1(dog)=1, h2(dog)=7, h3(dog)=9  → set 1,7,9 to 1 (7 already 1)

     [0 1 0 1 0 0 0 1 0 1  0  0  1  0  0  0]
         ^         ^       ^

QUERY "cow":
h1(cow)=1 (bit=1), h2(cow)=3 (bit=1), h3(cow)=6 (bit=0) → at least one zero
→ Result: DEFINITELY NOT PRESENT

QUERY "eel":
h1(eel)=7 (1), h2(eel)=9 (1), h3(eel)=12 (1) → all ones
→ Result: MAYBE PRESENT (could be a FALSE POSITIVE)
```

* Answers: **maybe present** / **definitely not present**; never false negatives (without deletions).
* False-positive rate is tunable via bit-array size **m**, number of hashes **k**, and items **n**; more space & good **k** → lower FPR.
* Time: O(k) per insert/lookup; Space: \~m bits.
* No deletions in the basic form; duplicates are harmless (idempotent sets).
* Union = bitwise OR; intersection = bitwise AND (for same m,k,hashes).
* Choose independent, well-mixed hash functions to avoid correlated bits.

#### Counting Bloom Filter
Bloom filter variant that keeps a small counter per bit so you can **delete** by decrementing; still probabilistic and may have false positives.

**Example inputs and outputs**

*Setup*

$$
m = 12 \;\; \text{counters (each 2–4 bits)}, 
\quad k = 3 \;\; \text{hash functions}
$$

Inserted set:

$$
\{\text{"alpha"}, \; \text{"beta"}\}
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

```
Counters (not bits). Each cell stores a small integer (0..15 if 4-bit).

Idx:  0 1 2 3 4 5 6 7 8 9 10 11
     [0 0 0 0 0 0 0 0 0 0  0  0]

INSERT "alpha": h: {2, 5, 9} → increment those counters
     [0 0 1 0 0 1 0 0 0 1  0  0]

INSERT "beta":  h: {3, 5, 11} → increment
     [0 0 1 1 0 2 0 0 0 1  0  1]

LOOKUP "beta": counters at {3,5,11} = {1,2,1} > 0 → MAYBE PRESENT

DELETE "alpha": decrement {2,5,9}
     [0 0 0 1 0 1 0 0 0 0  0  1]

LOOKUP "alpha": counters at {2,5,9} = {0,1,0}
→ has a zero → DEFINITELY NOT PRESENT
```

* Supports **deletion** by decrementing counters; insertion increments.
* Still probabilistic: may return false positives; avoids false negatives **if counters never underflow** and hashes are consistent.
* Space: more than Bloom (a few bits per counter instead of 1).
* Watch for counter **saturation** (caps at max value) and **underflow** (don’t decrement below 0).
* Good for dynamic sets with frequent inserts and deletes.

#### Cuckoo Filter
Hash-table–style filter that stores short **fingerprints** in two possible buckets; supports **insert, lookup, delete** with low false-positive rates and high load factors.

**Example inputs and outputs**

*Setup*

$$
b = 8 \;\; \text{buckets}, 
\quad \text{bucket size} = 2, 
\quad \text{fingerprint size} = 8 \; \text{bits}
$$

Inserted set:

$$
\{\text{"cat"}, \; \text{"dog"}, \; \text{"eel"}\}
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

```
Each key x → short fingerprint f = FP(x)
Two candidate buckets:
i1 = H(x) mod b
i2 = i1 XOR H(f) mod b   (so moving f between i1 and i2 preserves alternation)

Buckets (capacity 2 each), showing fingerprints as hex bytes:

Start (empty):
[0]: [  -- , -- ]   [1]: [ -- , -- ]   [2]: [ -- , -- ]   [3]: [ -- , -- ]
[4]: [  -- , -- ]   [5]: [ -- , -- ]   [6]: [ -- , -- ]   [7]: [ -- , -- ]

INSERT "cat": f=0xA7, i1=1, i2=1 XOR H(0xA7)=5
- Bucket 1 has space → place 0xA7 in [1]

[1]: [ A7 , -- ]

INSERT "dog": f=0x3C, i1=5, i2=5 XOR H(0x3C)=2
- Bucket 5 has space → place 0x3C in [5]

[5]: [ 3C , -- ]

INSERT "eel": f=0xD2, i1=1, i2=1 XOR H(0xD2)=4
- Bucket 1 has one free slot → place 0xD2 in [1]

[1]: [ A7 , D2 ]

LOOKUP "cat":
- Compute f=0xA7, check buckets 1 and 5 → found in bucket 1 → MAYBE PRESENT

LOOKUP "fox":
- Compute f=0x9B, buckets say 0 and 7 → fingerprint not in [0] or [7]
→ DEFINITELY NOT PRESENT

If an insertion finds both buckets full:
- Evict one resident fingerprint (“cuckoo kick”), move it to its alternate bucket,
  possibly triggering a chain; if a loop is detected, resize/rehash.
```

* Stores **fingerprints**, not full keys; answers **maybe present** / **definitely not present**.
* Supports **deletion** by removing a matching fingerprint from either bucket.
* Very high load factors (often 90%+ with small buckets) and excellent cache locality.
* False-positive rate controlled by fingerprint length (more bits → lower FPR).
* Insertions can trigger **eviction chains**; worst case requires a **rehash/resize**.
* Two buckets per item (or more in variants); lookups check a tiny, fixed set of places.

### String Search Algorithms

* **KMP:** Best all-rounder for guaranteed **O(n + m)** and tiny memory.
* **Boyer–Moore:** Fastest in practice on long patterns / large alphabets due to big skips.
* **Rabin–Karp:** Great for **many patterns** or streaming; hashing enables batched checks.
* **Naive:** Fine for tiny inputs or as a baseline; simplest to reason about.

#### Naive String Search

Slide the pattern one position at a time over the text; at each shift compare characters left-to-right until a mismatch or a full match.

**Example inputs and outputs**

*Example 1*

$$
\text{Text: } "abracadabra", 
\quad \text{Pattern: } "abra"
$$

$$
\text{Output: matches at indices } \; 0 \;\; \text{and} \;\; 7
$$

*Example 2*

$$
\text{Text: } "aaaaa", 
\quad \text{Pattern: } "aaa"
$$

$$
\text{Output: matches at indices } \; 0, \; 1, \; 2
$$

**How it works**

```
Text (index): 0 1 2 3 4 5 6 7 8 9 10
              a b r a c a d a b r  a
Pattern:      a b r a

Shift 0:
a b r a
a b r a   ← all match → REPORT 0

Shift 1:
  a b r a
  b r a c ← mismatch at first char → advance by 1

Shift 2:
    a b r a
    r a c a ← mismatch → advance

Shift 3:
      a b r a
      a c a d ← mismatch → advance

Shift 4:
        a b r a
        c a d a ← mismatch → advance

Shift 5:
          a b r a
          a d a b ← mismatch → advance

Shift 6:
            a b r a
            d a b r ← mismatch → advance

Shift 7:
              a b r a
              a b r a ← all match → REPORT 7
```

* Works anywhere; no preprocessing.
* Time: worst/average **O(n·m)** (text length n, pattern length m).
* Space: **O(1)**.
* Good for very short patterns or tiny inputs; otherwise use KMP/BM/RK.

#### Knuth–Morris–Pratt (KMP)

Precompute a table (LPS / prefix-function) for the pattern so that on a mismatch you “jump” the pattern to the longest proper prefix that is also a suffix, avoiding rechecks.

**Example inputs and outputs**

*Example 1*

$$
\text{Text: } "ababcabcabababd", 
\quad \text{Pattern: } "ababd"
$$

$$
\text{Output: match at index } 10
$$

*Example 2*

$$
\text{Text: } "aaaaab", 
\quad \text{Pattern: } "aaab"
$$

$$
\text{Output: match at index } 2
$$

**How it works**
```
1) Precompute LPS (Longest Proper Prefix that is also Suffix) for the pattern.

Pattern:  a  b  a  b  d
Index:    0  1  2  3  4
LPS:      0  0  1  2  0

Meaning: at each position, how far can we "fall back" within the pattern itself
to avoid rechecking text characters.

2) Scan the text with two pointers i (text), j (pattern):

Text:    a b a b c a b c a b a b a b d
Index:   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
Pattern: a b a b d

Walkthrough (only key steps shown):

- i=0..3 match "abab" (j=4 points to 'd'), then
  i=4 is 'c' vs pattern[j]='d' → mismatch
  → set j = LPS[j-1] = LPS[3] = 2  (jump pattern back to "ab")
  (i stays at 4; we do NOT recheck earlier text chars)

- Continue matching; eventually at i=14, j advances to 5 (pattern length)
  → FULL MATCH ends at i=14 → start index = 14 - 5 + 1 = 10 → REPORT 10
```

* Time: **O(n + m)** (preprocessing + scan).
* Space: **O(m)** for LPS table.
* Never moves i backward; avoids redundant comparisons.
* Ideal for repeated searches with the same pattern.
* LPS is also called prefix-function / failure-function.

#### Boyer–Moore (BM)

Compare the pattern right-to-left; on a mismatch, skip ahead using bad-character and good-suffix rules so many text characters are never touched.

**Example inputs and outputs**

*Example 1*

$$
\text{Text: } "HERE IS A SIMPLE EXAMPLE", 
\quad \text{Pattern: } "EXAMPLE"
$$

$$
\text{Output: match at index } 17
$$

*Example 2*

$$
\text{Text: } "NEEDLE IN A HAYSTACK", 
\quad \text{Pattern: } "STACK"
$$

$$
\text{Output: match at index } 15
$$


**How it works**

```
Idea: align pattern under text, compare RIGHT→LEFT.
On mismatch, shift by the MAX of:
  - Bad-character shift: move so the mismatching text char lines up with its last
    occurrence in the pattern (or skip past if absent).
  - Good-suffix shift: if a suffix matched, align another occurrence of that suffix
    (or a prefix) with the text.

Example (bad-character only shown for brevity):
Text (0..):  H E R E _ I S _ A _ S I M P L E _ E X A M P L E
Pattern:                       E X A M P L E
                               ↑ compare from here (rightmost)

1) Align at text index 10..16 ("SIMPLE"):
   compare L→R? No, BM compares R→L:
   E vs E (ok), L vs L (ok), P vs P (ok), M vs M (ok), A vs A (ok), X vs I (mismatch)
   Bad char = 'I' in text; last 'I' in pattern? none → shift pattern PAST 'I'

2) After shifts, eventually align under "... E X A M P L E":
   Compare from right:
   E=E, L=L, P=P, M=M, A=A, X=X, E=E → FULL MATCH at index 17
```

* Average case sublinear (often skips large chunks of text).
* Worst case can be **O(n·m)**; with both rules + Galil’s optimization, comparisons can be bounded **O(n + m)**.
* Space: **O(σ + m)** for tables (σ = alphabet size).
* Shines on long patterns over large alphabets (e.g., English text, logs).
* Careful table prep (bad-character & good-suffix) is crucial.

#### Rabin–Karp (RK)

Compare rolling hashes of the current text window and the pattern; only if hashes match do a direct character check (to rule out collisions).

**Example inputs and outputs**

*Example 1*

$$
\text{Text: } "ABCDABCABCD", 
\quad \text{Pattern: } "ABC"
$$

$$
\text{Output: matches at indices } 0, \; 4, \; 7
$$

*Example 2*

$$
\text{Text: } "ABCDE", 
\quad \text{Pattern: } "FG"
$$

$$
\text{Output: no match}
$$


**How it works**

```
Pick a base B and modulus M. Compute:
- pattern hash H(P)
- rolling window hash H(T[i..i+m-1]) for each window of length m

Example windows (conceptual; showing only positions, not numbers):

Text:   A B C D A B C A B C D
Index:  0 1 2 3 4 5 6 7 8 9 10
Pat:    A B C      (m = 3)

Windows & hashes:
[0..2] ABC → hash h0
[1..3] BCD → hash h1  (derived from h0 by removing 'A', adding 'D')
[2..4] CDA → hash h2
[3..5] DAB → hash h3
[4..6] ABC → hash h4 (equals H(P) → verify chars → MATCH at 4)
[5..7] BCA → hash h5
[6..8] CAB → hash h6
[7..9] ABC → hash h7 (equals H(P) → verify → MATCH at 7)

Rolling update (conceptually):
h_next = (B*(h_curr - value(left_char)*B^(m-1)) + value(new_char)) mod M
Only on hash equality do we compare characters to avoid false positives.
```

* Expected time **O(n + m)** with a good modulus and low collision rate; worst case **O(n·m)** if many collisions.
* Space: **O(1)** beyond the text/pattern and precomputed powers.
* Excellent for multi-pattern search (compute many pattern hashes, reuse rolling windows).
* Choose modulus to reduce collisions; verify on hash hits to ensure correctness.
* Works naturally on streams/very large texts since it needs only the current window.
