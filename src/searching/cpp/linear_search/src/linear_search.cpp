#include "linear_search.h"

#include <cstddef>
#include <optional>
#include <vector>

template <typename T>
std::optional<std::size_t> linear_search(const std::vector<T> &arr, const T &target) {
  for (std::size_t i = 0; i < arr.size(); ++i) {
    if (arr[i] == target) {
      return i;
    }
  }
  return std::nullopt;
}

// Explicit template instantiations
template std::optional<std::size_t> linear_search<int>(const std::vector<int> &arr, const int &target);
template std::optional<std::size_t> linear_search<float>(const std::vector<float> &arr, const float &target);
template std::optional<std::size_t> linear_search<double>(const std::vector<double> &arr, const double &target);
template std::optional<std::size_t> linear_search<char>(const std::vector<char> &arr, const char &target);
