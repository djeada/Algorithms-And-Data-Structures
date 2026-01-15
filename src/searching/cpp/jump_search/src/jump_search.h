#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include <optional>
#include <vector>

/**
 * @brief Search for a target value in a sorted array using jump search.
 *
 * This algorithm jumps ahead by fixed block sizes to find the block that may
 * contain the target, then performs a linear scan inside that block.
 *
 * @tparam T The type of elements in the vector (must be comparable).
 * @param arr The sorted vector of elements to search.
 * @param target The value to search for.
 * @return The index of the target if found, std::nullopt otherwise.
 *
 * @note Time complexity: O(√n)
 * @note Space complexity: O(1)
 * @note The array must be sorted in ascending order.
 */
template <typename T>
std::optional<std::size_t> jump_search(const std::vector<T> &arr, const T &target);

#endif // JUMP_SEARCH_H
