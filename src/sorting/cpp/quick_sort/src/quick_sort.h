#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

/**
 * @brief Sort an array using the quick sort algorithm.
 *
 * This implementation uses the first element as the pivot and partitions
 * the array around it, then recursively sorts the partitions.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The vector to sort in ascending order.
 *
 * @note Time complexity: O(n log n) average, O(n²) worst case
 * @note Space complexity: O(log n) average due to recursion
 */
template <typename T>
void quick_sort(std::vector<T> &arr);

#endif // QUICK_SORT_H
