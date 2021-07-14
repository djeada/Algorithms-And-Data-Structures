# Sorting

<h2>Bubble Sort</h2>
The bubble sort is simple to grasp and implement. The main idea behind bubble sort is to go over the file multiple times in a row. In each pass, we check each element in the file with its successor, i.e., X[i] with X[i+1], and swap two elements if they are not in the correct sequence.

The bigger elements will "bubble up" towards the end of the array.

Time complexity
O(n^2)

<h2>Selection Sort</h2>
There will be no more than n-1 interchanges required for selection sort. Assume x is a memory-stored array of size n. The selection sort algorithm chooses the smallest element in the array x and places it at array position 0; it then chooses the next smallest element in the array x and places it at array position 1. It just repeats this operation until the largest member is placed at the end of the array. The array is traversed (n-1) times, and the smallest member is placed in its appropriate position in the array, as seen below:

* Find the smallest element's position and replace it with arr[0].
* Remove the first element and locate the smallest element in the subarray beginning with arr[1] and swap it with xarr[1].
* Repeat these steps for the rest of the array.

Time complexity
O(n^2)

<h2>Quick Sort</h2>
The quick sort method divides the original array into two groups by rearranging it. The first group comprises items that are less than an arbitrarily selected value from the set, whereas the second group contains elements that are larger than or equal to the chosen value. The chosen value is referred to as the pivot element. After the array has been reorganized with regard to the pivot, the same partitioning method is done recursively to each of the two subgroups. The original array is sorted after all of the subsets have been partitioned and reorganized.

Time complexity
O(n log n)

<h2>Heap sort</h2>
It provides random access to iterators.
Since it is inplace sorting, the memory complexity is O(1).
It's an unstable sort.
In order for sorting to work, the '<' operator must be defined.

Sorting procedure consists of a  few binary heap operations.
* The inputted array is first max-heapifi
* The heap is then deconstructed by several deletions from the end.
* Finally, we will have a non-decreasing sorted array.

Time complexity
O(n log n)

<h2>Merge sort</h2>
In it's current implementation it's an unstable sort.
The function's interface can support iterators with random access.

Time complexity
O(n log n)
