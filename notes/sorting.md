# Sorting

## The problem of sorting
In computer science,'sorting' generally refers to arranging a collection of items in a specific order. To do so, we must first define the idea of order on the things under consideration. For numbers, for example, we can use the standard numerical order (defined by the mathematical 'less than' or " relation) and for strings, we can use the so-called lexicographic or alphabetic order, which is used by dictionaries and encyclopedias. Sorting may be applied to any arbitrary category of objects if the order is defined for them.

## Bubble Sort
The bubble sort is the simplest to grasp and implement, therefore it is usually used to introduce the students to sorting algorithms. The main idea behind bubble sort is to go over the n-element array n times. In each pass, we check each element in the array with its neighbor, i.e., <code>arr[i]</code> with <code>arr[i+1]</code> and swap two elements if they are not in order. This way the larger elements will "bubble up" towards the end of the array. In the first iteration we are guaranteed to have the largest element at the end of array. Therefore, n iterations will always result in a sorted array.

### Steps

1. Compare the first item with its neighbor.
1. Swap the items if they are not in the correct order.
1. Repeat steps 1-2 until you reach the end of the array, moving by one item to the right each time.
1. Repeat step 1-3 n times.

### Optimizations
It is possible that the array will be sorted before the nth iteration. In that case, we simply stop the algorithm.

### Stability
It is a stable algorithm since no item gets switched ahead of another unless they are in the incorrect order. As a result, objects with identical keys will retain their original arrangement.

### Time complexity

* Worst case complexity: <code>O(n^2)</code>
* Average case complexity: <code>O(n^2)</code>

### Implementation

* <a href="">C++</a>
* <a href="">Python</a>

## Selection Sort
The basic idea is to locate the smallest item and place it at the beginning of the array, then find the smallest of the remaining items and place it second, and so on. The algorithm will just repeat this operation until the largest member is placed at the end of the array. There will be no more than n-1 swaps required for selection sort.

### Steps

1. Consider the elements from 0 till n-1. Find the smallest element's position and swap it with <code>arr[0]</code>.
1. Consider the elements from 1 till n-1. Find the smallest element's position and swap it with <code>arr[1]</code>.
1. Repeat these steps, reducing the number of examined indices by one and increasing the position of the swapped element by one each time.

### Stability
It is not a stable algorithm since there is nothing to prevent an item from being switched past another item with the same key. For example, the array <code>[5_0, 5_1, 2_2]</code> would be sorted to <code>[2_2, 5_1, 5_0]</code>, which has the values <code>2_2</code> and <code>2_1</code> out of order.

### Time complexity

* Worst case complexity: <code>O(n^2)</code>
* Average case complexity: <code>O(n^2)</code>

### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/selection_sort.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/selection_sort.py">Python</a>

## Insertion Sort
Insertion sort works by directly inserting items from the unsorted part of the array into the sorted one at their proper position. The sorted part maintains its order and grows by one item with each iteration, whereas the unsorted part shrinks by one item. Again there are n iterations.

### Steps

1. Leave the first entry of the array untouched <code>arr[0]</code>.
1. Compare the second entry <code>arr[1]</code> with the first one <code>arr[0]</code> and swap them if they are not in order.
1. Compare the third entry <code>arr[2]</code> with the second one <code>arr[0]</code> and swap them if they are not in order.
1. Repeat the process until you reach the last element of the array.

### Stability
It is a stable algorithm because no item gets swapped past another unless it has a smaller key. As a result, items with identical keys will retain their original arrangement.

### Time complexity

* Worst case complexity: <code>O(n^2)</code>
* Average case complexity: <code>O(n^2)</code>

### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/insertion_sort/src/insertion_sort.py">Python</a>

## Merge sort

Recursively divide the problem into smaller sub-problems until you just have single items that are straightforward to sort. Then merge the sorted items.  In it's current implementation it's an unstable sort.

### Steps

1. Recursively divide the array into n subarrays each containing a single element.
1. Merge every pair of subarrays arrays into a single sorted array.
1. Repeat the second step until there is only one array left.

### Stability
It is a stable algorithm.

### Time complexity

* Worst case complexity: <code>O(nlogn)</code>
* Average case complexity: <code>O(nlogn)</code>

### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/merge_sort/src/merge_sort.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/merge_sort/src/merge_sort.py">Python</a>

## Quick Sort
The quick sort method divides the original array into two parts by rearranging it. The first part comprises items that are smaller than an arbitrarily selected value from the original array, whereas the second group contains elements that are larger than or equal to the selected value. The selected value is referred to as the pivot element. After the array has been reorganized with regard to the pivot, the same partitioning method is done recursively to each of the two subgroups. The original array is sorted after all of the subsets have been partitioned and reorganized.

### Steps

1. Choose the pivot element.
1. Divide the array into two halves. The first part contains all components that are smaller than the pivot, while the second contains all elements that are larger than the pivot.
1. Repeat the steps for each subarray until you reach single element arrays.

### Choosing the pivot

The crucial concern is how to split as effectively as possible. We must certainly avoid splitting the array into an empty sub-array and the whole array again.  If we do this, the algorithm will not only perform poorly, but it will also not terminate.

We have the following options:

* Pick an index k using a random number generator and then use <code>arr[k]</code>.
* Select a key from the array's middle, which is <code>arr[(n-1)/2]</code>.
* Take a small sample (e.g., three or five items) and select the middle key from those.

### Stability
The partitioning determines the stability. Quick sort is only stable if the partitioning is done so that the order of identical items can never be reversed.

### Time complexity

* Worst case complexity: <code>O(n^2)</code>
* Average case complexity: <code>O(nlogn)</code>

### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/quick_sort/src/quick_sort.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/quick_sort/src/quick_sort.py">Python</a>

## Heap sort
It provides random access to iterators.
Since it is inplace sorting, the memory complexity is O(1).
It's an unstable sort.
In order for sorting to work, the '<' operator must be defined.

### Steps

1. The original array is first max-heapified.
1. The heap is then deconstructed by several deletions from the end.
1. Deleted items will be used to create a sorted version of the original array.

### Stability
It is not a stable algorithm.

### Time complexity

* Worst case complexity: <code>O(nlogn)</code>
* Average case complexity: <code>O(nlogn)</code>

### Implementation

* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/heap_sort.cpp">C++</a>
* <a href="https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/heap_sort.py">Python</a>
