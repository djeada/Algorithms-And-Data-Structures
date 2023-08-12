## Sorting

In the realm of computer science, 'sorting' refers to the process of arranging a collection of items in a specific, predetermined order. This order is based on certain criteria that are defined beforehand.

For instance:
- **Numbers**: They can be sorted based on their numerical values, either in ascending or descending order.
- **Strings**: Sorting is usually done in alphabetical order, akin to how words are arranged in dictionaries.

Sorting isn't limited to just numbers and strings. Virtually any type of object can be sorted, provided there is a clear definition of order for them.

### Stability in Sorting

Stability, in the context of sorting, refers to preserving the relative order of equal items in the sorted output. In simple terms, when two items have equal keys:

- In an **unstable** sorting algorithm, their order might be reversed in the sorted output.
- In a **stable** sorting algorithm, their relative order remains unchanged.

For example, consider a sequence of colored balls, each with a number. If we sort them based on their number using a stable sorting method, two balls with the same number will retain their original order in terms of color.

This characteristic is particularly valuable in scenarios where we might perform multiple rounds of sorting based on different criteria.

## Bubble Sort

Bubble sort, one of the simplest sorting algorithms, is often a go-to choice for teaching the foundational concepts of sorting due to its intuitive nature. The name "bubble sort" stems from the way larger elements "bubble up" towards the end of the array, much like how bubbles rise in a liquid.

### Conceptual Overview

Imagine a sequence of numbers. Starting from the beginning of the sequence, we compare each pair of adjacent numbers and swap them if they are out of order. As a result, at the end of the first pass, the largest number will have "bubbled up" to the last position. Each subsequent pass ensures that the next largest number finds its correct position, and this continues until the whole array is sorted.

### Steps

1. Start from the first item and compare it with its neighbor to the right.
2. If the items are out of order (i.e., the left item is greater than the right), swap them.
3. Move to the next item and repeat the above steps until the end of the array.
4. After the first pass, the largest item will be at the last position. On the next pass, you can ignore the last item and consider the rest of the array.
5. Continue this process for `n-1` passes to ensure the array is completely sorted.

### Optimizations

An important optimization for bubble sort is to keep track of whether any swaps were made during a pass. If a pass completes without any swaps, it means the array is already sorted, and there's no need to continue further iterations.

### Stability

Bubble sort is stable. This means that two objects with equal keys will retain their relative order after sorting. Thus, if you had records sorted by name and then sorted them using bubble sort based on age, records with the same age would still maintain the name order.

### Time Complexity

- **Worst-case**: $(O(n^2))$ - This occurs when the array is in reverse order.
- **Average-case**: $(O(n^2))$ - On average, bubble sort still requires quadratic time.
- **Best-case**: $(O(n))$ - This happens when the array is already sorted, especially with the mentioned optimization.

### Space Complexity

$(O(1))$ - It sorts in place, so it doesn't require any additional memory beyond the input array.

## Selection Sort

Selection sort is another intuitive algorithm, widely taught in computer science curricula due to its straightforward mechanism. The crux of selection sort lies in repeatedly selecting the smallest (or largest, depending on the desired order) element from the unsorted section of the array and swapping it with the first unsorted element.

### Conceptual Overview

Consider an array of numbers. The algorithm divides the array into two parts: a sorted subarray and an unsorted subarray. Initially, the sorted subarray is empty, while the entire array is unsorted. During each pass, the smallest element from the unsorted subarray is identified and then swapped with the first unsorted element. As a result, the sorted subarray grows by one element after each pass.

### Steps

1. Assume the first element is the smallest.
2. Traverse the unsorted subarray and find the smallest element.
3. Swap the found smallest element with the first element of the unsorted subarray.
4. Move the boundary of the sorted and unsorted subarrays one element to the right.
5. Repeat steps 1-4 until the entire array is sorted.

### Stability

Selection sort is inherently unstable. When two elements have equal keys, their relative order might change post-sorting. This can be problematic in scenarios where stability is crucial.

### Time Complexity

- **Worst-case**: $(O(n^2))$ - Even if the array is sorted, the algorithm will still go through every element to ensure it's the smallest.
- **Average-case**: $(O(n^2))$ - On average, the algorithm's performance remains quadratic.
- **Best-case**: $(O(n^2))$ - Unlike some other algorithms, the best case for selection sort remains quadratic due to its consistent checking mechanism.

### Space Complexity

$(O(1))$ - The algorithm sorts in-place, meaning it doesn't use any extra space beyond what's needed for the input.

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/selection_sort/src/selection_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/selection_sort/src/selection_sort.py)

## Insertion Sort

Insertion sort works much like how one might sort a hand of playing cards. It builds a sorted array (or list) one element at a time by repeatedly taking one element from the input and inserting it into the correct position in the already-sorted section of the array. Its simplicity makes it a common choice for teaching the basics of algorithm design.

### Conceptual Overview

Imagine you have a series of numbers. The algorithm begins with the second element (assuming the first element on its own is already sorted) and inserts it into the correct position relative to the first. With each subsequent iteration, the algorithm takes the next unsorted element and scans through the sorted subarray, finding the appropriate position to insert the new element.

