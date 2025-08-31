## Sorting

In the realm of computer science, 'sorting' refers to the process of arranging a collection of items in a specific, predetermined order. This order is based on certain criteria that are defined beforehand.

For instance:

- **Numbers** can be sorted according to their numerical values, either in ascending or descending order.
- **Strings** are typically sorted in alphabetical order, similar to how words are arranged in dictionaries.

Sorting isn't limited to just numbers and strings. Virtually any type of object can be sorted, provided there is a clear definition of order for them.

### Stability in Sorting

Stability, in the context of sorting, refers to preserving the relative order of equal items in the sorted output. In simple terms, when two items have equal keys:

- In an **unstable** sorting algorithm, their order might be reversed in the sorted output.
- In a **stable** sorting algorithm, their relative order remains unchanged.

Let’s take an analogous list of medieval knights (each with its original 0-based index):

```
[Lancelot0] [Gawain1] [Lancelot2] [Percival3] [Gawain4]
```

We’ll “sort” them by name, bringing all **Lancelot**s to the front, then **Gawain**, then **Percival**.

#### Stable Sort

A **stable** sort preserves the left-to-right order of equal items.

I. **Bring every “Lancelot” to the front**, in the order they appeared (index 0 before 2):

```
[Lancelot0] [Lancelot2] [Gawain1] [Percival3] [Gawain4]
```

II. **Next, move the two “Gawain”s** ahead of “Percival”, again preserving 1 before 4:

```
[Lancelot0] [Lancelot2] [Gawain1] [Gawain4] [Percival3]
```

So the **stable-sorted** sequence is:

```
[Lancelot0] [Lancelot2] [Gawain1] [Gawain4] [Percival3]
```

#### Unstable Sort

An **unstable** sort may reorder equal items arbitrarily.

I. When collecting the “Lancelot”s, it might pick index 2 before 0:

```
[Lancelot2] [Lancelot0] [Gawain1] [Percival3] [Gawain4]
```

II. Later, the two “Gawain”s might swap (4 before 1):

```
[Lancelot2] [Lancelot0] [Gawain4] [Gawain1] [Percival3]
```

So one possible **unstable-sorted** sequence is:

```
[Lancelot2] [Lancelot0] [Gawain4] [Gawain1] [Percival3]
```

If you then did a second pass (say, sorting by rank or battle-honors) you’d only want to reorder knights of different names, trusting that ties (same-name knights) are still in their intended original order—something only a stable sort guarantees.

### Bubble Sort

Bubble sort is one of the simplest sorting algorithms. It is often used as an **introductory algorithm** because it is easy to understand, even though it is not efficient for large datasets.

The name comes from the way **larger elements "bubble up"** to the top (end of the list), just as bubbles rise in water.

The basic idea:

* Compare **adjacent elements**.
* Swap them if they are in the wrong order.
* Repeat until no swaps are needed.

**Step-by-Step Walkthrough**

1. Start from the **first element**.
2. Compare it with its **neighbor to the right**.
3. If the left is greater, **swap** them.
4. Move to the next pair and repeat until the end of the list.
5. After the **first pass**, the largest element is at the end.
6. On each new pass, ignore the elements already in their correct place.
7. Continue until the list is sorted.

**Example Run**

We will sort the array:

```
[ 5 ][ 1 ][ 4 ][ 2 ][ 8 ]
```

**Pass 1**

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

✔ Largest element **8** has bubbled to the end.

**Pass 2**

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

✔ Second largest element **5** is now in place.

**Pass 3**

Check only the first 3 elements.

```
Start:     [ 1 ][ 2 ][ 4 ] [5][8]

Compare 1 and 2 → no swap
           [ 1 ][ 2 ][ 4 ] [5][8]

Compare 2 and 4 → no swap
           [ 1 ][ 2 ][ 4 ] [5][8]
```

✔ Sorted order is now reached.

**Final Result**

```
[ 1 ][ 2 ][ 4 ][ 5 ][ 8 ]
```

**Visual Illustration of Bubble Effect**

Here’s how the **largest values "bubble up"** to the right after each pass:

