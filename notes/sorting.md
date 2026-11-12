# Sorting

Sorting arranges a collection of items according to a defined ordering, such as ascending numeric value or a record's timestamp. The comparison rule must be consistent; contradictory comparisons make a sorted result ill-defined.

For instance:

- Numbers can be sorted according to their numerical values, either in ascending or descending order.
- Strings are typically sorted in alphabetical order, similar to how words are arranged in dictionaries.

Sorting isn't limited to just numbers and strings. Virtually any type of object can be sorted, provided there is a clear definition of order for them.

What makes sorting worth caring about is that it quietly powers “everyday” features: search bars, leaderboards, timelines, deduplicating data, grouping logs, ranking recommendations, and making reports readable. If you can sort efficiently (and correctly), you can often make a system feel instantly faster and more polished, because so many tasks become simpler once data is ordered.

## Stability in Sorting

> **First step:** Ask whether equal keys carry other data whose original order matters. If they do, use a stable sort or add the original index as the last tie-breaker.

Stability, in the context of sorting, refers to preserving the relative order of equal items in the sorted output. In simple terms, when two items have equal keys:

- In an unstable sorting algorithm, their order might be reversed in the sorted output.
- In a stable sorting algorithm, their relative order remains unchanged.

Stability is useful when sorting records by multiple keys. Sort by the secondary key first, then stably by the primary key. The second pass preserves the secondary ordering among records whose primary keys are equal.

Let’s take an analogous list of medieval knights (each with its original 0-based index):

```
[Lancelot0] [Gawain1] [Lancelot2] [Percival3] [Gawain4]
```

Use the custom name order Lancelot, Gawain, Percival for this example. This is not alphabetical order; it keeps the illustration focused on the relative order of equal names.

### Stable Sort

A stable sort preserves the left-to-right order of equal items.

I. Bring every “Lancelot” to the front, in the order they appeared (index 0 before 2):

```
[Lancelot0] [Lancelot2] [Gawain1] [Percival3] [Gawain4]
```

II. Next, move the two “Gawain”s ahead of “Percival”, again preserving 1 before 4:

```
[Lancelot0] [Lancelot2] [Gawain1] [Gawain4] [Percival3]
```

So the stable-sorted sequence is:

```
[Lancelot0] [Lancelot2] [Gawain1] [Gawain4] [Percival3]
```

### Unstable Sort

An unstable sort may reorder equal items arbitrarily.

I. When collecting the “Lancelot”s, it might pick index 2 before 0:

```
[Lancelot2] [Lancelot0] [Gawain1] [Percival3] [Gawain4]
```

II. Later, the two “Gawain”s might swap (4 before 1):

```
[Lancelot2] [Lancelot0] [Gawain4] [Gawain1] [Percival3]
```

So one possible unstable-sorted sequence is:

```
[Lancelot2] [Lancelot0] [Gawain4] [Gawain1] [Percival3]
```

If you next sort stably by rank, rank becomes the primary key. Among equal-rank knights, the previously established name order remains intact. A stable sort preserves prior order only among records equal under the current comparison key.

A quick rule of thumb:

- If you’re sorting primitive values (just numbers), stability often doesn’t matter.
- If you’re sorting records (like `(name, age, score)`), stability matters a lot more than people expect.

And because many real systems sort records, stability is one of those “small” choices that saves you from weird bugs later.

## Sort Keys, Tie-Breakers, and Comparators

> **First step:** Write the full ordering in words before writing code, including what happens on ties. Then decide whether it fits in a key tuple or truly needs a pairwise comparator.

Many sorting problems are not about the sorting algorithm at all. They are about the order. 1636 Sort Array by Increasing Frequency, 451 Sort Characters By Frequency, 791 Custom Sort String and 1122 Relative Sort Array all come down to one library sort with the right key.

In Python, a key function maps each item to something that compares naturally, usually a tuple. Tuples compare entry by entry, so the first entry is the primary key and later entries break ties. To reverse one numeric component, negate it. For 451 the key is `(-count[c], c)`, and for 791 it is the character's position in the order string.

Some orders depend on both items at once. In 179 Largest Number, `a` belongs before `b` when the string `a + b` is larger than `b + a`, which no single-item key expresses directly. Write a comparator that returns a negative, zero or positive number and wrap it with `functools.cmp_to_key`.

406 Queue Reconstruction by Height is a sort followed by inserts. Sort by height descending and then by `k` ascending, and insert each person at index `k`. Everyone already placed is at least as tall, so index `k` leaves exactly `k` such people in front, and later shorter people never change that count.

```python
# 1636: frequency ascending, then value descending
cnt = Counter(nums)
nums.sort(key=lambda x: (cnt[x], -x))

# 1122: values from arr2 in arr2's order, the rest ascending at the end
rank = {v: i for i, v in enumerate(arr2)}
arr1.sort(key=lambda x: (0, rank[x]) if x in rank else (1, x))

# 179: a goes first when a + b is the larger string
def cmp(a, b):
    return -1 if a + b > b + a else (1 if a + b < b + a else 0)
s = "".join(sorted(map(str, nums), key=cmp_to_key(cmp)))
answer = "0" if s[0] == "0" else s

# 406: tallest first, then by k, insert at index k
people.sort(key=lambda p: (-p[0], p[1]))
queue = []
for p in people:
    queue.insert(p[1], p)
```

In C++, `std::sort` requires a comparator that is a strict weak ordering. Above all, `comp(a, a)` must be false. Writing `return a <= b;` breaks this, because for equal items both `comp(a, b)` and `comp(b, a)` are true. That is undefined behavior: the output can be wrong, and some implementations read past the end of the range and crash when there are many duplicates. Use `<`, and for several keys compare `std::tie(a.k1, a.k2) < std::tie(b.k1, b.k2)`.

Stability also differs by language. Python's `sorted` and `list.sort` are stable, so the multi-pass trick from the previous section works. C++ `std::sort` is not stable; use `std::stable_sort` or add the original index as the last key.

Complexity is $O(n\log n)$ comparisons times the cost of one comparison, which is $O(L)$ for the string concatenations in 179. The most common mistake is a missing tie-breaker, such as forgetting that 1636 wants larger values first among equal frequencies.

## Bubble Sort

> **First step:** In practice, call the library sort instead. Bubble sort is worth knowing because every swap it makes fixes exactly one inversion, so its swap count equals the number of inversions in the input.

Bubble sort is one of the simplest sorting algorithms. It is often used as an introductory algorithm because it is easy to understand, even though it is not efficient for large datasets.

The name comes from the way larger elements "bubble up" to the top (end of the list), just as bubbles rise in water.

The basic idea:

- Compare adjacent elements.
- Swap them if they are in the wrong order.
- Repeat until no swaps are needed.

