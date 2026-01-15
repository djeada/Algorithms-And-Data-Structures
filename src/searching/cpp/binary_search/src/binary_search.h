#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <optional>
#include <vector>

/**
 * @brief Search for a target value in a sorted array using binary search.
 *
 * This algorithm repeatedly halves the search interval by comparing the
 * target to the middle element until found or the interval is empty.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The sorted vector of elements to search.
 * @param target The value to search for.
 * @return The index of the target if found, std::nullopt otherwise.
 *
 * @note Time complexity: O(log n)
 * @note Space complexity: O(1)
 * @note The array must be sorted in ascending order.
 */
template <typename T>
std::optional<std::size_t> binary_search(const std::vector<T> &arr, const T &target);

#endif // BINARY_SEARCH_H