```
Pass 1:  [ 5  1  4  2  8 ] → [ 1  4  2  5  8 ]
Pass 2:  [ 1  4  2  5 ]       → [ 1  2  4  5 ]  [8]
Pass 3:  [ 1  2  4 ]          → [ 1  2  4 ]     [5 8]
```

Sorted! ✅

**Optimizations**

* **Early Exit**: If in a full pass **no swaps occur**, the array is already sorted, and the algorithm can terminate early.
* This makes Bubble Sort’s **best case** much faster (\$O(n)\$).

**Stability**

Bubble sort is **stable**.

* If two elements have the same value, they remain in the same order relative to each other after sorting.
* This is important when sorting complex records where a secondary key matters.

**Complexity**

| Case             | Time Complexity | Notes                                  |
|------------------|-----------------|----------------------------------------|
| **Worst Case**   | $O(n^2)$        | Array in reverse order                 |
| **Average Case** | $O(n^2)$        | Typically quadratic comparisons        |
| **Best Case**    | $O(n)$          | Already sorted + early exit optimization |
| **Space**        | $O(1)$          | In-place, requires no extra memory     |

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/bubble_sort/src/bubble_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/bubble_sort/src/bubble_sort.py)

### Selection Sort

Selection sort is another simple sorting algorithm, often introduced right after bubble sort because it is equally easy to understand.

Instead of repeatedly "bubbling" elements, **selection sort works by repeatedly selecting the smallest (or largest) element** from the unsorted portion of the array and placing it into its correct position.

Think of it like arranging books:

* Look through all the books, find the smallest one, and put it first.
* Then, look through the rest, find the next smallest, and put it second.
* Repeat until the shelf is sorted.

**Step-by-Step Walkthrough**

1. Start at the **first position**.
2. Search the **entire unsorted region** to find the smallest element.
3. Swap it with the element in the current position.
4. Move the boundary of the sorted region one step forward.
5. Repeat until all elements are sorted.

**Example Run**

We will sort the array:

```
[ 64 ][ 25 ][ 12 ][ 22 ][ 11 ]
```

**Pass 1**

Find the smallest element in the entire array and put it in the first position.

```
Initial:    [ 64 ][ 25 ][ 12 ][ 22 ][ 11 ]

Smallest = 11  
Swap 64 ↔ 11  

Result:     [ 11 ][ 25 ][ 12 ][ 22 ][ 64 ]
```

✔ The first element is now in its correct place.

**Pass 2**

Find the smallest element in the remaining unsorted region.

```
Start:      [ 11 ][ 25 ][ 12 ][ 22 ][ 64 ]

Smallest in [25,12,22,64] = 12  
Swap 25 ↔ 12  

Result:     [ 11 ][ 12 ][ 25 ][ 22 ][ 64 ]
```

✔ The second element is now in place.

**Pass 3**

Repeat for the next unsorted region.

```
Start:      [ 11 ][ 12 ][ 25 ][ 22 ][ 64 ]

Smallest in [25,22,64] = 22  
Swap 25 ↔ 22  

Result:     [ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

✔ The third element is now in place.

**Pass 4**

Finally, sort the last two.

```
Start:      [ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]

Smallest in [25,64] = 25  
Already in correct place → no swap  

