#ifndef INTERPOLATION_SEARCH_H
#define INTERPOLATION_SEARCH_H

#include <optional>
#include <vector>

/**
 * @brief Search for a target value in a sorted array using interpolation search.
 *
 * This algorithm estimates the likely position of the target using the values
 * themselves, then probes there and narrows the search based on comparison.
 * Works best on uniformly distributed sorted data.
 *
 * @param arr The sorted vector of integers to search.
 * @param target The value to search for.
 * @return The index of the target if found, std::nullopt otherwise.
 *
 * @note Time complexity: O(log log n) average for uniform data, O(n) worst case
 * @note Space complexity: O(1)
 * @note The array must be sorted in ascending order.
 */
std::optional<std::size_t> interpolation_search(const std::vector<int> &arr, int target);

#endif // INTERPOLATION_SEARCH_H