### Steps

1. Start at the second element (index 1) assuming the element at index 0 is sorted.
2. Compare the current element with the previous elements.
3. If the current element is smaller than the previous element, compare it with the elements before until you reach an element smaller or until you reach the start of the array. 
4. Insert the current element into the correct position so that the elements before are all smaller.
5. Repeat steps 2-4 for each element in the array.

### Stability

Insertion sort is stable. When two elements have equal keys, their relative order remains unchanged post-sorting. This stability is preserved since the algorithm only swaps elements if they are out of order, ensuring that equal elements never overtake each other.

### Time Complexity

- **Worst-case**: $(O(n^2))$ - This occurs when the array is in reverse order and every element has to be compared with every other element.
- **Average-case**: $(O(n^2))$ - Typically, elements need to be compared with others, resulting in quadratic performance.
- **Best-case**: $(O(n))$ - This best-case scenario occurs when the array is already sorted. The algorithm just runs through the array once without having to make any swaps.

### Space Complexity

$(O(1))$ - This in-place sorting algorithm doesn't need any additional storage beyond the input array.

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/insertion_sort/src/insertion_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/insertion_sort/src/insertion_sort.py)

## Quick Sort

Quick Sort, often simply referred to as "quicksort", is a divide-and-conquer algorithm that's renowned for its efficiency and is widely used in practice. Its name stems from its ability to sort large datasets quickly. The core idea behind quicksort is selecting a 'pivot' element and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The process is then recursively applied to the sub-arrays.

### Conceptual Overview

1. **Choose a Pivot**: Pick an element from the array, called the 'pivot'. The choice of pivot selection methods can vary (e.g., always first element, always middle element, a random element, or using a more advanced median-of-three approach).
2. **Partitioning**: Rearrange the elements in the array so that all elements less than or equal to the pivot come before, and all elements greater than the pivot come after it. The pivot is then in its final sorted position.
3. **Recursion**: Recursively apply the above steps to the two sub-arrays (the elements less than the pivot and the elements greater than the pivot).

### Steps

1. Choose a 'pivot' from the array.
2. Partition the array around the pivot, ensuring all elements on the left are less than the pivot and all elements on the right are greater than it.
3. Recursively apply steps 1 and 2 to the left and right partitions.
4. Repeat until base case: the partition has only one or zero elements.

### Stability

Quick sort is inherently unstable due to the long-distance exchanges of values. However, with specific modifications, it can be made stable, although this is not commonly done.

### Time Complexity

- **Worst-case**: $(O(n^2))$ - This can occur when the pivot is the smallest or largest element, leading to unbalanced partitions. However, with good pivot selection strategies, this scenario is rare in practice.
- **Average-case**: $(O(n \log n))$ - This is the expected time complexity with good pivot selection.
- **Best-case**: $(O(n \log n))$ - This happens when every pivot splits the array into roughly equal parts.

### Space Complexity

$(O(\log n))$ - Though quicksort sorts in place, it requires stack space for recursion, which in the best case is logarithmic.

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/quick_sort/src/quick_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/quick_sort/src/quick_sort.py)

## Heap sort
Heap Sort is a comparison-based sorting technique performed on a binary heap data structure. It leverages the properties of a heap to efficiently sort a dataset. The essential idea is to build a heap from the input data, then continuously extract the maximum element from the heap and reconstruct the heap until it's empty. The result is a sorted list.

### Conceptual Overview

1. **Build a Max Heap**: The first step is to transform the list into a max heap (a complete binary tree where each node is greater than or equal to its children). This is usually done using a bottom-up approach.
2. **Sorting**: The maximum element of the heap (the root) is the largest element of the unsorted array. We swap this element with the last element of the unsorted part, shrinking the heap size by one and increasing the size of the sorted section. After the swap, we transform the unsorted section back into a max heap. This process repeats until the heap size is reduced to one.

### Steps

1. Construct a max heap from the given data. This will place the largest element at the root.
2. Swap the root (maximum value) with the last element of the heap. This element is now considered sorted.
3. Decrease the heap size by one (to exclude the sorted elements).
4. "Heapify" the root of the tree, i.e., ensure the heap property is maintained.
5. Repeat steps 2-4 until the size of the heap is one.

### Stability

Heap sort is inherently unstable. Similar to quicksort, the relative order of equal items is not preserved because of the long-distance exchanges.

### Time Complexity

- **Worst-case**: $(O(n \log n))$ - Despite the arrangement of the input data.
- **Average-case**: $(O(n \log n))$ - This remains consistent due to the structure of the algorithm.
- **Best-case**: $(O(n \log n))$ - Still requires building and deconstructing the heap.

### Space Complexity

$(O(1))$ - The sorting is done in-place, requiring only a constant amount of space for variables, regardless of the input size.

### Implementation

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/cpp/heap_sort/src/heap_sort.cpp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/sorting/python/heap_sort/src/heap_sort.py)
