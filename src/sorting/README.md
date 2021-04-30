# Sorting

<h2>Heap sort</h2>
It provides random access to iterators.
It has an O(nlogn) time complexity.
Since it is inplace sorting, the memory complexity is O(1).
It's an unstable sort.
In order for sorting to work, the '<' operator must be defined.

Sorting procedure consists of a  few binary heap operations.
* The inputted array is first max-heapifi
* The heap is then deconstructed by several deletions from the end.
* Finally, we will have a non-decreasing sorted array.

<h2>Merge sort</h2>
In it's current implementation it's an unstable sort.
The function's interface can support iterators with random access.

