#include "interpolation_search.h"

#include <algorithm>
#include <cstddef>
#include <optional>
#include <vector>

std::optional<std::size_t> interpolation_search(const std::vector<int> &arr, int target) {
  if (arr.empty()) {
    return std::nullopt;
  }

  std::size_t low = 0;
  std::size_t high = arr.size() - 1;

  while (low <= high && target >= arr[low] && target <= arr[high]) {
    // Handle case where all elements are the same
    if (arr[high] == arr[low]) {
      if (arr[low] == target) {
        return low;
      }
      return std::nullopt;
    }

    // Estimate position using interpolation formula
    std::size_t pos = low + static_cast<std::size_t>(
        (static_cast<double>(target - arr[low]) / (arr[high] - arr[low])) * (high - low)
    );

    // Ensure pos is within bounds
    pos = std::max(low, std::min(pos, high));

    if (arr[pos] == target) {
      return pos;
    } else if (arr[pos] < target) {
      low = pos + 1;
    } else {
      if (pos == 0) {
        break;
      }
      high = pos - 1;
    }
  }

  return std::nullopt;
}