Bubble sort is valuable mostly as a teaching tool: it helps you build intuition for comparison-based sorting, swapping, and passes. In real programs, it’s rarely the best choice, but understanding why it’s slow teaches you what good sorting algorithms avoid (repeated full scans with tiny progress each pass).

Step-by-Step Walkthrough

1. Start from the first element.
2. Compare it with its neighbor to the right.
3. If the left is greater, swap them.
4. Move to the next pair and repeat until the end of the list.
5. After the first pass, the largest element is at the end.
6. On each new pass, ignore the elements already in their correct place.
7. Continue until the list is sorted.

Example Run:

We will sort the array:

```
[ 5 ][ 1 ][ 4 ][ 2 ][ 8 ]
```

Pass 1

Compare adjacent pairs and push the largest to the end.

```
Initial:   [ 5 ][ 1 ][ 4 ][ 2 ][ 8 ]

Compare 5 and 1 → swap
           [ 1 ][ 5 ][ 4 ][ 2 ][ 8 ]

Compare 5 and 4 → swap
           [ 1 ][ 4 ][ 5 ][ 2 ][ 8 ]

Compare 5 and 2 → swap
           [ 1 ][ 4 ][ 2 ][ 5 ][ 8 ]

Compare 5 and 8 → no swap
           [ 1 ][ 4 ][ 2 ][ 5 ][ 8 ]
```

Largest element 8 has bubbled to the end.

Pass 2

Now we only need to check the first 4 elements.

```
Start:     [ 1 ][ 4 ][ 2 ][ 5 ] [8]

Compare 1 and 4 → no swap
           [ 1 ][ 4 ][ 2 ][ 5 ] [8]

Compare 4 and 2 → swap
           [ 1 ][ 2 ][ 4 ][ 5 ] [8]

Compare 4 and 5 → no swap
           [ 1 ][ 2 ][ 4 ][ 5 ] [8]
```

Second largest element 5 is now in place.

Pass 3

Check only the first 3 elements.

```
Start:     [ 1 ][ 2 ][ 4 ] [5][8]

Compare 1 and 2 → no swap
           [ 1 ][ 2 ][ 4 ] [5][8]

Compare 2 and 4 → no swap
           [ 1 ][ 2 ][ 4 ] [5][8]
```

Sorted order is now reached.

Final Result:

```
[ 1 ][ 2 ][ 4 ][ 5 ][ 8 ]
```

Visual Illustration of Bubble Effect

Here’s how the largest values "bubble up" to the right after each pass:

```
Pass 1:  [ 5  1  4  2  8 ] → [ 1  4  2  5  8 ]
Pass 2:  [ 1  4  2  5 ]       → [ 1  2  4  5 ]  [8]
Pass 3:  [ 1  2  4 ]          → [ 1  2  4 ]     [5 8]
```

Sorted!

Optimizations:

- By keeping track of whether any swaps were made during a pass, Bubble Sort can terminate early if the array is already sorted. This optimization makes Bubble Sort’s best case much faster ($O(n)$).

Early exit avoids further passes after a pass makes no swaps. Nearly sorted input is not always fast: a small element near the end may still need many passes to move left. That idea, detecting when you can stop early, shows up in far better algorithms too.

Stability:

Bubble sort is stable when it swaps only strictly out-of-order neighbors, leaving equal keys untouched.

- If two elements have the same value, they remain in the same order relative to each other after sorting.
- This is important when sorting complex records where a secondary key matters.

Complexity:

| Case             | Time Complexity | Notes                                    |
| ---------------- | --------------- | ---------------------------------------- |
| Worst Case   | $O(n^2)$        | Array in reverse order                   |
| Average Case | $O(n^2)$        | Typically quadratic comparisons          |
| Best Case    | $O(n)$          | Already sorted + early exit optimization |
| Space        | $O(1)$          | In-place, requires no extra memory       |

Implementation:

