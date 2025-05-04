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

Bubble sort, one of the simplest sorting algorithms, is often a go-to choice for teaching the foundational concepts of sorting due to its intuitive nature. The name "bubble sort" stems from the way larger elements "bubble up" towards the end of the array, much like how bubbles rise in a liquid.

#### Conceptual Overview

Imagine a sequence of numbers. Starting from the beginning of the sequence, we compare each pair of adjacent numbers and swap them if they are out of order. As a result, at the end of the first pass, the largest number will have "bubbled up" to the last position. Each subsequent pass ensures that the next largest number finds its correct position, and this continues until the whole array is sorted.

#### Steps

1. Start from the first item and compare it with its neighbor to the right.
2. If the items are out of order (i.e., the left item is greater than the right), swap them.
3. Move to the next item and repeat the above steps until the end of the array.
4. After the first pass, the largest item will be at the last position. On the next pass, you can ignore the last item and consider the rest of the array.
5. Continue this process for `n-1` passes to ensure the array is completely sorted.

```
Start:  [ 5 ][ 1 ][ 4 ][ 2 ][ 8 ]

Pass 1:
  [ 5 ][ 1 ][ 4 ][ 2 ][ 8 ]  → swap(5,1) →  [ 1 ][ 5 ][ 4 ][ 2 ][ 8 ]
  [ 1 ][ 5 ][ 4 ][ 2 ][ 8 ]  → swap(5,4) →  [ 1 ][ 4 ][ 5 ][ 2 ][ 8 ]
  [ 1 ][ 4 ][ 5 ][ 2 ][ 8 ]  → swap(5,2) →  [ 1 ][ 4 ][ 2 ][ 5 ][ 8 ]
  [ 1 ][ 4 ][ 2 ][ 5 ][ 8 ]  →      no swap      → [ 1 ][ 4 ][ 2 ][ 5 ][ 8 ]

Pass 2:
  [ 1 ][ 4 ][ 2 ][ 5 ] [8]  →      no swap      → [ 1 ][ 4 ][ 2 ][ 5 ] [8]
  [ 1 ][ 4 ][ 2 ][ 5 ] [8]  → swap(4,2) →  [ 1 ][ 2 ][ 4 ][ 5 ] [8]
  [ 1 ][ 2 ][ 4 ][ 5 ] [8]  →      no swap      → [ 1 ][ 2 ][ 4 ][ 5 ] [8]

Pass 3:
  [ 1 ][ 2 ][ 4 ] [5,8]  → all comparisons OK

Result: [ 1 ][ 2 ][ 4 ][ 5 ][ 8 ]
```

#### Optimizations

An important optimization for bubble sort is to keep track of whether any swaps were made during a pass. If a pass completes without any swaps, it means the array is already sorted, and there's no need to continue further iterations.

#### Stability

Bubble sort is stable. This means that two objects with equal keys will retain their relative order after sorting. Thus, if you had records sorted by name and then sorted them using bubble sort based on age, records with the same age would still maintain the name order.

#### Time Complexity

- In the **worst-case** scenario, the time complexity of bubble sort is $O(n^2)$, which occurs when the array is in reverse order.
- The **average-case** time complexity is also $O(n^2)$, as bubble sort generally requires quadratic time for typical unsorted arrays.
- In the **best-case** scenario, the time complexity is $O(n)$, which happens when the array is already sorted, especially if an optimization like early exit is implemented.

#### Space Complexity

$(O(1))$ - It sorts in place, so it doesn't require any additional memory beyond the input array.

### Selection Sort

Selection sort is another intuitive algorithm, widely taught in computer science curricula due to its straightforward mechanism. The crux of selection sort lies in repeatedly selecting the smallest (or largest, depending on the desired order) element from the unsorted section of the array and swapping it with the first unsorted element.

#### Conceptual Overview

Consider an array of numbers. The algorithm divides the array into two parts: a sorted subarray and an unsorted subarray. Initially, the sorted subarray is empty, while the entire array is unsorted. During each pass, the smallest element from the unsorted subarray is identified and then swapped with the first unsorted element. As a result, the sorted subarray grows by one element after each pass.

#### Steps

1. Assume the first element is the smallest.
2. Traverse the unsorted subarray and find the smallest element.
3. Swap the found smallest element with the first element of the unsorted subarray.
4. Move the boundary of the sorted and unsorted subarrays one element to the right.
5. Repeat steps 1-4 until the entire array is sorted.

```
Start:
[ 64 ][ 25 ][ 12 ][ 22 ][ 11 ]

Pass 1: find min(64,25,12,22,11)=11, swap with first element
[ 11 ][ 25 ][ 12 ][ 22 ][ 64 ]

Pass 2: find min(25,12,22,64)=12, swap with second element
[ 11 ][ 12 ][ 25 ][ 22 ][ 64 ]

Pass 3: find min(25,22,64)=22, swap with third element
[ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]

Pass 4: find min(25,64)=25, swap with fourth element (self-swap)
[ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]

Pass 5: only one element remains, already in place
[ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]

Result:
[ 11 ][ 12 ][ 22 ][ 25 ][ 64 ]
```

