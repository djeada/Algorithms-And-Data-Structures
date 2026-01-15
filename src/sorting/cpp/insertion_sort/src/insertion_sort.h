#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>

/**
 * @brief Sort an array using the insertion sort algorithm.
 *
 * This algorithm builds the sorted array one element at a time by repeatedly
 * picking the next element and inserting it into its correct position among
 * the previously sorted elements.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The vector to sort in ascending order.
 *
 * @note Time complexity: O(n²) worst/average case, O(n) best case (already sorted)
 * @note Space complexity: O(1)
 */
template <typename T>
void insertion_sort(std::vector<T> &arr);

#endif // INSERTION_SORT_H
