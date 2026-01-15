#include "jump_search.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <optional>
#include <vector>

template <typename T>
std::optional<std::size_t> jump_search(const std::vector<T> &arr, const T &target) {
  std::size_t n = arr.size();
  if (n == 0) {
    return std::nullopt;
  }

  std::size_t step = static_cast<std::size_t>(std::sqrt(static_cast<double>(n)));
  std::size_t prev = 0;

  // Jump ahead until we find a block where target could be
  while (arr[std::min(step, n) - 1] < target) {
    prev = step;
    step += static_cast<std::size_t>(std::sqrt(static_cast<double>(n)));
    if (prev >= n) {
      return std::nullopt;
    }
  }

  // Linear search within the block
  while (arr[prev] < target) {
    ++prev;
    if (prev == std::min(step, n)) {
      return std::nullopt;
    }
  }

  if (arr[prev] == target) {
    return prev;
  }

  return std::nullopt;
}

// Explicit template instantiations
template std::optional<std::size_t> jump_search<int>(const std::vector<int> &arr, const int &target);
template std::optional<std::size_t> jump_search<float>(const std::vector<float> &arr, const float &target);
template std::optional<std::size_t> jump_search<double>(const std::vector<double> &arr, const double &target);
template std::optional<std::size_t> jump_search<char>(const std::vector<char> &arr, const char &target);
