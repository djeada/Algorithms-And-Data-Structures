#include "exponential_search.h"

#include <algorithm>
#include <cstddef>
#include <optional>
#include <vector>

template <typename T>
std::optional<std::size_t> exponential_search(const std::vector<T> &arr, const T &target) {
  std::size_t n = arr.size();
  if (n == 0) {
    return std::nullopt;
  }

  // Check if target is at the first position
  if (arr[0] == target) {
    return 0;
  }

  // Find range for binary search by repeated doubling
  std::size_t bound = 1;
  while (bound < n && arr[bound] <= target) {
    bound *= 2;
  }

  // Binary search in the found range
  std::size_t low = bound / 2;
  std::size_t high = std::min(bound, n - 1);

  while (low <= high) {
    std::size_t mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      if (mid == 0) {
        break;
      }
      high = mid - 1;
    }
  }

  return std::nullopt;
}

// Explicit template instantiations
template std::optional<std::size_t> exponential_search<int>(const std::vector<int> &arr, const int &target);
template std::optional<std::size_t> exponential_search<float>(const std::vector<float> &arr, const float &target);
template std::optional<std::size_t> exponential_search<double>(const std::vector<double> &arr, const double &target);
template std::optional<std::size_t> exponential_search<char>(const std::vector<char> &arr, const char &target);
