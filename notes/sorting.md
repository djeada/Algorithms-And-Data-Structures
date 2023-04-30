## Sorting

In computer science, 'sorting' means arranging a collection of items in a specific order. We need to define an order for the items we want to sort. For numbers, we use the standard numerical order. For strings, we use the alphabetic order, like in dictionaries. Sorting can be applied to any type of object if the order is defined for them.

### Stability
Stability means that if two items are the same, they stay in the same order even after sorting. A stable sorting method doesn't mix up the order of equal items.

## Bubble Sort
Bubble sort is easy to understand and implement. It is often used to teach sorting algorithms. The main idea is to go over the array with n elements n times. In each pass, we compare each element with its neighbor and swap them if they are not in order. Larger elements "bubble up" towards the end of the array. After n iterations, the array will be sorted.

### Steps

1. Compare the first item with its neighbor.
1. Swap the items if they are not in the correct order.
1. Repeat steps 1-2 until you reach the end of the array, moving one item to the right each time.
1. Repeat step 1-3 n times.

### Optimizations
If the array is sorted before the nth iteration, we can stop the algorithm early.

### Stability
Bubble sort is stable because items with the same value keep their original order.

### Time complexity

* Worst case complexity: $O(n^2)$
* Average case complexity: $O(n^2)$

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/bubble_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/bubble_sort.py)

## Selection Sort
The idea is to find the smallest item and put it at the beginning of the array. Then, find the smallest remaining item and place it second. Repeat this process until the largest item is at the end of the array. Selection sort needs at most n-1 swaps.

### Steps

1. Look at elements from 0 to n-1. Find the smallest element's position and swap it with `arr[0]`.
1. Look at elements from 1 to n-1. Find the smallest element's position and swap it with `arr[1]`.
1. Repeat these steps, reducing the number of examined indices by one and increasing the position of the swapped element by one each time.

### Stability
Selection sort is not stable because items with the same value can be swapped, changing their original order.

### Time complexity

* Worst case complexity: $O(n^2)$
* Average case complexity: $O(n^2)$

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/selection_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/selection_sort.py)

## Insertion Sort
Insertion sort works by inserting items from the unsorted part of the array into the sorted part in their proper position. The sorted part grows by one item each iteration, and the unsorted part shrinks by one item. This process is repeated n times.

### Steps

1. Leave the first entry of the array untouched `arr[0]`.
1. Compare the second entry `arr[1]` with the first one `arr[0]` and swap them if they are not in order.
1. Compare the third entry `arr[2]` with the second one `arr[0]` and swap them if they are not in order.
1. Repeat the process until you reach the last element of the array.

### Stability
Insertion sort is stable because items with the same value keep their original order.

### Time complexity

* Worst case complexity: $O(n^2)$
* Average case complexity: $O(n^2)$

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/insertion_sort/src/insertion_sort.py)
github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp)

## Quick Sort
Quick sort divides the original array into two parts based on a selected value called the pivot. The first part has items smaller than the pivot, and the second part has items larger than or equal to the pivot. The partitioning process is repeated for each subgroup until all items are sorted.

### Steps

1. Choose the pivot element.
1. Divide the array into two parts. The first part contains items smaller than the pivot, and the second contains items larger than the pivot.
1. Repeat the steps for each subarray until you reach single element arrays.

### Choosing the pivot

We should avoid dividing the array in such a way that one of the resulting sub-arrays remains empty or has the same length as the original array. Options for choosing the pivot:

* Pick an index k using a random number generator and then use `arr[k]`.
* Select a key from the middle of the array, which is `arr[(n-1)/2]`.
* Take a small sample (e.g., three or five items) and select the middle key from those.

### Stability
Quick sort is stable only if the partitioning ensures that the order of identical items can never be reversed.

### Time complexity

* Worst case complexity: $O(n^2)$
* Average case complexity: $O(nlogn)$

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/quick_sort/src/quick_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/quick_sort/src/quick_sort.py)

## Heap sort
Heap sort sorts the array in place, meaning it uses very little extra memory. It is not a stable sorting algorithm.

### Steps

1. The original array is first max-heapified.
1. The heap is then deconstructed by several deletions from the end.
1. Deleted items will be used to create a sorted version of the original array.

### Stability
Heap sort is not a stable algorithm.

### Time complexity

* Worst case complexity: $O(nlogn)$
* Average case complexity: $O(nlogn)$

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/heap_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/heap_sort.py)
