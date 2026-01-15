#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>

/**
 * @brief Sort an array using the selection sort algorithm.
 *
 * This algorithm divides the input into a sorted and unsorted region,
 * repeatedly selecting the smallest element from the unsorted region
 * and moving it to the end of the sorted region.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The vector to sort in ascending order.
 *
 * @note Time complexity: O(n²)
 * @note Space complexity: O(1)
 */
template <typename T>
void selection_sort(std::vector<T> &arr);

#endif // SELECTION_SORT_H
