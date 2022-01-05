# Sorting

<h1>The problem of sorting</h1>
In computer science,'sorting' generally refers to arranging a collection of items in a specific order. To do so, we must first define the idea of order on the things under consideration. For numbers, for example, we can use the standard numerical order (defined by the mathematical 'less than' or " relation) and for strings, we can use the so-called lexicographic or alphabetic order, which is used by dictionaries and encyclopedias. Sorting may be applied to any arbitrary category of objects if the order is defined for them.

<h1>Bubble Sort</h1>
The bubble sort is the simplest to grasp and implement, therefore it is usally used to introduce the students to sorting algorithms. The main idea behind bubble sort is to go over the n-element array n times. In each pass, we check each element in the array with its neighbour, i.e., <code>arr[i]</code> with <code>arr[i+1]</code> and swap two elements if they are not in order. This way the larger elements will "bubble up" towards the end of the array. In the first iteration we are guaranteed to have the largest element at the end of array. Therefore n iterations will for sure give us a sorted array.

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
It works by adding the items one at a time into an initial empty container. With each iteration, the container maintains its order. Again there are n iterations.

<h2>Time complexity</h2>
<code>O(n^2)</code>

<h1>Merge sort</h1>

Recursively split the problem into smaller sub-problems till you
just have single items that are trivial to sort. Then put the sorted
‘parts’ back together in a way that preserves the sorting.

In it's current implementation it's an unstable sort.
The function's interface can support iterators with random access.

<h2>Time complexity</h2>
<code>O(nlogn)</code>

<h1>Quick Sort</h1>
The quick sort method divides the original array into two groups by rearranging it. The first group comprises items that are less than an arbitrarily selected value from the set, whereas the second group contains elements that are larger than or equal to the chosen value. The chosen value is referred to as the pivot element. After the array has been reorganized with regard to the pivot, the same partitioning method is done recursively to each of the two subgroups. The original array is sorted after all of the subsets have been partitioned and reorganized.

<h2>Time complexity</h2>
<code>O(nlogn)</code>

<h1>Heap sort</h1>
It provides random access to iterators.
Since it is inplace sorting, the memory complexity is O(1).
It's an unstable sort.
In order for sorting to work, the '<' operator must be defined.

Sorting procedure consists of a  few binary heap operations.
* The inputted array is first max-heapifi
* The heap is then deconstructed by several deletions from the end.
* Finally, we will have a non-decreasing sorted array.

<h2>Time complexity</h2>
<code>O(nlogn)</code>
