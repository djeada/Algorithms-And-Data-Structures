#include "heap_sort.h"

#include <cstddef>
#include <utility>
#include <vector>

namespace {

/**
 * @brief Recursively heapify a subtree rooted at the given index.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The vector to heapify.
 * @param curr Current node index (1-based).
 * @param offset Starting position in the array; elements before this
 *               index are already in their final sorted position.
 */
template <typename T>
void heapify(std::vector<T> &arr, std::size_t curr, std::size_t offset) {
  auto parent = [](std::size_t i) { return i >> 1; };
  auto left_child = [](std::size_t i) { return i << 1; };
  auto right_child = [](std::size_t i) { return (i << 1) + 1; };

  if (curr + offset > arr.size()) {
    return;
  }

  heapify(arr, left_child(curr), offset);
  heapify(arr, right_child(curr), offset);

  if (curr > 1 && arr[curr + offset - 1] < arr[parent(curr) + offset - 1]) {
    std::swap(arr[curr + offset - 1], arr[parent(curr) + offset - 1]);
  }
}

} // namespace

template <typename T>
void heap_sort(std::vector<T> &arr) {
  for (std::size_t i = 0; i < arr.size(); ++i) {
    heapify(arr, 1, i);
  }
}

// Explicit template instantiations
template void heap_sort<int>(std::vector<int> &arr);
template void heap_sort<float>(std::vector<float> &arr);
template void heap_sort<double>(std::vector<double> &arr);
template void heap_sort<char>(std::vector<char> &arr);
