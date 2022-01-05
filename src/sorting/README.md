# Sorting

<h1>The problem of sorting</h1>
In computer science,'sorting' generally refers to arranging a collection of items in a specific order. To do so, we must first define the idea of order on the things under consideration. For numbers, for example, we can use the standard numerical order (defined by the mathematical 'less than' or " relation) and for strings, we can use the so-called lexicographic or alphabetic order, which is used by dictionaries and encyclopedias. Sorting may be applied to any arbitrary category of objects if the order is defined for them.

<h1>Bubble Sort</h1>
The bubble sort is the simplest to grasp and implement, therefore it is usally used to introduce the students to sorting algorithms. The main idea behind bubble sort is to go over the n-element array n times. In each pass, we check each element in the array with its neighbour, i.e., <code>arr[i]</code> with <code>arr[i+1]</code> and swap two elements if they are not in order. This way the larger elements will "bubble up" towards the end of the array. In the first iteration we are guaranteed to have the largest element at the end of array. Therefore, n iterations will always result in a sorted array.

<h2>Steps</h2>

*

<h2>Optimizations</h2>
It is possible that the array will be sorted before the n'th iteration. In that case, we simply stop the algorithm.

<h2>Time complexity</h2>
<code>O(n^2)</code>

<h1>Selection Sort</h1>
The basic idea is to locate the smallest item and place it at the beginning of the array, then find the smallest of the remaining items and place it second, and so on. The algorithm will just repeat this operation until the largest member is placed at the end of the array. There will be no more than n-1 swaps required for selection sort.

<h2>Steps</h1>

* Consider the elements from 0 till n-1. Find the smallest element's position and swap it with <code>arr[0]</code>.
* Consider the elements from 1 till n-1. Find the smallest element's position and swap it with <code>arr[1]</code>.
* Repeat these steps, reducing the number of examined indices by one and increasing the position of the swapped element by one each time.

<h2>Time complexity</h2>
<code>O(n^2)</code>

<h1>Insertion Sort</h1>
Insertion sort works by directly inserting items from the unsorted part of the array into the sorted one at their proper position. The sorted part maintains its order and grows by one item with each iteration, whereas the unsorted part shrinks by one item. Again there are n iterations.

<h2>Steps</h2>

* Leave the first entry of the array untouched <code>arr[0]</code>.
* Compare the second entry <code>arr[1]</code> with the first one <code>arr[0]</code> and swap them if they are not in order.
* Compare the third entry <code>arr[2]</code> with the second one <code>arr[0]</code> and swap them if they are not in order.
* Repeat the process until you reach the last element of the array.

<h2>Time complexity</h2>
<code>O(n^2)</code>

<h1>Merge sort</h1>

Recursively divide the problem into smaller sub-problems until you just have single items that are straightforward to sort. Then merge the sorted items.  In it's current implementation it's an unstable sort.

<h2>Steps</h2>

* Recursively divide the array into n subarrays each containing a single element.
* Merge every pair of subarrays arrays into a single sorted array.
* Repeat the second step until theire is only one array left.

<h2>Time complexity</h2>
<code>O(nlogn)</code>

<h1>Quick Sort</h1>
The quick sort method divides the original array into two parts by rearranging it. The first part comprises items that are smaller than an arbitrarily selected value from the original array, whereas the second group contains elements that are larger than or equal to the selcted value. The selected value is referred to as the pivot element. After the array has been reorganized with regard to the pivot, the same partitioning method is done recursively to each of the two subgroups. The original array is sorted after all of the subsets have been partitioned and reorganized.

<h2>Steps</h2>

* Choose the pivot element.
* Divide the array into two halves. The first part contains all components that are smaller than the pivot, while the second contains all elements that are larger than the pivot.
* Repeat for each subarray until you reach single element arrays.

<h2>Time complexity</h2>
<code>O(nlogn)</code>

<h1>Heap sort</h1>
It provides random access to iterators.
Since it is inplace sorting, the memory complexity is O(1).
It's an unstable sort.
In order for sorting to work, the '<' operator must be defined.

<h2>Steps</h2>

* The inputted array is first max-heapifi
* The heap is then deconstructed by several deletions from the end.
* Finally, we will have a non-decreasing sorted array.

<h2>Time complexity</h2>
<code>O(nlogn)</code>
