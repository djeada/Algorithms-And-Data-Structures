#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

/**
 * @brief Sort an array using the heap sort algorithm.
 *
 * This implementation repeatedly heapifies portions of the array, moving
 * smaller elements toward the front during each pass through the array.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The vector to sort in ascending order.
 *
 * @note Time complexity: O(n log n)
 * @note Space complexity: O(log n) due to recursion stack
 */
template <typename T>
void heap_sort(std::vector<T> &arr);

#endif // HEAP_SORT_H
