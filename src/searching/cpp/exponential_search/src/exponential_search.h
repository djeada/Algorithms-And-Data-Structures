#ifndef EXPONENTIAL_SEARCH_H
#define EXPONENTIAL_SEARCH_H

#include <optional>
#include <vector>

/**
 * @brief Search for a target value in a sorted array using exponential search.
 *
 * This algorithm grows the right boundary exponentially (1, 2, 4, 8, ...) to
 * find a containing range, then finishes with binary search in that range.
 * Useful when target is likely near the beginning or the array is unbounded.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The sorted vector of elements to search.
 * @param target The value to search for.
 * @return The index of the target if found, std::nullopt otherwise.
 *
 * @note Time complexity: O(log p) where p is the position of the target
 * @note Space complexity: O(1)
 * @note The array must be sorted in ascending order.
 */
template <typename T>
std::optional<std::size_t> exponential_search(const std::vector<T> &arr, const T &target);

#endif // EXPONENTIAL_SEARCH_H
