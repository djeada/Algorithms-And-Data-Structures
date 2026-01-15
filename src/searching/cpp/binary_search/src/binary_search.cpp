#include "binary_search.h"

#include <cstddef>
#include <optional>
#include <vector>

template <typename T>
std::optional<std::size_t> binary_search(const std::vector<T> &arr, const T &target) {
  if (arr.empty()) {
    return std::nullopt;
  }

  std::size_t low = 0;
  std::size_t high = arr.size() - 1;

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
template std::optional<std::size_t> binary_search<int>(const std::vector<int> &arr, const int &target);
template std::optional<std::size_t> binary_search<float>(const std::vector<float> &arr, const float &target);
template std::optional<std::size_t> binary_search<double>(const std::vector<double> &arr, const double &target);
template std::optional<std::size_t> binary_search<char>(const std::vector<char> &arr, const char &target);
