#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

/**
 * @brief Sort a vector in ascending order using heap sort.
 *
 * Builds a max-heap in place, then repeatedly swaps the maximum to the end of
 * the shrinking heap and sifts the new root down.
 *
 * @tparam T The type of elements in the vector (must be comparable with <).
 * @param arr The vector to sort in ascending order.
 *
 * @note Time complexity: O(n log n)
 * @note Space complexity: O(1)
 */
template <typename T> void heap_sort(std::vector<T> &arr);

#endif // HEAP_SORT_H
