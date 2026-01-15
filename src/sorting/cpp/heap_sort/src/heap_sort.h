#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

/**
 * @brief Sort an array using the heap sort algorithm.
 *
 * This implementation builds a min-heap and repeatedly extracts the minimum
 * element to produce a sorted array in-place.
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