#### Stability

Selection sort is inherently unstable. When two elements have equal keys, their relative order might change post-sorting. This can be problematic in scenarios where stability is crucial.

#### Time Complexity

- In the **worst-case**, the time complexity is $O(n^2)$, as even if the array is already sorted, the algorithm still iterates through every element to find the smallest.
- The **average-case** time complexity is also $O(n^2)$, since the algorithm's performance generally remains quadratic regardless of input arrangement.
- In the **best-case**, the time complexity is still $O(n^2)$, unlike other algorithms, because selection sort always performs the same number of comparisons, regardless of the input's initial order.

#### Space Complexity

$(O(1))$ - The algorithm sorts in-place, meaning it doesn't use any extra space beyond what's needed for the input.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/selection_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/selection_sort.py)

### Insertion Sort

Insertion sort works much like how one might sort a hand of playing cards. It builds a sorted array (or list) one element at a time by repeatedly taking one element from the input and inserting it into the correct position in the already-sorted section of the array. Its simplicity makes it a common choice for teaching the basics of algorithm design.

#### Conceptual Overview

Imagine you have a series of numbers. The algorithm begins with the second element (assuming the first element on its own is already sorted) and inserts it into the correct position relative to the first. With each subsequent iteration, the algorithm takes the next unsorted element and scans through the sorted subarray, finding the appropriate position to insert the new element.

#### Steps

1. Start at the second element (index 1) assuming the element at index 0 is sorted.
2. Compare the current element with the previous elements.
3. If the current element is smaller than the previous element, compare it with the elements before until you reach an element smaller or until you reach the start of the array. 
4. Insert the current element into the correct position so that the elements before are all smaller.
5. Repeat steps 2-4 for each element in the array.

```
Start:
[ 12 ][ 11 ][ 13 ][  5 ][  6 ]

Pass 1: key = 11, insert into [12]
[ 11 ][ 12 ][ 13 ][  5 ][  6 ]

Pass 2: key = 13, stays in place
[ 11 ][ 12 ][ 13 ][  5 ][  6 ]

Pass 3: key =  5, insert into [11,12,13]
[  5 ][ 11 ][ 12 ][ 13 ][  6 ]

Pass 4: key =  6, insert into [5,11,12,13]
[  5 ][  6 ][ 11 ][ 12 ][ 13 ]

Result:
[  5 ][  6 ][ 11 ][ 12 ][ 13 ]
```

#### Stability

Insertion sort is stable. When two elements have equal keys, their relative order remains unchanged post-sorting. This stability is preserved since the algorithm only swaps elements if they are out of order, ensuring that equal elements never overtake each other.

#### Time Complexity

- In the **worst-case**, the time complexity is $O(n^2)$, which happens when the array is in reverse order, requiring every element to be compared with every other element.
- The **average-case** time complexity is $O(n^2)$, as elements generally need to be compared with others, leading to quadratic performance.
- In the **best-case**, the time complexity is $O(n)$, occurring when the array is already sorted, allowing the algorithm to simply pass through the array once without making any swaps.

#### Space Complexity

$(O(1))$ - This in-place sorting algorithm doesn't need any additional storage beyond the input array.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/insertion_sort/src/insertion_sort.py)

### Quick Sort

Quick Sort, often simply referred to as "quicksort", is a divide-and-conquer algorithm that's renowned for its efficiency and is widely used in practice. Its name stems from its ability to sort large datasets quickly. The core idea behind quicksort is selecting a 'pivot' element and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The process is then recursively applied to the sub-arrays.

#### Conceptual Overview

1. The first step is to **choose a pivot** from the array, which is the element used to partition the array. The pivot selection method can vary, such as picking the first element, the middle element, a random element, or using a more advanced approach like the median-of-three.
2. During **partitioning**, the elements in the array are rearranged so that all elements less than or equal to the pivot are placed before it, and all elements greater than the pivot are placed after it. At this point, the pivot reaches its final sorted position.
3. Finally, **recursion** is applied by repeating the same process for the two sub-arrays: one containing elements less than the pivot and the other containing elements greater than the pivot.

#### Steps

1. Choose a 'pivot' from the array.
2. Partition the array around the pivot, ensuring all elements on the left are less than the pivot and all elements on the right are greater than it.
3. Recursively apply steps 1 and 2 to the left and right partitions.
4. Repeat until base case: the partition has only one or zero elements.


```
Start:
[ 10 ][ 7 ][ 8 ][ 9 ][ 1 ][ 5 ]

Partition around pivot = 5:
  • Compare and swap ↓
    [  1 ][ 7 ][ 8 ][ 9 ][ 10 ][ 5 ]
  • Place pivot in correct spot ↓
    [  1 ][ 5 ][ 8 ][ 9 ][ 10 ][ 7 ]

Recurse on left [1]  → already sorted  
Recurse on right [8, 9, 10, 7]:

  Partition around pivot = 7:
    [  7 ][ 9 ][ 10 ][ 8 ]
  Recurse left []       → []
  Recurse right [9, 10, 8]:

    Partition around pivot = 8:
      [  8 ][ 10 ][ 9 ]
    Recurse left []     → []
    Recurse right [10, 9]:
      Partition pivot = 9:
        [  9 ][ 10 ]
      → both sides sorted

    → merge [8] + [9, 10] → [  8 ][  9 ][ 10 ]

  → merge [7] + [8, 9, 10] → [  7 ][  8 ][  9 ][ 10 ]

→ merge [1, 5] + [7, 8, 9, 10] → [  1 ][  5 ][  7 ][  8 ][  9 ][ 10 ]

Result:
[  1 ][  5 ][  7 ][  8 ][  9 ][ 10 ]
```