Result:     [ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

✔ Array fully sorted.

**Final Result**

```
[ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

**Visual Illustration of Selection**

Here’s how the **sorted region expands** from left to right:

```
Pass 1:  [ 64  25  12  22  11 ] → [ 11 ] [ 25  12  22  64 ]
Pass 2:  [ 11 ][ 25  12  22  64 ] → [ 11  12 ] [ 25  22  64 ]
Pass 3:  [ 11  12 ][ 25  22  64 ] → [ 11  12  22 ] [ 25  64 ]
Pass 4:  [ 11  12  22 ][ 25  64 ] → [ 11  12  22  25 ] [ 64 ]
```

At each step:

* The **left region is sorted** ✅
* The **right region is unsorted** 🔄

**Optimizations**

* Unlike bubble sort, **early exit is not possible** because selection sort always scans the entire unsorted region to find the minimum.
* But it does fewer swaps: **at most (n-1) swaps**, compared to potentially many in bubble sort.

**Stability**

* **Selection sort is NOT stable** in its classic form.
* If two elements are equal, their order may change due to swapping.
* Stability can be achieved by inserting instead of swapping, but this makes the algorithm more complex.

**Complexity**

| Case             | Time Complexity | Notes                                      |
|------------------|-----------------|--------------------------------------------|
| **Worst Case**   | $O(n^2)$        | Scanning full unsorted region every pass   |
| **Average Case** | $O(n^2)$        | Quadratic comparisons                      |
| **Best Case**    | $O(n^2)$        | No improvement, still must scan every pass |
| **Space**        | $O(1)$          | In-place sorting                           |

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/selection_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/selection_sort.py)

### Insertion Sort

Insertion sort is a simple, intuitive sorting algorithm that works the way people often sort playing cards in their hands.

It builds the **sorted portion one element at a time**, by repeatedly taking the next element from the unsorted portion and inserting it into its correct position among the already sorted elements.

The basic idea:

1. Start with the **second element** (the first element by itself is trivially sorted).
2. Compare it with elements to its **left**.
3. Shift larger elements one position to the right.
4. Insert the element into the correct spot.
5. Repeat until all elements are processed.

**Example Run**

We will sort the array:

```
[ 12 ][ 11 ][ 13 ][ 5 ][ 6 ]
```

**Pass 1: Insert 11**

Compare 11 with 12 → shift 12 right → insert 11 before it.

```
Before:  [ 12 ][ 11 ][ 13 ][ 5 ][ 6 ]
Action:  Insert 11 before 12
After:   [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
```

✔ Sorted portion: $[11, 12]$

**Pass 2: Insert 13**

Compare 13 with 12 → already greater → stays in place.

```
Before:  [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
After:   [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
```

✔ Sorted portion: \[11, 12, 13]

**Pass 3: Insert 5**

Compare 5 with 13 → shift 13
Compare 5 with 12 → shift 12
Compare 5 with 11 → shift 11
Insert 5 at start.

```
Before:  [ 11 ][ 12 ][ 13 ][ 5 ][ 6 ]
Action:  Move 13 → Move 12 → Move 11 → Insert 5
After:   [ 5 ][ 11 ][ 12 ][ 13 ][ 6 ]
```

✔ Sorted portion: [5, 11, 12, 13]

**Pass 4: Insert 6**

Compare 6 with 13 → shift 13
Compare 6 with 12 → shift 12
Compare 6 with 11 → shift 11
Insert 6 after 5.

```
Before:  [ 5 ][ 11 ][ 12 ][ 13 ][ 6 ]
Action:  Move 13 → Move 12 → Move 11 → Insert 6
After:   [ 5 ][ 6 ][ 11 ][ 12 ][ 13 ]
```

✔ Sorted!

**Final Result**

```
[ 5 ][ 6 ][ 11 ][ 12 ][ 13 ]
```

**Visual Growth of Sorted Region**

```
Start:   [ 12 | 11  13  5  6 ]
Pass 1:  [ 11  12 | 13  5  6 ]
Pass 2:  [ 11  12  13 | 5  6 ]
Pass 3:  [ 5  11  12  13 | 6 ]
Pass 4:  [ 5  6  11  12  13 ]
```

✔ The **bar ( | )** shows the boundary between **sorted** and **unsorted**.

**Optimizations**

* Efficient for **small arrays**.
* Useful as a **helper inside more complex sorts** (e.g., Quick Sort or Merge Sort) for small subarrays.
* Can be optimized with **binary search** to find insertion positions faster (but shifting still takes linear time).

**Stability**

Insertion sort is **stable** (equal elements keep their relative order).

**Complexity**

| Case             | Time Complexity | Notes                                             |
|------------------|-----------------|---------------------------------------------------|
| **Worst Case**   | $O(n^2)$        | Reverse-sorted input                              |
| **Average Case** | $O(n^2)$        |                                                   |
| **Best Case**    | $O(n)$          | Already sorted input — only comparisons, no shifts |
| **Space**        | $O(1)$          | In-place                                          |

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/insertion_sort/src/insertion_sort.py)

### Quick Sort

Quick Sort is a **divide-and-conquer** algorithm. Unlike bubble sort or selection sort, which work by repeatedly scanning the whole array, Quick Sort works by **partitioning** the array into smaller sections around a "pivot" element and then sorting those sections independently.

It is one of the **fastest sorting algorithms in practice**, widely used in libraries and systems.

The basic idea:

1. Choose a **pivot element** (commonly the last, first, middle, or random element).
2. Rearrange (partition) the array so that:
* All elements **smaller than the pivot** come before it.
* All elements **larger than the pivot** come after it.
3. The pivot is now in its **final sorted position**.
4. Recursively apply Quick Sort to the **left subarray** and **right subarray**.

**Example Run**

We will sort the array:

```
[ 10 ][ 80 ][ 30 ][ 90 ][ 40 ][ 50 ][ 70 ]
```

**Step 1: Choose Pivot (last element = 70)**

Partition around 70.

```
Initial:   [ 10 ][ 80 ][ 30 ][ 90 ][ 40 ][ 50 ][ 70 ]

→ Elements < 70: [ 10, 30, 40, 50 ]  
→ Pivot (70) goes here ↓
Sorted split:  [ 10 ][ 30 ][ 40 ][ 50 ][ 70 ][ 90 ][ 80 ]
```

*(ordering of right side may vary during partition; only pivot’s position is guaranteed)*

✔ Pivot (70) is in correct place.

**Step 2: Left Subarray [10, 30, 40, 50]**

Choose pivot = 50.

```
[ 10 ][ 30 ][ 40 ][ 50 ]   → pivot = 50

→ Elements < 50: [10, 30, 40]  
→ Pivot at correct place  

Result: [ 10 ][ 30 ][ 40 ][ 50 ]
```

✔ Pivot (50) fixed.

**Step 3: Left Subarray of Left [10, 30, 40]**

Choose pivot = 40.

```
[ 10 ][ 30 ][ 40 ]   → pivot = 40

→ Elements < 40: [10, 30]  
→ Pivot at correct place  

Result: [ 10 ][ 30 ][ 40 ]
```

✔ Pivot (40) fixed.

**Step 4: [10, 30]**

Choose pivot = 30.

```
[ 10 ][ 30 ]   → pivot = 30

→ Elements < 30: [10]  

Result: [ 10 ][ 30 ]
```

✔ Sorted.

**Final Result**

```
[ 10 ][ 30 ][ 40 ][ 50 ][ 70 ][ 80 ][ 90 ]
```

**Visual Partition Illustration**

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

✔ Each pivot splits the problem smaller and smaller until fully sorted.

**Optimizations**

* **Pivot Choice:** Choosing a good pivot (e.g., median or random) improves performance.
* **Small Subarrays:** For very small partitions, switch to Insertion Sort for efficiency.
* **Tail Recursion:** Can optimize recursion depth.

**Stability**

* Quick Sort is **not stable** by default (equal elements may be reordered).
* Stable versions exist, but require modifications.

**Complexity**

| Case             | Time Complexity | Notes                                                                 |
|------------------|-----------------|----------------------------------------------------------------------|
| **Worst Case**   | $O(n^2)$        | Poor pivot choices (e.g., always smallest/largest in sorted array)   |
| **Average Case** | $O(n \log n)$   | Expected performance, very fast in practice                          |
| **Best Case**    | $O(n \log n)$   | Balanced partitions                                                  |
| **Space**        | $O(\log n)$     | Due to recursion stack                                               |

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/quick_sort/src/quick_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/quick_sort/src/quick_sort.py)

### Heap sort

Heap Sort is a **comparison-based sorting algorithm** that uses a special data structure called a **binary heap**.
It is efficient, with guaranteed \$O(n \log n)\$ performance, and sorts **in-place** (no extra array needed).

The basic idea:

1. **Build a max heap** from the input array.
* In a max heap, every parent is greater than its children.
* This ensures the **largest element is at the root** (first index).
2. Swap the **root (largest element)** with the **last element** of the heap.
3. Reduce the heap size by 1 (ignore the last element, which is now in place).
4. **Heapify** (restore heap property).
5. Repeat until all elements are sorted.

**Example Run**

We will sort the array:

```
[ 4 ][ 10 ][ 3 ][ 5 ][ 1 ]
```

**Step 1: Build Max Heap**

Binary tree view:

```
        4
      /   \
    10     3
   /  \
  5    1
```

Heapify → Largest at top:

```
       10
      /   \
     5     3
    / \
   4   1

Array: [ 10 ][ 5 ][ 3 ][ 4 ][ 1 ]
```

**Step 2: Swap Root with Last**

Swap 10 ↔ 1 → largest (10) moves to correct final place.

```
[ 1 ][ 5 ][ 3 ][ 4 ][ 10 ]
```

Heapify the reduced heap \[1,5,3,4]:

```
       5
      / \
     4   3
    /
   1

Array: [ 5 ][ 4 ][ 3 ][ 1 ][ 10 ]
```

**Step 3: Swap Root with Last**

Swap 5 ↔ 1.

```
[ 1 ][ 4 ][ 3 ][ 5 ][ 10 ]
```

Heapify reduced heap \[1,4,3]:

```
       4
      / \
     1   3

Array: [ 4 ][ 1 ][ 3 ][ 5 ][ 10 ]
```

**Step 4: Swap Root with Last**

Swap 4 ↔ 3.

```
[ 3 ][ 1 ][ 4 ][ 5 ][ 10 ]
```

Heapify reduced heap \[3,1]:

```
       3
      /
     1

Array: [ 3 ][ 1 ][ 4 ][ 5 ][ 10 ]
```

**Step 5: Swap Root with Last**

Swap 3 ↔ 1.

```
[ 1 ][ 3 ][ 4 ][ 5 ][ 10 ]
```

✔ Sorted array achieved.

**Final Result**

```
[ 1 ][ 3 ][ 4 ][ 5 ][ 10 ]
```

**Visual Progress**

```
Initial:   [ 4  10  3  5  1 ]
Heapify:   [ 10  5  3  4  1 ]
Step 1:    [ 5  4  3  1 | 10 ]
Step 2:    [ 4  1  3 | 5  10 ]
Step 3:    [ 3  1 | 4  5  10 ]
Step 4:    [ 1 | 3  4  5  10 ]
Sorted:    [ 1  3  4  5  10 ]
```

✔ Each step places the largest element into its correct final position.

**Optimizations**

* Building the heap can be done in **O(n)** time using bottom-up heapify.
* After building, each extract-max + heapify takes **O(log n)**.

**Stability**

Heap sort is **not stable**. Equal elements may not preserve their original order because of swaps.

**Complexity**

| Case             | Time Complexity | Notes                          |
|------------------|-----------------|--------------------------------|
| **Worst Case**   | $O(n \log n)$   |                                |
| **Average Case** | $O(n \log n)$   |                                |
| **Best Case**    | $O(n \log n)$   | No early exit possible         |
| **Space**        | $O(1)$          | In-place                       |

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/heap_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/heap_sort.py)

### Radix Sort

Radix Sort is a **non-comparison-based sorting algorithm**.
Instead of comparing elements directly, it processes numbers digit by digit, from either the **least significant digit (LSD)** or the **most significant digit (MSD)**, using a stable intermediate sorting algorithm (commonly **Counting Sort**).

Because it avoids comparisons, Radix Sort can achieve **linear time complexity** in many cases.

The basic idea:

1. Pick a **digit position** (units, tens, hundreds, etc.).
2. Sort the array by that digit using a **stable sorting algorithm**.
3. Move to the next digit.
4. Repeat until all digits are processed.

**Example Run (LSD Radix Sort)**

We will sort the array:

```
[ 170 ][ 45 ][ 75 ][ 90 ][ 802 ][ 24 ][ 2 ][ 66 ]
```

**Step 1: Sort by 1s place (units digit)**

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

**Step 2: Sort by 10s place**

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

**Step 3: Sort by 100s place**

```
[802][2][24][45][66][170][75][90]

By 100s digit:
[2][24][45][66][75][90]  (0)
[170]                   (1)
[802]                   (8)

Result: [2][24][45][66][75][90][170][802]
```

**Final Result**

```
[ 2 ][ 24 ][ 45 ][ 66 ][ 75 ][ 90 ][ 170 ][ 802 ]
```

**Visual Process**

```
Step 1 (1s):   [170  90  802  2  24  45  75  66]
Step 2 (10s):  [802  2  24  45  66  170  75  90]
Step 3 (100s): [2  24  45  66  75  90  170  802]
```

✔ Each pass groups by digit → final sorted order.
 
**LSD vs MSD**

* **LSD (Least Significant Digit first):** Process digits from right (units) to left (hundreds). Most common, simpler.
* **MSD (Most Significant Digit first):** Process from left to right, useful for variable-length data like strings.

**Stability**

* Radix Sort **is stable**, because it relies on a stable intermediate sort (like Counting Sort).
* Equal elements remain in the same order across passes.

**Complexity**

* **Time Complexity:** \$O(n \cdot k)\$

  * \$n\$ = number of elements
  * \$k\$ = number of digits (or max digit length)

* **Space Complexity:** \$O(n + k)\$ (depends on the stable sorting method used, e.g., Counting Sort).

* For integers with fixed number of digits, Radix Sort can be considered **linear time**.

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/radix_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/radix_sort.py)

### Counting Sort

Counting Sort is a **non-comparison-based sorting algorithm** that works by **counting occurrences** of each distinct element and then calculating their positions in the output array.

It is especially efficient when:

* The input values are integers.
* The **range of values (k)** is not significantly larger than the number of elements (n).

The basic idea:

1. Find the **range** of the input (min to max).
2. Create a **count array** to store the frequency of each number.
3. Modify the count array to store **prefix sums** (cumulative counts).
* This gives the final position of each element.
4. Place elements into the output array in order, using the count array.

**Example Run**

We will sort the array:

```
[ 4 ][ 2 ][ 2 ][ 8 ][ 3 ][ 3 ][ 1 ]
```

**Step 1: Count Frequencies**

```
Elements:  1  2  3  4  5  6  7  8
Counts:    1  2  2  1  0  0  0  1
```

**Step 2: Prefix Sums**

```
Elements:  1  2  3  4  5  6  7  8
Counts:    1  3  5  6  6  6  6  7
```

✔ Now each number tells us the **last index position** where that value should go.

**Step 3: Place Elements**

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

**Final Result**

```
[ 1 ][ 2 ][ 2 ][ 3 ][ 3 ][ 4 ][ 8 ]
```

**Visual Process**

```
Step 1 Count:   [0,1,2,2,1,0,0,0,1]
Step 2 Prefix:  [0,1,3,5,6,6,6,6,7]
Step 3 Output:  [1,2,2,3,3,4,8]
```

✔ Linear-time sorting by counting positions.

**Stability**

Counting Sort is **stable** if we place elements **from right to left** into the output array.

**Complexity**

| Case             | Time Complexity | Notes                                    |
|------------------|-----------------|------------------------------------------|
| **Overall**      | $O(n + k)$      | $n$ = number of elements, $k$ = value range |
| **Space**        | $O(n + k)$      | Extra array for counts + output          |

**Implementation**

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/counting_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/counting_sort.py)

### Comparison Table

Below is a consolidated **side-by-side comparison** of all the sorts we’ve covered so far:

| Algorithm      | Best Case  | Average     | Worst Case  | Space       | Stable? | Notes                  |
|----------------|------------|-------------|-------------|-------------|---------|------------------------|
| **Bubble Sort**    | O(n)       | O(n²)       | O(n²)       | O(1)        | Yes     | Simple, slow           |
| **Selection Sort** | O(n²)      | O(n²)       | O(n²)       | O(1)        | No      | Few swaps              |
| **Insertion Sort** | O(n)       | O(n²)       | O(n²)       | O(1)        | Yes     | Good for small inputs  |
| **Quick Sort**     | O(n log n) | O(n log n)  | O(n²)       | O(log n)    | No      | Very fast in practice  |
| **Heap Sort**      | O(n log n) | O(n log n)  | O(n log n)  | O(1)        | No      | Guaranteed performance |
| **Counting Sort**  | O(n + k)   | O(n + k)    | O(n + k)    | O(n + k)    | Yes     | Integers only          |
| **Radix Sort**     | O(nk)      | O(nk)       | O(nk)       | O(n + k)    | Yes     | Uses Counting Sort     |