- [C++ (The Algorithms)](https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/bubble_sort.cpp)
- [Python (The Algorithms)](https://github.com/TheAlgorithms/Python/blob/master/sorts/bubble_sort.py)

## Selection Sort

> **First step:** Check whether writes are the expensive operation or whether you only need the smallest few items. Selection sort does at most $n-1$ swaps, and stopping after $k$ passes gives the $k$ smallest items in $O(nk)$ time.

Selection sort is another simple sorting algorithm, often introduced right after bubble sort because it is equally easy to understand.

Instead of repeatedly "bubbling" elements, selection sort works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the array and placing it into its correct position.

Think of it like arranging books:

- Look through all the books, find the smallest one, and put it first.
- Then, look through the rest, find the next smallest, and put it second.
- Repeat until the shelf is sorted.

Selection sort is a nice contrast to bubble sort: bubble sort makes lots of small swaps, while selection sort makes very few swaps but still pays for a full scan each pass. That’s a useful engineering lesson: minimizing swaps doesn’t automatically mean you’re minimizing total work.

Step-by-Step Walkthrough

1. Start at the first position.
2. Search the entire unsorted region to find the smallest element.
3. Swap it with the element in the current position.
4. Move the boundary of the sorted region one step forward.
5. Repeat until all elements are sorted.

Example Run:

We will sort the array:

```
[ 64 ][ 25 ][ 12 ][ 22 ][ 11 ]
```

Pass 1

Find the smallest element in the entire array and put it in the first position.

```
Initial:    [ 64 ][ 25 ][ 12 ][ 22 ][ 11 ]

Smallest = 11
Swap 64 ↔ 11

Result:     [ 11 ][ 25 ][ 12 ][ 22 ][ 64 ]
```

The first element is now in its correct place.

Pass 2

Find the smallest element in the remaining unsorted region.

```
Start:      [ 11 ][ 25 ][ 12 ][ 22 ][ 64 ]

Smallest in [25,12,22,64] = 12
Swap 25 ↔ 12

Result:     [ 11 ][ 12 ][ 25 ][ 22 ][ 64 ]
```

The second element is now in place.

Pass 3

Repeat for the next unsorted region.

```
Start:      [ 11 ][ 12 ][ 25 ][ 22 ][ 64 ]

Smallest in [25,22,64] = 22
Swap 25 ↔ 22

Result:     [ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

The third element is now in place.

Pass 4

Finally, sort the last two.

```
Start:      [ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]

Smallest in [25,64] = 25
Already in correct place → no swap

Result:     [ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

Array fully sorted.

Final Result:

```
[ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

Visual Illustration of Selection

Here’s how the sorted region expands from left to right:

```
Pass 1:  [ 64  25  12  22  11 ] → [ 11 ] [ 25  12  22  64 ]
Pass 2:  [ 11 ][ 25  12  22  64 ] → [ 11  12 ] [ 25  22  64 ]
Pass 3:  [ 11  12 ][ 25  22  64 ] → [ 11  12  22 ] [ 25  64 ]
Pass 4:  [ 11  12  22 ][ 25  64 ] → [ 11  12  22  25 ] [ 64 ]
```

At each step:

- The left region is sorted
- The right region is unsorted

Optimizations:

- Unlike bubble sort, early exit is not possible because selection sort always scans the entire unsorted region to find the minimum.
- But it does fewer swaps: at most (n-1) swaps, compared to potentially many in bubble sort.

This is why selection sort sometimes appears in environments where writes are expensive (think: limited-write memory). Even there, it’s a trade: fewer writes, but still lots of comparisons.

Stability:

- Selection sort is NOT stable in its classic form.
- If two elements are equal, their order may change due to swapping.
- Stability can be achieved by inserting instead of swapping, but this makes the algorithm more complex.

Complexity:

| Case             | Time Complexity | Notes                                      |
| ---------------- | --------------- | ------------------------------------------ |
| Worst Case   | $O(n^2)$        | Scanning full unsorted region every pass   |
| Average Case | $O(n^2)$        | Quadratic comparisons                      |
| Best Case    | $O(n^2)$        | No improvement, still must scan every pass |
| Space        | $O(1)$          | In-place sorting                           |

Implementation:

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/selection_sort.cpp)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/selection_sort.py)

## Insertion Sort

> **First step:** Check how close to sorted the input already is. Insertion sort runs in $O(n + I)$ time, where $I$ is the number of inversions, so it is excellent on nearly sorted or tiny inputs and poor otherwise.

Insertion sort is a simple, intuitive sorting algorithm that works the way people often sort playing cards in their hands.

It builds the sorted portion one element at a time, by repeatedly taking the next element from the unsorted portion and inserting it into its correct position among the already sorted elements.

Insertion sort is the first “small” sort that feels genuinely useful in practice. Why? Because many real datasets are already almost sorted, and insertion sort loves that. It’s also a common helper inside faster algorithms: when the subproblems become tiny, insertion sort finishes them efficiently with low overhead.

The basic idea:

1. Start with the second element (the first element by itself is trivially sorted).
2. Compare it with elements to its left.
3. Shift larger elements one position to the right.
4. Insert the element into the correct spot.
5. Repeat until all elements are processed.

Example Run:

We will sort the array:

```
[ 12 ][ 11 ][ 13 ][ 5 ][ 6 ]
```

Pass 1: Insert 11

Compare 11 with 12 → shift 12 right → insert 11 before it.

```
Before:  [ 12 ][ 11 ][ 13 ][ 5 ][ 6 ]
Action:  Insert 11 before 12
After:   [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
```

Sorted portion: $[11, 12]$

Pass 2: Insert 13

Compare 13 with 12 → already greater → stays in place.

```
Before:  [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
After:   [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
```

Sorted portion: [11, 12, 13]

Pass 3: Insert 5

Compare 5 with 13 → shift 13
Compare 5 with 12 → shift 12
Compare 5 with 11 → shift 11
Insert 5 at start.

```
Before:  [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
Action:  Move 13 → Move 12 → Move 11 → Insert 5
After:   [ 5 ][ 11 ][ 12 ][ 13 ][ 6 ]
```

Sorted portion: [5, 11, 12, 13]

Pass 4: Insert 6

Compare 6 with 13 → shift 13
Compare 6 with 12 → shift 12
Compare 6 with 11 → shift 11
Insert 6 after 5.

```
Before:  [ 5 ][ 11 ][ 12 ][ 13 ][ 6 ]
Action:  Move 13 → Move 12 → Move 11 → Insert 6
After:   [ 5 ][ 6 ][ 11 ][ 12 ][ 13 ]
```

Sorted!

Final Result:

```
[ 5 ][ 6 ][ 11 ][ 12 ][ 13 ]
```

Visual Growth of Sorted Region

```
Start:   [ 12 | 11  13  5  6 ]
Pass 1:  [ 11  12 | 13  5  6 ]
Pass 2:  [ 11  12  13 | 5  6 ]
Pass 3:  [ 5  11  12  13 | 6 ]
Pass 4:  [ 5  6  11  12  13 ]
```

The bar ( | ) shows the boundary between sorted and unsorted.

Optimizations:

- Efficient for small arrays.
- Useful as a helper inside more complex sorts (e.g., Quick Sort or Merge Sort) for small subarrays.
- Can be optimized with binary search to find insertion positions faster (but shifting still takes linear time).

That last bullet is a subtle but important point: binary search reduces comparisons, not movement. If moving elements is the expensive part (and it often is), the big win comes from having fewer shifts, which happens naturally when the array is already nearly sorted.

Stability:

Insertion sort is stable when it shifts only strictly larger keys and inserts the new item after existing equal keys.

Complexity:

| Case             | Time Complexity | Notes                                              |
| ---------------- | --------------- | -------------------------------------------------- |
| Worst Case   | $O(n^2)$        | Reverse-sorted input                               |
| Average Case | $O(n^2)$        |                                                    |
| Best Case    | $O(n)$          | Already sorted input: only comparisons, no shifts |
| Space        | $O(1)$          | In-place                                           |

Implementation:

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/insertion_sort/src/insertion_sort.py)

## Merge Sort

> **First step:** Decide whether you need what merge sort uniquely gives: a stable order, a guaranteed $O(n\log n)$, a sort of a linked list, or a chance to count something across the two halves during the merge.

Merge sort divides the input into two halves, sorts each half recursively, and merges the two sorted results. Unlike quicksort, its split does not depend on the values, so the recursion stays balanced.

To merge, compare the first unconsumed item from each half and copy the smaller one to the output. When one half is exhausted, append the remainder of the other half. Each item is processed once during a merge.

Example:

```text
Input:       [38, 27, 43, 3]
Split:       [38, 27]       [43, 3]
Split again: [38] [27]      [43] [3]
Merge pairs: [27, 38]       [3, 43]
Final merge:
  3 < 27  -> [3]
  27 < 43 -> [3, 27]
  38 < 43 -> [3, 27, 38]
  append 43 -> [3, 27, 38, 43]
```

A subarray of length zero or one is already sorted. For larger inputs, the recurrence is $T(n)=2T(n/2)+\Theta(n)$, giving $\Theta(n\log n)$ time for the standard version in all input-order cases.

- Stability: take from the left half first when keys compare equal.
- Auxiliary space: $O(n)$ for array merging, plus $O(\log n)$ recursive stack space.
- Optimization: reuse one merge buffer rather than allocate a new buffer at every call. A bottom-up version merges runs of length 1, 2, 4, and so on without recursion.
- Applications: stable record sorting and external sorting, where sequentially merging sorted runs is useful.

Implementations:

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/cpp/merge_sort)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/sorting/python/merge_sort)

## Merging from the Back and Sorting Linked Lists

> **First step:** Look at where the output has to live. If it shares memory with an input, merge in the direction where the free space is; if the input is a linked list, split with slow and fast pointers instead of indexing.

88 Merge Sorted Array gives `nums1` with `m` real values followed by `n` empty slots. Merging from the front would overwrite values that have not been read yet. Merge from the back instead: compare the last unread values of both arrays and write the larger into the last free slot. When `nums2` runs out, the rest of `nums1` is already in place; when `nums1` runs out, copy what is left of `nums2`.

148 Sort List asks for $O(n\log n)$ on a singly linked list, which rules out quicksort's random access and makes merge sort the natural fit. Merging two lists needs no extra buffer, because nodes are relinked rather than copied.

```python
def sort_list(head):
    if head is None or head.next is None:
        return head
    slow, fast = head, head.next
    while fast and fast.next:
        slow, fast = slow.next, fast.next.next
    mid, slow.next = slow.next, None          # cut the list in two
    left, right = sort_list(head), sort_list(mid)
    dummy = tail = ListNode()
    while left and right:
        if left.val <= right.val:             # <= keeps it stable
            tail.next, left = left, left.next
        else:
            tail.next, right = right, right.next
        tail = tail.next
    tail.next = left or right
    return dummy.next
```

Both run in linear time per merge, so 88 is $O(m+n)$ and 148 is $O(n\log n)$ with $O(\log n)$ recursion stack (a bottom-up version gets $O(1)$ extra space). The most common mistake in 148 is starting `fast` at `head`, which on a two-node list leaves the right half empty and recurses forever.

## Counting Pairs with Merge Sort

> **First step:** Check whether the question counts pairs $i < j$ that satisfy a comparison between `nums[i]` and `nums[j]`. If it does, every such pair is split by exactly one merge step, so you can count it there.

When merge sort combines two sorted halves, every element of the left half came before every element of the right half in the original array. So any pair with $i$ on the left and $j$ on the right can be counted using only the two sorted halves, and pairs inside one half were already counted deeper in the recursion. Because both halves are sorted, a single pointer that only moves forward does the counting in linear time.

The classic case is inversion counting, pairs with $i < j$ and `nums[i] > nums[j]`. 493 Reverse Pairs counts `nums[i] > 2 * nums[j]`, which is a different test from the merge comparison, so count in a separate pass before merging. 315 Count of Smaller Numbers After Self needs a count per element: sort `(value, index)` pairs, and whenever a left element is taken during the merge, add the number of right elements already taken to `counts[index]`. Taking the left element on ties keeps equal values out of the count.

```python
def sort_and_count(a):
    if len(a) <= 1:
        return a, 0
    mid = len(a) // 2
    left, x = sort_and_count(a[:mid])
    right, y = sort_and_count(a[mid:])
    count, j = x + y, 0
    for v in left:                     # left is sorted, so j never moves back
        while j < len(right) and v > 2 * right[j]:    # 493; use v > right[j] for inversions
            j += 1
        count += j
    return merge(left, right), count   # the usual linear merge
```

This is $O(n\log n)$ time and $O(n)$ extra space. A Fenwick tree over coordinate-compressed values, scanned from right to left, solves the same problems in the same time. The most common mistake is in C++, where `2 * nums[j]` overflows a 32-bit int; compute it in 64 bits.

## Quick Sort

> **First step:** Choose the pivot at random (or shuffle once) and decide how keys equal to the pivot are handled. A fixed first or last pivot is quadratic on sorted input, and the tests for 912 Sort an Array are known to punish that.

Quick Sort is a divide-and-conquer algorithm. Unlike bubble sort or selection sort, which work by repeatedly scanning the whole array, Quick Sort works by partitioning the array into smaller sections around a "pivot" element and then sorting those sections independently.

It is one of the fastest sorting algorithms in practice, widely used in libraries and systems.

Partitioning puts a pivot in place and separates the remaining items into smaller subproblems. Balanced partitions reduce the problem quickly; consistently extreme pivots leave one large subproblem and can produce quadratic total work.

The basic idea:

1. Choose a pivot element (commonly the last, first, middle, or random element).
2. Rearrange (partition) the array so that:

   - All elements smaller than the pivot come before it.
   - All elements larger than the pivot come after it.

3. In the pivot-placement scheme illustrated here, the pivot is now in its final position. Other schemes, such as Hoare partitioning, return a split boundary rather than a finalized pivot. Equal keys must be handled consistently so recursion always shrinks.
4. Recursively apply Quick Sort to the left subarray and right subarray.

Example Run:

We will sort the array:

```
[ 10 ][ 80 ][ 30 ][ 90 ][ 40 ][ 50 ][ 70 ]
```

Step 1: Choose Pivot (last element = 70)

Partition around 70.

```
Initial:   [ 10 ][ 80 ][ 30 ][ 90 ][ 40 ][ 50 ][ 70 ]

→ Elements < 70: [ 10, 30, 40, 50 ]
→ Pivot (70) goes here ↓
Sorted split:  [ 10 ][ 30 ][ 40 ][ 50 ][ 70 ][ 90 ][ 80 ]
```

(ordering of right side may vary during partition; only pivot’s position is guaranteed)

Pivot (70) is in correct place.

Step 2: Left Subarray [10, 30, 40, 50]

Choose pivot = 50.

```
[ 10 ][ 30 ][ 40 ][ 50 ]   → pivot = 50

→ Elements < 50: [10, 30, 40]
→ Pivot at correct place

Result: [ 10 ][ 30 ][ 40 ][ 50 ]
```

Pivot (50) fixed.

Step 3: Left Subarray of Left [10, 30, 40]

Choose pivot = 40.

```
[ 10 ][ 30 ][ 40 ]   → pivot = 40

→ Elements < 40: [10, 30]
→ Pivot at correct place

Result: [ 10 ][ 30 ][ 40 ]
```

Pivot (40) fixed.

Step 4: [10, 30]

Choose pivot = 30.

```
[ 10 ][ 30 ]   → pivot = 30

→ Elements < 30: [10]

Result: [ 10 ][ 30 ]
```

The left side is sorted. On the right, partition `[90, 80]` around pivot `80` to obtain `[80, 90]`. Both recursive branches are now complete.

Final Result:

```
[ 10 ][ 30 ][ 40 ][ 50 ][ 70 ][ 80 ][ 90 ]
```

Visual Partition Illustration

Here’s how the array gets partitioned step by step:

```
Pass 1:  [ 10  80  30  90  40  50 | 70 ]
          ↓ pivot = 70
          [ 10  30  40  50 | 70 | 90  80 ]

Pass 2:  [ 10  30  40 | 50 ] [70] [90  80]
          ↓ pivot = 50
          [ 10  30  40 | 50 ] [70] [90  80]

Pass 3:  [ 10  30 | 40 ] [50] [70] [90  80]
          ↓ pivot = 40
          [ 10  30 | 40 ] [50] [70] [90  80]

Pass 4:  [ 10 | 30 ] [40] [50] [70] [90  80]
          ↓ pivot = 30
          [ 10 | 30 ] [40] [50] [70] [90  80]
```

Each pivot splits the problem smaller and smaller until fully sorted.

Optimizations:

- Pivot Choice: Choosing a good pivot (e.g., median or random) improves performance.
- Small Subarrays: For very small partitions, switch to Insertion Sort for efficiency.
- Recursion depth: recurse on the smaller partition and loop over the larger partition to guarantee $O(\log n)$ stack space even when partitions are uneven.

These are not “nice-to-haves”, they’re what separates textbook quick sort from industrial quick sort. Real implementations work hard to avoid worst-case behavior, because worst-case quick sort can be painfully slow on already-sorted or adversarial inputs.

Stability:

- Quick Sort is not stable by default (equal elements may be reordered).
- Stable versions exist, but require modifications.

Complexity:

| Case             | Time Complexity | Notes                                                              |
| ---------------- | --------------- | ------------------------------------------------------------------ |
| Worst Case   | $O(n^2)$        | Poor pivot choices (e.g., always smallest/largest in sorted array) |
| Average Case | $O(n \log n)$   | Expected performance, very fast in practice                        |
| Best Case    | $O(n \log n)$   | Balanced partitions                                                |
| Space | $O(\log n)$ expected, $O(n)$ worst | Ordinary recursive implementation |

Implementation:

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/quick_sort/src/quick_sort.cpp)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/quick_sort/src/quick_sort.py)

## Three-Way Partition (Dutch National Flag)

> **First step:** Count how many distinct groups the output needs. Two groups is a plain partition with one write pointer; three groups (less than, equal to, greater than) is the Dutch national flag with three pointers.

75 Sort Colors asks to sort an array of 0s, 1s and 2s in place in one pass. Keep three regions: `a[:lo]` holds 0s, `a[lo:mid]` holds 1s, `a[hi+1:]` holds 2s, and `a[mid:hi+1]` is still unknown. Each step looks at `a[mid]` and grows one region.

The same routine with "less than pivot, equal, greater than pivot" is the fix for quicksort and quickselect on inputs with many duplicates, since the whole equal block is excluded from further recursion. 905 Sort Array By Parity is the two-group version: one pointer marks where the next even number goes. 324 Wiggle Sort II builds on the same idea. The simple $O(n\log n)$ answer sorts a copy, fills the even indices with the smaller half reversed and the odd indices with the larger half reversed, and the reversal keeps copies of the median apart.

```python
def sort_colors(a):
    lo, mid, hi = 0, 0, len(a) - 1
    while mid <= hi:
        if a[mid] == 0:
            a[lo], a[mid] = a[mid], a[lo]
            lo += 1
            mid += 1
        elif a[mid] == 1:
            mid += 1
        else:
            a[mid], a[hi] = a[hi], a[mid]
            hi -= 1                  # do not move mid: the new a[mid] is unread
```

This is $O(n)$ time and $O(1)$ space. The most common mistake is advancing `mid` after swapping with `hi`, which skips the value that just arrived from the right end.

## Quickselect for the k-th Element

> **First step:** Convert the request into a 0-based index in ascending order. The k-th largest of $n$ items sits at index $n-k$, and the k closest points are the first $k$ after selecting by distance.

Quickselect is quicksort that recurses into one side only. After a partition the pivot is at its final index `p`. If `p` equals the target index you are done; otherwise continue only in the side that contains the target. With a random pivot each round discards a constant fraction of the range on average, so the total work is a geometric series.

It fits 215 Kth Largest Element in an Array and 973 K Closest Points to Origin (select on squared distance; the first $k$ items are the answer in any order). It also finds the median that the linear-time version of 324 Wiggle Sort II needs. In C++, `std::nth_element` does the same job.

```python
def select(a, k):                    # value that would be at index k after sorting
    lo, hi = 0, len(a) - 1
    while True:
        r = random.randint(lo, hi)
        a[r], a[hi] = a[hi], a[r]
        store = lo
        for i in range(lo, hi):
            if a[i] < a[hi]:
                a[i], a[store] = a[store], a[i]
                store += 1
        a[store], a[hi] = a[hi], a[store]
        if store == k:
            return a[store]
        if store < k:
            lo = store + 1
        else:
            hi = store - 1

kth_largest = select(nums, len(nums) - k)
```

Expected time is $O(n)$ with $O(1)$ extra space, but the worst case is $O(n^2)$. The most common mistake is a partition like this one on input with many equal values: every equal item lands on one side and each round shrinks the range by one, so switch to a three-way partition when duplicates are likely.

## Heap Sort

> **First step:** Ask whether you need the full order or only the top $k$ items. A full heap sort costs $O(n\log n)$, while a heap kept at size $k$ answers top $k$ questions in $O(n\log k)$.

Heap Sort is a comparison-based sorting algorithm that uses a special data structure called a binary heap.
It is efficient, with guaranteed $O(n \log n)$ performance, and sorts in-place (no extra array needed).

Heap sort is useful when predictable worst-case time and low auxiliary memory matter. Its $O(n\log n)$ worst-case bound avoids quicksort's dependence on pivot quality.

The basic idea:

1. Build a max heap from the input array.

   - In a max heap, every parent is greater than or equal to its children.
   - This ensures the largest element is at the root (first index).

2. Swap the root (largest element) with the last element of the heap.
3. Reduce the heap size by 1 (ignore the last element, which is now in place).
4. Heapify (restore heap property).
5. Repeat until all elements are sorted.

Example Run:

We will sort the array:

```
[ 4 ][ 10 ][ 3 ][ 5 ][ 1 ]
```

Step 1: Build Max Heap

Binary tree view:

```
Heap:
        4
      /   \
    10     3
   /  \
  5    1
```

Heapify → Largest at top:

```
Heap:
       10
      /   \
     5     3
    / \
   4   1

Array: [ 10 ][ 5 ][ 3 ][ 4 ][ 1 ]
```

Step 2: Swap Root with Last

Swap 10 ↔ 1 → largest (10) moves to correct final place.

```
[ 1 ][ 5 ][ 3 ][ 4 ][ 10 ]
```

Heapify the reduced heap [1,5,3,4]:

```
Heap:
       5
      / \
     4   3
    /
   1

Array: [ 5 ][ 4 ][ 3 ][ 1 ][ 10 ]
```

Step 3: Swap Root with Last

Swap 5 ↔ 1.

```
[ 1 ][ 4 ][ 3 ][ 5 ][ 10 ]
```

Heapify reduced heap [1,4,3]:

```
Heap:
       4
      / \
     1   3

Array: [ 4 ][ 1 ][ 3 ][ 5 ][ 10 ]
```

Step 4: Swap Root with Last

Swap 4 ↔ 3.

```
[ 3 ][ 1 ][ 4 ][ 5 ][ 10 ]
```

Heapify reduced heap [3,1]:

```
Heap:
       3
      /
     1

Array: [ 3 ][ 1 ][ 4 ][ 5 ][ 10 ]
```

Step 5: Swap Root with Last

Swap 3 ↔ 1.

```
[ 1 ][ 3 ][ 4 ][ 5 ][ 10 ]
```

Sorted array achieved.

Final Result:

```
[ 1 ][ 3 ][ 4 ][ 5 ][ 10 ]
```

Visual Progress:

```
Initial:   [ 4  10  3  5  1 ]
Heapify:   [ 10  5  3  4  1 ]
Step 1:    [ 5  4  3  1 | 10 ]
Step 2:    [ 4  1  3 | 5  10 ]
Step 3:    [ 3  1 | 4  5  10 ]
Step 4:    [ 1 | 3  4  5  10 ]
Sorted:    [ 1  3  4  5  10 ]
```

Each step places the largest element into its correct final position.

Optimizations:

- Building the heap can be done in O(n) time using bottom-up heapify.
- After building, each extract-max + heapify takes O(log n).

Stability:

Heap sort is not stable. Equal elements may not preserve their original order because of swaps.

Complexity:

| Case             | Time Complexity | Notes                  |
| ---------------- | --------------- | ---------------------- |
| Worst Case   | $O(n \log n)$   |                        |
| Average Case | $O(n \log n)$   |                        |
| Best Case | $O(n \log n)$ | Upper bound; equal keys can allow linear time with early-stopping sift-down |
| Space        | $O(1)$          | In-place               |

Implementation:

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/heap_sort.cpp)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/heap_sort.py)

## Partial Sorting with a Heap (Top k)

> **First step:** Decide which end you are keeping and pick the opposite kind of heap. To keep the $k$ largest, use a min-heap of size $k$ so the weakest kept item sits on top and is the one evicted.

Many problems ask for a few items from the top of an order: 215 Kth Largest Element, 347 Top K Frequent Elements, 973 K Closest Points to Origin, and 692 Top K Frequent Words. Sorting everything costs $O(n\log n)$ and does more work than needed. A heap that never grows past $k$ costs $O(n\log k)$ and also works on a stream.

Python's `heapq` is a min-heap. To keep the $k$ smallest items instead, push negated keys, for example `(-dist, x, y)` in 973. For counts, push `(count, value)` pairs so the heap orders by count. For one-off queries `heapq.nlargest(k, items, key=...)` does this for you, and C++ has `std::partial_sort` and `std::priority_queue`.

```python
def k_largest(nums, k):
    heap = []
    for x in nums:
        heapq.heappush(heap, x)
        if len(heap) > k:
            heapq.heappop(heap)      # drop the smallest of the k + 1
    return heap                      # heap[0] is the k-th largest
```

This runs in $O(n\log k)$ time and $O(k)$ space. The most common mistake is using the heap in the wrong direction, a max-heap of size $k$ for the $k$ largest, which evicts exactly the items you wanted to keep.

## Radix Sort

> **First step:** Count the digits $d$ in the largest key and pick the base $b$. Radix sort pays off when $d(n+b)$ is clearly smaller than $n\log n$, and negative numbers need a shift or separate handling.

Radix Sort is a non-comparison-based sorting algorithm.
Instead of comparing elements directly, it processes numbers digit by digit, from either the least significant digit (LSD) or the most significant digit (MSD), using digit-based distribution. LSD radix sort requires a stable intermediate sort, commonly counting sort; MSD radix sort recursively sorts digit buckets and may use an unstable in-place partition.

Radix sort uses the structure of keys, such as digits or bytes, to distribute items directly into buckets. It can avoid the comparison-sorting lower bound because it performs more informative operations than pairwise comparisons.

Because it avoids comparisons, Radix Sort can achieve linear time complexity in many cases.

The basic idea:

1. Pick a digit position (units, tens, hundreds, etc.).
2. Sort the array by that digit using a stable sorting algorithm.
3. Move to the next digit.
4. Repeat until all digits are processed.

Example Run (LSD Radix Sort)

We will sort the array:

```
[ 170 ][ 45 ][ 75 ][ 90 ][ 802 ][ 24 ][ 2 ][ 66 ]
```

Step 1: Sort by 1s place (units digit)

```
Original: [170, 45, 75, 90, 802, 24, 2, 66]

By 1s digit:
[170][90] (0)
[802][2]  (2)
[24]      (4)
[45][75]  (5)
[66]      (6)

Result: [170][90][802][2][24][45][75][66]
```

Step 2: Sort by 10s place

```
[170][90][802][2][24][45][75][66]

By 10s digit:
[802][2]   (0)
[24]       (2)
[45]       (4)
[66]       (6)
[170][75]  (7)
[90]       (9)

Result: [802][2][24][45][66][170][75][90]
```

Step 3: Sort by 100s place

```
[802][2][24][45][66][170][75][90]

By 100s digit:
[2][24][45][66][75][90]  (0)
[170]                   (1)
[802]                   (8)

Result: [2][24][45][66][75][90][170][802]
```

Final Result:

```
[ 2 ][ 24 ][ 45 ][ 66 ][ 75 ][ 90 ][ 170 ][ 802 ]
```

Visual Process:

```
Step 1 (1s):   [170  90  802  2  24  45  75  66]
Step 2 (10s):  [802  2  24  45  66  170  75  90]
Step 3 (100s): [2  24  45  66  75  90  170  802]
```

Each pass groups by digit → final sorted order.

LSD vs MSD

- LSD (Least Significant Digit first): Process digits from right (units) to left (hundreds). Most common, simpler.
- MSD (Most Significant Digit first): Process from left to right, useful for variable-length data like strings.

Stability:

- The LSD variant shown is stable because each digit pass is stable. Stability of MSD variants depends on their implementation.
- Equal elements remain in the same order across passes.

Complexity:

Let $n$ be the number of keys, $d$ the number of digit positions, and $b$ the radix (number of possible digit values).

- Time: $O(d(n+b))$ with counting sort for each digit.
- Auxiliary space: $O(n+b)$, reusing the output and count arrays between passes.
- For fixed $d$ and $b$, time is $O(n)$. Digit extraction is assumed constant time.

The example uses non-negative base-10 integers, treating missing leading digits as zero. Signed integers require an order-preserving key transformation or separate handling of signs; strings need a defined alphabet and end-of-string ordering.

Implementation:

- [C++ (The Algorithms)](https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/radix_sort.cpp)
- [Python (The Algorithms)](https://github.com/TheAlgorithms/Python/blob/master/sorts/radix_sort.py)

## Counting Sort

> **First step:** Find the value range $k$ and compare it with $n$. If $k$ is small (letters, scores up to 1000, frequencies up to $n$), a count array replaces sorting entirely.

Counting Sort is a non-comparison-based sorting algorithm that works by counting occurrences of each distinct element and then calculating their positions in the output array.

It is especially efficient when:

- The input values are integers.
- The range of values (k) is not significantly larger than the number of elements (n).

Counting sort is the engine that often makes radix sort practical. It’s incredibly fast when the value range is reasonable, but it’s not a general-purpose sort: it relies on keys being integers in a known range. When it fits, it feels like you’re sorting by flipping a few switches rather than doing a lot of comparisons.

The basic idea:

1. Find the range of the input (min to max).
2. Create a count array to store the frequency of each number.
3. Modify the count array to store prefix sums (cumulative counts).

   - The cumulative count identifies the end of each key's output region.

4. Place elements into the output array in order, using the count array.

Example Run:

We will sort the array:

```
[ 4 ][ 2 ][ 2 ][ 8 ][ 3 ][ 3 ][ 1 ]
```

Step 1: Count Frequencies

```
Elements:  1  2  3  4  5  6  7  8
Counts:    1  2  2  1  0  0  0  1
```

Step 2: Prefix Sums

```
Elements:  1  2  3  4  5  6  7  8
Counts:    1  3  5  6  6  6  6  7
```

Each prefix count gives the number of elements less than or equal to that value. Its last available zero-based output position is `count[value] - 1`. After placing an element there, decrement its count.

Step 3: Place Elements

Process input from right → left (for stability).

```
Input:  [4,2,2,8,3,3,1]

Place 1 → index 0
Place 3 → index 4
Place 3 → index 3
Place 8 → index 6
Place 2 → index 2
Place 2 → index 1
Place 4 → index 5
```

Final Result:

```
[ 1 ][ 2 ][ 2 ][ 3 ][ 3 ][ 4 ][ 8 ]
```

Visual Process:

```
Step 1 Count:   [0,1,2,2,1,0,0,0,1]
Step 2 Prefix:  [0,1,3,5,6,6,6,6,7]
Step 3 Output:  [1,2,2,3,3,4,8]
```

Linear-time sorting by counting positions.

Stability:

With cumulative end positions, counting sort is stable when it scans the input right to left and decrements the count after each placement. Negative keys can be handled by indexing the count array with `key - minimum`; then $k = maximum - minimum + 1$. Return immediately for an empty input before computing its minimum or maximum.

Complexity:

| Case        | Time Complexity | Notes                                       |
| ----------- | --------------- | ------------------------------------------- |
| Overall | $O(n + k)$      | $n$ = number of elements, $k$ = value range |
| Space   | $O(n + k)$      | Extra array for counts + output             |

Implementation:

- [C++ (The Algorithms)](https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/counting_sort.cpp)
- [Python (The Algorithms)](https://github.com/TheAlgorithms/Python/blob/master/sorts/counting_sort.py)

## Bucket Sort for Frequencies and Gaps

> **First step:** Look for a natural bound on the keys. Frequencies never exceed $n$, letters fit in 26 slots, and $n$ values spread over a range force at least one large gap; any of these lets buckets replace comparisons.

A frequency is an integer between 1 and $n$, so items can be bucketed by how often they occur instead of sorted by it. That gives 347 Top K Frequent Elements and 451 Sort Characters By Frequency in linear time: count, put each value into `buckets[count]`, and read the buckets from high to low.

274 H-Index uses the same bound. Any citation count above $n$ can be capped at $n$, so count papers per capped value, then walk $h$ from $n$ down while keeping a running total of papers with at least $h$ citations; the first $h$ where that total reaches $h$ is the answer. 242 Valid Anagram and 49 Group Anagrams also fit here: a tuple of 26 letter counts is an $O(L)$ key, where sorting each word costs $O(L\log L)$.

164 Maximum Gap asks for linear time. With $n$ values from `lo` to `hi`, the largest gap is at least the average $(hi - lo)/(n-1)$. Use buckets of width $b = \max(1, \lfloor (hi-lo)/(n-1) \rfloor)$. Two values in one bucket differ by less than $b$, so the answer always spans two buckets. Keep only each bucket's minimum and maximum and compare each nonempty bucket's minimum with the previous nonempty bucket's maximum. LSD radix sort followed by a scan also works.

```python
def top_k_frequent(nums, k):
    cnt = Counter(nums)
    buckets = [[] for _ in range(len(nums) + 1)]
    for value, c in cnt.items():
        buckets[c].append(value)
    out = []
    for c in range(len(nums), 0, -1):
        for value in buckets[c]:
            out.append(value)
            if len(out) == k:
                return out
    return out
```

These run in $O(n)$ time plus the size of the bucket array. The most common mistake is sizing the bucket array by the values instead of by the bound, for example allocating up to the largest citation count in 274 instead of capping at $n$.

## Comparison Table

Space means auxiliary storage, including the recursion stack. Average-case bounds require input or randomization assumptions; the table does not predict elapsed time.

Below is a consolidated side-by-side comparison of all the sorts we’ve covered so far:

Use complexity bounds together with stability, memory requirements, and input characteristics. Constant factors and cache behavior also affect performance, so an asymptotically good bound alone does not identify the best implementation for every workload.

| Algorithm          | Best Case     | Average       | Worst Case    | Space       | Stable? | Notes                  |
| ------------------ | ------------- | ------------- | ------------- | ----------- | ------- | ---------------------- |
| Bubble Sort    | $O(n)$        | $O(n^2)$      | $O(n^2)$      | $O(1)$      | Yes     | Simple, slow           |
| Selection Sort | $O(n^2)$      | $O(n^2)$      | $O(n^2)$      | $O(1)$      | No      | Few swaps              |
| Insertion Sort | $O(n)$        | $O(n^2)$      | $O(n^2)$      | $O(1)$      | Yes     | Good for small inputs  |
| Quick Sort | $O(n\log n)$ | $O(n\log n)$ | $O(n^2)$ | $O(n)$ worst | No | Smaller-side recursion reduces stack to $O(\log n)$ |
| Merge Sort | $O(n\log n)$ | $O(n\log n)$ | $O(n\log n)$ | $O(n)$ | Yes | Stable merging |
| Heap Sort      | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$      | No      | Guaranteed performance |
| Counting Sort  | $O(n + k)$    | $O(n + k)$    | $O(n + k)$    | $O(n + k)$  | Yes     | Integers only          |
| LSD Radix Sort | $O(d(n+b))$ | $O(d(n+b))$ | $O(d(n+b))$ | $O(n+b)$ | Yes | $d$ digits, radix $b$ |

Use insertion sort for tiny or nearly-sorted arrays, quick sort for general high speed (with good pivot strategy), heap sort for worst-case guarantees, and counting/radix when your keys make it possible.

## Interval Problems

> **First step:** Decide whether you are combining intervals or choosing among them. Combining (merge, insert, count overlaps) sorts by start; choosing the most compatible intervals or the fewest points that hit them sorts by end. Also settle whether touching endpoints overlap.

56 Merge Intervals sorts by start and walks once. Each interval either overlaps the last merged one, which then extends to the larger of the two ends, or starts a new merged interval. 57 Insert Interval gets input that is already sorted, so it needs no sort: copy the intervals that end before the new one starts, absorb every interval that starts at or before its end, then copy the rest. 252 Meeting Rooms sorts by start and checks each neighbor pair for overlap.

253 Meeting Rooms II asks for the maximum number of meetings running at once. Sort the start times and the end times separately and walk both, opening a room when a meeting starts before the earliest unfinished one ends. A min-heap of end times gives the same answer and is easier to extend when you also need to know which room is used.

435 Non-overlapping Intervals and 452 Minimum Number of Arrows to Burst Balloons sort by end. Keeping the interval that finishes first leaves the most room for the rest, and the exchange argument behind this is in the [greedy algorithms notes](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/greedy_algorithms.md). In 435 the answer is $n$ minus the number kept. In 452 shoot each arrow at the current end and fire a new one only when a balloon starts strictly after it, since touching balloons share an arrow. 1288 Remove Covered Intervals sorts by start ascending and end descending, so an interval is covered exactly when its end does not exceed the largest end seen so far.

```python
def merge_intervals(intervals):      # 56
    intervals.sort(key=lambda iv: iv[0])
    out = []
    for s, e in intervals:
        if out and s <= out[-1][1]:
            out[-1][1] = max(out[-1][1], e)
        else:
            out.append([s, e])
    return out

def min_rooms(intervals):            # 253
    starts = sorted(s for s, e in intervals)
    ends = sorted(e for s, e in intervals)
    rooms, j = 0, 0
    for s in starts:
        if s < ends[j]:
            rooms += 1               # no meeting has ended yet: open a room
        else:
            j += 1                   # reuse the room freed at ends[j]
    return rooms
```

All of these are $O(n\log n)$ for the sort and $O(n)$ for the scan, except 57, which is $O(n)$. The most common mistake in 56 is setting the merged end to the new end instead of the maximum, which breaks when one interval contains the next, as in `[1, 10]` followed by `[2, 3]`.

## Sorting as Preprocessing

> **First step:** Ask whether the answer depends on the original positions. If it does not, sorting first costs only $O(n\log n)$ and turns a pair or triple search into two pointers or binary search.

Once an array is sorted, a pair sum that is too small can only grow by moving the left pointer right, and one that is too large can only shrink by moving the right pointer left. This turns the $O(n^2)$ pair search into $O(n)$. 15 3Sum fixes each first element and runs that two-pointer scan on the rest, for $O(n^2)$ overall; 16 3Sum Closest and 18 4Sum follow the same shape. Sorting also puts duplicates next to each other, which is how 3Sum avoids repeated triplets.

Sorted data also supports binary search, for example counting how many values are at most a target with `bisect_right`; the [searching notes](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/notes/searching.md) cover the variants. 945 Minimum Increment to Make Array Unique sorts and then keeps `need`, the smallest value the next item may take: each item `x` costs `max(0, need - x)` moves and sets `need = max(need, x) + 1`. 49 Group Anagrams uses the sorted string of each word as a dictionary key.

```python
def three_sum(nums):
    nums.sort()
    res = []
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue                 # same first value, same triplets
        lo, hi = i + 1, len(nums) - 1
        while lo < hi:
            total = nums[i] + nums[lo] + nums[hi]
            if total < 0:
                lo += 1
            elif total > 0:
                hi -= 1
            else:
                res.append([nums[i], nums[lo], nums[hi]])
                lo, hi = lo + 1, hi - 1
                while lo < hi and nums[lo] == nums[lo - 1]:
                    lo += 1
    return res
```

The cost is $O(n\log n)$ for the sort plus the scan, $O(n^2)$ in total for 3Sum. The most common mistake is sorting when the problem asks for original indices, as in 1 Two Sum; sort `(value, index)` pairs or use a hash map instead.

## Reading the Problem Statement

Certain phrases in a problem statement point straight at a sorting technique. The table maps the common ones to what they usually mean for your code.

| If the problem says | What it means for your code |
| --- | --- |
| Merge overlapping intervals | Sort by start, extend the last merged interval with the larger end |
| Keep the most non-overlapping intervals, or remove the fewest | Sort by end and greedily keep the earliest finish |
| Minimum rooms, or the most events at the same time | Sort starts and ends separately, or sweep with a min-heap of end times |
| k-th largest or k-th smallest | Quickselect with a random pivot or a heap of size $k$, not a full sort |
| Top k, k closest, k most frequent | Heap of size $k$ in $O(n\log k)$, or buckets by frequency |
| Values in a small range, or only lowercase letters | Counting sort or a count array |
| Sort in place, only three distinct values | Dutch national flag with three pointers in one pass |
| Move all items with a property to the front | Two-pointer partition in $O(n)$ time and $O(1)$ space |
| Relative order of equal items must be kept | Stable sort, or the original index as the last key |
| Sort by frequency, then by value | Key tuple with the tie-breaker written out |
| Order defined by another string or array | Rank dictionary as the key, or counting in that order |
| Arrange numbers to form the largest number | Custom comparator on a + b against b + a |
| Anagrams, or the same letters in a different order | Sorted string or 26-count tuple as the key |
| Count pairs i < j where nums[i] is larger than c times nums[j] | Merge sort counting, or a Fenwick tree over compressed values |
| For each element, count smaller elements to its right | Merge sort over (value, index) pairs, or a Fenwick tree |
| Sort a linked list in $O(n\log n)$ | Merge sort, split with slow and fast pointers |
| Merge into the first array, which has spare room at the end | Fill from the back with three pointers |
| Linear time even though values are large | Bucket (pigeonhole) or radix sort |
| n up to $10^5$ or $10^6$ | $O(n\log n)$ sorting fits comfortably |
| Triplets summing to a target without duplicates | Sort, then two pointers, skipping equal neighbors |