#### Stability

Quick sort is inherently unstable due to the long-distance exchanges of values. However, with specific modifications, it can be made stable, although this is not commonly done.

#### Time Complexity

- In the **worst-case**, the time complexity is $O(n^2)$, which can occur when the pivot is the smallest or largest element, resulting in highly unbalanced partitions. However, with effective pivot selection strategies, this scenario is rare in practice.
- The **average-case** time complexity is $O(n \log n)$, which is expected when using a good pivot selection method that balances the partitions reasonably well.
- In the **best-case**, the time complexity is also $O(n \log n)$, occurring when each pivot divides the array into two roughly equal-sized parts, leading to optimal partitioning.

#### Space Complexity

$(O(\log n))$ - Though quicksort sorts in place, it requires stack space for recursion, which in the best case is logarithmic.

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/quick_sort/src/quick_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/quick_sort/src/quick_sort.py)

### Heap sort

Heap Sort is a comparison-based sorting technique performed on a binary heap data structure. It leverages the properties of a heap to efficiently sort a dataset. The essential idea is to build a heap from the input data, then continuously extract the maximum element from the heap and reconstruct the heap until it's empty. The result is a sorted list.

#### Conceptual Overview

1. The first step is to **build a max heap**, which involves transforming the list into a max heap (a complete binary tree where each node is greater than or equal to its children). This is typically achieved using a bottom-up approach to ensure the heap property is satisfied. *(Building the heap with Floyd’s bottom-up procedure costs Θ(*n*) time—lower than Θ(*n log n*)—so it never dominates the overall running time.)*

2. During **sorting**, the maximum element (the root of the heap) is swapped with the last element of the unsorted portion of the array, placing the largest element in its final position. **After each swap, the newly “fixed” maximum stays at the end of the *same* array; the active heap is simply the prefix that remains unsorted.** The heap size is then reduced by one, and the unsorted portion is restructured into a max heap. This process continues until the heap size is reduced to one, completing the sort.

#### Steps

1. Construct a max heap from the given data. This will place the largest element at the root.
2. Swap the root (maximum value) with the last element of the heap. This element is now considered sorted.
3. Decrease the heap size by one (to exclude the sorted elements).
4. "Heapify" the root of the tree, i.e., ensure the heap property is maintained.
5. Repeat steps 2-4 until the size of the heap is one.

```
Initial array (size n = 5)                     index: 0 1 2 3 4
        4                                        [4,10,3,5,1]
      /   \
    10     3
   /  \
  5    1

↓ BUILD MAX-HEAP  (Θ(n))  —> heapSize = 5
        10                                       [10,5,3,4,1]
      /    \
     5      3
    / \
   4   1
```

**Pass 1 extract-max**

```
swap 10 ↔ 1                               [1,5,3,4 | 10]   heapSize = 4
                                           ↑ live heap ↑  ↑fixed↑
heapify (1↔5, 1↔4)  →                      [5,4,3,1 | 10]

        5
      /   \
     4     3
    /
   1
```

**Pass 2 extract-max**

```
swap 5 ↔ 1                                [1,4,3 | 5,10]   heapSize = 3
heapify (1↔4)      →                      [4,1,3 | 5,10]

        4
      /   \
     1     3
```

**Pass 3 extract-max**

```
swap 4 ↔ 3                                [3,1 | 4,5,10]   heapSize = 2
(no heapify needed – root already ≥ child)

        3
       /
      1
```

**Pass 4 extract-max**

```
swap 3 ↔ 1                                [1 | 3,4,5,10]   heapSize = 1
(heap of size 1 is trivially a heap)
```

**Pass 5 extract-max**

```
Done – heapSize = 0
Sorted array:                              [1,3,4,5,10]
```

#### Stability

Heap sort is inherently unstable. Similar to quicksort, the relative order of equal items is not preserved because of the long-distance exchanges.

#### Time Complexity

- In the **worst-case**, the time complexity is $O(n \log n)$, regardless of the arrangement of the input data.
- The **average-case** time complexity is also $O(n \log n)$, as the algorithm's structure ensures consistent performance.
- In the **best-case**, the time complexity remains $O(n \log n)$, since building and deconstructing the heap is still necessary, even if the input is already partially sorted.

#### Space Complexity

$O(1)$ – The sorting is done in-place, requiring only a constant amount of auxiliary space. **This assumes an *iterative* `siftDown/heapify`; a recursive version would add an \$O(\log n)\$ call stack.**

#### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/heap_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/heap_sort.py)
