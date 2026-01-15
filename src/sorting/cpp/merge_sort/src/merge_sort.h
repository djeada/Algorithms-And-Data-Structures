#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

/**
 * @brief Sort an array using the merge sort algorithm.
 *
 * This implementation uses the divide-and-conquer approach, recursively
 * splitting the array in half and merging the sorted halves.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The vector to sort in ascending order.
 *
 * @note Time complexity: O(n log n)
 * @note Space complexity: O(n)
 */
template <typename T>
void merge_sort(std::vector<T> &arr);

#endif // MERGE_SORT_H
