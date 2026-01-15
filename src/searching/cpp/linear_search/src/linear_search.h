#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <optional>
#include <vector>

/**
 * @brief Search for a target value in an array using linear search.
 *
 * This algorithm scans the array from left to right, comparing each element
 * with the target until a match is found or the end is reached.
 *
 * @tparam T The type of elements in the vector (must be equality comparable).
 * @param arr The vector of elements to search.
 * @param target The value to search for.
 * @return The index of the target if found, std::nullopt otherwise.
 *
 * @note Time complexity: O(n)
 * @note Space complexity: O(1)
 */
template <typename T>
std::optional<std::size_t> linear_search(const std::vector<T> &arr, const T &target);

#endif // LINEAR_SEARCH_H
